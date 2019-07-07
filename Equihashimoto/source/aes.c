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
