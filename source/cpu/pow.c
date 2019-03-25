#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "squash.h"
#if !defined(HAVE_SSE2)
#include "blake2/neon/blake2.h"
#else
#include "blake2/sse/blake2.h"
#endif


#define HASH_BYTES      32                 // hash length in bytes
#define CACHE_ROUNDS    4                  // number of rounds in cache production
#define EPOCH_LENGTH    60                 // blocks per epoch
#define DATASET_PARENTS 256                // number of hashes before calculating dataset entry
// Assuming 4 blocks per second, an epoch estimates 15 minutes

void make_scratchpad(uint8_t* seed, uint8_t* scratchpad){
	squash_0(seed, scratchpad);
	for(uint32_t i=32; i<65536;i+=32) squash_0(&scratchpad[i-32], &scratchpad[i]);
}

void make_cache(uint8_t* scratchpad, uint8_t* cache){
	/* 64MiB cache is allocated before executing
	   this function */
	uint32_t  iterations    = 67108864/HASH_BYTES;
	uint32_t  mask          = iterations-1;
	uint64_t* cache_64      = (uint64_t*)cache; 
	uint64_t  temp_cache[4] = {0};
	uint64_t  index[2]      = {0};
	for(uint32_t i=0;i<iterations;i++) squash_2(&cache[i*32], scratchpad, &cache[(i+1)*32]);
	for(uint8_t j=0;j<CACHE_ROUNDS;j++){
		for(uint32_t i=0;i<iterations;i++){
			index[0] = cache_64[i*4]&mask;
			index[1] = (i-1+iterations)&mask; 
			for(uint8_t k=0;k<4;k++)
				temp_cache[k] = ((uint64_t*)&cache[index[0]+k])[0]^((uint64_t*)&cache[index[1]+k])[0];
			squash_2((uint8_t*)temp_cache, scratchpad, &cache[i*32]);
		}
	}
}

void calc_dataset_item(uint8_t* cache, uint64_t item_number, uint8_t* out){
	uint32_t  mask     = 2097151; // Hashcount - 1 
	uint32_t  mask_32  = 67043327; // Cachesize-scratchpad size
	uint64_t* cache_64 = (uint64_t*)cache; 
	uint64_t  mix[4]   = {0};
	uint8_t*  mix_8    = (uint8_t*)mix;
	uint32_t* mix_32   = (uint32_t*)mix;
	item_number = item_number << 5;
	for(uint8_t i=0;i<4;i++)
		mix[i] = ((uint64_t*)&cache[(item_number&mask)+i])[0];
	for(uint16_t i=0;i<DATASET_PARENTS;i++)
		mix_32[i^0] = crc32(((uint32_t*)&cache[mix_32[i^0]&mask_32])[0]);
		mix_32[i^1] = crc32(((uint32_t*)&cache[mix_32[i^1]&mask_32])[0]);
		mix_32[i^2] = crc32(((uint32_t*)&cache[mix_32[i^2]&mask_32])[0]);
		mix_32[i^3] = crc32(((uint32_t*)&cache[mix_32[i^3]&mask_32])[0]);
		mix_32[i^4] = crc32(((uint32_t*)&cache[mix_32[i^4]&mask_32])[0]);
		mix_32[i^5] = crc32(((uint32_t*)&cache[mix_32[i^5]&mask_32])[0]);
		mix_32[i^6] = crc32(((uint32_t*)&cache[mix_32[i^6]&mask_32])[0]);
		mix_32[i^7] = crc32(((uint32_t*)&cache[mix_32[i^7]&mask_32])[0]);
	squash_2(mix_8, &cache[item_number&mask_32], out);
}

void calc_dataset(uint8_t* cache, uint8_t* out){
	for(uint64_t i=0;i<4294967296;i+=32){ // (1<<32)>>5
		calc_dataset_item(cache, i, &out[i]);
	}
}

void squash_pow_full(uint8_t* header, uint64_t nonce, uint8_t* dataset, uint8_t* result){
	uint64_t  seed_64[4] = {0}; 
	uint8_t*  seed       = (uint8_t*)seed_64; 
	memcpy(&header[80], (char*)&nonce, 8);
	blake2b(seed, 32, header, (size_t) 88, NULL, 0);
	squash_3_full(seed, dataset, result);
}

void squash_pow_light(uint8_t* header, uint64_t nonce, uint8_t* cache, uint8_t* result){
	uint64_t  seed_64[4] = {0}; 
	uint8_t*  seed       = (uint8_t*)seed_64; 
	memcpy(&header[80], (char*)&nonce, 8);
	blake2b(seed, 32, header, (size_t) 88, NULL, 0);
	squash_3_light(seed, cache, result);
}

void get_seedhash(uint64_t block_number, uint8_t* seed){ /* IN: block number | OUT: seed */
	for(uint64_t i=0;i<block_number/EPOCH_LENGTH;i++) squash_0(seed, seed);
}

void cache_from_seed(uint8_t* seed, uint8_t* cache){
	uint64_t* scratchpad_64 = malloc (65536);
	uint8_t*  scratchpad    = (uint8_t*)scratchpad_64;
	if (scratchpad == NULL) exit(1);
	make_scratchpad(seed, scratchpad);
	free(scratchpad);
	make_cache(scratchpad, cache);
}
void dataset_from_seed(uint8_t* seed, uint8_t* dataset){
	uint64_t* cache_64 = malloc (67108864);
	uint8_t*  cache    = (uint8_t*)cache_64;
	if (cache == NULL) exit(1);
	cache_from_seed(seed, cache);
	calc_dataset(cache, dataset);
	free(cache);
}
