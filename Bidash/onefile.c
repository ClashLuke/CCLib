// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ACCESS_ROUNDS 64   // Access rounds make hashing slower for everyone by a defined factor, comment it to have the greatest speed. 
#define DATASET_PARENTS 4   // Determines dataset creation time and validation speed. The higher the slower.


void error_exit(uint8_t code){
	printf("Error, exiting program. Code: %u\n", code);
	if(code==1) printf("Memory could not be initialised, insufficient RAM?\n");
	exit(-1);
}

uint32_t crc32c_table[256] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
	0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
	0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
	0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
	0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
	0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
	0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
	0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
	0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
	0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
	0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
	0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
	0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
	0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
	0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
	0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
	0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
	0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
	0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
	0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

void crc32p(uint32_t* in, uint32_t* out) { // CRC32-Pointer
#if defined(__aarch64__) && defined(__ARM_FEATURE_CRC32)
	__asm__("crc32w %w0,%w0,%w1\n":"+r"(*out):"r"(*in));
#else
	*out=crc32c_table[(*in )&0xff]^((*in )>>8);
	*out=crc32c_table[(*out)&0xff]^((*out)>>8);
	*out=crc32c_table[(*out)&0xff]^((*out)>>8);
	*out=crc32c_table[(*out)&0xff]^((*out)>>8);
#endif
}

void crc32i(uint32_t* in) { // CRC32-Inplace
#if defined(__aarch64__) && defined(__ARM_FEATURE_CRC32)
	__asm__("crc32w %w0,%w0,%w1\n":"+r"(*in):"r"(*in));
#else
	*in=crc32c_table[(*in)&0xff]^((*in)>>8);
	*in=crc32c_table[(*in)&0xff]^((*in)>>8);
	*in=crc32c_table[(*in)&0xff]^((*in)>>8);
	*in=crc32c_table[(*in)&0xff]^((*in)>>8);
#endif
}

void make_cache(uint8_t* seed, uint8_t* cache){
	/* 64MiB cache is allocated before executing
	   this function */
	uint32_t* se32          = (uint32_t*)seed;
	uint32_t* cache_32      = (uint32_t*)cache; 
	uint64_t* cache_64      = (uint64_t*)cache; 
	uint32_t  i64           = 0;
	crc32p(se32,       cache_32);
	crc32p(&se32[1],  &cache_32[1]);
	crc32p(&se32[2],  &cache_32[2]);
	crc32p(&se32[3],  &cache_32[3]);
	crc32p(&se32[4],  &cache_32[4]);
	crc32p(&se32[5],  &cache_32[5]);
	crc32p(&se32[6],  &cache_32[6]);
	crc32p(&se32[7],  &cache_32[7]);
	for(uint32_t i=0;i<0xfffff7;i+=8){
		i64 >>= 1;
		crc32p(&cache_32[i  ],  &cache_32[i+ 8]);
		crc32p(&cache_32[i+1],  &cache_32[i+ 9]);
		crc32p(&cache_32[i+2],  &cache_32[i+10]);
		crc32p(&cache_32[i+3],  &cache_32[i+11]);
		crc32p(&cache_32[i+4],  &cache_32[i+12]);
		crc32p(&cache_32[i+5],  &cache_32[i+13]);
		crc32p(&cache_32[i+6],  &cache_32[i+14]);
		crc32p(&cache_32[i+7],  &cache_32[i+15]);
		cache_64[i64  ] += cache_64[i64+1];
		cache_64[i64+2] += cache_64[i64+3];
		cache_64[i64+1] += cache_64[i64+2];
		cache_64[i64+3] += cache_64[i64  ];
	}
}

void calcDatasetItem(uint8_t* cache, uint32_t item_number, uint64_t* out){
	uint32_t* cache_32 = (uint32_t*)cache; 
	uint64_t  mix[4]   = {0};
	uint32_t* mix_32   = (uint32_t*)mix;
	uint32_t* mix_32_s = (uint32_t*)&(((uint16_t*)mix)[1]);
	uint32_t  x        = 0;
	item_number>>=2;
	*mix_32    = cache_32[(item_number  )&0x1fffff];
	mix_32[1]  = cache_32[(item_number+1)&0x1fffff];
	mix_32[2]  = cache_32[(item_number+2)&0x1fffff];
	mix_32[3]  = cache_32[(item_number+3)&0x1fffff];
	mix_32[4]  = cache_32[(item_number+4)&0x1fffff];
	mix_32[5]  = cache_32[(item_number+5)&0x1fffff];
	mix_32[6]  = cache_32[(item_number+6)&0x1fffff];
	mix_32[7]  = cache_32[(item_number+7)&0x1fffff];
	*mix_32   ^= item_number; mix_32[1] ^= item_number;
	mix_32[2] ^= item_number; mix_32[3] ^= item_number;
	mix_32[4] ^= item_number; mix_32[5] ^= item_number;
	mix_32[6] ^= item_number; mix_32[7] ^= item_number;
	for(uint16_t j=0;j<DATASET_PARENTS;j++){
		x = j^item_number;
		*mix_32 &= 0x1fffff; mix_32[1] &= 0x1fffff;
		mix_32[2] &= 0x1fffff; mix_32[3] &= 0x1fffff;
		mix_32[4] &= 0x1fffff; mix_32[5] &= 0x1fffff;
		mix_32[6] &= 0x1fffff; mix_32[7] &= 0x1fffff;
		*mix_32   = cache_32[*mix_32];
		mix_32[1] = cache_32[mix_32[1]];
		mix_32[2] = cache_32[mix_32[2]];
		mix_32[3] = cache_32[mix_32[3]];
		mix_32[4] = cache_32[mix_32[4]];
		mix_32[5] = cache_32[mix_32[5]];
		mix_32[6] = cache_32[mix_32[6]];
		mix_32[7] = cache_32[mix_32[7]];
		*mix_32   ^= x; mix_32[1] ^= x;
		mix_32[2] ^= x; mix_32[3] ^= x;
		mix_32[4] ^= x; mix_32[5] ^= x;
		mix_32[6] ^= x; mix_32[7] ^= x;
		crc32i(mix_32_s);
		crc32i(&mix_32_s[1]);
		crc32i(&mix_32_s[2]);
		crc32i(&mix_32_s[3]);
		crc32i(&mix_32_s[4]);
		crc32i(&mix_32_s[5]);
		crc32i(&mix_32_s[6]);
	}
	*out  =*mix;    out[1]=mix[1];
	out[2]= mix[2]; out[3]=mix[3];
}

void calc_dataset(uint8_t* cache, uint64_t* out){
	for(uint32_t i=0;i<536870912;i+=4){ // (1<<32)>>3
		calcDatasetItem(cache, i , &out[i]);
	}
}
void cache_from_seed(uint8_t* seed, uint8_t* cache){
	make_cache(seed, cache);
}
void dataset_from_seed(uint8_t* seed, uint64_t* dataset){
	uint64_t* cache_64 = (uint64_t*)calloc(8388608,8);
	if(!cache_64) error_exit(1);
	uint8_t*  cache    = (uint8_t*)cache_64;
	cache_from_seed(seed, cache);
	calc_dataset(cache, dataset);
	free(cache);
}



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

