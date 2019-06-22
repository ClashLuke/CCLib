#include <stdint.h>
#include <stdio.h>
#include "pow.h"
#include "random.h"

#if !defined(HAVE_SSE2)
#include "blake2/neon/blake2.h"
#else
#include "blake2/sse/blake2.h"
#endif

void equihashimoto_full(uint8_t* hash, uint8_t* dataset, uint64_t nonce, uint64_t iterations, uint64_t* output){
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
	uint32_t* item32_0  = (uint32_t*)item;
	uint32_t* item32_1  = (uint32_t*)&item[4];
	uint32_t* item32_2  = (uint32_t*)&item[8];
	uint32_t* item32_3  = (uint32_t*)&item[12];
	uint64_t* item64_0  = (uint64_t*)item;
	uint64_t* item64_1  = (uint64_t*)&item[8];
	uint64_t* item64_2  = (uint64_t*)&item[16];
	uint64_t* item64_3  = (uint64_t*)&item[24];
	uint32_t* hash32_0  = (uint32_t*)hash;
	uint32_t* hash32_1  = (uint32_t*)&hash[4];
	uint32_t* hash32_2  = (uint32_t*)&hash[8];
	uint32_t* hash32_3  = (uint32_t*)&hash[12];
	uint32_t* hash32_4  = (uint32_t*)&hash[16];
	uint32_t* hash32_5  = (uint32_t*)&hash[20];
	uint32_t* hash32_6  = (uint32_t*)&hash[24];
	uint32_t* hash32_7  = (uint32_t*)&hash[28];
	uint32_t* hash32_8  = (uint32_t*)&hash[32];
	uint32_t* hash32_9  = (uint32_t*)&hash[36];
	uint32_t* hash32_10 = (uint32_t*)&hash[40];
	uint32_t* hash32_11 = (uint32_t*)&hash[44];
	uint32_t* hash32_12 = (uint32_t*)&hash[48];
	uint32_t* hash32_13 = (uint32_t*)&hash[52];
	uint32_t* hash32_14 = (uint32_t*)&hash[56];
	uint32_t* hash32_15 = (uint32_t*)&hash[60];
	uint64_t* hash64_0  = (uint64_t*)hash;
	uint64_t* hash64_1  = (uint64_t*)&hash[8];
	uint64_t* hash64_2  = (uint64_t*)&hash[16];
	uint64_t* hash64_3  = (uint64_t*)&hash[24];
	uint64_t* hash64_4  = (uint64_t*)&hash[32];
	uint64_t* hash64_5  = (uint64_t*)&hash[40];
	uint64_t* hash64_6  = (uint64_t*)&hash[48];
	uint64_t* hash64_7  = (uint64_t*)&hash[56];
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
		*output ^= *item64_0 ^ *item64_1 ^ *item64_2 ^ *item64_3;
		nonce++;
		(*hash64_0)++; (*hash64_1)++;
		(*hash64_2)++; (*hash64_3)++;
	}
}

