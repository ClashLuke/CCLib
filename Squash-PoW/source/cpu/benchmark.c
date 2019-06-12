// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pow.h"
#include "error.h"

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

uint64_t benchmark_mine(uint64_t block_height, uint8_t printing){
	uint64_t  result_64[4] = {0};
	uint8_t*  result       = (uint8_t*)result_64;
	uint64_t  temp[4]      = {0};
	uint8_t   header[88]   = {0};
	uint64_t  seed_64[4]   = {0};
	uint64_t* dataset_64   = (uint64_t*)calloc(536870912,8);
	if (!dataset_64) error_exit(1);
	uint8_t*  seed         = (uint8_t*)seed_64;
	uint8_t*  dataset      = (uint8_t*)dataset_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	char      buffer[65]   = {0};
	uint32_t  iterations   = ITERATIONS;
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	get_seedhash(block_height, seed);
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
			for(uint32_t i=0;i<iterations;i++){
				squash_pow_full(header, i+(j*ITERATIONS), dataset_64, result);
				temp[0] ^= result_64[0]; temp[1] ^= result_64[1];
				temp[2] ^= result_64[2]; temp[3] ^= result_64[3];
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint32_t i=0;i<(iterations);i++){
			squash_pow_full(header, i, dataset_64, result);
			temp[0] ^= result_64[0]; temp[1] ^= result_64[1];
			temp[2] ^= result_64[2]; temp[3] ^= result_64[3];
		}
	}
	free(dataset);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %u hashes took: %us\n",iterations<<6, end_time-current_time);
	printf("\tHashrate is approximately: %uH/s\n", (iterations<<6)/(end_time-current_time));
	printf("\tResult: %016jx,%016jx,%016jx,%016jx\n",temp[0],temp[1],temp[2],temp[3]);
	return 0;
}

uint64_t benchmark_validation(uint64_t block_height, uint8_t printing){
	uint64_t  result_64[4] = {0};
	uint8_t*  result       = (uint8_t*)result_64;
	uint64_t  temp[4]      = {0};
	uint8_t   header[88]   = {0};
	uint64_t  seed_64[4]   = {0};
	uint64_t* cache_64     = (uint64_t*)calloc(8388608,8);
	if (!cache_64) error_exit(1);
	uint8_t*  seed         = (uint8_t*)seed_64;
	uint8_t*  cache        = (uint8_t*)cache_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint32_t  iterations   = ITERATIONS;
	char      buffer[65]   = {0};
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	get_seedhash(block_height, seed);
	printf("\tSeed calculation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	cache_from_seed(seed, cache);
	printf("\tCache generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	if(printing){
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		for(uint8_t j=0;j<64;j++){
			for(uint32_t i=0;i<ITERATIONS;i++){
				squash_pow_light(header, i+(j*ITERATIONS), cache, result);
				temp[0] ^= result_64[0]; temp[1] ^= result_64[1];
				temp[2] ^= result_64[2]; temp[3] ^= result_64[3];
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint32_t i=0;i<(iterations);i++){
			squash_pow_light(header, i, cache, result);
			temp[0] ^= result_64[0]; temp[1] ^= result_64[1];
			temp[2] ^= result_64[2]; temp[3] ^= result_64[3];
		}
	}
	free(cache);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %u hashes took: %us\n",ITERATIONS<<6, end_time-current_time);
	printf("\tHashrate is approximately: %uH/s\n", iterations/(end_time-current_time));
	printf("\tResult: %016jx,%016jx,%016jx,%016jx\n",temp[0],temp[1],temp[2],temp[3]);
	return 0;
}



int main(int argc, char *argv[]){
	uint8_t printing = argc==1?0:atoi(argv[1]);
	printf("\e[?25l"); // Hide cursor
	printf("Mining\n");
	benchmark_mine(10, printing);
	printf("Validation\n");
	benchmark_validation(10, printing);
	printf("\e[?25h");
	return 1;
}
