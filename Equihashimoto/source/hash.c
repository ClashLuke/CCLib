// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "pow.h"
#include "config.h"

#define MAX32   0xffffffff


void mash_full(uint8_t* data, uint8_t* dataset, uint8_t* out){
	uint32_t* out32 = (uint32_t*)out;
	uint64_t* dataset64 = (uint64_t*)dataset;
	uint32_t  item[ROUNDS] = {0};
	calcDataset(data, dataset64);
	for(uint32_t i=0; i<MAX32; i++){
		// read 64bit and process 32 elements without reading new data?
		// use 64bit instead of 32bit blocks?
		*item = *(uint32_t*)&dataset[i];
		for(uint32_t j=1+i; j<MAX32; j++){
			#if ROUNDS > 2
			item[1] = *item ^ *(uint32_t*)&dataset[j];
			for(uint32_t k=1+j; k<MAX32; k++){
			#if ROUNDS > 3
			item[2] = item[1] ^ *(uint32_t*)&dataset[k];
			for(uint32_t l=1+k; l<MAX32; l++){
			#if ROUNDS > 4
			item[3] = item[2] ^ *(uint32_t*)&dataset[l];
			for(uint32_t m=1+l; m<MAX32; m++){
			#if ROUNDS > 5
			item[4] = item[3] ^ *(uint32_t*)&dataset[m];
			for(uint32_t n=1+m; n<MAX32; n++){
			#if ROUNDS > 6
			item[5] = item[4] ^ *(uint32_t*)&dataset[n];
			for(uint32_t o=1+n; o<MAX32; o++){
			#if ROUNDS > 7
			item[6] = item[5] ^ *(uint32_t*)&dataset[o];
			for(uint32_t p=1+o; p<MAX32; p++){
			if(item[6] == *(uint32_t*)&dataset[p]){
			#else
			if(item[5] == *(uint32_t*)&dataset[o]){
			#endif
			#else
			if(item[4] == *(uint32_t*)&dataset[n]){
			#endif
			#else
			if(item[3] == *(uint32_t*)&dataset[m]){
			#endif
			#else
			if(item[2] == *(uint32_t*)&dataset[l]){
			#endif
			#else
			if(item[1] == *(uint32_t*)&dataset[k]){
			#endif
			#else
			if(*item   == *(uint32_t*)&dataset[j]){
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
			#if ROUNDS > 3
			}
			#if ROUNDS > 4
			}
			#if ROUNDS > 5
			}
			#if ROUNDS > 6
			}
			#if ROUNDS > 7
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
	}
	printf("Found nothing, next nonce\n");
}



uint8_t mash_light(uint8_t* data){
	uint32_t* data32 = (uint32_t*)&data[32];
	uint32_t  i = calcItem32(data, *data32);
	uint32_t  j = calcItem32(data, data32[1]); //change calcItem32 to calcItem
	#if ROUNDS > 2
	uint32_t  k = calcItem32(data, data32[2]);
	#if ROUNDS > 3
	uint32_t  l = calcItem32(data, data32[3]);
	#if ROUNDS > 4
	uint32_t  m = calcItem32(data, data32[4]);
	#if ROUNDS > 5
	uint32_t  n = calcItem32(data, data32[5]);
	#if ROUNDS > 6
	uint32_t  o = calcItem32(data, data32[6]);
	#if ROUNDS > 7
	uint32_t  p = calcItem32(data, data32[7]);
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	if(i==j) 
	#if ROUNDS > 2
	if(i==k) 
	#if ROUNDS > 3
	if(i==l)
	#if ROUNDS > 4
	if(i==m) 
	#if ROUNDS > 5
	if(i==n) 
	#if ROUNDS > 6
	if(i==o) 
	#if ROUNDS > 7
	if(i==p) 
	#endif
	#endif
	#endif
	#endif
	#endif
	#endif
	return 1;
	return 0;
}
