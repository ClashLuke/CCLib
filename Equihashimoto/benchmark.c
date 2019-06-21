// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash.h"
#include "pow.h"
#include "error.h"
#include "random.h"

#define ITERATIONS 65536 // iterations are multiplied with 64

void benchmark_dataset_generation(uint8_t* seed, uint64_t* dataset){
	char      buffer[65] = {0};
	uint64_t* cache_64   = (uint64_t*)calloc(8388608,8);
	uint8_t*  cache      = (uint8_t*)cache_64;
	uint32_t  temp       = 0;
	if (!cache_64) error_exit(1);
	cache_from_seed(seed, cache);
	for(uint8_t i=0;i<64;i++) buffer[i]=' ';
	printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
	for(uint8_t j=0;j<64;j++){
		for(uint32_t i=0;i<8388608;i+=4){ // (1<<32)>>9
			temp = (8388608*j)+i;
			calc_dataset_item(cache, temp, &dataset[temp]);
		}
		buffer[j] = '#';
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
	}
	printf("\r%*s\r",80,"");
	free(cache);

}

uint64_t benchmark_mine(uint8_t* seed, uint64_t block_height, uint8_t printing){
	uint64_t  result       = 0;
	uint64_t  temp         = 0;
	uint64_t* dataset_64   = (uint64_t*)calloc(536870912,8);
	if (!dataset_64) error_exit(1);
	uint8_t*  dataset      = (uint8_t*)dataset_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	char      buffer[65]   = {0};
	uint32_t  iterations   = ITERATIONS<<6;
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	printf("\tSeed calculation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	if(printing){
		benchmark_dataset_generation(seed, dataset_64);
	} else {
		dataset_from_seed(seed, dataset_64);
	}
	printf("\tDataset generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	if(printing){
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		for(uint8_t j=0;j<64;j++){
			for(uint32_t i=0;i<ITERATIONS;i++){
				equihashimoto_full(seed, dataset, result);
				temp ^= result;
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint32_t i=0;i<iterations;i++){
			equihashimoto_full(seed, dataset, result);
			temp ^= result;
		}
	}
	free(dataset);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %u hashes took: %us\n",iterations, end_time-current_time);
	printf("\tHashrate is approximately: %uH/s\n", iterations/(end_time-current_time));
	printf("\tResult: %016jx\n",temp);
	return 0;
}

uint64_t benchmark_validation(uint8_t* seed, uint64_t block_height, uint8_t printing){
	uint64_t  result       = 0;
	uint64_t  temp         = 0;
	uint64_t* cache_64     = (uint64_t*)calloc(8388608,8);
	if (!cache_64) error_exit(1);
	uint8_t*  cache        = (uint8_t*)cache_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint32_t  iterations   = ITERATIONS>>6;
	char      buffer[65]   = {0};
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	printf("\tSeed calculation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	cache_from_seed(seed, cache);
	printf("\tCache generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	if(printing){
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		for(uint8_t j=0;j<64;j++){
			for(uint32_t i=0;i<iterations;i++){
				equihashimoto_light(seed, cache, result);
				temp ^= result;
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint32_t i=0;i<ITERATIONS;i++){
			equihashimoto_light(seed, cache, result);
			temp ^= result;
		}
	}
	free(cache);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %u hashes took: %us\n",ITERATIONS, end_time-current_time);
	printf("\tHashrate is approximately: %uH/s\n", ITERATIONS/(end_time-current_time));
	printf("\tResult: %016jx\n",temp);
	return 0;
}



int main(int argc, char *argv[]){
	uint8_t* seed = urand(64);
	uint8_t printing = argc==1?0:atoi(argv[1]);
	printf("\e[?25l"); // Hide cursor
	printf("Mining\n");
	benchmark_mine(seed, 10, printing);
	printf("Validation\n");
	benchmark_validation(seed, 10, printing);
	printf("\e[?25h");
	free(seed);
	return 1;
}
