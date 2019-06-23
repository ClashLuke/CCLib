#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "pow.h"

#define ACCESS_ROUNDS 256

void mash_full(uint8_t* data, uint8_t* dataset, uint8_t* out){
	uint64_t  hash_64[16]     = {0};
	uint32_t* hash_32         = (uint32_t*)hash_64;
	uint32_t* data_32         = (uint32_t*)data;
	uint64_t* out_64          = (uint64_t*)out;
#ifdef ACCESS_ROUNDS
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
#endif
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
#ifdef ACCESS_ROUNDS
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

void mash_full_multi(uint8_t* data, uint8_t* dataset, const uint8_t threads, uint8_t* out){
	uint64_t  hash_64[threads*16];
	uint32_t* hash_32 = (uint32_t*)hash_64;
	uint32_t* data_32 = (uint32_t*)data;
	uint64_t* out_64  = (uint64_t*)out;
#ifdef ACCESS_ROUNDS
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
#endif
	hash_64[ 0] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[ 1] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[ 2] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[ 3] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[ 4] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[ 5] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[ 6] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[ 7] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[ 0] = *((uint64_t*)&dataset[hash_32[ 0]]);
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
#ifdef ACCESS_ROUNDS
	}
#endif
	for(uint8_t j=1; j<threads; j++){
	#ifdef ACCESS_ROUNDS
		for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
	#endif
		data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
		hash_64[j*16   ] = *((uint64_t*)&dataset[data_32[j*16   ]]);
		hash_64[j*16+ 1] = *((uint64_t*)&dataset[data_32[j*16+ 1]]);
		hash_64[j*16+ 2] = *((uint64_t*)&dataset[data_32[j*16+ 2]]);
		hash_64[j*16+ 3] = *((uint64_t*)&dataset[data_32[j*16+ 3]]);
		hash_64[j*16+ 4] = *((uint64_t*)&dataset[data_32[j*16+ 4]]);
		hash_64[j*16+ 5] = *((uint64_t*)&dataset[data_32[j*16+ 5]]);
		hash_64[j*16+ 6] = *((uint64_t*)&dataset[data_32[j*16+ 6]]);
		hash_64[j*16+ 7] = *((uint64_t*)&dataset[data_32[j*16+ 7]]);
		hash_64[j*16   ] = *((uint64_t*)&dataset[hash_32[j*16   ]]);
		hash_64[j*16+ 1] = *((uint64_t*)&dataset[hash_32[j*16+ 1]]);
		hash_64[j*16+ 2] = *((uint64_t*)&dataset[hash_32[j*16+ 2]]);
		hash_64[j*16+ 3] = *((uint64_t*)&dataset[hash_32[j*16+ 3]]);
		hash_64[j*16+ 4] = *((uint64_t*)&dataset[hash_32[j*16+ 4]]);
		hash_64[j*16+ 5] = *((uint64_t*)&dataset[hash_32[j*16+ 5]]);
		hash_64[j*16+ 6] = *((uint64_t*)&dataset[hash_32[j*16+ 6]]);
		hash_64[j*16+ 7] = *((uint64_t*)&dataset[hash_32[j*16+ 7]]);
		hash_64[j*16+ 8] = *((uint64_t*)&dataset[hash_32[j*16+ 8]]);
		hash_64[j*16+ 9] = *((uint64_t*)&dataset[hash_32[j*16+ 9]]);
		hash_64[j*16+10] = *((uint64_t*)&dataset[hash_32[j*16+10]]);
		hash_64[j*16+11] = *((uint64_t*)&dataset[hash_32[j*16+11]]);
		hash_64[j*16+12] = *((uint64_t*)&dataset[hash_32[j*16+12]]);
		hash_64[j*16+13] = *((uint64_t*)&dataset[hash_32[j*16+13]]);
		hash_64[j*16+14] = *((uint64_t*)&dataset[hash_32[j*16+14]]);
		hash_64[j*16+15] = *((uint64_t*)&dataset[hash_32[j*16+15]]);
	#ifdef ACCESS_ROUNDS
		}
	#endif
	}
	hash_64[ 0] += hash_64[ 1]; hash_64[ 2] += hash_64[ 3];
	hash_64[ 4] += hash_64[ 5]; hash_64[ 6] += hash_64[ 7];
	hash_64[ 8] += hash_64[ 9]; hash_64[10] += hash_64[11];
	hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
	hash_64[ 0] += hash_64[ 2]; hash_64[ 4] += hash_64[ 6];
	hash_64[ 8] += hash_64[10]; hash_64[12] += hash_64[14];
	*out_64   = hash_64[ 0]; out_64[1] = hash_64[ 4];
	out_64[2] = hash_64[ 8]; out_64[3] = hash_64[12];
	for(uint8_t j=1; j<threads; j++){
		hash_64[j*16   ] += hash_64[j*16+ 1]; hash_64[j*16+ 2] += hash_64[j*16+ 3];
		hash_64[j*16+ 4] += hash_64[j*16+ 5]; hash_64[j*16+ 6] += hash_64[j*16+ 7];
		hash_64[j*16+ 8] += hash_64[j*16+ 9]; hash_64[j*16+10] += hash_64[j*16+11];
		hash_64[j*16+12] += hash_64[j*16+13]; hash_64[j*16+14] += hash_64[j*16+15];
		hash_64[j*16   ] += hash_64[j*16+ 2]; hash_64[j*16+ 4] += hash_64[j*16+ 6];
		hash_64[j*16+ 8] += hash_64[j*16+10]; hash_64[j*16+12] += hash_64[j*16+14];
		if(((hash_64[j*16   ])<=(*out_64  ))
		&& ((hash_64[j*16+ 4])<=(out_64[1]))
		&& ((hash_64[j*16+ 8])<=(out_64[2]))
		&& ((hash_64[j*16+12])<=(out_64[3]))){
			*out_64   = hash_64[j*16+ 0]; out_64[1] = hash_64[j*16+ 4];
			out_64[2] = hash_64[j*16+ 8]; out_64[3] = hash_64[j*16+12];
		}
	}
}

