#include <stdio.h>
#include <emmintrin.h>
#include <stdint.h>
#include <math.h>

#ifndef _mm_set_epi64x
	#define _mm_set_epi64x(m0, m1) _mm_set_epi64(_m_from_int64(m0), _m_from_int64(m1))
#endif


static const unsigned int crc32_table[] =
{
  0x00000000, 0x04c11db7, 0x09823b6e, 0x0d4326d9,
  0x130476dc, 0x17c56b6b, 0x1a864db2, 0x1e475005,
  0x2608edb8, 0x22c9f00f, 0x2f8ad6d6, 0x2b4bcb61,
  0x350c9b64, 0x31cd86d3, 0x3c8ea00a, 0x384fbdbd,
  0x4c11db70, 0x48d0c6c7, 0x4593e01e, 0x4152fda9,
  0x5f15adac, 0x5bd4b01b, 0x569796c2, 0x52568b75,
  0x6a1936c8, 0x6ed82b7f, 0x639b0da6, 0x675a1011,
  0x791d4014, 0x7ddc5da3, 0x709f7b7a, 0x745e66cd,
  0x9823b6e0, 0x9ce2ab57, 0x91a18d8e, 0x95609039,
  0x8b27c03c, 0x8fe6dd8b, 0x82a5fb52, 0x8664e6e5,
  0xbe2b5b58, 0xbaea46ef, 0xb7a96036, 0xb3687d81,
  0xad2f2d84, 0xa9ee3033, 0xa4ad16ea, 0xa06c0b5d,
  0xd4326d90, 0xd0f37027, 0xddb056fe, 0xd9714b49,
  0xc7361b4c, 0xc3f706fb, 0xceb42022, 0xca753d95,
  0xf23a8028, 0xf6fb9d9f, 0xfbb8bb46, 0xff79a6f1,
  0xe13ef6f4, 0xe5ffeb43, 0xe8bccd9a, 0xec7dd02d,
  0x34867077, 0x30476dc0, 0x3d044b19, 0x39c556ae,
  0x278206ab, 0x23431b1c, 0x2e003dc5, 0x2ac12072,
  0x128e9dcf, 0x164f8078, 0x1b0ca6a1, 0x1fcdbb16,
  0x018aeb13, 0x054bf6a4, 0x0808d07d, 0x0cc9cdca,
  0x7897ab07, 0x7c56b6b0, 0x71159069, 0x75d48dde,
  0x6b93dddb, 0x6f52c06c, 0x6211e6b5, 0x66d0fb02,
  0x5e9f46bf, 0x5a5e5b08, 0x571d7dd1, 0x53dc6066,
  0x4d9b3063, 0x495a2dd4, 0x44190b0d, 0x40d816ba,
  0xaca5c697, 0xa864db20, 0xa527fdf9, 0xa1e6e04e,
  0xbfa1b04b, 0xbb60adfc, 0xb6238b25, 0xb2e29692,
  0x8aad2b2f, 0x8e6c3698, 0x832f1041, 0x87ee0df6,
  0x99a95df3, 0x9d684044, 0x902b669d, 0x94ea7b2a,
  0xe0b41de7, 0xe4750050, 0xe9362689, 0xedf73b3e,
  0xf3b06b3b, 0xf771768c, 0xfa325055, 0xfef34de2,
  0xc6bcf05f, 0xc27dede8, 0xcf3ecb31, 0xcbffd686,
  0xd5b88683, 0xd1799b34, 0xdc3abded, 0xd8fba05a,
  0x690ce0ee, 0x6dcdfd59, 0x608edb80, 0x644fc637,
  0x7a089632, 0x7ec98b85, 0x738aad5c, 0x774bb0eb,
  0x4f040d56, 0x4bc510e1, 0x46863638, 0x42472b8f,
  0x5c007b8a, 0x58c1663d, 0x558240e4, 0x51435d53,
  0x251d3b9e, 0x21dc2629, 0x2c9f00f0, 0x285e1d47,
  0x36194d42, 0x32d850f5, 0x3f9b762c, 0x3b5a6b9b,
  0x0315d626, 0x07d4cb91, 0x0a97ed48, 0x0e56f0ff,
  0x1011a0fa, 0x14d0bd4d, 0x19939b94, 0x1d528623,
  0xf12f560e, 0xf5ee4bb9, 0xf8ad6d60, 0xfc6c70d7,
  0xe22b20d2, 0xe6ea3d65, 0xeba91bbc, 0xef68060b,
  0xd727bbb6, 0xd3e6a601, 0xdea580d8, 0xda649d6f,
  0xc423cd6a, 0xc0e2d0dd, 0xcda1f604, 0xc960ebb3,
  0xbd3e8d7e, 0xb9ff90c9, 0xb4bcb610, 0xb07daba7,
  0xae3afba2, 0xaafbe615, 0xa7b8c0cc, 0xa379dd7b,
  0x9b3660c6, 0x9ff77d71, 0x92b45ba8, 0x9675461f,
  0x8832161a, 0x8cf30bad, 0x81b02d74, 0x857130c3,
  0x5d8a9099, 0x594b8d2e, 0x5408abf7, 0x50c9b640,
  0x4e8ee645, 0x4a4ffbf2, 0x470cdd2b, 0x43cdc09c,
  0x7b827d21, 0x7f436096, 0x7200464f, 0x76c15bf8,
  0x68860bfd, 0x6c47164a, 0x61043093, 0x65c52d24,
  0x119b4be9, 0x155a565e, 0x18197087, 0x1cd86d30,
  0x029f3d35, 0x065e2082, 0x0b1d065b, 0x0fdc1bec,
  0x3793a651, 0x3352bbe6, 0x3e119d3f, 0x3ad08088,
  0x2497d08d, 0x2056cd3a, 0x2d15ebe3, 0x29d4f654,
  0xc5a92679, 0xc1683bce, 0xcc2b1d17, 0xc8ea00a0,
  0xd6ad50a5, 0xd26c4d12, 0xdf2f6bcb, 0xdbee767c,
  0xe3a1cbc1, 0xe760d676, 0xea23f0af, 0xeee2ed18,
  0xf0a5bd1d, 0xf464a0aa, 0xf9278673, 0xfde69bc4,
  0x89b8fd09, 0x8d79e0be, 0x803ac667, 0x84fbdbd0,
  0x9abc8bd5, 0x9e7d9662, 0x933eb0bb, 0x97ffad0c,
  0xafb010b1, 0xab710d06, 0xa6322bdf, 0xa2f33668,
  0xbcb4666d, 0xb8757bda, 0xb5365d03, 0xb1f740b4
};