void equihashimoto_light(uint8_t* hash, uint8_t* cache, uint64_t nonce, uint64_t iterations, uint64_t* output){
	// Equihashimoto takes a hash as input
	// and returns a nonce which, when added to the hash,
	// can be used to perform a calculation inspired by equihash
	// on a dataset using a generation inspired by dagger hashimoto.
	uint8_t   item[32]  = {0};
	uint8_t   out[32]   = {0};
	uint64_t* out64_0   =   (uint64_t*)out;
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
	uint32_t* item32_0  = (uint32_t*)item;
	uint32_t* item32_1  = (uint32_t*)&item[4];
	uint32_t* item32_2  = (uint32_t*)&item[8];
	uint32_t* item32_3  = (uint32_t*)&item[12];
	uint64_t* item64_0  = (uint64_t*)item;
	uint64_t* item64_1  = (uint64_t*)&item[8];
	uint64_t* item64_2  = (uint64_t*)&item[16];
	uint64_t* item64_3  = (uint64_t*)&item[24];
	uint32_t* hash32_0  = (uint32_t*)hash;
	uint32_t* hash32_1  = (uint32_t*)&hash[4];
	uint32_t* hash32_2  = (uint32_t*)&hash[8];
	uint32_t* hash32_3  = (uint32_t*)&hash[12];
	uint32_t* hash32_4  = (uint32_t*)&hash[16];
	uint32_t* hash32_5  = (uint32_t*)&hash[20];
	uint32_t* hash32_6  = (uint32_t*)&hash[24];
	uint32_t* hash32_7  = (uint32_t*)&hash[28];
	uint32_t* hash32_8  = (uint32_t*)&hash[32];
	uint32_t* hash32_9  = (uint32_t*)&hash[36];
	uint32_t* hash32_10 = (uint32_t*)&hash[40];
	uint32_t* hash32_11 = (uint32_t*)&hash[44];
	uint32_t* hash32_12 = (uint32_t*)&hash[48];
	uint32_t* hash32_13 = (uint32_t*)&hash[52];
	uint32_t* hash32_14 = (uint32_t*)&hash[56];
	uint32_t* hash32_15 = (uint32_t*)&hash[60];
	uint64_t* hash64_0  = (uint64_t*)hash;
	uint64_t* hash64_1  = (uint64_t*)&hash[8];
	uint64_t* hash64_2  = (uint64_t*)&hash[16];
	uint64_t* hash64_3  = (uint64_t*)&hash[24];
	uint64_t* hash64_4  = (uint64_t*)&hash[32];
	uint64_t* hash64_5  = (uint64_t*)&hash[40];
	uint64_t* hash64_6  = (uint64_t*)&hash[48];
	uint64_t* hash64_7  = (uint64_t*)&hash[56];
	*hash64_0 += nonce; *hash64_1 += nonce;
	*hash64_2 += nonce; *hash64_3 += nonce;
	*hash64_4 += nonce; *hash64_5 += nonce;
	*hash64_6 += nonce; *hash64_7 += nonce;
	while(1){
		calc_dataset_item(cache, (*hash32_0)&0xffffffffffffffe0, out64_0);
		*item     = out[(*hash32_0)&0x1f];
		calc_dataset_item(cache, (*hash32_1)&0xffffffffffffffe0, out64_0);
		*item_1   = out[(*hash32_1)&0x1f];
		calc_dataset_item(cache, (*hash32_2)&0xffffffffffffffe0, out64_0);
		*item_2   = out[(*hash32_2)&0x1f];
		calc_dataset_item(cache, (*hash32_3)&0xffffffffffffffe0, out64_0);
		*item_3   = out[(*hash32_3)&0x1f];
		calc_dataset_item(cache, (*hash32_4)&0xffffffffffffffe0, out64_0);
		*item_4   = out[(*hash32_4)&0x1f];
		calc_dataset_item(cache, (*hash32_5)&0xffffffffffffffe0, out64_0);
		*item_5   = out[(*hash32_5)&0x1f];
		calc_dataset_item(cache, (*hash32_6)&0xffffffffffffffe0, out64_0);
		*item_6   = out[(*hash32_6)&0x1f];
		calc_dataset_item(cache, (*hash32_7)&0xffffffffffffffe0, out64_0);
		*item_7   = out[(*hash32_7)&0x1f];
		calc_dataset_item(cache, (*hash32_8)&0xffffffffffffffe0, out64_0);
		*item_8   = out[(*hash32_8)&0x1f];
		calc_dataset_item(cache, (*hash32_9)&0xffffffffffffffe0, out64_0);
		*item_9   = out[(*hash32_9)&0x1f];
		calc_dataset_item(cache, (*hash32_10)&0xffffffffffffffe0, out64_0);
		*item_10  = out[(*hash32_10)&0x1f];
		calc_dataset_item(cache, (*hash32_11)&0xffffffffffffffe0, out64_0);
		*item_11  = out[(*hash32_11)&0x1f];
		calc_dataset_item(cache, (*hash32_12)&0xffffffffffffffe0, out64_0);
		*item_12  = out[(*hash32_12)&0x1f];
		calc_dataset_item(cache, (*hash32_13)&0xffffffffffffffe0, out64_0);
		*item_13  = out[(*hash32_13)&0x1f];
		calc_dataset_item(cache, (*hash32_14)&0xffffffffffffffe0, out64_0);
		*item_14  = out[(*hash32_14)&0x1f];
		calc_dataset_item(cache, (*hash32_15)&0xffffffffffffffe0, out64_0);
		*item_15  = out[(*hash32_15)&0x1f];
		calc_dataset_item(cache, (*item32_0)&0xffffffffffffffe0, out64_0);
		*item64_0  = out64_0[(*item32_0)&0x18];
		calc_dataset_item(cache, (*item32_1)&0xffffffffffffffe0, out64_0);
		*item64_1  = out64_0[(*item32_1)&0x18];
		calc_dataset_item(cache, (*item32_2)&0xffffffffffffffe0, out64_0);
		*item64_2  = out64_0[(*item32_2)&0x18];
		calc_dataset_item(cache, (*item32_3)&0xffffffffffffffe0, out64_0);
		*item64_3  = out64_0[(*item32_3)&0x18];
		*output ^= *item64_0 ^ *item64_1 ^ *item64_2 ^ *item64_3;
		nonce++;
		(*hash64_0)++; (*hash64_1)++;
		(*hash64_2)++; (*hash64_3)++;
	}
}
