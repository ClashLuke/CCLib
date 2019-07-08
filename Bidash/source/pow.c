// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "config.h"
#include "error.h"

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
#define crc32p(y,x) __asm__("crc32w %w0,%w0,%w1\n":"+r"(y):"r"(x));
#else
#define crc32p(y,x) \
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

#define ITEM_CALCULATION() \
	mix[  1] = mix[  3] = mix[  5] = mix[  7] = mix[  9] = mix[ 11] = mix[ 13] =\
	mix[ 15] = mix[ 17] = mix[ 19] = mix[ 21] = mix[ 23] = mix[ 25] = mix[ 27] =\
	mix[ 29] = mix[ 31] = mix[ 33] = mix[ 35] = mix[ 37] = mix[ 39] = mix[ 41] =\
	mix[ 43] = mix[ 45] = mix[ 47] = mix[ 49] = mix[ 51] = mix[ 53] = mix[ 55] =\
	mix[ 57] = mix[ 59] = mix[ 61] = mix[ 63] = mix[ 65] = mix[ 67] = mix[ 69] =\
	mix[ 71] = mix[ 73] = mix[ 75] = mix[ 77] = mix[ 79] = mix[ 81] = mix[ 83] =\
	mix[ 85] = mix[ 87] = mix[ 89] = mix[ 91] = mix[ 93] = mix[ 95] = mix[ 97] =\
	mix[ 99] = mix[101] = mix[103] = mix[105] = mix[107] = mix[109] = mix[111] =\
	mix[113] = mix[115] = mix[117] = mix[119] = mix[121] = mix[123] = mix[125] =\
	mix[127] = 0;\
	*mix     = mix[  2] = mix[  4] = mix[  6] = mix[  8] = mix[ 10] = mix[ 12] =\
	mix[ 14] = mix[ 16] = mix[ 18] = mix[ 20] = mix[ 22] = mix[ 24] = mix[ 26] =\
	mix[ 28] = mix[ 30] = mix[ 32] = mix[ 34] = mix[ 36] = mix[ 38] = mix[ 40] =\
	mix[ 42] = mix[ 44] = mix[ 46] = mix[ 48] = mix[ 50] = mix[ 52] = mix[ 54] =\
	mix[ 56] = mix[ 58] = mix[ 60] = mix[ 62] = mix[ 64] = mix[ 66] = mix[ 68] =\
	mix[ 70] = mix[ 72] = mix[ 74] = mix[ 76] = mix[ 78] = mix[ 80] = mix[ 82] =\
	mix[ 84] = mix[ 86] = mix[ 88] = mix[ 90] = mix[ 92] = mix[ 94] = mix[ 96] =\
	mix[ 98] = mix[100] = mix[102] = mix[104] = mix[106] = mix[108] = mix[110] =\
	mix[112] = mix[114] = mix[116] = mix[118] = mix[120] = mix[122] = mix[124] =\
	mix[126] = i;\
	mix[ 16]++; mix[ 18]++; mix[ 20]++; mix[ 22]++;\
	mix[ 24]++; mix[ 26]++; mix[ 28]++; mix[ 30]++;\
	mix[ 32]+=2; mix[ 34]+=2; mix[ 36]+=2; mix[ 38]+=2;\
	mix[ 40]+=2; mix[ 42]+=2; mix[ 44]+=2; mix[ 46]+=2;\
	mix[ 48]+=3; mix[ 50]+=3; mix[ 52]+=3; mix[ 54]+=3;\
	mix[ 56]+=3; mix[ 58]+=3; mix[ 60]+=3; mix[ 62]+=3;\
	mix[ 64]+=4; mix[ 66]+=4; mix[ 68]+=4; mix[ 70]+=4;\
	mix[ 72]+=4; mix[ 74]+=4; mix[ 76]+=4; mix[ 78]+=4;\
	mix[ 80]+=5; mix[ 82]+=5; mix[ 84]+=5; mix[ 86]+=5;\
	mix[ 88]+=5; mix[ 90]+=5; mix[ 92]+=5; mix[ 94]+=5;\
	mix[ 96]+=6; mix[ 96]+=6; mix[ 98]+=6; mix[100]+=6;\
	mix[104]+=6; mix[106]+=6; mix[108]+=6; mix[110]+=6;\
	mix[112]+=7; mix[114]+=7; mix[116]+=7; mix[118]+=7;\
	mix[120]+=7; mix[122]+=7; mix[124]+=7; mix[126]+=7;\
	aes(mix8_0, seed); aes(mix8_1, seed1);\
	crc32i(*seed_32);    crc32i(seed_32[ 1]); crc32i(seed_32[ 2]); crc32i(seed_32[ 3]);\
	crc32i(seed_32[ 4]); crc32i(seed_32[ 5]); crc32i(seed_32[ 6]); crc32i(seed_32[ 7]);\
	crc32i(seed_32[ 8]); crc32i(seed_32[ 9]); crc32i(seed_32[10]); crc32i(seed_32[11]);\
	crc32i(seed_32[12]); crc32i(seed_32[13]); crc32i(seed_32[14]); crc32i(seed_32[15]);\
	aes(mix8_2, seed); aes(mix8_3, seed1);\
	crc32i(*seed_32);    crc32i(seed_32[ 1]); crc32i(seed_32[ 2]); crc32i(seed_32[ 3]);\
	crc32i(seed_32[ 4]); crc32i(seed_32[ 5]); crc32i(seed_32[ 6]); crc32i(seed_32[ 7]);\
	crc32i(seed_32[ 8]); crc32i(seed_32[ 9]); crc32i(seed_32[10]); crc32i(seed_32[11]);\
	crc32i(seed_32[12]); crc32i(seed_32[13]); crc32i(seed_32[14]); crc32i(seed_32[15]);\
	crc32p(mix32[ 16], *mix32);     crc32p(mix32[ 17], mix32[  1]);\
	crc32p(mix32[ 18], mix32[  2]); crc32p(mix32[ 19], mix32[  3]);\
	crc32p(mix32[ 20], mix32[  4]); crc32p(mix32[ 21], mix32[  5]);\
	crc32p(mix32[ 22], mix32[  6]); crc32p(mix32[ 23], mix32[  7]);\
	crc32p(mix32[ 24], mix32[  8]); crc32p(mix32[ 25], mix32[  9]);\
	crc32p(mix32[ 26], mix32[ 10]); crc32p(mix32[ 27], mix32[ 11]);\
	crc32p(mix32[ 28], mix32[ 12]); crc32p(mix32[ 29], mix32[ 13]);\
	crc32p(mix32[ 30], mix32[ 14]); crc32p(mix32[ 31], mix32[ 15]);\
	crc32p(mix32[ 32], mix32[ 16]); crc32p(mix32[ 33], mix32[ 17]);\
	crc32p(mix32[ 34], mix32[ 18]); crc32p(mix32[ 35], mix32[ 19]);\
	crc32p(mix32[ 36], mix32[ 20]); crc32p(mix32[ 37], mix32[ 21]);\
	crc32p(mix32[ 38], mix32[ 22]); crc32p(mix32[ 39], mix32[ 23]);\
	crc32p(mix32[ 40], mix32[ 24]); crc32p(mix32[ 41], mix32[ 25]);\
	crc32p(mix32[ 42], mix32[ 26]); crc32p(mix32[ 43], mix32[ 27]);\
	crc32p(mix32[ 44], mix32[ 28]); crc32p(mix32[ 45], mix32[ 29]);\
	crc32p(mix32[ 46], mix32[ 30]); crc32p(mix32[ 47], mix32[ 31]);\
	crc32p(mix32[ 48], mix32[ 32]); crc32p(mix32[ 49], mix32[ 33]);\
	crc32p(mix32[ 50], mix32[ 34]); crc32p(mix32[ 51], mix32[ 35]);\
	crc32p(mix32[ 52], mix32[ 36]); crc32p(mix32[ 53], mix32[ 37]);\
	crc32p(mix32[ 54], mix32[ 38]); crc32p(mix32[ 55], mix32[ 39]);\
	crc32p(mix32[ 56], mix32[ 40]); crc32p(mix32[ 57], mix32[ 41]);\
	crc32p(mix32[ 58], mix32[ 42]); crc32p(mix32[ 59], mix32[ 43]);\
	crc32p(mix32[ 60], mix32[ 44]); crc32p(mix32[ 61], mix32[ 45]);\
	crc32p(mix32[ 62], mix32[ 46]); crc32p(mix32[ 63], mix32[ 47]);\
	crc32p(mix32[ 64], mix32[ 48]); crc32p(mix32[ 65], mix32[ 49]);\
	crc32p(mix32[ 66], mix32[ 50]); crc32p(mix32[ 67], mix32[ 51]);\
	crc32p(mix32[ 68], mix32[ 52]); crc32p(mix32[ 69], mix32[ 53]);\
	crc32p(mix32[ 70], mix32[ 54]); crc32p(mix32[ 71], mix32[ 55]);\
	crc32p(mix32[ 72], mix32[ 56]); crc32p(mix32[ 73], mix32[ 57]);\
	crc32p(mix32[ 74], mix32[ 58]); crc32p(mix32[ 75], mix32[ 59]);\
	crc32p(mix32[ 76], mix32[ 60]); crc32p(mix32[ 77], mix32[ 61]);\
	crc32p(mix32[ 78], mix32[ 62]); crc32p(mix32[ 79], mix32[ 63]);\
	crc32p(mix32[ 80], mix32[ 64]); crc32p(mix32[ 81], mix32[ 65]);\
	crc32p(mix32[ 82], mix32[ 66]); crc32p(mix32[ 83], mix32[ 67]);\
	crc32p(mix32[ 84], mix32[ 68]); crc32p(mix32[ 85], mix32[ 69]);\
	crc32p(mix32[ 86], mix32[ 70]); crc32p(mix32[ 87], mix32[ 71]);\
	crc32p(mix32[ 88], mix32[ 72]); crc32p(mix32[ 89], mix32[ 73]);\
	crc32p(mix32[ 90], mix32[ 74]); crc32p(mix32[ 91], mix32[ 75]);\
	crc32p(mix32[ 92], mix32[ 76]); crc32p(mix32[ 93], mix32[ 77]);\
	crc32p(mix32[ 94], mix32[ 78]); crc32p(mix32[ 95], mix32[ 79]);\
	crc32p(mix32[ 96], mix32[ 80]); crc32p(mix32[ 97], mix32[ 81]);\
	crc32p(mix32[ 98], mix32[ 82]); crc32p(mix32[ 99], mix32[ 83]);\
	crc32p(mix32[100], mix32[ 84]); crc32p(mix32[101], mix32[ 85]);\
	crc32p(mix32[102], mix32[ 86]); crc32p(mix32[103], mix32[ 87]);\
	crc32p(mix32[104], mix32[ 88]); crc32p(mix32[105], mix32[ 89]);\
	crc32p(mix32[106], mix32[ 90]); crc32p(mix32[107], mix32[ 91]);\
	crc32p(mix32[108], mix32[ 92]); crc32p(mix32[109], mix32[ 93]);\
	crc32p(mix32[110], mix32[ 94]); crc32p(mix32[111], mix32[ 95]);\
	crc32p(mix32[112], mix32[ 96]); crc32p(mix32[113], mix32[ 97]);\
	crc32p(mix32[114], mix32[ 98]); crc32p(mix32[115], mix32[ 99]);\
	crc32p(mix32[116], mix32[100]); crc32p(mix32[117], mix32[101]);\
	crc32p(mix32[118], mix32[102]); crc32p(mix32[119], mix32[103]);\
	crc32p(mix32[120], mix32[104]); crc32p(mix32[121], mix32[105]);\
	crc32p(mix32[122], mix32[106]); crc32p(mix32[123], mix32[107]);\
	crc32p(mix32[124], mix32[108]); crc32p(mix32[125], mix32[109]);\
	crc32p(mix32[126], mix32[110]); crc32p(mix32[127], mix32[111]);\
	crc32p(mix32[128], mix32[112]); crc32p(mix32[129], mix32[113]);\
	crc32p(mix32[130], mix32[114]); crc32p(mix32[131], mix32[115]);\
	crc32p(mix32[132], mix32[116]); crc32p(mix32[133], mix32[117]);\
	crc32p(mix32[134], mix32[118]); crc32p(mix32[135], mix32[119]);\
	crc32p(mix32[136], mix32[120]); crc32p(mix32[137], mix32[121]);\
	crc32p(mix32[138], mix32[122]); crc32p(mix32[139], mix32[123]);\
	crc32p(mix32[140], mix32[124]); crc32p(mix32[141], mix32[125]);\
	crc32p(mix32[142], mix32[126]); crc32p(mix32[143], mix32[127]);\
	crc32p(mix32[144], mix32[128]); crc32p(mix32[145], mix32[129]);\
	crc32p(mix32[146], mix32[130]); crc32p(mix32[147], mix32[131]);\
	crc32p(mix32[148], mix32[132]); crc32p(mix32[149], mix32[133]);\
	crc32p(mix32[150], mix32[134]); crc32p(mix32[151], mix32[135]);\
	crc32p(mix32[152], mix32[136]); crc32p(mix32[153], mix32[137]);\
	crc32p(mix32[154], mix32[138]); crc32p(mix32[155], mix32[139]);\
	crc32p(mix32[156], mix32[140]); crc32p(mix32[157], mix32[141]);\
	crc32p(mix32[158], mix32[142]); crc32p(mix32[159], mix32[143]);\
	crc32p(mix32[160], mix32[144]); crc32p(mix32[161], mix32[145]);\
	crc32p(mix32[162], mix32[146]); crc32p(mix32[163], mix32[147]);\
	crc32p(mix32[164], mix32[148]); crc32p(mix32[165], mix32[149]);\
	crc32p(mix32[166], mix32[150]); crc32p(mix32[167], mix32[151]);\
	crc32p(mix32[168], mix32[152]); crc32p(mix32[169], mix32[153]);\
	crc32p(mix32[170], mix32[154]); crc32p(mix32[171], mix32[155]);\
	crc32p(mix32[172], mix32[156]); crc32p(mix32[173], mix32[157]);\
	crc32p(mix32[174], mix32[158]); crc32p(mix32[175], mix32[159]);\
	crc32p(mix32[176], mix32[160]); crc32p(mix32[177], mix32[161]);\
	crc32p(mix32[178], mix32[162]); crc32p(mix32[179], mix32[163]);\
	crc32p(mix32[180], mix32[164]); crc32p(mix32[181], mix32[165]);\
	crc32p(mix32[182], mix32[166]); crc32p(mix32[183], mix32[167]);\
	crc32p(mix32[184], mix32[168]); crc32p(mix32[185], mix32[169]);\
	crc32p(mix32[186], mix32[170]); crc32p(mix32[187], mix32[171]);\
	crc32p(mix32[188], mix32[172]); crc32p(mix32[189], mix32[173]);\
	crc32p(mix32[190], mix32[174]); crc32p(mix32[191], mix32[175]);\
	crc32p(mix32[192], mix32[176]); crc32p(mix32[193], mix32[177]);\
	crc32p(mix32[194], mix32[178]); crc32p(mix32[195], mix32[179]);\
	crc32p(mix32[196], mix32[180]); crc32p(mix32[197], mix32[181]);\
	crc32p(mix32[198], mix32[182]); crc32p(mix32[199], mix32[183]);\
	crc32p(mix32[200], mix32[184]); crc32p(mix32[201], mix32[185]);\
	crc32p(mix32[202], mix32[186]); crc32p(mix32[203], mix32[187]);\
	crc32p(mix32[204], mix32[188]); crc32p(mix32[205], mix32[189]);\
	crc32p(mix32[206], mix32[190]); crc32p(mix32[207], mix32[191]);\
	crc32p(mix32[208], mix32[192]); crc32p(mix32[209], mix32[193]);\
	crc32p(mix32[210], mix32[194]); crc32p(mix32[211], mix32[195]);\
	crc32p(mix32[212], mix32[196]); crc32p(mix32[213], mix32[197]);\
	crc32p(mix32[214], mix32[198]); crc32p(mix32[215], mix32[199]);\
	crc32p(mix32[216], mix32[200]); crc32p(mix32[217], mix32[201]);\
	crc32p(mix32[218], mix32[202]); crc32p(mix32[219], mix32[203]);\
	crc32p(mix32[220], mix32[204]); crc32p(mix32[221], mix32[205]);\
	crc32p(mix32[222], mix32[206]); crc32p(mix32[223], mix32[207]);\
	crc32p(mix32[224], mix32[208]); crc32p(mix32[225], mix32[209]);\
	crc32p(mix32[226], mix32[210]); crc32p(mix32[227], mix32[211]);\
	crc32p(mix32[228], mix32[212]); crc32p(mix32[229], mix32[213]);\
	crc32p(mix32[230], mix32[214]); crc32p(mix32[231], mix32[215]);\
	crc32p(mix32[232], mix32[216]); crc32p(mix32[233], mix32[217]);\
	crc32p(mix32[234], mix32[218]); crc32p(mix32[235], mix32[219]);\
	crc32p(mix32[236], mix32[220]); crc32p(mix32[237], mix32[221]);\
	crc32p(mix32[238], mix32[222]); crc32p(mix32[239], mix32[223]);\
	crc32p(mix32[240], mix32[224]); crc32p(mix32[241], mix32[225]);\
	crc32p(mix32[242], mix32[226]); crc32p(mix32[243], mix32[227]);\
	crc32p(mix32[244], mix32[228]); crc32p(mix32[245], mix32[229]);\
	crc32p(mix32[246], mix32[230]); crc32p(mix32[247], mix32[231]);\
	crc32p(mix32[248], mix32[232]); crc32p(mix32[249], mix32[233]);\
	crc32p(mix32[250], mix32[234]); crc32p(mix32[251], mix32[235]);\
	crc32p(mix32[252], mix32[236]); crc32p(mix32[253], mix32[237]);\
	crc32p(mix32[254], mix32[238]); crc32p(mix32[255], mix32[239]);\
	mix[128] = mix[256] = mix[384] = *mix;\
	mix[129] = mix[257] = mix[385] = mix[  1];\
	mix[130] = mix[258] = mix[386] = mix[  2];\
	mix[131] = mix[259] = mix[387] = mix[  3];\
	mix[132] = mix[260] = mix[388] = mix[  4];\
	mix[133] = mix[261] = mix[389] = mix[  5];\
	mix[134] = mix[262] = mix[390] = mix[  6];\
	mix[135] = mix[263] = mix[391] = mix[  7];\
	mix[136] = mix[264] = mix[392] = mix[  8];\
	mix[137] = mix[265] = mix[393] = mix[  9];\
	mix[138] = mix[266] = mix[394] = mix[ 10];\
	mix[139] = mix[267] = mix[395] = mix[ 11];\
	mix[140] = mix[268] = mix[396] = mix[ 12];\
	mix[141] = mix[269] = mix[397] = mix[ 13];\
	mix[142] = mix[270] = mix[398] = mix[ 14];\
	mix[143] = mix[271] = mix[399] = mix[ 15];\
	mix[144] = mix[272] = mix[400] = mix[ 16];\
	mix[145] = mix[273] = mix[401] = mix[ 17];\
	mix[146] = mix[274] = mix[402] = mix[ 18];\
	mix[147] = mix[275] = mix[403] = mix[ 19];\
	mix[148] = mix[276] = mix[404] = mix[ 20];\
	mix[149] = mix[277] = mix[405] = mix[ 21];\
	mix[150] = mix[278] = mix[406] = mix[ 22];\
	mix[151] = mix[279] = mix[407] = mix[ 23];\
	mix[152] = mix[280] = mix[408] = mix[ 24];\
	mix[153] = mix[281] = mix[409] = mix[ 25];\
	mix[154] = mix[282] = mix[410] = mix[ 26];\
	mix[155] = mix[283] = mix[411] = mix[ 27];\
	mix[156] = mix[284] = mix[412] = mix[ 28];\
	mix[157] = mix[285] = mix[413] = mix[ 29];\
	mix[158] = mix[286] = mix[414] = mix[ 30];\
	mix[159] = mix[287] = mix[415] = mix[ 31];\
	mix[160] = mix[288] = mix[416] = mix[ 32];\
	mix[161] = mix[289] = mix[417] = mix[ 33];\
	mix[162] = mix[290] = mix[418] = mix[ 34];\
	mix[163] = mix[291] = mix[419] = mix[ 35];\
	mix[164] = mix[292] = mix[420] = mix[ 36];\
	mix[165] = mix[293] = mix[421] = mix[ 37];\
	mix[166] = mix[294] = mix[422] = mix[ 38];\
	mix[167] = mix[295] = mix[423] = mix[ 39];\
	mix[168] = mix[296] = mix[424] = mix[ 40];\
	mix[169] = mix[297] = mix[425] = mix[ 41];\
	mix[170] = mix[298] = mix[426] = mix[ 42];\
	mix[171] = mix[299] = mix[427] = mix[ 43];\
	mix[172] = mix[300] = mix[428] = mix[ 44];\
	mix[173] = mix[301] = mix[429] = mix[ 45];\
	mix[174] = mix[302] = mix[430] = mix[ 46];\
	mix[175] = mix[303] = mix[431] = mix[ 47];\
	mix[176] = mix[304] = mix[432] = mix[ 48];\
	mix[177] = mix[305] = mix[433] = mix[ 49];\
	mix[178] = mix[306] = mix[434] = mix[ 50];\
	mix[179] = mix[307] = mix[435] = mix[ 51];\
	mix[180] = mix[308] = mix[436] = mix[ 52];\
	mix[181] = mix[309] = mix[437] = mix[ 53];\
	mix[182] = mix[310] = mix[438] = mix[ 54];\
	mix[183] = mix[311] = mix[439] = mix[ 55];\
	mix[184] = mix[312] = mix[440] = mix[ 56];\
	mix[185] = mix[313] = mix[441] = mix[ 57];\
	mix[186] = mix[314] = mix[442] = mix[ 58];\
	mix[187] = mix[315] = mix[443] = mix[ 59];\
	mix[188] = mix[316] = mix[444] = mix[ 60];\
	mix[189] = mix[317] = mix[445] = mix[ 61];\
	mix[190] = mix[318] = mix[446] = mix[ 62];\
	mix[191] = mix[319] = mix[447] = mix[ 63];\
	mix[192] = mix[320] = mix[448] = mix[ 64];\
	mix[193] = mix[321] = mix[449] = mix[ 65];\
	mix[194] = mix[322] = mix[450] = mix[ 66];\
	mix[195] = mix[323] = mix[451] = mix[ 67];\
	mix[196] = mix[324] = mix[452] = mix[ 68];\
	mix[197] = mix[325] = mix[453] = mix[ 69];\
	mix[198] = mix[326] = mix[454] = mix[ 70];\
	mix[199] = mix[327] = mix[455] = mix[ 71];\
	mix[200] = mix[328] = mix[456] = mix[ 72];\
	mix[201] = mix[329] = mix[457] = mix[ 73];\
	mix[202] = mix[330] = mix[458] = mix[ 74];\
	mix[203] = mix[331] = mix[459] = mix[ 75];\
	mix[204] = mix[332] = mix[460] = mix[ 76];\
	mix[205] = mix[333] = mix[461] = mix[ 77];\
	mix[206] = mix[334] = mix[462] = mix[ 78];\
	mix[207] = mix[335] = mix[463] = mix[ 79];\
	mix[208] = mix[336] = mix[464] = mix[ 80];\
	mix[209] = mix[337] = mix[465] = mix[ 81];\
	mix[210] = mix[338] = mix[466] = mix[ 82];\
	mix[211] = mix[339] = mix[467] = mix[ 83];\
	mix[212] = mix[340] = mix[468] = mix[ 84];\
	mix[213] = mix[341] = mix[469] = mix[ 85];\
	mix[214] = mix[342] = mix[470] = mix[ 86];\
	mix[215] = mix[343] = mix[471] = mix[ 87];\
	mix[216] = mix[344] = mix[472] = mix[ 88];\
	mix[217] = mix[345] = mix[473] = mix[ 89];\
	mix[218] = mix[346] = mix[474] = mix[ 90];\
	mix[219] = mix[347] = mix[475] = mix[ 91];\
	mix[220] = mix[348] = mix[476] = mix[ 92];\
	mix[221] = mix[349] = mix[477] = mix[ 93];\
	mix[222] = mix[350] = mix[478] = mix[ 94];\
	mix[223] = mix[351] = mix[479] = mix[ 95];\
	mix[224] = mix[352] = mix[480] = mix[ 96];\
	mix[225] = mix[353] = mix[481] = mix[ 97];\
	mix[226] = mix[354] = mix[482] = mix[ 98];\
	mix[227] = mix[355] = mix[483] = mix[ 99];\
	mix[228] = mix[356] = mix[484] = mix[100];\
	mix[229] = mix[357] = mix[485] = mix[101];\
	mix[230] = mix[358] = mix[486] = mix[102];\
	mix[231] = mix[359] = mix[487] = mix[103];\
	mix[232] = mix[360] = mix[488] = mix[104];\
	mix[233] = mix[361] = mix[489] = mix[105];\
	mix[234] = mix[362] = mix[490] = mix[106];\
	mix[235] = mix[363] = mix[491] = mix[107];\
	mix[236] = mix[364] = mix[492] = mix[108];\
	mix[237] = mix[365] = mix[493] = mix[109];\
	mix[238] = mix[366] = mix[494] = mix[110];\
	mix[239] = mix[367] = mix[495] = mix[111];\
	mix[240] = mix[368] = mix[496] = mix[112];\
	mix[241] = mix[369] = mix[497] = mix[113];\
	mix[242] = mix[370] = mix[498] = mix[114];\
	mix[243] = mix[371] = mix[499] = mix[115];\
	mix[244] = mix[372] = mix[500] = mix[116];\
	mix[245] = mix[373] = mix[501] = mix[117];\
	mix[246] = mix[374] = mix[502] = mix[118];\
	mix[247] = mix[375] = mix[503] = mix[119];\
	mix[248] = mix[376] = mix[504] = mix[120];\
	mix[249] = mix[377] = mix[505] = mix[121];\
	mix[250] = mix[378] = mix[506] = mix[122];\
	mix[251] = mix[379] = mix[507] = mix[123];\
	mix[252] = mix[380] = mix[508] = mix[124];\
	mix[253] = mix[381] = mix[509] = mix[125];\
	mix[254] = mix[382] = mix[510] = mix[126];\
	mix[255] = mix[383] = mix[511] = mix[127];\
	mix[128] += mix[  1]; mix[129] += mix[  2];\
	mix[130] += mix[  3]; mix[131] += mix[  4];\
	mix[132] += mix[  5]; mix[133] += mix[  6];\
	mix[134] += mix[  7]; mix[135] += mix[  8];\
	mix[136] += mix[  9]; mix[137] += mix[ 10];\
	mix[138] += mix[ 11]; mix[139] += mix[ 12];\
	mix[140] += mix[ 13]; mix[141] += mix[ 14];\
	mix[142] += mix[ 15]; mix[143] += mix[ 16];\
	mix[144] += mix[ 17]; mix[145] += mix[ 18];\
	mix[146] += mix[ 19]; mix[147] += mix[ 20];\
	mix[148] += mix[ 21]; mix[149] += mix[ 22];\
	mix[150] += mix[ 23]; mix[151] += mix[ 24];\
	mix[152] += mix[ 25]; mix[153] += mix[ 26];\
	mix[154] += mix[ 27]; mix[155] += mix[ 28];\
	mix[156] += mix[ 29]; mix[157] += mix[ 30];\
	mix[158] += mix[ 31]; mix[159] += mix[ 32];\
	mix[160] += mix[ 33]; mix[161] += mix[ 34];\
	mix[162] += mix[ 35]; mix[163] += mix[ 36];\
	mix[164] += mix[ 37]; mix[165] += mix[ 38];\
	mix[166] += mix[ 39]; mix[167] += mix[ 40];\
	mix[168] += mix[ 41]; mix[169] += mix[ 42];\
	mix[170] += mix[ 43]; mix[171] += mix[ 44];\
	mix[172] += mix[ 45]; mix[173] += mix[ 46];\
	mix[174] += mix[ 47]; mix[175] += mix[ 48];\
	mix[176] += mix[ 49]; mix[177] += mix[ 50];\
	mix[178] += mix[ 51]; mix[179] += mix[ 52];\
	mix[180] += mix[ 53]; mix[181] += mix[ 54];\
	mix[182] += mix[ 55]; mix[183] += mix[ 56];\
	mix[184] += mix[ 57]; mix[185] += mix[ 58];\
	mix[186] += mix[ 59]; mix[187] += mix[ 60];\
	mix[188] += mix[ 61]; mix[189] += mix[ 62];\
	mix[190] += mix[ 63]; mix[191] += mix[ 64];\
	mix[192] += mix[ 65]; mix[193] += mix[ 66];\
	mix[194] += mix[ 67]; mix[195] += mix[ 68];\
	mix[196] += mix[ 69]; mix[197] += mix[ 70];\
	mix[198] += mix[ 71]; mix[199] += mix[ 72];\
	mix[200] += mix[ 73]; mix[201] += mix[ 74];\
	mix[202] += mix[ 75]; mix[203] += mix[ 76];\
	mix[204] += mix[ 77]; mix[205] += mix[ 78];\
	mix[206] += mix[ 79]; mix[207] += mix[ 80];\
	mix[208] += mix[ 81]; mix[209] += mix[ 82];\
	mix[210] += mix[ 83]; mix[211] += mix[ 84];\
	mix[212] += mix[ 85]; mix[213] += mix[ 86];\
	mix[214] += mix[ 87]; mix[215] += mix[ 88];\
	mix[216] += mix[ 89]; mix[217] += mix[ 90];\
	mix[218] += mix[ 91]; mix[219] += mix[ 92];\
	mix[220] += mix[ 93]; mix[221] += mix[ 94];\
	mix[222] += mix[ 95]; mix[223] += mix[ 96];\
	mix[224] += mix[ 97]; mix[225] += mix[ 98];\
	mix[226] += mix[ 99]; mix[227] += mix[100];\
	mix[228] += mix[101]; mix[229] += mix[102];\
	mix[230] += mix[103]; mix[231] += mix[104];\
	mix[232] += mix[105]; mix[233] += mix[106];\
	mix[234] += mix[107]; mix[235] += mix[108];\
	mix[236] += mix[109]; mix[237] += mix[110];\
	mix[238] += mix[111]; mix[239] += mix[112];\
	mix[240] += mix[113]; mix[241] += mix[114];\
	mix[242] += mix[115]; mix[243] += mix[116];\
	mix[244] += mix[117]; mix[245] += mix[118];\
	mix[246] += mix[119]; mix[247] += mix[120];\
	mix[248] += mix[121]; mix[249] += mix[122];\
	mix[250] += mix[123]; mix[251] += mix[124];\
	mix[252] += mix[125]; mix[253] += mix[126];\
	mix[254] += mix[127]; mix[255] += mix[128];\
	mix[256] += mix[129]; mix[257] += mix[130];\
	mix[258] += mix[131]; mix[259] += mix[132];\
	mix[260] += mix[133]; mix[261] += mix[134];\
	mix[262] += mix[135]; mix[263] += mix[136];\
	mix[264] += mix[137]; mix[265] += mix[138];\
	mix[266] += mix[139]; mix[267] += mix[140];\
	mix[268] += mix[141]; mix[269] += mix[142];\
	mix[270] += mix[143]; mix[271] += mix[144];\
	mix[272] += mix[145]; mix[273] += mix[146];\
	mix[274] += mix[147]; mix[275] += mix[148];\
	mix[276] += mix[149]; mix[277] += mix[150];\
	mix[278] += mix[151]; mix[279] += mix[152];\
	mix[280] += mix[153]; mix[281] += mix[154];\
	mix[282] += mix[155]; mix[283] += mix[156];\
	mix[284] += mix[157]; mix[285] += mix[158];\
	mix[286] += mix[159]; mix[287] += mix[160];\
	mix[288] += mix[161]; mix[289] += mix[162];\
	mix[290] += mix[163]; mix[291] += mix[164];\
	mix[292] += mix[165]; mix[293] += mix[166];\
	mix[294] += mix[167]; mix[295] += mix[168];\
	mix[296] += mix[169]; mix[297] += mix[170];\
	mix[298] += mix[171]; mix[299] += mix[172];\
	mix[300] += mix[173]; mix[301] += mix[174];\
	mix[302] += mix[175]; mix[303] += mix[176];\
	mix[304] += mix[177]; mix[305] += mix[178];\
	mix[306] += mix[179]; mix[307] += mix[180];\
	mix[308] += mix[181]; mix[309] += mix[182];\
	mix[310] += mix[183]; mix[311] += mix[184];\
	mix[312] += mix[185]; mix[313] += mix[186];\
	mix[314] += mix[187]; mix[315] += mix[188];\
	mix[316] += mix[189]; mix[317] += mix[190];\
	mix[318] += mix[191]; mix[319] += mix[192];\
	mix[320] += mix[193]; mix[321] += mix[194];\
	mix[322] += mix[195]; mix[323] += mix[196];\
	mix[324] += mix[197]; mix[325] += mix[198];\
	mix[326] += mix[199]; mix[327] += mix[200];\
	mix[328] += mix[201]; mix[329] += mix[202];\
	mix[330] += mix[203]; mix[331] += mix[204];\
	mix[332] += mix[205]; mix[333] += mix[206];\
	mix[334] += mix[207]; mix[335] += mix[208];\
	mix[336] += mix[209]; mix[337] += mix[210];\
	mix[338] += mix[211]; mix[339] += mix[212];\
	mix[340] += mix[213]; mix[341] += mix[214];\
	mix[342] += mix[215]; mix[343] += mix[216];\
	mix[344] += mix[217]; mix[345] += mix[218];\
	mix[346] += mix[219]; mix[347] += mix[220];\
	mix[348] += mix[221]; mix[349] += mix[222];\
	mix[350] += mix[223]; mix[351] += mix[224];\
	mix[352] += mix[225]; mix[353] += mix[226];\
	mix[354] += mix[227]; mix[355] += mix[228];\
	mix[356] += mix[229]; mix[357] += mix[230];\
	mix[358] += mix[231]; mix[359] += mix[232];\
	mix[360] += mix[233]; mix[361] += mix[234];\
	mix[362] += mix[235]; mix[363] += mix[236];\
	mix[364] += mix[237]; mix[365] += mix[238];\
	mix[366] += mix[239]; mix[367] += mix[240];\
	mix[368] += mix[241]; mix[369] += mix[242];\
	mix[370] += mix[243]; mix[371] += mix[244];\
	mix[372] += mix[245]; mix[373] += mix[246];\
	mix[374] += mix[247]; mix[375] += mix[248];\
	mix[376] += mix[249]; mix[377] += mix[250];\
	mix[378] += mix[251]; mix[379] += mix[252];\
	mix[380] += mix[253]; mix[381] += mix[254];\
	mix[382] += mix[255]; mix[383] += mix[256];\
	mix[384] += mix[257]; mix[385] += mix[258];\
	mix[386] += mix[259]; mix[387] += mix[260];\
	mix[388] += mix[261]; mix[389] += mix[262];\
	mix[390] += mix[263]; mix[391] += mix[264];\
	mix[392] += mix[265]; mix[393] += mix[266];\
	mix[394] += mix[267]; mix[395] += mix[268];\
	mix[396] += mix[269]; mix[397] += mix[270];\
	mix[398] += mix[271]; mix[399] += mix[272];\
	mix[400] += mix[273]; mix[401] += mix[274];\
	mix[402] += mix[275]; mix[403] += mix[276];\
	mix[404] += mix[277]; mix[405] += mix[278];\
	mix[406] += mix[279]; mix[407] += mix[280];\
	mix[408] += mix[281]; mix[409] += mix[282];\
	mix[410] += mix[283]; mix[411] += mix[284];\
	mix[412] += mix[285]; mix[413] += mix[286];\
	mix[414] += mix[287]; mix[415] += mix[288];\
	mix[416] += mix[289]; mix[417] += mix[290];\
	mix[418] += mix[291]; mix[419] += mix[292];\
	mix[420] += mix[293]; mix[421] += mix[294];\
	mix[422] += mix[295]; mix[423] += mix[296];\
	mix[424] += mix[297]; mix[425] += mix[298];\
	mix[426] += mix[299]; mix[427] += mix[300];\
	mix[428] += mix[301]; mix[429] += mix[302];\
	mix[430] += mix[303]; mix[431] += mix[304];\
	mix[432] += mix[305]; mix[433] += mix[306];\
	mix[434] += mix[307]; mix[435] += mix[308];\
	mix[436] += mix[309]; mix[437] += mix[310];\
	mix[438] += mix[311]; mix[439] += mix[312];\
	mix[440] += mix[313]; mix[441] += mix[314];\
	mix[442] += mix[315]; mix[443] += mix[316];\
	mix[444] += mix[317]; mix[445] += mix[318];\
	mix[446] += mix[319]; mix[447] += mix[320];\
	mix[448] += mix[321]; mix[449] += mix[322];\
	mix[450] += mix[323]; mix[451] += mix[324];\
	mix[452] += mix[325]; mix[453] += mix[326];\
	mix[454] += mix[327]; mix[455] += mix[328];\
	mix[456] += mix[329]; mix[457] += mix[330];\
	mix[458] += mix[331]; mix[459] += mix[332];\
	mix[460] += mix[333]; mix[461] += mix[334];\
	mix[462] += mix[335]; mix[463] += mix[336];\
	mix[464] += mix[337]; mix[465] += mix[338];\
	mix[466] += mix[339]; mix[467] += mix[340];\
	mix[468] += mix[341]; mix[469] += mix[342];\
	mix[470] += mix[343]; mix[471] += mix[344];\
	mix[472] += mix[345]; mix[473] += mix[346];\
	mix[474] += mix[347]; mix[475] += mix[348];\
	mix[476] += mix[349]; mix[477] += mix[350];\
	mix[478] += mix[351]; mix[479] += mix[352];\
	mix[480] += mix[353]; mix[481] += mix[354];\
	mix[482] += mix[355]; mix[483] += mix[356];\
	mix[484] += mix[357]; mix[485] += mix[358];\
	mix[486] += mix[359]; mix[487] += mix[360];\
	mix[488] += mix[361]; mix[489] += mix[362];\
	mix[490] += mix[363]; mix[491] += mix[364];\
	mix[492] += mix[365]; mix[493] += mix[366];\
	mix[494] += mix[367]; mix[495] += mix[368];\
	mix[496] += mix[369]; mix[497] += mix[370];\
	mix[498] += mix[371]; mix[499] += mix[372];\
	mix[500] += mix[373]; mix[501] += mix[374];\
	mix[502] += mix[375]; mix[503] += mix[376];\
	mix[504] += mix[377]; mix[505] += mix[378];\
	mix[506] += mix[379]; mix[507] += mix[380];\
	mix[508] += mix[381]; mix[509] += mix[382];\
	mix[510] += mix[383]; mix[511] += *mix;