// Only one round of AES, looking at CryptoNight
// and other hashes, it can be considered
// secure "enough".
__asm__ __volatile__(
	".globl AES_CBC_encrypt\n"
	"AES_CBC_encrypt:\n"
	"# parameter 1: %rdi\n"
	"# parameter 2: %rsi\n"
	"# parameter 3: %rdx\n"
	"# parameter 4: %rcx\n"
	"# parameter 5: %r8\n"
	"# parameter 6: %r9d\n"
	"movq	%rcx, %r10\n"
	"shrq	$4, %rcx\n"
	"shlq	$60, %r10\n"
	"je	NO_PARTS\n"
	"addq	$1, %rcx\n"
	"NO_PARTS:\n"
	"subq	$16, %rsi\n"
	"movdqa	(%rdx), %xmm1\n"
	"LOOP:\n"
	"pxor	(%rdi), %xmm1\n"
	"pxor	(%r8), %xmm1\n"
	"addq	$16,%rsi\n"
	"addq	$16,%rdi\n"
	"aesenc	16(%r8),%xmm1\n"
	"aesenc	32(%r8),%xmm1\n"
	"aesenc	48(%r8),%xmm1\n"
	"aesenc	64(%r8),%xmm1\n"
	"aesenc	80(%r8),%xmm1\n"
	"aesenc	96(%r8),%xmm1\n"
	"aesenc	112(%r8),%xmm1\n"
	"aesenc	128(%r8),%xmm1\n"
	"aesenc	144(%r8),%xmm1\n"
	"movdqa	160(%r8),%xmm2\n"
	"jmp	LAST\n"
	"\n"
	"LAST:\n"
	"decq	%rcx\n"
	"aesenclast %xmm2,%xmm1\n"
	"movdqu	%xmm1,(%rsi)\n"
	"jne	LOOP\n"
	"ret"
);

