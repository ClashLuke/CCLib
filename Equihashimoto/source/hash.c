// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "pow.h"

#define MAX32   0xffffffff
#define MAX32R   0x1fffffff
//#define REDUCED
#define ROUNDS 6

void mash_full(uint8_t* data, uint8_t* dataset, uint8_t* out){
	uint32_t* out32 = (uint32_t*)out;
	uint64_t* dataset64 = (uint64_t*)dataset;
	uint32_t  item = 0;
	calcDataset(data, dataset64);
#ifndef REDUCED
	for(uint32_t i=0; i<MAX32; i++){
		for(uint32_t j=1+i; j<MAX32; j++){
			item = *(uint32_t*)&dataset[i];
			if(item==*(uint32_t*)&dataset[j]){
			#if ROUNDS > 2
			for(uint32_t k=1+j; k<MAX32; k++){
			if(item==*(uint32_t*)&dataset[k]){
			#if ROUNDS > 3
			for(uint32_t l=1+k; l<MAX32; l++){
			if(item==*(uint32_t*)&dataset[l]){
			#if ROUNDS > 4
			for(uint32_t m=1+l; m<MAX32; m++){
			if(item==*(uint32_t*)&dataset[m]){
			#if ROUNDS > 5
			for(uint32_t n=1+m; n<MAX32; n++){
			if(item==*(uint32_t*)&dataset[n]){
			#if ROUNDS > 6
			for(uint32_t o=1+n; o<MAX32; o++){
			if(item==*(uint32_t*)&dataset[o]){
			#if ROUNDS > 7
			for(uint32_t p=1+o; p<MAX32; p++){
			if(item==*(uint32_t*)&dataset[p]){
			#endif
			#endif
			#endif
			#endif
			#endif
			#endif
			*out32 = i;
			out32[1] = j;
			#if ROUNDS > 2
			out32[2] = k;
			#if ROUNDS > 3
			out32[3] = l;
			#if ROUNDS > 4
			out32[4] = m;
			#if ROUNDS > 5
			out32[5] = n;
			#if ROUNDS > 6
			out32[6] = o;
			#if ROUNDS > 7
			out32[7] = p;
			#endif
			#endif
			#endif
			#endif
			#endif
			#endif
			return;
			#if ROUNDS > 2
			}
			}
			#if ROUNDS > 3
			}
			}
			#if ROUNDS > 4
			}
			}
			#if ROUNDS > 5
			}
			}
			#if ROUNDS > 6
			}
			}
			#if ROUNDS > 7
			}
			}
			#endif
			#endif
			#endif
			#endif
			#endif
			#endif
			}
		}
	}
	printf("Found nothing, next nonce\n");
#else
	uint32_t* dataset32 = (uint32_t*)dataset;
	for(uint32_t i=0; i<MAX32R; i++){
		for(uint32_t j=1+i; j<MAX32R; j++){
			item = dataset32[i];
			if(item==dataset32[j]){
				printf("%u: %u,%u\n",item, i,j);
				for(uint32_t k=1+j; k<MAX32R; k++){
					if(item==dataset32[k]){
						for(uint32_t l=1+k; k<MAX32R; l++){
							if(item==dataset32[l]){
								*out32 = i; out32[1] = j; out32[2] = k; out32[3] = l;
								return;
							}
						}
					}
				}
			}
		}
	}
#endif
}

uint32_t calcItem32(uint8_t* data, uint32_t itemNumber){
	uint8_t   item[128] = {0};
	uint32_t* item_32  = (uint32_t*)item;
	uint64_t* item_64  = (uint64_t*)item;
	uint32_t* data_32  = (uint32_t*)data;
	uint32_t  out0     = 0; 
	uint32_t  out1     = 0; 
	uint8_t   innerPos = itemNumber&0x7f;
	uint8_t   pos      = itemNumber&0x3;
	itemNumber>>=7;
	(*data_32) += itemNumber; data_32[1] += itemNumber;
	data_32[2] += itemNumber; data_32[3] += itemNumber;
	data_32[4] += itemNumber; data_32[5] += itemNumber;
	data_32[6] += itemNumber; data_32[7] += itemNumber;
	itemNumber<<=4;
	if(innerPos>0x7c){
		calcDatasetItem(data, itemNumber, item_64);
		out0   = item_32[31];
		calcDatasetItem(data, 16+itemNumber, item_64);
		out1   = item_32[ 0];
		for(uint8_t i=0; i<  pos; i++) out0>>=8;
		for(uint8_t i=0; i<4-pos; i++) out1<<=8;
		out0  |= out1;
	}else{
		if(!pos){
			calcDatasetItem(data, itemNumber, item_64);
			out0 = item_32[innerPos/4];
		} else {
			calcDatasetItem(data, itemNumber, item_64);
			out0   = item_32[innerPos/4];
			out1   = item_32[1+(innerPos/4)];
			for(uint8_t i=0; i<  pos; i++) out0>>=8;
			for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			out0  |= out1;
		}
	}
	return out0;
}

uint8_t mash_light(uint8_t* data){
	uint32_t* data32 = (uint32_t*)&data[32];
	uint32_t  i = calcItem32(data, *data32);
	uint32_t  j = calcItem32(data, data32[1]);
	uint32_t  k = calcItem32(data, data32[2]);
	if(i==j && i==k) return 1;
	return 0;
}
