#include <stdlib.h>
#include <stdint.h>
#include "pow.h"
#include "blockchain.h"

#include <stdio.h>
uint64_t mine_block(uint8_t* header, uint8_t* dataset, uint64_t difficulty){
	uint8_t   result[32] = {0};
	uint64_t* result_64  = (uint64_t*)result;
	uint64_t  nonce      = 0;
	uint64_t  temp[4]    = {0};
	nonce = rand()&0xFFFFFFFFFFFFFFFF;
	squash_pow_full(header, nonce, dataset, result);
	temp[0] = result_64[0] * difficulty;
	temp[1] = result_64[1] * difficulty;
	temp[2] = result_64[2] * difficulty;
	temp[3] = result_64[3] * difficulty;
	while(  (temp[0]/difficulty != result_64[0]) &&
		(temp[1]/difficulty != result_64[1]) &&
		(temp[2]/difficulty != result_64[2]) &&
		(temp[3]/difficulty != result_64[3])
		){
		nonce = (rand()&0xFFFFFFFFFFFFFFFF) | ((rand()&0xFFFFFFFFFFFFFFFF)<<32);
		squash_pow_full(header, nonce, dataset, result);
		temp[0] = result_64[0] * difficulty;
		temp[1] = result_64[1] * difficulty;
		temp[2] = result_64[2] * difficulty;
		temp[3] = result_64[3] * difficulty;
	}
	return nonce;
}

void mine(uint64_t block_height){
	uint8_t* seed    = malloc(sizeof(uint8_t) * 32);
	uint8_t* dataset = malloc(sizeof(uint8_t) * 4294967296);
	if (dataset == NULL || seed == NULL) exit(1);
	get_seedhash(block_height, seed);
	dataset_from_seed(seed, dataset);
	free(seed);
	uint8_t  header[80] = {0};
	uint64_t nonce      = 0;
	uint64_t difficulty = getdifficulty(block_height);
	get_current_header(header);
	while(1){
		nonce = mine_block(header, dataset, difficulty);
		submitblock(header, nonce);
	}
}

int main(){
	mine(10);

}