uint32_t crc32(const unsigned char* buf){
	unsigned int crc = 0xFFFFFFFF;
	for(uint8_t i=0; i<4;i++){
		crc = (crc << 8) ^ crc32_table[((crc >> 24) ^ *buf) & 255];
		buf++;
	}
	return crc;
}


void ror128(__m128i in, __m128i* out, uint16_t n){
	uint8_t shift = n&0x3f;
        __m128i v0 = _mm_slli_epi64(in, shift);
        __m128i v1 = _mm_slli_si128(in, 8);
        v1 = _mm_srli_epi64(v1, 64-shift);
        v1 = _mm_or_si128(v0, v1);
        v0 = _mm_slli_si128(in, 8);
	__m128i v2 = _mm_slli_epi64(v0, shift^64);
	*out = _mm_or_si128(v1,v2);
	return;
}
void rol128(__m128i in, __m128i* out, uint16_t n){
	uint8_t shift = n&0x3f;
        __m128i v0 = _mm_srli_epi64(in, shift);
        __m128i v1 = _mm_srli_si128(in, 8);
        v1 = _mm_slli_epi64(v1, 64-shift);
        v1 = _mm_or_si128(v0, v1);
        v0 = _mm_srli_si128(in, 8);
	__m128i v2 = _mm_srli_epi64(v0, shift^64);
	*out = _mm_or_si128(v1,v2);
	return;
}
inline void AES_CBC_encrypt(const unsigned char* in, unsigned char* out,
							 unsigned char* ivec, unsigned long length,
							 const unsigned char* KS/*, int nr*/){
		XASM_LINK("AES_CBC_encrypt");}

void hash(uint8_t* data, uint8_t* scratchpad, uint8_t* out){
	uint16_t  crc_16[16] =	{0};
	uint32_t* crc_32 = (uint32_t*)crc_16;
	uint64_t* crc_64 = (uint64_t*)crc_16;
	uint64_t* data_64 = (uint64_t*)data;
	__m128i iv = _mm_set_epi64x(0,0);
	__m128i key = _mm_set_epi64x(0,0);

	crc_32[0] = crc32(data);
	crc_32[1] = crc32(&data[4]);

	crc_32[2] = (uint32_t)scratchpad[crc_16[0]];
	crc_32[3] = (uint32_t)scratchpad[crc_16[2]];
	crc_64[1] ^= data_64[1];
	crc_64[2] = (crc_64[1] + data_64[2]) ^ (crc_64[1] / data_64[2]);
	crc_64[3] = data_64[3];

	ror128(_mm_set_epi64x(crc_64[0],crc_64[1]),&iv,crc_16[15]);
	rol128(_mm_set_epi64x(crc_64[2],crc_64[3]),&key,crc_16[0 ]);
	AES_CBC_encrypt((const unsigned char*)crc_16, (unsigned char*)out, (unsigned char*)&iv, 32, (const unsigned char*)&key);
	return;
}


int main(){
	uint64_t iterations = (uint64_t)pow(2.0,34);
	uint8_t data[32] = {[0 ... 31] = 6};
	uint8_t scratchpad[65536] = {[0 ... 65535] = 5};
	uint8_t out[32] = {[0 ... 31] = 6};
	for(uint64_t i=0; i<iterations;i++) hash(out, scratchpad, out);
	printf("%x,%x,%x,%x,%x,%x,%x,%x",((uint32_t*)out)[0],((uint32_t*)out)[1],((uint32_t*)out)[2],((uint32_t*)out)[3],((uint32_t*)out)[4],((uint32_t*)out)[5],((uint32_t*)out)[6],((uint32_t*)out)[7]);
}
