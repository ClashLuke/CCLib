#include <stdlib.h>
#include <stdint.h>
#include "pow.h"

uint64_t mine_block(uint8_t* header, uint8_t* dataset, uint64_t difficulty){
	uint8_t   result[32] = {0};
	uint64_t* result_64  = (uint64_t*)result;
	uint64_t  nonce      = 0;
	uint64_t  temp       = 0;
	nonce = rand()&0xFFFFFFFFFFFFFFFF;
	squash_pow_full(header, nonce, dataset, result);
	temp = result_64[0] * difficulty;
	while(temp/difficulty != result_64[0]){
		nonce = rand()&0xFFFFFFFFFFFFFFFF;
		squash_pow_full(header, nonce, dataset, result);
		temp = result_64[0] * difficulty;
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
	uint8_t* header     = getheader();
	uint64_t nonce      = 0;
	uint64_t difficulty = getdifficulty(block_height);
	while(1){
		nonce = mine_block(header, dataset, difficulty);
		submitblock(header, nonce);
	}
}
