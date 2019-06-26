#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "pow.h"
#include "config.h"

void mash_full(uint8_t* data, uint8_t* dataset, uint8_t* out){
	uint64_t  hash_64[MEMORY_THREADS*16]     = {0};
	uint32_t* hash_32         = (uint32_t*)hash_64;
	uint32_t* data_32         = (uint32_t*)data;
	uint64_t* out_64          = (uint64_t*)out;
	for(uint32_t j=0; j<MEMORY_THREADS; j++){
		for(uint8_t i=0; i< 8; i++) hash_64[i] = *((uint64_t*)&dataset[data_32[i]]);
		for(uint8_t i=0; i<16; i++) hash_64[i] = *((uint64_t*)&dataset[hash_32[i]]);
	}
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
		for(uint32_t j=0; j<MEMORY_THREADS*16; j+=16){
			for(uint8_t k=0; k<32; k++ ) hash_32[k+j*2] = *((uint32_t*)&dataset[hash_32[k+j*2]]);
			for(uint8_t k=0; k<16; k+=2) hash_64[k+j]   += hash_64[k+j+1];
			for(uint8_t k=0; k<32; k++ ) hash_32[k+j*2] = *((uint32_t*)&dataset[hash_32[k+j*2]]);
			for(uint8_t k=0; k<16; k+=2) hash_64[k+j+1] += hash_64[k+j];
		}
	}
	for(uint32_t j=0; j<MEMORY_THREADS*16; j+=16){
		hash_64[j+ 0] += hash_64[j+ 1]; hash_64[j+ 2] += hash_64[j+ 3];
		hash_64[j+ 4] += hash_64[j+ 5]; hash_64[j+ 6] += hash_64[j+ 7];
		hash_64[j+ 8] += hash_64[j+ 9]; hash_64[j+10] += hash_64[j+11];
		hash_64[j+12] += hash_64[j+13]; hash_64[j+14] += hash_64[j+15];
		hash_64[j+ 0] += hash_64[j+ 2]; hash_64[j+ 4] += hash_64[j+ 6];
		hash_64[j+ 8] += hash_64[j+10]; hash_64[j+12] += hash_64[j+14];
	}

	*out_64   = hash_64[ 0]; out_64[1] = hash_64[ 4];
	out_64[2] = hash_64[ 8]; out_64[3] = hash_64[12];

	for(uint32_t j=0; j<MEMORY_THREADS*16; j+=16){
#ifndef BENCHMARK
		if(((hash_64[j   ])<=(*out_64  ))
		&& ((hash_64[j+ 4])<=(out_64[1]))
		&& ((hash_64[j+ 8])<=(out_64[2]))
		&& ((hash_64[j+12])<=(out_64[3]))){
			*out_64   = hash_64[j  ]; out_64[1] = hash_64[j+ 4];
			out_64[2] = hash_64[j+8]; out_64[3] = hash_64[j+12];
		}
#else
		*out_64   ^= hash_64[j  ]; out_64[1] ^= hash_64[j+ 4];
		out_64[2] ^= hash_64[j+8]; out_64[3] ^= hash_64[j+12];
#endif
	}
}

uint64_t calcItem64(uint32_t itemNumber, uint8_t* cache){
	uint8_t   item[32] = {0};
	uint64_t* item_64  = (uint64_t*)item;
	uint64_t  out0     = 0; 
	uint64_t  out1     = 0; 
	uint8_t   innerPos = itemNumber&0x1f;
	uint8_t   pos      = itemNumber&0x7;
	itemNumber>>=3;
	if(innerPos>0x18){
		calcDatasetItem(cache, itemNumber, item_64);
		out0   = item_64[3];
		calcDatasetItem(cache, 1+itemNumber, item_64);
		out1   = item_64[0];
		for(uint8_t i=0; i<  pos; i++) out0>>=8;
		for(uint8_t i=0; i<8-pos; i++) out1<<=8;
		out0  |= out1;
	}else{
		if(!pos){
			calcDatasetItem(cache, itemNumber, item_64);
			out0 = item_64[innerPos/8];
		} else {
			calcDatasetItem(cache, itemNumber, item_64);
			out0   = item_64[innerPos/8];
			out1   = item_64[1+(innerPos/8)];
			for(uint8_t i=0; i<  pos; i++) out0>>=8;
			for(uint8_t i=0; i<8-pos; i++) out1<<=8;
			out0  |= out1;
		}
	}
	return(out0);
}

