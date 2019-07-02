// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "error.h"
#include "aes.h"


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

uint32_t calcItem32(uint8_t* seed, uint32_t itemNumber){
	uint64_t  mix[8] = {0};
	uint8_t*  mix8   = (uint8_t*)mix;
	uint32_t* mix32  = (uint32_t*)mix;
	uint32_t* seed_32  = (uint32_t*)seed;
	uint32_t  out0   = 0; 
	uint32_t  out1   = 0; 
	uint8_t   pos    = itemNumber&0x3;
	uint8_t   pos64  = itemNumber&0x3f;
	itemNumber&=0xffffffc0;
	itemNumber>>=2;
	*mix   = itemNumber; mix[1] = itemNumber;
	mix[2] = itemNumber; mix[3] = itemNumber;
	itemNumber>>=4;
	(*seed_32)+=itemNumber; seed_32[1]+=itemNumber;
	seed_32[2]+=itemNumber; seed_32[3]+=itemNumber;
	seed_32[4]+=itemNumber; seed_32[5]+=itemNumber;
	seed_32[6]+=itemNumber; seed_32[7]+=itemNumber;
	itemNumber<<=4;
	if(!pos){
		aes(mix8, &seed[pos64&0x10]);
		uint8_t pos64_4 = pos64>>2;
		if(pos64>31){
			aes(&mix8[16], mix8);
			out0 = mix32[16+(pos64_4&0xf)];
		} else{
			out0 = mix32[pos64_4&0xf];
		}
	}else{
		if(pos64<29){
			if(pos64<13){
				uint8_t pos64_4 = pos64>>2;
				aes(mix8, seed);
				out0 = mix32[pos64_4  ];
				out1 = mix32[pos64_4+1];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			}else if(pos64>15){	
				uint8_t pos64_4 = pos64>>2;	
				aes(&mix8[16], &seed[16]); 
				out0 = mix32[pos64_4  ];
				out1 = mix32[pos64_4+1];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			}else{
				aes(mix8, seed); aes(&mix8[16], &seed[16]); 
				out0 = mix32[3];
				out1 = mix32[4];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;

			}
		}else if(pos64<45){
			mix[4] = itemNumber; mix[5] = itemNumber;
			aes(mix8, seed);
			aes(&mix8[32], mix8);
			if(pos64<32){
				aes(&mix8[16], &seed[16]); 
				out0 = mix32[7];
				out1 = mix32[8];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			}else{
				uint8_t pos64_4 = pos64>>2;
				out0 = mix32[pos64_4  ];
				out1 = mix32[pos64_4+1];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			}
		}else if(pos64<61){
			mix[4] = itemNumber; mix[5] = itemNumber;
			mix[6] = itemNumber; mix[7] = itemNumber;
			aes(&mix8[16], &seed[16]); aes(&mix8[48], &mix8[16]);
			if(pos64<48){
				aes(mix8, seed); aes(&mix8[32], mix8); 
				out0 = mix32[11];
				out1 = mix32[12];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			}else{
				uint8_t pos64_4 = pos64>>2;
				out0 = mix32[pos64_4  ];
				out1 = mix32[pos64_4+1];
				for(uint8_t i=0; i<  pos; i++) out0>>=8;
				for(uint8_t i=0; i<4-pos; i++) out1<<=8;
			}
		}else{
			mix[4] = itemNumber; mix[5] = itemNumber;
			mix[4]+=16; mix[5]+=16;
			aes(mix8, &seed[16]); aes(&mix8[16], &mix8[16]);
			(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
			aes(&mix8[32], seed);
			out0 = mix32[7];
			out1 = mix32[8];
			for(uint8_t i=0; i<  pos; i++) out0>>=8;
			for(uint8_t i=0; i<4-pos; i++) out1<<=8;
		}
		out0 |= out1;
	}
	return out0;
}

void calcDatasetItem8(uint8_t* seed, uint32_t itemNumber, uint64_t* out){
	uint64_t  mix[128] = {0};
	uint8_t*  mix8     = (uint8_t*)mix;
	uint32_t* seed_32  = (uint32_t*)seed;
	*mix     = itemNumber; mix[  2] = itemNumber; mix[  4] = itemNumber; mix[  6] = itemNumber;
	mix[  8] = itemNumber; mix[ 10] = itemNumber; mix[ 12] = itemNumber; mix[ 14] = itemNumber;
	mix[ 16] = itemNumber; mix[ 18] = itemNumber; mix[ 20] = itemNumber; mix[ 22] = itemNumber;
	mix[ 24] = itemNumber; mix[ 26] = itemNumber; mix[ 28] = itemNumber; mix[ 30] = itemNumber;
	mix[ 32] = itemNumber; mix[ 34] = itemNumber; mix[ 36] = itemNumber; mix[ 38] = itemNumber;
	mix[ 40] = itemNumber; mix[ 42] = itemNumber; mix[ 44] = itemNumber; mix[ 46] = itemNumber;
	mix[ 48] = itemNumber; mix[ 50] = itemNumber; mix[ 52] = itemNumber; mix[ 54] = itemNumber;
	mix[ 56] = itemNumber; mix[ 58] = itemNumber; mix[ 60] = itemNumber; mix[ 62] = itemNumber;
	mix[ 64] = itemNumber; mix[ 66] = itemNumber; mix[ 68] = itemNumber; mix[ 70] = itemNumber;
	mix[ 72] = itemNumber; mix[ 74] = itemNumber; mix[ 76] = itemNumber; mix[ 78] = itemNumber;
	mix[ 80] = itemNumber; mix[ 82] = itemNumber; mix[ 84] = itemNumber; mix[ 86] = itemNumber;
	mix[ 88] = itemNumber; mix[ 90] = itemNumber; mix[ 92] = itemNumber; mix[ 94] = itemNumber;
	mix[ 96] = itemNumber; mix[ 98] = itemNumber; mix[100] = itemNumber; mix[102] = itemNumber;
	mix[104] = itemNumber; mix[106] = itemNumber; mix[108] = itemNumber; mix[110] = itemNumber;
	mix[112] = itemNumber; mix[114] = itemNumber; mix[116] = itemNumber; mix[118] = itemNumber;
	mix[120] = itemNumber; mix[122] = itemNumber; mix[124] = itemNumber; mix[126] = itemNumber;
	mix[ 16]+=16; mix[ 18]+=16; mix[ 20]+=16; mix[ 22]+=16;
	mix[ 24]+=16; mix[ 26]+=16; mix[ 28]+=16; mix[ 30]+=16;
	mix[ 32]+=32; mix[ 34]+=32; mix[ 36]+=32; mix[ 38]+=32;
	mix[ 40]+=32; mix[ 42]+=32; mix[ 44]+=32; mix[ 46]+=32;
	mix[ 48]+=48; mix[ 50]+=48; mix[ 52]+=48; mix[ 54]+=48;
	mix[ 56]+=48; mix[ 58]+=48; mix[ 60]+=48; mix[ 62]+=48;
	mix[ 64]+=64; mix[ 66]+=64; mix[ 68]+=64; mix[ 70]+=64;
	mix[ 72]+=64; mix[ 74]+=64; mix[ 76]+=64; mix[ 78]+=64;
	mix[ 80]+=80; mix[ 82]+=80; mix[ 84]+=80; mix[ 86]+=80;
	mix[ 88]+=80; mix[ 90]+=80; mix[ 92]+=80; mix[ 94]+=80;
	mix[ 96]+=96; mix[ 96]+=96; mix[ 98]+=96; mix[100]+=96;
	mix[104]+=96; mix[106]+=96; mix[108]+=96; mix[110]+=96;
	mix[112]+=112; mix[114]+=112; mix[116]+=112; mix[118]+=112;
	mix[120]+=112; mix[122]+=112; mix[124]+=112; mix[126]+=112;
	aes(mix8,        seed       ); aes(&mix8[  16], &seed[  16]);
	aes(&mix8[  32], mix8       ); aes(&mix8[  48], &mix8[  16]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[  64], seed       ); aes(&mix8[  80], &seed[  16]);
	aes(&mix8[  96], &mix8[  64]); aes(&mix8[ 112], &mix8[  80]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 128], seed       ); aes(&mix8[ 144], &seed[  16]);
	aes(&mix8[ 160], &mix8[ 128]); aes(&mix8[ 176], &mix8[ 144]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 192], seed       ); aes(&mix8[ 208], &seed[  16]);
	aes(&mix8[ 224], &mix8[ 192]); aes(&mix8[ 240], &mix8[ 208]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 256], seed       ); aes(&mix8[ 272], &seed[  16]);
	aes(&mix8[ 288], &mix8[ 256]); aes(&mix8[ 304], &mix8[ 272]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 320], seed       ); aes(&mix8[ 336], &seed[  16]);
	aes(&mix8[ 352], &mix8[ 320]); aes(&mix8[ 368], &mix8[ 336]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 384], seed       ); aes(&mix8[ 400], &seed[  16]);
	aes(&mix8[ 416], &mix8[ 384]); aes(&mix8[ 432], &mix8[ 400]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 448], seed       ); aes(&mix8[ 464], &seed[  16]);
	aes(&mix8[ 480], &mix8[ 448]); aes(&mix8[ 496], &mix8[ 464]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 512], seed       ); aes(&mix8[ 528], &seed[  16]);
	aes(&mix8[ 544], &mix8[ 512]); aes(&mix8[ 560], &mix8[ 528]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 576], seed       ); aes(&mix8[ 592], &seed[  16]);
	aes(&mix8[ 608], &mix8[ 576]); aes(&mix8[ 624], &mix8[ 592]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 640], seed       ); aes(&mix8[ 656], &seed[  16]);
	aes(&mix8[ 672], &mix8[ 640]); aes(&mix8[ 688], &mix8[ 656]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 704], seed       ); aes(&mix8[ 720], &seed[  16]);
	aes(&mix8[ 736], &mix8[ 704]); aes(&mix8[ 752], &mix8[ 720]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 768], seed       ); aes(&mix8[ 784], &seed[  16]);
	aes(&mix8[ 800], &mix8[ 768]); aes(&mix8[ 816], &mix8[ 784]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 832], seed       ); aes(&mix8[ 848], &seed[  16]);
	aes(&mix8[ 864], &mix8[ 832]); aes(&mix8[ 880], &mix8[ 848]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 896], seed       ); aes(&mix8[ 912], &seed[  16]);
	aes(&mix8[ 928], &mix8[ 896]); aes(&mix8[ 944], &mix8[ 912]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	aes(&mix8[ 960], seed       ); aes(&mix8[ 976], &seed[  16]);
	aes(&mix8[ 992], &mix8[ 960]); aes(&mix8[1008], &mix8[ 976]);
	(*seed_32)++; seed_32[1]++; seed_32[2]++; seed_32[3]++;
	seed_32[4]++; seed_32[5]++; seed_32[6]++; seed_32[7]++;
	memcpy(out, mix, 1024);
}

void calcDataset(uint8_t* seed, uint64_t* out){
	for(uint32_t i=0;i<536870912;i+=128) // (1<<32)>>3
		calcDatasetItem8(seed, i, &out[i]);
	
}
