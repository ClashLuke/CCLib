#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "pow.h"

uint64_t benchmark_mine(uint64_t block_height){
	uint8_t   result[32] = {0};
	uint64_t* result_64  = (uint64_t*)result;
	uint64_t  final      = 0;
	uint64_t  temp[4]    = {0};
	uint8_t  header[80] = {0};
	uint8_t* seed    = malloc(sizeof(uint8_t) * 32);
	uint8_t* dataset = malloc(sizeof(uint8_t) * 4294967296);
	if (dataset == NULL || seed == NULL) exit(1);
	get_seedhash(block_height, seed);
	dataset_from_seed(seed, dataset);
	free(seed);
	for(uint32_t i=0;i<268435456;i++){
		squash_pow_full(header, i, dataset, result);
		final ^= result[0];
	}
	return final;
}

uint64_t benchmark_validation(uint64_t block_height){
	uint8_t   result[32] = {0};
	uint64_t* result_64  = (uint64_t*)result;
	uint64_t  final      = 0;
	uint64_t  temp[4]    = {0};
	uint8_t  header[80] = {0};
	uint8_t* seed    = malloc(sizeof(uint8_t) * 32);
	uint8_t* cache = malloc(sizeof(uint8_t) * 4294967296);
	if (cache == NULL || seed == NULL) exit(1);
	get_seedhash(block_height, seed);
	cache_from_seed(seed, cache);
	free(seed);
	for(uint32_t i=0;i<268435456;i++){
		squash_pow_light(header, i, cache, result);
		final ^= result[0];
	}
	return final;
}



int main(){
	printf("Current Time: %u\n\n",(uint32_t)time(NULL));
	printf("Mining Result: %016jx\n",benchmark_mine(10));
	printf("Current Time: %u\n\n",(uint32_t)time(NULL));
	printf("Validation Result: %016jx\n",benchmark_validation(10));
	printf("Current Time: %u\n\n",(uint32_t)time(NULL));
}
