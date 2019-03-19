#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "squash.h"
#include "prime_test.h"
#include "blake2/blake2.h"

#define WORD_BYTES 4                    // bytes in word
#define DATASET_BYTES_INIT 1073741824   // bytes in dataset at genesis
#define DATASET_BYTES_GROWTH 8388608    // dataset growth per epoch
#define CACHE_BYTES_INIT 16777216       // bytes in cache at genesis
#define CACHE_BYTES_GROWTH 131072       // cache growth per epoch
#define CACHE_MULTIPLIER 1024           // Size of the DAG relative to the cache
#define EPOCH_LENGTH 30000              // blocks per epoch
#define MIX_BYTES 128                   // width of mix
#define HASH_BYTES 32                   // hash length in bytes
#define DATASET_PARENTS 256             // number of parents of each dataset element
#define CACHE_ROUNDS 3                  // number of rounds in cache production
#define ACCESSES 64                     // number of accesses in hashimoto loop
#define FNV_PRIME 0x01000193

#define fnv(v1, v2) ((((v1) * FNV_PRIME)^(v2))&0xFFFFFFFF)

uint64_t get_cache_size(uint64_t block_number){
	uint64_t sz = CACHE_BYTES_INIT + CACHE_BYTES_GROWTH * (block_number / EPOCH_LENGTH);
	sz -= HASH_BYTES;
	while (1^isprime(sz / HASH_BYTES)) sz -= 2 * HASH_BYTES;
	return sz;
}

uint64_t get_full_size(uint64_t block_number){
	uint64_t  sz = DATASET_BYTES_INIT + DATASET_BYTES_GROWTH * (block_number / EPOCH_LENGTH);
	sz -= MIX_BYTES;
	while (1^isprime(sz / MIX_BYTES)) sz -= 2 * MIX_BYTES;
	return sz;
}

void make_cache(uint8_t* seed, uint8_t* cache){
	/* 32MiB cache is allocated before executing
	   this function */
	uint32_t  iterations    = 33554432/HASH_BYTES;
	uint32_t  mask          = iterations-1;
	uint64_t* cache_64      = (uint64_t*)cache; 
	uint64_t* seed_64       = (uint64_t*)seed; 
	uint64_t  temp_cache[4] = {0};
	uint64_t  index[2]      = {0};
	cache_64[0] = seed_64[0]; cache_64[1] = seed_64[1];
	cache_64[2] = seed_64[2]; cache_64[3] = seed_64[3];
	for(uint32_t i=1;i<iterations;i++) squash_0(&cache[i*32], &cache[(i+1)*32]);
	for(uint8_t j=0;j<CACHE_ROUNDS;j++){
		for(uint32_t i=0;i<iterations;i++){
			index[0] = cache_64[i*4]&mask;
			index[1] = (i-1+iterations)&mask; 
			temp_cache[0] = cache_64[index[0]  ]^cache_64[index[1]  ];
			temp_cache[1] = cache_64[index[0]+1]^cache_64[index[1]+1];
			temp_cache[2] = cache_64[index[0]+2]^cache_64[index[1]+2];
			temp_cache[3] = cache_64[index[0]+3]^cache_64[index[1]+3];
			squash_0((uint8_t*)temp_cache,&cache[i*32]);
		}
	}
}

void calc_dataset_item(uint8_t* cache, uint64_t item_number, uint8_t* out){
	uint32_t  mask        = 1048575; // Hashcount - 1 
	uint32_t  mask_32     = 33554431;
	uint64_t* cache_64    = (uint64_t*)cache; 
	uint8_t   mix_8[32]   = {0};
	uint64_t* mix         = (uint64_t*)mix_8;
	uint32_t* mix_32      = (uint32_t*)mix;
	uint32_t  cache_index = 0;
	mix[0] = cache_64[item_number&mask  ]; mix[1] = cache_64[item_number&mask+1];
	mix[2] = cache_64[item_number&mask+2]; mix[3] = cache_64[item_number&mask+3];
	squash_2(mix_8, &cache[item_number&mask_32], mix_8);
	for(uint16_t i=0;i<DATASET_PARENTS;i++){
		cache_index = fnv(item_number^i, mix[i&3])&mask;
		for(uint8_t j=0;j<8;j++){
			mix_32[j] = fnv(mix_32[j], cache[cache_index]);
		}
	}
	squash_2(mix_8, &cache[item_number&mask_32], out);
}

void calc_dataset(uint64_t full_size, uint8_t* cache, uint8_t* out){
	for(uint64_t i=0;i<full_size;i+=32){
		calc_dataset_item(cache, i, &out[i]);
	}
}