uint32_t calcItem32(uint8_t* seed, uint32_t i){
	uint64_t  mix[512];
	uint32_t* seed_32 = (uint32_t*)seed;
	uint8_t*  mix8_0 = (uint8_t*)mix;
	uint8_t*  mix8_1 = (uint8_t*)&mix[2];
	uint8_t*  mix8_2 = (uint8_t*)&mix[4];
	uint8_t*  mix8_3 = (uint8_t*)&mix[6];
	uint32_t* mix32  = (uint32_t*)mix;
	uint32_t  out0   = 0; 
	uint32_t  out1   = 0; 
	const uint8_t pos     = i&0x3;
	const uint8_t pos4096 = (i&0xfff)>>2;
	const uint8_t* seed1 = &seed[16];
	ITEM_CALCULATION()
	if(pos4096<1023){
		out0 = mix32[pos4096];
		out1 = mix32[1+pos4096];
	}else{
		out0 = mix32[1023];
		if(pos){
			i++;
			ITEM_CALCULATION()
			out1 = *mix32;
		}
	}
	for(uint8_t j=0; j<  pos; j++) (out0)>>=8;
	for(uint8_t j=0; j<4-pos; j++) (out1)<<=8;
	out0 |= out1;
	return out0;
}

uint64_t calcItem64(uint8_t* seed, uint32_t i){
	uint64_t  mix[512];
	uint32_t* seed_32 = (uint32_t*)seed;
	uint8_t*  mix8_0 = (uint8_t*)mix;
	uint8_t*  mix8_1 = (uint8_t*)&mix[2];
	uint8_t*  mix8_2 = (uint8_t*)&mix[4];
	uint8_t*  mix8_3 = (uint8_t*)&mix[6];
	uint32_t* mix32  = (uint32_t*)mix;
	uint64_t  out0   = 0; 
	uint64_t  out1   = 0; 
	const uint8_t pos     = i&0x7;
	const uint8_t pos4096 = (i&0xfff)>>3;
	const uint8_t* seed1 = &seed[16];
	ITEM_CALCULATION()
	if(pos4096<511){
		out0 = mix[pos4096];
		out1 = mix[1+pos4096];
	}else{
		out0 = mix[511];
		if(pos){
			i++;
			ITEM_CALCULATION()
			out1 = *mix32;
		}
	}
	for(uint8_t j=0; j<  pos; j++) (out0)>>=8;
	for(uint8_t j=0; j<8-pos; j++) (out1)<<=8;
	out0 |= out1;
	return out0;
}

void calcDataset(uint8_t* seed, uint8_t* out){
	uint64_t  mix[512];
	uint8_t*  mix8_0   = (uint8_t*)mix;
	uint8_t*  mix8_1   = (uint8_t*)&mix[2];
	uint8_t*  mix8_2   = (uint8_t*)&mix[4];
	uint8_t*  mix8_3   = (uint8_t*)&mix[6];
	uint32_t* mix32    = (uint32_t*)mix;
	uint32_t* seed_32  = (uint32_t*)seed;
	uint32_t  max      = (ITEMS>>9);
	const uint8_t* seed1 = &seed[16];
	for(uint32_t i=0;i<max;i+=8){
	ITEM_CALCULATION()
	memcpy(out, mix, 4096);
	out+=0x1000;
	}
}
