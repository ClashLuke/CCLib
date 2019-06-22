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

uint64_t benchmark_mine(uint8_t* hash, uint64_t block_height, uint8_t printing, uint64_t iterations){
	uint64_t  nonce        = urand64();
	uint64_t* dataset_64   = (uint64_t*)calloc(536870912,8);
	if (!dataset_64) error_exit(1);
	uint8_t*  dataset      = (uint8_t*)dataset_64;
	uint32_t  current_time = (uint32_t)time(NULL);
	uint64_t retValue      = 0;
	if(printing){
		benchmark_dataset_generation(hash, dataset_64);
	} else {
		dataset_from_seed(hash, dataset_64);
	}
	printf("\tDataset generation took: %us\n",(uint32_t)time(NULL)-current_time);
	current_time = (uint32_t)time(NULL);
	// Equihashimoto takes a hash as input
	// and returns a nonce which, when added to the hash,
	// can be used to perform a calculation inspired by equihash
	// on a dataset using a generation inspired by dagger hashimoto.
	uint8_t   item[32]  = {0};
	uint8_t*  item_1    = &item[1];
	uint8_t*  item_2    = &item[2];
	uint8_t*  item_3    = &item[3];
	uint8_t*  item_4    = &item[4];
	uint8_t*  item_5    = &item[5];
	uint8_t*  item_6    = &item[6];
	uint8_t*  item_7    = &item[7];
	uint8_t*  item_8    = &item[8];
	uint8_t*  item_9    = &item[9];
	uint8_t*  item_10   = &item[10];
	uint8_t*  item_11   = &item[11];
	uint8_t*  item_12   = &item[12];
	uint8_t*  item_13   = &item[13];
	uint8_t*  item_14   = &item[14];
	uint8_t*  item_15   = &item[15];
	uint32_t* item32_0  =   (uint32_t*)item;
	uint32_t* item32_1  = &((uint32_t*)item)[1];
	uint32_t* item32_2  = &((uint32_t*)item)[2];
	uint32_t* item32_3  = &((uint32_t*)item)[3];
	uint64_t* item64_0  =   (uint64_t*)item;
	uint64_t* item64_1  = &((uint64_t*)item)[1];
	uint64_t* item64_2  = &((uint64_t*)item)[2];
	uint64_t* item64_3  = &((uint64_t*)item)[3];
	uint32_t* hash32_0  =   (uint32_t*)hash;
	uint32_t* hash32_1  = &((uint32_t*)hash)[1];
	uint32_t* hash32_2  = &((uint32_t*)hash)[2];
	uint32_t* hash32_3  = &((uint32_t*)hash)[3];
	uint32_t* hash32_4  = &((uint32_t*)hash)[4];
	uint32_t* hash32_5  = &((uint32_t*)hash)[5];
	uint32_t* hash32_6  = &((uint32_t*)hash)[6];
	uint32_t* hash32_7  = &((uint32_t*)hash)[7];
	uint32_t* hash32_8  = &((uint32_t*)hash)[8];
	uint32_t* hash32_9  = &((uint32_t*)hash)[9];
	uint32_t* hash32_10 = &((uint32_t*)hash)[10];
	uint32_t* hash32_11 = &((uint32_t*)hash)[11];
	uint32_t* hash32_12 = &((uint32_t*)hash)[12];
	uint32_t* hash32_13 = &((uint32_t*)hash)[13];
	uint32_t* hash32_14 = &((uint32_t*)hash)[14];
	uint32_t* hash32_15 = &((uint32_t*)hash)[15];
	uint64_t* hash64_0  =   (uint64_t*)hash;
	uint64_t* hash64_1  = &((uint64_t*)hash)[1];
	uint64_t* hash64_2  = &((uint64_t*)hash)[2];
	uint64_t* hash64_3  = &((uint64_t*)hash)[3];
	uint64_t* hash64_4  = &((uint64_t*)hash)[4];
	uint64_t* hash64_5  = &((uint64_t*)hash)[5];
	uint64_t* hash64_6  = &((uint64_t*)hash)[6];
	uint64_t* hash64_7  = &((uint64_t*)hash)[7];
	*hash64_0 += nonce; *hash64_1 += nonce;
	*hash64_2 += nonce; *hash64_3 += nonce;
	*hash64_4 += nonce; *hash64_5 += nonce;
	*hash64_6 += nonce; *hash64_7 += nonce;
	for(uint64_t i=0; i<iterations; i++){
		*item     = dataset[*hash32_0 ]; *item_1   = dataset[*hash32_1 ];
		*item_2   = dataset[*hash32_2 ]; *item_3   = dataset[*hash32_3 ]; 
		*item_4   = dataset[*hash32_4 ]; *item_5   = dataset[*hash32_5 ];
		*item_6   = dataset[*hash32_6 ]; *item_7   = dataset[*hash32_7 ];
		*item_8   = dataset[*hash32_8 ]; *item_9   = dataset[*hash32_9 ];
		*item_10  = dataset[*hash32_10]; *item_11  = dataset[*hash32_11];
		*item_12  = dataset[*hash32_12]; *item_13  = dataset[*hash32_13];
		*item_14  = dataset[*hash32_14]; *item_15  = dataset[*hash32_15];
		*item64_0 = *((uint64_t*)&(dataset[*item32_0]));
		*item64_1 = *((uint64_t*)&(dataset[*item32_1]));
		*item64_2 = *((uint64_t*)&(dataset[*item32_2]));
		*item64_3 = *((uint64_t*)&(dataset[*item32_3]));
		retValue ^= *item64_0 ^ *item64_1 ^ *item64_2 ^ *item64_3;
		nonce++;
		(*hash64_0)++; (*hash64_1)++;
		(*hash64_2)++; (*hash64_3)++;
	}
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
