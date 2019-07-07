// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdint.h>
#include <stdlib.h>
#include "config.h"


static const uint32_t crc32c_table[256] = {
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

#if defined(__aarch64__) && defined(__ARM_FEATURE_CRC32)
#define crc32p(x,y) __asm__("crc32w %w0,%w0,%w1\n":"+r"(y):"r"(x));
#else
#define crc32p(x,y) \
	y=crc32c_table[(x)&0xff]^((x)>>8);\
	y=crc32c_table[(y)&0xff]^((y)>>8);\
	y=crc32c_table[(y)&0xff]^((y)>>8);\
	y=crc32c_table[(y)&0xff]^((y)>>8);
#endif

#if defined(__aarch64__) && defined(__ARM_FEATURE_CRC32)
#define crc32i(y) __asm__("crc32w %w0,%w0,%w1\n":"+r"(y):"r"(y));
#else
#define crc32i(y) \
	y=crc32c_table[(y)&0xff]^((y)>>8);\
	y=crc32c_table[(y)&0xff]^((y)>>8);\
	y=crc32c_table[(y)&0xff]^((y)>>8);\
	y=crc32c_table[(y)&0xff]^((y)>>8);
#endif


#include <stdint.h>

#if (!defined(__aarch64__) || !defined(__ARM_FEATURE_CRYPTO)) && (!defined(__x86_64__) || !defined(__AES__))
static const uint8_t SBOX[256] = {
	0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
	0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
	0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
	0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
	0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
	0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
	0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
	0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
	0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
	0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
	0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
	0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
	0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
	0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
	0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
	0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
};

#define ADD_ROUND_KEY(x) \
	state[ 1] ^= key[x+ 1]; state[ 2] ^= key[x+ 2];\
	state[ 3] ^= key[x+ 3]; state[ 4] ^= key[x+ 4];\
	state[ 5] ^= key[x+ 5]; state[ 6] ^= key[x+ 6];\
	state[ 7] ^= key[x+ 7]; state[ 8] ^= key[x+ 8];\
	state[ 9] ^= key[x+ 9]; state[10] ^= key[x+10];\
	state[11] ^= key[x+11]; state[12] ^= key[x+12];\
	state[13] ^= key[x+13]; state[14] ^= key[x+14];\
	state[15] ^= key[x+15]; *state ^= key[x]; 

#define SUB_BYTES() \
	state[ 1] = SBOX[state[ 1]]; state[ 2] = SBOX[state[ 2]];\
	state[ 3] = SBOX[state[ 3]]; state[ 4] = SBOX[state[ 4]];\
	state[ 5] = SBOX[state[ 5]]; state[ 6] = SBOX[state[ 6]];\
	state[ 7] = SBOX[state[ 7]]; state[ 8] = SBOX[state[ 8]];\
	state[ 9] = SBOX[state[ 9]]; state[10] = SBOX[state[10]];\
	state[11] = SBOX[state[11]]; state[12] = SBOX[state[12]];\
	state[13] = SBOX[state[13]]; state[14] = SBOX[state[14]];\
	state[15] = SBOX[state[15]]; *state = SBOX[*state];

#define SHIFT_ROWS() \
	a_0 = state[ 5]; b_0 = state[10]; c_0 = state[15];\
	a_1 = state[ 9]; b_1 = state[14]; c_1 = state[ 3];\
	a_2 = state[13]; b_2 = state[ 2]; c_2 = state[ 7];\
	a_3 = state[ 1]; b_3 = state[ 6]; c_3 = state[11];\
	state[ 1] = a_0; state[ 2] = b_0; state[ 3] = c_0;\
	state[ 5] = a_1; state[ 6] = b_1; state[ 7] = c_1;\
	state[ 9] = a_2; state[10] = b_2; state[11] = c_2;\
	state[13] = a_3; state[14] = b_3; state[15] = c_3;

#define MIX_COLLUMS() \
	a_0 = *state; b_0 = (*state) << 1; a_1 = state[1]; b_1 = state[1] << 1;\
	a_2 = state[2]; b_2 = state[2] << 1; a_3 = state[3]; b_3 = state[3] << 1;\
	if ((*state) & 0x80) b_0 ^= 0x1b; if (state[1] & 0x80) b_1 ^= 0x1b; \
	if (state[2] & 0x80) b_2 ^= 0x1b; if (state[3] & 0x80) b_3 ^= 0x1b; \
	*state = b_0 ^ a_3 ^ a_2 ^ b_1 ^ a_1; state[1] = b_1 ^ a_0 ^ a_3 ^ b_2 ^ a_2;\
	state[2] = b_2 ^ a_1 ^ a_0 ^ b_3 ^ a_3; state[3] = b_3 ^ a_2 ^ a_1 ^ b_0 ^ a_0;\
	a_0 = state[4]; b_0 = state[4] << 1;\
	a_1 = state[5]; b_1 = state[5] << 1;\
	a_2 = state[6]; b_2 = state[6] << 1;\
	a_3 = state[7]; b_3 = state[7] << 1;\
	if (state[4] & 0x80) b_0 ^= 0x1b; if (state[5] & 0x80) b_1 ^= 0x1b; \
	if (state[6] & 0x80) b_2 ^= 0x1b; if (state[7] & 0x80) b_3 ^= 0x1b; \
	state[4] = b_0 ^ a_3 ^ a_2 ^ b_1 ^ a_1; state[5] = b_1 ^ a_0 ^ a_3 ^ b_2 ^ a_2;\
	state[6] = b_2 ^ a_1 ^ a_0 ^ b_3 ^ a_3; state[7] = b_3 ^ a_2 ^ a_1 ^ b_0 ^ a_0;\
	a_0 = state[8]; b_0 = state[8] << 1;\
	a_1 = state[9]; b_1 = state[9] << 1;\
	a_2 = state[10]; b_2 = state[10] << 1;\
	a_3 = state[11]; b_3 = state[11] << 1;\
	if (state[ 8] & 0x80) b_0 ^= 0x1b; if (state[ 9] & 0x80) b_1 ^= 0x1b; \
	if (state[10] & 0x80) b_2 ^= 0x1b; if (state[11] & 0x80) b_3 ^= 0x1b; \
	state[ 8] = b_0 ^ a_3 ^ a_2 ^ b_1 ^ a_1; state[ 9] = b_1 ^ a_0 ^ a_3 ^ b_2 ^ a_2;\
	state[10] = b_2 ^ a_1 ^ a_0 ^ b_3 ^ a_3; state[11] = b_3 ^ a_2 ^ a_1 ^ b_0 ^ a_0;\
	a_0 = state[12]; b_0 = state[12] << 1;\
	a_1 = state[13]; b_1 = state[13] << 1;\
	a_2 = state[14]; b_2 = state[14] << 1;\
	a_3 = state[15]; b_3 = state[15] << 1;\
	if (state[12] & 0x80) b_0 ^= 0x1b; if (state[13] & 0x80) b_1 ^= 0x1b; \
	if (state[14] & 0x80) b_2 ^= 0x1b; if (state[15] & 0x80) b_3 ^= 0x1b; \
	state[12] = b_0 ^ a_3 ^ a_2 ^ b_1 ^ a_1; state[13] = b_1 ^ a_0 ^ a_3 ^ b_2 ^ a_2;\
	state[14] = b_2 ^ a_1 ^ a_0 ^ b_3 ^ a_3; state[15] = b_3 ^ a_2 ^ a_1 ^ b_0 ^ a_0;

#endif // (!defined(__aarch64__) || !defined(__ARM_FEATURE_CRYPTO)) && (!defined(__x86_64__) || !defined(__AES__))

static inline void aes(uint8_t* state, const uint8_t* key)
{
#if defined(__aarch64__) && defined(__ARM_FEATURE_CRYPTO)
	__asm__ volatile(
		"ld1  {v0.16b},[%0]    \n"
		"ld1  {v1.16b,v2.16b,v3.16b},[%1] \n"
		"aese v0.16b,v1.16b    \n"
		"aesmc v0.16b,v0.16b    \n"
		"aese v0.16b,v2.16b    \n"
		"eor  v0.16b,v0.16b,v3.16b \n"
		"st1  {v0.16b},[%0]    \n"
		: /* only output is in *state */
		: "r"(state), "r"(key)
		: "v0", "v1", "v2", "v3", "cc", "memory");

	// Use -maes to get this one
#elif defined(__x86_64__) && defined(__AES__)
	__asm__ volatile(
		"movups (%0), %%xmm0   \n"
		"movups (%1), %%xmm1   \n"
		"pxor  %%xmm1,%%xmm0   \n"
		"movups 16(%1),%%xmm2   \n"
		"movups 32(%1),%%xmm1   \n"
		"aesenc %%xmm2,%%xmm0   \n" 
		"aesenclast %%xmm1,%%xmm0 \n"
		"movups %%xmm0, (%0) \n"
		: /* only output is in *state */
		: "r"(state), "r" (key)
		: "xmm0", "xmm1", "xmm2", "cc", "memory");
#else
	uint8_t a_0, a_1, a_2, a_3, b_0, b_1, b_2, b_3, c_0, c_1, c_2, c_3;
	ADD_ROUND_KEY(0)
	SUB_BYTES()
	SHIFT_ROWS()
	MIX_COLLUMS()
	ADD_ROUND_KEY(16)
	SUB_BYTES()
	SHIFT_ROWS()
	ADD_ROUND_KEY(32)
#endif
}


// Input will always be 64 byte, output will be 32 byte
void balloon(const uint8_t* data, uint8_t* out){
#ifndef USE_CRC
	uint32_t  size         = SIZE>>3;
	uint64_t  cache_64[SIZE>>3] = {0};
#else
	uint32_t  size         = SIZE>>2;
	uint64_t  cache_64[SIZE>>3] = {0};
#endif
	uint64_t* out_64       = (uint64_t*)out;
	const uint32_t* data_32      = (const uint32_t*)data;
	uint8_t*  cache        = (uint8_t*)cache_64;
	uint32_t* cache_32     = (uint32_t*)cache_64;
	uint32_t  mask         = (SIZE/4)-1;
	uint32_t  prevItem[16] = {0};
	uint32_t  j_4          = 0;
#ifdef USE_CRC
	uint32_t  j_2          = 0;
#endif
	crc32p(*data_32,   *cache_32    ); crc32p(data_32[ 1], cache_32[ 2]);
#if INPUT_SIZE > 1
	crc32p(data_32[ 2], cache_32[ 4]); crc32p(data_32[ 3], cache_32[ 6]);
#if INPUT_SIZE > 2
	crc32p(data_32[ 4], cache_32[ 8]); crc32p(data_32[ 5], cache_32[10]);
#if INPUT_SIZE > 3
	crc32p(data_32[ 6], cache_32[12]); crc32p(data_32[ 7], cache_32[14]);
#if INPUT_SIZE > 4
	crc32p(data_32[ 8], cache_32[16]); crc32p(data_32[ 9], cache_32[18]);
#if INPUT_SIZE > 5
	crc32p(data_32[10], cache_32[20]); crc32p(data_32[11], cache_32[22]);
#if INPUT_SIZE > 6
	crc32p(data_32[12], cache_32[24]); crc32p(data_32[13], cache_32[26]);
#if INPUT_SIZE > 7
	crc32p(data_32[14], cache_32[28]); crc32p(data_32[15], cache_32[30]);
#if INPUT_SIZE > 8
	crc32p(data_32[16], cache_32[32]); crc32p(data_32[17], cache_32[34]);
#if INPUT_SIZE > 9
	crc32p(data_32[18], cache_32[36]); crc32p(data_32[19], cache_32[38]);
#if INPUT_SIZE > 10
	crc32p(data_32[20], cache_32[40]); crc32p(data_32[21], cache_32[42]);
#if INPUT_SIZE > 11
	crc32p(data_32[22], cache_32[44]); crc32p(data_32[23], cache_32[46]);
#if INPUT_SIZE > 12
	crc32p(data_32[24], cache_32[48]); crc32p(data_32[25], cache_32[50]);
#if INPUT_SIZE > 13
	crc32p(data_32[26], cache_32[52]); crc32p(data_32[27], cache_32[54]);
#if INPUT_SIZE > 14
	crc32p(data_32[28], cache_32[56]); crc32p(data_32[29], cache_32[58]);
#if INPUT_SIZE > 15
	crc32p(data_32[30], cache_32[60]); crc32p(data_32[31], cache_32[62]);
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
	aes(&cache[ 16],  cache     ); aes(&cache[ 32], cache      ); aes(&cache[ 48], cache      ); aes(&cache[ 64], &cache[ 16]);
	aes(&cache[ 80], &cache[ 32]); aes(&cache[ 96], &cache[ 48]); aes(&cache[112], &cache[ 64]); aes(&cache[128], &cache[ 80]);
	aes(&cache[144], &cache[ 96]); aes(&cache[160], &cache[112]); aes(&cache[176], &cache[128]); aes(&cache[192], &cache[144]);
	aes(&cache[208], &cache[160]); aes(&cache[224], &cache[176]); aes(&cache[240], &cache[192]);
	
#ifdef USE_CRC
	size-=64;
	for(uint32_t j=0; j<size; j+=64){
		j_2 = j>>1;
		j_4 = j<<2;
		crc32p(cache_32[j   ], cache_32[j+16]); crc32p(cache_32[j+ 1], cache_32[j+17]);
		crc32p(cache_32[j+ 2], cache_32[j+18]); crc32p(cache_32[j+ 3], cache_32[j+19]);
		crc32p(cache_32[j+ 4], cache_32[j+20]); crc32p(cache_32[j+ 5], cache_32[j+21]);
		crc32p(cache_32[j+ 6], cache_32[j+22]); crc32p(cache_32[j+ 7], cache_32[j+23]);
		crc32p(cache_32[j+ 8], cache_32[j+24]); crc32p(cache_32[j+ 9], cache_32[j+25]);
		crc32p(cache_32[j+10], cache_32[j+26]); crc32p(cache_32[j+11], cache_32[j+27]);
		crc32p(cache_32[j+12], cache_32[j+28]); crc32p(cache_32[j+13], cache_32[j+29]);
		crc32p(cache_32[j+14], cache_32[j+30]); crc32p(cache_32[j+15], cache_32[j+31]);
		crc32p(cache_32[j+16], cache_32[j+32]); crc32p(cache_32[j+17], cache_32[j+33]);
		crc32p(cache_32[j+18], cache_32[j+34]); crc32p(cache_32[j+19], cache_32[j+35]);
		crc32p(cache_32[j+20], cache_32[j+36]); crc32p(cache_32[j+21], cache_32[j+37]);
		crc32p(cache_32[j+22], cache_32[j+38]); crc32p(cache_32[j+23], cache_32[j+39]);
		crc32p(cache_32[j+24], cache_32[j+40]); crc32p(cache_32[j+25], cache_32[j+41]);
		crc32p(cache_32[j+26], cache_32[j+42]); crc32p(cache_32[j+27], cache_32[j+43]);
		crc32p(cache_32[j+28], cache_32[j+44]); crc32p(cache_32[j+29], cache_32[j+45]);
		crc32p(cache_32[j+30], cache_32[j+46]); crc32p(cache_32[j+31], cache_32[j+47]);
		crc32p(cache_32[j+32], cache_32[j+48]); crc32p(cache_32[j+33], cache_32[j+49]);
		crc32p(cache_32[j+34], cache_32[j+50]); crc32p(cache_32[j+35], cache_32[j+51]);
		crc32p(cache_32[j+36], cache_32[j+52]); crc32p(cache_32[j+37], cache_32[j+53]);
		crc32p(cache_32[j+38], cache_32[j+54]); crc32p(cache_32[j+39], cache_32[j+55]);
		crc32p(cache_32[j+40], cache_32[j+56]); crc32p(cache_32[j+41], cache_32[j+57]);
		crc32p(cache_32[j+42], cache_32[j+58]); crc32p(cache_32[j+43], cache_32[j+59]);
		crc32p(cache_32[j+44], cache_32[j+60]); crc32p(cache_32[j+45], cache_32[j+61]);
		crc32p(cache_32[j+46], cache_32[j+62]); crc32p(cache_32[j+47], cache_32[j+63]);
#else
	size-=32;
	for(uint32_t j_2=0; j_2<size; j_2+=32){
		j_4 = j_2<<3;
		cache_64[j_2+ 8] = cache_64[j_2+16] = cache_64[j_2+24] = cache_64[j_2   ];
		cache_64[j_2+ 9] = cache_64[j_2+17] = cache_64[j_2+25] = cache_64[j_2+ 1];
		cache_64[j_2+10] = cache_64[j_2+18] = cache_64[j_2+26] = cache_64[j_2+ 2];
		cache_64[j_2+11] = cache_64[j_2+19] = cache_64[j_2+27] = cache_64[j_2+ 3];
		cache_64[j_2+12] = cache_64[j_2+20] = cache_64[j_2+28] = cache_64[j_2+ 4];
		cache_64[j_2+13] = cache_64[j_2+21] = cache_64[j_2+29] = cache_64[j_2+ 5];
		cache_64[j_2+14] = cache_64[j_2+22] = cache_64[j_2+30] = cache_64[j_2+ 6];
		cache_64[j_2+15] = cache_64[j_2+23] = cache_64[j_2+31] = cache_64[j_2+ 7];
#endif
		aes(&cache[j_4+ 16], &cache[j_4    ]); aes(&cache[j_4+ 32], &cache[j_4    ]);
		aes(&cache[j_4+ 48], &cache[j_4    ]); aes(&cache[j_4+ 64], &cache[j_4+ 16]);
		aes(&cache[j_4+ 80], &cache[j_4+ 32]); aes(&cache[j_4+ 96], &cache[j_4+ 48]);
		aes(&cache[j_4+112], &cache[j_4+ 48]); aes(&cache[j_4+128], &cache[j_4+ 80]);
		aes(&cache[j_4+144], &cache[j_4+ 96]); aes(&cache[j_4+160], &cache[j_4+112]);
		aes(&cache[j_4+176], &cache[j_4+128]); aes(&cache[j_4+192], &cache[j_4+144]);
		aes(&cache[j_4+208], &cache[j_4+160]); aes(&cache[j_4+224], &cache[j_4+176]);
		aes(&cache[j_4+240], &cache[j_4+192]); aes(&cache[j_4    ], &cache[j_4+208]); 
		cache_64[j_2+16] += cache_64[j_2   ]; cache_64[j_2+17] += cache_64[j_2+ 1];
		cache_64[j_2+18] += cache_64[j_2+ 2]; cache_64[j_2+19] += cache_64[j_2+ 3];
		cache_64[j_2+20] += cache_64[j_2+ 4]; cache_64[j_2+21] += cache_64[j_2+ 5];
		cache_64[j_2+22] += cache_64[j_2+ 6]; cache_64[j_2+23] += cache_64[j_2+ 7];
		cache_64[j_2+24] += cache_64[j_2+ 8]; cache_64[j_2+25] += cache_64[j_2+ 9];
		cache_64[j_2+26] += cache_64[j_2+10]; cache_64[j_2+27] += cache_64[j_2+11];
		cache_64[j_2+28] += cache_64[j_2+12]; cache_64[j_2+29] += cache_64[j_2+13];
		cache_64[j_2+30] += cache_64[j_2+14]; cache_64[j_2+31] += cache_64[j_2+15];
	}
	crc32p(*cache_32,    *prevItem   ); crc32p(cache_32[ 1], prevItem[ 1]);
	crc32p(cache_32[ 2], prevItem[ 2]); crc32p(cache_32[ 3], prevItem[ 3]);
	crc32p(cache_32[ 4], prevItem[ 4]); crc32p(cache_32[ 5], prevItem[ 5]);
	crc32p(cache_32[ 6], prevItem[ 6]); crc32p(cache_32[ 7], prevItem[ 7]);
	crc32p(cache_32[ 8], prevItem[ 8]); crc32p(cache_32[ 9], prevItem[ 9]);
	crc32p(cache_32[10], prevItem[10]); crc32p(cache_32[11], prevItem[11]);
	crc32p(cache_32[12], prevItem[12]); crc32p(cache_32[13], prevItem[13]);
	crc32p(cache_32[14], prevItem[14]); crc32p(cache_32[15], prevItem[15]);
	for(uint32_t j=0; j<ITER; j+=16){
		*prevItem    &=mask; prevItem[ 1] &=mask; prevItem[ 2] &=mask; prevItem[ 3] &=mask;
		prevItem[ 4] &=mask; prevItem[ 5] &=mask; prevItem[ 6] &=mask; prevItem[ 7] &=mask;
		prevItem[ 8] &=mask; prevItem[ 9] &=mask; prevItem[10] &=mask; prevItem[11] &=mask;
		prevItem[12] &=mask; prevItem[13] &=mask; prevItem[14] &=mask; prevItem[15] &=mask;
		crc32i(cache_32[*prevItem   ]); crc32i(cache_32[prevItem[ 1]]);
		crc32i(cache_32[prevItem[ 2]]); crc32i(cache_32[prevItem[ 3]]);
		crc32i(cache_32[prevItem[ 4]]); crc32i(cache_32[prevItem[ 5]]);
		crc32i(cache_32[prevItem[ 6]]); crc32i(cache_32[prevItem[ 7]]);
		crc32i(cache_32[prevItem[ 8]]); crc32i(cache_32[prevItem[ 9]]);
		crc32i(cache_32[prevItem[10]]); crc32i(cache_32[prevItem[11]]);
		crc32i(cache_32[prevItem[12]]); crc32i(cache_32[prevItem[13]]);
		crc32i(cache_32[prevItem[14]]); crc32i(cache_32[prevItem[15]]);
	}
	for(uint32_t j=0; j<SIZE/8; j+=OUTPUT_SIZE*2){
		 *out_64   += cache_64[j  ]; out_64[1] += cache_64[j+1];
#if OUTPUT_SIZE > 1
		 out_64[2] += cache_64[j+2]; out_64[3] += cache_64[j+3];
#if OUTPUT_SIZE > 2
		 out_64[4] += cache_64[j+4]; out_64[5] += cache_64[j+5];
#if OUTPUT_SIZE > 3
		 out_64[6] += cache_64[j+6]; out_64[7] += cache_64[j+7];
#endif
#endif
#endif
	}
}

