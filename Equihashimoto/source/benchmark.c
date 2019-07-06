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
#include "config.h"

uint64_t benchmark_mine(uint64_t* seed_64, uint8_t printing, uint64_t difficulty, uint64_t ITERATIONS, uint64_t nonce){
	uint64_t* dataset_64   = (uint64_t*)calloc((ITEMS>>3)+1,8);
	if (!dataset_64) error_exit(1);
	uint8_t*  seed         = (uint8_t*)seed_64;
	uint32_t* seed_32      = (uint32_t*)seed_64;
	uint32_t* result       = &seed_32[8];
	uint8_t*  dataset      = (uint8_t*)dataset_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	char      buffer[65]   = {0};
	uint64_t  iterations   = ITERATIONS>>6;
	uint32_t  temp[2]      = {0};
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	current_time = (uint32_t)time(NULL);
	calcDataset(seed, dataset_64);
	uint8_t datasetGenerationTime = (uint32_t)time(NULL)-current_time;
	current_time = (uint32_t)time(NULL); 
	if(printing){
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		for(uint8_t j=0;j<64;j++){
			for(uint64_t i=0;i<iterations;i++){
				mash_full(seed, dataset, nonce,  difficulty, result);
				temp[0] ^= seed_32[8]; temp[1] ^= seed_32[9]; nonce++;
				(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
				seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint64_t i=0;i<ITERATIONS;i++){
			mash_full(seed, dataset, nonce, difficulty, result);
			temp[0] ^= seed_32[8]; temp[1] ^= seed_32[9]; nonce++;
			(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
			seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
		}
	}
	free(dataset);
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took:  %us\n",ITERATIONS, end_time-current_time);
	printf("\tDataset generation Time:  %us\n",datasetGenerationTime);
	printf("\tHashrate is approximately:  %lu H/s\n", difficulty*ITERATIONS/(end_time-current_time));
	printf("\tResult:  %08x,%08x",temp[0],temp[1]);
	printf("\n");
	return 0;
}

uint64_t benchmark_validation(uint64_t* seed_64, uint8_t printing, uint64_t difficulty, uint64_t ITERATIONS, uint64_t nonce){
	uint64_t  temp         = 0;
	uint8_t*  seed         = (uint8_t*)seed_64;
	uint32_t* seed_32      = (uint32_t*)seed_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint64_t  iterations   = ITERATIONS<<26;
	char      buffer[65]   = {0};
	for(uint16_t i=0;i<64;i++) buffer[i]=' ';
	current_time = (uint32_t)time(NULL);
	if(printing){
		printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		for(uint8_t j=0;j<64;j++){
			for(uint64_t i=0;i<ITERATIONS<<20;i++){
				uint8_t a = mash_light(seed, difficulty);
				temp ^= a; nonce++;
				crc32i(&seed_32[8]); crc32i(&seed_32[9]); crc32i(&seed_32[10]);
			}
			buffer[j] = '#';
			printf("\rBenchmarking: [%s]",buffer); fflush(stdout);
		}
		printf("\r%*s\r",80,"");
	} else {
		for(uint64_t i=0;i<iterations;i++){
			uint8_t a = mash_light(seed, difficulty);
			temp ^= a; nonce++;
			crc32i(&seed_32[8]); crc32i(&seed_32[9]); crc32i(&seed_32[10]);
		}
	}
	uint32_t end_time = (uint32_t)time(NULL);
	printf("\tCalculation of %lu hashes took:  %us\n",iterations, end_time-current_time);
	uint64_t out = (10*iterations)/(end_time-current_time);
	printf("\tHashrate is approximately:  %lu.%lu H/s\n",out/10,out%10);
	printf("\tResult:  %016jx\n",temp);
	return 0;
}



int main(int argc, char *argv[]){
	uint8_t   printing     = argc>1?atoi(argv[1]):0;
	uint8_t   iterShifts   = argc>2?atoi(argv[2]):20;
	uint8_t   diffShifts   = argc>3?atoi(argv[3]):20;
	uint32_t  seed         = argc>4?atoi(argv[4]):0x89ABCDEF;
	uint32_t  seed32_0[16] = {0};
	uint64_t* seed64_0     = (uint64_t*)seed32_0;
	uint32_t  seed32_1[16] = {0};
	uint64_t* seed64_1     = (uint64_t*)seed32_1;
	uint64_t  iterations   = 1;
	uint64_t  difficulty   = 1;
	uint64_t  nonce        = 0;
	srand(seed);
	nonce = rand();
	for(uint8_t i=0; i<32; i++) nonce<<=1;
	for(uint8_t i=0; i<iterShifts; i++) iterations<<=1;
	for(uint8_t i=0; i<diffShifts; i++) difficulty<<=1;
	nonce+=rand();
	for(uint8_t i=0;i<8;i++) seed32_0[i] = seed32_1[i] = rand();
	printf("\e[?25l"); // Hide cursor
	printf("Parameters\n");
	printf("\tProgressbar:  %s\n", printing?"yes":"no");
	printf("\tIterations\n\t\tFull:  %lu\n\t\tLight:  %lu\n", iterations, iterations<<26);
	printf("\tSeed:  %08x\n", seed);
	printf("\tDifficulty:  %lu\n", difficulty);
	printf("Mining\n");
	benchmark_mine(seed64_0, printing, difficulty, iterations, nonce);
	printf("Validation\n");
	benchmark_validation(seed64_1, printing, difficulty, iterations, nonce);
	printf("\e[?25h");
	return 1;
}
