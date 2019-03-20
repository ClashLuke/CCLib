#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "squash.h"
#include "blake2/blake2.h"

#define HASH_BYTES   32                 // hash length in bytes
#define CACHE_ROUNDS 4                  // number of rounds in cache production
#define EPOCH_LENGTH 60                 // blocks per epoch
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
			temp_cache[0] = cache_64[index[0]  ]^cache_64[index[1]  ];
			temp_cache[1] = cache_64[index[0]+1]^cache_64[index[1]+1];
			temp_cache[2] = cache_64[index[0]+2]^cache_64[index[1]+2];
			temp_cache[3] = cache_64[index[0]+3]^cache_64[index[1]+3];
			squash_2((uint8_t*)temp_cache, scratchpad, &cache[i*32]);
		}
	}
}

void calc_dataset_item(uint8_t* cache, uint32_t item_number, uint8_t* out){
	uint32_t  mask        = 2097151; // Hashcount - 1 
	uint32_t  mask_32     = 67108863;
	uint64_t* cache_64    = (uint64_t*)cache; 
	uint8_t   mix_8[32]   = {0};
	uint64_t* mix         = (uint64_t*)mix_8;
	mix[0] = cache_64[item_number&mask  ]; mix[1] = cache_64[item_number&mask+1];
	mix[2] = cache_64[item_number&mask+2]; mix[3] = cache_64[item_number&mask+3];
	squash_2(mix_8, &cache[item_number&mask_32], out);
}

void calc_dataset(uint8_t* cache, uint8_t* out){
	for(uint64_t i=0;i<4294967296;i+=32){
		calc_dataset_item(cache, i, &out[i]);
	}
}

void squash_pow_full(uint8_t* header, uint64_t nonce, uint8_t* dataset, uint8_t* result){
	uint32_t  header_len               = sizeof(header)/sizeof(header[0]);
	uint8_t   seed[32+2*4]             = {0};
	memcpy(&header[header_len], (char*)&nonce, 8);
	blake2b(seed, 32, header, (size_t) header_len+8, NULL, 0);
	squash_3_full(seed, dataset, result);
}

void squash_pow_light(uint8_t* header, uint64_t nonce, uint8_t* cache, uint8_t* result){
	uint32_t  header_len               = sizeof(header)/sizeof(header[0]);
	uint8_t   seed[32+2*4]             = {0};
	memcpy(&header[header_len], (char*)&nonce, 8);
	blake2b(seed, 32, header, (size_t) header_len+8, NULL, 0);
	squash_3_light(seed, cache, result);
}

void get_seedhash(uint64_t block_number, uint8_t* seed){ /* IN: block number | OUT: seed */
	for(uint64_t i=0;i<block_number/EPOCH_LENGTH;i++) squash_0(seed, seed);
}

void cache_from_seed(uint8_t* seed, uint8_t* cache){
	uint8_t* scratchpad;
	scratchpad = malloc (sizeof(uint8_t) * 65536);
	if (scratchpad == NULL) exit(1);
	make_scratchpad(seed, scratchpad);
	cache = malloc (sizeof(uint8_t) * 67108864);
	if (cache == NULL) exit(1);
	make_cache(scratchpad, cache);
}
void dataset_from_seed(uint8_t* seed, uint8_t* dataset){
	uint8_t* cache;
	cache = malloc (sizeof(uint8_t) * 67108864);
	if (cache == NULL) exit(1);
	cache_from_seed(seed, cache);
	calc_dataset(cache, dataset);
	free(cache);
}