uint64_t calcItem(uint32_t itemNumber, uint8_t* cache){
	uint8_t   item[32] = {0};
	uint64_t* item_64  = (uint64_t*)item;
	uint64_t  out0     = 0; 
	uint64_t  out1     = 0; 
	uint8_t   innerPos = itemNumber&0xff;
	calcDatasetItem(cache, itemNumber>>8, item_64);
	if(innerPos>0xbf){
		out0   = item_64[3]>>(32-(innerPos&0x20));
		out0 >>= 32-(innerPos&0x1f);
		calcDatasetItem(cache, 1+(itemNumber>>8), item_64);
		out1   = item_64[0]<<(innerPos&0x20);
		out1 <<= innerPos&0x1f;
		out0  |= out1; 
	}else{
		uint8_t pos = innerPos&0x3f;
		if(!pos){
			out0 = item_64[innerPos/64];
		} else {
			out0   = item_64[innerPos/64]>>(32-(pos&0x20));
			out0 >>= 32-(pos&0x1f);
			out1   = item_64[1+(innerPos/64)]<<(pos&0x20);
			out1 <<= pos&0x1f;
			out0  |= out1;
		}
	}
	return(out0);
}

void mash_light(uint8_t* data, uint8_t* cache, uint8_t* out){
	uint64_t  hash_64[16]     = {0};
	uint32_t* hash_32         = (uint32_t*)hash_64;
	uint32_t* data_32         = (uint32_t*)data;
	uint64_t* out_64          = (uint64_t*)out;
#ifdef ACCESS_ROUNDS
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
#endif
	*hash_64    = calcItem(*data_32,    cache);
	hash_64[ 1] = calcItem(data_32[ 1], cache);
	hash_64[ 2] = calcItem(data_32[ 2], cache);
	hash_64[ 3] = calcItem(data_32[ 3], cache);
	hash_64[ 4] = calcItem(data_32[ 4], cache);
	hash_64[ 5] = calcItem(data_32[ 5], cache);
	hash_64[ 6] = calcItem(data_32[ 6], cache);
	hash_64[ 7] = calcItem(data_32[ 7], cache);
	*hash_64    = calcItem(*hash_32,    cache);
	hash_64[ 1] = calcItem(hash_32[ 1], cache);
	hash_64[ 2] = calcItem(hash_32[ 2], cache);
	hash_64[ 3] = calcItem(hash_32[ 3], cache);
	hash_64[ 4] = calcItem(hash_32[ 4], cache);
	hash_64[ 5] = calcItem(hash_32[ 5], cache);
	hash_64[ 6] = calcItem(hash_32[ 6], cache);
	hash_64[ 7] = calcItem(hash_32[ 7], cache);
	hash_64[ 8] = calcItem(hash_32[ 8], cache);
	hash_64[ 9] = calcItem(hash_32[ 9], cache);
	hash_64[10] = calcItem(hash_32[10], cache);
	hash_64[11] = calcItem(hash_32[11], cache);
	hash_64[12] = calcItem(hash_32[12], cache);
	hash_64[13] = calcItem(hash_32[13], cache);
	hash_64[14] = calcItem(hash_32[14], cache);
	hash_64[15] = calcItem(hash_32[15], cache);
#ifdef ACCESS_ROUNDS
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

void mash_light_multi(uint8_t* data, uint8_t* cache, const uint8_t threads, uint8_t* out){
	uint64_t  hash_64[threads*16];
	uint32_t* hash_32 = (uint32_t*)hash_64;
	uint32_t* data_32 = (uint32_t*)data;
	uint64_t* out_64  = (uint64_t*)out;
#ifdef ACCESS_ROUNDS
	for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
#endif
	hash_64[ 0] = calcItem(data_32[ 0], cache);
	hash_64[ 1] = calcItem(data_32[ 1], cache);
	hash_64[ 2] = calcItem(data_32[ 2], cache);
	hash_64[ 3] = calcItem(data_32[ 3], cache);
	hash_64[ 4] = calcItem(data_32[ 4], cache);
	hash_64[ 5] = calcItem(data_32[ 5], cache);
	hash_64[ 6] = calcItem(data_32[ 6], cache);
	hash_64[ 7] = calcItem(data_32[ 7], cache);
	hash_64[ 0] = calcItem(hash_32[ 0], cache);
	hash_64[ 1] = calcItem(hash_32[ 1], cache);
	hash_64[ 2] = calcItem(hash_32[ 2], cache);
	hash_64[ 3] = calcItem(hash_32[ 3], cache);
	hash_64[ 4] = calcItem(hash_32[ 4], cache);
	hash_64[ 5] = calcItem(hash_32[ 5], cache);
	hash_64[ 6] = calcItem(hash_32[ 6], cache);
	hash_64[ 7] = calcItem(hash_32[ 7], cache);
	hash_64[ 8] = calcItem(hash_32[ 8], cache);
	hash_64[ 9] = calcItem(hash_32[ 9], cache);
	hash_64[10] = calcItem(hash_32[10], cache);
	hash_64[11] = calcItem(hash_32[11], cache);
	hash_64[12] = calcItem(hash_32[12], cache);
	hash_64[13] = calcItem(hash_32[13], cache);
	hash_64[14] = calcItem(hash_32[14], cache);
	hash_64[15] = calcItem(hash_32[15], cache);
#ifdef ACCESS_ROUNDS
	}
#endif
	for(uint8_t j=1; j<threads; j++){
	#ifdef ACCESS_ROUNDS
		for(uint32_t i=0; i<ACCESS_ROUNDS; i++){
	#endif
		data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
		hash_64[j*16+ 0] = calcItem(data_32[ 0], cache);
		hash_64[j*16+ 2] = calcItem(data_32[ 2], cache);
		hash_64[j*16+ 4] = calcItem(data_32[ 4], cache);
		hash_64[j*16+ 6] = calcItem(data_32[ 6], cache);
		hash_64[j*16+ 1] = calcItem(data_32[ 1], cache);
		hash_64[j*16+ 3] = calcItem(data_32[ 3], cache);
		hash_64[j*16+ 5] = calcItem(data_32[ 5], cache);
		hash_64[j*16+ 7] = calcItem(data_32[ 7], cache);
		hash_64[j*16+ 0] = calcItem(hash_32[j*16+ 0], cache);
		hash_64[j*16+ 1] = calcItem(hash_32[j*16+ 1], cache);
		hash_64[j*16+ 2] = calcItem(hash_32[j*16+ 2], cache);
		hash_64[j*16+ 3] = calcItem(hash_32[j*16+ 3], cache);
		hash_64[j*16+ 4] = calcItem(hash_32[j*16+ 4], cache);
		hash_64[j*16+ 5] = calcItem(hash_32[j*16+ 5], cache);
		hash_64[j*16+ 6] = calcItem(hash_32[j*16+ 6], cache);
		hash_64[j*16+ 7] = calcItem(hash_32[j*16+ 7], cache);
		hash_64[j*16+ 8] = calcItem(hash_32[j*16+ 8], cache);
		hash_64[j*16+ 9] = calcItem(hash_32[j*16+ 9], cache);
		hash_64[j*16+10] = calcItem(hash_32[j*16+10], cache);
		hash_64[j*16+11] = calcItem(hash_32[j*16+11], cache);
		hash_64[j*16+12] = calcItem(hash_32[j*16+12], cache);
		hash_64[j*16+13] = calcItem(hash_32[j*16+13], cache);
		hash_64[j*16+14] = calcItem(hash_32[j*16+14], cache);
		hash_64[j*16+15] = calcItem(hash_32[j*16+15], cache);
	#ifdef ACCESS_ROUNDS
		}
	#endif
	}
	hash_64[ 0] += hash_64[ 1]; hash_64[ 2] += hash_64[ 3];
	hash_64[ 4] += hash_64[ 5]; hash_64[ 6] += hash_64[ 7];
	hash_64[ 8] += hash_64[ 9]; hash_64[10] += hash_64[11];
	hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
	hash_64[ 0] += hash_64[ 2]; hash_64[ 4] += hash_64[ 6];
	hash_64[ 8] += hash_64[10]; hash_64[12] += hash_64[14];
	*out_64   = hash_64[ 0]; out_64[1] = hash_64[ 4];
	out_64[2] = hash_64[ 8]; out_64[3] = hash_64[12];
	for(uint8_t j=1; j<threads; j++){
		hash_64[j*16   ] += hash_64[j*16+ 1]; hash_64[j*16+ 2] += hash_64[j*16+ 3];
		hash_64[j*16+ 4] += hash_64[j*16+ 5]; hash_64[j*16+ 6] += hash_64[j*16+ 7];
		hash_64[j*16+ 8] += hash_64[j*16+ 9]; hash_64[j*16+10] += hash_64[j*16+11];
		hash_64[j*16+12] += hash_64[j*16+13]; hash_64[j*16+14] += hash_64[j*16+15];
		hash_64[j*16   ] += hash_64[j*16+ 2]; hash_64[j*16+ 4] += hash_64[j*16+ 6];
		hash_64[j*16+ 8] += hash_64[j*16+10]; hash_64[j*16+12] += hash_64[j*16+14];
		if(((hash_64[j*16   ])<=(*out_64  ))
		&& ((hash_64[j*16+ 4])<=(out_64[1]))
		&& ((hash_64[j*16+ 8])<=(out_64[2]))
		&& ((hash_64[j*16+12])<=(out_64[3]))){
			*out_64   = hash_64[j*16+ 0]; out_64[1] = hash_64[j*16+ 4];
			out_64[2] = hash_64[j*16+ 8]; out_64[3] = hash_64[j*16+12];
		}
	}
}


