#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "pow.h"
#include "blockchain.h"

bool validate_block(uint8_t* header, uint8_t* cache, uint8_t* result, uint64_t difficulty, uint64_t nonce){
	uint8_t   new_result[32] = {0};
	uint64_t* new_result_64  = (uint64_t*)new_result;
	uint64_t* result_64      = (uint64_t*)result;
	squash_pow_light(header, nonce, cache, new_result);
	if(     new_result_64[0] == result_64[0] && 
		new_result_64[1] == result_64[1] &&
		new_result_64[2] == result_64[2] &&
		new_result_64[3] == result_64[3]) return 0;
	uint64_t temp = {0};
	for(uint8_t i=0;i<4;i++){
		temp = result_64[i] * difficulty;
		if(temp/difficulty != result_64[i]) return 0;
		temp = new_result_64[i] * difficulty;
		if(temp/difficulty != new_result_64[i]) return 0;
	}
	return 1;
}

bool validate(uint64_t block_height){
	uint8_t* seed    = malloc(sizeof(uint8_t) * 32);
	uint8_t* cache = malloc(sizeof(uint8_t) * 67108864);
	if (cache == NULL || seed == NULL) return 0;
	get_seedhash(block_height, seed);
	cache_from_seed(seed, cache);
	free(seed);
	uint8_t  header[80] = {0};
	uint64_t nonce      = getnonce(block_height);
	uint64_t difficulty = getdifficulty(block_height);
	uint8_t  result[32] = {0};
	getheader(block_height, header);
	gethash(block_height, result);
	return validate_block(header, cache, result, difficulty, nonce);
}

int main(){
	bool init = validate(0);
	printf("%s\n", init ? "true" : "false");
}
