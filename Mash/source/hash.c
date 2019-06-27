#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "pow.h"
#include "config.h"

void mash_full(uint8_t* data, uint8_t* dataset, uint8_t* out){
	uint64_t  hash_64[16]     = {0};
	uint32_t* hash_32         = (uint32_t*)hash_64;
	uint32_t* data_32         = (uint32_t*)data;
	uint64_t* out_64          = (uint64_t*)out;

	*hash_64    = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[ 1] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[ 2] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[ 3] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[ 4] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[ 5] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[ 6] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[ 7] = *((uint64_t*)&dataset[data_32[ 7]]);
	*hash_64    = *((uint64_t*)&dataset[*hash_32   ]);
	hash_64[ 1] = *((uint64_t*)&dataset[hash_32[ 1]]);
	hash_64[ 2] = *((uint64_t*)&dataset[hash_32[ 2]]);
	hash_64[ 3] = *((uint64_t*)&dataset[hash_32[ 3]]);
	hash_64[ 4] = *((uint64_t*)&dataset[hash_32[ 4]]);
	hash_64[ 5] = *((uint64_t*)&dataset[hash_32[ 5]]);
	hash_64[ 6] = *((uint64_t*)&dataset[hash_32[ 6]]);
	hash_64[ 7] = *((uint64_t*)&dataset[hash_32[ 7]]);
	hash_64[ 8] = *((uint64_t*)&dataset[hash_32[ 8]]);
	hash_64[ 9] = *((uint64_t*)&dataset[hash_32[ 9]]);
	hash_64[10] = *((uint64_t*)&dataset[hash_32[10]]);
	hash_64[11] = *((uint64_t*)&dataset[hash_32[11]]);
	hash_64[12] = *((uint64_t*)&dataset[hash_32[12]]);
	hash_64[13] = *((uint64_t*)&dataset[hash_32[13]]);
	hash_64[14] = *((uint64_t*)&dataset[hash_32[14]]);
	hash_64[15] = *((uint64_t*)&dataset[hash_32[15]]);
	data_32[ 0]++; data_32[ 2]++; data_32[ 4]++; data_32[ 6]++;
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
		hash_32[0]  = *((uint32_t*)&dataset[hash_32[0]]);
		hash_32[1]  = *((uint32_t*)&dataset[hash_32[1]]);
		hash_32[2]  = *((uint32_t*)&dataset[hash_32[2]]);
		hash_32[3]  = *((uint32_t*)&dataset[hash_32[3]]);
		hash_32[4]  = *((uint32_t*)&dataset[hash_32[4]]);
		hash_32[5]  = *((uint32_t*)&dataset[hash_32[5]]);
		hash_32[6]  = *((uint32_t*)&dataset[hash_32[6]]);
		hash_32[7]  = *((uint32_t*)&dataset[hash_32[7]]);
		hash_32[8]  = *((uint32_t*)&dataset[hash_32[8]]);
		hash_32[9]  = *((uint32_t*)&dataset[hash_32[9]]);
		hash_32[10]  = *((uint32_t*)&dataset[hash_32[10]]);
		hash_32[11]  = *((uint32_t*)&dataset[hash_32[11]]);
		hash_32[12]  = *((uint32_t*)&dataset[hash_32[12]]);
		hash_32[13]  = *((uint32_t*)&dataset[hash_32[13]]);
		hash_32[14]  = *((uint32_t*)&dataset[hash_32[14]]);
		hash_32[15]  = *((uint32_t*)&dataset[hash_32[15]]);
		hash_32[16]  = *((uint32_t*)&dataset[hash_32[16]]);
		hash_32[17]  = *((uint32_t*)&dataset[hash_32[17]]);
		hash_32[18]  = *((uint32_t*)&dataset[hash_32[18]]);
		hash_32[19]  = *((uint32_t*)&dataset[hash_32[19]]);
		hash_32[20]  = *((uint32_t*)&dataset[hash_32[20]]);
		hash_32[21]  = *((uint32_t*)&dataset[hash_32[21]]);
		hash_32[22]  = *((uint32_t*)&dataset[hash_32[22]]);
		hash_32[23]  = *((uint32_t*)&dataset[hash_32[23]]);
		hash_32[24]  = *((uint32_t*)&dataset[hash_32[24]]);
		hash_32[25]  = *((uint32_t*)&dataset[hash_32[25]]);
		hash_32[26]  = *((uint32_t*)&dataset[hash_32[26]]);
		hash_32[27]  = *((uint32_t*)&dataset[hash_32[27]]);
		hash_32[28]  = *((uint32_t*)&dataset[hash_32[28]]);
		hash_32[29]  = *((uint32_t*)&dataset[hash_32[29]]);
		hash_32[30]  = *((uint32_t*)&dataset[hash_32[30]]);
		hash_32[31]  = *((uint32_t*)&dataset[hash_32[31]]);
		hash_64[0] += hash_64[1]; hash_64[2] += hash_64[3];
		hash_64[4] += hash_64[5]; hash_64[6] += hash_64[7];
		hash_64[8] += hash_64[9]; hash_64[10] += hash_64[11];
		hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
		hash_32[0]  = *((uint32_t*)&dataset[hash_32[0]]);
		hash_32[1]  = *((uint32_t*)&dataset[hash_32[1]]);
		hash_32[2]  = *((uint32_t*)&dataset[hash_32[2]]);
		hash_32[3]  = *((uint32_t*)&dataset[hash_32[3]]);
		hash_32[4]  = *((uint32_t*)&dataset[hash_32[4]]);
		hash_32[5]  = *((uint32_t*)&dataset[hash_32[5]]);
		hash_32[6]  = *((uint32_t*)&dataset[hash_32[6]]);
		hash_32[7]  = *((uint32_t*)&dataset[hash_32[7]]);
		hash_32[8]  = *((uint32_t*)&dataset[hash_32[8]]);
		hash_32[9]  = *((uint32_t*)&dataset[hash_32[9]]);
		hash_32[10]  = *((uint32_t*)&dataset[hash_32[10]]);
		hash_32[11]  = *((uint32_t*)&dataset[hash_32[11]]);
		hash_32[12]  = *((uint32_t*)&dataset[hash_32[12]]);
		hash_32[13]  = *((uint32_t*)&dataset[hash_32[13]]);
		hash_32[14]  = *((uint32_t*)&dataset[hash_32[14]]);
		hash_32[15]  = *((uint32_t*)&dataset[hash_32[15]]);
		hash_32[16]  = *((uint32_t*)&dataset[hash_32[16]]);
		hash_32[17]  = *((uint32_t*)&dataset[hash_32[17]]);
		hash_32[18]  = *((uint32_t*)&dataset[hash_32[18]]);
		hash_32[19]  = *((uint32_t*)&dataset[hash_32[19]]);
		hash_32[20]  = *((uint32_t*)&dataset[hash_32[20]]);
		hash_32[21]  = *((uint32_t*)&dataset[hash_32[21]]);
		hash_32[22]  = *((uint32_t*)&dataset[hash_32[22]]);
		hash_32[23]  = *((uint32_t*)&dataset[hash_32[23]]);
		hash_32[24]  = *((uint32_t*)&dataset[hash_32[24]]);
		hash_32[25]  = *((uint32_t*)&dataset[hash_32[25]]);
		hash_32[26]  = *((uint32_t*)&dataset[hash_32[26]]);
		hash_32[27]  = *((uint32_t*)&dataset[hash_32[27]]);
		hash_32[28]  = *((uint32_t*)&dataset[hash_32[28]]);
		hash_32[29]  = *((uint32_t*)&dataset[hash_32[29]]);
		hash_32[30]  = *((uint32_t*)&dataset[hash_32[30]]);
		hash_32[31]  = *((uint32_t*)&dataset[hash_32[31]]);
		hash_64[1] += hash_64[0]; hash_64[3] += hash_64[2];
		hash_64[5] += hash_64[4]; hash_64[7] += hash_64[6];
		hash_64[9] += hash_64[8]; hash_64[11] += hash_64[10];
		hash_64[13] += hash_64[12]; hash_64[15] += hash_64[14];
	}
	hash_64[ 0] += hash_64[ 1]; hash_64[ 2] += hash_64[ 3];
	hash_64[ 4] += hash_64[ 5]; hash_64[ 6] += hash_64[ 7];
	hash_64[ 8] += hash_64[ 9]; hash_64[10] += hash_64[11];
	hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
	hash_64[ 0] += hash_64[ 2]; hash_64[ 4] += hash_64[ 6];
	hash_64[ 8] += hash_64[10]; hash_64[12] += hash_64[14];
	*out_64   = hash_64[ 0]; out_64[1] = hash_64[ 4];
	out_64[2] = hash_64[ 8]; out_64[3] = hash_64[12];
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
#ifdef ACCESS_ROUNDS
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
		for(uint8_t j=0; j<32; j++) calcItem32(&hash_32[j], cache);
		for(uint8_t j=0; j<16; j+=2) hash_64[j]   += hash_64[j+1];
		for(uint8_t j=0; j<32; j++) calcItem32(&hash_32[j], cache);
		for(uint8_t j=0; j<16; j+=2) hash_64[j+1] += hash_64[j];
	}
#endif
	*hash_64    += hash_64[ 1]; hash_64[ 2] += hash_64[ 3];
	hash_64[ 4] += hash_64[ 5]; hash_64[ 6] += hash_64[ 7];
	hash_64[ 8] += hash_64[ 9]; hash_64[10] += hash_64[11];
	hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
	*hash_64    += hash_64[ 2]; hash_64[ 4] += hash_64[ 6];
	hash_64[ 8] += hash_64[10]; hash_64[12] += hash_64[14];
	*out_64      = *hash_64;    out_64[  1]  = hash_64[ 4];
	out_64[  2]  = hash_64[ 8]; out_64[  3]  = hash_64[12];
}
