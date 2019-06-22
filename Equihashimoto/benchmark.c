// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "benchmark_hash.h"
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

uint64_t benchmark_mine(uint8_t* seed, uint64_t block_height, uint8_t printing, uint64_t iterations){
	uint64_t  nonce        = urand64();
	uint64_t* dataset_64   = (uint64_t*)calloc(536870912,8);
	if (!dataset_64) error_exit(1);
	uint8_t*  dataset      = (uint8_t*)dataset_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint64_t retValue      = 0;
	if(printing) benchmark_dataset_generation(seed, dataset_64);
	else dataset_from_seed(seed, dataset_64);
	printf("\tDataset generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	equihashimoto_full(seed, dataset, nonce, iterations, &retValue);
	free(dataset_64);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took: %us\n",iterations, end_time-current_time);
	printf("\tHashrate is approximately: %luH/s\n", iterations/(end_time-current_time));
	printf("\tReturn Value is: %016jx\n", retValue);
	return 0;
}

uint64_t benchmark_validation(uint8_t* seed, uint64_t block_height, uint8_t printing, uint64_t iterations){
	iterations >>= 10;
	uint64_t  nonce        = urand64();
	uint64_t* cache_64     = (uint64_t*)calloc(8388608,8);
	if (!cache_64) error_exit(1);
	uint8_t*  cache        = (uint8_t*)cache_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint64_t retValue      = 0;
	cache_from_seed(seed, cache);
	printf("\tCache generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	equihashimoto_light(seed, cache, nonce, iterations, &retValue);
	free(cache);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took: %us\n",iterations, end_time-current_time);
	//printf("\tHashrate is approximately: %luH/s\n", iterations/(end_time-current_time));
	printf("\tReturn Value is: %016jx\n", retValue);
	return 0;
}



int main(int argc, char *argv[]){
	uint8_t* seed = urand(64);
	uint8_t printing = argc<2?0:atoi(argv[1]);
	uint8_t iterShifts = argc<3?10:atoi(argv[2]);
	uint64_t iterations = 1;
	for(uint8_t i=0; i<iterShifts; i++) iterations<<=1;	
	printf("\e[?25l"); // Hide cursor
	printf("Mining\n");
	benchmark_mine(seed, 10, printing, iterations);
	printf("Validation\n");
	benchmark_validation(seed, 10, printing, iterations);
	printf("\e[?25h");
	free(seed);
	return 1;
}
