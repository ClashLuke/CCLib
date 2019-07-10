// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdint.h>
#include <string.h>
#include "pow.h"
#include "config.h"


void bidash_full(uint8_t* data, uint8_t* dataset){
	uint8_t   cache0[BLOCK+16] = {0};
	uint8_t   cache1[BLOCK+8] = {0};
	uint64_t  item      = *(uint64_t*)&data[64];  
	uint32_t* item32    = (uint32_t*)&data[64]; 
	const uint64_t diff = *(uint64_t*)&data[72];
	calcDataset(data, dataset);
	for(uint64_t j=0; j<ITEMS; j+=BLOCK){
		memcpy((void*)cache0, (void*)&dataset[j], BLOCK+16);
		for(uint32_t a=0; a<BLOCK; a++){
			if(!((*item32) ^ *(uint32_t*)&cache0[a])){
				item ^= *(uint64_t*)&cache0[8+a];	
				for(uint64_t k=j+a+1; k<ITEMS; k+=BLOCK){
					memcpy(cache1, &dataset[k], BLOCK+8);
					for(uint32_t b=0; b<BLOCK; b++){
						if((item ^ *(uint64_t*)&cache1[b]) < diff){
							*item32   = j+a;
							item32[1] = k+b;
							return;
						}
					}
				}
				item ^= *(uint64_t*)&cache0[8+a];
			}
		}
	}
}
