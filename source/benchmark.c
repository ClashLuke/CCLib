#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "pow.h"

#define ITERATIONS 268435456

uint64_t benchmark_mine(uint64_t block_height){
	uint8_t   result[32] = {0};
	uint64_t* result_64  = (uint64_t*)result;
	uint64_t  final      = 0;
	uint64_t  temp[4]    = {0};
	uint8_t  header[80] = {0};
	uint8_t* seed    = malloc(sizeof(uint8_t) * 32);
	uint8_t* dataset = malloc(sizeof(uint8_t) * 4294967296);
	uint32_t current_time = (uint32_t)time(NULL);
	if (dataset == NULL || seed == NULL) exit(1);
	get_seedhash(block_height, seed);
	printf("\tSeed calculation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	dataset_from_seed(seed, dataset);
	printf("\tDataset generation took: %us\n",(uint32_t)time(NULL)-current_time);
	free(seed);
	current_time = (uint32_t)time(NULL);
	for(uint32_t i=0;i<ITERATIONS;i++){
		squash_pow_full(header, i, dataset, result);
		final ^= result[0];
	}
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %u hashes took: %us\n",ITERATIONS, end_time-current_time);
	printf("\tHashrate is about: %uH/s\n\n", ITERATIONS/(end_time-current_time));
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
	uint32_t current_time = (uint32_t)time(NULL);
	if (cache == NULL || seed == NULL) exit(1);
	get_seedhash(block_height, seed);
	printf("\tSeed calculation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	cache_from_seed(seed, cache);
	printf("\nCache generation took: %us\n",(uint32_t)time(NULL)-current_time);
	free(seed);
	current_time = (uint32_t)time(NULL);
	for(uint32_t i=0;i<ITERATIONS;i++){
		squash_pow_light(header, i, cache, result);
		final ^= result[0];
	}
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %u hashes took: %us\n",ITERATIONS, end_time-current_time);
	printf("\tHashrate is about: %uH/s\n\n", ITERATIONS/(end_time-current_time));
	return final;
}



int main(){
	printf("Mining\n");
	printf("\tResult: %016jx",benchmark_mine(10));
	printf("Validation\n");
	printf("\tResult: %016jx",benchmark_validation(10));
	return 1;
}