void calcItem32(uint32_t* itemNumber, uint8_t* cache){
	uint8_t   item[32] = {0};
	uint32_t* item_32  = (uint32_t*)item;
	uint64_t* item_64  = (uint64_t*)item;
	uint64_t  out0     = 0; 
	uint64_t  out1     = 0; 
	uint8_t   innerPos = (*itemNumber)&0x1f;
	uint8_t   pos      = (*itemNumber)&0x3;
	(*itemNumber)>>=3;
	if(innerPos>0x1C){
		calcDatasetItem(cache, *itemNumber, item_64);
		out0   = item_32[7];
		calcDatasetItem(cache, 1+(*itemNumber), item_64);
		out1   = item_32[0];
		for(uint8_t i=0; i<  pos; i++) out0>>=8;
		for(uint8_t i=0; i<4-pos; i++) out1<<=8;
		out0  |= out1;
	}else{
		if(!pos){
			calcDatasetItem(cache, *itemNumber, item_64);
			out0 = item_32[innerPos/4];
		} else {
			calcDatasetItem(cache, *itemNumber, item_64);
			out0   = item_32[innerPos/4];
			out1   = item_32[1+(innerPos/4)];
			for(uint8_t i=0; i<  pos; i++) out0>>=8;
			for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			out0  |= out1;
		}
	}
	*itemNumber = out0;
}

void mash_light(uint8_t* data, uint8_t* cache, uint8_t* out){
	uint64_t  hash_64[16]     = {0};
	uint32_t* hash_32         = (uint32_t*)hash_64;
	uint32_t* data_32         = (uint32_t*)data;
	uint64_t* out_64          = (uint64_t*)out;
	*hash_64    = calcItem64(*data_32,    cache);
	hash_64[ 1] = calcItem64(data_32[ 1], cache);
	hash_64[ 2] = calcItem64(data_32[ 2], cache);
	hash_64[ 3] = calcItem64(data_32[ 3], cache);
	hash_64[ 4] = calcItem64(data_32[ 4], cache);
	hash_64[ 5] = calcItem64(data_32[ 5], cache);
	hash_64[ 6] = calcItem64(data_32[ 6], cache);
	hash_64[ 7] = calcItem64(data_32[ 7], cache);
	*hash_64    = calcItem64(*hash_32,    cache);
	hash_64[ 1] = calcItem64(hash_32[ 1], cache);
	hash_64[ 2] = calcItem64(hash_32[ 2], cache);
	hash_64[ 3] = calcItem64(hash_32[ 3], cache);
	hash_64[ 4] = calcItem64(hash_32[ 4], cache);
	hash_64[ 5] = calcItem64(hash_32[ 5], cache);
	hash_64[ 6] = calcItem64(hash_32[ 6], cache);
	hash_64[ 7] = calcItem64(hash_32[ 7], cache);
	hash_64[ 8] = calcItem64(hash_32[ 8], cache);
	hash_64[ 9] = calcItem64(hash_32[ 9], cache);
	hash_64[10] = calcItem64(hash_32[10], cache);
	hash_64[11] = calcItem64(hash_32[11], cache);
	hash_64[12] = calcItem64(hash_32[12], cache);
	hash_64[13] = calcItem64(hash_32[13], cache);
	hash_64[14] = calcItem64(hash_32[14], cache);
	hash_64[15] = calcItem64(hash_32[15], cache);
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
		for(uint8_t j=0; j<32; j++) calcItem32(&hash_32[j], cache);
		for(uint8_t j=0; j<16; j+=2) hash_64[j]   += hash_64[j+1];
		for(uint8_t j=0; j<32; j++) calcItem32(&hash_32[j], cache);
		for(uint8_t j=0; j<16; j+=2) hash_64[j+1] += hash_64[j];
	}
	*hash_64    += hash_64[ 1]; hash_64[ 2] += hash_64[ 3];
	hash_64[ 4] += hash_64[ 5]; hash_64[ 6] += hash_64[ 7];
	hash_64[ 8] += hash_64[ 9]; hash_64[10] += hash_64[11];
	hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
	*hash_64    += hash_64[ 2]; hash_64[ 4] += hash_64[ 6];
	hash_64[ 8] += hash_64[10]; hash_64[12] += hash_64[14];
	*out_64      = *hash_64;    out_64[  1]  = hash_64[ 4];
	out_64[  2]  = hash_64[ 8]; out_64[  3]  = hash_64[12];
}


