// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pow.h"
#include "config.h"


void mash_full(uint8_t* data, uint8_t* dataset, uint64_t item, uint64_t difficulty, uint32_t* out){
	uint64_t  j            = 0;
	uint64_t  k            = 0;
	uint8_t   cache0[8196] = {0};
	uint8_t   cache1[8200] = {0};
	uint32_t* item32       = (uint32_t*)&item; 
	calcDataset(data, (uint64_t*)dataset);
	for(; j<ITEMS; j+=8192){
	memcpy(cache0, &dataset[j], 8196);
	for(uint16_t a=0; a<8192; a++){
	if(*item32 == *(uint32_t*)&cache0[a]){
	k = 0;
	for(; k<ITEMS; k+=8192){
	memcpy(cache1, &dataset[k], 8200);
	for(uint16_t b=0; b<8192; b++){
	if((item ^ *(uint64_t*)&cache1[b]) > difficulty){
	*out   = j+a;
	out[1] = k+b;
	return;
	}
	}
	}
	}
	}
	}
}



uint8_t mash_light(uint8_t* data, uint64_t difficulty){
	uint32_t* data32 = (uint32_t*)&data[32];
	//change calcItem32 to calcItem64
	return (calcItem32(data, *data32) ^ calcItem32(data, data32[1])) < difficulty;
}
