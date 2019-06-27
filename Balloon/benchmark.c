// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash.h"
#include "config.h"

uint64_t benchmark(uint64_t* seed_64, uint8_t printing, uint64_t ITERATIONS){
	uint64_t  result_64[4] = {0};
	uint8_t*  result       = (uint8_t*)result_64;
	uint64_t  temp[4]      = {0};
	uint8_t*  seed         = (uint8_t*)seed_64;
	uint32_t* seed_32      = (uint32_t*)seed_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint64_t  iterations   = ITERATIONS>>6;
	char      buffer[65]   = {0};
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	current_time = (uint32_t)time(NULL);
	if(printing){
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		for(uint8_t j=0;j<64;j++){
			for(uint64_t i=0;i<iterations;i++){
				balloon(seed, result);
				temp[0] ^= result_64[0]; temp[1] ^= result_64[1];
				temp[2] ^= result_64[2]; temp[3] ^= result_64[3];
				for(uint8_t i=0; i< 8; i++) seed_32[i]++;
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint64_t i=0;i<ITERATIONS;i++){
			balloon(seed, result);
			temp[0] ^= result_64[0]; temp[1] ^= result_64[1];
			temp[2] ^= result_64[2]; temp[3] ^= result_64[3];
			for(uint8_t i=0; i< 8; i++) seed_32[i]++;
		}
	}
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took: %us\n",ITERATIONS, end_time-current_time);
	printf("\tHashrate is approximately: %luH/s\n", ITERATIONS/(end_time-current_time));
	printf("\tResult: %016jx,%016jx,%016jx,%016jx\n",temp[0],temp[1],temp[2],temp[3]);
	return 0;
}



int main(int argc, char *argv[]){
	uint8_t   printing   = argc>1?atoi(argv[1]):0;
	uint8_t   iterShifts = argc>2?atoi(argv[2]):20;
	uint32_t  seed       = argc>3?atoi(argv[3]):0x89ABCDEF;
	uint32_t  seed32[16] = {0};
	uint64_t* seed64    = (uint64_t*)seed32;
	uint64_t  iterations = 1;
	srand(seed);
	for(uint8_t i=0; i<iterShifts; i++) iterations<<=1;
	for(uint8_t i=0;i<16;i++) seed32[i] = rand();
	printf("\e[?25l"); // Hide cursor
	printf("Parameters\n");
	printf("\tProgressbar: %s\n", printing?"yes":"no");
	printf("\tIterations: %lu\n", iterations);
	printf("\tSeed: %08x\n", seed);
	printf("Config\n");
	printf("\tCache Size: %uKiB\n", SIZE/1024);
	printf("\tMixing Iterations: %u\n", 1048576);
	printf("\tMemory Threads: %u\n", 16);
	printf("Mining\n");
	benchmark(seed64, printing, iterations);
	printf("\e[?25h");
	return 1;
}
