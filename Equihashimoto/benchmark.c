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

uint64_t benchmark_mine(uint8_t* seed, uint64_t block_height, uint8_t printing, uint64_t difficulty){
	uint64_t  nonce        = urand64();
	uint64_t  prevNonce    = nonce;
	uint64_t* dataset_64   = (uint64_t*)calloc(536870912,8);
	if (!dataset_64) error_exit(1);
	uint8_t*  dataset      = (uint8_t*)dataset_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	if(printing){
		benchmark_dataset_generation(seed, dataset_64);
	} else {
		dataset_from_seed(seed, dataset_64);
	}
	//printf("\tDataset generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	nonce = equihashimoto_full(seed, dataset, difficulty, nonce);
	nonce-=prevNonce;
	printf("\n2\n");
	free(dataset_64);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took: %us\n",nonce, end_time-current_time);
	//printf("\tHashrate is approximately: %luH/s\n", nonce/(end_time-current_time));
	return 0;
}

uint64_t benchmark_validation(uint8_t* seed, uint64_t block_height, uint8_t printing, uint64_t difficulty){
	uint64_t  nonce        = urand64();
	uint64_t  prevNonce    = nonce;
	uint64_t* cache_64     = (uint64_t*)calloc(8388608,8);
	if (!cache_64) error_exit(1);
	uint8_t*  cache        = (uint8_t*)cache_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	cache_from_seed(seed, cache);
	printf("\tCache generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	nonce = equihashimoto_light(seed, cache, difficulty, nonce);
	nonce-=prevNonce;
	free(cache);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took: %us\n",nonce, end_time-current_time);
	//printf("\tHashrate is approximately: %luH/s\n", nonce/(end_time-current_time));
	return 0;
}



int main(int argc, char *argv[]){
	uint8_t* seed = urand(64);
	uint8_t printing = argc<2?0:atoi(argv[1]);
	uint64_t difficulty = argc<3?0xffff:atoi(argv[2]);
	printf("\e[?25l"); // Hide cursor
	printf("Mining\n");
	benchmark_mine(seed, 10, printing, difficulty);
	printf("Validation\n");
	benchmark_validation(seed, 10, printing, difficulty);
	printf("\e[?25h");
	free(seed);
	return 1;
}