void squashimoto_full(uint8_t* header, uint64_t nonce, uint64_t full_size, uint8_t* dataset, /*uint8_t* mix_digest,*/ uint8_t* result){
	uint32_t  header_len               = sizeof(header)/sizeof(header[0]);
	uint32_t  size_mask                = full_size/HASH_BYTES-4;
	uint8_t   word_mask                = (MIX_BYTES/WORD_BYTES)-1;
	uint32_t  mix_32[8*4]              = {0}; 
	uint64_t* mix                      = (uint64_t*)mix_32; 
	uint8_t   newdata[32*4]            = {0};
	uint32_t* newdata_32               = (uint32_t*)newdata;
	uint8_t   seed[32+2*4]             = {0};
	uint32_t  ptr                      = 0;
	uint32_t  temp                     = 0;
	memcpy(&header[header_len], (char*)&nonce, 8);
	blake2b(seed, 32, header, (size_t) header_len+8, NULL, 0);
	for(uint8_t i=0;i<64;i+=4){ // MIX_BYTES / HASH_BYTES
		mix[i  ] = seed[0]; mix[i+1] = seed[1];
		mix[i+2] = seed[2]; mix[i+3] = seed[3];
	}
	for(uint8_t i=0;i<ACCESSES;i++){
		ptr = fnv(i^seed[0], mix[i&word_mask])%size_mask;
		for(uint8_t j=0;j<4;j++){
			newdata[0] = ((uint64_t*)&dataset[ptr*32+j  ])[0];
			newdata[1] = ((uint64_t*)&dataset[ptr*32+j+1])[0];
			newdata[2] = ((uint64_t*)&dataset[ptr*32+j+2])[0];
			newdata[3] = ((uint64_t*)&dataset[ptr*32+j+3])[0];
		}
		squash_1((uint8_t*)&mix_32[0], (uint8_t*)&newdata_32[0], (uint8_t*)&mix_32[0]);
		squash_1((uint8_t*)&mix_32[4], (uint8_t*)&newdata_32[4], (uint8_t*)&mix_32[4]);
	}
	for(uint8_t i=0;i<8;i++){
		temp = fnv(mix[i<<2],mix[(i<<2)+1]);
		temp = fnv(temp     ,mix[(i<<2)+2]);
		temp = fnv(temp     ,mix[(i<<2)+3]);
		seed[32+i] = temp;
	}
	blake2b(result, 32, seed, (size_t)32+2*4, NULL, 0);
	//memcpy(mix_digest,&seed[32],2*hash_per_mix);
}

void squashimoto_light(uint8_t* header, uint64_t nonce, uint64_t full_size, uint8_t* cache, /*uint8_t* mix_digest,*/ uint8_t* result){
	uint32_t  header_len               = sizeof(header)/sizeof(header[0]);
	uint32_t  size_mask                = full_size/HASH_BYTES-4;
	uint8_t   word_mask                = (MIX_BYTES/WORD_BYTES)-1;
	uint32_t  mix_32[8*4]              = {0}; 
	uint64_t* mix                      = (uint64_t*)mix_32; 
	uint8_t   newdata[32*4]            = {0};
	uint32_t* newdata_32               = (uint32_t*)newdata;
	uint8_t   seed[32+2*4]             = {0};
	uint32_t  ptr                      = 0;
	uint32_t  temp                     = 0;
	memcpy(&header[header_len], (char*)&nonce, 8);
	blake2b(seed, 32, header, (size_t) header_len+8, NULL, 0);
	for(uint8_t i=0;i<64;i+=4){ // MIX_BYTES / HASH_BYTES
		mix[i  ] = seed[0]; mix[i+1] = seed[1];
		mix[i+2] = seed[2]; mix[i+3] = seed[3];
	}
	for(uint8_t i=0;i<ACCESSES;i++){
		ptr = fnv(i^seed[0], mix[i&word_mask])%size_mask;
		for(uint8_t j=0;j<4;j++){
			calc_dataset_item(cache, ptr*32+j  , &newdata[ 0]);
			calc_dataset_item(cache, ptr*32+j+1, &newdata[ 4]);
			calc_dataset_item(cache, ptr*32+j+2, &newdata[ 8]);
			calc_dataset_item(cache, ptr*32+j+3, &newdata[12]);
		}
		squash_1((uint8_t*)&mix_32[0], (uint8_t*)&newdata_32[0], (uint8_t*)&mix_32[0]);
		squash_1((uint8_t*)&mix_32[4], (uint8_t*)&newdata_32[4], (uint8_t*)&mix_32[4]);
	}
	for(uint8_t i=0;i<8;i++){
		temp = fnv(mix[i<<2],mix[(i<<2)+1]);
		temp = fnv(temp     ,mix[(i<<2)+2]);
		temp = fnv(temp     ,mix[(i<<2)+3]);
		seed[32+i] = temp;
	}
	blake2b(result, 32, seed, (size_t)32+2*4, NULL, 0);
	//memcpy(mix_digest,&seed[32],2*hash_per_mix);
}

uint64_t mine(uint64_t full_size, uint8_t* dataset, uint8_t* header, uint64_t difficulty){
	uint8_t result[32] = {0};
	uint64_t* result_64 = (uint64_t*)result;
	uint64_t nonce = 0;
	nonce = rand()&0xFFFFFFFFFFFFFFFF;
	squashimoto_full(header, nonce, full_size, dataset, result);
	uint64_t temp = result_64[0] * difficulty;
	while(temp/difficulty != result_64[0]){
		nonce = rand()&0xFFFFFFFFFFFFFFFF;
		squashimoto_full(header, nonce, full_size, dataset, result);
		temp = result_64[0] * difficulty;
	}
	return nonce;
} 

void get_seedhash(uint64_t block_number, uint8_t* seed){
	for(uint8_t i=0;i<32;i++)seed[i]=0;
	for(uint64_t i=0;i<block_number/EPOCH_LENGTH;i++) squash_0(seed, seed);
}

static uint8_t cache[33554432+65539] = {0};
int main(){
	uint8_t seed[32] = {0};
	uint64_t* cache_64 = (uint64_t*)cache;
	make_cache(seed, cache);
	printf("%016jx,%016jx,%016jx,%016jx|%016jx,%016jx,%016jx,%016jx\n",cache_64[0],cache_64[1],cache_64[2],cache_64[3],cache_64[524284],cache_64[524285],cache_64[524286],cache_64[524287]);
	return 0;
}
