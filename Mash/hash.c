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
#if MEMORY_THREADS > 1
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[16] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[17] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[18] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[19] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[20] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[21] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[22] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[23] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[16] = *((uint64_t*)&dataset[hash_32[32]]);
	hash_64[17] = *((uint64_t*)&dataset[hash_32[33]]);
	hash_64[18] = *((uint64_t*)&dataset[hash_32[34]]);
	hash_64[19] = *((uint64_t*)&dataset[hash_32[35]]);
	hash_64[20] = *((uint64_t*)&dataset[hash_32[36]]);
	hash_64[21] = *((uint64_t*)&dataset[hash_32[37]]);
	hash_64[22] = *((uint64_t*)&dataset[hash_32[38]]);
	hash_64[23] = *((uint64_t*)&dataset[hash_32[39]]);
	hash_64[24] = *((uint64_t*)&dataset[hash_32[40]]);
	hash_64[25] = *((uint64_t*)&dataset[hash_32[41]]);
	hash_64[26] = *((uint64_t*)&dataset[hash_32[42]]);
	hash_64[27] = *((uint64_t*)&dataset[hash_32[43]]);
	hash_64[28] = *((uint64_t*)&dataset[hash_32[44]]);
	hash_64[29] = *((uint64_t*)&dataset[hash_32[45]]);
	hash_64[30] = *((uint64_t*)&dataset[hash_32[46]]);
	hash_64[31] = *((uint64_t*)&dataset[hash_32[47]]);
#endif
#if MEMORY_THREADS > 2
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[32] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[33] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[34] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[35] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[36] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[37] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[38] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[39] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[32] = *((uint64_t*)&dataset[hash_32[64]]);
	hash_64[33] = *((uint64_t*)&dataset[hash_32[65]]);
	hash_64[34] = *((uint64_t*)&dataset[hash_32[66]]);
	hash_64[35] = *((uint64_t*)&dataset[hash_32[67]]);
	hash_64[36] = *((uint64_t*)&dataset[hash_32[68]]);
	hash_64[37] = *((uint64_t*)&dataset[hash_32[69]]);
	hash_64[38] = *((uint64_t*)&dataset[hash_32[70]]);
	hash_64[39] = *((uint64_t*)&dataset[hash_32[71]]);
	hash_64[40] = *((uint64_t*)&dataset[hash_32[72]]);
	hash_64[41] = *((uint64_t*)&dataset[hash_32[73]]);
	hash_64[42] = *((uint64_t*)&dataset[hash_32[74]]);
	hash_64[43] = *((uint64_t*)&dataset[hash_32[75]]);
	hash_64[44] = *((uint64_t*)&dataset[hash_32[76]]);
	hash_64[45] = *((uint64_t*)&dataset[hash_32[77]]);
	hash_64[46] = *((uint64_t*)&dataset[hash_32[78]]);
	hash_64[47] = *((uint64_t*)&dataset[hash_32[79]]);
#endif
#if MEMORY_THREADS > 3
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[48] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[49] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[50] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[51] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[52] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[53] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[54] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[55] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[48] = *((uint64_t*)&dataset[hash_32[96]]);
	hash_64[49] = *((uint64_t*)&dataset[hash_32[97]]);
	hash_64[50] = *((uint64_t*)&dataset[hash_32[98]]);
	hash_64[51] = *((uint64_t*)&dataset[hash_32[99]]);
	hash_64[52] = *((uint64_t*)&dataset[hash_32[100]]);
	hash_64[53] = *((uint64_t*)&dataset[hash_32[101]]);
	hash_64[54] = *((uint64_t*)&dataset[hash_32[102]]);
	hash_64[55] = *((uint64_t*)&dataset[hash_32[103]]);
	hash_64[56] = *((uint64_t*)&dataset[hash_32[104]]);
	hash_64[57] = *((uint64_t*)&dataset[hash_32[105]]);
	hash_64[58] = *((uint64_t*)&dataset[hash_32[106]]);
	hash_64[59] = *((uint64_t*)&dataset[hash_32[107]]);
	hash_64[60] = *((uint64_t*)&dataset[hash_32[108]]);
	hash_64[61] = *((uint64_t*)&dataset[hash_32[109]]);
	hash_64[62] = *((uint64_t*)&dataset[hash_32[110]]);
	hash_64[63] = *((uint64_t*)&dataset[hash_32[111]]);
#endif
#if MEMORY_THREADS > 4
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[64] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[65] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[66] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[67] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[68] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[69] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[70] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[71] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[64] = *((uint64_t*)&dataset[hash_32[128]]);
	hash_64[65] = *((uint64_t*)&dataset[hash_32[129]]);
	hash_64[66] = *((uint64_t*)&dataset[hash_32[130]]);
	hash_64[67] = *((uint64_t*)&dataset[hash_32[131]]);
	hash_64[68] = *((uint64_t*)&dataset[hash_32[132]]);
	hash_64[69] = *((uint64_t*)&dataset[hash_32[133]]);
	hash_64[70] = *((uint64_t*)&dataset[hash_32[134]]);
	hash_64[71] = *((uint64_t*)&dataset[hash_32[135]]);
	hash_64[72] = *((uint64_t*)&dataset[hash_32[136]]);
	hash_64[73] = *((uint64_t*)&dataset[hash_32[137]]);
	hash_64[74] = *((uint64_t*)&dataset[hash_32[138]]);
	hash_64[75] = *((uint64_t*)&dataset[hash_32[139]]);
	hash_64[76] = *((uint64_t*)&dataset[hash_32[140]]);
	hash_64[77] = *((uint64_t*)&dataset[hash_32[141]]);
	hash_64[78] = *((uint64_t*)&dataset[hash_32[142]]);
	hash_64[79] = *((uint64_t*)&dataset[hash_32[143]]);
#endif
#if MEMORY_THREADS > 5
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[80] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[81] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[82] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[83] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[84] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[85] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[86] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[87] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[80] = *((uint64_t*)&dataset[hash_32[160]]);
	hash_64[81] = *((uint64_t*)&dataset[hash_32[161]]);
	hash_64[82] = *((uint64_t*)&dataset[hash_32[162]]);
	hash_64[83] = *((uint64_t*)&dataset[hash_32[163]]);
	hash_64[84] = *((uint64_t*)&dataset[hash_32[164]]);
	hash_64[85] = *((uint64_t*)&dataset[hash_32[165]]);
	hash_64[86] = *((uint64_t*)&dataset[hash_32[166]]);
	hash_64[87] = *((uint64_t*)&dataset[hash_32[167]]);
	hash_64[88] = *((uint64_t*)&dataset[hash_32[168]]);
	hash_64[89] = *((uint64_t*)&dataset[hash_32[169]]);
	hash_64[90] = *((uint64_t*)&dataset[hash_32[170]]);
	hash_64[91] = *((uint64_t*)&dataset[hash_32[171]]);
	hash_64[92] = *((uint64_t*)&dataset[hash_32[172]]);
	hash_64[93] = *((uint64_t*)&dataset[hash_32[173]]);
	hash_64[94] = *((uint64_t*)&dataset[hash_32[174]]);
	hash_64[95] = *((uint64_t*)&dataset[hash_32[175]]);
#endif
#if MEMORY_THREADS > 6
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[96] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[97] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[98] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[99] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[100] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[101] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[102] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[103] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[96] = *((uint64_t*)&dataset[hash_32[192]]);
	hash_64[97] = *((uint64_t*)&dataset[hash_32[193]]);
	hash_64[98] = *((uint64_t*)&dataset[hash_32[194]]);
	hash_64[99] = *((uint64_t*)&dataset[hash_32[195]]);
	hash_64[100] = *((uint64_t*)&dataset[hash_32[196]]);
	hash_64[101] = *((uint64_t*)&dataset[hash_32[197]]);
	hash_64[102] = *((uint64_t*)&dataset[hash_32[198]]);
	hash_64[103] = *((uint64_t*)&dataset[hash_32[199]]);
	hash_64[104] = *((uint64_t*)&dataset[hash_32[200]]);
	hash_64[105] = *((uint64_t*)&dataset[hash_32[201]]);
	hash_64[106] = *((uint64_t*)&dataset[hash_32[202]]);
	hash_64[107] = *((uint64_t*)&dataset[hash_32[203]]);
	hash_64[108] = *((uint64_t*)&dataset[hash_32[204]]);
	hash_64[109] = *((uint64_t*)&dataset[hash_32[205]]);
	hash_64[110] = *((uint64_t*)&dataset[hash_32[206]]);
	hash_64[111] = *((uint64_t*)&dataset[hash_32[207]]);
#endif
#if MEMORY_THREADS > 7
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[112] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[113] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[114] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[115] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[116] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[117] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[118] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[119] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[112] = *((uint64_t*)&dataset[hash_32[224]]);
	hash_64[113] = *((uint64_t*)&dataset[hash_32[225]]);
	hash_64[114] = *((uint64_t*)&dataset[hash_32[226]]);
	hash_64[115] = *((uint64_t*)&dataset[hash_32[227]]);
	hash_64[116] = *((uint64_t*)&dataset[hash_32[228]]);
	hash_64[117] = *((uint64_t*)&dataset[hash_32[229]]);
	hash_64[118] = *((uint64_t*)&dataset[hash_32[230]]);
	hash_64[119] = *((uint64_t*)&dataset[hash_32[231]]);
	hash_64[120] = *((uint64_t*)&dataset[hash_32[232]]);
	hash_64[121] = *((uint64_t*)&dataset[hash_32[233]]);
	hash_64[122] = *((uint64_t*)&dataset[hash_32[234]]);
	hash_64[123] = *((uint64_t*)&dataset[hash_32[235]]);
	hash_64[124] = *((uint64_t*)&dataset[hash_32[236]]);
	hash_64[125] = *((uint64_t*)&dataset[hash_32[237]]);
	hash_64[126] = *((uint64_t*)&dataset[hash_32[238]]);
	hash_64[127] = *((uint64_t*)&dataset[hash_32[239]]);
#endif
#if MEMORY_THREADS > 8
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[128] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[129] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[130] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[131] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[132] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[133] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[134] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[135] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[128] = *((uint64_t*)&dataset[hash_32[256]]);
	hash_64[129] = *((uint64_t*)&dataset[hash_32[257]]);
	hash_64[130] = *((uint64_t*)&dataset[hash_32[258]]);
	hash_64[131] = *((uint64_t*)&dataset[hash_32[259]]);
	hash_64[132] = *((uint64_t*)&dataset[hash_32[260]]);
	hash_64[133] = *((uint64_t*)&dataset[hash_32[261]]);
	hash_64[134] = *((uint64_t*)&dataset[hash_32[262]]);
	hash_64[135] = *((uint64_t*)&dataset[hash_32[263]]);
	hash_64[136] = *((uint64_t*)&dataset[hash_32[264]]);
	hash_64[137] = *((uint64_t*)&dataset[hash_32[265]]);
	hash_64[138] = *((uint64_t*)&dataset[hash_32[266]]);
	hash_64[139] = *((uint64_t*)&dataset[hash_32[267]]);
	hash_64[140] = *((uint64_t*)&dataset[hash_32[268]]);
	hash_64[141] = *((uint64_t*)&dataset[hash_32[269]]);
	hash_64[142] = *((uint64_t*)&dataset[hash_32[270]]);
	hash_64[143] = *((uint64_t*)&dataset[hash_32[271]]);
#endif
#if MEMORY_THREADS > 9
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[144] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[145] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[146] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[147] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[148] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[149] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[150] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[151] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[144] = *((uint64_t*)&dataset[hash_32[288]]);
	hash_64[145] = *((uint64_t*)&dataset[hash_32[289]]);
	hash_64[146] = *((uint64_t*)&dataset[hash_32[290]]);
	hash_64[147] = *((uint64_t*)&dataset[hash_32[291]]);
	hash_64[148] = *((uint64_t*)&dataset[hash_32[292]]);
	hash_64[149] = *((uint64_t*)&dataset[hash_32[293]]);
	hash_64[150] = *((uint64_t*)&dataset[hash_32[294]]);
	hash_64[151] = *((uint64_t*)&dataset[hash_32[295]]);
	hash_64[152] = *((uint64_t*)&dataset[hash_32[296]]);
	hash_64[153] = *((uint64_t*)&dataset[hash_32[297]]);
	hash_64[154] = *((uint64_t*)&dataset[hash_32[298]]);
	hash_64[155] = *((uint64_t*)&dataset[hash_32[299]]);
	hash_64[156] = *((uint64_t*)&dataset[hash_32[300]]);
	hash_64[157] = *((uint64_t*)&dataset[hash_32[301]]);
	hash_64[158] = *((uint64_t*)&dataset[hash_32[302]]);
	hash_64[159] = *((uint64_t*)&dataset[hash_32[303]]);
#endif
#if MEMORY_THREADS > 10
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[160] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[161] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[162] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[163] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[164] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[165] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[166] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[167] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[160] = *((uint64_t*)&dataset[hash_32[320]]);
	hash_64[161] = *((uint64_t*)&dataset[hash_32[321]]);
	hash_64[162] = *((uint64_t*)&dataset[hash_32[322]]);
	hash_64[163] = *((uint64_t*)&dataset[hash_32[323]]);
	hash_64[164] = *((uint64_t*)&dataset[hash_32[324]]);
	hash_64[165] = *((uint64_t*)&dataset[hash_32[325]]);
	hash_64[166] = *((uint64_t*)&dataset[hash_32[326]]);
	hash_64[167] = *((uint64_t*)&dataset[hash_32[327]]);
	hash_64[168] = *((uint64_t*)&dataset[hash_32[328]]);
	hash_64[169] = *((uint64_t*)&dataset[hash_32[329]]);
	hash_64[170] = *((uint64_t*)&dataset[hash_32[330]]);
	hash_64[171] = *((uint64_t*)&dataset[hash_32[331]]);
	hash_64[172] = *((uint64_t*)&dataset[hash_32[332]]);
	hash_64[173] = *((uint64_t*)&dataset[hash_32[333]]);
	hash_64[174] = *((uint64_t*)&dataset[hash_32[334]]);
	hash_64[175] = *((uint64_t*)&dataset[hash_32[335]]);
#endif
#if MEMORY_THREADS > 11
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[176] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[177] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[178] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[179] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[180] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[181] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[182] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[183] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[176] = *((uint64_t*)&dataset[hash_32[352]]);
	hash_64[177] = *((uint64_t*)&dataset[hash_32[353]]);
	hash_64[178] = *((uint64_t*)&dataset[hash_32[354]]);
	hash_64[179] = *((uint64_t*)&dataset[hash_32[355]]);
	hash_64[180] = *((uint64_t*)&dataset[hash_32[356]]);
	hash_64[181] = *((uint64_t*)&dataset[hash_32[357]]);
	hash_64[182] = *((uint64_t*)&dataset[hash_32[358]]);
	hash_64[183] = *((uint64_t*)&dataset[hash_32[359]]);
	hash_64[184] = *((uint64_t*)&dataset[hash_32[360]]);
	hash_64[185] = *((uint64_t*)&dataset[hash_32[361]]);
	hash_64[186] = *((uint64_t*)&dataset[hash_32[362]]);
	hash_64[187] = *((uint64_t*)&dataset[hash_32[363]]);
	hash_64[188] = *((uint64_t*)&dataset[hash_32[364]]);
	hash_64[189] = *((uint64_t*)&dataset[hash_32[365]]);
	hash_64[190] = *((uint64_t*)&dataset[hash_32[366]]);
	hash_64[191] = *((uint64_t*)&dataset[hash_32[367]]);
#endif
#if MEMORY_THREADS > 12
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[192] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[193] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[194] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[195] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[196] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[197] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[198] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[199] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[192] = *((uint64_t*)&dataset[hash_32[384]]);
	hash_64[193] = *((uint64_t*)&dataset[hash_32[385]]);
	hash_64[194] = *((uint64_t*)&dataset[hash_32[386]]);
	hash_64[195] = *((uint64_t*)&dataset[hash_32[387]]);
	hash_64[196] = *((uint64_t*)&dataset[hash_32[388]]);
	hash_64[197] = *((uint64_t*)&dataset[hash_32[389]]);
	hash_64[198] = *((uint64_t*)&dataset[hash_32[390]]);
	hash_64[199] = *((uint64_t*)&dataset[hash_32[391]]);
	hash_64[200] = *((uint64_t*)&dataset[hash_32[392]]);
	hash_64[201] = *((uint64_t*)&dataset[hash_32[393]]);
	hash_64[202] = *((uint64_t*)&dataset[hash_32[394]]);
	hash_64[203] = *((uint64_t*)&dataset[hash_32[395]]);
	hash_64[204] = *((uint64_t*)&dataset[hash_32[396]]);
	hash_64[205] = *((uint64_t*)&dataset[hash_32[397]]);
	hash_64[206] = *((uint64_t*)&dataset[hash_32[398]]);
	hash_64[207] = *((uint64_t*)&dataset[hash_32[399]]);
#endif
#if MEMORY_THREADS > 13
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[208] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[209] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[210] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[211] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[212] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[213] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[214] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[215] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[208] = *((uint64_t*)&dataset[hash_32[416]]);
	hash_64[209] = *((uint64_t*)&dataset[hash_32[417]]);
	hash_64[210] = *((uint64_t*)&dataset[hash_32[418]]);
	hash_64[211] = *((uint64_t*)&dataset[hash_32[419]]);
	hash_64[212] = *((uint64_t*)&dataset[hash_32[420]]);
	hash_64[213] = *((uint64_t*)&dataset[hash_32[421]]);
	hash_64[214] = *((uint64_t*)&dataset[hash_32[422]]);
	hash_64[215] = *((uint64_t*)&dataset[hash_32[423]]);
	hash_64[216] = *((uint64_t*)&dataset[hash_32[424]]);
	hash_64[217] = *((uint64_t*)&dataset[hash_32[425]]);
	hash_64[218] = *((uint64_t*)&dataset[hash_32[426]]);
	hash_64[219] = *((uint64_t*)&dataset[hash_32[427]]);
	hash_64[220] = *((uint64_t*)&dataset[hash_32[428]]);
	hash_64[221] = *((uint64_t*)&dataset[hash_32[429]]);
	hash_64[222] = *((uint64_t*)&dataset[hash_32[430]]);
	hash_64[223] = *((uint64_t*)&dataset[hash_32[431]]);
#endif
#if MEMORY_THREADS > 14
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[224] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[225] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[226] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[227] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[228] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[229] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[230] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[231] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[224] = *((uint64_t*)&dataset[hash_32[448]]);
	hash_64[225] = *((uint64_t*)&dataset[hash_32[449]]);
	hash_64[226] = *((uint64_t*)&dataset[hash_32[450]]);
	hash_64[227] = *((uint64_t*)&dataset[hash_32[451]]);
	hash_64[228] = *((uint64_t*)&dataset[hash_32[452]]);
	hash_64[229] = *((uint64_t*)&dataset[hash_32[453]]);
	hash_64[230] = *((uint64_t*)&dataset[hash_32[454]]);
	hash_64[231] = *((uint64_t*)&dataset[hash_32[455]]);
	hash_64[232] = *((uint64_t*)&dataset[hash_32[456]]);
	hash_64[233] = *((uint64_t*)&dataset[hash_32[457]]);
	hash_64[234] = *((uint64_t*)&dataset[hash_32[458]]);
	hash_64[235] = *((uint64_t*)&dataset[hash_32[459]]);
	hash_64[236] = *((uint64_t*)&dataset[hash_32[460]]);
	hash_64[237] = *((uint64_t*)&dataset[hash_32[461]]);
	hash_64[238] = *((uint64_t*)&dataset[hash_32[462]]);
	hash_64[239] = *((uint64_t*)&dataset[hash_32[463]]);
#endif
#if MEMORY_THREADS > 15
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[240] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[241] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[242] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[243] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[244] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[245] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[246] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[247] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[240] = *((uint64_t*)&dataset[hash_32[480]]);
	hash_64[241] = *((uint64_t*)&dataset[hash_32[481]]);
	hash_64[242] = *((uint64_t*)&dataset[hash_32[482]]);
	hash_64[243] = *((uint64_t*)&dataset[hash_32[483]]);
	hash_64[244] = *((uint64_t*)&dataset[hash_32[484]]);
	hash_64[245] = *((uint64_t*)&dataset[hash_32[485]]);
	hash_64[246] = *((uint64_t*)&dataset[hash_32[486]]);
	hash_64[247] = *((uint64_t*)&dataset[hash_32[487]]);
	hash_64[248] = *((uint64_t*)&dataset[hash_32[488]]);
	hash_64[249] = *((uint64_t*)&dataset[hash_32[489]]);
	hash_64[250] = *((uint64_t*)&dataset[hash_32[490]]);
	hash_64[251] = *((uint64_t*)&dataset[hash_32[491]]);
	hash_64[252] = *((uint64_t*)&dataset[hash_32[492]]);
	hash_64[253] = *((uint64_t*)&dataset[hash_32[493]]);
	hash_64[254] = *((uint64_t*)&dataset[hash_32[494]]);
	hash_64[255] = *((uint64_t*)&dataset[hash_32[495]]);
#endif
#if MEMORY_THREADS > 16
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[256] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[257] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[258] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[259] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[260] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[261] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[262] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[263] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[256] = *((uint64_t*)&dataset[hash_32[512]]);
	hash_64[257] = *((uint64_t*)&dataset[hash_32[513]]);
	hash_64[258] = *((uint64_t*)&dataset[hash_32[514]]);
	hash_64[259] = *((uint64_t*)&dataset[hash_32[515]]);
	hash_64[260] = *((uint64_t*)&dataset[hash_32[516]]);
	hash_64[261] = *((uint64_t*)&dataset[hash_32[517]]);
	hash_64[262] = *((uint64_t*)&dataset[hash_32[518]]);
	hash_64[263] = *((uint64_t*)&dataset[hash_32[519]]);
	hash_64[264] = *((uint64_t*)&dataset[hash_32[520]]);
	hash_64[265] = *((uint64_t*)&dataset[hash_32[521]]);
	hash_64[266] = *((uint64_t*)&dataset[hash_32[522]]);
	hash_64[267] = *((uint64_t*)&dataset[hash_32[523]]);
	hash_64[268] = *((uint64_t*)&dataset[hash_32[524]]);
	hash_64[269] = *((uint64_t*)&dataset[hash_32[525]]);
	hash_64[270] = *((uint64_t*)&dataset[hash_32[526]]);
	hash_64[271] = *((uint64_t*)&dataset[hash_32[527]]);
#endif
#if MEMORY_THREADS > 17
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[272] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[273] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[274] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[275] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[276] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[277] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[278] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[279] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[272] = *((uint64_t*)&dataset[hash_32[544]]);
	hash_64[273] = *((uint64_t*)&dataset[hash_32[545]]);
	hash_64[274] = *((uint64_t*)&dataset[hash_32[546]]);
	hash_64[275] = *((uint64_t*)&dataset[hash_32[547]]);
	hash_64[276] = *((uint64_t*)&dataset[hash_32[548]]);
	hash_64[277] = *((uint64_t*)&dataset[hash_32[549]]);
	hash_64[278] = *((uint64_t*)&dataset[hash_32[550]]);
	hash_64[279] = *((uint64_t*)&dataset[hash_32[551]]);
	hash_64[280] = *((uint64_t*)&dataset[hash_32[552]]);
	hash_64[281] = *((uint64_t*)&dataset[hash_32[553]]);
	hash_64[282] = *((uint64_t*)&dataset[hash_32[554]]);
	hash_64[283] = *((uint64_t*)&dataset[hash_32[555]]);
	hash_64[284] = *((uint64_t*)&dataset[hash_32[556]]);
	hash_64[285] = *((uint64_t*)&dataset[hash_32[557]]);
	hash_64[286] = *((uint64_t*)&dataset[hash_32[558]]);
	hash_64[287] = *((uint64_t*)&dataset[hash_32[559]]);
#endif
#if MEMORY_THREADS > 18
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[288] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[289] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[290] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[291] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[292] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[293] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[294] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[295] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[288] = *((uint64_t*)&dataset[hash_32[576]]);
	hash_64[289] = *((uint64_t*)&dataset[hash_32[577]]);
	hash_64[290] = *((uint64_t*)&dataset[hash_32[578]]);
	hash_64[291] = *((uint64_t*)&dataset[hash_32[579]]);
	hash_64[292] = *((uint64_t*)&dataset[hash_32[580]]);
	hash_64[293] = *((uint64_t*)&dataset[hash_32[581]]);
	hash_64[294] = *((uint64_t*)&dataset[hash_32[582]]);
	hash_64[295] = *((uint64_t*)&dataset[hash_32[583]]);
	hash_64[296] = *((uint64_t*)&dataset[hash_32[584]]);
	hash_64[297] = *((uint64_t*)&dataset[hash_32[585]]);
	hash_64[298] = *((uint64_t*)&dataset[hash_32[586]]);
	hash_64[299] = *((uint64_t*)&dataset[hash_32[587]]);
	hash_64[300] = *((uint64_t*)&dataset[hash_32[588]]);
	hash_64[301] = *((uint64_t*)&dataset[hash_32[589]]);
	hash_64[302] = *((uint64_t*)&dataset[hash_32[590]]);
	hash_64[303] = *((uint64_t*)&dataset[hash_32[591]]);
#endif
#if MEMORY_THREADS > 19
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[304] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[305] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[306] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[307] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[308] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[309] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[310] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[311] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[304] = *((uint64_t*)&dataset[hash_32[608]]);
	hash_64[305] = *((uint64_t*)&dataset[hash_32[609]]);
	hash_64[306] = *((uint64_t*)&dataset[hash_32[610]]);
	hash_64[307] = *((uint64_t*)&dataset[hash_32[611]]);
	hash_64[308] = *((uint64_t*)&dataset[hash_32[612]]);
	hash_64[309] = *((uint64_t*)&dataset[hash_32[613]]);
	hash_64[310] = *((uint64_t*)&dataset[hash_32[614]]);
	hash_64[311] = *((uint64_t*)&dataset[hash_32[615]]);
	hash_64[312] = *((uint64_t*)&dataset[hash_32[616]]);
	hash_64[313] = *((uint64_t*)&dataset[hash_32[617]]);
	hash_64[314] = *((uint64_t*)&dataset[hash_32[618]]);
	hash_64[315] = *((uint64_t*)&dataset[hash_32[619]]);
	hash_64[316] = *((uint64_t*)&dataset[hash_32[620]]);
	hash_64[317] = *((uint64_t*)&dataset[hash_32[621]]);
	hash_64[318] = *((uint64_t*)&dataset[hash_32[622]]);
	hash_64[319] = *((uint64_t*)&dataset[hash_32[623]]);
#endif
#if MEMORY_THREADS > 20
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[320] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[321] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[322] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[323] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[324] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[325] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[326] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[327] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[320] = *((uint64_t*)&dataset[hash_32[640]]);
	hash_64[321] = *((uint64_t*)&dataset[hash_32[641]]);
	hash_64[322] = *((uint64_t*)&dataset[hash_32[642]]);
	hash_64[323] = *((uint64_t*)&dataset[hash_32[643]]);
	hash_64[324] = *((uint64_t*)&dataset[hash_32[644]]);
	hash_64[325] = *((uint64_t*)&dataset[hash_32[645]]);
	hash_64[326] = *((uint64_t*)&dataset[hash_32[646]]);
	hash_64[327] = *((uint64_t*)&dataset[hash_32[647]]);
	hash_64[328] = *((uint64_t*)&dataset[hash_32[648]]);
	hash_64[329] = *((uint64_t*)&dataset[hash_32[649]]);
	hash_64[330] = *((uint64_t*)&dataset[hash_32[650]]);
	hash_64[331] = *((uint64_t*)&dataset[hash_32[651]]);
	hash_64[332] = *((uint64_t*)&dataset[hash_32[652]]);
	hash_64[333] = *((uint64_t*)&dataset[hash_32[653]]);
	hash_64[334] = *((uint64_t*)&dataset[hash_32[654]]);
	hash_64[335] = *((uint64_t*)&dataset[hash_32[655]]);
#endif
#if MEMORY_THREADS > 21
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[336] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[337] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[338] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[339] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[340] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[341] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[342] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[343] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[336] = *((uint64_t*)&dataset[hash_32[672]]);
	hash_64[337] = *((uint64_t*)&dataset[hash_32[673]]);
	hash_64[338] = *((uint64_t*)&dataset[hash_32[674]]);
	hash_64[339] = *((uint64_t*)&dataset[hash_32[675]]);
	hash_64[340] = *((uint64_t*)&dataset[hash_32[676]]);
	hash_64[341] = *((uint64_t*)&dataset[hash_32[677]]);
	hash_64[342] = *((uint64_t*)&dataset[hash_32[678]]);
	hash_64[343] = *((uint64_t*)&dataset[hash_32[679]]);
	hash_64[344] = *((uint64_t*)&dataset[hash_32[680]]);
	hash_64[345] = *((uint64_t*)&dataset[hash_32[681]]);
	hash_64[346] = *((uint64_t*)&dataset[hash_32[682]]);
	hash_64[347] = *((uint64_t*)&dataset[hash_32[683]]);
	hash_64[348] = *((uint64_t*)&dataset[hash_32[684]]);
	hash_64[349] = *((uint64_t*)&dataset[hash_32[685]]);
	hash_64[350] = *((uint64_t*)&dataset[hash_32[686]]);
	hash_64[351] = *((uint64_t*)&dataset[hash_32[687]]);
#endif
#if MEMORY_THREADS > 22
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[352] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[353] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[354] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[355] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[356] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[357] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[358] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[359] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[352] = *((uint64_t*)&dataset[hash_32[704]]);
	hash_64[353] = *((uint64_t*)&dataset[hash_32[705]]);
	hash_64[354] = *((uint64_t*)&dataset[hash_32[706]]);
	hash_64[355] = *((uint64_t*)&dataset[hash_32[707]]);
	hash_64[356] = *((uint64_t*)&dataset[hash_32[708]]);
	hash_64[357] = *((uint64_t*)&dataset[hash_32[709]]);
	hash_64[358] = *((uint64_t*)&dataset[hash_32[710]]);
	hash_64[359] = *((uint64_t*)&dataset[hash_32[711]]);
	hash_64[360] = *((uint64_t*)&dataset[hash_32[712]]);
	hash_64[361] = *((uint64_t*)&dataset[hash_32[713]]);
	hash_64[362] = *((uint64_t*)&dataset[hash_32[714]]);
	hash_64[363] = *((uint64_t*)&dataset[hash_32[715]]);
	hash_64[364] = *((uint64_t*)&dataset[hash_32[716]]);
	hash_64[365] = *((uint64_t*)&dataset[hash_32[717]]);
	hash_64[366] = *((uint64_t*)&dataset[hash_32[718]]);
	hash_64[367] = *((uint64_t*)&dataset[hash_32[719]]);
#endif
#if MEMORY_THREADS > 23
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[368] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[369] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[370] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[371] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[372] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[373] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[374] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[375] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[368] = *((uint64_t*)&dataset[hash_32[736]]);
	hash_64[369] = *((uint64_t*)&dataset[hash_32[737]]);
	hash_64[370] = *((uint64_t*)&dataset[hash_32[738]]);
	hash_64[371] = *((uint64_t*)&dataset[hash_32[739]]);
	hash_64[372] = *((uint64_t*)&dataset[hash_32[740]]);
	hash_64[373] = *((uint64_t*)&dataset[hash_32[741]]);
	hash_64[374] = *((uint64_t*)&dataset[hash_32[742]]);
	hash_64[375] = *((uint64_t*)&dataset[hash_32[743]]);
	hash_64[376] = *((uint64_t*)&dataset[hash_32[744]]);
	hash_64[377] = *((uint64_t*)&dataset[hash_32[745]]);
	hash_64[378] = *((uint64_t*)&dataset[hash_32[746]]);
	hash_64[379] = *((uint64_t*)&dataset[hash_32[747]]);
	hash_64[380] = *((uint64_t*)&dataset[hash_32[748]]);
	hash_64[381] = *((uint64_t*)&dataset[hash_32[749]]);
	hash_64[382] = *((uint64_t*)&dataset[hash_32[750]]);
	hash_64[383] = *((uint64_t*)&dataset[hash_32[751]]);
#endif
#if MEMORY_THREADS > 24
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[384] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[385] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[386] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[387] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[388] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[389] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[390] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[391] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[384] = *((uint64_t*)&dataset[hash_32[768]]);
	hash_64[385] = *((uint64_t*)&dataset[hash_32[769]]);
	hash_64[386] = *((uint64_t*)&dataset[hash_32[770]]);
	hash_64[387] = *((uint64_t*)&dataset[hash_32[771]]);
	hash_64[388] = *((uint64_t*)&dataset[hash_32[772]]);
	hash_64[389] = *((uint64_t*)&dataset[hash_32[773]]);
	hash_64[390] = *((uint64_t*)&dataset[hash_32[774]]);
	hash_64[391] = *((uint64_t*)&dataset[hash_32[775]]);
	hash_64[392] = *((uint64_t*)&dataset[hash_32[776]]);
	hash_64[393] = *((uint64_t*)&dataset[hash_32[777]]);
	hash_64[394] = *((uint64_t*)&dataset[hash_32[778]]);
	hash_64[395] = *((uint64_t*)&dataset[hash_32[779]]);
	hash_64[396] = *((uint64_t*)&dataset[hash_32[780]]);
	hash_64[397] = *((uint64_t*)&dataset[hash_32[781]]);
	hash_64[398] = *((uint64_t*)&dataset[hash_32[782]]);
	hash_64[399] = *((uint64_t*)&dataset[hash_32[783]]);
#endif
#if MEMORY_THREADS > 25
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[400] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[401] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[402] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[403] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[404] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[405] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[406] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[407] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[400] = *((uint64_t*)&dataset[hash_32[800]]);
	hash_64[401] = *((uint64_t*)&dataset[hash_32[801]]);
	hash_64[402] = *((uint64_t*)&dataset[hash_32[802]]);
	hash_64[403] = *((uint64_t*)&dataset[hash_32[803]]);
	hash_64[404] = *((uint64_t*)&dataset[hash_32[804]]);
	hash_64[405] = *((uint64_t*)&dataset[hash_32[805]]);
	hash_64[406] = *((uint64_t*)&dataset[hash_32[806]]);
	hash_64[407] = *((uint64_t*)&dataset[hash_32[807]]);
	hash_64[408] = *((uint64_t*)&dataset[hash_32[808]]);
	hash_64[409] = *((uint64_t*)&dataset[hash_32[809]]);
	hash_64[410] = *((uint64_t*)&dataset[hash_32[810]]);
	hash_64[411] = *((uint64_t*)&dataset[hash_32[811]]);
	hash_64[412] = *((uint64_t*)&dataset[hash_32[812]]);
	hash_64[413] = *((uint64_t*)&dataset[hash_32[813]]);
	hash_64[414] = *((uint64_t*)&dataset[hash_32[814]]);
	hash_64[415] = *((uint64_t*)&dataset[hash_32[815]]);
#endif
#if MEMORY_THREADS > 26
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[416] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[417] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[418] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[419] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[420] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[421] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[422] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[423] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[416] = *((uint64_t*)&dataset[hash_32[832]]);
	hash_64[417] = *((uint64_t*)&dataset[hash_32[833]]);
	hash_64[418] = *((uint64_t*)&dataset[hash_32[834]]);
	hash_64[419] = *((uint64_t*)&dataset[hash_32[835]]);
	hash_64[420] = *((uint64_t*)&dataset[hash_32[836]]);
	hash_64[421] = *((uint64_t*)&dataset[hash_32[837]]);
	hash_64[422] = *((uint64_t*)&dataset[hash_32[838]]);
	hash_64[423] = *((uint64_t*)&dataset[hash_32[839]]);
	hash_64[424] = *((uint64_t*)&dataset[hash_32[840]]);
	hash_64[425] = *((uint64_t*)&dataset[hash_32[841]]);
	hash_64[426] = *((uint64_t*)&dataset[hash_32[842]]);
	hash_64[427] = *((uint64_t*)&dataset[hash_32[843]]);
	hash_64[428] = *((uint64_t*)&dataset[hash_32[844]]);
	hash_64[429] = *((uint64_t*)&dataset[hash_32[845]]);
	hash_64[430] = *((uint64_t*)&dataset[hash_32[846]]);
	hash_64[431] = *((uint64_t*)&dataset[hash_32[847]]);
#endif
#if MEMORY_THREADS > 27
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[432] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[433] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[434] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[435] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[436] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[437] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[438] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[439] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[432] = *((uint64_t*)&dataset[hash_32[864]]);
	hash_64[433] = *((uint64_t*)&dataset[hash_32[865]]);
	hash_64[434] = *((uint64_t*)&dataset[hash_32[866]]);
	hash_64[435] = *((uint64_t*)&dataset[hash_32[867]]);
	hash_64[436] = *((uint64_t*)&dataset[hash_32[868]]);
	hash_64[437] = *((uint64_t*)&dataset[hash_32[869]]);
	hash_64[438] = *((uint64_t*)&dataset[hash_32[870]]);
	hash_64[439] = *((uint64_t*)&dataset[hash_32[871]]);
	hash_64[440] = *((uint64_t*)&dataset[hash_32[872]]);
	hash_64[441] = *((uint64_t*)&dataset[hash_32[873]]);
	hash_64[442] = *((uint64_t*)&dataset[hash_32[874]]);
	hash_64[443] = *((uint64_t*)&dataset[hash_32[875]]);
	hash_64[444] = *((uint64_t*)&dataset[hash_32[876]]);
	hash_64[445] = *((uint64_t*)&dataset[hash_32[877]]);
	hash_64[446] = *((uint64_t*)&dataset[hash_32[878]]);
	hash_64[447] = *((uint64_t*)&dataset[hash_32[879]]);
#endif
#if MEMORY_THREADS > 28
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[448] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[449] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[450] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[451] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[452] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[453] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[454] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[455] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[448] = *((uint64_t*)&dataset[hash_32[896]]);
	hash_64[449] = *((uint64_t*)&dataset[hash_32[897]]);
	hash_64[450] = *((uint64_t*)&dataset[hash_32[898]]);
	hash_64[451] = *((uint64_t*)&dataset[hash_32[899]]);
	hash_64[452] = *((uint64_t*)&dataset[hash_32[900]]);
	hash_64[453] = *((uint64_t*)&dataset[hash_32[901]]);
	hash_64[454] = *((uint64_t*)&dataset[hash_32[902]]);
	hash_64[455] = *((uint64_t*)&dataset[hash_32[903]]);
	hash_64[456] = *((uint64_t*)&dataset[hash_32[904]]);
	hash_64[457] = *((uint64_t*)&dataset[hash_32[905]]);
	hash_64[458] = *((uint64_t*)&dataset[hash_32[906]]);
	hash_64[459] = *((uint64_t*)&dataset[hash_32[907]]);
	hash_64[460] = *((uint64_t*)&dataset[hash_32[908]]);
	hash_64[461] = *((uint64_t*)&dataset[hash_32[909]]);
	hash_64[462] = *((uint64_t*)&dataset[hash_32[910]]);
	hash_64[463] = *((uint64_t*)&dataset[hash_32[911]]);
#endif
#if MEMORY_THREADS > 29
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[464] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[465] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[466] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[467] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[468] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[469] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[470] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[471] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[464] = *((uint64_t*)&dataset[hash_32[928]]);
	hash_64[465] = *((uint64_t*)&dataset[hash_32[929]]);
	hash_64[466] = *((uint64_t*)&dataset[hash_32[930]]);
	hash_64[467] = *((uint64_t*)&dataset[hash_32[931]]);
	hash_64[468] = *((uint64_t*)&dataset[hash_32[932]]);
	hash_64[469] = *((uint64_t*)&dataset[hash_32[933]]);
	hash_64[470] = *((uint64_t*)&dataset[hash_32[934]]);
	hash_64[471] = *((uint64_t*)&dataset[hash_32[935]]);
	hash_64[472] = *((uint64_t*)&dataset[hash_32[936]]);
	hash_64[473] = *((uint64_t*)&dataset[hash_32[937]]);
	hash_64[474] = *((uint64_t*)&dataset[hash_32[938]]);
	hash_64[475] = *((uint64_t*)&dataset[hash_32[939]]);
	hash_64[476] = *((uint64_t*)&dataset[hash_32[940]]);
	hash_64[477] = *((uint64_t*)&dataset[hash_32[941]]);
	hash_64[478] = *((uint64_t*)&dataset[hash_32[942]]);
	hash_64[479] = *((uint64_t*)&dataset[hash_32[943]]);
#endif
#if MEMORY_THREADS > 30
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[480] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[481] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[482] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[483] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[484] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[485] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[486] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[487] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[480] = *((uint64_t*)&dataset[hash_32[960]]);
	hash_64[481] = *((uint64_t*)&dataset[hash_32[961]]);
	hash_64[482] = *((uint64_t*)&dataset[hash_32[962]]);
	hash_64[483] = *((uint64_t*)&dataset[hash_32[963]]);
	hash_64[484] = *((uint64_t*)&dataset[hash_32[964]]);
	hash_64[485] = *((uint64_t*)&dataset[hash_32[965]]);
	hash_64[486] = *((uint64_t*)&dataset[hash_32[966]]);
	hash_64[487] = *((uint64_t*)&dataset[hash_32[967]]);
	hash_64[488] = *((uint64_t*)&dataset[hash_32[968]]);
	hash_64[489] = *((uint64_t*)&dataset[hash_32[969]]);
	hash_64[490] = *((uint64_t*)&dataset[hash_32[970]]);
	hash_64[491] = *((uint64_t*)&dataset[hash_32[971]]);
	hash_64[492] = *((uint64_t*)&dataset[hash_32[972]]);
	hash_64[493] = *((uint64_t*)&dataset[hash_32[973]]);
	hash_64[494] = *((uint64_t*)&dataset[hash_32[974]]);
	hash_64[495] = *((uint64_t*)&dataset[hash_32[975]]);
#endif
#if MEMORY_THREADS > 31
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[496] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[497] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[498] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[499] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[500] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[501] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[502] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[503] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[496] = *((uint64_t*)&dataset[hash_32[992]]);
	hash_64[497] = *((uint64_t*)&dataset[hash_32[993]]);
	hash_64[498] = *((uint64_t*)&dataset[hash_32[994]]);
	hash_64[499] = *((uint64_t*)&dataset[hash_32[995]]);
	hash_64[500] = *((uint64_t*)&dataset[hash_32[996]]);
	hash_64[501] = *((uint64_t*)&dataset[hash_32[997]]);
	hash_64[502] = *((uint64_t*)&dataset[hash_32[998]]);
	hash_64[503] = *((uint64_t*)&dataset[hash_32[999]]);
	hash_64[504] = *((uint64_t*)&dataset[hash_32[1000]]);
	hash_64[505] = *((uint64_t*)&dataset[hash_32[1001]]);
	hash_64[506] = *((uint64_t*)&dataset[hash_32[1002]]);
	hash_64[507] = *((uint64_t*)&dataset[hash_32[1003]]);
	hash_64[508] = *((uint64_t*)&dataset[hash_32[1004]]);
	hash_64[509] = *((uint64_t*)&dataset[hash_32[1005]]);
	hash_64[510] = *((uint64_t*)&dataset[hash_32[1006]]);
	hash_64[511] = *((uint64_t*)&dataset[hash_32[1007]]);
#endif
#if MEMORY_THREADS > 32
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[512] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[513] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[514] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[515] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[516] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[517] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[518] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[519] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[512] = *((uint64_t*)&dataset[hash_32[1024]]);
	hash_64[513] = *((uint64_t*)&dataset[hash_32[1025]]);
	hash_64[514] = *((uint64_t*)&dataset[hash_32[1026]]);
	hash_64[515] = *((uint64_t*)&dataset[hash_32[1027]]);
	hash_64[516] = *((uint64_t*)&dataset[hash_32[1028]]);
	hash_64[517] = *((uint64_t*)&dataset[hash_32[1029]]);
	hash_64[518] = *((uint64_t*)&dataset[hash_32[1030]]);
	hash_64[519] = *((uint64_t*)&dataset[hash_32[1031]]);
	hash_64[520] = *((uint64_t*)&dataset[hash_32[1032]]);
	hash_64[521] = *((uint64_t*)&dataset[hash_32[1033]]);
	hash_64[522] = *((uint64_t*)&dataset[hash_32[1034]]);
	hash_64[523] = *((uint64_t*)&dataset[hash_32[1035]]);
	hash_64[524] = *((uint64_t*)&dataset[hash_32[1036]]);
	hash_64[525] = *((uint64_t*)&dataset[hash_32[1037]]);
	hash_64[526] = *((uint64_t*)&dataset[hash_32[1038]]);
	hash_64[527] = *((uint64_t*)&dataset[hash_32[1039]]);
#endif
#if MEMORY_THREADS > 33
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[528] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[529] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[530] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[531] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[532] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[533] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[534] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[535] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[528] = *((uint64_t*)&dataset[hash_32[1056]]);
	hash_64[529] = *((uint64_t*)&dataset[hash_32[1057]]);
	hash_64[530] = *((uint64_t*)&dataset[hash_32[1058]]);
	hash_64[531] = *((uint64_t*)&dataset[hash_32[1059]]);
	hash_64[532] = *((uint64_t*)&dataset[hash_32[1060]]);
	hash_64[533] = *((uint64_t*)&dataset[hash_32[1061]]);
	hash_64[534] = *((uint64_t*)&dataset[hash_32[1062]]);
	hash_64[535] = *((uint64_t*)&dataset[hash_32[1063]]);
	hash_64[536] = *((uint64_t*)&dataset[hash_32[1064]]);
	hash_64[537] = *((uint64_t*)&dataset[hash_32[1065]]);
	hash_64[538] = *((uint64_t*)&dataset[hash_32[1066]]);
	hash_64[539] = *((uint64_t*)&dataset[hash_32[1067]]);
	hash_64[540] = *((uint64_t*)&dataset[hash_32[1068]]);
	hash_64[541] = *((uint64_t*)&dataset[hash_32[1069]]);
	hash_64[542] = *((uint64_t*)&dataset[hash_32[1070]]);
	hash_64[543] = *((uint64_t*)&dataset[hash_32[1071]]);
#endif
#if MEMORY_THREADS > 34
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[544] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[545] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[546] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[547] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[548] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[549] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[550] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[551] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[544] = *((uint64_t*)&dataset[hash_32[1088]]);
	hash_64[545] = *((uint64_t*)&dataset[hash_32[1089]]);
	hash_64[546] = *((uint64_t*)&dataset[hash_32[1090]]);
	hash_64[547] = *((uint64_t*)&dataset[hash_32[1091]]);
	hash_64[548] = *((uint64_t*)&dataset[hash_32[1092]]);
	hash_64[549] = *((uint64_t*)&dataset[hash_32[1093]]);
	hash_64[550] = *((uint64_t*)&dataset[hash_32[1094]]);
	hash_64[551] = *((uint64_t*)&dataset[hash_32[1095]]);
	hash_64[552] = *((uint64_t*)&dataset[hash_32[1096]]);
	hash_64[553] = *((uint64_t*)&dataset[hash_32[1097]]);
	hash_64[554] = *((uint64_t*)&dataset[hash_32[1098]]);
	hash_64[555] = *((uint64_t*)&dataset[hash_32[1099]]);
	hash_64[556] = *((uint64_t*)&dataset[hash_32[1100]]);
	hash_64[557] = *((uint64_t*)&dataset[hash_32[1101]]);
	hash_64[558] = *((uint64_t*)&dataset[hash_32[1102]]);
	hash_64[559] = *((uint64_t*)&dataset[hash_32[1103]]);
#endif
#if MEMORY_THREADS > 35
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[560] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[561] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[562] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[563] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[564] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[565] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[566] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[567] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[560] = *((uint64_t*)&dataset[hash_32[1120]]);
	hash_64[561] = *((uint64_t*)&dataset[hash_32[1121]]);
	hash_64[562] = *((uint64_t*)&dataset[hash_32[1122]]);
	hash_64[563] = *((uint64_t*)&dataset[hash_32[1123]]);
	hash_64[564] = *((uint64_t*)&dataset[hash_32[1124]]);
	hash_64[565] = *((uint64_t*)&dataset[hash_32[1125]]);
	hash_64[566] = *((uint64_t*)&dataset[hash_32[1126]]);
	hash_64[567] = *((uint64_t*)&dataset[hash_32[1127]]);
	hash_64[568] = *((uint64_t*)&dataset[hash_32[1128]]);
	hash_64[569] = *((uint64_t*)&dataset[hash_32[1129]]);
	hash_64[570] = *((uint64_t*)&dataset[hash_32[1130]]);
	hash_64[571] = *((uint64_t*)&dataset[hash_32[1131]]);
	hash_64[572] = *((uint64_t*)&dataset[hash_32[1132]]);
	hash_64[573] = *((uint64_t*)&dataset[hash_32[1133]]);
	hash_64[574] = *((uint64_t*)&dataset[hash_32[1134]]);
	hash_64[575] = *((uint64_t*)&dataset[hash_32[1135]]);
#endif
#if MEMORY_THREADS > 36
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[576] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[577] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[578] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[579] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[580] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[581] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[582] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[583] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[576] = *((uint64_t*)&dataset[hash_32[1152]]);
	hash_64[577] = *((uint64_t*)&dataset[hash_32[1153]]);
	hash_64[578] = *((uint64_t*)&dataset[hash_32[1154]]);
	hash_64[579] = *((uint64_t*)&dataset[hash_32[1155]]);
	hash_64[580] = *((uint64_t*)&dataset[hash_32[1156]]);
	hash_64[581] = *((uint64_t*)&dataset[hash_32[1157]]);
	hash_64[582] = *((uint64_t*)&dataset[hash_32[1158]]);
	hash_64[583] = *((uint64_t*)&dataset[hash_32[1159]]);
	hash_64[584] = *((uint64_t*)&dataset[hash_32[1160]]);
	hash_64[585] = *((uint64_t*)&dataset[hash_32[1161]]);
	hash_64[586] = *((uint64_t*)&dataset[hash_32[1162]]);
	hash_64[587] = *((uint64_t*)&dataset[hash_32[1163]]);
	hash_64[588] = *((uint64_t*)&dataset[hash_32[1164]]);
	hash_64[589] = *((uint64_t*)&dataset[hash_32[1165]]);
	hash_64[590] = *((uint64_t*)&dataset[hash_32[1166]]);
	hash_64[591] = *((uint64_t*)&dataset[hash_32[1167]]);
#endif
#if MEMORY_THREADS > 37
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[592] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[593] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[594] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[595] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[596] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[597] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[598] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[599] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[592] = *((uint64_t*)&dataset[hash_32[1184]]);
	hash_64[593] = *((uint64_t*)&dataset[hash_32[1185]]);
	hash_64[594] = *((uint64_t*)&dataset[hash_32[1186]]);
	hash_64[595] = *((uint64_t*)&dataset[hash_32[1187]]);
	hash_64[596] = *((uint64_t*)&dataset[hash_32[1188]]);
	hash_64[597] = *((uint64_t*)&dataset[hash_32[1189]]);
	hash_64[598] = *((uint64_t*)&dataset[hash_32[1190]]);
	hash_64[599] = *((uint64_t*)&dataset[hash_32[1191]]);
	hash_64[600] = *((uint64_t*)&dataset[hash_32[1192]]);
	hash_64[601] = *((uint64_t*)&dataset[hash_32[1193]]);
	hash_64[602] = *((uint64_t*)&dataset[hash_32[1194]]);
	hash_64[603] = *((uint64_t*)&dataset[hash_32[1195]]);
	hash_64[604] = *((uint64_t*)&dataset[hash_32[1196]]);
	hash_64[605] = *((uint64_t*)&dataset[hash_32[1197]]);
	hash_64[606] = *((uint64_t*)&dataset[hash_32[1198]]);
	hash_64[607] = *((uint64_t*)&dataset[hash_32[1199]]);
#endif
#if MEMORY_THREADS > 38
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[608] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[609] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[610] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[611] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[612] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[613] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[614] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[615] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[608] = *((uint64_t*)&dataset[hash_32[1216]]);
	hash_64[609] = *((uint64_t*)&dataset[hash_32[1217]]);
	hash_64[610] = *((uint64_t*)&dataset[hash_32[1218]]);
	hash_64[611] = *((uint64_t*)&dataset[hash_32[1219]]);
	hash_64[612] = *((uint64_t*)&dataset[hash_32[1220]]);
	hash_64[613] = *((uint64_t*)&dataset[hash_32[1221]]);
	hash_64[614] = *((uint64_t*)&dataset[hash_32[1222]]);
	hash_64[615] = *((uint64_t*)&dataset[hash_32[1223]]);
	hash_64[616] = *((uint64_t*)&dataset[hash_32[1224]]);
	hash_64[617] = *((uint64_t*)&dataset[hash_32[1225]]);
	hash_64[618] = *((uint64_t*)&dataset[hash_32[1226]]);
	hash_64[619] = *((uint64_t*)&dataset[hash_32[1227]]);
	hash_64[620] = *((uint64_t*)&dataset[hash_32[1228]]);
	hash_64[621] = *((uint64_t*)&dataset[hash_32[1229]]);
	hash_64[622] = *((uint64_t*)&dataset[hash_32[1230]]);
	hash_64[623] = *((uint64_t*)&dataset[hash_32[1231]]);
#endif
#if MEMORY_THREADS > 39
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[624] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[625] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[626] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[627] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[628] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[629] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[630] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[631] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[624] = *((uint64_t*)&dataset[hash_32[1248]]);
	hash_64[625] = *((uint64_t*)&dataset[hash_32[1249]]);
	hash_64[626] = *((uint64_t*)&dataset[hash_32[1250]]);
	hash_64[627] = *((uint64_t*)&dataset[hash_32[1251]]);
	hash_64[628] = *((uint64_t*)&dataset[hash_32[1252]]);
	hash_64[629] = *((uint64_t*)&dataset[hash_32[1253]]);
	hash_64[630] = *((uint64_t*)&dataset[hash_32[1254]]);
	hash_64[631] = *((uint64_t*)&dataset[hash_32[1255]]);
	hash_64[632] = *((uint64_t*)&dataset[hash_32[1256]]);
	hash_64[633] = *((uint64_t*)&dataset[hash_32[1257]]);
	hash_64[634] = *((uint64_t*)&dataset[hash_32[1258]]);
	hash_64[635] = *((uint64_t*)&dataset[hash_32[1259]]);
	hash_64[636] = *((uint64_t*)&dataset[hash_32[1260]]);
	hash_64[637] = *((uint64_t*)&dataset[hash_32[1261]]);
	hash_64[638] = *((uint64_t*)&dataset[hash_32[1262]]);
	hash_64[639] = *((uint64_t*)&dataset[hash_32[1263]]);
#endif
#if MEMORY_THREADS > 40
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[640] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[641] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[642] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[643] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[644] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[645] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[646] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[647] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[640] = *((uint64_t*)&dataset[hash_32[1280]]);
	hash_64[641] = *((uint64_t*)&dataset[hash_32[1281]]);
	hash_64[642] = *((uint64_t*)&dataset[hash_32[1282]]);
	hash_64[643] = *((uint64_t*)&dataset[hash_32[1283]]);
	hash_64[644] = *((uint64_t*)&dataset[hash_32[1284]]);
	hash_64[645] = *((uint64_t*)&dataset[hash_32[1285]]);
	hash_64[646] = *((uint64_t*)&dataset[hash_32[1286]]);
	hash_64[647] = *((uint64_t*)&dataset[hash_32[1287]]);
	hash_64[648] = *((uint64_t*)&dataset[hash_32[1288]]);
	hash_64[649] = *((uint64_t*)&dataset[hash_32[1289]]);
	hash_64[650] = *((uint64_t*)&dataset[hash_32[1290]]);
	hash_64[651] = *((uint64_t*)&dataset[hash_32[1291]]);
	hash_64[652] = *((uint64_t*)&dataset[hash_32[1292]]);
	hash_64[653] = *((uint64_t*)&dataset[hash_32[1293]]);
	hash_64[654] = *((uint64_t*)&dataset[hash_32[1294]]);
	hash_64[655] = *((uint64_t*)&dataset[hash_32[1295]]);
#endif
#if MEMORY_THREADS > 41
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[656] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[657] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[658] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[659] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[660] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[661] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[662] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[663] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[656] = *((uint64_t*)&dataset[hash_32[1312]]);
	hash_64[657] = *((uint64_t*)&dataset[hash_32[1313]]);
	hash_64[658] = *((uint64_t*)&dataset[hash_32[1314]]);
	hash_64[659] = *((uint64_t*)&dataset[hash_32[1315]]);
	hash_64[660] = *((uint64_t*)&dataset[hash_32[1316]]);
	hash_64[661] = *((uint64_t*)&dataset[hash_32[1317]]);
	hash_64[662] = *((uint64_t*)&dataset[hash_32[1318]]);
	hash_64[663] = *((uint64_t*)&dataset[hash_32[1319]]);
	hash_64[664] = *((uint64_t*)&dataset[hash_32[1320]]);
	hash_64[665] = *((uint64_t*)&dataset[hash_32[1321]]);
	hash_64[666] = *((uint64_t*)&dataset[hash_32[1322]]);
	hash_64[667] = *((uint64_t*)&dataset[hash_32[1323]]);
	hash_64[668] = *((uint64_t*)&dataset[hash_32[1324]]);
	hash_64[669] = *((uint64_t*)&dataset[hash_32[1325]]);
	hash_64[670] = *((uint64_t*)&dataset[hash_32[1326]]);
	hash_64[671] = *((uint64_t*)&dataset[hash_32[1327]]);
#endif
#if MEMORY_THREADS > 42
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[672] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[673] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[674] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[675] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[676] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[677] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[678] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[679] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[672] = *((uint64_t*)&dataset[hash_32[1344]]);
	hash_64[673] = *((uint64_t*)&dataset[hash_32[1345]]);
	hash_64[674] = *((uint64_t*)&dataset[hash_32[1346]]);
	hash_64[675] = *((uint64_t*)&dataset[hash_32[1347]]);
	hash_64[676] = *((uint64_t*)&dataset[hash_32[1348]]);
	hash_64[677] = *((uint64_t*)&dataset[hash_32[1349]]);
	hash_64[678] = *((uint64_t*)&dataset[hash_32[1350]]);
	hash_64[679] = *((uint64_t*)&dataset[hash_32[1351]]);
	hash_64[680] = *((uint64_t*)&dataset[hash_32[1352]]);
	hash_64[681] = *((uint64_t*)&dataset[hash_32[1353]]);
	hash_64[682] = *((uint64_t*)&dataset[hash_32[1354]]);
	hash_64[683] = *((uint64_t*)&dataset[hash_32[1355]]);
	hash_64[684] = *((uint64_t*)&dataset[hash_32[1356]]);
	hash_64[685] = *((uint64_t*)&dataset[hash_32[1357]]);
	hash_64[686] = *((uint64_t*)&dataset[hash_32[1358]]);
	hash_64[687] = *((uint64_t*)&dataset[hash_32[1359]]);
#endif
#if MEMORY_THREADS > 43
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[688] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[689] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[690] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[691] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[692] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[693] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[694] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[695] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[688] = *((uint64_t*)&dataset[hash_32[1376]]);
	hash_64[689] = *((uint64_t*)&dataset[hash_32[1377]]);
	hash_64[690] = *((uint64_t*)&dataset[hash_32[1378]]);
	hash_64[691] = *((uint64_t*)&dataset[hash_32[1379]]);
	hash_64[692] = *((uint64_t*)&dataset[hash_32[1380]]);
	hash_64[693] = *((uint64_t*)&dataset[hash_32[1381]]);
	hash_64[694] = *((uint64_t*)&dataset[hash_32[1382]]);
	hash_64[695] = *((uint64_t*)&dataset[hash_32[1383]]);
	hash_64[696] = *((uint64_t*)&dataset[hash_32[1384]]);
	hash_64[697] = *((uint64_t*)&dataset[hash_32[1385]]);
	hash_64[698] = *((uint64_t*)&dataset[hash_32[1386]]);
	hash_64[699] = *((uint64_t*)&dataset[hash_32[1387]]);
	hash_64[700] = *((uint64_t*)&dataset[hash_32[1388]]);
	hash_64[701] = *((uint64_t*)&dataset[hash_32[1389]]);
	hash_64[702] = *((uint64_t*)&dataset[hash_32[1390]]);
	hash_64[703] = *((uint64_t*)&dataset[hash_32[1391]]);
#endif
#if MEMORY_THREADS > 44
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[704] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[705] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[706] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[707] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[708] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[709] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[710] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[711] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[704] = *((uint64_t*)&dataset[hash_32[1408]]);
	hash_64[705] = *((uint64_t*)&dataset[hash_32[1409]]);
	hash_64[706] = *((uint64_t*)&dataset[hash_32[1410]]);
	hash_64[707] = *((uint64_t*)&dataset[hash_32[1411]]);
	hash_64[708] = *((uint64_t*)&dataset[hash_32[1412]]);
	hash_64[709] = *((uint64_t*)&dataset[hash_32[1413]]);
	hash_64[710] = *((uint64_t*)&dataset[hash_32[1414]]);
	hash_64[711] = *((uint64_t*)&dataset[hash_32[1415]]);
	hash_64[712] = *((uint64_t*)&dataset[hash_32[1416]]);
	hash_64[713] = *((uint64_t*)&dataset[hash_32[1417]]);
	hash_64[714] = *((uint64_t*)&dataset[hash_32[1418]]);
	hash_64[715] = *((uint64_t*)&dataset[hash_32[1419]]);
	hash_64[716] = *((uint64_t*)&dataset[hash_32[1420]]);
	hash_64[717] = *((uint64_t*)&dataset[hash_32[1421]]);
	hash_64[718] = *((uint64_t*)&dataset[hash_32[1422]]);
	hash_64[719] = *((uint64_t*)&dataset[hash_32[1423]]);
#endif
#if MEMORY_THREADS > 45
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[720] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[721] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[722] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[723] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[724] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[725] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[726] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[727] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[720] = *((uint64_t*)&dataset[hash_32[1440]]);
	hash_64[721] = *((uint64_t*)&dataset[hash_32[1441]]);
	hash_64[722] = *((uint64_t*)&dataset[hash_32[1442]]);
	hash_64[723] = *((uint64_t*)&dataset[hash_32[1443]]);
	hash_64[724] = *((uint64_t*)&dataset[hash_32[1444]]);
	hash_64[725] = *((uint64_t*)&dataset[hash_32[1445]]);
	hash_64[726] = *((uint64_t*)&dataset[hash_32[1446]]);
	hash_64[727] = *((uint64_t*)&dataset[hash_32[1447]]);
	hash_64[728] = *((uint64_t*)&dataset[hash_32[1448]]);
	hash_64[729] = *((uint64_t*)&dataset[hash_32[1449]]);
	hash_64[730] = *((uint64_t*)&dataset[hash_32[1450]]);
	hash_64[731] = *((uint64_t*)&dataset[hash_32[1451]]);
	hash_64[732] = *((uint64_t*)&dataset[hash_32[1452]]);
	hash_64[733] = *((uint64_t*)&dataset[hash_32[1453]]);
	hash_64[734] = *((uint64_t*)&dataset[hash_32[1454]]);
	hash_64[735] = *((uint64_t*)&dataset[hash_32[1455]]);
#endif
#if MEMORY_THREADS > 46
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[736] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[737] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[738] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[739] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[740] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[741] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[742] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[743] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[736] = *((uint64_t*)&dataset[hash_32[1472]]);
	hash_64[737] = *((uint64_t*)&dataset[hash_32[1473]]);
	hash_64[738] = *((uint64_t*)&dataset[hash_32[1474]]);
	hash_64[739] = *((uint64_t*)&dataset[hash_32[1475]]);
	hash_64[740] = *((uint64_t*)&dataset[hash_32[1476]]);
	hash_64[741] = *((uint64_t*)&dataset[hash_32[1477]]);
	hash_64[742] = *((uint64_t*)&dataset[hash_32[1478]]);
	hash_64[743] = *((uint64_t*)&dataset[hash_32[1479]]);
	hash_64[744] = *((uint64_t*)&dataset[hash_32[1480]]);
	hash_64[745] = *((uint64_t*)&dataset[hash_32[1481]]);
	hash_64[746] = *((uint64_t*)&dataset[hash_32[1482]]);
	hash_64[747] = *((uint64_t*)&dataset[hash_32[1483]]);
	hash_64[748] = *((uint64_t*)&dataset[hash_32[1484]]);
	hash_64[749] = *((uint64_t*)&dataset[hash_32[1485]]);
	hash_64[750] = *((uint64_t*)&dataset[hash_32[1486]]);
	hash_64[751] = *((uint64_t*)&dataset[hash_32[1487]]);
#endif
#if MEMORY_THREADS > 47
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[752] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[753] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[754] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[755] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[756] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[757] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[758] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[759] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[752] = *((uint64_t*)&dataset[hash_32[1504]]);
	hash_64[753] = *((uint64_t*)&dataset[hash_32[1505]]);
	hash_64[754] = *((uint64_t*)&dataset[hash_32[1506]]);
	hash_64[755] = *((uint64_t*)&dataset[hash_32[1507]]);
	hash_64[756] = *((uint64_t*)&dataset[hash_32[1508]]);
	hash_64[757] = *((uint64_t*)&dataset[hash_32[1509]]);
	hash_64[758] = *((uint64_t*)&dataset[hash_32[1510]]);
	hash_64[759] = *((uint64_t*)&dataset[hash_32[1511]]);
	hash_64[760] = *((uint64_t*)&dataset[hash_32[1512]]);
	hash_64[761] = *((uint64_t*)&dataset[hash_32[1513]]);
	hash_64[762] = *((uint64_t*)&dataset[hash_32[1514]]);
	hash_64[763] = *((uint64_t*)&dataset[hash_32[1515]]);
	hash_64[764] = *((uint64_t*)&dataset[hash_32[1516]]);
	hash_64[765] = *((uint64_t*)&dataset[hash_32[1517]]);
	hash_64[766] = *((uint64_t*)&dataset[hash_32[1518]]);
	hash_64[767] = *((uint64_t*)&dataset[hash_32[1519]]);
#endif
#if MEMORY_THREADS > 48
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[768] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[769] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[770] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[771] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[772] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[773] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[774] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[775] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[768] = *((uint64_t*)&dataset[hash_32[1536]]);
	hash_64[769] = *((uint64_t*)&dataset[hash_32[1537]]);
	hash_64[770] = *((uint64_t*)&dataset[hash_32[1538]]);
	hash_64[771] = *((uint64_t*)&dataset[hash_32[1539]]);
	hash_64[772] = *((uint64_t*)&dataset[hash_32[1540]]);
	hash_64[773] = *((uint64_t*)&dataset[hash_32[1541]]);
	hash_64[774] = *((uint64_t*)&dataset[hash_32[1542]]);
	hash_64[775] = *((uint64_t*)&dataset[hash_32[1543]]);
	hash_64[776] = *((uint64_t*)&dataset[hash_32[1544]]);
	hash_64[777] = *((uint64_t*)&dataset[hash_32[1545]]);
	hash_64[778] = *((uint64_t*)&dataset[hash_32[1546]]);
	hash_64[779] = *((uint64_t*)&dataset[hash_32[1547]]);
	hash_64[780] = *((uint64_t*)&dataset[hash_32[1548]]);
	hash_64[781] = *((uint64_t*)&dataset[hash_32[1549]]);
	hash_64[782] = *((uint64_t*)&dataset[hash_32[1550]]);
	hash_64[783] = *((uint64_t*)&dataset[hash_32[1551]]);
#endif
#if MEMORY_THREADS > 49
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[784] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[785] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[786] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[787] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[788] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[789] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[790] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[791] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[784] = *((uint64_t*)&dataset[hash_32[1568]]);
	hash_64[785] = *((uint64_t*)&dataset[hash_32[1569]]);
	hash_64[786] = *((uint64_t*)&dataset[hash_32[1570]]);
	hash_64[787] = *((uint64_t*)&dataset[hash_32[1571]]);
	hash_64[788] = *((uint64_t*)&dataset[hash_32[1572]]);
	hash_64[789] = *((uint64_t*)&dataset[hash_32[1573]]);
	hash_64[790] = *((uint64_t*)&dataset[hash_32[1574]]);
	hash_64[791] = *((uint64_t*)&dataset[hash_32[1575]]);
	hash_64[792] = *((uint64_t*)&dataset[hash_32[1576]]);
	hash_64[793] = *((uint64_t*)&dataset[hash_32[1577]]);
	hash_64[794] = *((uint64_t*)&dataset[hash_32[1578]]);
	hash_64[795] = *((uint64_t*)&dataset[hash_32[1579]]);
	hash_64[796] = *((uint64_t*)&dataset[hash_32[1580]]);
	hash_64[797] = *((uint64_t*)&dataset[hash_32[1581]]);
	hash_64[798] = *((uint64_t*)&dataset[hash_32[1582]]);
	hash_64[799] = *((uint64_t*)&dataset[hash_32[1583]]);
#endif
#if MEMORY_THREADS > 50
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[800] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[801] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[802] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[803] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[804] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[805] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[806] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[807] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[800] = *((uint64_t*)&dataset[hash_32[1600]]);
	hash_64[801] = *((uint64_t*)&dataset[hash_32[1601]]);
	hash_64[802] = *((uint64_t*)&dataset[hash_32[1602]]);
	hash_64[803] = *((uint64_t*)&dataset[hash_32[1603]]);
	hash_64[804] = *((uint64_t*)&dataset[hash_32[1604]]);
	hash_64[805] = *((uint64_t*)&dataset[hash_32[1605]]);
	hash_64[806] = *((uint64_t*)&dataset[hash_32[1606]]);
	hash_64[807] = *((uint64_t*)&dataset[hash_32[1607]]);
	hash_64[808] = *((uint64_t*)&dataset[hash_32[1608]]);
	hash_64[809] = *((uint64_t*)&dataset[hash_32[1609]]);
	hash_64[810] = *((uint64_t*)&dataset[hash_32[1610]]);
	hash_64[811] = *((uint64_t*)&dataset[hash_32[1611]]);
	hash_64[812] = *((uint64_t*)&dataset[hash_32[1612]]);
	hash_64[813] = *((uint64_t*)&dataset[hash_32[1613]]);
	hash_64[814] = *((uint64_t*)&dataset[hash_32[1614]]);
	hash_64[815] = *((uint64_t*)&dataset[hash_32[1615]]);
#endif
#if MEMORY_THREADS > 51
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[816] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[817] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[818] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[819] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[820] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[821] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[822] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[823] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[816] = *((uint64_t*)&dataset[hash_32[1632]]);
	hash_64[817] = *((uint64_t*)&dataset[hash_32[1633]]);
	hash_64[818] = *((uint64_t*)&dataset[hash_32[1634]]);
	hash_64[819] = *((uint64_t*)&dataset[hash_32[1635]]);
	hash_64[820] = *((uint64_t*)&dataset[hash_32[1636]]);
	hash_64[821] = *((uint64_t*)&dataset[hash_32[1637]]);
	hash_64[822] = *((uint64_t*)&dataset[hash_32[1638]]);
	hash_64[823] = *((uint64_t*)&dataset[hash_32[1639]]);
	hash_64[824] = *((uint64_t*)&dataset[hash_32[1640]]);
	hash_64[825] = *((uint64_t*)&dataset[hash_32[1641]]);
	hash_64[826] = *((uint64_t*)&dataset[hash_32[1642]]);
	hash_64[827] = *((uint64_t*)&dataset[hash_32[1643]]);
	hash_64[828] = *((uint64_t*)&dataset[hash_32[1644]]);
	hash_64[829] = *((uint64_t*)&dataset[hash_32[1645]]);
	hash_64[830] = *((uint64_t*)&dataset[hash_32[1646]]);
	hash_64[831] = *((uint64_t*)&dataset[hash_32[1647]]);
#endif
#if MEMORY_THREADS > 52
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[832] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[833] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[834] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[835] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[836] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[837] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[838] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[839] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[832] = *((uint64_t*)&dataset[hash_32[1664]]);
	hash_64[833] = *((uint64_t*)&dataset[hash_32[1665]]);
	hash_64[834] = *((uint64_t*)&dataset[hash_32[1666]]);
	hash_64[835] = *((uint64_t*)&dataset[hash_32[1667]]);
	hash_64[836] = *((uint64_t*)&dataset[hash_32[1668]]);
	hash_64[837] = *((uint64_t*)&dataset[hash_32[1669]]);
	hash_64[838] = *((uint64_t*)&dataset[hash_32[1670]]);
	hash_64[839] = *((uint64_t*)&dataset[hash_32[1671]]);
	hash_64[840] = *((uint64_t*)&dataset[hash_32[1672]]);
	hash_64[841] = *((uint64_t*)&dataset[hash_32[1673]]);
	hash_64[842] = *((uint64_t*)&dataset[hash_32[1674]]);
	hash_64[843] = *((uint64_t*)&dataset[hash_32[1675]]);
	hash_64[844] = *((uint64_t*)&dataset[hash_32[1676]]);
	hash_64[845] = *((uint64_t*)&dataset[hash_32[1677]]);
	hash_64[846] = *((uint64_t*)&dataset[hash_32[1678]]);
	hash_64[847] = *((uint64_t*)&dataset[hash_32[1679]]);
#endif
#if MEMORY_THREADS > 53
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[848] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[849] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[850] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[851] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[852] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[853] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[854] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[855] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[848] = *((uint64_t*)&dataset[hash_32[1696]]);
	hash_64[849] = *((uint64_t*)&dataset[hash_32[1697]]);
	hash_64[850] = *((uint64_t*)&dataset[hash_32[1698]]);
	hash_64[851] = *((uint64_t*)&dataset[hash_32[1699]]);
	hash_64[852] = *((uint64_t*)&dataset[hash_32[1700]]);
	hash_64[853] = *((uint64_t*)&dataset[hash_32[1701]]);
	hash_64[854] = *((uint64_t*)&dataset[hash_32[1702]]);
	hash_64[855] = *((uint64_t*)&dataset[hash_32[1703]]);
	hash_64[856] = *((uint64_t*)&dataset[hash_32[1704]]);
	hash_64[857] = *((uint64_t*)&dataset[hash_32[1705]]);
	hash_64[858] = *((uint64_t*)&dataset[hash_32[1706]]);
	hash_64[859] = *((uint64_t*)&dataset[hash_32[1707]]);
	hash_64[860] = *((uint64_t*)&dataset[hash_32[1708]]);
	hash_64[861] = *((uint64_t*)&dataset[hash_32[1709]]);
	hash_64[862] = *((uint64_t*)&dataset[hash_32[1710]]);
	hash_64[863] = *((uint64_t*)&dataset[hash_32[1711]]);
#endif
#if MEMORY_THREADS > 54
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[864] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[865] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[866] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[867] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[868] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[869] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[870] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[871] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[864] = *((uint64_t*)&dataset[hash_32[1728]]);
	hash_64[865] = *((uint64_t*)&dataset[hash_32[1729]]);
	hash_64[866] = *((uint64_t*)&dataset[hash_32[1730]]);
	hash_64[867] = *((uint64_t*)&dataset[hash_32[1731]]);
	hash_64[868] = *((uint64_t*)&dataset[hash_32[1732]]);
	hash_64[869] = *((uint64_t*)&dataset[hash_32[1733]]);
	hash_64[870] = *((uint64_t*)&dataset[hash_32[1734]]);
	hash_64[871] = *((uint64_t*)&dataset[hash_32[1735]]);
	hash_64[872] = *((uint64_t*)&dataset[hash_32[1736]]);
	hash_64[873] = *((uint64_t*)&dataset[hash_32[1737]]);
	hash_64[874] = *((uint64_t*)&dataset[hash_32[1738]]);
	hash_64[875] = *((uint64_t*)&dataset[hash_32[1739]]);
	hash_64[876] = *((uint64_t*)&dataset[hash_32[1740]]);
	hash_64[877] = *((uint64_t*)&dataset[hash_32[1741]]);
	hash_64[878] = *((uint64_t*)&dataset[hash_32[1742]]);
	hash_64[879] = *((uint64_t*)&dataset[hash_32[1743]]);
#endif
#if MEMORY_THREADS > 55
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[880] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[881] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[882] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[883] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[884] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[885] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[886] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[887] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[880] = *((uint64_t*)&dataset[hash_32[1760]]);
	hash_64[881] = *((uint64_t*)&dataset[hash_32[1761]]);
	hash_64[882] = *((uint64_t*)&dataset[hash_32[1762]]);
	hash_64[883] = *((uint64_t*)&dataset[hash_32[1763]]);
	hash_64[884] = *((uint64_t*)&dataset[hash_32[1764]]);
	hash_64[885] = *((uint64_t*)&dataset[hash_32[1765]]);
	hash_64[886] = *((uint64_t*)&dataset[hash_32[1766]]);
	hash_64[887] = *((uint64_t*)&dataset[hash_32[1767]]);
	hash_64[888] = *((uint64_t*)&dataset[hash_32[1768]]);
	hash_64[889] = *((uint64_t*)&dataset[hash_32[1769]]);
	hash_64[890] = *((uint64_t*)&dataset[hash_32[1770]]);
	hash_64[891] = *((uint64_t*)&dataset[hash_32[1771]]);
	hash_64[892] = *((uint64_t*)&dataset[hash_32[1772]]);
	hash_64[893] = *((uint64_t*)&dataset[hash_32[1773]]);
	hash_64[894] = *((uint64_t*)&dataset[hash_32[1774]]);
	hash_64[895] = *((uint64_t*)&dataset[hash_32[1775]]);
#endif
#if MEMORY_THREADS > 56
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[896] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[897] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[898] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[899] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[900] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[901] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[902] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[903] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[896] = *((uint64_t*)&dataset[hash_32[1792]]);
	hash_64[897] = *((uint64_t*)&dataset[hash_32[1793]]);
	hash_64[898] = *((uint64_t*)&dataset[hash_32[1794]]);
	hash_64[899] = *((uint64_t*)&dataset[hash_32[1795]]);
	hash_64[900] = *((uint64_t*)&dataset[hash_32[1796]]);
	hash_64[901] = *((uint64_t*)&dataset[hash_32[1797]]);
	hash_64[902] = *((uint64_t*)&dataset[hash_32[1798]]);
	hash_64[903] = *((uint64_t*)&dataset[hash_32[1799]]);
	hash_64[904] = *((uint64_t*)&dataset[hash_32[1800]]);
	hash_64[905] = *((uint64_t*)&dataset[hash_32[1801]]);
	hash_64[906] = *((uint64_t*)&dataset[hash_32[1802]]);
	hash_64[907] = *((uint64_t*)&dataset[hash_32[1803]]);
	hash_64[908] = *((uint64_t*)&dataset[hash_32[1804]]);
	hash_64[909] = *((uint64_t*)&dataset[hash_32[1805]]);
	hash_64[910] = *((uint64_t*)&dataset[hash_32[1806]]);
	hash_64[911] = *((uint64_t*)&dataset[hash_32[1807]]);
#endif
#if MEMORY_THREADS > 57
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[912] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[913] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[914] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[915] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[916] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[917] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[918] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[919] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[912] = *((uint64_t*)&dataset[hash_32[1824]]);
	hash_64[913] = *((uint64_t*)&dataset[hash_32[1825]]);
	hash_64[914] = *((uint64_t*)&dataset[hash_32[1826]]);
	hash_64[915] = *((uint64_t*)&dataset[hash_32[1827]]);
	hash_64[916] = *((uint64_t*)&dataset[hash_32[1828]]);
	hash_64[917] = *((uint64_t*)&dataset[hash_32[1829]]);
	hash_64[918] = *((uint64_t*)&dataset[hash_32[1830]]);
	hash_64[919] = *((uint64_t*)&dataset[hash_32[1831]]);
	hash_64[920] = *((uint64_t*)&dataset[hash_32[1832]]);
	hash_64[921] = *((uint64_t*)&dataset[hash_32[1833]]);
	hash_64[922] = *((uint64_t*)&dataset[hash_32[1834]]);
	hash_64[923] = *((uint64_t*)&dataset[hash_32[1835]]);
	hash_64[924] = *((uint64_t*)&dataset[hash_32[1836]]);
	hash_64[925] = *((uint64_t*)&dataset[hash_32[1837]]);
	hash_64[926] = *((uint64_t*)&dataset[hash_32[1838]]);
	hash_64[927] = *((uint64_t*)&dataset[hash_32[1839]]);
#endif
#if MEMORY_THREADS > 58
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[928] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[929] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[930] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[931] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[932] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[933] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[934] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[935] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[928] = *((uint64_t*)&dataset[hash_32[1856]]);
	hash_64[929] = *((uint64_t*)&dataset[hash_32[1857]]);
	hash_64[930] = *((uint64_t*)&dataset[hash_32[1858]]);
	hash_64[931] = *((uint64_t*)&dataset[hash_32[1859]]);
	hash_64[932] = *((uint64_t*)&dataset[hash_32[1860]]);
	hash_64[933] = *((uint64_t*)&dataset[hash_32[1861]]);
	hash_64[934] = *((uint64_t*)&dataset[hash_32[1862]]);
	hash_64[935] = *((uint64_t*)&dataset[hash_32[1863]]);
	hash_64[936] = *((uint64_t*)&dataset[hash_32[1864]]);
	hash_64[937] = *((uint64_t*)&dataset[hash_32[1865]]);
	hash_64[938] = *((uint64_t*)&dataset[hash_32[1866]]);
	hash_64[939] = *((uint64_t*)&dataset[hash_32[1867]]);
	hash_64[940] = *((uint64_t*)&dataset[hash_32[1868]]);
	hash_64[941] = *((uint64_t*)&dataset[hash_32[1869]]);
	hash_64[942] = *((uint64_t*)&dataset[hash_32[1870]]);
	hash_64[943] = *((uint64_t*)&dataset[hash_32[1871]]);
#endif
#if MEMORY_THREADS > 59
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[944] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[945] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[946] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[947] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[948] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[949] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[950] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[951] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[944] = *((uint64_t*)&dataset[hash_32[1888]]);
	hash_64[945] = *((uint64_t*)&dataset[hash_32[1889]]);
	hash_64[946] = *((uint64_t*)&dataset[hash_32[1890]]);
	hash_64[947] = *((uint64_t*)&dataset[hash_32[1891]]);
	hash_64[948] = *((uint64_t*)&dataset[hash_32[1892]]);
	hash_64[949] = *((uint64_t*)&dataset[hash_32[1893]]);
	hash_64[950] = *((uint64_t*)&dataset[hash_32[1894]]);
	hash_64[951] = *((uint64_t*)&dataset[hash_32[1895]]);
	hash_64[952] = *((uint64_t*)&dataset[hash_32[1896]]);
	hash_64[953] = *((uint64_t*)&dataset[hash_32[1897]]);
	hash_64[954] = *((uint64_t*)&dataset[hash_32[1898]]);
	hash_64[955] = *((uint64_t*)&dataset[hash_32[1899]]);
	hash_64[956] = *((uint64_t*)&dataset[hash_32[1900]]);
	hash_64[957] = *((uint64_t*)&dataset[hash_32[1901]]);
	hash_64[958] = *((uint64_t*)&dataset[hash_32[1902]]);
	hash_64[959] = *((uint64_t*)&dataset[hash_32[1903]]);
#endif
#if MEMORY_THREADS > 60
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[960] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[961] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[962] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[963] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[964] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[965] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[966] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[967] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[960] = *((uint64_t*)&dataset[hash_32[1920]]);
	hash_64[961] = *((uint64_t*)&dataset[hash_32[1921]]);
	hash_64[962] = *((uint64_t*)&dataset[hash_32[1922]]);
	hash_64[963] = *((uint64_t*)&dataset[hash_32[1923]]);
	hash_64[964] = *((uint64_t*)&dataset[hash_32[1924]]);
	hash_64[965] = *((uint64_t*)&dataset[hash_32[1925]]);
	hash_64[966] = *((uint64_t*)&dataset[hash_32[1926]]);
	hash_64[967] = *((uint64_t*)&dataset[hash_32[1927]]);
	hash_64[968] = *((uint64_t*)&dataset[hash_32[1928]]);
	hash_64[969] = *((uint64_t*)&dataset[hash_32[1929]]);
	hash_64[970] = *((uint64_t*)&dataset[hash_32[1930]]);
	hash_64[971] = *((uint64_t*)&dataset[hash_32[1931]]);
	hash_64[972] = *((uint64_t*)&dataset[hash_32[1932]]);
	hash_64[973] = *((uint64_t*)&dataset[hash_32[1933]]);
	hash_64[974] = *((uint64_t*)&dataset[hash_32[1934]]);
	hash_64[975] = *((uint64_t*)&dataset[hash_32[1935]]);
#endif
#if MEMORY_THREADS > 61
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[976] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[977] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[978] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[979] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[980] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[981] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[982] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[983] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[976] = *((uint64_t*)&dataset[hash_32[1952]]);
	hash_64[977] = *((uint64_t*)&dataset[hash_32[1953]]);
	hash_64[978] = *((uint64_t*)&dataset[hash_32[1954]]);
	hash_64[979] = *((uint64_t*)&dataset[hash_32[1955]]);
	hash_64[980] = *((uint64_t*)&dataset[hash_32[1956]]);
	hash_64[981] = *((uint64_t*)&dataset[hash_32[1957]]);
	hash_64[982] = *((uint64_t*)&dataset[hash_32[1958]]);
	hash_64[983] = *((uint64_t*)&dataset[hash_32[1959]]);
	hash_64[984] = *((uint64_t*)&dataset[hash_32[1960]]);
	hash_64[985] = *((uint64_t*)&dataset[hash_32[1961]]);
	hash_64[986] = *((uint64_t*)&dataset[hash_32[1962]]);
	hash_64[987] = *((uint64_t*)&dataset[hash_32[1963]]);
	hash_64[988] = *((uint64_t*)&dataset[hash_32[1964]]);
	hash_64[989] = *((uint64_t*)&dataset[hash_32[1965]]);
	hash_64[990] = *((uint64_t*)&dataset[hash_32[1966]]);
	hash_64[991] = *((uint64_t*)&dataset[hash_32[1967]]);
#endif
#if MEMORY_THREADS > 62
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[992] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[993] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[994] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[995] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[996] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[997] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[998] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[999] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[992] = *((uint64_t*)&dataset[hash_32[1984]]);
	hash_64[993] = *((uint64_t*)&dataset[hash_32[1985]]);
	hash_64[994] = *((uint64_t*)&dataset[hash_32[1986]]);
	hash_64[995] = *((uint64_t*)&dataset[hash_32[1987]]);
	hash_64[996] = *((uint64_t*)&dataset[hash_32[1988]]);
	hash_64[997] = *((uint64_t*)&dataset[hash_32[1989]]);
	hash_64[998] = *((uint64_t*)&dataset[hash_32[1990]]);
	hash_64[999] = *((uint64_t*)&dataset[hash_32[1991]]);
	hash_64[1000] = *((uint64_t*)&dataset[hash_32[1992]]);
	hash_64[1001] = *((uint64_t*)&dataset[hash_32[1993]]);
	hash_64[1002] = *((uint64_t*)&dataset[hash_32[1994]]);
	hash_64[1003] = *((uint64_t*)&dataset[hash_32[1995]]);
	hash_64[1004] = *((uint64_t*)&dataset[hash_32[1996]]);
	hash_64[1005] = *((uint64_t*)&dataset[hash_32[1997]]);
	hash_64[1006] = *((uint64_t*)&dataset[hash_32[1998]]);
	hash_64[1007] = *((uint64_t*)&dataset[hash_32[1999]]);
#endif
#if MEMORY_THREADS > 63
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1008] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1009] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1010] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1011] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1012] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1013] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1014] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1015] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1008] = *((uint64_t*)&dataset[hash_32[2016]]);
	hash_64[1009] = *((uint64_t*)&dataset[hash_32[2017]]);
	hash_64[1010] = *((uint64_t*)&dataset[hash_32[2018]]);
	hash_64[1011] = *((uint64_t*)&dataset[hash_32[2019]]);
	hash_64[1012] = *((uint64_t*)&dataset[hash_32[2020]]);
	hash_64[1013] = *((uint64_t*)&dataset[hash_32[2021]]);
	hash_64[1014] = *((uint64_t*)&dataset[hash_32[2022]]);
	hash_64[1015] = *((uint64_t*)&dataset[hash_32[2023]]);
	hash_64[1016] = *((uint64_t*)&dataset[hash_32[2024]]);
	hash_64[1017] = *((uint64_t*)&dataset[hash_32[2025]]);
	hash_64[1018] = *((uint64_t*)&dataset[hash_32[2026]]);
	hash_64[1019] = *((uint64_t*)&dataset[hash_32[2027]]);
	hash_64[1020] = *((uint64_t*)&dataset[hash_32[2028]]);
	hash_64[1021] = *((uint64_t*)&dataset[hash_32[2029]]);
	hash_64[1022] = *((uint64_t*)&dataset[hash_32[2030]]);
	hash_64[1023] = *((uint64_t*)&dataset[hash_32[2031]]);
#endif
#if MEMORY_THREADS > 64
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1024] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1025] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1026] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1027] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1028] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1029] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1030] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1031] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1024] = *((uint64_t*)&dataset[hash_32[2048]]);
	hash_64[1025] = *((uint64_t*)&dataset[hash_32[2049]]);
	hash_64[1026] = *((uint64_t*)&dataset[hash_32[2050]]);
	hash_64[1027] = *((uint64_t*)&dataset[hash_32[2051]]);
	hash_64[1028] = *((uint64_t*)&dataset[hash_32[2052]]);
	hash_64[1029] = *((uint64_t*)&dataset[hash_32[2053]]);
	hash_64[1030] = *((uint64_t*)&dataset[hash_32[2054]]);
	hash_64[1031] = *((uint64_t*)&dataset[hash_32[2055]]);
	hash_64[1032] = *((uint64_t*)&dataset[hash_32[2056]]);
	hash_64[1033] = *((uint64_t*)&dataset[hash_32[2057]]);
	hash_64[1034] = *((uint64_t*)&dataset[hash_32[2058]]);
	hash_64[1035] = *((uint64_t*)&dataset[hash_32[2059]]);
	hash_64[1036] = *((uint64_t*)&dataset[hash_32[2060]]);
	hash_64[1037] = *((uint64_t*)&dataset[hash_32[2061]]);
	hash_64[1038] = *((uint64_t*)&dataset[hash_32[2062]]);
	hash_64[1039] = *((uint64_t*)&dataset[hash_32[2063]]);
#endif
#if MEMORY_THREADS > 65
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1040] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1041] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1042] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1043] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1044] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1045] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1046] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1047] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1040] = *((uint64_t*)&dataset[hash_32[2080]]);
	hash_64[1041] = *((uint64_t*)&dataset[hash_32[2081]]);
	hash_64[1042] = *((uint64_t*)&dataset[hash_32[2082]]);
	hash_64[1043] = *((uint64_t*)&dataset[hash_32[2083]]);
	hash_64[1044] = *((uint64_t*)&dataset[hash_32[2084]]);
	hash_64[1045] = *((uint64_t*)&dataset[hash_32[2085]]);
	hash_64[1046] = *((uint64_t*)&dataset[hash_32[2086]]);
	hash_64[1047] = *((uint64_t*)&dataset[hash_32[2087]]);
	hash_64[1048] = *((uint64_t*)&dataset[hash_32[2088]]);
	hash_64[1049] = *((uint64_t*)&dataset[hash_32[2089]]);
	hash_64[1050] = *((uint64_t*)&dataset[hash_32[2090]]);
	hash_64[1051] = *((uint64_t*)&dataset[hash_32[2091]]);
	hash_64[1052] = *((uint64_t*)&dataset[hash_32[2092]]);
	hash_64[1053] = *((uint64_t*)&dataset[hash_32[2093]]);
	hash_64[1054] = *((uint64_t*)&dataset[hash_32[2094]]);
	hash_64[1055] = *((uint64_t*)&dataset[hash_32[2095]]);
#endif
#if MEMORY_THREADS > 66
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1056] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1057] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1058] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1059] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1060] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1061] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1062] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1063] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1056] = *((uint64_t*)&dataset[hash_32[2112]]);
	hash_64[1057] = *((uint64_t*)&dataset[hash_32[2113]]);
	hash_64[1058] = *((uint64_t*)&dataset[hash_32[2114]]);
	hash_64[1059] = *((uint64_t*)&dataset[hash_32[2115]]);
	hash_64[1060] = *((uint64_t*)&dataset[hash_32[2116]]);
	hash_64[1061] = *((uint64_t*)&dataset[hash_32[2117]]);
	hash_64[1062] = *((uint64_t*)&dataset[hash_32[2118]]);
	hash_64[1063] = *((uint64_t*)&dataset[hash_32[2119]]);
	hash_64[1064] = *((uint64_t*)&dataset[hash_32[2120]]);
	hash_64[1065] = *((uint64_t*)&dataset[hash_32[2121]]);
	hash_64[1066] = *((uint64_t*)&dataset[hash_32[2122]]);
	hash_64[1067] = *((uint64_t*)&dataset[hash_32[2123]]);
	hash_64[1068] = *((uint64_t*)&dataset[hash_32[2124]]);
	hash_64[1069] = *((uint64_t*)&dataset[hash_32[2125]]);
	hash_64[1070] = *((uint64_t*)&dataset[hash_32[2126]]);
	hash_64[1071] = *((uint64_t*)&dataset[hash_32[2127]]);
#endif
#if MEMORY_THREADS > 67
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1072] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1073] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1074] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1075] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1076] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1077] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1078] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1079] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1072] = *((uint64_t*)&dataset[hash_32[2144]]);
	hash_64[1073] = *((uint64_t*)&dataset[hash_32[2145]]);
	hash_64[1074] = *((uint64_t*)&dataset[hash_32[2146]]);
	hash_64[1075] = *((uint64_t*)&dataset[hash_32[2147]]);
	hash_64[1076] = *((uint64_t*)&dataset[hash_32[2148]]);
	hash_64[1077] = *((uint64_t*)&dataset[hash_32[2149]]);
	hash_64[1078] = *((uint64_t*)&dataset[hash_32[2150]]);
	hash_64[1079] = *((uint64_t*)&dataset[hash_32[2151]]);
	hash_64[1080] = *((uint64_t*)&dataset[hash_32[2152]]);
	hash_64[1081] = *((uint64_t*)&dataset[hash_32[2153]]);
	hash_64[1082] = *((uint64_t*)&dataset[hash_32[2154]]);
	hash_64[1083] = *((uint64_t*)&dataset[hash_32[2155]]);
	hash_64[1084] = *((uint64_t*)&dataset[hash_32[2156]]);
	hash_64[1085] = *((uint64_t*)&dataset[hash_32[2157]]);
	hash_64[1086] = *((uint64_t*)&dataset[hash_32[2158]]);
	hash_64[1087] = *((uint64_t*)&dataset[hash_32[2159]]);
#endif
#if MEMORY_THREADS > 68
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1088] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1089] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1090] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1091] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1092] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1093] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1094] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1095] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1088] = *((uint64_t*)&dataset[hash_32[2176]]);
	hash_64[1089] = *((uint64_t*)&dataset[hash_32[2177]]);
	hash_64[1090] = *((uint64_t*)&dataset[hash_32[2178]]);
	hash_64[1091] = *((uint64_t*)&dataset[hash_32[2179]]);
	hash_64[1092] = *((uint64_t*)&dataset[hash_32[2180]]);
	hash_64[1093] = *((uint64_t*)&dataset[hash_32[2181]]);
	hash_64[1094] = *((uint64_t*)&dataset[hash_32[2182]]);
	hash_64[1095] = *((uint64_t*)&dataset[hash_32[2183]]);
	hash_64[1096] = *((uint64_t*)&dataset[hash_32[2184]]);
	hash_64[1097] = *((uint64_t*)&dataset[hash_32[2185]]);
	hash_64[1098] = *((uint64_t*)&dataset[hash_32[2186]]);
	hash_64[1099] = *((uint64_t*)&dataset[hash_32[2187]]);
	hash_64[1100] = *((uint64_t*)&dataset[hash_32[2188]]);
	hash_64[1101] = *((uint64_t*)&dataset[hash_32[2189]]);
	hash_64[1102] = *((uint64_t*)&dataset[hash_32[2190]]);
	hash_64[1103] = *((uint64_t*)&dataset[hash_32[2191]]);
#endif
#if MEMORY_THREADS > 69
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1104] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1105] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1106] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1107] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1108] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1109] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1110] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1111] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1104] = *((uint64_t*)&dataset[hash_32[2208]]);
	hash_64[1105] = *((uint64_t*)&dataset[hash_32[2209]]);
	hash_64[1106] = *((uint64_t*)&dataset[hash_32[2210]]);
	hash_64[1107] = *((uint64_t*)&dataset[hash_32[2211]]);
	hash_64[1108] = *((uint64_t*)&dataset[hash_32[2212]]);
	hash_64[1109] = *((uint64_t*)&dataset[hash_32[2213]]);
	hash_64[1110] = *((uint64_t*)&dataset[hash_32[2214]]);
	hash_64[1111] = *((uint64_t*)&dataset[hash_32[2215]]);
	hash_64[1112] = *((uint64_t*)&dataset[hash_32[2216]]);
	hash_64[1113] = *((uint64_t*)&dataset[hash_32[2217]]);
	hash_64[1114] = *((uint64_t*)&dataset[hash_32[2218]]);
	hash_64[1115] = *((uint64_t*)&dataset[hash_32[2219]]);
	hash_64[1116] = *((uint64_t*)&dataset[hash_32[2220]]);
	hash_64[1117] = *((uint64_t*)&dataset[hash_32[2221]]);
	hash_64[1118] = *((uint64_t*)&dataset[hash_32[2222]]);
	hash_64[1119] = *((uint64_t*)&dataset[hash_32[2223]]);
#endif
#if MEMORY_THREADS > 70
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1120] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1121] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1122] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1123] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1124] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1125] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1126] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1127] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1120] = *((uint64_t*)&dataset[hash_32[2240]]);
	hash_64[1121] = *((uint64_t*)&dataset[hash_32[2241]]);
	hash_64[1122] = *((uint64_t*)&dataset[hash_32[2242]]);
	hash_64[1123] = *((uint64_t*)&dataset[hash_32[2243]]);
	hash_64[1124] = *((uint64_t*)&dataset[hash_32[2244]]);
	hash_64[1125] = *((uint64_t*)&dataset[hash_32[2245]]);
	hash_64[1126] = *((uint64_t*)&dataset[hash_32[2246]]);
	hash_64[1127] = *((uint64_t*)&dataset[hash_32[2247]]);
	hash_64[1128] = *((uint64_t*)&dataset[hash_32[2248]]);
	hash_64[1129] = *((uint64_t*)&dataset[hash_32[2249]]);
	hash_64[1130] = *((uint64_t*)&dataset[hash_32[2250]]);
	hash_64[1131] = *((uint64_t*)&dataset[hash_32[2251]]);
	hash_64[1132] = *((uint64_t*)&dataset[hash_32[2252]]);
	hash_64[1133] = *((uint64_t*)&dataset[hash_32[2253]]);
	hash_64[1134] = *((uint64_t*)&dataset[hash_32[2254]]);
	hash_64[1135] = *((uint64_t*)&dataset[hash_32[2255]]);
#endif
#if MEMORY_THREADS > 71
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1136] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1137] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1138] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1139] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1140] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1141] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1142] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1143] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1136] = *((uint64_t*)&dataset[hash_32[2272]]);
	hash_64[1137] = *((uint64_t*)&dataset[hash_32[2273]]);
	hash_64[1138] = *((uint64_t*)&dataset[hash_32[2274]]);
	hash_64[1139] = *((uint64_t*)&dataset[hash_32[2275]]);
	hash_64[1140] = *((uint64_t*)&dataset[hash_32[2276]]);
	hash_64[1141] = *((uint64_t*)&dataset[hash_32[2277]]);
	hash_64[1142] = *((uint64_t*)&dataset[hash_32[2278]]);
	hash_64[1143] = *((uint64_t*)&dataset[hash_32[2279]]);
	hash_64[1144] = *((uint64_t*)&dataset[hash_32[2280]]);
	hash_64[1145] = *((uint64_t*)&dataset[hash_32[2281]]);
	hash_64[1146] = *((uint64_t*)&dataset[hash_32[2282]]);
	hash_64[1147] = *((uint64_t*)&dataset[hash_32[2283]]);
	hash_64[1148] = *((uint64_t*)&dataset[hash_32[2284]]);
	hash_64[1149] = *((uint64_t*)&dataset[hash_32[2285]]);
	hash_64[1150] = *((uint64_t*)&dataset[hash_32[2286]]);
	hash_64[1151] = *((uint64_t*)&dataset[hash_32[2287]]);
#endif
#if MEMORY_THREADS > 72
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1152] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1153] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1154] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1155] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1156] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1157] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1158] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1159] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1152] = *((uint64_t*)&dataset[hash_32[2304]]);
	hash_64[1153] = *((uint64_t*)&dataset[hash_32[2305]]);
	hash_64[1154] = *((uint64_t*)&dataset[hash_32[2306]]);
	hash_64[1155] = *((uint64_t*)&dataset[hash_32[2307]]);
	hash_64[1156] = *((uint64_t*)&dataset[hash_32[2308]]);
	hash_64[1157] = *((uint64_t*)&dataset[hash_32[2309]]);
	hash_64[1158] = *((uint64_t*)&dataset[hash_32[2310]]);
	hash_64[1159] = *((uint64_t*)&dataset[hash_32[2311]]);
	hash_64[1160] = *((uint64_t*)&dataset[hash_32[2312]]);
	hash_64[1161] = *((uint64_t*)&dataset[hash_32[2313]]);
	hash_64[1162] = *((uint64_t*)&dataset[hash_32[2314]]);
	hash_64[1163] = *((uint64_t*)&dataset[hash_32[2315]]);
	hash_64[1164] = *((uint64_t*)&dataset[hash_32[2316]]);
	hash_64[1165] = *((uint64_t*)&dataset[hash_32[2317]]);
	hash_64[1166] = *((uint64_t*)&dataset[hash_32[2318]]);
	hash_64[1167] = *((uint64_t*)&dataset[hash_32[2319]]);
#endif
#if MEMORY_THREADS > 73
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1168] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1169] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1170] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1171] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1172] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1173] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1174] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1175] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1168] = *((uint64_t*)&dataset[hash_32[2336]]);
	hash_64[1169] = *((uint64_t*)&dataset[hash_32[2337]]);
	hash_64[1170] = *((uint64_t*)&dataset[hash_32[2338]]);
	hash_64[1171] = *((uint64_t*)&dataset[hash_32[2339]]);
	hash_64[1172] = *((uint64_t*)&dataset[hash_32[2340]]);
	hash_64[1173] = *((uint64_t*)&dataset[hash_32[2341]]);
	hash_64[1174] = *((uint64_t*)&dataset[hash_32[2342]]);
	hash_64[1175] = *((uint64_t*)&dataset[hash_32[2343]]);
	hash_64[1176] = *((uint64_t*)&dataset[hash_32[2344]]);
	hash_64[1177] = *((uint64_t*)&dataset[hash_32[2345]]);
	hash_64[1178] = *((uint64_t*)&dataset[hash_32[2346]]);
	hash_64[1179] = *((uint64_t*)&dataset[hash_32[2347]]);
	hash_64[1180] = *((uint64_t*)&dataset[hash_32[2348]]);
	hash_64[1181] = *((uint64_t*)&dataset[hash_32[2349]]);
	hash_64[1182] = *((uint64_t*)&dataset[hash_32[2350]]);
	hash_64[1183] = *((uint64_t*)&dataset[hash_32[2351]]);
#endif
#if MEMORY_THREADS > 74
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1184] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1185] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1186] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1187] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1188] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1189] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1190] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1191] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1184] = *((uint64_t*)&dataset[hash_32[2368]]);
	hash_64[1185] = *((uint64_t*)&dataset[hash_32[2369]]);
	hash_64[1186] = *((uint64_t*)&dataset[hash_32[2370]]);
	hash_64[1187] = *((uint64_t*)&dataset[hash_32[2371]]);
	hash_64[1188] = *((uint64_t*)&dataset[hash_32[2372]]);
	hash_64[1189] = *((uint64_t*)&dataset[hash_32[2373]]);
	hash_64[1190] = *((uint64_t*)&dataset[hash_32[2374]]);
	hash_64[1191] = *((uint64_t*)&dataset[hash_32[2375]]);
	hash_64[1192] = *((uint64_t*)&dataset[hash_32[2376]]);
	hash_64[1193] = *((uint64_t*)&dataset[hash_32[2377]]);
	hash_64[1194] = *((uint64_t*)&dataset[hash_32[2378]]);
	hash_64[1195] = *((uint64_t*)&dataset[hash_32[2379]]);
	hash_64[1196] = *((uint64_t*)&dataset[hash_32[2380]]);
	hash_64[1197] = *((uint64_t*)&dataset[hash_32[2381]]);
	hash_64[1198] = *((uint64_t*)&dataset[hash_32[2382]]);
	hash_64[1199] = *((uint64_t*)&dataset[hash_32[2383]]);
#endif
#if MEMORY_THREADS > 75
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1200] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1201] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1202] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1203] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1204] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1205] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1206] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1207] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1200] = *((uint64_t*)&dataset[hash_32[2400]]);
	hash_64[1201] = *((uint64_t*)&dataset[hash_32[2401]]);
	hash_64[1202] = *((uint64_t*)&dataset[hash_32[2402]]);
	hash_64[1203] = *((uint64_t*)&dataset[hash_32[2403]]);
	hash_64[1204] = *((uint64_t*)&dataset[hash_32[2404]]);
	hash_64[1205] = *((uint64_t*)&dataset[hash_32[2405]]);
	hash_64[1206] = *((uint64_t*)&dataset[hash_32[2406]]);
	hash_64[1207] = *((uint64_t*)&dataset[hash_32[2407]]);
	hash_64[1208] = *((uint64_t*)&dataset[hash_32[2408]]);
	hash_64[1209] = *((uint64_t*)&dataset[hash_32[2409]]);
	hash_64[1210] = *((uint64_t*)&dataset[hash_32[2410]]);
	hash_64[1211] = *((uint64_t*)&dataset[hash_32[2411]]);
	hash_64[1212] = *((uint64_t*)&dataset[hash_32[2412]]);
	hash_64[1213] = *((uint64_t*)&dataset[hash_32[2413]]);
	hash_64[1214] = *((uint64_t*)&dataset[hash_32[2414]]);
	hash_64[1215] = *((uint64_t*)&dataset[hash_32[2415]]);
#endif
#if MEMORY_THREADS > 76
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1216] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1217] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1218] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1219] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1220] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1221] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1222] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1223] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1216] = *((uint64_t*)&dataset[hash_32[2432]]);
	hash_64[1217] = *((uint64_t*)&dataset[hash_32[2433]]);
	hash_64[1218] = *((uint64_t*)&dataset[hash_32[2434]]);
	hash_64[1219] = *((uint64_t*)&dataset[hash_32[2435]]);
	hash_64[1220] = *((uint64_t*)&dataset[hash_32[2436]]);
	hash_64[1221] = *((uint64_t*)&dataset[hash_32[2437]]);
	hash_64[1222] = *((uint64_t*)&dataset[hash_32[2438]]);
	hash_64[1223] = *((uint64_t*)&dataset[hash_32[2439]]);
	hash_64[1224] = *((uint64_t*)&dataset[hash_32[2440]]);
	hash_64[1225] = *((uint64_t*)&dataset[hash_32[2441]]);
	hash_64[1226] = *((uint64_t*)&dataset[hash_32[2442]]);
	hash_64[1227] = *((uint64_t*)&dataset[hash_32[2443]]);
	hash_64[1228] = *((uint64_t*)&dataset[hash_32[2444]]);
	hash_64[1229] = *((uint64_t*)&dataset[hash_32[2445]]);
	hash_64[1230] = *((uint64_t*)&dataset[hash_32[2446]]);
	hash_64[1231] = *((uint64_t*)&dataset[hash_32[2447]]);
#endif
#if MEMORY_THREADS > 77
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1232] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1233] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1234] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1235] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1236] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1237] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1238] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1239] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1232] = *((uint64_t*)&dataset[hash_32[2464]]);
	hash_64[1233] = *((uint64_t*)&dataset[hash_32[2465]]);
	hash_64[1234] = *((uint64_t*)&dataset[hash_32[2466]]);
	hash_64[1235] = *((uint64_t*)&dataset[hash_32[2467]]);
	hash_64[1236] = *((uint64_t*)&dataset[hash_32[2468]]);
	hash_64[1237] = *((uint64_t*)&dataset[hash_32[2469]]);
	hash_64[1238] = *((uint64_t*)&dataset[hash_32[2470]]);
	hash_64[1239] = *((uint64_t*)&dataset[hash_32[2471]]);
	hash_64[1240] = *((uint64_t*)&dataset[hash_32[2472]]);
	hash_64[1241] = *((uint64_t*)&dataset[hash_32[2473]]);
	hash_64[1242] = *((uint64_t*)&dataset[hash_32[2474]]);
	hash_64[1243] = *((uint64_t*)&dataset[hash_32[2475]]);
	hash_64[1244] = *((uint64_t*)&dataset[hash_32[2476]]);
	hash_64[1245] = *((uint64_t*)&dataset[hash_32[2477]]);
	hash_64[1246] = *((uint64_t*)&dataset[hash_32[2478]]);
	hash_64[1247] = *((uint64_t*)&dataset[hash_32[2479]]);
#endif
#if MEMORY_THREADS > 78
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1248] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1249] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1250] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1251] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1252] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1253] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1254] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1255] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1248] = *((uint64_t*)&dataset[hash_32[2496]]);
	hash_64[1249] = *((uint64_t*)&dataset[hash_32[2497]]);
	hash_64[1250] = *((uint64_t*)&dataset[hash_32[2498]]);
	hash_64[1251] = *((uint64_t*)&dataset[hash_32[2499]]);
	hash_64[1252] = *((uint64_t*)&dataset[hash_32[2500]]);
	hash_64[1253] = *((uint64_t*)&dataset[hash_32[2501]]);
	hash_64[1254] = *((uint64_t*)&dataset[hash_32[2502]]);
	hash_64[1255] = *((uint64_t*)&dataset[hash_32[2503]]);
	hash_64[1256] = *((uint64_t*)&dataset[hash_32[2504]]);
	hash_64[1257] = *((uint64_t*)&dataset[hash_32[2505]]);
	hash_64[1258] = *((uint64_t*)&dataset[hash_32[2506]]);
	hash_64[1259] = *((uint64_t*)&dataset[hash_32[2507]]);
	hash_64[1260] = *((uint64_t*)&dataset[hash_32[2508]]);
	hash_64[1261] = *((uint64_t*)&dataset[hash_32[2509]]);
	hash_64[1262] = *((uint64_t*)&dataset[hash_32[2510]]);
	hash_64[1263] = *((uint64_t*)&dataset[hash_32[2511]]);
#endif
#if MEMORY_THREADS > 79
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1264] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1265] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1266] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1267] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1268] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1269] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1270] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1271] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1264] = *((uint64_t*)&dataset[hash_32[2528]]);
	hash_64[1265] = *((uint64_t*)&dataset[hash_32[2529]]);
	hash_64[1266] = *((uint64_t*)&dataset[hash_32[2530]]);
	hash_64[1267] = *((uint64_t*)&dataset[hash_32[2531]]);
	hash_64[1268] = *((uint64_t*)&dataset[hash_32[2532]]);
	hash_64[1269] = *((uint64_t*)&dataset[hash_32[2533]]);
	hash_64[1270] = *((uint64_t*)&dataset[hash_32[2534]]);
	hash_64[1271] = *((uint64_t*)&dataset[hash_32[2535]]);
	hash_64[1272] = *((uint64_t*)&dataset[hash_32[2536]]);
	hash_64[1273] = *((uint64_t*)&dataset[hash_32[2537]]);
	hash_64[1274] = *((uint64_t*)&dataset[hash_32[2538]]);
	hash_64[1275] = *((uint64_t*)&dataset[hash_32[2539]]);
	hash_64[1276] = *((uint64_t*)&dataset[hash_32[2540]]);
	hash_64[1277] = *((uint64_t*)&dataset[hash_32[2541]]);
	hash_64[1278] = *((uint64_t*)&dataset[hash_32[2542]]);
	hash_64[1279] = *((uint64_t*)&dataset[hash_32[2543]]);
#endif
#if MEMORY_THREADS > 80
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1280] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1281] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1282] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1283] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1284] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1285] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1286] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1287] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1280] = *((uint64_t*)&dataset[hash_32[2560]]);
	hash_64[1281] = *((uint64_t*)&dataset[hash_32[2561]]);
	hash_64[1282] = *((uint64_t*)&dataset[hash_32[2562]]);
	hash_64[1283] = *((uint64_t*)&dataset[hash_32[2563]]);
	hash_64[1284] = *((uint64_t*)&dataset[hash_32[2564]]);
	hash_64[1285] = *((uint64_t*)&dataset[hash_32[2565]]);
	hash_64[1286] = *((uint64_t*)&dataset[hash_32[2566]]);
	hash_64[1287] = *((uint64_t*)&dataset[hash_32[2567]]);
	hash_64[1288] = *((uint64_t*)&dataset[hash_32[2568]]);
	hash_64[1289] = *((uint64_t*)&dataset[hash_32[2569]]);
	hash_64[1290] = *((uint64_t*)&dataset[hash_32[2570]]);
	hash_64[1291] = *((uint64_t*)&dataset[hash_32[2571]]);
	hash_64[1292] = *((uint64_t*)&dataset[hash_32[2572]]);
	hash_64[1293] = *((uint64_t*)&dataset[hash_32[2573]]);
	hash_64[1294] = *((uint64_t*)&dataset[hash_32[2574]]);
	hash_64[1295] = *((uint64_t*)&dataset[hash_32[2575]]);
#endif
#if MEMORY_THREADS > 81
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1296] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1297] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1298] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1299] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1300] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1301] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1302] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1303] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1296] = *((uint64_t*)&dataset[hash_32[2592]]);
	hash_64[1297] = *((uint64_t*)&dataset[hash_32[2593]]);
	hash_64[1298] = *((uint64_t*)&dataset[hash_32[2594]]);
	hash_64[1299] = *((uint64_t*)&dataset[hash_32[2595]]);
	hash_64[1300] = *((uint64_t*)&dataset[hash_32[2596]]);
	hash_64[1301] = *((uint64_t*)&dataset[hash_32[2597]]);
	hash_64[1302] = *((uint64_t*)&dataset[hash_32[2598]]);
	hash_64[1303] = *((uint64_t*)&dataset[hash_32[2599]]);
	hash_64[1304] = *((uint64_t*)&dataset[hash_32[2600]]);
	hash_64[1305] = *((uint64_t*)&dataset[hash_32[2601]]);
	hash_64[1306] = *((uint64_t*)&dataset[hash_32[2602]]);
	hash_64[1307] = *((uint64_t*)&dataset[hash_32[2603]]);
	hash_64[1308] = *((uint64_t*)&dataset[hash_32[2604]]);
	hash_64[1309] = *((uint64_t*)&dataset[hash_32[2605]]);
	hash_64[1310] = *((uint64_t*)&dataset[hash_32[2606]]);
	hash_64[1311] = *((uint64_t*)&dataset[hash_32[2607]]);
#endif
#if MEMORY_THREADS > 82
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1312] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1313] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1314] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1315] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1316] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1317] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1318] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1319] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1312] = *((uint64_t*)&dataset[hash_32[2624]]);
	hash_64[1313] = *((uint64_t*)&dataset[hash_32[2625]]);
	hash_64[1314] = *((uint64_t*)&dataset[hash_32[2626]]);
	hash_64[1315] = *((uint64_t*)&dataset[hash_32[2627]]);
	hash_64[1316] = *((uint64_t*)&dataset[hash_32[2628]]);
	hash_64[1317] = *((uint64_t*)&dataset[hash_32[2629]]);
	hash_64[1318] = *((uint64_t*)&dataset[hash_32[2630]]);
	hash_64[1319] = *((uint64_t*)&dataset[hash_32[2631]]);
	hash_64[1320] = *((uint64_t*)&dataset[hash_32[2632]]);
	hash_64[1321] = *((uint64_t*)&dataset[hash_32[2633]]);
	hash_64[1322] = *((uint64_t*)&dataset[hash_32[2634]]);
	hash_64[1323] = *((uint64_t*)&dataset[hash_32[2635]]);
	hash_64[1324] = *((uint64_t*)&dataset[hash_32[2636]]);
	hash_64[1325] = *((uint64_t*)&dataset[hash_32[2637]]);
	hash_64[1326] = *((uint64_t*)&dataset[hash_32[2638]]);
	hash_64[1327] = *((uint64_t*)&dataset[hash_32[2639]]);
#endif
#if MEMORY_THREADS > 83
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1328] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1329] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1330] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1331] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1332] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1333] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1334] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1335] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1328] = *((uint64_t*)&dataset[hash_32[2656]]);
	hash_64[1329] = *((uint64_t*)&dataset[hash_32[2657]]);
	hash_64[1330] = *((uint64_t*)&dataset[hash_32[2658]]);
	hash_64[1331] = *((uint64_t*)&dataset[hash_32[2659]]);
	hash_64[1332] = *((uint64_t*)&dataset[hash_32[2660]]);
	hash_64[1333] = *((uint64_t*)&dataset[hash_32[2661]]);
	hash_64[1334] = *((uint64_t*)&dataset[hash_32[2662]]);
	hash_64[1335] = *((uint64_t*)&dataset[hash_32[2663]]);
	hash_64[1336] = *((uint64_t*)&dataset[hash_32[2664]]);
	hash_64[1337] = *((uint64_t*)&dataset[hash_32[2665]]);
	hash_64[1338] = *((uint64_t*)&dataset[hash_32[2666]]);
	hash_64[1339] = *((uint64_t*)&dataset[hash_32[2667]]);
	hash_64[1340] = *((uint64_t*)&dataset[hash_32[2668]]);
	hash_64[1341] = *((uint64_t*)&dataset[hash_32[2669]]);
	hash_64[1342] = *((uint64_t*)&dataset[hash_32[2670]]);
	hash_64[1343] = *((uint64_t*)&dataset[hash_32[2671]]);
#endif
#if MEMORY_THREADS > 84
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1344] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1345] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1346] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1347] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1348] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1349] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1350] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1351] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1344] = *((uint64_t*)&dataset[hash_32[2688]]);
	hash_64[1345] = *((uint64_t*)&dataset[hash_32[2689]]);
	hash_64[1346] = *((uint64_t*)&dataset[hash_32[2690]]);
	hash_64[1347] = *((uint64_t*)&dataset[hash_32[2691]]);
	hash_64[1348] = *((uint64_t*)&dataset[hash_32[2692]]);
	hash_64[1349] = *((uint64_t*)&dataset[hash_32[2693]]);
	hash_64[1350] = *((uint64_t*)&dataset[hash_32[2694]]);
	hash_64[1351] = *((uint64_t*)&dataset[hash_32[2695]]);
	hash_64[1352] = *((uint64_t*)&dataset[hash_32[2696]]);
	hash_64[1353] = *((uint64_t*)&dataset[hash_32[2697]]);
	hash_64[1354] = *((uint64_t*)&dataset[hash_32[2698]]);
	hash_64[1355] = *((uint64_t*)&dataset[hash_32[2699]]);
	hash_64[1356] = *((uint64_t*)&dataset[hash_32[2700]]);
	hash_64[1357] = *((uint64_t*)&dataset[hash_32[2701]]);
	hash_64[1358] = *((uint64_t*)&dataset[hash_32[2702]]);
	hash_64[1359] = *((uint64_t*)&dataset[hash_32[2703]]);
#endif
#if MEMORY_THREADS > 85
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1360] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1361] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1362] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1363] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1364] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1365] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1366] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1367] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1360] = *((uint64_t*)&dataset[hash_32[2720]]);
	hash_64[1361] = *((uint64_t*)&dataset[hash_32[2721]]);
	hash_64[1362] = *((uint64_t*)&dataset[hash_32[2722]]);
	hash_64[1363] = *((uint64_t*)&dataset[hash_32[2723]]);
	hash_64[1364] = *((uint64_t*)&dataset[hash_32[2724]]);
	hash_64[1365] = *((uint64_t*)&dataset[hash_32[2725]]);
	hash_64[1366] = *((uint64_t*)&dataset[hash_32[2726]]);
	hash_64[1367] = *((uint64_t*)&dataset[hash_32[2727]]);
	hash_64[1368] = *((uint64_t*)&dataset[hash_32[2728]]);
	hash_64[1369] = *((uint64_t*)&dataset[hash_32[2729]]);
	hash_64[1370] = *((uint64_t*)&dataset[hash_32[2730]]);
	hash_64[1371] = *((uint64_t*)&dataset[hash_32[2731]]);
	hash_64[1372] = *((uint64_t*)&dataset[hash_32[2732]]);
	hash_64[1373] = *((uint64_t*)&dataset[hash_32[2733]]);
	hash_64[1374] = *((uint64_t*)&dataset[hash_32[2734]]);
	hash_64[1375] = *((uint64_t*)&dataset[hash_32[2735]]);
#endif
#if MEMORY_THREADS > 86
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1376] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1377] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1378] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1379] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1380] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1381] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1382] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1383] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1376] = *((uint64_t*)&dataset[hash_32[2752]]);
	hash_64[1377] = *((uint64_t*)&dataset[hash_32[2753]]);
	hash_64[1378] = *((uint64_t*)&dataset[hash_32[2754]]);
	hash_64[1379] = *((uint64_t*)&dataset[hash_32[2755]]);
	hash_64[1380] = *((uint64_t*)&dataset[hash_32[2756]]);
	hash_64[1381] = *((uint64_t*)&dataset[hash_32[2757]]);
	hash_64[1382] = *((uint64_t*)&dataset[hash_32[2758]]);
	hash_64[1383] = *((uint64_t*)&dataset[hash_32[2759]]);
	hash_64[1384] = *((uint64_t*)&dataset[hash_32[2760]]);
	hash_64[1385] = *((uint64_t*)&dataset[hash_32[2761]]);
	hash_64[1386] = *((uint64_t*)&dataset[hash_32[2762]]);
	hash_64[1387] = *((uint64_t*)&dataset[hash_32[2763]]);
	hash_64[1388] = *((uint64_t*)&dataset[hash_32[2764]]);
	hash_64[1389] = *((uint64_t*)&dataset[hash_32[2765]]);
	hash_64[1390] = *((uint64_t*)&dataset[hash_32[2766]]);
	hash_64[1391] = *((uint64_t*)&dataset[hash_32[2767]]);
#endif
#if MEMORY_THREADS > 87
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1392] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1393] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1394] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1395] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1396] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1397] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1398] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1399] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1392] = *((uint64_t*)&dataset[hash_32[2784]]);
	hash_64[1393] = *((uint64_t*)&dataset[hash_32[2785]]);
	hash_64[1394] = *((uint64_t*)&dataset[hash_32[2786]]);
	hash_64[1395] = *((uint64_t*)&dataset[hash_32[2787]]);
	hash_64[1396] = *((uint64_t*)&dataset[hash_32[2788]]);
	hash_64[1397] = *((uint64_t*)&dataset[hash_32[2789]]);
	hash_64[1398] = *((uint64_t*)&dataset[hash_32[2790]]);
	hash_64[1399] = *((uint64_t*)&dataset[hash_32[2791]]);
	hash_64[1400] = *((uint64_t*)&dataset[hash_32[2792]]);
	hash_64[1401] = *((uint64_t*)&dataset[hash_32[2793]]);
	hash_64[1402] = *((uint64_t*)&dataset[hash_32[2794]]);
	hash_64[1403] = *((uint64_t*)&dataset[hash_32[2795]]);
	hash_64[1404] = *((uint64_t*)&dataset[hash_32[2796]]);
	hash_64[1405] = *((uint64_t*)&dataset[hash_32[2797]]);
	hash_64[1406] = *((uint64_t*)&dataset[hash_32[2798]]);
	hash_64[1407] = *((uint64_t*)&dataset[hash_32[2799]]);
#endif
#if MEMORY_THREADS > 88
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1408] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1409] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1410] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1411] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1412] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1413] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1414] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1415] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1408] = *((uint64_t*)&dataset[hash_32[2816]]);
	hash_64[1409] = *((uint64_t*)&dataset[hash_32[2817]]);
	hash_64[1410] = *((uint64_t*)&dataset[hash_32[2818]]);
	hash_64[1411] = *((uint64_t*)&dataset[hash_32[2819]]);
	hash_64[1412] = *((uint64_t*)&dataset[hash_32[2820]]);
	hash_64[1413] = *((uint64_t*)&dataset[hash_32[2821]]);
	hash_64[1414] = *((uint64_t*)&dataset[hash_32[2822]]);
	hash_64[1415] = *((uint64_t*)&dataset[hash_32[2823]]);
	hash_64[1416] = *((uint64_t*)&dataset[hash_32[2824]]);
	hash_64[1417] = *((uint64_t*)&dataset[hash_32[2825]]);
	hash_64[1418] = *((uint64_t*)&dataset[hash_32[2826]]);
	hash_64[1419] = *((uint64_t*)&dataset[hash_32[2827]]);
	hash_64[1420] = *((uint64_t*)&dataset[hash_32[2828]]);
	hash_64[1421] = *((uint64_t*)&dataset[hash_32[2829]]);
	hash_64[1422] = *((uint64_t*)&dataset[hash_32[2830]]);
	hash_64[1423] = *((uint64_t*)&dataset[hash_32[2831]]);
#endif
#if MEMORY_THREADS > 89
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1424] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1425] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1426] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1427] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1428] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1429] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1430] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1431] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1424] = *((uint64_t*)&dataset[hash_32[2848]]);
	hash_64[1425] = *((uint64_t*)&dataset[hash_32[2849]]);
	hash_64[1426] = *((uint64_t*)&dataset[hash_32[2850]]);
	hash_64[1427] = *((uint64_t*)&dataset[hash_32[2851]]);
	hash_64[1428] = *((uint64_t*)&dataset[hash_32[2852]]);
	hash_64[1429] = *((uint64_t*)&dataset[hash_32[2853]]);
	hash_64[1430] = *((uint64_t*)&dataset[hash_32[2854]]);
	hash_64[1431] = *((uint64_t*)&dataset[hash_32[2855]]);
	hash_64[1432] = *((uint64_t*)&dataset[hash_32[2856]]);
	hash_64[1433] = *((uint64_t*)&dataset[hash_32[2857]]);
	hash_64[1434] = *((uint64_t*)&dataset[hash_32[2858]]);
	hash_64[1435] = *((uint64_t*)&dataset[hash_32[2859]]);
	hash_64[1436] = *((uint64_t*)&dataset[hash_32[2860]]);
	hash_64[1437] = *((uint64_t*)&dataset[hash_32[2861]]);
	hash_64[1438] = *((uint64_t*)&dataset[hash_32[2862]]);
	hash_64[1439] = *((uint64_t*)&dataset[hash_32[2863]]);
#endif
#if MEMORY_THREADS > 90
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1440] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1441] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1442] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1443] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1444] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1445] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1446] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1447] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1440] = *((uint64_t*)&dataset[hash_32[2880]]);
	hash_64[1441] = *((uint64_t*)&dataset[hash_32[2881]]);
	hash_64[1442] = *((uint64_t*)&dataset[hash_32[2882]]);
	hash_64[1443] = *((uint64_t*)&dataset[hash_32[2883]]);
	hash_64[1444] = *((uint64_t*)&dataset[hash_32[2884]]);
	hash_64[1445] = *((uint64_t*)&dataset[hash_32[2885]]);
	hash_64[1446] = *((uint64_t*)&dataset[hash_32[2886]]);
	hash_64[1447] = *((uint64_t*)&dataset[hash_32[2887]]);
	hash_64[1448] = *((uint64_t*)&dataset[hash_32[2888]]);
	hash_64[1449] = *((uint64_t*)&dataset[hash_32[2889]]);
	hash_64[1450] = *((uint64_t*)&dataset[hash_32[2890]]);
	hash_64[1451] = *((uint64_t*)&dataset[hash_32[2891]]);
	hash_64[1452] = *((uint64_t*)&dataset[hash_32[2892]]);
	hash_64[1453] = *((uint64_t*)&dataset[hash_32[2893]]);
	hash_64[1454] = *((uint64_t*)&dataset[hash_32[2894]]);
	hash_64[1455] = *((uint64_t*)&dataset[hash_32[2895]]);
#endif
#if MEMORY_THREADS > 91
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1456] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1457] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1458] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1459] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1460] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1461] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1462] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1463] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1456] = *((uint64_t*)&dataset[hash_32[2912]]);
	hash_64[1457] = *((uint64_t*)&dataset[hash_32[2913]]);
	hash_64[1458] = *((uint64_t*)&dataset[hash_32[2914]]);
	hash_64[1459] = *((uint64_t*)&dataset[hash_32[2915]]);
	hash_64[1460] = *((uint64_t*)&dataset[hash_32[2916]]);
	hash_64[1461] = *((uint64_t*)&dataset[hash_32[2917]]);
	hash_64[1462] = *((uint64_t*)&dataset[hash_32[2918]]);
	hash_64[1463] = *((uint64_t*)&dataset[hash_32[2919]]);
	hash_64[1464] = *((uint64_t*)&dataset[hash_32[2920]]);
	hash_64[1465] = *((uint64_t*)&dataset[hash_32[2921]]);
	hash_64[1466] = *((uint64_t*)&dataset[hash_32[2922]]);
	hash_64[1467] = *((uint64_t*)&dataset[hash_32[2923]]);
	hash_64[1468] = *((uint64_t*)&dataset[hash_32[2924]]);
	hash_64[1469] = *((uint64_t*)&dataset[hash_32[2925]]);
	hash_64[1470] = *((uint64_t*)&dataset[hash_32[2926]]);
	hash_64[1471] = *((uint64_t*)&dataset[hash_32[2927]]);
#endif
#if MEMORY_THREADS > 92
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1472] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1473] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1474] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1475] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1476] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1477] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1478] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1479] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1472] = *((uint64_t*)&dataset[hash_32[2944]]);
	hash_64[1473] = *((uint64_t*)&dataset[hash_32[2945]]);
	hash_64[1474] = *((uint64_t*)&dataset[hash_32[2946]]);
	hash_64[1475] = *((uint64_t*)&dataset[hash_32[2947]]);
	hash_64[1476] = *((uint64_t*)&dataset[hash_32[2948]]);
	hash_64[1477] = *((uint64_t*)&dataset[hash_32[2949]]);
	hash_64[1478] = *((uint64_t*)&dataset[hash_32[2950]]);
	hash_64[1479] = *((uint64_t*)&dataset[hash_32[2951]]);
	hash_64[1480] = *((uint64_t*)&dataset[hash_32[2952]]);
	hash_64[1481] = *((uint64_t*)&dataset[hash_32[2953]]);
	hash_64[1482] = *((uint64_t*)&dataset[hash_32[2954]]);
	hash_64[1483] = *((uint64_t*)&dataset[hash_32[2955]]);
	hash_64[1484] = *((uint64_t*)&dataset[hash_32[2956]]);
	hash_64[1485] = *((uint64_t*)&dataset[hash_32[2957]]);
	hash_64[1486] = *((uint64_t*)&dataset[hash_32[2958]]);
	hash_64[1487] = *((uint64_t*)&dataset[hash_32[2959]]);
#endif
#if MEMORY_THREADS > 93
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1488] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1489] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1490] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1491] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1492] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1493] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1494] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1495] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1488] = *((uint64_t*)&dataset[hash_32[2976]]);
	hash_64[1489] = *((uint64_t*)&dataset[hash_32[2977]]);
	hash_64[1490] = *((uint64_t*)&dataset[hash_32[2978]]);
	hash_64[1491] = *((uint64_t*)&dataset[hash_32[2979]]);
	hash_64[1492] = *((uint64_t*)&dataset[hash_32[2980]]);
	hash_64[1493] = *((uint64_t*)&dataset[hash_32[2981]]);
	hash_64[1494] = *((uint64_t*)&dataset[hash_32[2982]]);
	hash_64[1495] = *((uint64_t*)&dataset[hash_32[2983]]);
	hash_64[1496] = *((uint64_t*)&dataset[hash_32[2984]]);
	hash_64[1497] = *((uint64_t*)&dataset[hash_32[2985]]);
	hash_64[1498] = *((uint64_t*)&dataset[hash_32[2986]]);
	hash_64[1499] = *((uint64_t*)&dataset[hash_32[2987]]);
	hash_64[1500] = *((uint64_t*)&dataset[hash_32[2988]]);
	hash_64[1501] = *((uint64_t*)&dataset[hash_32[2989]]);
	hash_64[1502] = *((uint64_t*)&dataset[hash_32[2990]]);
	hash_64[1503] = *((uint64_t*)&dataset[hash_32[2991]]);
#endif
#if MEMORY_THREADS > 94
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1504] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1505] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1506] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1507] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1508] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1509] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1510] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1511] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1504] = *((uint64_t*)&dataset[hash_32[3008]]);
	hash_64[1505] = *((uint64_t*)&dataset[hash_32[3009]]);
	hash_64[1506] = *((uint64_t*)&dataset[hash_32[3010]]);
	hash_64[1507] = *((uint64_t*)&dataset[hash_32[3011]]);
	hash_64[1508] = *((uint64_t*)&dataset[hash_32[3012]]);
	hash_64[1509] = *((uint64_t*)&dataset[hash_32[3013]]);
	hash_64[1510] = *((uint64_t*)&dataset[hash_32[3014]]);
	hash_64[1511] = *((uint64_t*)&dataset[hash_32[3015]]);
	hash_64[1512] = *((uint64_t*)&dataset[hash_32[3016]]);
	hash_64[1513] = *((uint64_t*)&dataset[hash_32[3017]]);
	hash_64[1514] = *((uint64_t*)&dataset[hash_32[3018]]);
	hash_64[1515] = *((uint64_t*)&dataset[hash_32[3019]]);
	hash_64[1516] = *((uint64_t*)&dataset[hash_32[3020]]);
	hash_64[1517] = *((uint64_t*)&dataset[hash_32[3021]]);
	hash_64[1518] = *((uint64_t*)&dataset[hash_32[3022]]);
	hash_64[1519] = *((uint64_t*)&dataset[hash_32[3023]]);
#endif
#if MEMORY_THREADS > 95
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1520] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1521] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1522] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1523] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1524] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1525] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1526] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1527] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1520] = *((uint64_t*)&dataset[hash_32[3040]]);
	hash_64[1521] = *((uint64_t*)&dataset[hash_32[3041]]);
	hash_64[1522] = *((uint64_t*)&dataset[hash_32[3042]]);
	hash_64[1523] = *((uint64_t*)&dataset[hash_32[3043]]);
	hash_64[1524] = *((uint64_t*)&dataset[hash_32[3044]]);
	hash_64[1525] = *((uint64_t*)&dataset[hash_32[3045]]);
	hash_64[1526] = *((uint64_t*)&dataset[hash_32[3046]]);
	hash_64[1527] = *((uint64_t*)&dataset[hash_32[3047]]);
	hash_64[1528] = *((uint64_t*)&dataset[hash_32[3048]]);
	hash_64[1529] = *((uint64_t*)&dataset[hash_32[3049]]);
	hash_64[1530] = *((uint64_t*)&dataset[hash_32[3050]]);
	hash_64[1531] = *((uint64_t*)&dataset[hash_32[3051]]);
	hash_64[1532] = *((uint64_t*)&dataset[hash_32[3052]]);
	hash_64[1533] = *((uint64_t*)&dataset[hash_32[3053]]);
	hash_64[1534] = *((uint64_t*)&dataset[hash_32[3054]]);
	hash_64[1535] = *((uint64_t*)&dataset[hash_32[3055]]);
#endif
#if MEMORY_THREADS > 96
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1536] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1537] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1538] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1539] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1540] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1541] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1542] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1543] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1536] = *((uint64_t*)&dataset[hash_32[3072]]);
	hash_64[1537] = *((uint64_t*)&dataset[hash_32[3073]]);
	hash_64[1538] = *((uint64_t*)&dataset[hash_32[3074]]);
	hash_64[1539] = *((uint64_t*)&dataset[hash_32[3075]]);
	hash_64[1540] = *((uint64_t*)&dataset[hash_32[3076]]);
	hash_64[1541] = *((uint64_t*)&dataset[hash_32[3077]]);
	hash_64[1542] = *((uint64_t*)&dataset[hash_32[3078]]);
	hash_64[1543] = *((uint64_t*)&dataset[hash_32[3079]]);
	hash_64[1544] = *((uint64_t*)&dataset[hash_32[3080]]);
	hash_64[1545] = *((uint64_t*)&dataset[hash_32[3081]]);
	hash_64[1546] = *((uint64_t*)&dataset[hash_32[3082]]);
	hash_64[1547] = *((uint64_t*)&dataset[hash_32[3083]]);
	hash_64[1548] = *((uint64_t*)&dataset[hash_32[3084]]);
	hash_64[1549] = *((uint64_t*)&dataset[hash_32[3085]]);
	hash_64[1550] = *((uint64_t*)&dataset[hash_32[3086]]);
	hash_64[1551] = *((uint64_t*)&dataset[hash_32[3087]]);
#endif
#if MEMORY_THREADS > 97
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1552] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1553] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1554] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1555] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1556] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1557] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1558] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1559] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1552] = *((uint64_t*)&dataset[hash_32[3104]]);
	hash_64[1553] = *((uint64_t*)&dataset[hash_32[3105]]);
	hash_64[1554] = *((uint64_t*)&dataset[hash_32[3106]]);
	hash_64[1555] = *((uint64_t*)&dataset[hash_32[3107]]);
	hash_64[1556] = *((uint64_t*)&dataset[hash_32[3108]]);
	hash_64[1557] = *((uint64_t*)&dataset[hash_32[3109]]);
	hash_64[1558] = *((uint64_t*)&dataset[hash_32[3110]]);
	hash_64[1559] = *((uint64_t*)&dataset[hash_32[3111]]);
	hash_64[1560] = *((uint64_t*)&dataset[hash_32[3112]]);
	hash_64[1561] = *((uint64_t*)&dataset[hash_32[3113]]);
	hash_64[1562] = *((uint64_t*)&dataset[hash_32[3114]]);
	hash_64[1563] = *((uint64_t*)&dataset[hash_32[3115]]);
	hash_64[1564] = *((uint64_t*)&dataset[hash_32[3116]]);
	hash_64[1565] = *((uint64_t*)&dataset[hash_32[3117]]);
	hash_64[1566] = *((uint64_t*)&dataset[hash_32[3118]]);
	hash_64[1567] = *((uint64_t*)&dataset[hash_32[3119]]);
#endif
#if MEMORY_THREADS > 98
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1568] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1569] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1570] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1571] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1572] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1573] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1574] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1575] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1568] = *((uint64_t*)&dataset[hash_32[3136]]);
	hash_64[1569] = *((uint64_t*)&dataset[hash_32[3137]]);
	hash_64[1570] = *((uint64_t*)&dataset[hash_32[3138]]);
	hash_64[1571] = *((uint64_t*)&dataset[hash_32[3139]]);
	hash_64[1572] = *((uint64_t*)&dataset[hash_32[3140]]);
	hash_64[1573] = *((uint64_t*)&dataset[hash_32[3141]]);
	hash_64[1574] = *((uint64_t*)&dataset[hash_32[3142]]);
	hash_64[1575] = *((uint64_t*)&dataset[hash_32[3143]]);
	hash_64[1576] = *((uint64_t*)&dataset[hash_32[3144]]);
	hash_64[1577] = *((uint64_t*)&dataset[hash_32[3145]]);
	hash_64[1578] = *((uint64_t*)&dataset[hash_32[3146]]);
	hash_64[1579] = *((uint64_t*)&dataset[hash_32[3147]]);
	hash_64[1580] = *((uint64_t*)&dataset[hash_32[3148]]);
	hash_64[1581] = *((uint64_t*)&dataset[hash_32[3149]]);
	hash_64[1582] = *((uint64_t*)&dataset[hash_32[3150]]);
	hash_64[1583] = *((uint64_t*)&dataset[hash_32[3151]]);
#endif
#if MEMORY_THREADS > 99
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1584] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1585] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1586] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1587] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1588] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1589] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1590] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1591] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1584] = *((uint64_t*)&dataset[hash_32[3168]]);
	hash_64[1585] = *((uint64_t*)&dataset[hash_32[3169]]);
	hash_64[1586] = *((uint64_t*)&dataset[hash_32[3170]]);
	hash_64[1587] = *((uint64_t*)&dataset[hash_32[3171]]);
	hash_64[1588] = *((uint64_t*)&dataset[hash_32[3172]]);
	hash_64[1589] = *((uint64_t*)&dataset[hash_32[3173]]);
	hash_64[1590] = *((uint64_t*)&dataset[hash_32[3174]]);
	hash_64[1591] = *((uint64_t*)&dataset[hash_32[3175]]);
	hash_64[1592] = *((uint64_t*)&dataset[hash_32[3176]]);
	hash_64[1593] = *((uint64_t*)&dataset[hash_32[3177]]);
	hash_64[1594] = *((uint64_t*)&dataset[hash_32[3178]]);
	hash_64[1595] = *((uint64_t*)&dataset[hash_32[3179]]);
	hash_64[1596] = *((uint64_t*)&dataset[hash_32[3180]]);
	hash_64[1597] = *((uint64_t*)&dataset[hash_32[3181]]);
	hash_64[1598] = *((uint64_t*)&dataset[hash_32[3182]]);
	hash_64[1599] = *((uint64_t*)&dataset[hash_32[3183]]);
#endif
#if MEMORY_THREADS > 100
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1600] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1601] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1602] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1603] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1604] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1605] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1606] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1607] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1600] = *((uint64_t*)&dataset[hash_32[3200]]);
	hash_64[1601] = *((uint64_t*)&dataset[hash_32[3201]]);
	hash_64[1602] = *((uint64_t*)&dataset[hash_32[3202]]);
	hash_64[1603] = *((uint64_t*)&dataset[hash_32[3203]]);
	hash_64[1604] = *((uint64_t*)&dataset[hash_32[3204]]);
	hash_64[1605] = *((uint64_t*)&dataset[hash_32[3205]]);
	hash_64[1606] = *((uint64_t*)&dataset[hash_32[3206]]);
	hash_64[1607] = *((uint64_t*)&dataset[hash_32[3207]]);
	hash_64[1608] = *((uint64_t*)&dataset[hash_32[3208]]);
	hash_64[1609] = *((uint64_t*)&dataset[hash_32[3209]]);
	hash_64[1610] = *((uint64_t*)&dataset[hash_32[3210]]);
	hash_64[1611] = *((uint64_t*)&dataset[hash_32[3211]]);
	hash_64[1612] = *((uint64_t*)&dataset[hash_32[3212]]);
	hash_64[1613] = *((uint64_t*)&dataset[hash_32[3213]]);
	hash_64[1614] = *((uint64_t*)&dataset[hash_32[3214]]);
	hash_64[1615] = *((uint64_t*)&dataset[hash_32[3215]]);
#endif
#if MEMORY_THREADS > 101
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1616] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1617] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1618] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1619] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1620] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1621] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1622] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1623] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1616] = *((uint64_t*)&dataset[hash_32[3232]]);
	hash_64[1617] = *((uint64_t*)&dataset[hash_32[3233]]);
	hash_64[1618] = *((uint64_t*)&dataset[hash_32[3234]]);
	hash_64[1619] = *((uint64_t*)&dataset[hash_32[3235]]);
	hash_64[1620] = *((uint64_t*)&dataset[hash_32[3236]]);
	hash_64[1621] = *((uint64_t*)&dataset[hash_32[3237]]);
	hash_64[1622] = *((uint64_t*)&dataset[hash_32[3238]]);
	hash_64[1623] = *((uint64_t*)&dataset[hash_32[3239]]);
	hash_64[1624] = *((uint64_t*)&dataset[hash_32[3240]]);
	hash_64[1625] = *((uint64_t*)&dataset[hash_32[3241]]);
	hash_64[1626] = *((uint64_t*)&dataset[hash_32[3242]]);
	hash_64[1627] = *((uint64_t*)&dataset[hash_32[3243]]);
	hash_64[1628] = *((uint64_t*)&dataset[hash_32[3244]]);
	hash_64[1629] = *((uint64_t*)&dataset[hash_32[3245]]);
	hash_64[1630] = *((uint64_t*)&dataset[hash_32[3246]]);
	hash_64[1631] = *((uint64_t*)&dataset[hash_32[3247]]);
#endif
#if MEMORY_THREADS > 102
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1632] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1633] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1634] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1635] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1636] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1637] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1638] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1639] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1632] = *((uint64_t*)&dataset[hash_32[3264]]);
	hash_64[1633] = *((uint64_t*)&dataset[hash_32[3265]]);
	hash_64[1634] = *((uint64_t*)&dataset[hash_32[3266]]);
	hash_64[1635] = *((uint64_t*)&dataset[hash_32[3267]]);
	hash_64[1636] = *((uint64_t*)&dataset[hash_32[3268]]);
	hash_64[1637] = *((uint64_t*)&dataset[hash_32[3269]]);
	hash_64[1638] = *((uint64_t*)&dataset[hash_32[3270]]);
	hash_64[1639] = *((uint64_t*)&dataset[hash_32[3271]]);
	hash_64[1640] = *((uint64_t*)&dataset[hash_32[3272]]);
	hash_64[1641] = *((uint64_t*)&dataset[hash_32[3273]]);
	hash_64[1642] = *((uint64_t*)&dataset[hash_32[3274]]);
	hash_64[1643] = *((uint64_t*)&dataset[hash_32[3275]]);
	hash_64[1644] = *((uint64_t*)&dataset[hash_32[3276]]);
	hash_64[1645] = *((uint64_t*)&dataset[hash_32[3277]]);
	hash_64[1646] = *((uint64_t*)&dataset[hash_32[3278]]);
	hash_64[1647] = *((uint64_t*)&dataset[hash_32[3279]]);
#endif
#if MEMORY_THREADS > 103
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1648] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1649] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1650] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1651] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1652] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1653] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1654] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1655] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1648] = *((uint64_t*)&dataset[hash_32[3296]]);
	hash_64[1649] = *((uint64_t*)&dataset[hash_32[3297]]);
	hash_64[1650] = *((uint64_t*)&dataset[hash_32[3298]]);
	hash_64[1651] = *((uint64_t*)&dataset[hash_32[3299]]);
	hash_64[1652] = *((uint64_t*)&dataset[hash_32[3300]]);
	hash_64[1653] = *((uint64_t*)&dataset[hash_32[3301]]);
	hash_64[1654] = *((uint64_t*)&dataset[hash_32[3302]]);
	hash_64[1655] = *((uint64_t*)&dataset[hash_32[3303]]);
	hash_64[1656] = *((uint64_t*)&dataset[hash_32[3304]]);
	hash_64[1657] = *((uint64_t*)&dataset[hash_32[3305]]);
	hash_64[1658] = *((uint64_t*)&dataset[hash_32[3306]]);
	hash_64[1659] = *((uint64_t*)&dataset[hash_32[3307]]);
	hash_64[1660] = *((uint64_t*)&dataset[hash_32[3308]]);
	hash_64[1661] = *((uint64_t*)&dataset[hash_32[3309]]);
	hash_64[1662] = *((uint64_t*)&dataset[hash_32[3310]]);
	hash_64[1663] = *((uint64_t*)&dataset[hash_32[3311]]);
#endif
#if MEMORY_THREADS > 104
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1664] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1665] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1666] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1667] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1668] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1669] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1670] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1671] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1664] = *((uint64_t*)&dataset[hash_32[3328]]);
	hash_64[1665] = *((uint64_t*)&dataset[hash_32[3329]]);
	hash_64[1666] = *((uint64_t*)&dataset[hash_32[3330]]);
	hash_64[1667] = *((uint64_t*)&dataset[hash_32[3331]]);
	hash_64[1668] = *((uint64_t*)&dataset[hash_32[3332]]);
	hash_64[1669] = *((uint64_t*)&dataset[hash_32[3333]]);
	hash_64[1670] = *((uint64_t*)&dataset[hash_32[3334]]);
	hash_64[1671] = *((uint64_t*)&dataset[hash_32[3335]]);
	hash_64[1672] = *((uint64_t*)&dataset[hash_32[3336]]);
	hash_64[1673] = *((uint64_t*)&dataset[hash_32[3337]]);
	hash_64[1674] = *((uint64_t*)&dataset[hash_32[3338]]);
	hash_64[1675] = *((uint64_t*)&dataset[hash_32[3339]]);
	hash_64[1676] = *((uint64_t*)&dataset[hash_32[3340]]);
	hash_64[1677] = *((uint64_t*)&dataset[hash_32[3341]]);
	hash_64[1678] = *((uint64_t*)&dataset[hash_32[3342]]);
	hash_64[1679] = *((uint64_t*)&dataset[hash_32[3343]]);
#endif
#if MEMORY_THREADS > 105
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1680] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1681] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1682] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1683] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1684] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1685] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1686] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1687] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1680] = *((uint64_t*)&dataset[hash_32[3360]]);
	hash_64[1681] = *((uint64_t*)&dataset[hash_32[3361]]);
	hash_64[1682] = *((uint64_t*)&dataset[hash_32[3362]]);
	hash_64[1683] = *((uint64_t*)&dataset[hash_32[3363]]);
	hash_64[1684] = *((uint64_t*)&dataset[hash_32[3364]]);
	hash_64[1685] = *((uint64_t*)&dataset[hash_32[3365]]);
	hash_64[1686] = *((uint64_t*)&dataset[hash_32[3366]]);
	hash_64[1687] = *((uint64_t*)&dataset[hash_32[3367]]);
	hash_64[1688] = *((uint64_t*)&dataset[hash_32[3368]]);
	hash_64[1689] = *((uint64_t*)&dataset[hash_32[3369]]);
	hash_64[1690] = *((uint64_t*)&dataset[hash_32[3370]]);
	hash_64[1691] = *((uint64_t*)&dataset[hash_32[3371]]);
	hash_64[1692] = *((uint64_t*)&dataset[hash_32[3372]]);
	hash_64[1693] = *((uint64_t*)&dataset[hash_32[3373]]);
	hash_64[1694] = *((uint64_t*)&dataset[hash_32[3374]]);
	hash_64[1695] = *((uint64_t*)&dataset[hash_32[3375]]);
#endif
#if MEMORY_THREADS > 106
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1696] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1697] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1698] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1699] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1700] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1701] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1702] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1703] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1696] = *((uint64_t*)&dataset[hash_32[3392]]);
	hash_64[1697] = *((uint64_t*)&dataset[hash_32[3393]]);
	hash_64[1698] = *((uint64_t*)&dataset[hash_32[3394]]);
	hash_64[1699] = *((uint64_t*)&dataset[hash_32[3395]]);
	hash_64[1700] = *((uint64_t*)&dataset[hash_32[3396]]);
	hash_64[1701] = *((uint64_t*)&dataset[hash_32[3397]]);
	hash_64[1702] = *((uint64_t*)&dataset[hash_32[3398]]);
	hash_64[1703] = *((uint64_t*)&dataset[hash_32[3399]]);
	hash_64[1704] = *((uint64_t*)&dataset[hash_32[3400]]);
	hash_64[1705] = *((uint64_t*)&dataset[hash_32[3401]]);
	hash_64[1706] = *((uint64_t*)&dataset[hash_32[3402]]);
	hash_64[1707] = *((uint64_t*)&dataset[hash_32[3403]]);
	hash_64[1708] = *((uint64_t*)&dataset[hash_32[3404]]);
	hash_64[1709] = *((uint64_t*)&dataset[hash_32[3405]]);
	hash_64[1710] = *((uint64_t*)&dataset[hash_32[3406]]);
	hash_64[1711] = *((uint64_t*)&dataset[hash_32[3407]]);
#endif
#if MEMORY_THREADS > 107
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1712] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1713] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1714] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1715] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1716] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1717] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1718] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1719] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1712] = *((uint64_t*)&dataset[hash_32[3424]]);
	hash_64[1713] = *((uint64_t*)&dataset[hash_32[3425]]);
	hash_64[1714] = *((uint64_t*)&dataset[hash_32[3426]]);
	hash_64[1715] = *((uint64_t*)&dataset[hash_32[3427]]);
	hash_64[1716] = *((uint64_t*)&dataset[hash_32[3428]]);
	hash_64[1717] = *((uint64_t*)&dataset[hash_32[3429]]);
	hash_64[1718] = *((uint64_t*)&dataset[hash_32[3430]]);
	hash_64[1719] = *((uint64_t*)&dataset[hash_32[3431]]);
	hash_64[1720] = *((uint64_t*)&dataset[hash_32[3432]]);
	hash_64[1721] = *((uint64_t*)&dataset[hash_32[3433]]);
	hash_64[1722] = *((uint64_t*)&dataset[hash_32[3434]]);
	hash_64[1723] = *((uint64_t*)&dataset[hash_32[3435]]);
	hash_64[1724] = *((uint64_t*)&dataset[hash_32[3436]]);
	hash_64[1725] = *((uint64_t*)&dataset[hash_32[3437]]);
	hash_64[1726] = *((uint64_t*)&dataset[hash_32[3438]]);
	hash_64[1727] = *((uint64_t*)&dataset[hash_32[3439]]);
#endif
#if MEMORY_THREADS > 108
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1728] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1729] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1730] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1731] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1732] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1733] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1734] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1735] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1728] = *((uint64_t*)&dataset[hash_32[3456]]);
	hash_64[1729] = *((uint64_t*)&dataset[hash_32[3457]]);
	hash_64[1730] = *((uint64_t*)&dataset[hash_32[3458]]);
	hash_64[1731] = *((uint64_t*)&dataset[hash_32[3459]]);
	hash_64[1732] = *((uint64_t*)&dataset[hash_32[3460]]);
	hash_64[1733] = *((uint64_t*)&dataset[hash_32[3461]]);
	hash_64[1734] = *((uint64_t*)&dataset[hash_32[3462]]);
	hash_64[1735] = *((uint64_t*)&dataset[hash_32[3463]]);
	hash_64[1736] = *((uint64_t*)&dataset[hash_32[3464]]);
	hash_64[1737] = *((uint64_t*)&dataset[hash_32[3465]]);
	hash_64[1738] = *((uint64_t*)&dataset[hash_32[3466]]);
	hash_64[1739] = *((uint64_t*)&dataset[hash_32[3467]]);
	hash_64[1740] = *((uint64_t*)&dataset[hash_32[3468]]);
	hash_64[1741] = *((uint64_t*)&dataset[hash_32[3469]]);
	hash_64[1742] = *((uint64_t*)&dataset[hash_32[3470]]);
	hash_64[1743] = *((uint64_t*)&dataset[hash_32[3471]]);
#endif
#if MEMORY_THREADS > 109
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1744] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1745] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1746] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1747] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1748] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1749] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1750] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1751] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1744] = *((uint64_t*)&dataset[hash_32[3488]]);
	hash_64[1745] = *((uint64_t*)&dataset[hash_32[3489]]);
	hash_64[1746] = *((uint64_t*)&dataset[hash_32[3490]]);
	hash_64[1747] = *((uint64_t*)&dataset[hash_32[3491]]);
	hash_64[1748] = *((uint64_t*)&dataset[hash_32[3492]]);
	hash_64[1749] = *((uint64_t*)&dataset[hash_32[3493]]);
	hash_64[1750] = *((uint64_t*)&dataset[hash_32[3494]]);
	hash_64[1751] = *((uint64_t*)&dataset[hash_32[3495]]);
	hash_64[1752] = *((uint64_t*)&dataset[hash_32[3496]]);
	hash_64[1753] = *((uint64_t*)&dataset[hash_32[3497]]);
	hash_64[1754] = *((uint64_t*)&dataset[hash_32[3498]]);
	hash_64[1755] = *((uint64_t*)&dataset[hash_32[3499]]);
	hash_64[1756] = *((uint64_t*)&dataset[hash_32[3500]]);
	hash_64[1757] = *((uint64_t*)&dataset[hash_32[3501]]);
	hash_64[1758] = *((uint64_t*)&dataset[hash_32[3502]]);
	hash_64[1759] = *((uint64_t*)&dataset[hash_32[3503]]);
#endif
#if MEMORY_THREADS > 110
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1760] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1761] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1762] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1763] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1764] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1765] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1766] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1767] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1760] = *((uint64_t*)&dataset[hash_32[3520]]);
	hash_64[1761] = *((uint64_t*)&dataset[hash_32[3521]]);
	hash_64[1762] = *((uint64_t*)&dataset[hash_32[3522]]);
	hash_64[1763] = *((uint64_t*)&dataset[hash_32[3523]]);
	hash_64[1764] = *((uint64_t*)&dataset[hash_32[3524]]);
	hash_64[1765] = *((uint64_t*)&dataset[hash_32[3525]]);
	hash_64[1766] = *((uint64_t*)&dataset[hash_32[3526]]);
	hash_64[1767] = *((uint64_t*)&dataset[hash_32[3527]]);
	hash_64[1768] = *((uint64_t*)&dataset[hash_32[3528]]);
	hash_64[1769] = *((uint64_t*)&dataset[hash_32[3529]]);
	hash_64[1770] = *((uint64_t*)&dataset[hash_32[3530]]);
	hash_64[1771] = *((uint64_t*)&dataset[hash_32[3531]]);
	hash_64[1772] = *((uint64_t*)&dataset[hash_32[3532]]);
	hash_64[1773] = *((uint64_t*)&dataset[hash_32[3533]]);
	hash_64[1774] = *((uint64_t*)&dataset[hash_32[3534]]);
	hash_64[1775] = *((uint64_t*)&dataset[hash_32[3535]]);
#endif
#if MEMORY_THREADS > 111
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1776] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1777] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1778] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1779] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1780] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1781] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1782] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1783] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1776] = *((uint64_t*)&dataset[hash_32[3552]]);
	hash_64[1777] = *((uint64_t*)&dataset[hash_32[3553]]);
	hash_64[1778] = *((uint64_t*)&dataset[hash_32[3554]]);
	hash_64[1779] = *((uint64_t*)&dataset[hash_32[3555]]);
	hash_64[1780] = *((uint64_t*)&dataset[hash_32[3556]]);
	hash_64[1781] = *((uint64_t*)&dataset[hash_32[3557]]);
	hash_64[1782] = *((uint64_t*)&dataset[hash_32[3558]]);
	hash_64[1783] = *((uint64_t*)&dataset[hash_32[3559]]);
	hash_64[1784] = *((uint64_t*)&dataset[hash_32[3560]]);
	hash_64[1785] = *((uint64_t*)&dataset[hash_32[3561]]);
	hash_64[1786] = *((uint64_t*)&dataset[hash_32[3562]]);
	hash_64[1787] = *((uint64_t*)&dataset[hash_32[3563]]);
	hash_64[1788] = *((uint64_t*)&dataset[hash_32[3564]]);
	hash_64[1789] = *((uint64_t*)&dataset[hash_32[3565]]);
	hash_64[1790] = *((uint64_t*)&dataset[hash_32[3566]]);
	hash_64[1791] = *((uint64_t*)&dataset[hash_32[3567]]);
#endif
#if MEMORY_THREADS > 112
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1792] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1793] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1794] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1795] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1796] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1797] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1798] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1799] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1792] = *((uint64_t*)&dataset[hash_32[3584]]);
	hash_64[1793] = *((uint64_t*)&dataset[hash_32[3585]]);
	hash_64[1794] = *((uint64_t*)&dataset[hash_32[3586]]);
	hash_64[1795] = *((uint64_t*)&dataset[hash_32[3587]]);
	hash_64[1796] = *((uint64_t*)&dataset[hash_32[3588]]);
	hash_64[1797] = *((uint64_t*)&dataset[hash_32[3589]]);
	hash_64[1798] = *((uint64_t*)&dataset[hash_32[3590]]);
	hash_64[1799] = *((uint64_t*)&dataset[hash_32[3591]]);
	hash_64[1800] = *((uint64_t*)&dataset[hash_32[3592]]);
	hash_64[1801] = *((uint64_t*)&dataset[hash_32[3593]]);
	hash_64[1802] = *((uint64_t*)&dataset[hash_32[3594]]);
	hash_64[1803] = *((uint64_t*)&dataset[hash_32[3595]]);
	hash_64[1804] = *((uint64_t*)&dataset[hash_32[3596]]);
	hash_64[1805] = *((uint64_t*)&dataset[hash_32[3597]]);
	hash_64[1806] = *((uint64_t*)&dataset[hash_32[3598]]);
	hash_64[1807] = *((uint64_t*)&dataset[hash_32[3599]]);
#endif
#if MEMORY_THREADS > 113
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1808] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1809] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1810] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1811] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1812] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1813] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1814] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1815] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1808] = *((uint64_t*)&dataset[hash_32[3616]]);
	hash_64[1809] = *((uint64_t*)&dataset[hash_32[3617]]);
	hash_64[1810] = *((uint64_t*)&dataset[hash_32[3618]]);
	hash_64[1811] = *((uint64_t*)&dataset[hash_32[3619]]);
	hash_64[1812] = *((uint64_t*)&dataset[hash_32[3620]]);
	hash_64[1813] = *((uint64_t*)&dataset[hash_32[3621]]);
	hash_64[1814] = *((uint64_t*)&dataset[hash_32[3622]]);
	hash_64[1815] = *((uint64_t*)&dataset[hash_32[3623]]);
	hash_64[1816] = *((uint64_t*)&dataset[hash_32[3624]]);
	hash_64[1817] = *((uint64_t*)&dataset[hash_32[3625]]);
	hash_64[1818] = *((uint64_t*)&dataset[hash_32[3626]]);
	hash_64[1819] = *((uint64_t*)&dataset[hash_32[3627]]);
	hash_64[1820] = *((uint64_t*)&dataset[hash_32[3628]]);
	hash_64[1821] = *((uint64_t*)&dataset[hash_32[3629]]);
	hash_64[1822] = *((uint64_t*)&dataset[hash_32[3630]]);
	hash_64[1823] = *((uint64_t*)&dataset[hash_32[3631]]);
#endif
#if MEMORY_THREADS > 114
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1824] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1825] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1826] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1827] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1828] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1829] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1830] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1831] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1824] = *((uint64_t*)&dataset[hash_32[3648]]);
	hash_64[1825] = *((uint64_t*)&dataset[hash_32[3649]]);
	hash_64[1826] = *((uint64_t*)&dataset[hash_32[3650]]);
	hash_64[1827] = *((uint64_t*)&dataset[hash_32[3651]]);
	hash_64[1828] = *((uint64_t*)&dataset[hash_32[3652]]);
	hash_64[1829] = *((uint64_t*)&dataset[hash_32[3653]]);
	hash_64[1830] = *((uint64_t*)&dataset[hash_32[3654]]);
	hash_64[1831] = *((uint64_t*)&dataset[hash_32[3655]]);
	hash_64[1832] = *((uint64_t*)&dataset[hash_32[3656]]);
	hash_64[1833] = *((uint64_t*)&dataset[hash_32[3657]]);
	hash_64[1834] = *((uint64_t*)&dataset[hash_32[3658]]);
	hash_64[1835] = *((uint64_t*)&dataset[hash_32[3659]]);
	hash_64[1836] = *((uint64_t*)&dataset[hash_32[3660]]);
	hash_64[1837] = *((uint64_t*)&dataset[hash_32[3661]]);
	hash_64[1838] = *((uint64_t*)&dataset[hash_32[3662]]);
	hash_64[1839] = *((uint64_t*)&dataset[hash_32[3663]]);
#endif
#if MEMORY_THREADS > 115
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1840] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1841] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1842] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1843] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1844] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1845] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1846] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1847] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1840] = *((uint64_t*)&dataset[hash_32[3680]]);
	hash_64[1841] = *((uint64_t*)&dataset[hash_32[3681]]);
	hash_64[1842] = *((uint64_t*)&dataset[hash_32[3682]]);
	hash_64[1843] = *((uint64_t*)&dataset[hash_32[3683]]);
	hash_64[1844] = *((uint64_t*)&dataset[hash_32[3684]]);
	hash_64[1845] = *((uint64_t*)&dataset[hash_32[3685]]);
	hash_64[1846] = *((uint64_t*)&dataset[hash_32[3686]]);
	hash_64[1847] = *((uint64_t*)&dataset[hash_32[3687]]);
	hash_64[1848] = *((uint64_t*)&dataset[hash_32[3688]]);
	hash_64[1849] = *((uint64_t*)&dataset[hash_32[3689]]);
	hash_64[1850] = *((uint64_t*)&dataset[hash_32[3690]]);
	hash_64[1851] = *((uint64_t*)&dataset[hash_32[3691]]);
	hash_64[1852] = *((uint64_t*)&dataset[hash_32[3692]]);
	hash_64[1853] = *((uint64_t*)&dataset[hash_32[3693]]);
	hash_64[1854] = *((uint64_t*)&dataset[hash_32[3694]]);
	hash_64[1855] = *((uint64_t*)&dataset[hash_32[3695]]);
#endif
#if MEMORY_THREADS > 116
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1856] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1857] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1858] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1859] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1860] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1861] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1862] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1863] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1856] = *((uint64_t*)&dataset[hash_32[3712]]);
	hash_64[1857] = *((uint64_t*)&dataset[hash_32[3713]]);
	hash_64[1858] = *((uint64_t*)&dataset[hash_32[3714]]);
	hash_64[1859] = *((uint64_t*)&dataset[hash_32[3715]]);
	hash_64[1860] = *((uint64_t*)&dataset[hash_32[3716]]);
	hash_64[1861] = *((uint64_t*)&dataset[hash_32[3717]]);
	hash_64[1862] = *((uint64_t*)&dataset[hash_32[3718]]);
	hash_64[1863] = *((uint64_t*)&dataset[hash_32[3719]]);
	hash_64[1864] = *((uint64_t*)&dataset[hash_32[3720]]);
	hash_64[1865] = *((uint64_t*)&dataset[hash_32[3721]]);
	hash_64[1866] = *((uint64_t*)&dataset[hash_32[3722]]);
	hash_64[1867] = *((uint64_t*)&dataset[hash_32[3723]]);
	hash_64[1868] = *((uint64_t*)&dataset[hash_32[3724]]);
	hash_64[1869] = *((uint64_t*)&dataset[hash_32[3725]]);
	hash_64[1870] = *((uint64_t*)&dataset[hash_32[3726]]);
	hash_64[1871] = *((uint64_t*)&dataset[hash_32[3727]]);
#endif
#if MEMORY_THREADS > 117
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1872] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1873] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1874] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1875] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1876] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1877] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1878] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1879] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1872] = *((uint64_t*)&dataset[hash_32[3744]]);
	hash_64[1873] = *((uint64_t*)&dataset[hash_32[3745]]);
	hash_64[1874] = *((uint64_t*)&dataset[hash_32[3746]]);
	hash_64[1875] = *((uint64_t*)&dataset[hash_32[3747]]);
	hash_64[1876] = *((uint64_t*)&dataset[hash_32[3748]]);
	hash_64[1877] = *((uint64_t*)&dataset[hash_32[3749]]);
	hash_64[1878] = *((uint64_t*)&dataset[hash_32[3750]]);
	hash_64[1879] = *((uint64_t*)&dataset[hash_32[3751]]);
	hash_64[1880] = *((uint64_t*)&dataset[hash_32[3752]]);
	hash_64[1881] = *((uint64_t*)&dataset[hash_32[3753]]);
	hash_64[1882] = *((uint64_t*)&dataset[hash_32[3754]]);
	hash_64[1883] = *((uint64_t*)&dataset[hash_32[3755]]);
	hash_64[1884] = *((uint64_t*)&dataset[hash_32[3756]]);
	hash_64[1885] = *((uint64_t*)&dataset[hash_32[3757]]);
	hash_64[1886] = *((uint64_t*)&dataset[hash_32[3758]]);
	hash_64[1887] = *((uint64_t*)&dataset[hash_32[3759]]);
#endif
#if MEMORY_THREADS > 118
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1888] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1889] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1890] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1891] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1892] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1893] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1894] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1895] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1888] = *((uint64_t*)&dataset[hash_32[3776]]);
	hash_64[1889] = *((uint64_t*)&dataset[hash_32[3777]]);
	hash_64[1890] = *((uint64_t*)&dataset[hash_32[3778]]);
	hash_64[1891] = *((uint64_t*)&dataset[hash_32[3779]]);
	hash_64[1892] = *((uint64_t*)&dataset[hash_32[3780]]);
	hash_64[1893] = *((uint64_t*)&dataset[hash_32[3781]]);
	hash_64[1894] = *((uint64_t*)&dataset[hash_32[3782]]);
	hash_64[1895] = *((uint64_t*)&dataset[hash_32[3783]]);
	hash_64[1896] = *((uint64_t*)&dataset[hash_32[3784]]);
	hash_64[1897] = *((uint64_t*)&dataset[hash_32[3785]]);
	hash_64[1898] = *((uint64_t*)&dataset[hash_32[3786]]);
	hash_64[1899] = *((uint64_t*)&dataset[hash_32[3787]]);
	hash_64[1900] = *((uint64_t*)&dataset[hash_32[3788]]);
	hash_64[1901] = *((uint64_t*)&dataset[hash_32[3789]]);
	hash_64[1902] = *((uint64_t*)&dataset[hash_32[3790]]);
	hash_64[1903] = *((uint64_t*)&dataset[hash_32[3791]]);
#endif
#if MEMORY_THREADS > 119
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1904] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1905] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1906] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1907] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1908] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1909] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1910] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1911] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1904] = *((uint64_t*)&dataset[hash_32[3808]]);
	hash_64[1905] = *((uint64_t*)&dataset[hash_32[3809]]);
	hash_64[1906] = *((uint64_t*)&dataset[hash_32[3810]]);
	hash_64[1907] = *((uint64_t*)&dataset[hash_32[3811]]);
	hash_64[1908] = *((uint64_t*)&dataset[hash_32[3812]]);
	hash_64[1909] = *((uint64_t*)&dataset[hash_32[3813]]);
	hash_64[1910] = *((uint64_t*)&dataset[hash_32[3814]]);
	hash_64[1911] = *((uint64_t*)&dataset[hash_32[3815]]);
	hash_64[1912] = *((uint64_t*)&dataset[hash_32[3816]]);
	hash_64[1913] = *((uint64_t*)&dataset[hash_32[3817]]);
	hash_64[1914] = *((uint64_t*)&dataset[hash_32[3818]]);
	hash_64[1915] = *((uint64_t*)&dataset[hash_32[3819]]);
	hash_64[1916] = *((uint64_t*)&dataset[hash_32[3820]]);
	hash_64[1917] = *((uint64_t*)&dataset[hash_32[3821]]);
	hash_64[1918] = *((uint64_t*)&dataset[hash_32[3822]]);
	hash_64[1919] = *((uint64_t*)&dataset[hash_32[3823]]);
#endif
#if MEMORY_THREADS > 120
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1920] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1921] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1922] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1923] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1924] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1925] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1926] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1927] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1920] = *((uint64_t*)&dataset[hash_32[3840]]);
	hash_64[1921] = *((uint64_t*)&dataset[hash_32[3841]]);
	hash_64[1922] = *((uint64_t*)&dataset[hash_32[3842]]);
	hash_64[1923] = *((uint64_t*)&dataset[hash_32[3843]]);
	hash_64[1924] = *((uint64_t*)&dataset[hash_32[3844]]);
	hash_64[1925] = *((uint64_t*)&dataset[hash_32[3845]]);
	hash_64[1926] = *((uint64_t*)&dataset[hash_32[3846]]);
	hash_64[1927] = *((uint64_t*)&dataset[hash_32[3847]]);
	hash_64[1928] = *((uint64_t*)&dataset[hash_32[3848]]);
	hash_64[1929] = *((uint64_t*)&dataset[hash_32[3849]]);
	hash_64[1930] = *((uint64_t*)&dataset[hash_32[3850]]);
	hash_64[1931] = *((uint64_t*)&dataset[hash_32[3851]]);
	hash_64[1932] = *((uint64_t*)&dataset[hash_32[3852]]);
	hash_64[1933] = *((uint64_t*)&dataset[hash_32[3853]]);
	hash_64[1934] = *((uint64_t*)&dataset[hash_32[3854]]);
	hash_64[1935] = *((uint64_t*)&dataset[hash_32[3855]]);
#endif
#if MEMORY_THREADS > 121
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1936] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1937] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1938] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1939] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1940] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1941] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1942] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1943] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1936] = *((uint64_t*)&dataset[hash_32[3872]]);
	hash_64[1937] = *((uint64_t*)&dataset[hash_32[3873]]);
	hash_64[1938] = *((uint64_t*)&dataset[hash_32[3874]]);
	hash_64[1939] = *((uint64_t*)&dataset[hash_32[3875]]);
	hash_64[1940] = *((uint64_t*)&dataset[hash_32[3876]]);
	hash_64[1941] = *((uint64_t*)&dataset[hash_32[3877]]);
	hash_64[1942] = *((uint64_t*)&dataset[hash_32[3878]]);
	hash_64[1943] = *((uint64_t*)&dataset[hash_32[3879]]);
	hash_64[1944] = *((uint64_t*)&dataset[hash_32[3880]]);
	hash_64[1945] = *((uint64_t*)&dataset[hash_32[3881]]);
	hash_64[1946] = *((uint64_t*)&dataset[hash_32[3882]]);
	hash_64[1947] = *((uint64_t*)&dataset[hash_32[3883]]);
	hash_64[1948] = *((uint64_t*)&dataset[hash_32[3884]]);
	hash_64[1949] = *((uint64_t*)&dataset[hash_32[3885]]);
	hash_64[1950] = *((uint64_t*)&dataset[hash_32[3886]]);
	hash_64[1951] = *((uint64_t*)&dataset[hash_32[3887]]);
#endif
#if MEMORY_THREADS > 122
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1952] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1953] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1954] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1955] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1956] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1957] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1958] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1959] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1952] = *((uint64_t*)&dataset[hash_32[3904]]);
	hash_64[1953] = *((uint64_t*)&dataset[hash_32[3905]]);
	hash_64[1954] = *((uint64_t*)&dataset[hash_32[3906]]);
	hash_64[1955] = *((uint64_t*)&dataset[hash_32[3907]]);
	hash_64[1956] = *((uint64_t*)&dataset[hash_32[3908]]);
	hash_64[1957] = *((uint64_t*)&dataset[hash_32[3909]]);
	hash_64[1958] = *((uint64_t*)&dataset[hash_32[3910]]);
	hash_64[1959] = *((uint64_t*)&dataset[hash_32[3911]]);
	hash_64[1960] = *((uint64_t*)&dataset[hash_32[3912]]);
	hash_64[1961] = *((uint64_t*)&dataset[hash_32[3913]]);
	hash_64[1962] = *((uint64_t*)&dataset[hash_32[3914]]);
	hash_64[1963] = *((uint64_t*)&dataset[hash_32[3915]]);
	hash_64[1964] = *((uint64_t*)&dataset[hash_32[3916]]);
	hash_64[1965] = *((uint64_t*)&dataset[hash_32[3917]]);
	hash_64[1966] = *((uint64_t*)&dataset[hash_32[3918]]);
	hash_64[1967] = *((uint64_t*)&dataset[hash_32[3919]]);
#endif
#if MEMORY_THREADS > 123
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1968] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1969] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1970] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1971] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1972] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1973] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1974] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1975] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1968] = *((uint64_t*)&dataset[hash_32[3936]]);
	hash_64[1969] = *((uint64_t*)&dataset[hash_32[3937]]);
	hash_64[1970] = *((uint64_t*)&dataset[hash_32[3938]]);
	hash_64[1971] = *((uint64_t*)&dataset[hash_32[3939]]);
	hash_64[1972] = *((uint64_t*)&dataset[hash_32[3940]]);
	hash_64[1973] = *((uint64_t*)&dataset[hash_32[3941]]);
	hash_64[1974] = *((uint64_t*)&dataset[hash_32[3942]]);
	hash_64[1975] = *((uint64_t*)&dataset[hash_32[3943]]);
	hash_64[1976] = *((uint64_t*)&dataset[hash_32[3944]]);
	hash_64[1977] = *((uint64_t*)&dataset[hash_32[3945]]);
	hash_64[1978] = *((uint64_t*)&dataset[hash_32[3946]]);
	hash_64[1979] = *((uint64_t*)&dataset[hash_32[3947]]);
	hash_64[1980] = *((uint64_t*)&dataset[hash_32[3948]]);
	hash_64[1981] = *((uint64_t*)&dataset[hash_32[3949]]);
	hash_64[1982] = *((uint64_t*)&dataset[hash_32[3950]]);
	hash_64[1983] = *((uint64_t*)&dataset[hash_32[3951]]);
#endif
#if MEMORY_THREADS > 124
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[1984] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[1985] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[1986] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[1987] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[1988] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[1989] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[1990] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[1991] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[1984] = *((uint64_t*)&dataset[hash_32[3968]]);
	hash_64[1985] = *((uint64_t*)&dataset[hash_32[3969]]);
	hash_64[1986] = *((uint64_t*)&dataset[hash_32[3970]]);
	hash_64[1987] = *((uint64_t*)&dataset[hash_32[3971]]);
	hash_64[1988] = *((uint64_t*)&dataset[hash_32[3972]]);
	hash_64[1989] = *((uint64_t*)&dataset[hash_32[3973]]);
	hash_64[1990] = *((uint64_t*)&dataset[hash_32[3974]]);
	hash_64[1991] = *((uint64_t*)&dataset[hash_32[3975]]);
	hash_64[1992] = *((uint64_t*)&dataset[hash_32[3976]]);
	hash_64[1993] = *((uint64_t*)&dataset[hash_32[3977]]);
	hash_64[1994] = *((uint64_t*)&dataset[hash_32[3978]]);
	hash_64[1995] = *((uint64_t*)&dataset[hash_32[3979]]);
	hash_64[1996] = *((uint64_t*)&dataset[hash_32[3980]]);
	hash_64[1997] = *((uint64_t*)&dataset[hash_32[3981]]);
	hash_64[1998] = *((uint64_t*)&dataset[hash_32[3982]]);
	hash_64[1999] = *((uint64_t*)&dataset[hash_32[3983]]);
#endif
#if MEMORY_THREADS > 125
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2000] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2001] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2002] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2003] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2004] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2005] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2006] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2007] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2000] = *((uint64_t*)&dataset[hash_32[4000]]);
	hash_64[2001] = *((uint64_t*)&dataset[hash_32[4001]]);
	hash_64[2002] = *((uint64_t*)&dataset[hash_32[4002]]);
	hash_64[2003] = *((uint64_t*)&dataset[hash_32[4003]]);
	hash_64[2004] = *((uint64_t*)&dataset[hash_32[4004]]);
	hash_64[2005] = *((uint64_t*)&dataset[hash_32[4005]]);
	hash_64[2006] = *((uint64_t*)&dataset[hash_32[4006]]);
	hash_64[2007] = *((uint64_t*)&dataset[hash_32[4007]]);
	hash_64[2008] = *((uint64_t*)&dataset[hash_32[4008]]);
	hash_64[2009] = *((uint64_t*)&dataset[hash_32[4009]]);
	hash_64[2010] = *((uint64_t*)&dataset[hash_32[4010]]);
	hash_64[2011] = *((uint64_t*)&dataset[hash_32[4011]]);
	hash_64[2012] = *((uint64_t*)&dataset[hash_32[4012]]);
	hash_64[2013] = *((uint64_t*)&dataset[hash_32[4013]]);
	hash_64[2014] = *((uint64_t*)&dataset[hash_32[4014]]);
	hash_64[2015] = *((uint64_t*)&dataset[hash_32[4015]]);
#endif
#if MEMORY_THREADS > 126
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2016] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2017] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2018] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2019] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2020] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2021] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2022] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2023] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2016] = *((uint64_t*)&dataset[hash_32[4032]]);
	hash_64[2017] = *((uint64_t*)&dataset[hash_32[4033]]);
	hash_64[2018] = *((uint64_t*)&dataset[hash_32[4034]]);
	hash_64[2019] = *((uint64_t*)&dataset[hash_32[4035]]);
	hash_64[2020] = *((uint64_t*)&dataset[hash_32[4036]]);
	hash_64[2021] = *((uint64_t*)&dataset[hash_32[4037]]);
	hash_64[2022] = *((uint64_t*)&dataset[hash_32[4038]]);
	hash_64[2023] = *((uint64_t*)&dataset[hash_32[4039]]);
	hash_64[2024] = *((uint64_t*)&dataset[hash_32[4040]]);
	hash_64[2025] = *((uint64_t*)&dataset[hash_32[4041]]);
	hash_64[2026] = *((uint64_t*)&dataset[hash_32[4042]]);
	hash_64[2027] = *((uint64_t*)&dataset[hash_32[4043]]);
	hash_64[2028] = *((uint64_t*)&dataset[hash_32[4044]]);
	hash_64[2029] = *((uint64_t*)&dataset[hash_32[4045]]);
	hash_64[2030] = *((uint64_t*)&dataset[hash_32[4046]]);
	hash_64[2031] = *((uint64_t*)&dataset[hash_32[4047]]);
#endif
#if MEMORY_THREADS > 127
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2032] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2033] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2034] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2035] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2036] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2037] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2038] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2039] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2032] = *((uint64_t*)&dataset[hash_32[4064]]);
	hash_64[2033] = *((uint64_t*)&dataset[hash_32[4065]]);
	hash_64[2034] = *((uint64_t*)&dataset[hash_32[4066]]);
	hash_64[2035] = *((uint64_t*)&dataset[hash_32[4067]]);
	hash_64[2036] = *((uint64_t*)&dataset[hash_32[4068]]);
	hash_64[2037] = *((uint64_t*)&dataset[hash_32[4069]]);
	hash_64[2038] = *((uint64_t*)&dataset[hash_32[4070]]);
	hash_64[2039] = *((uint64_t*)&dataset[hash_32[4071]]);
	hash_64[2040] = *((uint64_t*)&dataset[hash_32[4072]]);
	hash_64[2041] = *((uint64_t*)&dataset[hash_32[4073]]);
	hash_64[2042] = *((uint64_t*)&dataset[hash_32[4074]]);
	hash_64[2043] = *((uint64_t*)&dataset[hash_32[4075]]);
	hash_64[2044] = *((uint64_t*)&dataset[hash_32[4076]]);
	hash_64[2045] = *((uint64_t*)&dataset[hash_32[4077]]);
	hash_64[2046] = *((uint64_t*)&dataset[hash_32[4078]]);
	hash_64[2047] = *((uint64_t*)&dataset[hash_32[4079]]);
#endif
#if MEMORY_THREADS > 128
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2048] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2049] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2050] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2051] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2052] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2053] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2054] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2055] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2048] = *((uint64_t*)&dataset[hash_32[4096]]);
	hash_64[2049] = *((uint64_t*)&dataset[hash_32[4097]]);
	hash_64[2050] = *((uint64_t*)&dataset[hash_32[4098]]);
	hash_64[2051] = *((uint64_t*)&dataset[hash_32[4099]]);
	hash_64[2052] = *((uint64_t*)&dataset[hash_32[4100]]);
	hash_64[2053] = *((uint64_t*)&dataset[hash_32[4101]]);
	hash_64[2054] = *((uint64_t*)&dataset[hash_32[4102]]);
	hash_64[2055] = *((uint64_t*)&dataset[hash_32[4103]]);
	hash_64[2056] = *((uint64_t*)&dataset[hash_32[4104]]);
	hash_64[2057] = *((uint64_t*)&dataset[hash_32[4105]]);
	hash_64[2058] = *((uint64_t*)&dataset[hash_32[4106]]);
	hash_64[2059] = *((uint64_t*)&dataset[hash_32[4107]]);
	hash_64[2060] = *((uint64_t*)&dataset[hash_32[4108]]);
	hash_64[2061] = *((uint64_t*)&dataset[hash_32[4109]]);
	hash_64[2062] = *((uint64_t*)&dataset[hash_32[4110]]);
	hash_64[2063] = *((uint64_t*)&dataset[hash_32[4111]]);
#endif
#if MEMORY_THREADS > 129
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2064] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2065] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2066] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2067] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2068] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2069] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2070] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2071] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2064] = *((uint64_t*)&dataset[hash_32[4128]]);
	hash_64[2065] = *((uint64_t*)&dataset[hash_32[4129]]);
	hash_64[2066] = *((uint64_t*)&dataset[hash_32[4130]]);
	hash_64[2067] = *((uint64_t*)&dataset[hash_32[4131]]);
	hash_64[2068] = *((uint64_t*)&dataset[hash_32[4132]]);
	hash_64[2069] = *((uint64_t*)&dataset[hash_32[4133]]);
	hash_64[2070] = *((uint64_t*)&dataset[hash_32[4134]]);
	hash_64[2071] = *((uint64_t*)&dataset[hash_32[4135]]);
	hash_64[2072] = *((uint64_t*)&dataset[hash_32[4136]]);
	hash_64[2073] = *((uint64_t*)&dataset[hash_32[4137]]);
	hash_64[2074] = *((uint64_t*)&dataset[hash_32[4138]]);
	hash_64[2075] = *((uint64_t*)&dataset[hash_32[4139]]);
	hash_64[2076] = *((uint64_t*)&dataset[hash_32[4140]]);
	hash_64[2077] = *((uint64_t*)&dataset[hash_32[4141]]);
	hash_64[2078] = *((uint64_t*)&dataset[hash_32[4142]]);
	hash_64[2079] = *((uint64_t*)&dataset[hash_32[4143]]);
#endif
#if MEMORY_THREADS > 130
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2080] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2081] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2082] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2083] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2084] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2085] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2086] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2087] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2080] = *((uint64_t*)&dataset[hash_32[4160]]);
	hash_64[2081] = *((uint64_t*)&dataset[hash_32[4161]]);
	hash_64[2082] = *((uint64_t*)&dataset[hash_32[4162]]);
	hash_64[2083] = *((uint64_t*)&dataset[hash_32[4163]]);
	hash_64[2084] = *((uint64_t*)&dataset[hash_32[4164]]);
	hash_64[2085] = *((uint64_t*)&dataset[hash_32[4165]]);
	hash_64[2086] = *((uint64_t*)&dataset[hash_32[4166]]);
	hash_64[2087] = *((uint64_t*)&dataset[hash_32[4167]]);
	hash_64[2088] = *((uint64_t*)&dataset[hash_32[4168]]);
	hash_64[2089] = *((uint64_t*)&dataset[hash_32[4169]]);
	hash_64[2090] = *((uint64_t*)&dataset[hash_32[4170]]);
	hash_64[2091] = *((uint64_t*)&dataset[hash_32[4171]]);
	hash_64[2092] = *((uint64_t*)&dataset[hash_32[4172]]);
	hash_64[2093] = *((uint64_t*)&dataset[hash_32[4173]]);
	hash_64[2094] = *((uint64_t*)&dataset[hash_32[4174]]);
	hash_64[2095] = *((uint64_t*)&dataset[hash_32[4175]]);
#endif
#if MEMORY_THREADS > 131
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2096] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2097] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2098] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2099] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2100] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2101] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2102] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2103] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2096] = *((uint64_t*)&dataset[hash_32[4192]]);
	hash_64[2097] = *((uint64_t*)&dataset[hash_32[4193]]);
	hash_64[2098] = *((uint64_t*)&dataset[hash_32[4194]]);
	hash_64[2099] = *((uint64_t*)&dataset[hash_32[4195]]);
	hash_64[2100] = *((uint64_t*)&dataset[hash_32[4196]]);
	hash_64[2101] = *((uint64_t*)&dataset[hash_32[4197]]);
	hash_64[2102] = *((uint64_t*)&dataset[hash_32[4198]]);
	hash_64[2103] = *((uint64_t*)&dataset[hash_32[4199]]);
	hash_64[2104] = *((uint64_t*)&dataset[hash_32[4200]]);
	hash_64[2105] = *((uint64_t*)&dataset[hash_32[4201]]);
	hash_64[2106] = *((uint64_t*)&dataset[hash_32[4202]]);
	hash_64[2107] = *((uint64_t*)&dataset[hash_32[4203]]);
	hash_64[2108] = *((uint64_t*)&dataset[hash_32[4204]]);
	hash_64[2109] = *((uint64_t*)&dataset[hash_32[4205]]);
	hash_64[2110] = *((uint64_t*)&dataset[hash_32[4206]]);
	hash_64[2111] = *((uint64_t*)&dataset[hash_32[4207]]);
#endif
#if MEMORY_THREADS > 132
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2112] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2113] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2114] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2115] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2116] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2117] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2118] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2119] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2112] = *((uint64_t*)&dataset[hash_32[4224]]);
	hash_64[2113] = *((uint64_t*)&dataset[hash_32[4225]]);
	hash_64[2114] = *((uint64_t*)&dataset[hash_32[4226]]);
	hash_64[2115] = *((uint64_t*)&dataset[hash_32[4227]]);
	hash_64[2116] = *((uint64_t*)&dataset[hash_32[4228]]);
	hash_64[2117] = *((uint64_t*)&dataset[hash_32[4229]]);
	hash_64[2118] = *((uint64_t*)&dataset[hash_32[4230]]);
	hash_64[2119] = *((uint64_t*)&dataset[hash_32[4231]]);
	hash_64[2120] = *((uint64_t*)&dataset[hash_32[4232]]);
	hash_64[2121] = *((uint64_t*)&dataset[hash_32[4233]]);
	hash_64[2122] = *((uint64_t*)&dataset[hash_32[4234]]);
	hash_64[2123] = *((uint64_t*)&dataset[hash_32[4235]]);
	hash_64[2124] = *((uint64_t*)&dataset[hash_32[4236]]);
	hash_64[2125] = *((uint64_t*)&dataset[hash_32[4237]]);
	hash_64[2126] = *((uint64_t*)&dataset[hash_32[4238]]);
	hash_64[2127] = *((uint64_t*)&dataset[hash_32[4239]]);
#endif
#if MEMORY_THREADS > 133
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2128] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2129] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2130] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2131] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2132] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2133] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2134] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2135] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2128] = *((uint64_t*)&dataset[hash_32[4256]]);
	hash_64[2129] = *((uint64_t*)&dataset[hash_32[4257]]);
	hash_64[2130] = *((uint64_t*)&dataset[hash_32[4258]]);
	hash_64[2131] = *((uint64_t*)&dataset[hash_32[4259]]);
	hash_64[2132] = *((uint64_t*)&dataset[hash_32[4260]]);
	hash_64[2133] = *((uint64_t*)&dataset[hash_32[4261]]);
	hash_64[2134] = *((uint64_t*)&dataset[hash_32[4262]]);
	hash_64[2135] = *((uint64_t*)&dataset[hash_32[4263]]);
	hash_64[2136] = *((uint64_t*)&dataset[hash_32[4264]]);
	hash_64[2137] = *((uint64_t*)&dataset[hash_32[4265]]);
	hash_64[2138] = *((uint64_t*)&dataset[hash_32[4266]]);
	hash_64[2139] = *((uint64_t*)&dataset[hash_32[4267]]);
	hash_64[2140] = *((uint64_t*)&dataset[hash_32[4268]]);
	hash_64[2141] = *((uint64_t*)&dataset[hash_32[4269]]);
	hash_64[2142] = *((uint64_t*)&dataset[hash_32[4270]]);
	hash_64[2143] = *((uint64_t*)&dataset[hash_32[4271]]);
#endif
#if MEMORY_THREADS > 134
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2144] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2145] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2146] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2147] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2148] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2149] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2150] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2151] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2144] = *((uint64_t*)&dataset[hash_32[4288]]);
	hash_64[2145] = *((uint64_t*)&dataset[hash_32[4289]]);
	hash_64[2146] = *((uint64_t*)&dataset[hash_32[4290]]);
	hash_64[2147] = *((uint64_t*)&dataset[hash_32[4291]]);
	hash_64[2148] = *((uint64_t*)&dataset[hash_32[4292]]);
	hash_64[2149] = *((uint64_t*)&dataset[hash_32[4293]]);
	hash_64[2150] = *((uint64_t*)&dataset[hash_32[4294]]);
	hash_64[2151] = *((uint64_t*)&dataset[hash_32[4295]]);
	hash_64[2152] = *((uint64_t*)&dataset[hash_32[4296]]);
	hash_64[2153] = *((uint64_t*)&dataset[hash_32[4297]]);
	hash_64[2154] = *((uint64_t*)&dataset[hash_32[4298]]);
	hash_64[2155] = *((uint64_t*)&dataset[hash_32[4299]]);
	hash_64[2156] = *((uint64_t*)&dataset[hash_32[4300]]);
	hash_64[2157] = *((uint64_t*)&dataset[hash_32[4301]]);
	hash_64[2158] = *((uint64_t*)&dataset[hash_32[4302]]);
	hash_64[2159] = *((uint64_t*)&dataset[hash_32[4303]]);
#endif
#if MEMORY_THREADS > 135
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2160] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2161] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2162] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2163] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2164] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2165] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2166] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2167] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2160] = *((uint64_t*)&dataset[hash_32[4320]]);
	hash_64[2161] = *((uint64_t*)&dataset[hash_32[4321]]);
	hash_64[2162] = *((uint64_t*)&dataset[hash_32[4322]]);
	hash_64[2163] = *((uint64_t*)&dataset[hash_32[4323]]);
	hash_64[2164] = *((uint64_t*)&dataset[hash_32[4324]]);
	hash_64[2165] = *((uint64_t*)&dataset[hash_32[4325]]);
	hash_64[2166] = *((uint64_t*)&dataset[hash_32[4326]]);
	hash_64[2167] = *((uint64_t*)&dataset[hash_32[4327]]);
	hash_64[2168] = *((uint64_t*)&dataset[hash_32[4328]]);
	hash_64[2169] = *((uint64_t*)&dataset[hash_32[4329]]);
	hash_64[2170] = *((uint64_t*)&dataset[hash_32[4330]]);
	hash_64[2171] = *((uint64_t*)&dataset[hash_32[4331]]);
	hash_64[2172] = *((uint64_t*)&dataset[hash_32[4332]]);
	hash_64[2173] = *((uint64_t*)&dataset[hash_32[4333]]);
	hash_64[2174] = *((uint64_t*)&dataset[hash_32[4334]]);
	hash_64[2175] = *((uint64_t*)&dataset[hash_32[4335]]);
#endif
#if MEMORY_THREADS > 136
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2176] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2177] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2178] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2179] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2180] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2181] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2182] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2183] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2176] = *((uint64_t*)&dataset[hash_32[4352]]);
	hash_64[2177] = *((uint64_t*)&dataset[hash_32[4353]]);
	hash_64[2178] = *((uint64_t*)&dataset[hash_32[4354]]);
	hash_64[2179] = *((uint64_t*)&dataset[hash_32[4355]]);
	hash_64[2180] = *((uint64_t*)&dataset[hash_32[4356]]);
	hash_64[2181] = *((uint64_t*)&dataset[hash_32[4357]]);
	hash_64[2182] = *((uint64_t*)&dataset[hash_32[4358]]);
	hash_64[2183] = *((uint64_t*)&dataset[hash_32[4359]]);
	hash_64[2184] = *((uint64_t*)&dataset[hash_32[4360]]);
	hash_64[2185] = *((uint64_t*)&dataset[hash_32[4361]]);
	hash_64[2186] = *((uint64_t*)&dataset[hash_32[4362]]);
	hash_64[2187] = *((uint64_t*)&dataset[hash_32[4363]]);
	hash_64[2188] = *((uint64_t*)&dataset[hash_32[4364]]);
	hash_64[2189] = *((uint64_t*)&dataset[hash_32[4365]]);
	hash_64[2190] = *((uint64_t*)&dataset[hash_32[4366]]);
	hash_64[2191] = *((uint64_t*)&dataset[hash_32[4367]]);
#endif
#if MEMORY_THREADS > 137
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2192] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2193] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2194] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2195] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2196] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2197] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2198] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2199] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2192] = *((uint64_t*)&dataset[hash_32[4384]]);
	hash_64[2193] = *((uint64_t*)&dataset[hash_32[4385]]);
	hash_64[2194] = *((uint64_t*)&dataset[hash_32[4386]]);
	hash_64[2195] = *((uint64_t*)&dataset[hash_32[4387]]);
	hash_64[2196] = *((uint64_t*)&dataset[hash_32[4388]]);
	hash_64[2197] = *((uint64_t*)&dataset[hash_32[4389]]);
	hash_64[2198] = *((uint64_t*)&dataset[hash_32[4390]]);
	hash_64[2199] = *((uint64_t*)&dataset[hash_32[4391]]);
	hash_64[2200] = *((uint64_t*)&dataset[hash_32[4392]]);
	hash_64[2201] = *((uint64_t*)&dataset[hash_32[4393]]);
	hash_64[2202] = *((uint64_t*)&dataset[hash_32[4394]]);
	hash_64[2203] = *((uint64_t*)&dataset[hash_32[4395]]);
	hash_64[2204] = *((uint64_t*)&dataset[hash_32[4396]]);
	hash_64[2205] = *((uint64_t*)&dataset[hash_32[4397]]);
	hash_64[2206] = *((uint64_t*)&dataset[hash_32[4398]]);
	hash_64[2207] = *((uint64_t*)&dataset[hash_32[4399]]);
#endif
#if MEMORY_THREADS > 138
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2208] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2209] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2210] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2211] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2212] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2213] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2214] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2215] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2208] = *((uint64_t*)&dataset[hash_32[4416]]);
	hash_64[2209] = *((uint64_t*)&dataset[hash_32[4417]]);
	hash_64[2210] = *((uint64_t*)&dataset[hash_32[4418]]);
	hash_64[2211] = *((uint64_t*)&dataset[hash_32[4419]]);
	hash_64[2212] = *((uint64_t*)&dataset[hash_32[4420]]);
	hash_64[2213] = *((uint64_t*)&dataset[hash_32[4421]]);
	hash_64[2214] = *((uint64_t*)&dataset[hash_32[4422]]);
	hash_64[2215] = *((uint64_t*)&dataset[hash_32[4423]]);
	hash_64[2216] = *((uint64_t*)&dataset[hash_32[4424]]);
	hash_64[2217] = *((uint64_t*)&dataset[hash_32[4425]]);
	hash_64[2218] = *((uint64_t*)&dataset[hash_32[4426]]);
	hash_64[2219] = *((uint64_t*)&dataset[hash_32[4427]]);
	hash_64[2220] = *((uint64_t*)&dataset[hash_32[4428]]);
	hash_64[2221] = *((uint64_t*)&dataset[hash_32[4429]]);
	hash_64[2222] = *((uint64_t*)&dataset[hash_32[4430]]);
	hash_64[2223] = *((uint64_t*)&dataset[hash_32[4431]]);
#endif
#if MEMORY_THREADS > 139
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2224] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2225] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2226] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2227] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2228] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2229] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2230] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2231] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2224] = *((uint64_t*)&dataset[hash_32[4448]]);
	hash_64[2225] = *((uint64_t*)&dataset[hash_32[4449]]);
	hash_64[2226] = *((uint64_t*)&dataset[hash_32[4450]]);
	hash_64[2227] = *((uint64_t*)&dataset[hash_32[4451]]);
	hash_64[2228] = *((uint64_t*)&dataset[hash_32[4452]]);
	hash_64[2229] = *((uint64_t*)&dataset[hash_32[4453]]);
	hash_64[2230] = *((uint64_t*)&dataset[hash_32[4454]]);
	hash_64[2231] = *((uint64_t*)&dataset[hash_32[4455]]);
	hash_64[2232] = *((uint64_t*)&dataset[hash_32[4456]]);
	hash_64[2233] = *((uint64_t*)&dataset[hash_32[4457]]);
	hash_64[2234] = *((uint64_t*)&dataset[hash_32[4458]]);
	hash_64[2235] = *((uint64_t*)&dataset[hash_32[4459]]);
	hash_64[2236] = *((uint64_t*)&dataset[hash_32[4460]]);
	hash_64[2237] = *((uint64_t*)&dataset[hash_32[4461]]);
	hash_64[2238] = *((uint64_t*)&dataset[hash_32[4462]]);
	hash_64[2239] = *((uint64_t*)&dataset[hash_32[4463]]);
#endif
#if MEMORY_THREADS > 140
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2240] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2241] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2242] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2243] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2244] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2245] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2246] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2247] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2240] = *((uint64_t*)&dataset[hash_32[4480]]);
	hash_64[2241] = *((uint64_t*)&dataset[hash_32[4481]]);
	hash_64[2242] = *((uint64_t*)&dataset[hash_32[4482]]);
	hash_64[2243] = *((uint64_t*)&dataset[hash_32[4483]]);
	hash_64[2244] = *((uint64_t*)&dataset[hash_32[4484]]);
	hash_64[2245] = *((uint64_t*)&dataset[hash_32[4485]]);
	hash_64[2246] = *((uint64_t*)&dataset[hash_32[4486]]);
	hash_64[2247] = *((uint64_t*)&dataset[hash_32[4487]]);
	hash_64[2248] = *((uint64_t*)&dataset[hash_32[4488]]);
	hash_64[2249] = *((uint64_t*)&dataset[hash_32[4489]]);
	hash_64[2250] = *((uint64_t*)&dataset[hash_32[4490]]);
	hash_64[2251] = *((uint64_t*)&dataset[hash_32[4491]]);
	hash_64[2252] = *((uint64_t*)&dataset[hash_32[4492]]);
	hash_64[2253] = *((uint64_t*)&dataset[hash_32[4493]]);
	hash_64[2254] = *((uint64_t*)&dataset[hash_32[4494]]);
	hash_64[2255] = *((uint64_t*)&dataset[hash_32[4495]]);
#endif
#if MEMORY_THREADS > 141
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2256] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2257] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2258] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2259] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2260] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2261] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2262] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2263] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2256] = *((uint64_t*)&dataset[hash_32[4512]]);
	hash_64[2257] = *((uint64_t*)&dataset[hash_32[4513]]);
	hash_64[2258] = *((uint64_t*)&dataset[hash_32[4514]]);
	hash_64[2259] = *((uint64_t*)&dataset[hash_32[4515]]);
	hash_64[2260] = *((uint64_t*)&dataset[hash_32[4516]]);
	hash_64[2261] = *((uint64_t*)&dataset[hash_32[4517]]);
	hash_64[2262] = *((uint64_t*)&dataset[hash_32[4518]]);
	hash_64[2263] = *((uint64_t*)&dataset[hash_32[4519]]);
	hash_64[2264] = *((uint64_t*)&dataset[hash_32[4520]]);
	hash_64[2265] = *((uint64_t*)&dataset[hash_32[4521]]);
	hash_64[2266] = *((uint64_t*)&dataset[hash_32[4522]]);
	hash_64[2267] = *((uint64_t*)&dataset[hash_32[4523]]);
	hash_64[2268] = *((uint64_t*)&dataset[hash_32[4524]]);
	hash_64[2269] = *((uint64_t*)&dataset[hash_32[4525]]);
	hash_64[2270] = *((uint64_t*)&dataset[hash_32[4526]]);
	hash_64[2271] = *((uint64_t*)&dataset[hash_32[4527]]);
#endif
#if MEMORY_THREADS > 142
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2272] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2273] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2274] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2275] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2276] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2277] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2278] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2279] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2272] = *((uint64_t*)&dataset[hash_32[4544]]);
	hash_64[2273] = *((uint64_t*)&dataset[hash_32[4545]]);
	hash_64[2274] = *((uint64_t*)&dataset[hash_32[4546]]);
	hash_64[2275] = *((uint64_t*)&dataset[hash_32[4547]]);
	hash_64[2276] = *((uint64_t*)&dataset[hash_32[4548]]);
	hash_64[2277] = *((uint64_t*)&dataset[hash_32[4549]]);
	hash_64[2278] = *((uint64_t*)&dataset[hash_32[4550]]);
	hash_64[2279] = *((uint64_t*)&dataset[hash_32[4551]]);
	hash_64[2280] = *((uint64_t*)&dataset[hash_32[4552]]);
	hash_64[2281] = *((uint64_t*)&dataset[hash_32[4553]]);
	hash_64[2282] = *((uint64_t*)&dataset[hash_32[4554]]);
	hash_64[2283] = *((uint64_t*)&dataset[hash_32[4555]]);
	hash_64[2284] = *((uint64_t*)&dataset[hash_32[4556]]);
	hash_64[2285] = *((uint64_t*)&dataset[hash_32[4557]]);
	hash_64[2286] = *((uint64_t*)&dataset[hash_32[4558]]);
	hash_64[2287] = *((uint64_t*)&dataset[hash_32[4559]]);
#endif
#if MEMORY_THREADS > 143
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2288] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2289] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2290] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2291] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2292] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2293] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2294] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2295] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2288] = *((uint64_t*)&dataset[hash_32[4576]]);
	hash_64[2289] = *((uint64_t*)&dataset[hash_32[4577]]);
	hash_64[2290] = *((uint64_t*)&dataset[hash_32[4578]]);
	hash_64[2291] = *((uint64_t*)&dataset[hash_32[4579]]);
	hash_64[2292] = *((uint64_t*)&dataset[hash_32[4580]]);
	hash_64[2293] = *((uint64_t*)&dataset[hash_32[4581]]);
	hash_64[2294] = *((uint64_t*)&dataset[hash_32[4582]]);
	hash_64[2295] = *((uint64_t*)&dataset[hash_32[4583]]);
	hash_64[2296] = *((uint64_t*)&dataset[hash_32[4584]]);
	hash_64[2297] = *((uint64_t*)&dataset[hash_32[4585]]);
	hash_64[2298] = *((uint64_t*)&dataset[hash_32[4586]]);
	hash_64[2299] = *((uint64_t*)&dataset[hash_32[4587]]);
	hash_64[2300] = *((uint64_t*)&dataset[hash_32[4588]]);
	hash_64[2301] = *((uint64_t*)&dataset[hash_32[4589]]);
	hash_64[2302] = *((uint64_t*)&dataset[hash_32[4590]]);
	hash_64[2303] = *((uint64_t*)&dataset[hash_32[4591]]);
#endif
#if MEMORY_THREADS > 144
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2304] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2305] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2306] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2307] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2308] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2309] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2310] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2311] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2304] = *((uint64_t*)&dataset[hash_32[4608]]);
	hash_64[2305] = *((uint64_t*)&dataset[hash_32[4609]]);
	hash_64[2306] = *((uint64_t*)&dataset[hash_32[4610]]);
	hash_64[2307] = *((uint64_t*)&dataset[hash_32[4611]]);
	hash_64[2308] = *((uint64_t*)&dataset[hash_32[4612]]);
	hash_64[2309] = *((uint64_t*)&dataset[hash_32[4613]]);
	hash_64[2310] = *((uint64_t*)&dataset[hash_32[4614]]);
	hash_64[2311] = *((uint64_t*)&dataset[hash_32[4615]]);
	hash_64[2312] = *((uint64_t*)&dataset[hash_32[4616]]);
	hash_64[2313] = *((uint64_t*)&dataset[hash_32[4617]]);
	hash_64[2314] = *((uint64_t*)&dataset[hash_32[4618]]);
	hash_64[2315] = *((uint64_t*)&dataset[hash_32[4619]]);
	hash_64[2316] = *((uint64_t*)&dataset[hash_32[4620]]);
	hash_64[2317] = *((uint64_t*)&dataset[hash_32[4621]]);
	hash_64[2318] = *((uint64_t*)&dataset[hash_32[4622]]);
	hash_64[2319] = *((uint64_t*)&dataset[hash_32[4623]]);
#endif
#if MEMORY_THREADS > 145
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2320] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2321] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2322] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2323] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2324] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2325] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2326] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2327] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2320] = *((uint64_t*)&dataset[hash_32[4640]]);
	hash_64[2321] = *((uint64_t*)&dataset[hash_32[4641]]);
	hash_64[2322] = *((uint64_t*)&dataset[hash_32[4642]]);
	hash_64[2323] = *((uint64_t*)&dataset[hash_32[4643]]);
	hash_64[2324] = *((uint64_t*)&dataset[hash_32[4644]]);
	hash_64[2325] = *((uint64_t*)&dataset[hash_32[4645]]);
	hash_64[2326] = *((uint64_t*)&dataset[hash_32[4646]]);
	hash_64[2327] = *((uint64_t*)&dataset[hash_32[4647]]);
	hash_64[2328] = *((uint64_t*)&dataset[hash_32[4648]]);
	hash_64[2329] = *((uint64_t*)&dataset[hash_32[4649]]);
	hash_64[2330] = *((uint64_t*)&dataset[hash_32[4650]]);
	hash_64[2331] = *((uint64_t*)&dataset[hash_32[4651]]);
	hash_64[2332] = *((uint64_t*)&dataset[hash_32[4652]]);
	hash_64[2333] = *((uint64_t*)&dataset[hash_32[4653]]);
	hash_64[2334] = *((uint64_t*)&dataset[hash_32[4654]]);
	hash_64[2335] = *((uint64_t*)&dataset[hash_32[4655]]);
#endif
#if MEMORY_THREADS > 146
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2336] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2337] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2338] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2339] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2340] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2341] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2342] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2343] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2336] = *((uint64_t*)&dataset[hash_32[4672]]);
	hash_64[2337] = *((uint64_t*)&dataset[hash_32[4673]]);
	hash_64[2338] = *((uint64_t*)&dataset[hash_32[4674]]);
	hash_64[2339] = *((uint64_t*)&dataset[hash_32[4675]]);
	hash_64[2340] = *((uint64_t*)&dataset[hash_32[4676]]);
	hash_64[2341] = *((uint64_t*)&dataset[hash_32[4677]]);
	hash_64[2342] = *((uint64_t*)&dataset[hash_32[4678]]);
	hash_64[2343] = *((uint64_t*)&dataset[hash_32[4679]]);
	hash_64[2344] = *((uint64_t*)&dataset[hash_32[4680]]);
	hash_64[2345] = *((uint64_t*)&dataset[hash_32[4681]]);
	hash_64[2346] = *((uint64_t*)&dataset[hash_32[4682]]);
	hash_64[2347] = *((uint64_t*)&dataset[hash_32[4683]]);
	hash_64[2348] = *((uint64_t*)&dataset[hash_32[4684]]);
	hash_64[2349] = *((uint64_t*)&dataset[hash_32[4685]]);
	hash_64[2350] = *((uint64_t*)&dataset[hash_32[4686]]);
	hash_64[2351] = *((uint64_t*)&dataset[hash_32[4687]]);
#endif
#if MEMORY_THREADS > 147
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2352] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2353] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2354] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2355] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2356] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2357] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2358] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2359] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2352] = *((uint64_t*)&dataset[hash_32[4704]]);
	hash_64[2353] = *((uint64_t*)&dataset[hash_32[4705]]);
	hash_64[2354] = *((uint64_t*)&dataset[hash_32[4706]]);
	hash_64[2355] = *((uint64_t*)&dataset[hash_32[4707]]);
	hash_64[2356] = *((uint64_t*)&dataset[hash_32[4708]]);
	hash_64[2357] = *((uint64_t*)&dataset[hash_32[4709]]);
	hash_64[2358] = *((uint64_t*)&dataset[hash_32[4710]]);
	hash_64[2359] = *((uint64_t*)&dataset[hash_32[4711]]);
	hash_64[2360] = *((uint64_t*)&dataset[hash_32[4712]]);
	hash_64[2361] = *((uint64_t*)&dataset[hash_32[4713]]);
	hash_64[2362] = *((uint64_t*)&dataset[hash_32[4714]]);
	hash_64[2363] = *((uint64_t*)&dataset[hash_32[4715]]);
	hash_64[2364] = *((uint64_t*)&dataset[hash_32[4716]]);
	hash_64[2365] = *((uint64_t*)&dataset[hash_32[4717]]);
	hash_64[2366] = *((uint64_t*)&dataset[hash_32[4718]]);
	hash_64[2367] = *((uint64_t*)&dataset[hash_32[4719]]);
#endif
#if MEMORY_THREADS > 148
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2368] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2369] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2370] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2371] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2372] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2373] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2374] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2375] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2368] = *((uint64_t*)&dataset[hash_32[4736]]);
	hash_64[2369] = *((uint64_t*)&dataset[hash_32[4737]]);
	hash_64[2370] = *((uint64_t*)&dataset[hash_32[4738]]);
	hash_64[2371] = *((uint64_t*)&dataset[hash_32[4739]]);
	hash_64[2372] = *((uint64_t*)&dataset[hash_32[4740]]);
	hash_64[2373] = *((uint64_t*)&dataset[hash_32[4741]]);
	hash_64[2374] = *((uint64_t*)&dataset[hash_32[4742]]);
	hash_64[2375] = *((uint64_t*)&dataset[hash_32[4743]]);
	hash_64[2376] = *((uint64_t*)&dataset[hash_32[4744]]);
	hash_64[2377] = *((uint64_t*)&dataset[hash_32[4745]]);
	hash_64[2378] = *((uint64_t*)&dataset[hash_32[4746]]);
	hash_64[2379] = *((uint64_t*)&dataset[hash_32[4747]]);
	hash_64[2380] = *((uint64_t*)&dataset[hash_32[4748]]);
	hash_64[2381] = *((uint64_t*)&dataset[hash_32[4749]]);
	hash_64[2382] = *((uint64_t*)&dataset[hash_32[4750]]);
	hash_64[2383] = *((uint64_t*)&dataset[hash_32[4751]]);
#endif
#if MEMORY_THREADS > 149
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2384] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2385] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2386] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2387] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2388] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2389] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2390] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2391] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2384] = *((uint64_t*)&dataset[hash_32[4768]]);
	hash_64[2385] = *((uint64_t*)&dataset[hash_32[4769]]);
	hash_64[2386] = *((uint64_t*)&dataset[hash_32[4770]]);
	hash_64[2387] = *((uint64_t*)&dataset[hash_32[4771]]);
	hash_64[2388] = *((uint64_t*)&dataset[hash_32[4772]]);
	hash_64[2389] = *((uint64_t*)&dataset[hash_32[4773]]);
	hash_64[2390] = *((uint64_t*)&dataset[hash_32[4774]]);
	hash_64[2391] = *((uint64_t*)&dataset[hash_32[4775]]);
	hash_64[2392] = *((uint64_t*)&dataset[hash_32[4776]]);
	hash_64[2393] = *((uint64_t*)&dataset[hash_32[4777]]);
	hash_64[2394] = *((uint64_t*)&dataset[hash_32[4778]]);
	hash_64[2395] = *((uint64_t*)&dataset[hash_32[4779]]);
	hash_64[2396] = *((uint64_t*)&dataset[hash_32[4780]]);
	hash_64[2397] = *((uint64_t*)&dataset[hash_32[4781]]);
	hash_64[2398] = *((uint64_t*)&dataset[hash_32[4782]]);
	hash_64[2399] = *((uint64_t*)&dataset[hash_32[4783]]);
#endif
#if MEMORY_THREADS > 150
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2400] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2401] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2402] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2403] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2404] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2405] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2406] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2407] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2400] = *((uint64_t*)&dataset[hash_32[4800]]);
	hash_64[2401] = *((uint64_t*)&dataset[hash_32[4801]]);
	hash_64[2402] = *((uint64_t*)&dataset[hash_32[4802]]);
	hash_64[2403] = *((uint64_t*)&dataset[hash_32[4803]]);
	hash_64[2404] = *((uint64_t*)&dataset[hash_32[4804]]);
	hash_64[2405] = *((uint64_t*)&dataset[hash_32[4805]]);
	hash_64[2406] = *((uint64_t*)&dataset[hash_32[4806]]);
	hash_64[2407] = *((uint64_t*)&dataset[hash_32[4807]]);
	hash_64[2408] = *((uint64_t*)&dataset[hash_32[4808]]);
	hash_64[2409] = *((uint64_t*)&dataset[hash_32[4809]]);
	hash_64[2410] = *((uint64_t*)&dataset[hash_32[4810]]);
	hash_64[2411] = *((uint64_t*)&dataset[hash_32[4811]]);
	hash_64[2412] = *((uint64_t*)&dataset[hash_32[4812]]);
	hash_64[2413] = *((uint64_t*)&dataset[hash_32[4813]]);
	hash_64[2414] = *((uint64_t*)&dataset[hash_32[4814]]);
	hash_64[2415] = *((uint64_t*)&dataset[hash_32[4815]]);
#endif
#if MEMORY_THREADS > 151
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2416] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2417] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2418] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2419] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2420] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2421] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2422] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2423] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2416] = *((uint64_t*)&dataset[hash_32[4832]]);
	hash_64[2417] = *((uint64_t*)&dataset[hash_32[4833]]);
	hash_64[2418] = *((uint64_t*)&dataset[hash_32[4834]]);
	hash_64[2419] = *((uint64_t*)&dataset[hash_32[4835]]);
	hash_64[2420] = *((uint64_t*)&dataset[hash_32[4836]]);
	hash_64[2421] = *((uint64_t*)&dataset[hash_32[4837]]);
	hash_64[2422] = *((uint64_t*)&dataset[hash_32[4838]]);
	hash_64[2423] = *((uint64_t*)&dataset[hash_32[4839]]);
	hash_64[2424] = *((uint64_t*)&dataset[hash_32[4840]]);
	hash_64[2425] = *((uint64_t*)&dataset[hash_32[4841]]);
	hash_64[2426] = *((uint64_t*)&dataset[hash_32[4842]]);
	hash_64[2427] = *((uint64_t*)&dataset[hash_32[4843]]);
	hash_64[2428] = *((uint64_t*)&dataset[hash_32[4844]]);
	hash_64[2429] = *((uint64_t*)&dataset[hash_32[4845]]);
	hash_64[2430] = *((uint64_t*)&dataset[hash_32[4846]]);
	hash_64[2431] = *((uint64_t*)&dataset[hash_32[4847]]);
#endif
#if MEMORY_THREADS > 152
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2432] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2433] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2434] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2435] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2436] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2437] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2438] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2439] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2432] = *((uint64_t*)&dataset[hash_32[4864]]);
	hash_64[2433] = *((uint64_t*)&dataset[hash_32[4865]]);
	hash_64[2434] = *((uint64_t*)&dataset[hash_32[4866]]);
	hash_64[2435] = *((uint64_t*)&dataset[hash_32[4867]]);
	hash_64[2436] = *((uint64_t*)&dataset[hash_32[4868]]);
	hash_64[2437] = *((uint64_t*)&dataset[hash_32[4869]]);
	hash_64[2438] = *((uint64_t*)&dataset[hash_32[4870]]);
	hash_64[2439] = *((uint64_t*)&dataset[hash_32[4871]]);
	hash_64[2440] = *((uint64_t*)&dataset[hash_32[4872]]);
	hash_64[2441] = *((uint64_t*)&dataset[hash_32[4873]]);
	hash_64[2442] = *((uint64_t*)&dataset[hash_32[4874]]);
	hash_64[2443] = *((uint64_t*)&dataset[hash_32[4875]]);
	hash_64[2444] = *((uint64_t*)&dataset[hash_32[4876]]);
	hash_64[2445] = *((uint64_t*)&dataset[hash_32[4877]]);
	hash_64[2446] = *((uint64_t*)&dataset[hash_32[4878]]);
	hash_64[2447] = *((uint64_t*)&dataset[hash_32[4879]]);
#endif
#if MEMORY_THREADS > 153
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2448] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2449] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2450] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2451] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2452] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2453] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2454] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2455] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2448] = *((uint64_t*)&dataset[hash_32[4896]]);
	hash_64[2449] = *((uint64_t*)&dataset[hash_32[4897]]);
	hash_64[2450] = *((uint64_t*)&dataset[hash_32[4898]]);
	hash_64[2451] = *((uint64_t*)&dataset[hash_32[4899]]);
	hash_64[2452] = *((uint64_t*)&dataset[hash_32[4900]]);
	hash_64[2453] = *((uint64_t*)&dataset[hash_32[4901]]);
	hash_64[2454] = *((uint64_t*)&dataset[hash_32[4902]]);
	hash_64[2455] = *((uint64_t*)&dataset[hash_32[4903]]);
	hash_64[2456] = *((uint64_t*)&dataset[hash_32[4904]]);
	hash_64[2457] = *((uint64_t*)&dataset[hash_32[4905]]);
	hash_64[2458] = *((uint64_t*)&dataset[hash_32[4906]]);
	hash_64[2459] = *((uint64_t*)&dataset[hash_32[4907]]);
	hash_64[2460] = *((uint64_t*)&dataset[hash_32[4908]]);
	hash_64[2461] = *((uint64_t*)&dataset[hash_32[4909]]);
	hash_64[2462] = *((uint64_t*)&dataset[hash_32[4910]]);
	hash_64[2463] = *((uint64_t*)&dataset[hash_32[4911]]);
#endif
#if MEMORY_THREADS > 154
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2464] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2465] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2466] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2467] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2468] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2469] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2470] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2471] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2464] = *((uint64_t*)&dataset[hash_32[4928]]);
	hash_64[2465] = *((uint64_t*)&dataset[hash_32[4929]]);
	hash_64[2466] = *((uint64_t*)&dataset[hash_32[4930]]);
	hash_64[2467] = *((uint64_t*)&dataset[hash_32[4931]]);
	hash_64[2468] = *((uint64_t*)&dataset[hash_32[4932]]);
	hash_64[2469] = *((uint64_t*)&dataset[hash_32[4933]]);
	hash_64[2470] = *((uint64_t*)&dataset[hash_32[4934]]);
	hash_64[2471] = *((uint64_t*)&dataset[hash_32[4935]]);
	hash_64[2472] = *((uint64_t*)&dataset[hash_32[4936]]);
	hash_64[2473] = *((uint64_t*)&dataset[hash_32[4937]]);
	hash_64[2474] = *((uint64_t*)&dataset[hash_32[4938]]);
	hash_64[2475] = *((uint64_t*)&dataset[hash_32[4939]]);
	hash_64[2476] = *((uint64_t*)&dataset[hash_32[4940]]);
	hash_64[2477] = *((uint64_t*)&dataset[hash_32[4941]]);
	hash_64[2478] = *((uint64_t*)&dataset[hash_32[4942]]);
	hash_64[2479] = *((uint64_t*)&dataset[hash_32[4943]]);
#endif
#if MEMORY_THREADS > 155
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2480] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2481] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2482] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2483] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2484] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2485] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2486] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2487] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2480] = *((uint64_t*)&dataset[hash_32[4960]]);
	hash_64[2481] = *((uint64_t*)&dataset[hash_32[4961]]);
	hash_64[2482] = *((uint64_t*)&dataset[hash_32[4962]]);
	hash_64[2483] = *((uint64_t*)&dataset[hash_32[4963]]);
	hash_64[2484] = *((uint64_t*)&dataset[hash_32[4964]]);
	hash_64[2485] = *((uint64_t*)&dataset[hash_32[4965]]);
	hash_64[2486] = *((uint64_t*)&dataset[hash_32[4966]]);
	hash_64[2487] = *((uint64_t*)&dataset[hash_32[4967]]);
	hash_64[2488] = *((uint64_t*)&dataset[hash_32[4968]]);
	hash_64[2489] = *((uint64_t*)&dataset[hash_32[4969]]);
	hash_64[2490] = *((uint64_t*)&dataset[hash_32[4970]]);
	hash_64[2491] = *((uint64_t*)&dataset[hash_32[4971]]);
	hash_64[2492] = *((uint64_t*)&dataset[hash_32[4972]]);
	hash_64[2493] = *((uint64_t*)&dataset[hash_32[4973]]);
	hash_64[2494] = *((uint64_t*)&dataset[hash_32[4974]]);
	hash_64[2495] = *((uint64_t*)&dataset[hash_32[4975]]);
#endif
#if MEMORY_THREADS > 156
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2496] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2497] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2498] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2499] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2500] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2501] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2502] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2503] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2496] = *((uint64_t*)&dataset[hash_32[4992]]);
	hash_64[2497] = *((uint64_t*)&dataset[hash_32[4993]]);
	hash_64[2498] = *((uint64_t*)&dataset[hash_32[4994]]);
	hash_64[2499] = *((uint64_t*)&dataset[hash_32[4995]]);
	hash_64[2500] = *((uint64_t*)&dataset[hash_32[4996]]);
	hash_64[2501] = *((uint64_t*)&dataset[hash_32[4997]]);
	hash_64[2502] = *((uint64_t*)&dataset[hash_32[4998]]);
	hash_64[2503] = *((uint64_t*)&dataset[hash_32[4999]]);
	hash_64[2504] = *((uint64_t*)&dataset[hash_32[5000]]);
	hash_64[2505] = *((uint64_t*)&dataset[hash_32[5001]]);
	hash_64[2506] = *((uint64_t*)&dataset[hash_32[5002]]);
	hash_64[2507] = *((uint64_t*)&dataset[hash_32[5003]]);
	hash_64[2508] = *((uint64_t*)&dataset[hash_32[5004]]);
	hash_64[2509] = *((uint64_t*)&dataset[hash_32[5005]]);
	hash_64[2510] = *((uint64_t*)&dataset[hash_32[5006]]);
	hash_64[2511] = *((uint64_t*)&dataset[hash_32[5007]]);
#endif
#if MEMORY_THREADS > 157
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2512] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2513] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2514] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2515] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2516] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2517] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2518] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2519] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2512] = *((uint64_t*)&dataset[hash_32[5024]]);
	hash_64[2513] = *((uint64_t*)&dataset[hash_32[5025]]);
	hash_64[2514] = *((uint64_t*)&dataset[hash_32[5026]]);
	hash_64[2515] = *((uint64_t*)&dataset[hash_32[5027]]);
	hash_64[2516] = *((uint64_t*)&dataset[hash_32[5028]]);
	hash_64[2517] = *((uint64_t*)&dataset[hash_32[5029]]);
	hash_64[2518] = *((uint64_t*)&dataset[hash_32[5030]]);
	hash_64[2519] = *((uint64_t*)&dataset[hash_32[5031]]);
	hash_64[2520] = *((uint64_t*)&dataset[hash_32[5032]]);
	hash_64[2521] = *((uint64_t*)&dataset[hash_32[5033]]);
	hash_64[2522] = *((uint64_t*)&dataset[hash_32[5034]]);
	hash_64[2523] = *((uint64_t*)&dataset[hash_32[5035]]);
	hash_64[2524] = *((uint64_t*)&dataset[hash_32[5036]]);
	hash_64[2525] = *((uint64_t*)&dataset[hash_32[5037]]);
	hash_64[2526] = *((uint64_t*)&dataset[hash_32[5038]]);
	hash_64[2527] = *((uint64_t*)&dataset[hash_32[5039]]);
#endif
#if MEMORY_THREADS > 158
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2528] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2529] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2530] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2531] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2532] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2533] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2534] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2535] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2528] = *((uint64_t*)&dataset[hash_32[5056]]);
	hash_64[2529] = *((uint64_t*)&dataset[hash_32[5057]]);
	hash_64[2530] = *((uint64_t*)&dataset[hash_32[5058]]);
	hash_64[2531] = *((uint64_t*)&dataset[hash_32[5059]]);
	hash_64[2532] = *((uint64_t*)&dataset[hash_32[5060]]);
	hash_64[2533] = *((uint64_t*)&dataset[hash_32[5061]]);
	hash_64[2534] = *((uint64_t*)&dataset[hash_32[5062]]);
	hash_64[2535] = *((uint64_t*)&dataset[hash_32[5063]]);
	hash_64[2536] = *((uint64_t*)&dataset[hash_32[5064]]);
	hash_64[2537] = *((uint64_t*)&dataset[hash_32[5065]]);
	hash_64[2538] = *((uint64_t*)&dataset[hash_32[5066]]);
	hash_64[2539] = *((uint64_t*)&dataset[hash_32[5067]]);
	hash_64[2540] = *((uint64_t*)&dataset[hash_32[5068]]);
	hash_64[2541] = *((uint64_t*)&dataset[hash_32[5069]]);
	hash_64[2542] = *((uint64_t*)&dataset[hash_32[5070]]);
	hash_64[2543] = *((uint64_t*)&dataset[hash_32[5071]]);
#endif
#if MEMORY_THREADS > 159
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2544] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2545] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2546] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2547] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2548] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2549] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2550] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2551] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2544] = *((uint64_t*)&dataset[hash_32[5088]]);
	hash_64[2545] = *((uint64_t*)&dataset[hash_32[5089]]);
	hash_64[2546] = *((uint64_t*)&dataset[hash_32[5090]]);
	hash_64[2547] = *((uint64_t*)&dataset[hash_32[5091]]);
	hash_64[2548] = *((uint64_t*)&dataset[hash_32[5092]]);
	hash_64[2549] = *((uint64_t*)&dataset[hash_32[5093]]);
	hash_64[2550] = *((uint64_t*)&dataset[hash_32[5094]]);
	hash_64[2551] = *((uint64_t*)&dataset[hash_32[5095]]);
	hash_64[2552] = *((uint64_t*)&dataset[hash_32[5096]]);
	hash_64[2553] = *((uint64_t*)&dataset[hash_32[5097]]);
	hash_64[2554] = *((uint64_t*)&dataset[hash_32[5098]]);
	hash_64[2555] = *((uint64_t*)&dataset[hash_32[5099]]);
	hash_64[2556] = *((uint64_t*)&dataset[hash_32[5100]]);
	hash_64[2557] = *((uint64_t*)&dataset[hash_32[5101]]);
	hash_64[2558] = *((uint64_t*)&dataset[hash_32[5102]]);
	hash_64[2559] = *((uint64_t*)&dataset[hash_32[5103]]);
#endif
#if MEMORY_THREADS > 160
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2560] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2561] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2562] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2563] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2564] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2565] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2566] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2567] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2560] = *((uint64_t*)&dataset[hash_32[5120]]);
	hash_64[2561] = *((uint64_t*)&dataset[hash_32[5121]]);
	hash_64[2562] = *((uint64_t*)&dataset[hash_32[5122]]);
	hash_64[2563] = *((uint64_t*)&dataset[hash_32[5123]]);
	hash_64[2564] = *((uint64_t*)&dataset[hash_32[5124]]);
	hash_64[2565] = *((uint64_t*)&dataset[hash_32[5125]]);
	hash_64[2566] = *((uint64_t*)&dataset[hash_32[5126]]);
	hash_64[2567] = *((uint64_t*)&dataset[hash_32[5127]]);
	hash_64[2568] = *((uint64_t*)&dataset[hash_32[5128]]);
	hash_64[2569] = *((uint64_t*)&dataset[hash_32[5129]]);
	hash_64[2570] = *((uint64_t*)&dataset[hash_32[5130]]);
	hash_64[2571] = *((uint64_t*)&dataset[hash_32[5131]]);
	hash_64[2572] = *((uint64_t*)&dataset[hash_32[5132]]);
	hash_64[2573] = *((uint64_t*)&dataset[hash_32[5133]]);
	hash_64[2574] = *((uint64_t*)&dataset[hash_32[5134]]);
	hash_64[2575] = *((uint64_t*)&dataset[hash_32[5135]]);
#endif
#if MEMORY_THREADS > 161
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2576] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2577] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2578] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2579] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2580] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2581] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2582] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2583] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2576] = *((uint64_t*)&dataset[hash_32[5152]]);
	hash_64[2577] = *((uint64_t*)&dataset[hash_32[5153]]);
	hash_64[2578] = *((uint64_t*)&dataset[hash_32[5154]]);
	hash_64[2579] = *((uint64_t*)&dataset[hash_32[5155]]);
	hash_64[2580] = *((uint64_t*)&dataset[hash_32[5156]]);
	hash_64[2581] = *((uint64_t*)&dataset[hash_32[5157]]);
	hash_64[2582] = *((uint64_t*)&dataset[hash_32[5158]]);
	hash_64[2583] = *((uint64_t*)&dataset[hash_32[5159]]);
	hash_64[2584] = *((uint64_t*)&dataset[hash_32[5160]]);
	hash_64[2585] = *((uint64_t*)&dataset[hash_32[5161]]);
	hash_64[2586] = *((uint64_t*)&dataset[hash_32[5162]]);
	hash_64[2587] = *((uint64_t*)&dataset[hash_32[5163]]);
	hash_64[2588] = *((uint64_t*)&dataset[hash_32[5164]]);
	hash_64[2589] = *((uint64_t*)&dataset[hash_32[5165]]);
	hash_64[2590] = *((uint64_t*)&dataset[hash_32[5166]]);
	hash_64[2591] = *((uint64_t*)&dataset[hash_32[5167]]);
#endif
#if MEMORY_THREADS > 162
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2592] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2593] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2594] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2595] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2596] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2597] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2598] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2599] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2592] = *((uint64_t*)&dataset[hash_32[5184]]);
	hash_64[2593] = *((uint64_t*)&dataset[hash_32[5185]]);
	hash_64[2594] = *((uint64_t*)&dataset[hash_32[5186]]);
	hash_64[2595] = *((uint64_t*)&dataset[hash_32[5187]]);
	hash_64[2596] = *((uint64_t*)&dataset[hash_32[5188]]);
	hash_64[2597] = *((uint64_t*)&dataset[hash_32[5189]]);
	hash_64[2598] = *((uint64_t*)&dataset[hash_32[5190]]);
	hash_64[2599] = *((uint64_t*)&dataset[hash_32[5191]]);
	hash_64[2600] = *((uint64_t*)&dataset[hash_32[5192]]);
	hash_64[2601] = *((uint64_t*)&dataset[hash_32[5193]]);
	hash_64[2602] = *((uint64_t*)&dataset[hash_32[5194]]);
	hash_64[2603] = *((uint64_t*)&dataset[hash_32[5195]]);
	hash_64[2604] = *((uint64_t*)&dataset[hash_32[5196]]);
	hash_64[2605] = *((uint64_t*)&dataset[hash_32[5197]]);
	hash_64[2606] = *((uint64_t*)&dataset[hash_32[5198]]);
	hash_64[2607] = *((uint64_t*)&dataset[hash_32[5199]]);
#endif
#if MEMORY_THREADS > 163
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2608] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2609] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2610] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2611] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2612] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2613] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2614] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2615] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2608] = *((uint64_t*)&dataset[hash_32[5216]]);
	hash_64[2609] = *((uint64_t*)&dataset[hash_32[5217]]);
	hash_64[2610] = *((uint64_t*)&dataset[hash_32[5218]]);
	hash_64[2611] = *((uint64_t*)&dataset[hash_32[5219]]);
	hash_64[2612] = *((uint64_t*)&dataset[hash_32[5220]]);
	hash_64[2613] = *((uint64_t*)&dataset[hash_32[5221]]);
	hash_64[2614] = *((uint64_t*)&dataset[hash_32[5222]]);
	hash_64[2615] = *((uint64_t*)&dataset[hash_32[5223]]);
	hash_64[2616] = *((uint64_t*)&dataset[hash_32[5224]]);
	hash_64[2617] = *((uint64_t*)&dataset[hash_32[5225]]);
	hash_64[2618] = *((uint64_t*)&dataset[hash_32[5226]]);
	hash_64[2619] = *((uint64_t*)&dataset[hash_32[5227]]);
	hash_64[2620] = *((uint64_t*)&dataset[hash_32[5228]]);
	hash_64[2621] = *((uint64_t*)&dataset[hash_32[5229]]);
	hash_64[2622] = *((uint64_t*)&dataset[hash_32[5230]]);
	hash_64[2623] = *((uint64_t*)&dataset[hash_32[5231]]);
#endif
#if MEMORY_THREADS > 164
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2624] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2625] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2626] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2627] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2628] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2629] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2630] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2631] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2624] = *((uint64_t*)&dataset[hash_32[5248]]);
	hash_64[2625] = *((uint64_t*)&dataset[hash_32[5249]]);
	hash_64[2626] = *((uint64_t*)&dataset[hash_32[5250]]);
	hash_64[2627] = *((uint64_t*)&dataset[hash_32[5251]]);
	hash_64[2628] = *((uint64_t*)&dataset[hash_32[5252]]);
	hash_64[2629] = *((uint64_t*)&dataset[hash_32[5253]]);
	hash_64[2630] = *((uint64_t*)&dataset[hash_32[5254]]);
	hash_64[2631] = *((uint64_t*)&dataset[hash_32[5255]]);
	hash_64[2632] = *((uint64_t*)&dataset[hash_32[5256]]);
	hash_64[2633] = *((uint64_t*)&dataset[hash_32[5257]]);
	hash_64[2634] = *((uint64_t*)&dataset[hash_32[5258]]);
	hash_64[2635] = *((uint64_t*)&dataset[hash_32[5259]]);
	hash_64[2636] = *((uint64_t*)&dataset[hash_32[5260]]);
	hash_64[2637] = *((uint64_t*)&dataset[hash_32[5261]]);
	hash_64[2638] = *((uint64_t*)&dataset[hash_32[5262]]);
	hash_64[2639] = *((uint64_t*)&dataset[hash_32[5263]]);
#endif
#if MEMORY_THREADS > 165
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2640] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2641] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2642] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2643] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2644] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2645] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2646] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2647] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2640] = *((uint64_t*)&dataset[hash_32[5280]]);
	hash_64[2641] = *((uint64_t*)&dataset[hash_32[5281]]);
	hash_64[2642] = *((uint64_t*)&dataset[hash_32[5282]]);
	hash_64[2643] = *((uint64_t*)&dataset[hash_32[5283]]);
	hash_64[2644] = *((uint64_t*)&dataset[hash_32[5284]]);
	hash_64[2645] = *((uint64_t*)&dataset[hash_32[5285]]);
	hash_64[2646] = *((uint64_t*)&dataset[hash_32[5286]]);
	hash_64[2647] = *((uint64_t*)&dataset[hash_32[5287]]);
	hash_64[2648] = *((uint64_t*)&dataset[hash_32[5288]]);
	hash_64[2649] = *((uint64_t*)&dataset[hash_32[5289]]);
	hash_64[2650] = *((uint64_t*)&dataset[hash_32[5290]]);
	hash_64[2651] = *((uint64_t*)&dataset[hash_32[5291]]);
	hash_64[2652] = *((uint64_t*)&dataset[hash_32[5292]]);
	hash_64[2653] = *((uint64_t*)&dataset[hash_32[5293]]);
	hash_64[2654] = *((uint64_t*)&dataset[hash_32[5294]]);
	hash_64[2655] = *((uint64_t*)&dataset[hash_32[5295]]);
#endif
#if MEMORY_THREADS > 166
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2656] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2657] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2658] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2659] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2660] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2661] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2662] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2663] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2656] = *((uint64_t*)&dataset[hash_32[5312]]);
	hash_64[2657] = *((uint64_t*)&dataset[hash_32[5313]]);
	hash_64[2658] = *((uint64_t*)&dataset[hash_32[5314]]);
	hash_64[2659] = *((uint64_t*)&dataset[hash_32[5315]]);
	hash_64[2660] = *((uint64_t*)&dataset[hash_32[5316]]);
	hash_64[2661] = *((uint64_t*)&dataset[hash_32[5317]]);
	hash_64[2662] = *((uint64_t*)&dataset[hash_32[5318]]);
	hash_64[2663] = *((uint64_t*)&dataset[hash_32[5319]]);
	hash_64[2664] = *((uint64_t*)&dataset[hash_32[5320]]);
	hash_64[2665] = *((uint64_t*)&dataset[hash_32[5321]]);
	hash_64[2666] = *((uint64_t*)&dataset[hash_32[5322]]);
	hash_64[2667] = *((uint64_t*)&dataset[hash_32[5323]]);
	hash_64[2668] = *((uint64_t*)&dataset[hash_32[5324]]);
	hash_64[2669] = *((uint64_t*)&dataset[hash_32[5325]]);
	hash_64[2670] = *((uint64_t*)&dataset[hash_32[5326]]);
	hash_64[2671] = *((uint64_t*)&dataset[hash_32[5327]]);
#endif
#if MEMORY_THREADS > 167
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2672] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2673] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2674] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2675] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2676] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2677] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2678] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2679] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2672] = *((uint64_t*)&dataset[hash_32[5344]]);
	hash_64[2673] = *((uint64_t*)&dataset[hash_32[5345]]);
	hash_64[2674] = *((uint64_t*)&dataset[hash_32[5346]]);
	hash_64[2675] = *((uint64_t*)&dataset[hash_32[5347]]);
	hash_64[2676] = *((uint64_t*)&dataset[hash_32[5348]]);
	hash_64[2677] = *((uint64_t*)&dataset[hash_32[5349]]);
	hash_64[2678] = *((uint64_t*)&dataset[hash_32[5350]]);
	hash_64[2679] = *((uint64_t*)&dataset[hash_32[5351]]);
	hash_64[2680] = *((uint64_t*)&dataset[hash_32[5352]]);
	hash_64[2681] = *((uint64_t*)&dataset[hash_32[5353]]);
	hash_64[2682] = *((uint64_t*)&dataset[hash_32[5354]]);
	hash_64[2683] = *((uint64_t*)&dataset[hash_32[5355]]);
	hash_64[2684] = *((uint64_t*)&dataset[hash_32[5356]]);
	hash_64[2685] = *((uint64_t*)&dataset[hash_32[5357]]);
	hash_64[2686] = *((uint64_t*)&dataset[hash_32[5358]]);
	hash_64[2687] = *((uint64_t*)&dataset[hash_32[5359]]);
#endif
#if MEMORY_THREADS > 168
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2688] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2689] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2690] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2691] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2692] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2693] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2694] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2695] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2688] = *((uint64_t*)&dataset[hash_32[5376]]);
	hash_64[2689] = *((uint64_t*)&dataset[hash_32[5377]]);
	hash_64[2690] = *((uint64_t*)&dataset[hash_32[5378]]);
	hash_64[2691] = *((uint64_t*)&dataset[hash_32[5379]]);
	hash_64[2692] = *((uint64_t*)&dataset[hash_32[5380]]);
	hash_64[2693] = *((uint64_t*)&dataset[hash_32[5381]]);
	hash_64[2694] = *((uint64_t*)&dataset[hash_32[5382]]);
	hash_64[2695] = *((uint64_t*)&dataset[hash_32[5383]]);
	hash_64[2696] = *((uint64_t*)&dataset[hash_32[5384]]);
	hash_64[2697] = *((uint64_t*)&dataset[hash_32[5385]]);
	hash_64[2698] = *((uint64_t*)&dataset[hash_32[5386]]);
	hash_64[2699] = *((uint64_t*)&dataset[hash_32[5387]]);
	hash_64[2700] = *((uint64_t*)&dataset[hash_32[5388]]);
	hash_64[2701] = *((uint64_t*)&dataset[hash_32[5389]]);
	hash_64[2702] = *((uint64_t*)&dataset[hash_32[5390]]);
	hash_64[2703] = *((uint64_t*)&dataset[hash_32[5391]]);
#endif
#if MEMORY_THREADS > 169
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2704] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2705] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2706] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2707] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2708] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2709] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2710] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2711] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2704] = *((uint64_t*)&dataset[hash_32[5408]]);
	hash_64[2705] = *((uint64_t*)&dataset[hash_32[5409]]);
	hash_64[2706] = *((uint64_t*)&dataset[hash_32[5410]]);
	hash_64[2707] = *((uint64_t*)&dataset[hash_32[5411]]);
	hash_64[2708] = *((uint64_t*)&dataset[hash_32[5412]]);
	hash_64[2709] = *((uint64_t*)&dataset[hash_32[5413]]);
	hash_64[2710] = *((uint64_t*)&dataset[hash_32[5414]]);
	hash_64[2711] = *((uint64_t*)&dataset[hash_32[5415]]);
	hash_64[2712] = *((uint64_t*)&dataset[hash_32[5416]]);
	hash_64[2713] = *((uint64_t*)&dataset[hash_32[5417]]);
	hash_64[2714] = *((uint64_t*)&dataset[hash_32[5418]]);
	hash_64[2715] = *((uint64_t*)&dataset[hash_32[5419]]);
	hash_64[2716] = *((uint64_t*)&dataset[hash_32[5420]]);
	hash_64[2717] = *((uint64_t*)&dataset[hash_32[5421]]);
	hash_64[2718] = *((uint64_t*)&dataset[hash_32[5422]]);
	hash_64[2719] = *((uint64_t*)&dataset[hash_32[5423]]);
#endif
#if MEMORY_THREADS > 170
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2720] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2721] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2722] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2723] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2724] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2725] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2726] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2727] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2720] = *((uint64_t*)&dataset[hash_32[5440]]);
	hash_64[2721] = *((uint64_t*)&dataset[hash_32[5441]]);
	hash_64[2722] = *((uint64_t*)&dataset[hash_32[5442]]);
	hash_64[2723] = *((uint64_t*)&dataset[hash_32[5443]]);
	hash_64[2724] = *((uint64_t*)&dataset[hash_32[5444]]);
	hash_64[2725] = *((uint64_t*)&dataset[hash_32[5445]]);
	hash_64[2726] = *((uint64_t*)&dataset[hash_32[5446]]);
	hash_64[2727] = *((uint64_t*)&dataset[hash_32[5447]]);
	hash_64[2728] = *((uint64_t*)&dataset[hash_32[5448]]);
	hash_64[2729] = *((uint64_t*)&dataset[hash_32[5449]]);
	hash_64[2730] = *((uint64_t*)&dataset[hash_32[5450]]);
	hash_64[2731] = *((uint64_t*)&dataset[hash_32[5451]]);
	hash_64[2732] = *((uint64_t*)&dataset[hash_32[5452]]);
	hash_64[2733] = *((uint64_t*)&dataset[hash_32[5453]]);
	hash_64[2734] = *((uint64_t*)&dataset[hash_32[5454]]);
	hash_64[2735] = *((uint64_t*)&dataset[hash_32[5455]]);
#endif
#if MEMORY_THREADS > 171
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2736] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2737] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2738] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2739] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2740] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2741] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2742] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2743] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2736] = *((uint64_t*)&dataset[hash_32[5472]]);
	hash_64[2737] = *((uint64_t*)&dataset[hash_32[5473]]);
	hash_64[2738] = *((uint64_t*)&dataset[hash_32[5474]]);
	hash_64[2739] = *((uint64_t*)&dataset[hash_32[5475]]);
	hash_64[2740] = *((uint64_t*)&dataset[hash_32[5476]]);
	hash_64[2741] = *((uint64_t*)&dataset[hash_32[5477]]);
	hash_64[2742] = *((uint64_t*)&dataset[hash_32[5478]]);
	hash_64[2743] = *((uint64_t*)&dataset[hash_32[5479]]);
	hash_64[2744] = *((uint64_t*)&dataset[hash_32[5480]]);
	hash_64[2745] = *((uint64_t*)&dataset[hash_32[5481]]);
	hash_64[2746] = *((uint64_t*)&dataset[hash_32[5482]]);
	hash_64[2747] = *((uint64_t*)&dataset[hash_32[5483]]);
	hash_64[2748] = *((uint64_t*)&dataset[hash_32[5484]]);
	hash_64[2749] = *((uint64_t*)&dataset[hash_32[5485]]);
	hash_64[2750] = *((uint64_t*)&dataset[hash_32[5486]]);
	hash_64[2751] = *((uint64_t*)&dataset[hash_32[5487]]);
#endif
#if MEMORY_THREADS > 172
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2752] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2753] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2754] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2755] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2756] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2757] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2758] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2759] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2752] = *((uint64_t*)&dataset[hash_32[5504]]);
	hash_64[2753] = *((uint64_t*)&dataset[hash_32[5505]]);
	hash_64[2754] = *((uint64_t*)&dataset[hash_32[5506]]);
	hash_64[2755] = *((uint64_t*)&dataset[hash_32[5507]]);
	hash_64[2756] = *((uint64_t*)&dataset[hash_32[5508]]);
	hash_64[2757] = *((uint64_t*)&dataset[hash_32[5509]]);
	hash_64[2758] = *((uint64_t*)&dataset[hash_32[5510]]);
	hash_64[2759] = *((uint64_t*)&dataset[hash_32[5511]]);
	hash_64[2760] = *((uint64_t*)&dataset[hash_32[5512]]);
	hash_64[2761] = *((uint64_t*)&dataset[hash_32[5513]]);
	hash_64[2762] = *((uint64_t*)&dataset[hash_32[5514]]);
	hash_64[2763] = *((uint64_t*)&dataset[hash_32[5515]]);
	hash_64[2764] = *((uint64_t*)&dataset[hash_32[5516]]);
	hash_64[2765] = *((uint64_t*)&dataset[hash_32[5517]]);
	hash_64[2766] = *((uint64_t*)&dataset[hash_32[5518]]);
	hash_64[2767] = *((uint64_t*)&dataset[hash_32[5519]]);
#endif
#if MEMORY_THREADS > 173
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2768] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2769] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2770] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2771] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2772] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2773] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2774] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2775] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2768] = *((uint64_t*)&dataset[hash_32[5536]]);
	hash_64[2769] = *((uint64_t*)&dataset[hash_32[5537]]);
	hash_64[2770] = *((uint64_t*)&dataset[hash_32[5538]]);
	hash_64[2771] = *((uint64_t*)&dataset[hash_32[5539]]);
	hash_64[2772] = *((uint64_t*)&dataset[hash_32[5540]]);
	hash_64[2773] = *((uint64_t*)&dataset[hash_32[5541]]);
	hash_64[2774] = *((uint64_t*)&dataset[hash_32[5542]]);
	hash_64[2775] = *((uint64_t*)&dataset[hash_32[5543]]);
	hash_64[2776] = *((uint64_t*)&dataset[hash_32[5544]]);
	hash_64[2777] = *((uint64_t*)&dataset[hash_32[5545]]);
	hash_64[2778] = *((uint64_t*)&dataset[hash_32[5546]]);
	hash_64[2779] = *((uint64_t*)&dataset[hash_32[5547]]);
	hash_64[2780] = *((uint64_t*)&dataset[hash_32[5548]]);
	hash_64[2781] = *((uint64_t*)&dataset[hash_32[5549]]);
	hash_64[2782] = *((uint64_t*)&dataset[hash_32[5550]]);
	hash_64[2783] = *((uint64_t*)&dataset[hash_32[5551]]);
#endif
#if MEMORY_THREADS > 174
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2784] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2785] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2786] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2787] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2788] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2789] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2790] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2791] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2784] = *((uint64_t*)&dataset[hash_32[5568]]);
	hash_64[2785] = *((uint64_t*)&dataset[hash_32[5569]]);
	hash_64[2786] = *((uint64_t*)&dataset[hash_32[5570]]);
	hash_64[2787] = *((uint64_t*)&dataset[hash_32[5571]]);
	hash_64[2788] = *((uint64_t*)&dataset[hash_32[5572]]);
	hash_64[2789] = *((uint64_t*)&dataset[hash_32[5573]]);
	hash_64[2790] = *((uint64_t*)&dataset[hash_32[5574]]);
	hash_64[2791] = *((uint64_t*)&dataset[hash_32[5575]]);
	hash_64[2792] = *((uint64_t*)&dataset[hash_32[5576]]);
	hash_64[2793] = *((uint64_t*)&dataset[hash_32[5577]]);
	hash_64[2794] = *((uint64_t*)&dataset[hash_32[5578]]);
	hash_64[2795] = *((uint64_t*)&dataset[hash_32[5579]]);
	hash_64[2796] = *((uint64_t*)&dataset[hash_32[5580]]);
	hash_64[2797] = *((uint64_t*)&dataset[hash_32[5581]]);
	hash_64[2798] = *((uint64_t*)&dataset[hash_32[5582]]);
	hash_64[2799] = *((uint64_t*)&dataset[hash_32[5583]]);
#endif
#if MEMORY_THREADS > 175
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2800] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2801] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2802] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2803] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2804] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2805] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2806] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2807] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2800] = *((uint64_t*)&dataset[hash_32[5600]]);
	hash_64[2801] = *((uint64_t*)&dataset[hash_32[5601]]);
	hash_64[2802] = *((uint64_t*)&dataset[hash_32[5602]]);
	hash_64[2803] = *((uint64_t*)&dataset[hash_32[5603]]);
	hash_64[2804] = *((uint64_t*)&dataset[hash_32[5604]]);
	hash_64[2805] = *((uint64_t*)&dataset[hash_32[5605]]);
	hash_64[2806] = *((uint64_t*)&dataset[hash_32[5606]]);
	hash_64[2807] = *((uint64_t*)&dataset[hash_32[5607]]);
	hash_64[2808] = *((uint64_t*)&dataset[hash_32[5608]]);
	hash_64[2809] = *((uint64_t*)&dataset[hash_32[5609]]);
	hash_64[2810] = *((uint64_t*)&dataset[hash_32[5610]]);
	hash_64[2811] = *((uint64_t*)&dataset[hash_32[5611]]);
	hash_64[2812] = *((uint64_t*)&dataset[hash_32[5612]]);
	hash_64[2813] = *((uint64_t*)&dataset[hash_32[5613]]);
	hash_64[2814] = *((uint64_t*)&dataset[hash_32[5614]]);
	hash_64[2815] = *((uint64_t*)&dataset[hash_32[5615]]);
#endif
#if MEMORY_THREADS > 176
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2816] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2817] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2818] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2819] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2820] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2821] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2822] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2823] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2816] = *((uint64_t*)&dataset[hash_32[5632]]);
	hash_64[2817] = *((uint64_t*)&dataset[hash_32[5633]]);
	hash_64[2818] = *((uint64_t*)&dataset[hash_32[5634]]);
	hash_64[2819] = *((uint64_t*)&dataset[hash_32[5635]]);
	hash_64[2820] = *((uint64_t*)&dataset[hash_32[5636]]);
	hash_64[2821] = *((uint64_t*)&dataset[hash_32[5637]]);
	hash_64[2822] = *((uint64_t*)&dataset[hash_32[5638]]);
	hash_64[2823] = *((uint64_t*)&dataset[hash_32[5639]]);
	hash_64[2824] = *((uint64_t*)&dataset[hash_32[5640]]);
	hash_64[2825] = *((uint64_t*)&dataset[hash_32[5641]]);
	hash_64[2826] = *((uint64_t*)&dataset[hash_32[5642]]);
	hash_64[2827] = *((uint64_t*)&dataset[hash_32[5643]]);
	hash_64[2828] = *((uint64_t*)&dataset[hash_32[5644]]);
	hash_64[2829] = *((uint64_t*)&dataset[hash_32[5645]]);
	hash_64[2830] = *((uint64_t*)&dataset[hash_32[5646]]);
	hash_64[2831] = *((uint64_t*)&dataset[hash_32[5647]]);
#endif
#if MEMORY_THREADS > 177
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2832] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2833] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2834] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2835] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2836] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2837] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2838] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2839] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2832] = *((uint64_t*)&dataset[hash_32[5664]]);
	hash_64[2833] = *((uint64_t*)&dataset[hash_32[5665]]);
	hash_64[2834] = *((uint64_t*)&dataset[hash_32[5666]]);
	hash_64[2835] = *((uint64_t*)&dataset[hash_32[5667]]);
	hash_64[2836] = *((uint64_t*)&dataset[hash_32[5668]]);
	hash_64[2837] = *((uint64_t*)&dataset[hash_32[5669]]);
	hash_64[2838] = *((uint64_t*)&dataset[hash_32[5670]]);
	hash_64[2839] = *((uint64_t*)&dataset[hash_32[5671]]);
	hash_64[2840] = *((uint64_t*)&dataset[hash_32[5672]]);
	hash_64[2841] = *((uint64_t*)&dataset[hash_32[5673]]);
	hash_64[2842] = *((uint64_t*)&dataset[hash_32[5674]]);
	hash_64[2843] = *((uint64_t*)&dataset[hash_32[5675]]);
	hash_64[2844] = *((uint64_t*)&dataset[hash_32[5676]]);
	hash_64[2845] = *((uint64_t*)&dataset[hash_32[5677]]);
	hash_64[2846] = *((uint64_t*)&dataset[hash_32[5678]]);
	hash_64[2847] = *((uint64_t*)&dataset[hash_32[5679]]);
#endif
#if MEMORY_THREADS > 178
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2848] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2849] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2850] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2851] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2852] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2853] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2854] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2855] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2848] = *((uint64_t*)&dataset[hash_32[5696]]);
	hash_64[2849] = *((uint64_t*)&dataset[hash_32[5697]]);
	hash_64[2850] = *((uint64_t*)&dataset[hash_32[5698]]);
	hash_64[2851] = *((uint64_t*)&dataset[hash_32[5699]]);
	hash_64[2852] = *((uint64_t*)&dataset[hash_32[5700]]);
	hash_64[2853] = *((uint64_t*)&dataset[hash_32[5701]]);
	hash_64[2854] = *((uint64_t*)&dataset[hash_32[5702]]);
	hash_64[2855] = *((uint64_t*)&dataset[hash_32[5703]]);
	hash_64[2856] = *((uint64_t*)&dataset[hash_32[5704]]);
	hash_64[2857] = *((uint64_t*)&dataset[hash_32[5705]]);
	hash_64[2858] = *((uint64_t*)&dataset[hash_32[5706]]);
	hash_64[2859] = *((uint64_t*)&dataset[hash_32[5707]]);
	hash_64[2860] = *((uint64_t*)&dataset[hash_32[5708]]);
	hash_64[2861] = *((uint64_t*)&dataset[hash_32[5709]]);
	hash_64[2862] = *((uint64_t*)&dataset[hash_32[5710]]);
	hash_64[2863] = *((uint64_t*)&dataset[hash_32[5711]]);
#endif
#if MEMORY_THREADS > 179
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2864] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2865] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2866] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2867] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2868] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2869] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2870] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2871] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2864] = *((uint64_t*)&dataset[hash_32[5728]]);
	hash_64[2865] = *((uint64_t*)&dataset[hash_32[5729]]);
	hash_64[2866] = *((uint64_t*)&dataset[hash_32[5730]]);
	hash_64[2867] = *((uint64_t*)&dataset[hash_32[5731]]);
	hash_64[2868] = *((uint64_t*)&dataset[hash_32[5732]]);
	hash_64[2869] = *((uint64_t*)&dataset[hash_32[5733]]);
	hash_64[2870] = *((uint64_t*)&dataset[hash_32[5734]]);
	hash_64[2871] = *((uint64_t*)&dataset[hash_32[5735]]);
	hash_64[2872] = *((uint64_t*)&dataset[hash_32[5736]]);
	hash_64[2873] = *((uint64_t*)&dataset[hash_32[5737]]);
	hash_64[2874] = *((uint64_t*)&dataset[hash_32[5738]]);
	hash_64[2875] = *((uint64_t*)&dataset[hash_32[5739]]);
	hash_64[2876] = *((uint64_t*)&dataset[hash_32[5740]]);
	hash_64[2877] = *((uint64_t*)&dataset[hash_32[5741]]);
	hash_64[2878] = *((uint64_t*)&dataset[hash_32[5742]]);
	hash_64[2879] = *((uint64_t*)&dataset[hash_32[5743]]);
#endif
#if MEMORY_THREADS > 180
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2880] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2881] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2882] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2883] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2884] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2885] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2886] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2887] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2880] = *((uint64_t*)&dataset[hash_32[5760]]);
	hash_64[2881] = *((uint64_t*)&dataset[hash_32[5761]]);
	hash_64[2882] = *((uint64_t*)&dataset[hash_32[5762]]);
	hash_64[2883] = *((uint64_t*)&dataset[hash_32[5763]]);
	hash_64[2884] = *((uint64_t*)&dataset[hash_32[5764]]);
	hash_64[2885] = *((uint64_t*)&dataset[hash_32[5765]]);
	hash_64[2886] = *((uint64_t*)&dataset[hash_32[5766]]);
	hash_64[2887] = *((uint64_t*)&dataset[hash_32[5767]]);
	hash_64[2888] = *((uint64_t*)&dataset[hash_32[5768]]);
	hash_64[2889] = *((uint64_t*)&dataset[hash_32[5769]]);
	hash_64[2890] = *((uint64_t*)&dataset[hash_32[5770]]);
	hash_64[2891] = *((uint64_t*)&dataset[hash_32[5771]]);
	hash_64[2892] = *((uint64_t*)&dataset[hash_32[5772]]);
	hash_64[2893] = *((uint64_t*)&dataset[hash_32[5773]]);
	hash_64[2894] = *((uint64_t*)&dataset[hash_32[5774]]);
	hash_64[2895] = *((uint64_t*)&dataset[hash_32[5775]]);
#endif
#if MEMORY_THREADS > 181
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2896] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2897] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2898] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2899] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2900] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2901] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2902] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2903] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2896] = *((uint64_t*)&dataset[hash_32[5792]]);
	hash_64[2897] = *((uint64_t*)&dataset[hash_32[5793]]);
	hash_64[2898] = *((uint64_t*)&dataset[hash_32[5794]]);
	hash_64[2899] = *((uint64_t*)&dataset[hash_32[5795]]);
	hash_64[2900] = *((uint64_t*)&dataset[hash_32[5796]]);
	hash_64[2901] = *((uint64_t*)&dataset[hash_32[5797]]);
	hash_64[2902] = *((uint64_t*)&dataset[hash_32[5798]]);
	hash_64[2903] = *((uint64_t*)&dataset[hash_32[5799]]);
	hash_64[2904] = *((uint64_t*)&dataset[hash_32[5800]]);
	hash_64[2905] = *((uint64_t*)&dataset[hash_32[5801]]);
	hash_64[2906] = *((uint64_t*)&dataset[hash_32[5802]]);
	hash_64[2907] = *((uint64_t*)&dataset[hash_32[5803]]);
	hash_64[2908] = *((uint64_t*)&dataset[hash_32[5804]]);
	hash_64[2909] = *((uint64_t*)&dataset[hash_32[5805]]);
	hash_64[2910] = *((uint64_t*)&dataset[hash_32[5806]]);
	hash_64[2911] = *((uint64_t*)&dataset[hash_32[5807]]);
#endif
#if MEMORY_THREADS > 182
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2912] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2913] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2914] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2915] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2916] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2917] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2918] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2919] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2912] = *((uint64_t*)&dataset[hash_32[5824]]);
	hash_64[2913] = *((uint64_t*)&dataset[hash_32[5825]]);
	hash_64[2914] = *((uint64_t*)&dataset[hash_32[5826]]);
	hash_64[2915] = *((uint64_t*)&dataset[hash_32[5827]]);
	hash_64[2916] = *((uint64_t*)&dataset[hash_32[5828]]);
	hash_64[2917] = *((uint64_t*)&dataset[hash_32[5829]]);
	hash_64[2918] = *((uint64_t*)&dataset[hash_32[5830]]);
	hash_64[2919] = *((uint64_t*)&dataset[hash_32[5831]]);
	hash_64[2920] = *((uint64_t*)&dataset[hash_32[5832]]);
	hash_64[2921] = *((uint64_t*)&dataset[hash_32[5833]]);
	hash_64[2922] = *((uint64_t*)&dataset[hash_32[5834]]);
	hash_64[2923] = *((uint64_t*)&dataset[hash_32[5835]]);
	hash_64[2924] = *((uint64_t*)&dataset[hash_32[5836]]);
	hash_64[2925] = *((uint64_t*)&dataset[hash_32[5837]]);
	hash_64[2926] = *((uint64_t*)&dataset[hash_32[5838]]);
	hash_64[2927] = *((uint64_t*)&dataset[hash_32[5839]]);
#endif
#if MEMORY_THREADS > 183
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2928] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2929] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2930] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2931] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2932] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2933] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2934] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2935] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2928] = *((uint64_t*)&dataset[hash_32[5856]]);
	hash_64[2929] = *((uint64_t*)&dataset[hash_32[5857]]);
	hash_64[2930] = *((uint64_t*)&dataset[hash_32[5858]]);
	hash_64[2931] = *((uint64_t*)&dataset[hash_32[5859]]);
	hash_64[2932] = *((uint64_t*)&dataset[hash_32[5860]]);
	hash_64[2933] = *((uint64_t*)&dataset[hash_32[5861]]);
	hash_64[2934] = *((uint64_t*)&dataset[hash_32[5862]]);
	hash_64[2935] = *((uint64_t*)&dataset[hash_32[5863]]);
	hash_64[2936] = *((uint64_t*)&dataset[hash_32[5864]]);
	hash_64[2937] = *((uint64_t*)&dataset[hash_32[5865]]);
	hash_64[2938] = *((uint64_t*)&dataset[hash_32[5866]]);
	hash_64[2939] = *((uint64_t*)&dataset[hash_32[5867]]);
	hash_64[2940] = *((uint64_t*)&dataset[hash_32[5868]]);
	hash_64[2941] = *((uint64_t*)&dataset[hash_32[5869]]);
	hash_64[2942] = *((uint64_t*)&dataset[hash_32[5870]]);
	hash_64[2943] = *((uint64_t*)&dataset[hash_32[5871]]);
#endif
#if MEMORY_THREADS > 184
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2944] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2945] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2946] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2947] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2948] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2949] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2950] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2951] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2944] = *((uint64_t*)&dataset[hash_32[5888]]);
	hash_64[2945] = *((uint64_t*)&dataset[hash_32[5889]]);
	hash_64[2946] = *((uint64_t*)&dataset[hash_32[5890]]);
	hash_64[2947] = *((uint64_t*)&dataset[hash_32[5891]]);
	hash_64[2948] = *((uint64_t*)&dataset[hash_32[5892]]);
	hash_64[2949] = *((uint64_t*)&dataset[hash_32[5893]]);
	hash_64[2950] = *((uint64_t*)&dataset[hash_32[5894]]);
	hash_64[2951] = *((uint64_t*)&dataset[hash_32[5895]]);
	hash_64[2952] = *((uint64_t*)&dataset[hash_32[5896]]);
	hash_64[2953] = *((uint64_t*)&dataset[hash_32[5897]]);
	hash_64[2954] = *((uint64_t*)&dataset[hash_32[5898]]);
	hash_64[2955] = *((uint64_t*)&dataset[hash_32[5899]]);
	hash_64[2956] = *((uint64_t*)&dataset[hash_32[5900]]);
	hash_64[2957] = *((uint64_t*)&dataset[hash_32[5901]]);
	hash_64[2958] = *((uint64_t*)&dataset[hash_32[5902]]);
	hash_64[2959] = *((uint64_t*)&dataset[hash_32[5903]]);
#endif
#if MEMORY_THREADS > 185
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2960] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2961] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2962] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2963] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2964] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2965] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2966] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2967] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2960] = *((uint64_t*)&dataset[hash_32[5920]]);
	hash_64[2961] = *((uint64_t*)&dataset[hash_32[5921]]);
	hash_64[2962] = *((uint64_t*)&dataset[hash_32[5922]]);
	hash_64[2963] = *((uint64_t*)&dataset[hash_32[5923]]);
	hash_64[2964] = *((uint64_t*)&dataset[hash_32[5924]]);
	hash_64[2965] = *((uint64_t*)&dataset[hash_32[5925]]);
	hash_64[2966] = *((uint64_t*)&dataset[hash_32[5926]]);
	hash_64[2967] = *((uint64_t*)&dataset[hash_32[5927]]);
	hash_64[2968] = *((uint64_t*)&dataset[hash_32[5928]]);
	hash_64[2969] = *((uint64_t*)&dataset[hash_32[5929]]);
	hash_64[2970] = *((uint64_t*)&dataset[hash_32[5930]]);
	hash_64[2971] = *((uint64_t*)&dataset[hash_32[5931]]);
	hash_64[2972] = *((uint64_t*)&dataset[hash_32[5932]]);
	hash_64[2973] = *((uint64_t*)&dataset[hash_32[5933]]);
	hash_64[2974] = *((uint64_t*)&dataset[hash_32[5934]]);
	hash_64[2975] = *((uint64_t*)&dataset[hash_32[5935]]);
#endif
#if MEMORY_THREADS > 186
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2976] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2977] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2978] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2979] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2980] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2981] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2982] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2983] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2976] = *((uint64_t*)&dataset[hash_32[5952]]);
	hash_64[2977] = *((uint64_t*)&dataset[hash_32[5953]]);
	hash_64[2978] = *((uint64_t*)&dataset[hash_32[5954]]);
	hash_64[2979] = *((uint64_t*)&dataset[hash_32[5955]]);
	hash_64[2980] = *((uint64_t*)&dataset[hash_32[5956]]);
	hash_64[2981] = *((uint64_t*)&dataset[hash_32[5957]]);
	hash_64[2982] = *((uint64_t*)&dataset[hash_32[5958]]);
	hash_64[2983] = *((uint64_t*)&dataset[hash_32[5959]]);
	hash_64[2984] = *((uint64_t*)&dataset[hash_32[5960]]);
	hash_64[2985] = *((uint64_t*)&dataset[hash_32[5961]]);
	hash_64[2986] = *((uint64_t*)&dataset[hash_32[5962]]);
	hash_64[2987] = *((uint64_t*)&dataset[hash_32[5963]]);
	hash_64[2988] = *((uint64_t*)&dataset[hash_32[5964]]);
	hash_64[2989] = *((uint64_t*)&dataset[hash_32[5965]]);
	hash_64[2990] = *((uint64_t*)&dataset[hash_32[5966]]);
	hash_64[2991] = *((uint64_t*)&dataset[hash_32[5967]]);
#endif
#if MEMORY_THREADS > 187
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[2992] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[2993] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[2994] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[2995] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[2996] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[2997] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[2998] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[2999] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[2992] = *((uint64_t*)&dataset[hash_32[5984]]);
	hash_64[2993] = *((uint64_t*)&dataset[hash_32[5985]]);
	hash_64[2994] = *((uint64_t*)&dataset[hash_32[5986]]);
	hash_64[2995] = *((uint64_t*)&dataset[hash_32[5987]]);
	hash_64[2996] = *((uint64_t*)&dataset[hash_32[5988]]);
	hash_64[2997] = *((uint64_t*)&dataset[hash_32[5989]]);
	hash_64[2998] = *((uint64_t*)&dataset[hash_32[5990]]);
	hash_64[2999] = *((uint64_t*)&dataset[hash_32[5991]]);
	hash_64[3000] = *((uint64_t*)&dataset[hash_32[5992]]);
	hash_64[3001] = *((uint64_t*)&dataset[hash_32[5993]]);
	hash_64[3002] = *((uint64_t*)&dataset[hash_32[5994]]);
	hash_64[3003] = *((uint64_t*)&dataset[hash_32[5995]]);
	hash_64[3004] = *((uint64_t*)&dataset[hash_32[5996]]);
	hash_64[3005] = *((uint64_t*)&dataset[hash_32[5997]]);
	hash_64[3006] = *((uint64_t*)&dataset[hash_32[5998]]);
	hash_64[3007] = *((uint64_t*)&dataset[hash_32[5999]]);
#endif
#if MEMORY_THREADS > 188
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3008] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3009] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3010] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3011] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3012] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3013] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3014] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3015] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3008] = *((uint64_t*)&dataset[hash_32[6016]]);
	hash_64[3009] = *((uint64_t*)&dataset[hash_32[6017]]);
	hash_64[3010] = *((uint64_t*)&dataset[hash_32[6018]]);
	hash_64[3011] = *((uint64_t*)&dataset[hash_32[6019]]);
	hash_64[3012] = *((uint64_t*)&dataset[hash_32[6020]]);
	hash_64[3013] = *((uint64_t*)&dataset[hash_32[6021]]);
	hash_64[3014] = *((uint64_t*)&dataset[hash_32[6022]]);
	hash_64[3015] = *((uint64_t*)&dataset[hash_32[6023]]);
	hash_64[3016] = *((uint64_t*)&dataset[hash_32[6024]]);
	hash_64[3017] = *((uint64_t*)&dataset[hash_32[6025]]);
	hash_64[3018] = *((uint64_t*)&dataset[hash_32[6026]]);
	hash_64[3019] = *((uint64_t*)&dataset[hash_32[6027]]);
	hash_64[3020] = *((uint64_t*)&dataset[hash_32[6028]]);
	hash_64[3021] = *((uint64_t*)&dataset[hash_32[6029]]);
	hash_64[3022] = *((uint64_t*)&dataset[hash_32[6030]]);
	hash_64[3023] = *((uint64_t*)&dataset[hash_32[6031]]);
#endif
#if MEMORY_THREADS > 189
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3024] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3025] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3026] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3027] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3028] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3029] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3030] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3031] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3024] = *((uint64_t*)&dataset[hash_32[6048]]);
	hash_64[3025] = *((uint64_t*)&dataset[hash_32[6049]]);
	hash_64[3026] = *((uint64_t*)&dataset[hash_32[6050]]);
	hash_64[3027] = *((uint64_t*)&dataset[hash_32[6051]]);
	hash_64[3028] = *((uint64_t*)&dataset[hash_32[6052]]);
	hash_64[3029] = *((uint64_t*)&dataset[hash_32[6053]]);
	hash_64[3030] = *((uint64_t*)&dataset[hash_32[6054]]);
	hash_64[3031] = *((uint64_t*)&dataset[hash_32[6055]]);
	hash_64[3032] = *((uint64_t*)&dataset[hash_32[6056]]);
	hash_64[3033] = *((uint64_t*)&dataset[hash_32[6057]]);
	hash_64[3034] = *((uint64_t*)&dataset[hash_32[6058]]);
	hash_64[3035] = *((uint64_t*)&dataset[hash_32[6059]]);
	hash_64[3036] = *((uint64_t*)&dataset[hash_32[6060]]);
	hash_64[3037] = *((uint64_t*)&dataset[hash_32[6061]]);
	hash_64[3038] = *((uint64_t*)&dataset[hash_32[6062]]);
	hash_64[3039] = *((uint64_t*)&dataset[hash_32[6063]]);
#endif
#if MEMORY_THREADS > 190
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3040] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3041] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3042] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3043] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3044] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3045] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3046] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3047] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3040] = *((uint64_t*)&dataset[hash_32[6080]]);
	hash_64[3041] = *((uint64_t*)&dataset[hash_32[6081]]);
	hash_64[3042] = *((uint64_t*)&dataset[hash_32[6082]]);
	hash_64[3043] = *((uint64_t*)&dataset[hash_32[6083]]);
	hash_64[3044] = *((uint64_t*)&dataset[hash_32[6084]]);
	hash_64[3045] = *((uint64_t*)&dataset[hash_32[6085]]);
	hash_64[3046] = *((uint64_t*)&dataset[hash_32[6086]]);
	hash_64[3047] = *((uint64_t*)&dataset[hash_32[6087]]);
	hash_64[3048] = *((uint64_t*)&dataset[hash_32[6088]]);
	hash_64[3049] = *((uint64_t*)&dataset[hash_32[6089]]);
	hash_64[3050] = *((uint64_t*)&dataset[hash_32[6090]]);
	hash_64[3051] = *((uint64_t*)&dataset[hash_32[6091]]);
	hash_64[3052] = *((uint64_t*)&dataset[hash_32[6092]]);
	hash_64[3053] = *((uint64_t*)&dataset[hash_32[6093]]);
	hash_64[3054] = *((uint64_t*)&dataset[hash_32[6094]]);
	hash_64[3055] = *((uint64_t*)&dataset[hash_32[6095]]);
#endif
#if MEMORY_THREADS > 191
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3056] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3057] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3058] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3059] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3060] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3061] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3062] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3063] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3056] = *((uint64_t*)&dataset[hash_32[6112]]);
	hash_64[3057] = *((uint64_t*)&dataset[hash_32[6113]]);
	hash_64[3058] = *((uint64_t*)&dataset[hash_32[6114]]);
	hash_64[3059] = *((uint64_t*)&dataset[hash_32[6115]]);
	hash_64[3060] = *((uint64_t*)&dataset[hash_32[6116]]);
	hash_64[3061] = *((uint64_t*)&dataset[hash_32[6117]]);
	hash_64[3062] = *((uint64_t*)&dataset[hash_32[6118]]);
	hash_64[3063] = *((uint64_t*)&dataset[hash_32[6119]]);
	hash_64[3064] = *((uint64_t*)&dataset[hash_32[6120]]);
	hash_64[3065] = *((uint64_t*)&dataset[hash_32[6121]]);
	hash_64[3066] = *((uint64_t*)&dataset[hash_32[6122]]);
	hash_64[3067] = *((uint64_t*)&dataset[hash_32[6123]]);
	hash_64[3068] = *((uint64_t*)&dataset[hash_32[6124]]);
	hash_64[3069] = *((uint64_t*)&dataset[hash_32[6125]]);
	hash_64[3070] = *((uint64_t*)&dataset[hash_32[6126]]);
	hash_64[3071] = *((uint64_t*)&dataset[hash_32[6127]]);
#endif
#if MEMORY_THREADS > 192
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3072] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3073] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3074] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3075] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3076] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3077] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3078] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3079] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3072] = *((uint64_t*)&dataset[hash_32[6144]]);
	hash_64[3073] = *((uint64_t*)&dataset[hash_32[6145]]);
	hash_64[3074] = *((uint64_t*)&dataset[hash_32[6146]]);
	hash_64[3075] = *((uint64_t*)&dataset[hash_32[6147]]);
	hash_64[3076] = *((uint64_t*)&dataset[hash_32[6148]]);
	hash_64[3077] = *((uint64_t*)&dataset[hash_32[6149]]);
	hash_64[3078] = *((uint64_t*)&dataset[hash_32[6150]]);
	hash_64[3079] = *((uint64_t*)&dataset[hash_32[6151]]);
	hash_64[3080] = *((uint64_t*)&dataset[hash_32[6152]]);
	hash_64[3081] = *((uint64_t*)&dataset[hash_32[6153]]);
	hash_64[3082] = *((uint64_t*)&dataset[hash_32[6154]]);
	hash_64[3083] = *((uint64_t*)&dataset[hash_32[6155]]);
	hash_64[3084] = *((uint64_t*)&dataset[hash_32[6156]]);
	hash_64[3085] = *((uint64_t*)&dataset[hash_32[6157]]);
	hash_64[3086] = *((uint64_t*)&dataset[hash_32[6158]]);
	hash_64[3087] = *((uint64_t*)&dataset[hash_32[6159]]);
#endif
#if MEMORY_THREADS > 193
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3088] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3089] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3090] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3091] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3092] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3093] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3094] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3095] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3088] = *((uint64_t*)&dataset[hash_32[6176]]);
	hash_64[3089] = *((uint64_t*)&dataset[hash_32[6177]]);
	hash_64[3090] = *((uint64_t*)&dataset[hash_32[6178]]);
	hash_64[3091] = *((uint64_t*)&dataset[hash_32[6179]]);
	hash_64[3092] = *((uint64_t*)&dataset[hash_32[6180]]);
	hash_64[3093] = *((uint64_t*)&dataset[hash_32[6181]]);
	hash_64[3094] = *((uint64_t*)&dataset[hash_32[6182]]);
	hash_64[3095] = *((uint64_t*)&dataset[hash_32[6183]]);
	hash_64[3096] = *((uint64_t*)&dataset[hash_32[6184]]);
	hash_64[3097] = *((uint64_t*)&dataset[hash_32[6185]]);
	hash_64[3098] = *((uint64_t*)&dataset[hash_32[6186]]);
	hash_64[3099] = *((uint64_t*)&dataset[hash_32[6187]]);
	hash_64[3100] = *((uint64_t*)&dataset[hash_32[6188]]);
	hash_64[3101] = *((uint64_t*)&dataset[hash_32[6189]]);
	hash_64[3102] = *((uint64_t*)&dataset[hash_32[6190]]);
	hash_64[3103] = *((uint64_t*)&dataset[hash_32[6191]]);
#endif
#if MEMORY_THREADS > 194
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3104] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3105] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3106] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3107] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3108] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3109] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3110] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3111] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3104] = *((uint64_t*)&dataset[hash_32[6208]]);
	hash_64[3105] = *((uint64_t*)&dataset[hash_32[6209]]);
	hash_64[3106] = *((uint64_t*)&dataset[hash_32[6210]]);
	hash_64[3107] = *((uint64_t*)&dataset[hash_32[6211]]);
	hash_64[3108] = *((uint64_t*)&dataset[hash_32[6212]]);
	hash_64[3109] = *((uint64_t*)&dataset[hash_32[6213]]);
	hash_64[3110] = *((uint64_t*)&dataset[hash_32[6214]]);
	hash_64[3111] = *((uint64_t*)&dataset[hash_32[6215]]);
	hash_64[3112] = *((uint64_t*)&dataset[hash_32[6216]]);
	hash_64[3113] = *((uint64_t*)&dataset[hash_32[6217]]);
	hash_64[3114] = *((uint64_t*)&dataset[hash_32[6218]]);
	hash_64[3115] = *((uint64_t*)&dataset[hash_32[6219]]);
	hash_64[3116] = *((uint64_t*)&dataset[hash_32[6220]]);
	hash_64[3117] = *((uint64_t*)&dataset[hash_32[6221]]);
	hash_64[3118] = *((uint64_t*)&dataset[hash_32[6222]]);
	hash_64[3119] = *((uint64_t*)&dataset[hash_32[6223]]);
#endif
#if MEMORY_THREADS > 195
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3120] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3121] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3122] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3123] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3124] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3125] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3126] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3127] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3120] = *((uint64_t*)&dataset[hash_32[6240]]);
	hash_64[3121] = *((uint64_t*)&dataset[hash_32[6241]]);
	hash_64[3122] = *((uint64_t*)&dataset[hash_32[6242]]);
	hash_64[3123] = *((uint64_t*)&dataset[hash_32[6243]]);
	hash_64[3124] = *((uint64_t*)&dataset[hash_32[6244]]);
	hash_64[3125] = *((uint64_t*)&dataset[hash_32[6245]]);
	hash_64[3126] = *((uint64_t*)&dataset[hash_32[6246]]);
	hash_64[3127] = *((uint64_t*)&dataset[hash_32[6247]]);
	hash_64[3128] = *((uint64_t*)&dataset[hash_32[6248]]);
	hash_64[3129] = *((uint64_t*)&dataset[hash_32[6249]]);
	hash_64[3130] = *((uint64_t*)&dataset[hash_32[6250]]);
	hash_64[3131] = *((uint64_t*)&dataset[hash_32[6251]]);
	hash_64[3132] = *((uint64_t*)&dataset[hash_32[6252]]);
	hash_64[3133] = *((uint64_t*)&dataset[hash_32[6253]]);
	hash_64[3134] = *((uint64_t*)&dataset[hash_32[6254]]);
	hash_64[3135] = *((uint64_t*)&dataset[hash_32[6255]]);
#endif
#if MEMORY_THREADS > 196
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3136] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3137] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3138] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3139] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3140] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3141] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3142] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3143] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3136] = *((uint64_t*)&dataset[hash_32[6272]]);
	hash_64[3137] = *((uint64_t*)&dataset[hash_32[6273]]);
	hash_64[3138] = *((uint64_t*)&dataset[hash_32[6274]]);
	hash_64[3139] = *((uint64_t*)&dataset[hash_32[6275]]);
	hash_64[3140] = *((uint64_t*)&dataset[hash_32[6276]]);
	hash_64[3141] = *((uint64_t*)&dataset[hash_32[6277]]);
	hash_64[3142] = *((uint64_t*)&dataset[hash_32[6278]]);
	hash_64[3143] = *((uint64_t*)&dataset[hash_32[6279]]);
	hash_64[3144] = *((uint64_t*)&dataset[hash_32[6280]]);
	hash_64[3145] = *((uint64_t*)&dataset[hash_32[6281]]);
	hash_64[3146] = *((uint64_t*)&dataset[hash_32[6282]]);
	hash_64[3147] = *((uint64_t*)&dataset[hash_32[6283]]);
	hash_64[3148] = *((uint64_t*)&dataset[hash_32[6284]]);
	hash_64[3149] = *((uint64_t*)&dataset[hash_32[6285]]);
	hash_64[3150] = *((uint64_t*)&dataset[hash_32[6286]]);
	hash_64[3151] = *((uint64_t*)&dataset[hash_32[6287]]);
#endif
#if MEMORY_THREADS > 197
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3152] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3153] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3154] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3155] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3156] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3157] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3158] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3159] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3152] = *((uint64_t*)&dataset[hash_32[6304]]);
	hash_64[3153] = *((uint64_t*)&dataset[hash_32[6305]]);
	hash_64[3154] = *((uint64_t*)&dataset[hash_32[6306]]);
	hash_64[3155] = *((uint64_t*)&dataset[hash_32[6307]]);
	hash_64[3156] = *((uint64_t*)&dataset[hash_32[6308]]);
	hash_64[3157] = *((uint64_t*)&dataset[hash_32[6309]]);
	hash_64[3158] = *((uint64_t*)&dataset[hash_32[6310]]);
	hash_64[3159] = *((uint64_t*)&dataset[hash_32[6311]]);
	hash_64[3160] = *((uint64_t*)&dataset[hash_32[6312]]);
	hash_64[3161] = *((uint64_t*)&dataset[hash_32[6313]]);
	hash_64[3162] = *((uint64_t*)&dataset[hash_32[6314]]);
	hash_64[3163] = *((uint64_t*)&dataset[hash_32[6315]]);
	hash_64[3164] = *((uint64_t*)&dataset[hash_32[6316]]);
	hash_64[3165] = *((uint64_t*)&dataset[hash_32[6317]]);
	hash_64[3166] = *((uint64_t*)&dataset[hash_32[6318]]);
	hash_64[3167] = *((uint64_t*)&dataset[hash_32[6319]]);
#endif
#if MEMORY_THREADS > 198
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3168] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3169] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3170] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3171] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3172] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3173] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3174] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3175] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3168] = *((uint64_t*)&dataset[hash_32[6336]]);
	hash_64[3169] = *((uint64_t*)&dataset[hash_32[6337]]);
	hash_64[3170] = *((uint64_t*)&dataset[hash_32[6338]]);
	hash_64[3171] = *((uint64_t*)&dataset[hash_32[6339]]);
	hash_64[3172] = *((uint64_t*)&dataset[hash_32[6340]]);
	hash_64[3173] = *((uint64_t*)&dataset[hash_32[6341]]);
	hash_64[3174] = *((uint64_t*)&dataset[hash_32[6342]]);
	hash_64[3175] = *((uint64_t*)&dataset[hash_32[6343]]);
	hash_64[3176] = *((uint64_t*)&dataset[hash_32[6344]]);
	hash_64[3177] = *((uint64_t*)&dataset[hash_32[6345]]);
	hash_64[3178] = *((uint64_t*)&dataset[hash_32[6346]]);
	hash_64[3179] = *((uint64_t*)&dataset[hash_32[6347]]);
	hash_64[3180] = *((uint64_t*)&dataset[hash_32[6348]]);
	hash_64[3181] = *((uint64_t*)&dataset[hash_32[6349]]);
	hash_64[3182] = *((uint64_t*)&dataset[hash_32[6350]]);
	hash_64[3183] = *((uint64_t*)&dataset[hash_32[6351]]);
#endif
#if MEMORY_THREADS > 199
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3184] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3185] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3186] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3187] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3188] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3189] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3190] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3191] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3184] = *((uint64_t*)&dataset[hash_32[6368]]);
	hash_64[3185] = *((uint64_t*)&dataset[hash_32[6369]]);
	hash_64[3186] = *((uint64_t*)&dataset[hash_32[6370]]);
	hash_64[3187] = *((uint64_t*)&dataset[hash_32[6371]]);
	hash_64[3188] = *((uint64_t*)&dataset[hash_32[6372]]);
	hash_64[3189] = *((uint64_t*)&dataset[hash_32[6373]]);
	hash_64[3190] = *((uint64_t*)&dataset[hash_32[6374]]);
	hash_64[3191] = *((uint64_t*)&dataset[hash_32[6375]]);
	hash_64[3192] = *((uint64_t*)&dataset[hash_32[6376]]);
	hash_64[3193] = *((uint64_t*)&dataset[hash_32[6377]]);
	hash_64[3194] = *((uint64_t*)&dataset[hash_32[6378]]);
	hash_64[3195] = *((uint64_t*)&dataset[hash_32[6379]]);
	hash_64[3196] = *((uint64_t*)&dataset[hash_32[6380]]);
	hash_64[3197] = *((uint64_t*)&dataset[hash_32[6381]]);
	hash_64[3198] = *((uint64_t*)&dataset[hash_32[6382]]);
	hash_64[3199] = *((uint64_t*)&dataset[hash_32[6383]]);
#endif
#if MEMORY_THREADS > 200
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3200] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3201] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3202] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3203] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3204] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3205] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3206] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3207] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3200] = *((uint64_t*)&dataset[hash_32[6400]]);
	hash_64[3201] = *((uint64_t*)&dataset[hash_32[6401]]);
	hash_64[3202] = *((uint64_t*)&dataset[hash_32[6402]]);
	hash_64[3203] = *((uint64_t*)&dataset[hash_32[6403]]);
	hash_64[3204] = *((uint64_t*)&dataset[hash_32[6404]]);
	hash_64[3205] = *((uint64_t*)&dataset[hash_32[6405]]);
	hash_64[3206] = *((uint64_t*)&dataset[hash_32[6406]]);
	hash_64[3207] = *((uint64_t*)&dataset[hash_32[6407]]);
	hash_64[3208] = *((uint64_t*)&dataset[hash_32[6408]]);
	hash_64[3209] = *((uint64_t*)&dataset[hash_32[6409]]);
	hash_64[3210] = *((uint64_t*)&dataset[hash_32[6410]]);
	hash_64[3211] = *((uint64_t*)&dataset[hash_32[6411]]);
	hash_64[3212] = *((uint64_t*)&dataset[hash_32[6412]]);
	hash_64[3213] = *((uint64_t*)&dataset[hash_32[6413]]);
	hash_64[3214] = *((uint64_t*)&dataset[hash_32[6414]]);
	hash_64[3215] = *((uint64_t*)&dataset[hash_32[6415]]);
#endif
#if MEMORY_THREADS > 201
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3216] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3217] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3218] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3219] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3220] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3221] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3222] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3223] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3216] = *((uint64_t*)&dataset[hash_32[6432]]);
	hash_64[3217] = *((uint64_t*)&dataset[hash_32[6433]]);
	hash_64[3218] = *((uint64_t*)&dataset[hash_32[6434]]);
	hash_64[3219] = *((uint64_t*)&dataset[hash_32[6435]]);
	hash_64[3220] = *((uint64_t*)&dataset[hash_32[6436]]);
	hash_64[3221] = *((uint64_t*)&dataset[hash_32[6437]]);
	hash_64[3222] = *((uint64_t*)&dataset[hash_32[6438]]);
	hash_64[3223] = *((uint64_t*)&dataset[hash_32[6439]]);
	hash_64[3224] = *((uint64_t*)&dataset[hash_32[6440]]);
	hash_64[3225] = *((uint64_t*)&dataset[hash_32[6441]]);
	hash_64[3226] = *((uint64_t*)&dataset[hash_32[6442]]);
	hash_64[3227] = *((uint64_t*)&dataset[hash_32[6443]]);
	hash_64[3228] = *((uint64_t*)&dataset[hash_32[6444]]);
	hash_64[3229] = *((uint64_t*)&dataset[hash_32[6445]]);
	hash_64[3230] = *((uint64_t*)&dataset[hash_32[6446]]);
	hash_64[3231] = *((uint64_t*)&dataset[hash_32[6447]]);
#endif
#if MEMORY_THREADS > 202
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3232] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3233] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3234] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3235] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3236] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3237] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3238] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3239] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3232] = *((uint64_t*)&dataset[hash_32[6464]]);
	hash_64[3233] = *((uint64_t*)&dataset[hash_32[6465]]);
	hash_64[3234] = *((uint64_t*)&dataset[hash_32[6466]]);
	hash_64[3235] = *((uint64_t*)&dataset[hash_32[6467]]);
	hash_64[3236] = *((uint64_t*)&dataset[hash_32[6468]]);
	hash_64[3237] = *((uint64_t*)&dataset[hash_32[6469]]);
	hash_64[3238] = *((uint64_t*)&dataset[hash_32[6470]]);
	hash_64[3239] = *((uint64_t*)&dataset[hash_32[6471]]);
	hash_64[3240] = *((uint64_t*)&dataset[hash_32[6472]]);
	hash_64[3241] = *((uint64_t*)&dataset[hash_32[6473]]);
	hash_64[3242] = *((uint64_t*)&dataset[hash_32[6474]]);
	hash_64[3243] = *((uint64_t*)&dataset[hash_32[6475]]);
	hash_64[3244] = *((uint64_t*)&dataset[hash_32[6476]]);
	hash_64[3245] = *((uint64_t*)&dataset[hash_32[6477]]);
	hash_64[3246] = *((uint64_t*)&dataset[hash_32[6478]]);
	hash_64[3247] = *((uint64_t*)&dataset[hash_32[6479]]);
#endif
#if MEMORY_THREADS > 203
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3248] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3249] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3250] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3251] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3252] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3253] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3254] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3255] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3248] = *((uint64_t*)&dataset[hash_32[6496]]);
	hash_64[3249] = *((uint64_t*)&dataset[hash_32[6497]]);
	hash_64[3250] = *((uint64_t*)&dataset[hash_32[6498]]);
	hash_64[3251] = *((uint64_t*)&dataset[hash_32[6499]]);
	hash_64[3252] = *((uint64_t*)&dataset[hash_32[6500]]);
	hash_64[3253] = *((uint64_t*)&dataset[hash_32[6501]]);
	hash_64[3254] = *((uint64_t*)&dataset[hash_32[6502]]);
	hash_64[3255] = *((uint64_t*)&dataset[hash_32[6503]]);
	hash_64[3256] = *((uint64_t*)&dataset[hash_32[6504]]);
	hash_64[3257] = *((uint64_t*)&dataset[hash_32[6505]]);
	hash_64[3258] = *((uint64_t*)&dataset[hash_32[6506]]);
	hash_64[3259] = *((uint64_t*)&dataset[hash_32[6507]]);
	hash_64[3260] = *((uint64_t*)&dataset[hash_32[6508]]);
	hash_64[3261] = *((uint64_t*)&dataset[hash_32[6509]]);
	hash_64[3262] = *((uint64_t*)&dataset[hash_32[6510]]);
	hash_64[3263] = *((uint64_t*)&dataset[hash_32[6511]]);
#endif
#if MEMORY_THREADS > 204
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3264] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3265] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3266] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3267] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3268] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3269] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3270] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3271] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3264] = *((uint64_t*)&dataset[hash_32[6528]]);
	hash_64[3265] = *((uint64_t*)&dataset[hash_32[6529]]);
	hash_64[3266] = *((uint64_t*)&dataset[hash_32[6530]]);
	hash_64[3267] = *((uint64_t*)&dataset[hash_32[6531]]);
	hash_64[3268] = *((uint64_t*)&dataset[hash_32[6532]]);
	hash_64[3269] = *((uint64_t*)&dataset[hash_32[6533]]);
	hash_64[3270] = *((uint64_t*)&dataset[hash_32[6534]]);
	hash_64[3271] = *((uint64_t*)&dataset[hash_32[6535]]);
	hash_64[3272] = *((uint64_t*)&dataset[hash_32[6536]]);
	hash_64[3273] = *((uint64_t*)&dataset[hash_32[6537]]);
	hash_64[3274] = *((uint64_t*)&dataset[hash_32[6538]]);
	hash_64[3275] = *((uint64_t*)&dataset[hash_32[6539]]);
	hash_64[3276] = *((uint64_t*)&dataset[hash_32[6540]]);
	hash_64[3277] = *((uint64_t*)&dataset[hash_32[6541]]);
	hash_64[3278] = *((uint64_t*)&dataset[hash_32[6542]]);
	hash_64[3279] = *((uint64_t*)&dataset[hash_32[6543]]);
#endif
#if MEMORY_THREADS > 205
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3280] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3281] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3282] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3283] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3284] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3285] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3286] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3287] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3280] = *((uint64_t*)&dataset[hash_32[6560]]);
	hash_64[3281] = *((uint64_t*)&dataset[hash_32[6561]]);
	hash_64[3282] = *((uint64_t*)&dataset[hash_32[6562]]);
	hash_64[3283] = *((uint64_t*)&dataset[hash_32[6563]]);
	hash_64[3284] = *((uint64_t*)&dataset[hash_32[6564]]);
	hash_64[3285] = *((uint64_t*)&dataset[hash_32[6565]]);
	hash_64[3286] = *((uint64_t*)&dataset[hash_32[6566]]);
	hash_64[3287] = *((uint64_t*)&dataset[hash_32[6567]]);
	hash_64[3288] = *((uint64_t*)&dataset[hash_32[6568]]);
	hash_64[3289] = *((uint64_t*)&dataset[hash_32[6569]]);
	hash_64[3290] = *((uint64_t*)&dataset[hash_32[6570]]);
	hash_64[3291] = *((uint64_t*)&dataset[hash_32[6571]]);
	hash_64[3292] = *((uint64_t*)&dataset[hash_32[6572]]);
	hash_64[3293] = *((uint64_t*)&dataset[hash_32[6573]]);
	hash_64[3294] = *((uint64_t*)&dataset[hash_32[6574]]);
	hash_64[3295] = *((uint64_t*)&dataset[hash_32[6575]]);
#endif
#if MEMORY_THREADS > 206
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3296] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3297] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3298] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3299] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3300] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3301] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3302] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3303] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3296] = *((uint64_t*)&dataset[hash_32[6592]]);
	hash_64[3297] = *((uint64_t*)&dataset[hash_32[6593]]);
	hash_64[3298] = *((uint64_t*)&dataset[hash_32[6594]]);
	hash_64[3299] = *((uint64_t*)&dataset[hash_32[6595]]);
	hash_64[3300] = *((uint64_t*)&dataset[hash_32[6596]]);
	hash_64[3301] = *((uint64_t*)&dataset[hash_32[6597]]);
	hash_64[3302] = *((uint64_t*)&dataset[hash_32[6598]]);
	hash_64[3303] = *((uint64_t*)&dataset[hash_32[6599]]);
	hash_64[3304] = *((uint64_t*)&dataset[hash_32[6600]]);
	hash_64[3305] = *((uint64_t*)&dataset[hash_32[6601]]);
	hash_64[3306] = *((uint64_t*)&dataset[hash_32[6602]]);
	hash_64[3307] = *((uint64_t*)&dataset[hash_32[6603]]);
	hash_64[3308] = *((uint64_t*)&dataset[hash_32[6604]]);
	hash_64[3309] = *((uint64_t*)&dataset[hash_32[6605]]);
	hash_64[3310] = *((uint64_t*)&dataset[hash_32[6606]]);
	hash_64[3311] = *((uint64_t*)&dataset[hash_32[6607]]);
#endif
#if MEMORY_THREADS > 207
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3312] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3313] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3314] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3315] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3316] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3317] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3318] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3319] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3312] = *((uint64_t*)&dataset[hash_32[6624]]);
	hash_64[3313] = *((uint64_t*)&dataset[hash_32[6625]]);
	hash_64[3314] = *((uint64_t*)&dataset[hash_32[6626]]);
	hash_64[3315] = *((uint64_t*)&dataset[hash_32[6627]]);
	hash_64[3316] = *((uint64_t*)&dataset[hash_32[6628]]);
	hash_64[3317] = *((uint64_t*)&dataset[hash_32[6629]]);
	hash_64[3318] = *((uint64_t*)&dataset[hash_32[6630]]);
	hash_64[3319] = *((uint64_t*)&dataset[hash_32[6631]]);
	hash_64[3320] = *((uint64_t*)&dataset[hash_32[6632]]);
	hash_64[3321] = *((uint64_t*)&dataset[hash_32[6633]]);
	hash_64[3322] = *((uint64_t*)&dataset[hash_32[6634]]);
	hash_64[3323] = *((uint64_t*)&dataset[hash_32[6635]]);
	hash_64[3324] = *((uint64_t*)&dataset[hash_32[6636]]);
	hash_64[3325] = *((uint64_t*)&dataset[hash_32[6637]]);
	hash_64[3326] = *((uint64_t*)&dataset[hash_32[6638]]);
	hash_64[3327] = *((uint64_t*)&dataset[hash_32[6639]]);
#endif
#if MEMORY_THREADS > 208
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3328] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3329] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3330] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3331] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3332] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3333] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3334] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3335] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3328] = *((uint64_t*)&dataset[hash_32[6656]]);
	hash_64[3329] = *((uint64_t*)&dataset[hash_32[6657]]);
	hash_64[3330] = *((uint64_t*)&dataset[hash_32[6658]]);
	hash_64[3331] = *((uint64_t*)&dataset[hash_32[6659]]);
	hash_64[3332] = *((uint64_t*)&dataset[hash_32[6660]]);
	hash_64[3333] = *((uint64_t*)&dataset[hash_32[6661]]);
	hash_64[3334] = *((uint64_t*)&dataset[hash_32[6662]]);
	hash_64[3335] = *((uint64_t*)&dataset[hash_32[6663]]);
	hash_64[3336] = *((uint64_t*)&dataset[hash_32[6664]]);
	hash_64[3337] = *((uint64_t*)&dataset[hash_32[6665]]);
	hash_64[3338] = *((uint64_t*)&dataset[hash_32[6666]]);
	hash_64[3339] = *((uint64_t*)&dataset[hash_32[6667]]);
	hash_64[3340] = *((uint64_t*)&dataset[hash_32[6668]]);
	hash_64[3341] = *((uint64_t*)&dataset[hash_32[6669]]);
	hash_64[3342] = *((uint64_t*)&dataset[hash_32[6670]]);
	hash_64[3343] = *((uint64_t*)&dataset[hash_32[6671]]);
#endif
#if MEMORY_THREADS > 209
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3344] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3345] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3346] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3347] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3348] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3349] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3350] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3351] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3344] = *((uint64_t*)&dataset[hash_32[6688]]);
	hash_64[3345] = *((uint64_t*)&dataset[hash_32[6689]]);
	hash_64[3346] = *((uint64_t*)&dataset[hash_32[6690]]);
	hash_64[3347] = *((uint64_t*)&dataset[hash_32[6691]]);
	hash_64[3348] = *((uint64_t*)&dataset[hash_32[6692]]);
	hash_64[3349] = *((uint64_t*)&dataset[hash_32[6693]]);
	hash_64[3350] = *((uint64_t*)&dataset[hash_32[6694]]);
	hash_64[3351] = *((uint64_t*)&dataset[hash_32[6695]]);
	hash_64[3352] = *((uint64_t*)&dataset[hash_32[6696]]);
	hash_64[3353] = *((uint64_t*)&dataset[hash_32[6697]]);
	hash_64[3354] = *((uint64_t*)&dataset[hash_32[6698]]);
	hash_64[3355] = *((uint64_t*)&dataset[hash_32[6699]]);
	hash_64[3356] = *((uint64_t*)&dataset[hash_32[6700]]);
	hash_64[3357] = *((uint64_t*)&dataset[hash_32[6701]]);
	hash_64[3358] = *((uint64_t*)&dataset[hash_32[6702]]);
	hash_64[3359] = *((uint64_t*)&dataset[hash_32[6703]]);
#endif
#if MEMORY_THREADS > 210
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3360] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3361] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3362] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3363] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3364] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3365] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3366] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3367] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3360] = *((uint64_t*)&dataset[hash_32[6720]]);
	hash_64[3361] = *((uint64_t*)&dataset[hash_32[6721]]);
	hash_64[3362] = *((uint64_t*)&dataset[hash_32[6722]]);
	hash_64[3363] = *((uint64_t*)&dataset[hash_32[6723]]);
	hash_64[3364] = *((uint64_t*)&dataset[hash_32[6724]]);
	hash_64[3365] = *((uint64_t*)&dataset[hash_32[6725]]);
	hash_64[3366] = *((uint64_t*)&dataset[hash_32[6726]]);
	hash_64[3367] = *((uint64_t*)&dataset[hash_32[6727]]);
	hash_64[3368] = *((uint64_t*)&dataset[hash_32[6728]]);
	hash_64[3369] = *((uint64_t*)&dataset[hash_32[6729]]);
	hash_64[3370] = *((uint64_t*)&dataset[hash_32[6730]]);
	hash_64[3371] = *((uint64_t*)&dataset[hash_32[6731]]);
	hash_64[3372] = *((uint64_t*)&dataset[hash_32[6732]]);
	hash_64[3373] = *((uint64_t*)&dataset[hash_32[6733]]);
	hash_64[3374] = *((uint64_t*)&dataset[hash_32[6734]]);
	hash_64[3375] = *((uint64_t*)&dataset[hash_32[6735]]);
#endif
#if MEMORY_THREADS > 211
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3376] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3377] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3378] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3379] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3380] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3381] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3382] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3383] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3376] = *((uint64_t*)&dataset[hash_32[6752]]);
	hash_64[3377] = *((uint64_t*)&dataset[hash_32[6753]]);
	hash_64[3378] = *((uint64_t*)&dataset[hash_32[6754]]);
	hash_64[3379] = *((uint64_t*)&dataset[hash_32[6755]]);
	hash_64[3380] = *((uint64_t*)&dataset[hash_32[6756]]);
	hash_64[3381] = *((uint64_t*)&dataset[hash_32[6757]]);
	hash_64[3382] = *((uint64_t*)&dataset[hash_32[6758]]);
	hash_64[3383] = *((uint64_t*)&dataset[hash_32[6759]]);
	hash_64[3384] = *((uint64_t*)&dataset[hash_32[6760]]);
	hash_64[3385] = *((uint64_t*)&dataset[hash_32[6761]]);
	hash_64[3386] = *((uint64_t*)&dataset[hash_32[6762]]);
	hash_64[3387] = *((uint64_t*)&dataset[hash_32[6763]]);
	hash_64[3388] = *((uint64_t*)&dataset[hash_32[6764]]);
	hash_64[3389] = *((uint64_t*)&dataset[hash_32[6765]]);
	hash_64[3390] = *((uint64_t*)&dataset[hash_32[6766]]);
	hash_64[3391] = *((uint64_t*)&dataset[hash_32[6767]]);
#endif
#if MEMORY_THREADS > 212
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3392] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3393] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3394] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3395] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3396] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3397] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3398] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3399] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3392] = *((uint64_t*)&dataset[hash_32[6784]]);
	hash_64[3393] = *((uint64_t*)&dataset[hash_32[6785]]);
	hash_64[3394] = *((uint64_t*)&dataset[hash_32[6786]]);
	hash_64[3395] = *((uint64_t*)&dataset[hash_32[6787]]);
	hash_64[3396] = *((uint64_t*)&dataset[hash_32[6788]]);
	hash_64[3397] = *((uint64_t*)&dataset[hash_32[6789]]);
	hash_64[3398] = *((uint64_t*)&dataset[hash_32[6790]]);
	hash_64[3399] = *((uint64_t*)&dataset[hash_32[6791]]);
	hash_64[3400] = *((uint64_t*)&dataset[hash_32[6792]]);
	hash_64[3401] = *((uint64_t*)&dataset[hash_32[6793]]);
	hash_64[3402] = *((uint64_t*)&dataset[hash_32[6794]]);
	hash_64[3403] = *((uint64_t*)&dataset[hash_32[6795]]);
	hash_64[3404] = *((uint64_t*)&dataset[hash_32[6796]]);
	hash_64[3405] = *((uint64_t*)&dataset[hash_32[6797]]);
	hash_64[3406] = *((uint64_t*)&dataset[hash_32[6798]]);
	hash_64[3407] = *((uint64_t*)&dataset[hash_32[6799]]);
#endif
#if MEMORY_THREADS > 213
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3408] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3409] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3410] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3411] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3412] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3413] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3414] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3415] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3408] = *((uint64_t*)&dataset[hash_32[6816]]);
	hash_64[3409] = *((uint64_t*)&dataset[hash_32[6817]]);
	hash_64[3410] = *((uint64_t*)&dataset[hash_32[6818]]);
	hash_64[3411] = *((uint64_t*)&dataset[hash_32[6819]]);
	hash_64[3412] = *((uint64_t*)&dataset[hash_32[6820]]);
	hash_64[3413] = *((uint64_t*)&dataset[hash_32[6821]]);
	hash_64[3414] = *((uint64_t*)&dataset[hash_32[6822]]);
	hash_64[3415] = *((uint64_t*)&dataset[hash_32[6823]]);
	hash_64[3416] = *((uint64_t*)&dataset[hash_32[6824]]);
	hash_64[3417] = *((uint64_t*)&dataset[hash_32[6825]]);
	hash_64[3418] = *((uint64_t*)&dataset[hash_32[6826]]);
	hash_64[3419] = *((uint64_t*)&dataset[hash_32[6827]]);
	hash_64[3420] = *((uint64_t*)&dataset[hash_32[6828]]);
	hash_64[3421] = *((uint64_t*)&dataset[hash_32[6829]]);
	hash_64[3422] = *((uint64_t*)&dataset[hash_32[6830]]);
	hash_64[3423] = *((uint64_t*)&dataset[hash_32[6831]]);
#endif
#if MEMORY_THREADS > 214
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3424] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3425] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3426] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3427] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3428] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3429] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3430] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3431] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3424] = *((uint64_t*)&dataset[hash_32[6848]]);
	hash_64[3425] = *((uint64_t*)&dataset[hash_32[6849]]);
	hash_64[3426] = *((uint64_t*)&dataset[hash_32[6850]]);
	hash_64[3427] = *((uint64_t*)&dataset[hash_32[6851]]);
	hash_64[3428] = *((uint64_t*)&dataset[hash_32[6852]]);
	hash_64[3429] = *((uint64_t*)&dataset[hash_32[6853]]);
	hash_64[3430] = *((uint64_t*)&dataset[hash_32[6854]]);
	hash_64[3431] = *((uint64_t*)&dataset[hash_32[6855]]);
	hash_64[3432] = *((uint64_t*)&dataset[hash_32[6856]]);
	hash_64[3433] = *((uint64_t*)&dataset[hash_32[6857]]);
	hash_64[3434] = *((uint64_t*)&dataset[hash_32[6858]]);
	hash_64[3435] = *((uint64_t*)&dataset[hash_32[6859]]);
	hash_64[3436] = *((uint64_t*)&dataset[hash_32[6860]]);
	hash_64[3437] = *((uint64_t*)&dataset[hash_32[6861]]);
	hash_64[3438] = *((uint64_t*)&dataset[hash_32[6862]]);
	hash_64[3439] = *((uint64_t*)&dataset[hash_32[6863]]);
#endif
#if MEMORY_THREADS > 215
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3440] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3441] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3442] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3443] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3444] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3445] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3446] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3447] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3440] = *((uint64_t*)&dataset[hash_32[6880]]);
	hash_64[3441] = *((uint64_t*)&dataset[hash_32[6881]]);
	hash_64[3442] = *((uint64_t*)&dataset[hash_32[6882]]);
	hash_64[3443] = *((uint64_t*)&dataset[hash_32[6883]]);
	hash_64[3444] = *((uint64_t*)&dataset[hash_32[6884]]);
	hash_64[3445] = *((uint64_t*)&dataset[hash_32[6885]]);
	hash_64[3446] = *((uint64_t*)&dataset[hash_32[6886]]);
	hash_64[3447] = *((uint64_t*)&dataset[hash_32[6887]]);
	hash_64[3448] = *((uint64_t*)&dataset[hash_32[6888]]);
	hash_64[3449] = *((uint64_t*)&dataset[hash_32[6889]]);
	hash_64[3450] = *((uint64_t*)&dataset[hash_32[6890]]);
	hash_64[3451] = *((uint64_t*)&dataset[hash_32[6891]]);
	hash_64[3452] = *((uint64_t*)&dataset[hash_32[6892]]);
	hash_64[3453] = *((uint64_t*)&dataset[hash_32[6893]]);
	hash_64[3454] = *((uint64_t*)&dataset[hash_32[6894]]);
	hash_64[3455] = *((uint64_t*)&dataset[hash_32[6895]]);
#endif
#if MEMORY_THREADS > 216
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3456] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3457] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3458] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3459] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3460] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3461] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3462] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3463] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3456] = *((uint64_t*)&dataset[hash_32[6912]]);
	hash_64[3457] = *((uint64_t*)&dataset[hash_32[6913]]);
	hash_64[3458] = *((uint64_t*)&dataset[hash_32[6914]]);
	hash_64[3459] = *((uint64_t*)&dataset[hash_32[6915]]);
	hash_64[3460] = *((uint64_t*)&dataset[hash_32[6916]]);
	hash_64[3461] = *((uint64_t*)&dataset[hash_32[6917]]);
	hash_64[3462] = *((uint64_t*)&dataset[hash_32[6918]]);
	hash_64[3463] = *((uint64_t*)&dataset[hash_32[6919]]);
	hash_64[3464] = *((uint64_t*)&dataset[hash_32[6920]]);
	hash_64[3465] = *((uint64_t*)&dataset[hash_32[6921]]);
	hash_64[3466] = *((uint64_t*)&dataset[hash_32[6922]]);
	hash_64[3467] = *((uint64_t*)&dataset[hash_32[6923]]);
	hash_64[3468] = *((uint64_t*)&dataset[hash_32[6924]]);
	hash_64[3469] = *((uint64_t*)&dataset[hash_32[6925]]);
	hash_64[3470] = *((uint64_t*)&dataset[hash_32[6926]]);
	hash_64[3471] = *((uint64_t*)&dataset[hash_32[6927]]);
#endif
#if MEMORY_THREADS > 217
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3472] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3473] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3474] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3475] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3476] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3477] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3478] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3479] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3472] = *((uint64_t*)&dataset[hash_32[6944]]);
	hash_64[3473] = *((uint64_t*)&dataset[hash_32[6945]]);
	hash_64[3474] = *((uint64_t*)&dataset[hash_32[6946]]);
	hash_64[3475] = *((uint64_t*)&dataset[hash_32[6947]]);
	hash_64[3476] = *((uint64_t*)&dataset[hash_32[6948]]);
	hash_64[3477] = *((uint64_t*)&dataset[hash_32[6949]]);
	hash_64[3478] = *((uint64_t*)&dataset[hash_32[6950]]);
	hash_64[3479] = *((uint64_t*)&dataset[hash_32[6951]]);
	hash_64[3480] = *((uint64_t*)&dataset[hash_32[6952]]);
	hash_64[3481] = *((uint64_t*)&dataset[hash_32[6953]]);
	hash_64[3482] = *((uint64_t*)&dataset[hash_32[6954]]);
	hash_64[3483] = *((uint64_t*)&dataset[hash_32[6955]]);
	hash_64[3484] = *((uint64_t*)&dataset[hash_32[6956]]);
	hash_64[3485] = *((uint64_t*)&dataset[hash_32[6957]]);
	hash_64[3486] = *((uint64_t*)&dataset[hash_32[6958]]);
	hash_64[3487] = *((uint64_t*)&dataset[hash_32[6959]]);
#endif
#if MEMORY_THREADS > 218
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3488] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3489] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3490] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3491] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3492] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3493] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3494] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3495] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3488] = *((uint64_t*)&dataset[hash_32[6976]]);
	hash_64[3489] = *((uint64_t*)&dataset[hash_32[6977]]);
	hash_64[3490] = *((uint64_t*)&dataset[hash_32[6978]]);
	hash_64[3491] = *((uint64_t*)&dataset[hash_32[6979]]);
	hash_64[3492] = *((uint64_t*)&dataset[hash_32[6980]]);
	hash_64[3493] = *((uint64_t*)&dataset[hash_32[6981]]);
	hash_64[3494] = *((uint64_t*)&dataset[hash_32[6982]]);
	hash_64[3495] = *((uint64_t*)&dataset[hash_32[6983]]);
	hash_64[3496] = *((uint64_t*)&dataset[hash_32[6984]]);
	hash_64[3497] = *((uint64_t*)&dataset[hash_32[6985]]);
	hash_64[3498] = *((uint64_t*)&dataset[hash_32[6986]]);
	hash_64[3499] = *((uint64_t*)&dataset[hash_32[6987]]);
	hash_64[3500] = *((uint64_t*)&dataset[hash_32[6988]]);
	hash_64[3501] = *((uint64_t*)&dataset[hash_32[6989]]);
	hash_64[3502] = *((uint64_t*)&dataset[hash_32[6990]]);
	hash_64[3503] = *((uint64_t*)&dataset[hash_32[6991]]);
#endif
#if MEMORY_THREADS > 219
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3504] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3505] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3506] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3507] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3508] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3509] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3510] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3511] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3504] = *((uint64_t*)&dataset[hash_32[7008]]);
	hash_64[3505] = *((uint64_t*)&dataset[hash_32[7009]]);
	hash_64[3506] = *((uint64_t*)&dataset[hash_32[7010]]);
	hash_64[3507] = *((uint64_t*)&dataset[hash_32[7011]]);
	hash_64[3508] = *((uint64_t*)&dataset[hash_32[7012]]);
	hash_64[3509] = *((uint64_t*)&dataset[hash_32[7013]]);
	hash_64[3510] = *((uint64_t*)&dataset[hash_32[7014]]);
	hash_64[3511] = *((uint64_t*)&dataset[hash_32[7015]]);
	hash_64[3512] = *((uint64_t*)&dataset[hash_32[7016]]);
	hash_64[3513] = *((uint64_t*)&dataset[hash_32[7017]]);
	hash_64[3514] = *((uint64_t*)&dataset[hash_32[7018]]);
	hash_64[3515] = *((uint64_t*)&dataset[hash_32[7019]]);
	hash_64[3516] = *((uint64_t*)&dataset[hash_32[7020]]);
	hash_64[3517] = *((uint64_t*)&dataset[hash_32[7021]]);
	hash_64[3518] = *((uint64_t*)&dataset[hash_32[7022]]);
	hash_64[3519] = *((uint64_t*)&dataset[hash_32[7023]]);
#endif
#if MEMORY_THREADS > 220
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3520] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3521] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3522] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3523] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3524] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3525] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3526] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3527] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3520] = *((uint64_t*)&dataset[hash_32[7040]]);
	hash_64[3521] = *((uint64_t*)&dataset[hash_32[7041]]);
	hash_64[3522] = *((uint64_t*)&dataset[hash_32[7042]]);
	hash_64[3523] = *((uint64_t*)&dataset[hash_32[7043]]);
	hash_64[3524] = *((uint64_t*)&dataset[hash_32[7044]]);
	hash_64[3525] = *((uint64_t*)&dataset[hash_32[7045]]);
	hash_64[3526] = *((uint64_t*)&dataset[hash_32[7046]]);
	hash_64[3527] = *((uint64_t*)&dataset[hash_32[7047]]);
	hash_64[3528] = *((uint64_t*)&dataset[hash_32[7048]]);
	hash_64[3529] = *((uint64_t*)&dataset[hash_32[7049]]);
	hash_64[3530] = *((uint64_t*)&dataset[hash_32[7050]]);
	hash_64[3531] = *((uint64_t*)&dataset[hash_32[7051]]);
	hash_64[3532] = *((uint64_t*)&dataset[hash_32[7052]]);
	hash_64[3533] = *((uint64_t*)&dataset[hash_32[7053]]);
	hash_64[3534] = *((uint64_t*)&dataset[hash_32[7054]]);
	hash_64[3535] = *((uint64_t*)&dataset[hash_32[7055]]);
#endif
#if MEMORY_THREADS > 221
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3536] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3537] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3538] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3539] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3540] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3541] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3542] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3543] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3536] = *((uint64_t*)&dataset[hash_32[7072]]);
	hash_64[3537] = *((uint64_t*)&dataset[hash_32[7073]]);
	hash_64[3538] = *((uint64_t*)&dataset[hash_32[7074]]);
	hash_64[3539] = *((uint64_t*)&dataset[hash_32[7075]]);
	hash_64[3540] = *((uint64_t*)&dataset[hash_32[7076]]);
	hash_64[3541] = *((uint64_t*)&dataset[hash_32[7077]]);
	hash_64[3542] = *((uint64_t*)&dataset[hash_32[7078]]);
	hash_64[3543] = *((uint64_t*)&dataset[hash_32[7079]]);
	hash_64[3544] = *((uint64_t*)&dataset[hash_32[7080]]);
	hash_64[3545] = *((uint64_t*)&dataset[hash_32[7081]]);
	hash_64[3546] = *((uint64_t*)&dataset[hash_32[7082]]);
	hash_64[3547] = *((uint64_t*)&dataset[hash_32[7083]]);
	hash_64[3548] = *((uint64_t*)&dataset[hash_32[7084]]);
	hash_64[3549] = *((uint64_t*)&dataset[hash_32[7085]]);
	hash_64[3550] = *((uint64_t*)&dataset[hash_32[7086]]);
	hash_64[3551] = *((uint64_t*)&dataset[hash_32[7087]]);
#endif
#if MEMORY_THREADS > 222
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3552] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3553] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3554] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3555] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3556] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3557] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3558] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3559] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3552] = *((uint64_t*)&dataset[hash_32[7104]]);
	hash_64[3553] = *((uint64_t*)&dataset[hash_32[7105]]);
	hash_64[3554] = *((uint64_t*)&dataset[hash_32[7106]]);
	hash_64[3555] = *((uint64_t*)&dataset[hash_32[7107]]);
	hash_64[3556] = *((uint64_t*)&dataset[hash_32[7108]]);
	hash_64[3557] = *((uint64_t*)&dataset[hash_32[7109]]);
	hash_64[3558] = *((uint64_t*)&dataset[hash_32[7110]]);
	hash_64[3559] = *((uint64_t*)&dataset[hash_32[7111]]);
	hash_64[3560] = *((uint64_t*)&dataset[hash_32[7112]]);
	hash_64[3561] = *((uint64_t*)&dataset[hash_32[7113]]);
	hash_64[3562] = *((uint64_t*)&dataset[hash_32[7114]]);
	hash_64[3563] = *((uint64_t*)&dataset[hash_32[7115]]);
	hash_64[3564] = *((uint64_t*)&dataset[hash_32[7116]]);
	hash_64[3565] = *((uint64_t*)&dataset[hash_32[7117]]);
	hash_64[3566] = *((uint64_t*)&dataset[hash_32[7118]]);
	hash_64[3567] = *((uint64_t*)&dataset[hash_32[7119]]);
#endif
#if MEMORY_THREADS > 223
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3568] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3569] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3570] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3571] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3572] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3573] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3574] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3575] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3568] = *((uint64_t*)&dataset[hash_32[7136]]);
	hash_64[3569] = *((uint64_t*)&dataset[hash_32[7137]]);
	hash_64[3570] = *((uint64_t*)&dataset[hash_32[7138]]);
	hash_64[3571] = *((uint64_t*)&dataset[hash_32[7139]]);
	hash_64[3572] = *((uint64_t*)&dataset[hash_32[7140]]);
	hash_64[3573] = *((uint64_t*)&dataset[hash_32[7141]]);
	hash_64[3574] = *((uint64_t*)&dataset[hash_32[7142]]);
	hash_64[3575] = *((uint64_t*)&dataset[hash_32[7143]]);
	hash_64[3576] = *((uint64_t*)&dataset[hash_32[7144]]);
	hash_64[3577] = *((uint64_t*)&dataset[hash_32[7145]]);
	hash_64[3578] = *((uint64_t*)&dataset[hash_32[7146]]);
	hash_64[3579] = *((uint64_t*)&dataset[hash_32[7147]]);
	hash_64[3580] = *((uint64_t*)&dataset[hash_32[7148]]);
	hash_64[3581] = *((uint64_t*)&dataset[hash_32[7149]]);
	hash_64[3582] = *((uint64_t*)&dataset[hash_32[7150]]);
	hash_64[3583] = *((uint64_t*)&dataset[hash_32[7151]]);
#endif
#if MEMORY_THREADS > 224
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3584] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3585] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3586] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3587] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3588] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3589] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3590] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3591] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3584] = *((uint64_t*)&dataset[hash_32[7168]]);
	hash_64[3585] = *((uint64_t*)&dataset[hash_32[7169]]);
	hash_64[3586] = *((uint64_t*)&dataset[hash_32[7170]]);
	hash_64[3587] = *((uint64_t*)&dataset[hash_32[7171]]);
	hash_64[3588] = *((uint64_t*)&dataset[hash_32[7172]]);
	hash_64[3589] = *((uint64_t*)&dataset[hash_32[7173]]);
	hash_64[3590] = *((uint64_t*)&dataset[hash_32[7174]]);
	hash_64[3591] = *((uint64_t*)&dataset[hash_32[7175]]);
	hash_64[3592] = *((uint64_t*)&dataset[hash_32[7176]]);
	hash_64[3593] = *((uint64_t*)&dataset[hash_32[7177]]);
	hash_64[3594] = *((uint64_t*)&dataset[hash_32[7178]]);
	hash_64[3595] = *((uint64_t*)&dataset[hash_32[7179]]);
	hash_64[3596] = *((uint64_t*)&dataset[hash_32[7180]]);
	hash_64[3597] = *((uint64_t*)&dataset[hash_32[7181]]);
	hash_64[3598] = *((uint64_t*)&dataset[hash_32[7182]]);
	hash_64[3599] = *((uint64_t*)&dataset[hash_32[7183]]);
#endif
#if MEMORY_THREADS > 225
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3600] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3601] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3602] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3603] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3604] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3605] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3606] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3607] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3600] = *((uint64_t*)&dataset[hash_32[7200]]);
	hash_64[3601] = *((uint64_t*)&dataset[hash_32[7201]]);
	hash_64[3602] = *((uint64_t*)&dataset[hash_32[7202]]);
	hash_64[3603] = *((uint64_t*)&dataset[hash_32[7203]]);
	hash_64[3604] = *((uint64_t*)&dataset[hash_32[7204]]);
	hash_64[3605] = *((uint64_t*)&dataset[hash_32[7205]]);
	hash_64[3606] = *((uint64_t*)&dataset[hash_32[7206]]);
	hash_64[3607] = *((uint64_t*)&dataset[hash_32[7207]]);
	hash_64[3608] = *((uint64_t*)&dataset[hash_32[7208]]);
	hash_64[3609] = *((uint64_t*)&dataset[hash_32[7209]]);
	hash_64[3610] = *((uint64_t*)&dataset[hash_32[7210]]);
	hash_64[3611] = *((uint64_t*)&dataset[hash_32[7211]]);
	hash_64[3612] = *((uint64_t*)&dataset[hash_32[7212]]);
	hash_64[3613] = *((uint64_t*)&dataset[hash_32[7213]]);
	hash_64[3614] = *((uint64_t*)&dataset[hash_32[7214]]);
	hash_64[3615] = *((uint64_t*)&dataset[hash_32[7215]]);
#endif
#if MEMORY_THREADS > 226
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3616] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3617] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3618] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3619] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3620] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3621] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3622] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3623] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3616] = *((uint64_t*)&dataset[hash_32[7232]]);
	hash_64[3617] = *((uint64_t*)&dataset[hash_32[7233]]);
	hash_64[3618] = *((uint64_t*)&dataset[hash_32[7234]]);
	hash_64[3619] = *((uint64_t*)&dataset[hash_32[7235]]);
	hash_64[3620] = *((uint64_t*)&dataset[hash_32[7236]]);
	hash_64[3621] = *((uint64_t*)&dataset[hash_32[7237]]);
	hash_64[3622] = *((uint64_t*)&dataset[hash_32[7238]]);
	hash_64[3623] = *((uint64_t*)&dataset[hash_32[7239]]);
	hash_64[3624] = *((uint64_t*)&dataset[hash_32[7240]]);
	hash_64[3625] = *((uint64_t*)&dataset[hash_32[7241]]);
	hash_64[3626] = *((uint64_t*)&dataset[hash_32[7242]]);
	hash_64[3627] = *((uint64_t*)&dataset[hash_32[7243]]);
	hash_64[3628] = *((uint64_t*)&dataset[hash_32[7244]]);
	hash_64[3629] = *((uint64_t*)&dataset[hash_32[7245]]);
	hash_64[3630] = *((uint64_t*)&dataset[hash_32[7246]]);
	hash_64[3631] = *((uint64_t*)&dataset[hash_32[7247]]);
#endif
#if MEMORY_THREADS > 227
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3632] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3633] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3634] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3635] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3636] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3637] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3638] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3639] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3632] = *((uint64_t*)&dataset[hash_32[7264]]);
	hash_64[3633] = *((uint64_t*)&dataset[hash_32[7265]]);
	hash_64[3634] = *((uint64_t*)&dataset[hash_32[7266]]);
	hash_64[3635] = *((uint64_t*)&dataset[hash_32[7267]]);
	hash_64[3636] = *((uint64_t*)&dataset[hash_32[7268]]);
	hash_64[3637] = *((uint64_t*)&dataset[hash_32[7269]]);
	hash_64[3638] = *((uint64_t*)&dataset[hash_32[7270]]);
	hash_64[3639] = *((uint64_t*)&dataset[hash_32[7271]]);
	hash_64[3640] = *((uint64_t*)&dataset[hash_32[7272]]);
	hash_64[3641] = *((uint64_t*)&dataset[hash_32[7273]]);
	hash_64[3642] = *((uint64_t*)&dataset[hash_32[7274]]);
	hash_64[3643] = *((uint64_t*)&dataset[hash_32[7275]]);
	hash_64[3644] = *((uint64_t*)&dataset[hash_32[7276]]);
	hash_64[3645] = *((uint64_t*)&dataset[hash_32[7277]]);
	hash_64[3646] = *((uint64_t*)&dataset[hash_32[7278]]);
	hash_64[3647] = *((uint64_t*)&dataset[hash_32[7279]]);
#endif
#if MEMORY_THREADS > 228
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3648] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3649] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3650] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3651] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3652] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3653] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3654] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3655] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3648] = *((uint64_t*)&dataset[hash_32[7296]]);
	hash_64[3649] = *((uint64_t*)&dataset[hash_32[7297]]);
	hash_64[3650] = *((uint64_t*)&dataset[hash_32[7298]]);
	hash_64[3651] = *((uint64_t*)&dataset[hash_32[7299]]);
	hash_64[3652] = *((uint64_t*)&dataset[hash_32[7300]]);
	hash_64[3653] = *((uint64_t*)&dataset[hash_32[7301]]);
	hash_64[3654] = *((uint64_t*)&dataset[hash_32[7302]]);
	hash_64[3655] = *((uint64_t*)&dataset[hash_32[7303]]);
	hash_64[3656] = *((uint64_t*)&dataset[hash_32[7304]]);
	hash_64[3657] = *((uint64_t*)&dataset[hash_32[7305]]);
	hash_64[3658] = *((uint64_t*)&dataset[hash_32[7306]]);
	hash_64[3659] = *((uint64_t*)&dataset[hash_32[7307]]);
	hash_64[3660] = *((uint64_t*)&dataset[hash_32[7308]]);
	hash_64[3661] = *((uint64_t*)&dataset[hash_32[7309]]);
	hash_64[3662] = *((uint64_t*)&dataset[hash_32[7310]]);
	hash_64[3663] = *((uint64_t*)&dataset[hash_32[7311]]);
#endif
#if MEMORY_THREADS > 229
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3664] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3665] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3666] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3667] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3668] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3669] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3670] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3671] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3664] = *((uint64_t*)&dataset[hash_32[7328]]);
	hash_64[3665] = *((uint64_t*)&dataset[hash_32[7329]]);
	hash_64[3666] = *((uint64_t*)&dataset[hash_32[7330]]);
	hash_64[3667] = *((uint64_t*)&dataset[hash_32[7331]]);
	hash_64[3668] = *((uint64_t*)&dataset[hash_32[7332]]);
	hash_64[3669] = *((uint64_t*)&dataset[hash_32[7333]]);
	hash_64[3670] = *((uint64_t*)&dataset[hash_32[7334]]);
	hash_64[3671] = *((uint64_t*)&dataset[hash_32[7335]]);
	hash_64[3672] = *((uint64_t*)&dataset[hash_32[7336]]);
	hash_64[3673] = *((uint64_t*)&dataset[hash_32[7337]]);
	hash_64[3674] = *((uint64_t*)&dataset[hash_32[7338]]);
	hash_64[3675] = *((uint64_t*)&dataset[hash_32[7339]]);
	hash_64[3676] = *((uint64_t*)&dataset[hash_32[7340]]);
	hash_64[3677] = *((uint64_t*)&dataset[hash_32[7341]]);
	hash_64[3678] = *((uint64_t*)&dataset[hash_32[7342]]);
	hash_64[3679] = *((uint64_t*)&dataset[hash_32[7343]]);
#endif
#if MEMORY_THREADS > 230
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3680] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3681] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3682] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3683] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3684] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3685] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3686] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3687] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3680] = *((uint64_t*)&dataset[hash_32[7360]]);
	hash_64[3681] = *((uint64_t*)&dataset[hash_32[7361]]);
	hash_64[3682] = *((uint64_t*)&dataset[hash_32[7362]]);
	hash_64[3683] = *((uint64_t*)&dataset[hash_32[7363]]);
	hash_64[3684] = *((uint64_t*)&dataset[hash_32[7364]]);
	hash_64[3685] = *((uint64_t*)&dataset[hash_32[7365]]);
	hash_64[3686] = *((uint64_t*)&dataset[hash_32[7366]]);
	hash_64[3687] = *((uint64_t*)&dataset[hash_32[7367]]);
	hash_64[3688] = *((uint64_t*)&dataset[hash_32[7368]]);
	hash_64[3689] = *((uint64_t*)&dataset[hash_32[7369]]);
	hash_64[3690] = *((uint64_t*)&dataset[hash_32[7370]]);
	hash_64[3691] = *((uint64_t*)&dataset[hash_32[7371]]);
	hash_64[3692] = *((uint64_t*)&dataset[hash_32[7372]]);
	hash_64[3693] = *((uint64_t*)&dataset[hash_32[7373]]);
	hash_64[3694] = *((uint64_t*)&dataset[hash_32[7374]]);
	hash_64[3695] = *((uint64_t*)&dataset[hash_32[7375]]);
#endif
#if MEMORY_THREADS > 231
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3696] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3697] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3698] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3699] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3700] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3701] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3702] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3703] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3696] = *((uint64_t*)&dataset[hash_32[7392]]);
	hash_64[3697] = *((uint64_t*)&dataset[hash_32[7393]]);
	hash_64[3698] = *((uint64_t*)&dataset[hash_32[7394]]);
	hash_64[3699] = *((uint64_t*)&dataset[hash_32[7395]]);
	hash_64[3700] = *((uint64_t*)&dataset[hash_32[7396]]);
	hash_64[3701] = *((uint64_t*)&dataset[hash_32[7397]]);
	hash_64[3702] = *((uint64_t*)&dataset[hash_32[7398]]);
	hash_64[3703] = *((uint64_t*)&dataset[hash_32[7399]]);
	hash_64[3704] = *((uint64_t*)&dataset[hash_32[7400]]);
	hash_64[3705] = *((uint64_t*)&dataset[hash_32[7401]]);
	hash_64[3706] = *((uint64_t*)&dataset[hash_32[7402]]);
	hash_64[3707] = *((uint64_t*)&dataset[hash_32[7403]]);
	hash_64[3708] = *((uint64_t*)&dataset[hash_32[7404]]);
	hash_64[3709] = *((uint64_t*)&dataset[hash_32[7405]]);
	hash_64[3710] = *((uint64_t*)&dataset[hash_32[7406]]);
	hash_64[3711] = *((uint64_t*)&dataset[hash_32[7407]]);
#endif
#if MEMORY_THREADS > 232
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3712] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3713] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3714] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3715] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3716] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3717] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3718] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3719] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3712] = *((uint64_t*)&dataset[hash_32[7424]]);
	hash_64[3713] = *((uint64_t*)&dataset[hash_32[7425]]);
	hash_64[3714] = *((uint64_t*)&dataset[hash_32[7426]]);
	hash_64[3715] = *((uint64_t*)&dataset[hash_32[7427]]);
	hash_64[3716] = *((uint64_t*)&dataset[hash_32[7428]]);
	hash_64[3717] = *((uint64_t*)&dataset[hash_32[7429]]);
	hash_64[3718] = *((uint64_t*)&dataset[hash_32[7430]]);
	hash_64[3719] = *((uint64_t*)&dataset[hash_32[7431]]);
	hash_64[3720] = *((uint64_t*)&dataset[hash_32[7432]]);
	hash_64[3721] = *((uint64_t*)&dataset[hash_32[7433]]);
	hash_64[3722] = *((uint64_t*)&dataset[hash_32[7434]]);
	hash_64[3723] = *((uint64_t*)&dataset[hash_32[7435]]);
	hash_64[3724] = *((uint64_t*)&dataset[hash_32[7436]]);
	hash_64[3725] = *((uint64_t*)&dataset[hash_32[7437]]);
	hash_64[3726] = *((uint64_t*)&dataset[hash_32[7438]]);
	hash_64[3727] = *((uint64_t*)&dataset[hash_32[7439]]);
#endif
#if MEMORY_THREADS > 233
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3728] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3729] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3730] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3731] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3732] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3733] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3734] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3735] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3728] = *((uint64_t*)&dataset[hash_32[7456]]);
	hash_64[3729] = *((uint64_t*)&dataset[hash_32[7457]]);
	hash_64[3730] = *((uint64_t*)&dataset[hash_32[7458]]);
	hash_64[3731] = *((uint64_t*)&dataset[hash_32[7459]]);
	hash_64[3732] = *((uint64_t*)&dataset[hash_32[7460]]);
	hash_64[3733] = *((uint64_t*)&dataset[hash_32[7461]]);
	hash_64[3734] = *((uint64_t*)&dataset[hash_32[7462]]);
	hash_64[3735] = *((uint64_t*)&dataset[hash_32[7463]]);
	hash_64[3736] = *((uint64_t*)&dataset[hash_32[7464]]);
	hash_64[3737] = *((uint64_t*)&dataset[hash_32[7465]]);
	hash_64[3738] = *((uint64_t*)&dataset[hash_32[7466]]);
	hash_64[3739] = *((uint64_t*)&dataset[hash_32[7467]]);
	hash_64[3740] = *((uint64_t*)&dataset[hash_32[7468]]);
	hash_64[3741] = *((uint64_t*)&dataset[hash_32[7469]]);
	hash_64[3742] = *((uint64_t*)&dataset[hash_32[7470]]);
	hash_64[3743] = *((uint64_t*)&dataset[hash_32[7471]]);
#endif
#if MEMORY_THREADS > 234
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3744] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3745] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3746] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3747] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3748] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3749] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3750] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3751] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3744] = *((uint64_t*)&dataset[hash_32[7488]]);
	hash_64[3745] = *((uint64_t*)&dataset[hash_32[7489]]);
	hash_64[3746] = *((uint64_t*)&dataset[hash_32[7490]]);
	hash_64[3747] = *((uint64_t*)&dataset[hash_32[7491]]);
	hash_64[3748] = *((uint64_t*)&dataset[hash_32[7492]]);
	hash_64[3749] = *((uint64_t*)&dataset[hash_32[7493]]);
	hash_64[3750] = *((uint64_t*)&dataset[hash_32[7494]]);
	hash_64[3751] = *((uint64_t*)&dataset[hash_32[7495]]);
	hash_64[3752] = *((uint64_t*)&dataset[hash_32[7496]]);
	hash_64[3753] = *((uint64_t*)&dataset[hash_32[7497]]);
	hash_64[3754] = *((uint64_t*)&dataset[hash_32[7498]]);
	hash_64[3755] = *((uint64_t*)&dataset[hash_32[7499]]);
	hash_64[3756] = *((uint64_t*)&dataset[hash_32[7500]]);
	hash_64[3757] = *((uint64_t*)&dataset[hash_32[7501]]);
	hash_64[3758] = *((uint64_t*)&dataset[hash_32[7502]]);
	hash_64[3759] = *((uint64_t*)&dataset[hash_32[7503]]);
#endif
#if MEMORY_THREADS > 235
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3760] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3761] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3762] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3763] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3764] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3765] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3766] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3767] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3760] = *((uint64_t*)&dataset[hash_32[7520]]);
	hash_64[3761] = *((uint64_t*)&dataset[hash_32[7521]]);
	hash_64[3762] = *((uint64_t*)&dataset[hash_32[7522]]);
	hash_64[3763] = *((uint64_t*)&dataset[hash_32[7523]]);
	hash_64[3764] = *((uint64_t*)&dataset[hash_32[7524]]);
	hash_64[3765] = *((uint64_t*)&dataset[hash_32[7525]]);
	hash_64[3766] = *((uint64_t*)&dataset[hash_32[7526]]);
	hash_64[3767] = *((uint64_t*)&dataset[hash_32[7527]]);
	hash_64[3768] = *((uint64_t*)&dataset[hash_32[7528]]);
	hash_64[3769] = *((uint64_t*)&dataset[hash_32[7529]]);
	hash_64[3770] = *((uint64_t*)&dataset[hash_32[7530]]);
	hash_64[3771] = *((uint64_t*)&dataset[hash_32[7531]]);
	hash_64[3772] = *((uint64_t*)&dataset[hash_32[7532]]);
	hash_64[3773] = *((uint64_t*)&dataset[hash_32[7533]]);
	hash_64[3774] = *((uint64_t*)&dataset[hash_32[7534]]);
	hash_64[3775] = *((uint64_t*)&dataset[hash_32[7535]]);
#endif
#if MEMORY_THREADS > 236
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3776] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3777] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3778] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3779] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3780] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3781] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3782] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3783] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3776] = *((uint64_t*)&dataset[hash_32[7552]]);
	hash_64[3777] = *((uint64_t*)&dataset[hash_32[7553]]);
	hash_64[3778] = *((uint64_t*)&dataset[hash_32[7554]]);
	hash_64[3779] = *((uint64_t*)&dataset[hash_32[7555]]);
	hash_64[3780] = *((uint64_t*)&dataset[hash_32[7556]]);
	hash_64[3781] = *((uint64_t*)&dataset[hash_32[7557]]);
	hash_64[3782] = *((uint64_t*)&dataset[hash_32[7558]]);
	hash_64[3783] = *((uint64_t*)&dataset[hash_32[7559]]);
	hash_64[3784] = *((uint64_t*)&dataset[hash_32[7560]]);
	hash_64[3785] = *((uint64_t*)&dataset[hash_32[7561]]);
	hash_64[3786] = *((uint64_t*)&dataset[hash_32[7562]]);
	hash_64[3787] = *((uint64_t*)&dataset[hash_32[7563]]);
	hash_64[3788] = *((uint64_t*)&dataset[hash_32[7564]]);
	hash_64[3789] = *((uint64_t*)&dataset[hash_32[7565]]);
	hash_64[3790] = *((uint64_t*)&dataset[hash_32[7566]]);
	hash_64[3791] = *((uint64_t*)&dataset[hash_32[7567]]);
#endif
#if MEMORY_THREADS > 237
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3792] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3793] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3794] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3795] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3796] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3797] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3798] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3799] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3792] = *((uint64_t*)&dataset[hash_32[7584]]);
	hash_64[3793] = *((uint64_t*)&dataset[hash_32[7585]]);
	hash_64[3794] = *((uint64_t*)&dataset[hash_32[7586]]);
	hash_64[3795] = *((uint64_t*)&dataset[hash_32[7587]]);
	hash_64[3796] = *((uint64_t*)&dataset[hash_32[7588]]);
	hash_64[3797] = *((uint64_t*)&dataset[hash_32[7589]]);
	hash_64[3798] = *((uint64_t*)&dataset[hash_32[7590]]);
	hash_64[3799] = *((uint64_t*)&dataset[hash_32[7591]]);
	hash_64[3800] = *((uint64_t*)&dataset[hash_32[7592]]);
	hash_64[3801] = *((uint64_t*)&dataset[hash_32[7593]]);
	hash_64[3802] = *((uint64_t*)&dataset[hash_32[7594]]);
	hash_64[3803] = *((uint64_t*)&dataset[hash_32[7595]]);
	hash_64[3804] = *((uint64_t*)&dataset[hash_32[7596]]);
	hash_64[3805] = *((uint64_t*)&dataset[hash_32[7597]]);
	hash_64[3806] = *((uint64_t*)&dataset[hash_32[7598]]);
	hash_64[3807] = *((uint64_t*)&dataset[hash_32[7599]]);
#endif
#if MEMORY_THREADS > 238
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3808] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3809] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3810] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3811] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3812] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3813] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3814] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3815] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3808] = *((uint64_t*)&dataset[hash_32[7616]]);
	hash_64[3809] = *((uint64_t*)&dataset[hash_32[7617]]);
	hash_64[3810] = *((uint64_t*)&dataset[hash_32[7618]]);
	hash_64[3811] = *((uint64_t*)&dataset[hash_32[7619]]);
	hash_64[3812] = *((uint64_t*)&dataset[hash_32[7620]]);
	hash_64[3813] = *((uint64_t*)&dataset[hash_32[7621]]);
	hash_64[3814] = *((uint64_t*)&dataset[hash_32[7622]]);
	hash_64[3815] = *((uint64_t*)&dataset[hash_32[7623]]);
	hash_64[3816] = *((uint64_t*)&dataset[hash_32[7624]]);
	hash_64[3817] = *((uint64_t*)&dataset[hash_32[7625]]);
	hash_64[3818] = *((uint64_t*)&dataset[hash_32[7626]]);
	hash_64[3819] = *((uint64_t*)&dataset[hash_32[7627]]);
	hash_64[3820] = *((uint64_t*)&dataset[hash_32[7628]]);
	hash_64[3821] = *((uint64_t*)&dataset[hash_32[7629]]);
	hash_64[3822] = *((uint64_t*)&dataset[hash_32[7630]]);
	hash_64[3823] = *((uint64_t*)&dataset[hash_32[7631]]);
#endif
#if MEMORY_THREADS > 239
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3824] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3825] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3826] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3827] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3828] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3829] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3830] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3831] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3824] = *((uint64_t*)&dataset[hash_32[7648]]);
	hash_64[3825] = *((uint64_t*)&dataset[hash_32[7649]]);
	hash_64[3826] = *((uint64_t*)&dataset[hash_32[7650]]);
	hash_64[3827] = *((uint64_t*)&dataset[hash_32[7651]]);
	hash_64[3828] = *((uint64_t*)&dataset[hash_32[7652]]);
	hash_64[3829] = *((uint64_t*)&dataset[hash_32[7653]]);
	hash_64[3830] = *((uint64_t*)&dataset[hash_32[7654]]);
	hash_64[3831] = *((uint64_t*)&dataset[hash_32[7655]]);
	hash_64[3832] = *((uint64_t*)&dataset[hash_32[7656]]);
	hash_64[3833] = *((uint64_t*)&dataset[hash_32[7657]]);
	hash_64[3834] = *((uint64_t*)&dataset[hash_32[7658]]);
	hash_64[3835] = *((uint64_t*)&dataset[hash_32[7659]]);
	hash_64[3836] = *((uint64_t*)&dataset[hash_32[7660]]);
	hash_64[3837] = *((uint64_t*)&dataset[hash_32[7661]]);
	hash_64[3838] = *((uint64_t*)&dataset[hash_32[7662]]);
	hash_64[3839] = *((uint64_t*)&dataset[hash_32[7663]]);
#endif
#if MEMORY_THREADS > 240
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3840] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3841] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3842] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3843] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3844] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3845] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3846] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3847] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3840] = *((uint64_t*)&dataset[hash_32[7680]]);
	hash_64[3841] = *((uint64_t*)&dataset[hash_32[7681]]);
	hash_64[3842] = *((uint64_t*)&dataset[hash_32[7682]]);
	hash_64[3843] = *((uint64_t*)&dataset[hash_32[7683]]);
	hash_64[3844] = *((uint64_t*)&dataset[hash_32[7684]]);
	hash_64[3845] = *((uint64_t*)&dataset[hash_32[7685]]);
	hash_64[3846] = *((uint64_t*)&dataset[hash_32[7686]]);
	hash_64[3847] = *((uint64_t*)&dataset[hash_32[7687]]);
	hash_64[3848] = *((uint64_t*)&dataset[hash_32[7688]]);
	hash_64[3849] = *((uint64_t*)&dataset[hash_32[7689]]);
	hash_64[3850] = *((uint64_t*)&dataset[hash_32[7690]]);
	hash_64[3851] = *((uint64_t*)&dataset[hash_32[7691]]);
	hash_64[3852] = *((uint64_t*)&dataset[hash_32[7692]]);
	hash_64[3853] = *((uint64_t*)&dataset[hash_32[7693]]);
	hash_64[3854] = *((uint64_t*)&dataset[hash_32[7694]]);
	hash_64[3855] = *((uint64_t*)&dataset[hash_32[7695]]);
#endif
#if MEMORY_THREADS > 241
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3856] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3857] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3858] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3859] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3860] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3861] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3862] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3863] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3856] = *((uint64_t*)&dataset[hash_32[7712]]);
	hash_64[3857] = *((uint64_t*)&dataset[hash_32[7713]]);
	hash_64[3858] = *((uint64_t*)&dataset[hash_32[7714]]);
	hash_64[3859] = *((uint64_t*)&dataset[hash_32[7715]]);
	hash_64[3860] = *((uint64_t*)&dataset[hash_32[7716]]);
	hash_64[3861] = *((uint64_t*)&dataset[hash_32[7717]]);
	hash_64[3862] = *((uint64_t*)&dataset[hash_32[7718]]);
	hash_64[3863] = *((uint64_t*)&dataset[hash_32[7719]]);
	hash_64[3864] = *((uint64_t*)&dataset[hash_32[7720]]);
	hash_64[3865] = *((uint64_t*)&dataset[hash_32[7721]]);
	hash_64[3866] = *((uint64_t*)&dataset[hash_32[7722]]);
	hash_64[3867] = *((uint64_t*)&dataset[hash_32[7723]]);
	hash_64[3868] = *((uint64_t*)&dataset[hash_32[7724]]);
	hash_64[3869] = *((uint64_t*)&dataset[hash_32[7725]]);
	hash_64[3870] = *((uint64_t*)&dataset[hash_32[7726]]);
	hash_64[3871] = *((uint64_t*)&dataset[hash_32[7727]]);
#endif
#if MEMORY_THREADS > 242
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3872] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3873] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3874] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3875] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3876] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3877] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3878] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3879] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3872] = *((uint64_t*)&dataset[hash_32[7744]]);
	hash_64[3873] = *((uint64_t*)&dataset[hash_32[7745]]);
	hash_64[3874] = *((uint64_t*)&dataset[hash_32[7746]]);
	hash_64[3875] = *((uint64_t*)&dataset[hash_32[7747]]);
	hash_64[3876] = *((uint64_t*)&dataset[hash_32[7748]]);
	hash_64[3877] = *((uint64_t*)&dataset[hash_32[7749]]);
	hash_64[3878] = *((uint64_t*)&dataset[hash_32[7750]]);
	hash_64[3879] = *((uint64_t*)&dataset[hash_32[7751]]);
	hash_64[3880] = *((uint64_t*)&dataset[hash_32[7752]]);
	hash_64[3881] = *((uint64_t*)&dataset[hash_32[7753]]);
	hash_64[3882] = *((uint64_t*)&dataset[hash_32[7754]]);
	hash_64[3883] = *((uint64_t*)&dataset[hash_32[7755]]);
	hash_64[3884] = *((uint64_t*)&dataset[hash_32[7756]]);
	hash_64[3885] = *((uint64_t*)&dataset[hash_32[7757]]);
	hash_64[3886] = *((uint64_t*)&dataset[hash_32[7758]]);
	hash_64[3887] = *((uint64_t*)&dataset[hash_32[7759]]);
#endif
#if MEMORY_THREADS > 243
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3888] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3889] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3890] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3891] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3892] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3893] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3894] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3895] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3888] = *((uint64_t*)&dataset[hash_32[7776]]);
	hash_64[3889] = *((uint64_t*)&dataset[hash_32[7777]]);
	hash_64[3890] = *((uint64_t*)&dataset[hash_32[7778]]);
	hash_64[3891] = *((uint64_t*)&dataset[hash_32[7779]]);
	hash_64[3892] = *((uint64_t*)&dataset[hash_32[7780]]);
	hash_64[3893] = *((uint64_t*)&dataset[hash_32[7781]]);
	hash_64[3894] = *((uint64_t*)&dataset[hash_32[7782]]);
	hash_64[3895] = *((uint64_t*)&dataset[hash_32[7783]]);
	hash_64[3896] = *((uint64_t*)&dataset[hash_32[7784]]);
	hash_64[3897] = *((uint64_t*)&dataset[hash_32[7785]]);
	hash_64[3898] = *((uint64_t*)&dataset[hash_32[7786]]);
	hash_64[3899] = *((uint64_t*)&dataset[hash_32[7787]]);
	hash_64[3900] = *((uint64_t*)&dataset[hash_32[7788]]);
	hash_64[3901] = *((uint64_t*)&dataset[hash_32[7789]]);
	hash_64[3902] = *((uint64_t*)&dataset[hash_32[7790]]);
	hash_64[3903] = *((uint64_t*)&dataset[hash_32[7791]]);
#endif
#if MEMORY_THREADS > 244
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3904] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3905] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3906] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3907] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3908] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3909] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3910] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3911] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3904] = *((uint64_t*)&dataset[hash_32[7808]]);
	hash_64[3905] = *((uint64_t*)&dataset[hash_32[7809]]);
	hash_64[3906] = *((uint64_t*)&dataset[hash_32[7810]]);
	hash_64[3907] = *((uint64_t*)&dataset[hash_32[7811]]);
	hash_64[3908] = *((uint64_t*)&dataset[hash_32[7812]]);
	hash_64[3909] = *((uint64_t*)&dataset[hash_32[7813]]);
	hash_64[3910] = *((uint64_t*)&dataset[hash_32[7814]]);
	hash_64[3911] = *((uint64_t*)&dataset[hash_32[7815]]);
	hash_64[3912] = *((uint64_t*)&dataset[hash_32[7816]]);
	hash_64[3913] = *((uint64_t*)&dataset[hash_32[7817]]);
	hash_64[3914] = *((uint64_t*)&dataset[hash_32[7818]]);
	hash_64[3915] = *((uint64_t*)&dataset[hash_32[7819]]);
	hash_64[3916] = *((uint64_t*)&dataset[hash_32[7820]]);
	hash_64[3917] = *((uint64_t*)&dataset[hash_32[7821]]);
	hash_64[3918] = *((uint64_t*)&dataset[hash_32[7822]]);
	hash_64[3919] = *((uint64_t*)&dataset[hash_32[7823]]);
#endif
#if MEMORY_THREADS > 245
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3920] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3921] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3922] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3923] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3924] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3925] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3926] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3927] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3920] = *((uint64_t*)&dataset[hash_32[7840]]);
	hash_64[3921] = *((uint64_t*)&dataset[hash_32[7841]]);
	hash_64[3922] = *((uint64_t*)&dataset[hash_32[7842]]);
	hash_64[3923] = *((uint64_t*)&dataset[hash_32[7843]]);
	hash_64[3924] = *((uint64_t*)&dataset[hash_32[7844]]);
	hash_64[3925] = *((uint64_t*)&dataset[hash_32[7845]]);
	hash_64[3926] = *((uint64_t*)&dataset[hash_32[7846]]);
	hash_64[3927] = *((uint64_t*)&dataset[hash_32[7847]]);
	hash_64[3928] = *((uint64_t*)&dataset[hash_32[7848]]);
	hash_64[3929] = *((uint64_t*)&dataset[hash_32[7849]]);
	hash_64[3930] = *((uint64_t*)&dataset[hash_32[7850]]);
	hash_64[3931] = *((uint64_t*)&dataset[hash_32[7851]]);
	hash_64[3932] = *((uint64_t*)&dataset[hash_32[7852]]);
	hash_64[3933] = *((uint64_t*)&dataset[hash_32[7853]]);
	hash_64[3934] = *((uint64_t*)&dataset[hash_32[7854]]);
	hash_64[3935] = *((uint64_t*)&dataset[hash_32[7855]]);
#endif
#if MEMORY_THREADS > 246
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3936] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3937] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3938] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3939] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3940] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3941] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3942] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3943] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3936] = *((uint64_t*)&dataset[hash_32[7872]]);
	hash_64[3937] = *((uint64_t*)&dataset[hash_32[7873]]);
	hash_64[3938] = *((uint64_t*)&dataset[hash_32[7874]]);
	hash_64[3939] = *((uint64_t*)&dataset[hash_32[7875]]);
	hash_64[3940] = *((uint64_t*)&dataset[hash_32[7876]]);
	hash_64[3941] = *((uint64_t*)&dataset[hash_32[7877]]);
	hash_64[3942] = *((uint64_t*)&dataset[hash_32[7878]]);
	hash_64[3943] = *((uint64_t*)&dataset[hash_32[7879]]);
	hash_64[3944] = *((uint64_t*)&dataset[hash_32[7880]]);
	hash_64[3945] = *((uint64_t*)&dataset[hash_32[7881]]);
	hash_64[3946] = *((uint64_t*)&dataset[hash_32[7882]]);
	hash_64[3947] = *((uint64_t*)&dataset[hash_32[7883]]);
	hash_64[3948] = *((uint64_t*)&dataset[hash_32[7884]]);
	hash_64[3949] = *((uint64_t*)&dataset[hash_32[7885]]);
	hash_64[3950] = *((uint64_t*)&dataset[hash_32[7886]]);
	hash_64[3951] = *((uint64_t*)&dataset[hash_32[7887]]);
#endif
#if MEMORY_THREADS > 247
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3952] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3953] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3954] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3955] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3956] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3957] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3958] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3959] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3952] = *((uint64_t*)&dataset[hash_32[7904]]);
	hash_64[3953] = *((uint64_t*)&dataset[hash_32[7905]]);
	hash_64[3954] = *((uint64_t*)&dataset[hash_32[7906]]);
	hash_64[3955] = *((uint64_t*)&dataset[hash_32[7907]]);
	hash_64[3956] = *((uint64_t*)&dataset[hash_32[7908]]);
	hash_64[3957] = *((uint64_t*)&dataset[hash_32[7909]]);
	hash_64[3958] = *((uint64_t*)&dataset[hash_32[7910]]);
	hash_64[3959] = *((uint64_t*)&dataset[hash_32[7911]]);
	hash_64[3960] = *((uint64_t*)&dataset[hash_32[7912]]);
	hash_64[3961] = *((uint64_t*)&dataset[hash_32[7913]]);
	hash_64[3962] = *((uint64_t*)&dataset[hash_32[7914]]);
	hash_64[3963] = *((uint64_t*)&dataset[hash_32[7915]]);
	hash_64[3964] = *((uint64_t*)&dataset[hash_32[7916]]);
	hash_64[3965] = *((uint64_t*)&dataset[hash_32[7917]]);
	hash_64[3966] = *((uint64_t*)&dataset[hash_32[7918]]);
	hash_64[3967] = *((uint64_t*)&dataset[hash_32[7919]]);
#endif
#if MEMORY_THREADS > 248
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3968] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3969] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3970] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3971] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3972] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3973] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3974] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3975] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3968] = *((uint64_t*)&dataset[hash_32[7936]]);
	hash_64[3969] = *((uint64_t*)&dataset[hash_32[7937]]);
	hash_64[3970] = *((uint64_t*)&dataset[hash_32[7938]]);
	hash_64[3971] = *((uint64_t*)&dataset[hash_32[7939]]);
	hash_64[3972] = *((uint64_t*)&dataset[hash_32[7940]]);
	hash_64[3973] = *((uint64_t*)&dataset[hash_32[7941]]);
	hash_64[3974] = *((uint64_t*)&dataset[hash_32[7942]]);
	hash_64[3975] = *((uint64_t*)&dataset[hash_32[7943]]);
	hash_64[3976] = *((uint64_t*)&dataset[hash_32[7944]]);
	hash_64[3977] = *((uint64_t*)&dataset[hash_32[7945]]);
	hash_64[3978] = *((uint64_t*)&dataset[hash_32[7946]]);
	hash_64[3979] = *((uint64_t*)&dataset[hash_32[7947]]);
	hash_64[3980] = *((uint64_t*)&dataset[hash_32[7948]]);
	hash_64[3981] = *((uint64_t*)&dataset[hash_32[7949]]);
	hash_64[3982] = *((uint64_t*)&dataset[hash_32[7950]]);
	hash_64[3983] = *((uint64_t*)&dataset[hash_32[7951]]);
#endif
#if MEMORY_THREADS > 249
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[3984] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[3985] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[3986] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[3987] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[3988] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[3989] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[3990] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[3991] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[3984] = *((uint64_t*)&dataset[hash_32[7968]]);
	hash_64[3985] = *((uint64_t*)&dataset[hash_32[7969]]);
	hash_64[3986] = *((uint64_t*)&dataset[hash_32[7970]]);
	hash_64[3987] = *((uint64_t*)&dataset[hash_32[7971]]);
	hash_64[3988] = *((uint64_t*)&dataset[hash_32[7972]]);
	hash_64[3989] = *((uint64_t*)&dataset[hash_32[7973]]);
	hash_64[3990] = *((uint64_t*)&dataset[hash_32[7974]]);
	hash_64[3991] = *((uint64_t*)&dataset[hash_32[7975]]);
	hash_64[3992] = *((uint64_t*)&dataset[hash_32[7976]]);
	hash_64[3993] = *((uint64_t*)&dataset[hash_32[7977]]);
	hash_64[3994] = *((uint64_t*)&dataset[hash_32[7978]]);
	hash_64[3995] = *((uint64_t*)&dataset[hash_32[7979]]);
	hash_64[3996] = *((uint64_t*)&dataset[hash_32[7980]]);
	hash_64[3997] = *((uint64_t*)&dataset[hash_32[7981]]);
	hash_64[3998] = *((uint64_t*)&dataset[hash_32[7982]]);
	hash_64[3999] = *((uint64_t*)&dataset[hash_32[7983]]);
#endif
#if MEMORY_THREADS > 250
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[4000] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[4001] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[4002] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[4003] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[4004] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[4005] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[4006] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[4007] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[4000] = *((uint64_t*)&dataset[hash_32[8000]]);
	hash_64[4001] = *((uint64_t*)&dataset[hash_32[8001]]);
	hash_64[4002] = *((uint64_t*)&dataset[hash_32[8002]]);
	hash_64[4003] = *((uint64_t*)&dataset[hash_32[8003]]);
	hash_64[4004] = *((uint64_t*)&dataset[hash_32[8004]]);
	hash_64[4005] = *((uint64_t*)&dataset[hash_32[8005]]);
	hash_64[4006] = *((uint64_t*)&dataset[hash_32[8006]]);
	hash_64[4007] = *((uint64_t*)&dataset[hash_32[8007]]);
	hash_64[4008] = *((uint64_t*)&dataset[hash_32[8008]]);
	hash_64[4009] = *((uint64_t*)&dataset[hash_32[8009]]);
	hash_64[4010] = *((uint64_t*)&dataset[hash_32[8010]]);
	hash_64[4011] = *((uint64_t*)&dataset[hash_32[8011]]);
	hash_64[4012] = *((uint64_t*)&dataset[hash_32[8012]]);
	hash_64[4013] = *((uint64_t*)&dataset[hash_32[8013]]);
	hash_64[4014] = *((uint64_t*)&dataset[hash_32[8014]]);
	hash_64[4015] = *((uint64_t*)&dataset[hash_32[8015]]);
#endif
#if MEMORY_THREADS > 251
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[4016] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[4017] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[4018] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[4019] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[4020] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[4021] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[4022] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[4023] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[4016] = *((uint64_t*)&dataset[hash_32[8032]]);
	hash_64[4017] = *((uint64_t*)&dataset[hash_32[8033]]);
	hash_64[4018] = *((uint64_t*)&dataset[hash_32[8034]]);
	hash_64[4019] = *((uint64_t*)&dataset[hash_32[8035]]);
	hash_64[4020] = *((uint64_t*)&dataset[hash_32[8036]]);
	hash_64[4021] = *((uint64_t*)&dataset[hash_32[8037]]);
	hash_64[4022] = *((uint64_t*)&dataset[hash_32[8038]]);
	hash_64[4023] = *((uint64_t*)&dataset[hash_32[8039]]);
	hash_64[4024] = *((uint64_t*)&dataset[hash_32[8040]]);
	hash_64[4025] = *((uint64_t*)&dataset[hash_32[8041]]);
	hash_64[4026] = *((uint64_t*)&dataset[hash_32[8042]]);
	hash_64[4027] = *((uint64_t*)&dataset[hash_32[8043]]);
	hash_64[4028] = *((uint64_t*)&dataset[hash_32[8044]]);
	hash_64[4029] = *((uint64_t*)&dataset[hash_32[8045]]);
	hash_64[4030] = *((uint64_t*)&dataset[hash_32[8046]]);
	hash_64[4031] = *((uint64_t*)&dataset[hash_32[8047]]);
#endif
#if MEMORY_THREADS > 252
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[4032] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[4033] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[4034] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[4035] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[4036] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[4037] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[4038] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[4039] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[4032] = *((uint64_t*)&dataset[hash_32[8064]]);
	hash_64[4033] = *((uint64_t*)&dataset[hash_32[8065]]);
	hash_64[4034] = *((uint64_t*)&dataset[hash_32[8066]]);
	hash_64[4035] = *((uint64_t*)&dataset[hash_32[8067]]);
	hash_64[4036] = *((uint64_t*)&dataset[hash_32[8068]]);
	hash_64[4037] = *((uint64_t*)&dataset[hash_32[8069]]);
	hash_64[4038] = *((uint64_t*)&dataset[hash_32[8070]]);
	hash_64[4039] = *((uint64_t*)&dataset[hash_32[8071]]);
	hash_64[4040] = *((uint64_t*)&dataset[hash_32[8072]]);
	hash_64[4041] = *((uint64_t*)&dataset[hash_32[8073]]);
	hash_64[4042] = *((uint64_t*)&dataset[hash_32[8074]]);
	hash_64[4043] = *((uint64_t*)&dataset[hash_32[8075]]);
	hash_64[4044] = *((uint64_t*)&dataset[hash_32[8076]]);
	hash_64[4045] = *((uint64_t*)&dataset[hash_32[8077]]);
	hash_64[4046] = *((uint64_t*)&dataset[hash_32[8078]]);
	hash_64[4047] = *((uint64_t*)&dataset[hash_32[8079]]);
#endif
#if MEMORY_THREADS > 253
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[4048] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[4049] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[4050] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[4051] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[4052] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[4053] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[4054] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[4055] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[4048] = *((uint64_t*)&dataset[hash_32[8096]]);
	hash_64[4049] = *((uint64_t*)&dataset[hash_32[8097]]);
	hash_64[4050] = *((uint64_t*)&dataset[hash_32[8098]]);
	hash_64[4051] = *((uint64_t*)&dataset[hash_32[8099]]);
	hash_64[4052] = *((uint64_t*)&dataset[hash_32[8100]]);
	hash_64[4053] = *((uint64_t*)&dataset[hash_32[8101]]);
	hash_64[4054] = *((uint64_t*)&dataset[hash_32[8102]]);
	hash_64[4055] = *((uint64_t*)&dataset[hash_32[8103]]);
	hash_64[4056] = *((uint64_t*)&dataset[hash_32[8104]]);
	hash_64[4057] = *((uint64_t*)&dataset[hash_32[8105]]);
	hash_64[4058] = *((uint64_t*)&dataset[hash_32[8106]]);
	hash_64[4059] = *((uint64_t*)&dataset[hash_32[8107]]);
	hash_64[4060] = *((uint64_t*)&dataset[hash_32[8108]]);
	hash_64[4061] = *((uint64_t*)&dataset[hash_32[8109]]);
	hash_64[4062] = *((uint64_t*)&dataset[hash_32[8110]]);
	hash_64[4063] = *((uint64_t*)&dataset[hash_32[8111]]);
#endif
#if MEMORY_THREADS > 254
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[4064] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[4065] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[4066] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[4067] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[4068] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[4069] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[4070] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[4071] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[4064] = *((uint64_t*)&dataset[hash_32[8128]]);
	hash_64[4065] = *((uint64_t*)&dataset[hash_32[8129]]);
	hash_64[4066] = *((uint64_t*)&dataset[hash_32[8130]]);
	hash_64[4067] = *((uint64_t*)&dataset[hash_32[8131]]);
	hash_64[4068] = *((uint64_t*)&dataset[hash_32[8132]]);
	hash_64[4069] = *((uint64_t*)&dataset[hash_32[8133]]);
	hash_64[4070] = *((uint64_t*)&dataset[hash_32[8134]]);
	hash_64[4071] = *((uint64_t*)&dataset[hash_32[8135]]);
	hash_64[4072] = *((uint64_t*)&dataset[hash_32[8136]]);
	hash_64[4073] = *((uint64_t*)&dataset[hash_32[8137]]);
	hash_64[4074] = *((uint64_t*)&dataset[hash_32[8138]]);
	hash_64[4075] = *((uint64_t*)&dataset[hash_32[8139]]);
	hash_64[4076] = *((uint64_t*)&dataset[hash_32[8140]]);
	hash_64[4077] = *((uint64_t*)&dataset[hash_32[8141]]);
	hash_64[4078] = *((uint64_t*)&dataset[hash_32[8142]]);
	hash_64[4079] = *((uint64_t*)&dataset[hash_32[8143]]);
#endif
#if MEMORY_THREADS > 255
	data_32[ 1]++; data_32[ 3]++; data_32[ 5]++; data_32[ 7]++;
	hash_64[4080] = *((uint64_t*)&dataset[*data_32   ]);
	hash_64[4081] = *((uint64_t*)&dataset[data_32[ 1]]);
	hash_64[4082] = *((uint64_t*)&dataset[data_32[ 2]]);
	hash_64[4083] = *((uint64_t*)&dataset[data_32[ 3]]);
	hash_64[4084] = *((uint64_t*)&dataset[data_32[ 4]]);
	hash_64[4085] = *((uint64_t*)&dataset[data_32[ 5]]);
	hash_64[4086] = *((uint64_t*)&dataset[data_32[ 6]]);
	hash_64[4087] = *((uint64_t*)&dataset[data_32[ 7]]);
	hash_64[4080] = *((uint64_t*)&dataset[hash_32[8160]]);
	hash_64[4081] = *((uint64_t*)&dataset[hash_32[8161]]);
	hash_64[4082] = *((uint64_t*)&dataset[hash_32[8162]]);
	hash_64[4083] = *((uint64_t*)&dataset[hash_32[8163]]);
	hash_64[4084] = *((uint64_t*)&dataset[hash_32[8164]]);
	hash_64[4085] = *((uint64_t*)&dataset[hash_32[8165]]);
	hash_64[4086] = *((uint64_t*)&dataset[hash_32[8166]]);
	hash_64[4087] = *((uint64_t*)&dataset[hash_32[8167]]);
	hash_64[4088] = *((uint64_t*)&dataset[hash_32[8168]]);
	hash_64[4089] = *((uint64_t*)&dataset[hash_32[8169]]);
	hash_64[4090] = *((uint64_t*)&dataset[hash_32[8170]]);
	hash_64[4091] = *((uint64_t*)&dataset[hash_32[8171]]);
	hash_64[4092] = *((uint64_t*)&dataset[hash_32[8172]]);
	hash_64[4093] = *((uint64_t*)&dataset[hash_32[8173]]);
	hash_64[4094] = *((uint64_t*)&dataset[hash_32[8174]]);
	hash_64[4095] = *((uint64_t*)&dataset[hash_32[8175]]);
#endif
#ifdef ACCESS_ROUNDS
	}
#endif
	hash_64[ 0] += hash_64[ 1]; hash_64[ 2] += hash_64[ 3];
	hash_64[ 4] += hash_64[ 5]; hash_64[ 6] += hash_64[ 7];
	hash_64[ 8] += hash_64[ 9]; hash_64[10] += hash_64[11];
	hash_64[12] += hash_64[13]; hash_64[14] += hash_64[15];
	hash_64[ 0] += hash_64[ 2]; hash_64[ 4] += hash_64[ 6];
	hash_64[ 8] += hash_64[10]; hash_64[12] += hash_64[14];
#if MEMORY_THREADS > 1
	hash_64[16] += hash_64[17]; hash_64[18] += hash_64[19];
	hash_64[20] += hash_64[21]; hash_64[22] += hash_64[23];
	hash_64[24] += hash_64[25]; hash_64[26] += hash_64[27];
	hash_64[28] += hash_64[29]; hash_64[30] += hash_64[31];
	hash_64[16] += hash_64[18]; hash_64[20] += hash_64[22];
	hash_64[24] += hash_64[26]; hash_64[28] += hash_64[30];
#endif
#if MEMORY_THREADS > 2
	hash_64[32] += hash_64[33]; hash_64[34] += hash_64[35];
	hash_64[36] += hash_64[37]; hash_64[38] += hash_64[39];
	hash_64[40] += hash_64[41]; hash_64[42] += hash_64[43];
	hash_64[44] += hash_64[45]; hash_64[46] += hash_64[47];
	hash_64[32] += hash_64[34]; hash_64[36] += hash_64[38];
	hash_64[40] += hash_64[42]; hash_64[44] += hash_64[46];
#endif
#if MEMORY_THREADS > 3
	hash_64[48] += hash_64[49]; hash_64[50] += hash_64[51];
	hash_64[52] += hash_64[53]; hash_64[54] += hash_64[55];
	hash_64[56] += hash_64[57]; hash_64[58] += hash_64[59];
	hash_64[60] += hash_64[61]; hash_64[62] += hash_64[63];
	hash_64[48] += hash_64[50]; hash_64[52] += hash_64[54];
	hash_64[56] += hash_64[58]; hash_64[60] += hash_64[62];
#endif
#if MEMORY_THREADS > 4
	hash_64[64] += hash_64[65]; hash_64[66] += hash_64[67];
	hash_64[68] += hash_64[69]; hash_64[70] += hash_64[71];
	hash_64[72] += hash_64[73]; hash_64[74] += hash_64[75];
	hash_64[76] += hash_64[77]; hash_64[78] += hash_64[79];
	hash_64[64] += hash_64[66]; hash_64[68] += hash_64[70];
	hash_64[72] += hash_64[74]; hash_64[76] += hash_64[78];
#endif
#if MEMORY_THREADS > 5
	hash_64[80] += hash_64[81]; hash_64[82] += hash_64[83];
	hash_64[84] += hash_64[85]; hash_64[86] += hash_64[87];
	hash_64[88] += hash_64[89]; hash_64[90] += hash_64[91];
	hash_64[92] += hash_64[93]; hash_64[94] += hash_64[95];
	hash_64[80] += hash_64[82]; hash_64[84] += hash_64[86];
	hash_64[88] += hash_64[90]; hash_64[92] += hash_64[94];
#endif
#if MEMORY_THREADS > 6
	hash_64[96] += hash_64[97]; hash_64[98] += hash_64[99];
	hash_64[100] += hash_64[101]; hash_64[102] += hash_64[103];
	hash_64[104] += hash_64[105]; hash_64[106] += hash_64[107];
	hash_64[108] += hash_64[109]; hash_64[110] += hash_64[111];
	hash_64[96] += hash_64[98]; hash_64[100] += hash_64[102];
	hash_64[104] += hash_64[106]; hash_64[108] += hash_64[110];
#endif
#if MEMORY_THREADS > 7
	hash_64[112] += hash_64[113]; hash_64[114] += hash_64[115];
	hash_64[116] += hash_64[117]; hash_64[118] += hash_64[119];
	hash_64[120] += hash_64[121]; hash_64[122] += hash_64[123];
	hash_64[124] += hash_64[125]; hash_64[126] += hash_64[127];
	hash_64[112] += hash_64[114]; hash_64[116] += hash_64[118];
	hash_64[120] += hash_64[122]; hash_64[124] += hash_64[126];
#endif
#if MEMORY_THREADS > 8
	hash_64[128] += hash_64[129]; hash_64[130] += hash_64[131];
	hash_64[132] += hash_64[133]; hash_64[134] += hash_64[135];
	hash_64[136] += hash_64[137]; hash_64[138] += hash_64[139];
	hash_64[140] += hash_64[141]; hash_64[142] += hash_64[143];
	hash_64[128] += hash_64[130]; hash_64[132] += hash_64[134];
	hash_64[136] += hash_64[138]; hash_64[140] += hash_64[142];
#endif
#if MEMORY_THREADS > 9
	hash_64[144] += hash_64[145]; hash_64[146] += hash_64[147];
	hash_64[148] += hash_64[149]; hash_64[150] += hash_64[151];
	hash_64[152] += hash_64[153]; hash_64[154] += hash_64[155];
	hash_64[156] += hash_64[157]; hash_64[158] += hash_64[159];
	hash_64[144] += hash_64[146]; hash_64[148] += hash_64[150];
	hash_64[152] += hash_64[154]; hash_64[156] += hash_64[158];
#endif
#if MEMORY_THREADS > 10
	hash_64[160] += hash_64[161]; hash_64[162] += hash_64[163];
	hash_64[164] += hash_64[165]; hash_64[166] += hash_64[167];
	hash_64[168] += hash_64[169]; hash_64[170] += hash_64[171];
	hash_64[172] += hash_64[173]; hash_64[174] += hash_64[175];
	hash_64[160] += hash_64[162]; hash_64[164] += hash_64[166];
	hash_64[168] += hash_64[170]; hash_64[172] += hash_64[174];
#endif
#if MEMORY_THREADS > 11
	hash_64[176] += hash_64[177]; hash_64[178] += hash_64[179];
	hash_64[180] += hash_64[181]; hash_64[182] += hash_64[183];
	hash_64[184] += hash_64[185]; hash_64[186] += hash_64[187];
	hash_64[188] += hash_64[189]; hash_64[190] += hash_64[191];
	hash_64[176] += hash_64[178]; hash_64[180] += hash_64[182];
	hash_64[184] += hash_64[186]; hash_64[188] += hash_64[190];
#endif
#if MEMORY_THREADS > 12
	hash_64[192] += hash_64[193]; hash_64[194] += hash_64[195];
	hash_64[196] += hash_64[197]; hash_64[198] += hash_64[199];
	hash_64[200] += hash_64[201]; hash_64[202] += hash_64[203];
	hash_64[204] += hash_64[205]; hash_64[206] += hash_64[207];
	hash_64[192] += hash_64[194]; hash_64[196] += hash_64[198];
	hash_64[200] += hash_64[202]; hash_64[204] += hash_64[206];
#endif
#if MEMORY_THREADS > 13
	hash_64[208] += hash_64[209]; hash_64[210] += hash_64[211];
	hash_64[212] += hash_64[213]; hash_64[214] += hash_64[215];
	hash_64[216] += hash_64[217]; hash_64[218] += hash_64[219];
	hash_64[220] += hash_64[221]; hash_64[222] += hash_64[223];
	hash_64[208] += hash_64[210]; hash_64[212] += hash_64[214];
	hash_64[216] += hash_64[218]; hash_64[220] += hash_64[222];
#endif
#if MEMORY_THREADS > 14
	hash_64[224] += hash_64[225]; hash_64[226] += hash_64[227];
	hash_64[228] += hash_64[229]; hash_64[230] += hash_64[231];
	hash_64[232] += hash_64[233]; hash_64[234] += hash_64[235];
	hash_64[236] += hash_64[237]; hash_64[238] += hash_64[239];
	hash_64[224] += hash_64[226]; hash_64[228] += hash_64[230];
	hash_64[232] += hash_64[234]; hash_64[236] += hash_64[238];
#endif
#if MEMORY_THREADS > 15
	hash_64[240] += hash_64[241]; hash_64[242] += hash_64[243];
	hash_64[244] += hash_64[245]; hash_64[246] += hash_64[247];
	hash_64[248] += hash_64[249]; hash_64[250] += hash_64[251];
	hash_64[252] += hash_64[253]; hash_64[254] += hash_64[255];
	hash_64[240] += hash_64[242]; hash_64[244] += hash_64[246];
	hash_64[248] += hash_64[250]; hash_64[252] += hash_64[254];
#endif
#if MEMORY_THREADS > 16
	hash_64[256] += hash_64[257]; hash_64[258] += hash_64[259];
	hash_64[260] += hash_64[261]; hash_64[262] += hash_64[263];
	hash_64[264] += hash_64[265]; hash_64[266] += hash_64[267];
	hash_64[268] += hash_64[269]; hash_64[270] += hash_64[271];
	hash_64[256] += hash_64[258]; hash_64[260] += hash_64[262];
	hash_64[264] += hash_64[266]; hash_64[268] += hash_64[270];
#endif
#if MEMORY_THREADS > 17
	hash_64[272] += hash_64[273]; hash_64[274] += hash_64[275];
	hash_64[276] += hash_64[277]; hash_64[278] += hash_64[279];
	hash_64[280] += hash_64[281]; hash_64[282] += hash_64[283];
	hash_64[284] += hash_64[285]; hash_64[286] += hash_64[287];
	hash_64[272] += hash_64[274]; hash_64[276] += hash_64[278];
	hash_64[280] += hash_64[282]; hash_64[284] += hash_64[286];
#endif
#if MEMORY_THREADS > 18
	hash_64[288] += hash_64[289]; hash_64[290] += hash_64[291];
	hash_64[292] += hash_64[293]; hash_64[294] += hash_64[295];
	hash_64[296] += hash_64[297]; hash_64[298] += hash_64[299];
	hash_64[300] += hash_64[301]; hash_64[302] += hash_64[303];
	hash_64[288] += hash_64[290]; hash_64[292] += hash_64[294];
	hash_64[296] += hash_64[298]; hash_64[300] += hash_64[302];
#endif
#if MEMORY_THREADS > 19
	hash_64[304] += hash_64[305]; hash_64[306] += hash_64[307];
	hash_64[308] += hash_64[309]; hash_64[310] += hash_64[311];
	hash_64[312] += hash_64[313]; hash_64[314] += hash_64[315];
	hash_64[316] += hash_64[317]; hash_64[318] += hash_64[319];
	hash_64[304] += hash_64[306]; hash_64[308] += hash_64[310];
	hash_64[312] += hash_64[314]; hash_64[316] += hash_64[318];
#endif
#if MEMORY_THREADS > 20
	hash_64[320] += hash_64[321]; hash_64[322] += hash_64[323];
	hash_64[324] += hash_64[325]; hash_64[326] += hash_64[327];
	hash_64[328] += hash_64[329]; hash_64[330] += hash_64[331];
	hash_64[332] += hash_64[333]; hash_64[334] += hash_64[335];
	hash_64[320] += hash_64[322]; hash_64[324] += hash_64[326];
	hash_64[328] += hash_64[330]; hash_64[332] += hash_64[334];
#endif
#if MEMORY_THREADS > 21
	hash_64[336] += hash_64[337]; hash_64[338] += hash_64[339];
	hash_64[340] += hash_64[341]; hash_64[342] += hash_64[343];
	hash_64[344] += hash_64[345]; hash_64[346] += hash_64[347];
	hash_64[348] += hash_64[349]; hash_64[350] += hash_64[351];
	hash_64[336] += hash_64[338]; hash_64[340] += hash_64[342];
	hash_64[344] += hash_64[346]; hash_64[348] += hash_64[350];
#endif
#if MEMORY_THREADS > 22
	hash_64[352] += hash_64[353]; hash_64[354] += hash_64[355];
	hash_64[356] += hash_64[357]; hash_64[358] += hash_64[359];
	hash_64[360] += hash_64[361]; hash_64[362] += hash_64[363];
	hash_64[364] += hash_64[365]; hash_64[366] += hash_64[367];
	hash_64[352] += hash_64[354]; hash_64[356] += hash_64[358];
	hash_64[360] += hash_64[362]; hash_64[364] += hash_64[366];
#endif
#if MEMORY_THREADS > 23
	hash_64[368] += hash_64[369]; hash_64[370] += hash_64[371];
	hash_64[372] += hash_64[373]; hash_64[374] += hash_64[375];
	hash_64[376] += hash_64[377]; hash_64[378] += hash_64[379];
	hash_64[380] += hash_64[381]; hash_64[382] += hash_64[383];
	hash_64[368] += hash_64[370]; hash_64[372] += hash_64[374];
	hash_64[376] += hash_64[378]; hash_64[380] += hash_64[382];
#endif
#if MEMORY_THREADS > 24
	hash_64[384] += hash_64[385]; hash_64[386] += hash_64[387];
	hash_64[388] += hash_64[389]; hash_64[390] += hash_64[391];
	hash_64[392] += hash_64[393]; hash_64[394] += hash_64[395];
	hash_64[396] += hash_64[397]; hash_64[398] += hash_64[399];
	hash_64[384] += hash_64[386]; hash_64[388] += hash_64[390];
	hash_64[392] += hash_64[394]; hash_64[396] += hash_64[398];
#endif
#if MEMORY_THREADS > 25
	hash_64[400] += hash_64[401]; hash_64[402] += hash_64[403];
	hash_64[404] += hash_64[405]; hash_64[406] += hash_64[407];
	hash_64[408] += hash_64[409]; hash_64[410] += hash_64[411];
	hash_64[412] += hash_64[413]; hash_64[414] += hash_64[415];
	hash_64[400] += hash_64[402]; hash_64[404] += hash_64[406];
	hash_64[408] += hash_64[410]; hash_64[412] += hash_64[414];
#endif
#if MEMORY_THREADS > 26
	hash_64[416] += hash_64[417]; hash_64[418] += hash_64[419];
	hash_64[420] += hash_64[421]; hash_64[422] += hash_64[423];
	hash_64[424] += hash_64[425]; hash_64[426] += hash_64[427];
	hash_64[428] += hash_64[429]; hash_64[430] += hash_64[431];
	hash_64[416] += hash_64[418]; hash_64[420] += hash_64[422];
	hash_64[424] += hash_64[426]; hash_64[428] += hash_64[430];
#endif
#if MEMORY_THREADS > 27
	hash_64[432] += hash_64[433]; hash_64[434] += hash_64[435];
	hash_64[436] += hash_64[437]; hash_64[438] += hash_64[439];
	hash_64[440] += hash_64[441]; hash_64[442] += hash_64[443];
	hash_64[444] += hash_64[445]; hash_64[446] += hash_64[447];
	hash_64[432] += hash_64[434]; hash_64[436] += hash_64[438];
	hash_64[440] += hash_64[442]; hash_64[444] += hash_64[446];
#endif
#if MEMORY_THREADS > 28
	hash_64[448] += hash_64[449]; hash_64[450] += hash_64[451];
	hash_64[452] += hash_64[453]; hash_64[454] += hash_64[455];
	hash_64[456] += hash_64[457]; hash_64[458] += hash_64[459];
	hash_64[460] += hash_64[461]; hash_64[462] += hash_64[463];
	hash_64[448] += hash_64[450]; hash_64[452] += hash_64[454];
	hash_64[456] += hash_64[458]; hash_64[460] += hash_64[462];
#endif
#if MEMORY_THREADS > 29
	hash_64[464] += hash_64[465]; hash_64[466] += hash_64[467];
	hash_64[468] += hash_64[469]; hash_64[470] += hash_64[471];
	hash_64[472] += hash_64[473]; hash_64[474] += hash_64[475];
	hash_64[476] += hash_64[477]; hash_64[478] += hash_64[479];
	hash_64[464] += hash_64[466]; hash_64[468] += hash_64[470];
	hash_64[472] += hash_64[474]; hash_64[476] += hash_64[478];
#endif
#if MEMORY_THREADS > 30
	hash_64[480] += hash_64[481]; hash_64[482] += hash_64[483];
	hash_64[484] += hash_64[485]; hash_64[486] += hash_64[487];
	hash_64[488] += hash_64[489]; hash_64[490] += hash_64[491];
	hash_64[492] += hash_64[493]; hash_64[494] += hash_64[495];
	hash_64[480] += hash_64[482]; hash_64[484] += hash_64[486];
	hash_64[488] += hash_64[490]; hash_64[492] += hash_64[494];
#endif
#if MEMORY_THREADS > 31
	hash_64[496] += hash_64[497]; hash_64[498] += hash_64[499];
	hash_64[500] += hash_64[501]; hash_64[502] += hash_64[503];
	hash_64[504] += hash_64[505]; hash_64[506] += hash_64[507];
	hash_64[508] += hash_64[509]; hash_64[510] += hash_64[511];
	hash_64[496] += hash_64[498]; hash_64[500] += hash_64[502];
	hash_64[504] += hash_64[506]; hash_64[508] += hash_64[510];
#endif
#if MEMORY_THREADS > 32
	hash_64[512] += hash_64[513]; hash_64[514] += hash_64[515];
	hash_64[516] += hash_64[517]; hash_64[518] += hash_64[519];
	hash_64[520] += hash_64[521]; hash_64[522] += hash_64[523];
	hash_64[524] += hash_64[525]; hash_64[526] += hash_64[527];
	hash_64[512] += hash_64[514]; hash_64[516] += hash_64[518];
	hash_64[520] += hash_64[522]; hash_64[524] += hash_64[526];
#endif
#if MEMORY_THREADS > 33
	hash_64[528] += hash_64[529]; hash_64[530] += hash_64[531];
	hash_64[532] += hash_64[533]; hash_64[534] += hash_64[535];
	hash_64[536] += hash_64[537]; hash_64[538] += hash_64[539];
	hash_64[540] += hash_64[541]; hash_64[542] += hash_64[543];
	hash_64[528] += hash_64[530]; hash_64[532] += hash_64[534];
	hash_64[536] += hash_64[538]; hash_64[540] += hash_64[542];
#endif
#if MEMORY_THREADS > 34
	hash_64[544] += hash_64[545]; hash_64[546] += hash_64[547];
	hash_64[548] += hash_64[549]; hash_64[550] += hash_64[551];
	hash_64[552] += hash_64[553]; hash_64[554] += hash_64[555];
	hash_64[556] += hash_64[557]; hash_64[558] += hash_64[559];
	hash_64[544] += hash_64[546]; hash_64[548] += hash_64[550];
	hash_64[552] += hash_64[554]; hash_64[556] += hash_64[558];
#endif
#if MEMORY_THREADS > 35
	hash_64[560] += hash_64[561]; hash_64[562] += hash_64[563];
	hash_64[564] += hash_64[565]; hash_64[566] += hash_64[567];
	hash_64[568] += hash_64[569]; hash_64[570] += hash_64[571];
	hash_64[572] += hash_64[573]; hash_64[574] += hash_64[575];
	hash_64[560] += hash_64[562]; hash_64[564] += hash_64[566];
	hash_64[568] += hash_64[570]; hash_64[572] += hash_64[574];
#endif
#if MEMORY_THREADS > 36
	hash_64[576] += hash_64[577]; hash_64[578] += hash_64[579];
	hash_64[580] += hash_64[581]; hash_64[582] += hash_64[583];
	hash_64[584] += hash_64[585]; hash_64[586] += hash_64[587];
	hash_64[588] += hash_64[589]; hash_64[590] += hash_64[591];
	hash_64[576] += hash_64[578]; hash_64[580] += hash_64[582];
	hash_64[584] += hash_64[586]; hash_64[588] += hash_64[590];
#endif
#if MEMORY_THREADS > 37
	hash_64[592] += hash_64[593]; hash_64[594] += hash_64[595];
	hash_64[596] += hash_64[597]; hash_64[598] += hash_64[599];
	hash_64[600] += hash_64[601]; hash_64[602] += hash_64[603];
	hash_64[604] += hash_64[605]; hash_64[606] += hash_64[607];
	hash_64[592] += hash_64[594]; hash_64[596] += hash_64[598];
	hash_64[600] += hash_64[602]; hash_64[604] += hash_64[606];
#endif
#if MEMORY_THREADS > 38
	hash_64[608] += hash_64[609]; hash_64[610] += hash_64[611];
	hash_64[612] += hash_64[613]; hash_64[614] += hash_64[615];
	hash_64[616] += hash_64[617]; hash_64[618] += hash_64[619];
	hash_64[620] += hash_64[621]; hash_64[622] += hash_64[623];
	hash_64[608] += hash_64[610]; hash_64[612] += hash_64[614];
	hash_64[616] += hash_64[618]; hash_64[620] += hash_64[622];
#endif
#if MEMORY_THREADS > 39
	hash_64[624] += hash_64[625]; hash_64[626] += hash_64[627];
	hash_64[628] += hash_64[629]; hash_64[630] += hash_64[631];
	hash_64[632] += hash_64[633]; hash_64[634] += hash_64[635];
	hash_64[636] += hash_64[637]; hash_64[638] += hash_64[639];
	hash_64[624] += hash_64[626]; hash_64[628] += hash_64[630];
	hash_64[632] += hash_64[634]; hash_64[636] += hash_64[638];
#endif
#if MEMORY_THREADS > 40
	hash_64[640] += hash_64[641]; hash_64[642] += hash_64[643];
	hash_64[644] += hash_64[645]; hash_64[646] += hash_64[647];
	hash_64[648] += hash_64[649]; hash_64[650] += hash_64[651];
	hash_64[652] += hash_64[653]; hash_64[654] += hash_64[655];
	hash_64[640] += hash_64[642]; hash_64[644] += hash_64[646];
	hash_64[648] += hash_64[650]; hash_64[652] += hash_64[654];
#endif
#if MEMORY_THREADS > 41
	hash_64[656] += hash_64[657]; hash_64[658] += hash_64[659];
	hash_64[660] += hash_64[661]; hash_64[662] += hash_64[663];
	hash_64[664] += hash_64[665]; hash_64[666] += hash_64[667];
	hash_64[668] += hash_64[669]; hash_64[670] += hash_64[671];
	hash_64[656] += hash_64[658]; hash_64[660] += hash_64[662];
	hash_64[664] += hash_64[666]; hash_64[668] += hash_64[670];
#endif
#if MEMORY_THREADS > 42
	hash_64[672] += hash_64[673]; hash_64[674] += hash_64[675];
	hash_64[676] += hash_64[677]; hash_64[678] += hash_64[679];
	hash_64[680] += hash_64[681]; hash_64[682] += hash_64[683];
	hash_64[684] += hash_64[685]; hash_64[686] += hash_64[687];
	hash_64[672] += hash_64[674]; hash_64[676] += hash_64[678];
	hash_64[680] += hash_64[682]; hash_64[684] += hash_64[686];
#endif
#if MEMORY_THREADS > 43
	hash_64[688] += hash_64[689]; hash_64[690] += hash_64[691];
	hash_64[692] += hash_64[693]; hash_64[694] += hash_64[695];
	hash_64[696] += hash_64[697]; hash_64[698] += hash_64[699];
	hash_64[700] += hash_64[701]; hash_64[702] += hash_64[703];
	hash_64[688] += hash_64[690]; hash_64[692] += hash_64[694];
	hash_64[696] += hash_64[698]; hash_64[700] += hash_64[702];
#endif
#if MEMORY_THREADS > 44
	hash_64[704] += hash_64[705]; hash_64[706] += hash_64[707];
	hash_64[708] += hash_64[709]; hash_64[710] += hash_64[711];
	hash_64[712] += hash_64[713]; hash_64[714] += hash_64[715];
	hash_64[716] += hash_64[717]; hash_64[718] += hash_64[719];
	hash_64[704] += hash_64[706]; hash_64[708] += hash_64[710];
	hash_64[712] += hash_64[714]; hash_64[716] += hash_64[718];
#endif
#if MEMORY_THREADS > 45
	hash_64[720] += hash_64[721]; hash_64[722] += hash_64[723];
	hash_64[724] += hash_64[725]; hash_64[726] += hash_64[727];
	hash_64[728] += hash_64[729]; hash_64[730] += hash_64[731];
	hash_64[732] += hash_64[733]; hash_64[734] += hash_64[735];
	hash_64[720] += hash_64[722]; hash_64[724] += hash_64[726];
	hash_64[728] += hash_64[730]; hash_64[732] += hash_64[734];
#endif
#if MEMORY_THREADS > 46
	hash_64[736] += hash_64[737]; hash_64[738] += hash_64[739];
	hash_64[740] += hash_64[741]; hash_64[742] += hash_64[743];
	hash_64[744] += hash_64[745]; hash_64[746] += hash_64[747];
	hash_64[748] += hash_64[749]; hash_64[750] += hash_64[751];
	hash_64[736] += hash_64[738]; hash_64[740] += hash_64[742];
	hash_64[744] += hash_64[746]; hash_64[748] += hash_64[750];
#endif
#if MEMORY_THREADS > 47
	hash_64[752] += hash_64[753]; hash_64[754] += hash_64[755];
	hash_64[756] += hash_64[757]; hash_64[758] += hash_64[759];
	hash_64[760] += hash_64[761]; hash_64[762] += hash_64[763];
	hash_64[764] += hash_64[765]; hash_64[766] += hash_64[767];
	hash_64[752] += hash_64[754]; hash_64[756] += hash_64[758];
	hash_64[760] += hash_64[762]; hash_64[764] += hash_64[766];
#endif
#if MEMORY_THREADS > 48
	hash_64[768] += hash_64[769]; hash_64[770] += hash_64[771];
	hash_64[772] += hash_64[773]; hash_64[774] += hash_64[775];
	hash_64[776] += hash_64[777]; hash_64[778] += hash_64[779];
	hash_64[780] += hash_64[781]; hash_64[782] += hash_64[783];
	hash_64[768] += hash_64[770]; hash_64[772] += hash_64[774];
	hash_64[776] += hash_64[778]; hash_64[780] += hash_64[782];
#endif
#if MEMORY_THREADS > 49
	hash_64[784] += hash_64[785]; hash_64[786] += hash_64[787];
	hash_64[788] += hash_64[789]; hash_64[790] += hash_64[791];
	hash_64[792] += hash_64[793]; hash_64[794] += hash_64[795];
	hash_64[796] += hash_64[797]; hash_64[798] += hash_64[799];
	hash_64[784] += hash_64[786]; hash_64[788] += hash_64[790];
	hash_64[792] += hash_64[794]; hash_64[796] += hash_64[798];
#endif
#if MEMORY_THREADS > 50
	hash_64[800] += hash_64[801]; hash_64[802] += hash_64[803];
	hash_64[804] += hash_64[805]; hash_64[806] += hash_64[807];
	hash_64[808] += hash_64[809]; hash_64[810] += hash_64[811];
	hash_64[812] += hash_64[813]; hash_64[814] += hash_64[815];
	hash_64[800] += hash_64[802]; hash_64[804] += hash_64[806];
	hash_64[808] += hash_64[810]; hash_64[812] += hash_64[814];
#endif
#if MEMORY_THREADS > 51
	hash_64[816] += hash_64[817]; hash_64[818] += hash_64[819];
	hash_64[820] += hash_64[821]; hash_64[822] += hash_64[823];
	hash_64[824] += hash_64[825]; hash_64[826] += hash_64[827];
	hash_64[828] += hash_64[829]; hash_64[830] += hash_64[831];
	hash_64[816] += hash_64[818]; hash_64[820] += hash_64[822];
	hash_64[824] += hash_64[826]; hash_64[828] += hash_64[830];
#endif
#if MEMORY_THREADS > 52
	hash_64[832] += hash_64[833]; hash_64[834] += hash_64[835];
	hash_64[836] += hash_64[837]; hash_64[838] += hash_64[839];
	hash_64[840] += hash_64[841]; hash_64[842] += hash_64[843];
	hash_64[844] += hash_64[845]; hash_64[846] += hash_64[847];
	hash_64[832] += hash_64[834]; hash_64[836] += hash_64[838];
	hash_64[840] += hash_64[842]; hash_64[844] += hash_64[846];
#endif
#if MEMORY_THREADS > 53
	hash_64[848] += hash_64[849]; hash_64[850] += hash_64[851];
	hash_64[852] += hash_64[853]; hash_64[854] += hash_64[855];
	hash_64[856] += hash_64[857]; hash_64[858] += hash_64[859];
	hash_64[860] += hash_64[861]; hash_64[862] += hash_64[863];
	hash_64[848] += hash_64[850]; hash_64[852] += hash_64[854];
	hash_64[856] += hash_64[858]; hash_64[860] += hash_64[862];
#endif
#if MEMORY_THREADS > 54
	hash_64[864] += hash_64[865]; hash_64[866] += hash_64[867];
	hash_64[868] += hash_64[869]; hash_64[870] += hash_64[871];
	hash_64[872] += hash_64[873]; hash_64[874] += hash_64[875];
	hash_64[876] += hash_64[877]; hash_64[878] += hash_64[879];
	hash_64[864] += hash_64[866]; hash_64[868] += hash_64[870];
	hash_64[872] += hash_64[874]; hash_64[876] += hash_64[878];
#endif
#if MEMORY_THREADS > 55
	hash_64[880] += hash_64[881]; hash_64[882] += hash_64[883];
	hash_64[884] += hash_64[885]; hash_64[886] += hash_64[887];
	hash_64[888] += hash_64[889]; hash_64[890] += hash_64[891];
	hash_64[892] += hash_64[893]; hash_64[894] += hash_64[895];
	hash_64[880] += hash_64[882]; hash_64[884] += hash_64[886];
	hash_64[888] += hash_64[890]; hash_64[892] += hash_64[894];
#endif
#if MEMORY_THREADS > 56
	hash_64[896] += hash_64[897]; hash_64[898] += hash_64[899];
	hash_64[900] += hash_64[901]; hash_64[902] += hash_64[903];
	hash_64[904] += hash_64[905]; hash_64[906] += hash_64[907];
	hash_64[908] += hash_64[909]; hash_64[910] += hash_64[911];
	hash_64[896] += hash_64[898]; hash_64[900] += hash_64[902];
	hash_64[904] += hash_64[906]; hash_64[908] += hash_64[910];
#endif
#if MEMORY_THREADS > 57
	hash_64[912] += hash_64[913]; hash_64[914] += hash_64[915];
	hash_64[916] += hash_64[917]; hash_64[918] += hash_64[919];
	hash_64[920] += hash_64[921]; hash_64[922] += hash_64[923];
	hash_64[924] += hash_64[925]; hash_64[926] += hash_64[927];
	hash_64[912] += hash_64[914]; hash_64[916] += hash_64[918];
	hash_64[920] += hash_64[922]; hash_64[924] += hash_64[926];
#endif
#if MEMORY_THREADS > 58
	hash_64[928] += hash_64[929]; hash_64[930] += hash_64[931];
	hash_64[932] += hash_64[933]; hash_64[934] += hash_64[935];
	hash_64[936] += hash_64[937]; hash_64[938] += hash_64[939];
	hash_64[940] += hash_64[941]; hash_64[942] += hash_64[943];
	hash_64[928] += hash_64[930]; hash_64[932] += hash_64[934];
	hash_64[936] += hash_64[938]; hash_64[940] += hash_64[942];
#endif
#if MEMORY_THREADS > 59
	hash_64[944] += hash_64[945]; hash_64[946] += hash_64[947];
	hash_64[948] += hash_64[949]; hash_64[950] += hash_64[951];
	hash_64[952] += hash_64[953]; hash_64[954] += hash_64[955];
	hash_64[956] += hash_64[957]; hash_64[958] += hash_64[959];
	hash_64[944] += hash_64[946]; hash_64[948] += hash_64[950];
	hash_64[952] += hash_64[954]; hash_64[956] += hash_64[958];
#endif
#if MEMORY_THREADS > 60
	hash_64[960] += hash_64[961]; hash_64[962] += hash_64[963];
	hash_64[964] += hash_64[965]; hash_64[966] += hash_64[967];
	hash_64[968] += hash_64[969]; hash_64[970] += hash_64[971];
	hash_64[972] += hash_64[973]; hash_64[974] += hash_64[975];
	hash_64[960] += hash_64[962]; hash_64[964] += hash_64[966];
	hash_64[968] += hash_64[970]; hash_64[972] += hash_64[974];
#endif
#if MEMORY_THREADS > 61
	hash_64[976] += hash_64[977]; hash_64[978] += hash_64[979];
	hash_64[980] += hash_64[981]; hash_64[982] += hash_64[983];
	hash_64[984] += hash_64[985]; hash_64[986] += hash_64[987];
	hash_64[988] += hash_64[989]; hash_64[990] += hash_64[991];
	hash_64[976] += hash_64[978]; hash_64[980] += hash_64[982];
	hash_64[984] += hash_64[986]; hash_64[988] += hash_64[990];
#endif
#if MEMORY_THREADS > 62
	hash_64[992] += hash_64[993]; hash_64[994] += hash_64[995];
	hash_64[996] += hash_64[997]; hash_64[998] += hash_64[999];
	hash_64[1000] += hash_64[1001]; hash_64[1002] += hash_64[1003];
	hash_64[1004] += hash_64[1005]; hash_64[1006] += hash_64[1007];
	hash_64[992] += hash_64[994]; hash_64[996] += hash_64[998];
	hash_64[1000] += hash_64[1002]; hash_64[1004] += hash_64[1006];
#endif
#if MEMORY_THREADS > 63
	hash_64[1008] += hash_64[1009]; hash_64[1010] += hash_64[1011];
	hash_64[1012] += hash_64[1013]; hash_64[1014] += hash_64[1015];
	hash_64[1016] += hash_64[1017]; hash_64[1018] += hash_64[1019];
	hash_64[1020] += hash_64[1021]; hash_64[1022] += hash_64[1023];
	hash_64[1008] += hash_64[1010]; hash_64[1012] += hash_64[1014];
	hash_64[1016] += hash_64[1018]; hash_64[1020] += hash_64[1022];
#endif
#if MEMORY_THREADS > 64
	hash_64[1024] += hash_64[1025]; hash_64[1026] += hash_64[1027];
	hash_64[1028] += hash_64[1029]; hash_64[1030] += hash_64[1031];
	hash_64[1032] += hash_64[1033]; hash_64[1034] += hash_64[1035];
	hash_64[1036] += hash_64[1037]; hash_64[1038] += hash_64[1039];
	hash_64[1024] += hash_64[1026]; hash_64[1028] += hash_64[1030];
	hash_64[1032] += hash_64[1034]; hash_64[1036] += hash_64[1038];
#endif
#if MEMORY_THREADS > 65
	hash_64[1040] += hash_64[1041]; hash_64[1042] += hash_64[1043];
	hash_64[1044] += hash_64[1045]; hash_64[1046] += hash_64[1047];
	hash_64[1048] += hash_64[1049]; hash_64[1050] += hash_64[1051];
	hash_64[1052] += hash_64[1053]; hash_64[1054] += hash_64[1055];
	hash_64[1040] += hash_64[1042]; hash_64[1044] += hash_64[1046];
	hash_64[1048] += hash_64[1050]; hash_64[1052] += hash_64[1054];
#endif
#if MEMORY_THREADS > 66
	hash_64[1056] += hash_64[1057]; hash_64[1058] += hash_64[1059];
	hash_64[1060] += hash_64[1061]; hash_64[1062] += hash_64[1063];
	hash_64[1064] += hash_64[1065]; hash_64[1066] += hash_64[1067];
	hash_64[1068] += hash_64[1069]; hash_64[1070] += hash_64[1071];
	hash_64[1056] += hash_64[1058]; hash_64[1060] += hash_64[1062];
	hash_64[1064] += hash_64[1066]; hash_64[1068] += hash_64[1070];
#endif
#if MEMORY_THREADS > 67
	hash_64[1072] += hash_64[1073]; hash_64[1074] += hash_64[1075];
	hash_64[1076] += hash_64[1077]; hash_64[1078] += hash_64[1079];
	hash_64[1080] += hash_64[1081]; hash_64[1082] += hash_64[1083];
	hash_64[1084] += hash_64[1085]; hash_64[1086] += hash_64[1087];
	hash_64[1072] += hash_64[1074]; hash_64[1076] += hash_64[1078];
	hash_64[1080] += hash_64[1082]; hash_64[1084] += hash_64[1086];
#endif
#if MEMORY_THREADS > 68
	hash_64[1088] += hash_64[1089]; hash_64[1090] += hash_64[1091];
	hash_64[1092] += hash_64[1093]; hash_64[1094] += hash_64[1095];
	hash_64[1096] += hash_64[1097]; hash_64[1098] += hash_64[1099];
	hash_64[1100] += hash_64[1101]; hash_64[1102] += hash_64[1103];
	hash_64[1088] += hash_64[1090]; hash_64[1092] += hash_64[1094];
	hash_64[1096] += hash_64[1098]; hash_64[1100] += hash_64[1102];
#endif
#if MEMORY_THREADS > 69
	hash_64[1104] += hash_64[1105]; hash_64[1106] += hash_64[1107];
	hash_64[1108] += hash_64[1109]; hash_64[1110] += hash_64[1111];
	hash_64[1112] += hash_64[1113]; hash_64[1114] += hash_64[1115];
	hash_64[1116] += hash_64[1117]; hash_64[1118] += hash_64[1119];
	hash_64[1104] += hash_64[1106]; hash_64[1108] += hash_64[1110];
	hash_64[1112] += hash_64[1114]; hash_64[1116] += hash_64[1118];
#endif
#if MEMORY_THREADS > 70
	hash_64[1120] += hash_64[1121]; hash_64[1122] += hash_64[1123];
	hash_64[1124] += hash_64[1125]; hash_64[1126] += hash_64[1127];
	hash_64[1128] += hash_64[1129]; hash_64[1130] += hash_64[1131];
	hash_64[1132] += hash_64[1133]; hash_64[1134] += hash_64[1135];
	hash_64[1120] += hash_64[1122]; hash_64[1124] += hash_64[1126];
	hash_64[1128] += hash_64[1130]; hash_64[1132] += hash_64[1134];
#endif
#if MEMORY_THREADS > 71
	hash_64[1136] += hash_64[1137]; hash_64[1138] += hash_64[1139];
	hash_64[1140] += hash_64[1141]; hash_64[1142] += hash_64[1143];
	hash_64[1144] += hash_64[1145]; hash_64[1146] += hash_64[1147];
	hash_64[1148] += hash_64[1149]; hash_64[1150] += hash_64[1151];
	hash_64[1136] += hash_64[1138]; hash_64[1140] += hash_64[1142];
	hash_64[1144] += hash_64[1146]; hash_64[1148] += hash_64[1150];
#endif
#if MEMORY_THREADS > 72
	hash_64[1152] += hash_64[1153]; hash_64[1154] += hash_64[1155];
	hash_64[1156] += hash_64[1157]; hash_64[1158] += hash_64[1159];
	hash_64[1160] += hash_64[1161]; hash_64[1162] += hash_64[1163];
	hash_64[1164] += hash_64[1165]; hash_64[1166] += hash_64[1167];
	hash_64[1152] += hash_64[1154]; hash_64[1156] += hash_64[1158];
	hash_64[1160] += hash_64[1162]; hash_64[1164] += hash_64[1166];
#endif
#if MEMORY_THREADS > 73
	hash_64[1168] += hash_64[1169]; hash_64[1170] += hash_64[1171];
	hash_64[1172] += hash_64[1173]; hash_64[1174] += hash_64[1175];
	hash_64[1176] += hash_64[1177]; hash_64[1178] += hash_64[1179];
	hash_64[1180] += hash_64[1181]; hash_64[1182] += hash_64[1183];
	hash_64[1168] += hash_64[1170]; hash_64[1172] += hash_64[1174];
	hash_64[1176] += hash_64[1178]; hash_64[1180] += hash_64[1182];
#endif
#if MEMORY_THREADS > 74
	hash_64[1184] += hash_64[1185]; hash_64[1186] += hash_64[1187];
	hash_64[1188] += hash_64[1189]; hash_64[1190] += hash_64[1191];
	hash_64[1192] += hash_64[1193]; hash_64[1194] += hash_64[1195];
	hash_64[1196] += hash_64[1197]; hash_64[1198] += hash_64[1199];
	hash_64[1184] += hash_64[1186]; hash_64[1188] += hash_64[1190];
	hash_64[1192] += hash_64[1194]; hash_64[1196] += hash_64[1198];
#endif
#if MEMORY_THREADS > 75
	hash_64[1200] += hash_64[1201]; hash_64[1202] += hash_64[1203];
	hash_64[1204] += hash_64[1205]; hash_64[1206] += hash_64[1207];
	hash_64[1208] += hash_64[1209]; hash_64[1210] += hash_64[1211];
	hash_64[1212] += hash_64[1213]; hash_64[1214] += hash_64[1215];
	hash_64[1200] += hash_64[1202]; hash_64[1204] += hash_64[1206];
	hash_64[1208] += hash_64[1210]; hash_64[1212] += hash_64[1214];
#endif
#if MEMORY_THREADS > 76
	hash_64[1216] += hash_64[1217]; hash_64[1218] += hash_64[1219];
	hash_64[1220] += hash_64[1221]; hash_64[1222] += hash_64[1223];
	hash_64[1224] += hash_64[1225]; hash_64[1226] += hash_64[1227];
	hash_64[1228] += hash_64[1229]; hash_64[1230] += hash_64[1231];
	hash_64[1216] += hash_64[1218]; hash_64[1220] += hash_64[1222];
	hash_64[1224] += hash_64[1226]; hash_64[1228] += hash_64[1230];
#endif
#if MEMORY_THREADS > 77
	hash_64[1232] += hash_64[1233]; hash_64[1234] += hash_64[1235];
	hash_64[1236] += hash_64[1237]; hash_64[1238] += hash_64[1239];
	hash_64[1240] += hash_64[1241]; hash_64[1242] += hash_64[1243];
	hash_64[1244] += hash_64[1245]; hash_64[1246] += hash_64[1247];
	hash_64[1232] += hash_64[1234]; hash_64[1236] += hash_64[1238];
	hash_64[1240] += hash_64[1242]; hash_64[1244] += hash_64[1246];
#endif
#if MEMORY_THREADS > 78
	hash_64[1248] += hash_64[1249]; hash_64[1250] += hash_64[1251];
	hash_64[1252] += hash_64[1253]; hash_64[1254] += hash_64[1255];
	hash_64[1256] += hash_64[1257]; hash_64[1258] += hash_64[1259];
	hash_64[1260] += hash_64[1261]; hash_64[1262] += hash_64[1263];
	hash_64[1248] += hash_64[1250]; hash_64[1252] += hash_64[1254];
	hash_64[1256] += hash_64[1258]; hash_64[1260] += hash_64[1262];
#endif
#if MEMORY_THREADS > 79
	hash_64[1264] += hash_64[1265]; hash_64[1266] += hash_64[1267];
	hash_64[1268] += hash_64[1269]; hash_64[1270] += hash_64[1271];
	hash_64[1272] += hash_64[1273]; hash_64[1274] += hash_64[1275];
	hash_64[1276] += hash_64[1277]; hash_64[1278] += hash_64[1279];
	hash_64[1264] += hash_64[1266]; hash_64[1268] += hash_64[1270];
	hash_64[1272] += hash_64[1274]; hash_64[1276] += hash_64[1278];
#endif
#if MEMORY_THREADS > 80
	hash_64[1280] += hash_64[1281]; hash_64[1282] += hash_64[1283];
	hash_64[1284] += hash_64[1285]; hash_64[1286] += hash_64[1287];
	hash_64[1288] += hash_64[1289]; hash_64[1290] += hash_64[1291];
	hash_64[1292] += hash_64[1293]; hash_64[1294] += hash_64[1295];
	hash_64[1280] += hash_64[1282]; hash_64[1284] += hash_64[1286];
	hash_64[1288] += hash_64[1290]; hash_64[1292] += hash_64[1294];
#endif
#if MEMORY_THREADS > 81
	hash_64[1296] += hash_64[1297]; hash_64[1298] += hash_64[1299];
	hash_64[1300] += hash_64[1301]; hash_64[1302] += hash_64[1303];
	hash_64[1304] += hash_64[1305]; hash_64[1306] += hash_64[1307];
	hash_64[1308] += hash_64[1309]; hash_64[1310] += hash_64[1311];
	hash_64[1296] += hash_64[1298]; hash_64[1300] += hash_64[1302];
	hash_64[1304] += hash_64[1306]; hash_64[1308] += hash_64[1310];
#endif
#if MEMORY_THREADS > 82
	hash_64[1312] += hash_64[1313]; hash_64[1314] += hash_64[1315];
	hash_64[1316] += hash_64[1317]; hash_64[1318] += hash_64[1319];
	hash_64[1320] += hash_64[1321]; hash_64[1322] += hash_64[1323];
	hash_64[1324] += hash_64[1325]; hash_64[1326] += hash_64[1327];
	hash_64[1312] += hash_64[1314]; hash_64[1316] += hash_64[1318];
	hash_64[1320] += hash_64[1322]; hash_64[1324] += hash_64[1326];
#endif
#if MEMORY_THREADS > 83
	hash_64[1328] += hash_64[1329]; hash_64[1330] += hash_64[1331];
	hash_64[1332] += hash_64[1333]; hash_64[1334] += hash_64[1335];
	hash_64[1336] += hash_64[1337]; hash_64[1338] += hash_64[1339];
	hash_64[1340] += hash_64[1341]; hash_64[1342] += hash_64[1343];
	hash_64[1328] += hash_64[1330]; hash_64[1332] += hash_64[1334];
	hash_64[1336] += hash_64[1338]; hash_64[1340] += hash_64[1342];
#endif
#if MEMORY_THREADS > 84
	hash_64[1344] += hash_64[1345]; hash_64[1346] += hash_64[1347];
	hash_64[1348] += hash_64[1349]; hash_64[1350] += hash_64[1351];
	hash_64[1352] += hash_64[1353]; hash_64[1354] += hash_64[1355];
	hash_64[1356] += hash_64[1357]; hash_64[1358] += hash_64[1359];
	hash_64[1344] += hash_64[1346]; hash_64[1348] += hash_64[1350];
	hash_64[1352] += hash_64[1354]; hash_64[1356] += hash_64[1358];
#endif
#if MEMORY_THREADS > 85
	hash_64[1360] += hash_64[1361]; hash_64[1362] += hash_64[1363];
	hash_64[1364] += hash_64[1365]; hash_64[1366] += hash_64[1367];
	hash_64[1368] += hash_64[1369]; hash_64[1370] += hash_64[1371];
	hash_64[1372] += hash_64[1373]; hash_64[1374] += hash_64[1375];
	hash_64[1360] += hash_64[1362]; hash_64[1364] += hash_64[1366];
	hash_64[1368] += hash_64[1370]; hash_64[1372] += hash_64[1374];
#endif
#if MEMORY_THREADS > 86
	hash_64[1376] += hash_64[1377]; hash_64[1378] += hash_64[1379];
	hash_64[1380] += hash_64[1381]; hash_64[1382] += hash_64[1383];
	hash_64[1384] += hash_64[1385]; hash_64[1386] += hash_64[1387];
	hash_64[1388] += hash_64[1389]; hash_64[1390] += hash_64[1391];
	hash_64[1376] += hash_64[1378]; hash_64[1380] += hash_64[1382];
	hash_64[1384] += hash_64[1386]; hash_64[1388] += hash_64[1390];
#endif
#if MEMORY_THREADS > 87
	hash_64[1392] += hash_64[1393]; hash_64[1394] += hash_64[1395];
	hash_64[1396] += hash_64[1397]; hash_64[1398] += hash_64[1399];
	hash_64[1400] += hash_64[1401]; hash_64[1402] += hash_64[1403];
	hash_64[1404] += hash_64[1405]; hash_64[1406] += hash_64[1407];
	hash_64[1392] += hash_64[1394]; hash_64[1396] += hash_64[1398];
	hash_64[1400] += hash_64[1402]; hash_64[1404] += hash_64[1406];
#endif
#if MEMORY_THREADS > 88
	hash_64[1408] += hash_64[1409]; hash_64[1410] += hash_64[1411];
	hash_64[1412] += hash_64[1413]; hash_64[1414] += hash_64[1415];
	hash_64[1416] += hash_64[1417]; hash_64[1418] += hash_64[1419];
	hash_64[1420] += hash_64[1421]; hash_64[1422] += hash_64[1423];
	hash_64[1408] += hash_64[1410]; hash_64[1412] += hash_64[1414];
	hash_64[1416] += hash_64[1418]; hash_64[1420] += hash_64[1422];
#endif
#if MEMORY_THREADS > 89
	hash_64[1424] += hash_64[1425]; hash_64[1426] += hash_64[1427];
	hash_64[1428] += hash_64[1429]; hash_64[1430] += hash_64[1431];
	hash_64[1432] += hash_64[1433]; hash_64[1434] += hash_64[1435];
	hash_64[1436] += hash_64[1437]; hash_64[1438] += hash_64[1439];
	hash_64[1424] += hash_64[1426]; hash_64[1428] += hash_64[1430];
	hash_64[1432] += hash_64[1434]; hash_64[1436] += hash_64[1438];
#endif
#if MEMORY_THREADS > 90
	hash_64[1440] += hash_64[1441]; hash_64[1442] += hash_64[1443];
	hash_64[1444] += hash_64[1445]; hash_64[1446] += hash_64[1447];
	hash_64[1448] += hash_64[1449]; hash_64[1450] += hash_64[1451];
	hash_64[1452] += hash_64[1453]; hash_64[1454] += hash_64[1455];
	hash_64[1440] += hash_64[1442]; hash_64[1444] += hash_64[1446];
	hash_64[1448] += hash_64[1450]; hash_64[1452] += hash_64[1454];
#endif
#if MEMORY_THREADS > 91
	hash_64[1456] += hash_64[1457]; hash_64[1458] += hash_64[1459];
	hash_64[1460] += hash_64[1461]; hash_64[1462] += hash_64[1463];
	hash_64[1464] += hash_64[1465]; hash_64[1466] += hash_64[1467];
	hash_64[1468] += hash_64[1469]; hash_64[1470] += hash_64[1471];
	hash_64[1456] += hash_64[1458]; hash_64[1460] += hash_64[1462];
	hash_64[1464] += hash_64[1466]; hash_64[1468] += hash_64[1470];
#endif
#if MEMORY_THREADS > 92
	hash_64[1472] += hash_64[1473]; hash_64[1474] += hash_64[1475];
	hash_64[1476] += hash_64[1477]; hash_64[1478] += hash_64[1479];
	hash_64[1480] += hash_64[1481]; hash_64[1482] += hash_64[1483];
	hash_64[1484] += hash_64[1485]; hash_64[1486] += hash_64[1487];
	hash_64[1472] += hash_64[1474]; hash_64[1476] += hash_64[1478];
	hash_64[1480] += hash_64[1482]; hash_64[1484] += hash_64[1486];
#endif
#if MEMORY_THREADS > 93
	hash_64[1488] += hash_64[1489]; hash_64[1490] += hash_64[1491];
	hash_64[1492] += hash_64[1493]; hash_64[1494] += hash_64[1495];
	hash_64[1496] += hash_64[1497]; hash_64[1498] += hash_64[1499];
	hash_64[1500] += hash_64[1501]; hash_64[1502] += hash_64[1503];
	hash_64[1488] += hash_64[1490]; hash_64[1492] += hash_64[1494];
	hash_64[1496] += hash_64[1498]; hash_64[1500] += hash_64[1502];
#endif
#if MEMORY_THREADS > 94
	hash_64[1504] += hash_64[1505]; hash_64[1506] += hash_64[1507];
	hash_64[1508] += hash_64[1509]; hash_64[1510] += hash_64[1511];
	hash_64[1512] += hash_64[1513]; hash_64[1514] += hash_64[1515];
	hash_64[1516] += hash_64[1517]; hash_64[1518] += hash_64[1519];
	hash_64[1504] += hash_64[1506]; hash_64[1508] += hash_64[1510];
	hash_64[1512] += hash_64[1514]; hash_64[1516] += hash_64[1518];
#endif
#if MEMORY_THREADS > 95
	hash_64[1520] += hash_64[1521]; hash_64[1522] += hash_64[1523];
	hash_64[1524] += hash_64[1525]; hash_64[1526] += hash_64[1527];
	hash_64[1528] += hash_64[1529]; hash_64[1530] += hash_64[1531];
	hash_64[1532] += hash_64[1533]; hash_64[1534] += hash_64[1535];
	hash_64[1520] += hash_64[1522]; hash_64[1524] += hash_64[1526];
	hash_64[1528] += hash_64[1530]; hash_64[1532] += hash_64[1534];
#endif
#if MEMORY_THREADS > 96
	hash_64[1536] += hash_64[1537]; hash_64[1538] += hash_64[1539];
	hash_64[1540] += hash_64[1541]; hash_64[1542] += hash_64[1543];
	hash_64[1544] += hash_64[1545]; hash_64[1546] += hash_64[1547];
	hash_64[1548] += hash_64[1549]; hash_64[1550] += hash_64[1551];
	hash_64[1536] += hash_64[1538]; hash_64[1540] += hash_64[1542];
	hash_64[1544] += hash_64[1546]; hash_64[1548] += hash_64[1550];
#endif
#if MEMORY_THREADS > 97
	hash_64[1552] += hash_64[1553]; hash_64[1554] += hash_64[1555];
	hash_64[1556] += hash_64[1557]; hash_64[1558] += hash_64[1559];
	hash_64[1560] += hash_64[1561]; hash_64[1562] += hash_64[1563];
	hash_64[1564] += hash_64[1565]; hash_64[1566] += hash_64[1567];
	hash_64[1552] += hash_64[1554]; hash_64[1556] += hash_64[1558];
	hash_64[1560] += hash_64[1562]; hash_64[1564] += hash_64[1566];
#endif
#if MEMORY_THREADS > 98
	hash_64[1568] += hash_64[1569]; hash_64[1570] += hash_64[1571];
	hash_64[1572] += hash_64[1573]; hash_64[1574] += hash_64[1575];
	hash_64[1576] += hash_64[1577]; hash_64[1578] += hash_64[1579];
	hash_64[1580] += hash_64[1581]; hash_64[1582] += hash_64[1583];
	hash_64[1568] += hash_64[1570]; hash_64[1572] += hash_64[1574];
	hash_64[1576] += hash_64[1578]; hash_64[1580] += hash_64[1582];
#endif
#if MEMORY_THREADS > 99
	hash_64[1584] += hash_64[1585]; hash_64[1586] += hash_64[1587];
	hash_64[1588] += hash_64[1589]; hash_64[1590] += hash_64[1591];
	hash_64[1592] += hash_64[1593]; hash_64[1594] += hash_64[1595];
	hash_64[1596] += hash_64[1597]; hash_64[1598] += hash_64[1599];
	hash_64[1584] += hash_64[1586]; hash_64[1588] += hash_64[1590];
	hash_64[1592] += hash_64[1594]; hash_64[1596] += hash_64[1598];
#endif
#if MEMORY_THREADS > 100
	hash_64[1600] += hash_64[1601]; hash_64[1602] += hash_64[1603];
	hash_64[1604] += hash_64[1605]; hash_64[1606] += hash_64[1607];
	hash_64[1608] += hash_64[1609]; hash_64[1610] += hash_64[1611];
	hash_64[1612] += hash_64[1613]; hash_64[1614] += hash_64[1615];
	hash_64[1600] += hash_64[1602]; hash_64[1604] += hash_64[1606];
	hash_64[1608] += hash_64[1610]; hash_64[1612] += hash_64[1614];
#endif
#if MEMORY_THREADS > 101
	hash_64[1616] += hash_64[1617]; hash_64[1618] += hash_64[1619];
	hash_64[1620] += hash_64[1621]; hash_64[1622] += hash_64[1623];
	hash_64[1624] += hash_64[1625]; hash_64[1626] += hash_64[1627];
	hash_64[1628] += hash_64[1629]; hash_64[1630] += hash_64[1631];
	hash_64[1616] += hash_64[1618]; hash_64[1620] += hash_64[1622];
	hash_64[1624] += hash_64[1626]; hash_64[1628] += hash_64[1630];
#endif
#if MEMORY_THREADS > 102
	hash_64[1632] += hash_64[1633]; hash_64[1634] += hash_64[1635];
	hash_64[1636] += hash_64[1637]; hash_64[1638] += hash_64[1639];
	hash_64[1640] += hash_64[1641]; hash_64[1642] += hash_64[1643];
	hash_64[1644] += hash_64[1645]; hash_64[1646] += hash_64[1647];
	hash_64[1632] += hash_64[1634]; hash_64[1636] += hash_64[1638];
	hash_64[1640] += hash_64[1642]; hash_64[1644] += hash_64[1646];
#endif
#if MEMORY_THREADS > 103
	hash_64[1648] += hash_64[1649]; hash_64[1650] += hash_64[1651];
	hash_64[1652] += hash_64[1653]; hash_64[1654] += hash_64[1655];
	hash_64[1656] += hash_64[1657]; hash_64[1658] += hash_64[1659];
	hash_64[1660] += hash_64[1661]; hash_64[1662] += hash_64[1663];
	hash_64[1648] += hash_64[1650]; hash_64[1652] += hash_64[1654];
	hash_64[1656] += hash_64[1658]; hash_64[1660] += hash_64[1662];
#endif
#if MEMORY_THREADS > 104
	hash_64[1664] += hash_64[1665]; hash_64[1666] += hash_64[1667];
	hash_64[1668] += hash_64[1669]; hash_64[1670] += hash_64[1671];
	hash_64[1672] += hash_64[1673]; hash_64[1674] += hash_64[1675];
	hash_64[1676] += hash_64[1677]; hash_64[1678] += hash_64[1679];
	hash_64[1664] += hash_64[1666]; hash_64[1668] += hash_64[1670];
	hash_64[1672] += hash_64[1674]; hash_64[1676] += hash_64[1678];
#endif
#if MEMORY_THREADS > 105
	hash_64[1680] += hash_64[1681]; hash_64[1682] += hash_64[1683];
	hash_64[1684] += hash_64[1685]; hash_64[1686] += hash_64[1687];
	hash_64[1688] += hash_64[1689]; hash_64[1690] += hash_64[1691];
	hash_64[1692] += hash_64[1693]; hash_64[1694] += hash_64[1695];
	hash_64[1680] += hash_64[1682]; hash_64[1684] += hash_64[1686];
	hash_64[1688] += hash_64[1690]; hash_64[1692] += hash_64[1694];
#endif
#if MEMORY_THREADS > 106
	hash_64[1696] += hash_64[1697]; hash_64[1698] += hash_64[1699];
	hash_64[1700] += hash_64[1701]; hash_64[1702] += hash_64[1703];
	hash_64[1704] += hash_64[1705]; hash_64[1706] += hash_64[1707];
	hash_64[1708] += hash_64[1709]; hash_64[1710] += hash_64[1711];
	hash_64[1696] += hash_64[1698]; hash_64[1700] += hash_64[1702];
	hash_64[1704] += hash_64[1706]; hash_64[1708] += hash_64[1710];
#endif
#if MEMORY_THREADS > 107
	hash_64[1712] += hash_64[1713]; hash_64[1714] += hash_64[1715];
	hash_64[1716] += hash_64[1717]; hash_64[1718] += hash_64[1719];
	hash_64[1720] += hash_64[1721]; hash_64[1722] += hash_64[1723];
	hash_64[1724] += hash_64[1725]; hash_64[1726] += hash_64[1727];
	hash_64[1712] += hash_64[1714]; hash_64[1716] += hash_64[1718];
	hash_64[1720] += hash_64[1722]; hash_64[1724] += hash_64[1726];
#endif
#if MEMORY_THREADS > 108
	hash_64[1728] += hash_64[1729]; hash_64[1730] += hash_64[1731];
	hash_64[1732] += hash_64[1733]; hash_64[1734] += hash_64[1735];
	hash_64[1736] += hash_64[1737]; hash_64[1738] += hash_64[1739];
	hash_64[1740] += hash_64[1741]; hash_64[1742] += hash_64[1743];
	hash_64[1728] += hash_64[1730]; hash_64[1732] += hash_64[1734];
	hash_64[1736] += hash_64[1738]; hash_64[1740] += hash_64[1742];
#endif
#if MEMORY_THREADS > 109
	hash_64[1744] += hash_64[1745]; hash_64[1746] += hash_64[1747];
	hash_64[1748] += hash_64[1749]; hash_64[1750] += hash_64[1751];
	hash_64[1752] += hash_64[1753]; hash_64[1754] += hash_64[1755];
	hash_64[1756] += hash_64[1757]; hash_64[1758] += hash_64[1759];
	hash_64[1744] += hash_64[1746]; hash_64[1748] += hash_64[1750];
	hash_64[1752] += hash_64[1754]; hash_64[1756] += hash_64[1758];
#endif
#if MEMORY_THREADS > 110
	hash_64[1760] += hash_64[1761]; hash_64[1762] += hash_64[1763];
	hash_64[1764] += hash_64[1765]; hash_64[1766] += hash_64[1767];
	hash_64[1768] += hash_64[1769]; hash_64[1770] += hash_64[1771];
	hash_64[1772] += hash_64[1773]; hash_64[1774] += hash_64[1775];
	hash_64[1760] += hash_64[1762]; hash_64[1764] += hash_64[1766];
	hash_64[1768] += hash_64[1770]; hash_64[1772] += hash_64[1774];
#endif
#if MEMORY_THREADS > 111
	hash_64[1776] += hash_64[1777]; hash_64[1778] += hash_64[1779];
	hash_64[1780] += hash_64[1781]; hash_64[1782] += hash_64[1783];
	hash_64[1784] += hash_64[1785]; hash_64[1786] += hash_64[1787];
	hash_64[1788] += hash_64[1789]; hash_64[1790] += hash_64[1791];
	hash_64[1776] += hash_64[1778]; hash_64[1780] += hash_64[1782];
	hash_64[1784] += hash_64[1786]; hash_64[1788] += hash_64[1790];
#endif
#if MEMORY_THREADS > 112
	hash_64[1792] += hash_64[1793]; hash_64[1794] += hash_64[1795];
	hash_64[1796] += hash_64[1797]; hash_64[1798] += hash_64[1799];
	hash_64[1800] += hash_64[1801]; hash_64[1802] += hash_64[1803];
	hash_64[1804] += hash_64[1805]; hash_64[1806] += hash_64[1807];
	hash_64[1792] += hash_64[1794]; hash_64[1796] += hash_64[1798];
	hash_64[1800] += hash_64[1802]; hash_64[1804] += hash_64[1806];
#endif
#if MEMORY_THREADS > 113
	hash_64[1808] += hash_64[1809]; hash_64[1810] += hash_64[1811];
	hash_64[1812] += hash_64[1813]; hash_64[1814] += hash_64[1815];
	hash_64[1816] += hash_64[1817]; hash_64[1818] += hash_64[1819];
	hash_64[1820] += hash_64[1821]; hash_64[1822] += hash_64[1823];
	hash_64[1808] += hash_64[1810]; hash_64[1812] += hash_64[1814];
	hash_64[1816] += hash_64[1818]; hash_64[1820] += hash_64[1822];
#endif
#if MEMORY_THREADS > 114
	hash_64[1824] += hash_64[1825]; hash_64[1826] += hash_64[1827];
	hash_64[1828] += hash_64[1829]; hash_64[1830] += hash_64[1831];
	hash_64[1832] += hash_64[1833]; hash_64[1834] += hash_64[1835];
	hash_64[1836] += hash_64[1837]; hash_64[1838] += hash_64[1839];
	hash_64[1824] += hash_64[1826]; hash_64[1828] += hash_64[1830];
	hash_64[1832] += hash_64[1834]; hash_64[1836] += hash_64[1838];
#endif
#if MEMORY_THREADS > 115
	hash_64[1840] += hash_64[1841]; hash_64[1842] += hash_64[1843];
	hash_64[1844] += hash_64[1845]; hash_64[1846] += hash_64[1847];
	hash_64[1848] += hash_64[1849]; hash_64[1850] += hash_64[1851];
	hash_64[1852] += hash_64[1853]; hash_64[1854] += hash_64[1855];
	hash_64[1840] += hash_64[1842]; hash_64[1844] += hash_64[1846];
	hash_64[1848] += hash_64[1850]; hash_64[1852] += hash_64[1854];
#endif
#if MEMORY_THREADS > 116
	hash_64[1856] += hash_64[1857]; hash_64[1858] += hash_64[1859];
	hash_64[1860] += hash_64[1861]; hash_64[1862] += hash_64[1863];
	hash_64[1864] += hash_64[1865]; hash_64[1866] += hash_64[1867];
	hash_64[1868] += hash_64[1869]; hash_64[1870] += hash_64[1871];
	hash_64[1856] += hash_64[1858]; hash_64[1860] += hash_64[1862];
	hash_64[1864] += hash_64[1866]; hash_64[1868] += hash_64[1870];
#endif
#if MEMORY_THREADS > 117
	hash_64[1872] += hash_64[1873]; hash_64[1874] += hash_64[1875];
	hash_64[1876] += hash_64[1877]; hash_64[1878] += hash_64[1879];
	hash_64[1880] += hash_64[1881]; hash_64[1882] += hash_64[1883];
	hash_64[1884] += hash_64[1885]; hash_64[1886] += hash_64[1887];
	hash_64[1872] += hash_64[1874]; hash_64[1876] += hash_64[1878];
	hash_64[1880] += hash_64[1882]; hash_64[1884] += hash_64[1886];
#endif
#if MEMORY_THREADS > 118
	hash_64[1888] += hash_64[1889]; hash_64[1890] += hash_64[1891];
	hash_64[1892] += hash_64[1893]; hash_64[1894] += hash_64[1895];
	hash_64[1896] += hash_64[1897]; hash_64[1898] += hash_64[1899];
	hash_64[1900] += hash_64[1901]; hash_64[1902] += hash_64[1903];
	hash_64[1888] += hash_64[1890]; hash_64[1892] += hash_64[1894];
	hash_64[1896] += hash_64[1898]; hash_64[1900] += hash_64[1902];
#endif
#if MEMORY_THREADS > 119
	hash_64[1904] += hash_64[1905]; hash_64[1906] += hash_64[1907];
	hash_64[1908] += hash_64[1909]; hash_64[1910] += hash_64[1911];
	hash_64[1912] += hash_64[1913]; hash_64[1914] += hash_64[1915];
	hash_64[1916] += hash_64[1917]; hash_64[1918] += hash_64[1919];
	hash_64[1904] += hash_64[1906]; hash_64[1908] += hash_64[1910];
	hash_64[1912] += hash_64[1914]; hash_64[1916] += hash_64[1918];
#endif
#if MEMORY_THREADS > 120
	hash_64[1920] += hash_64[1921]; hash_64[1922] += hash_64[1923];
	hash_64[1924] += hash_64[1925]; hash_64[1926] += hash_64[1927];
	hash_64[1928] += hash_64[1929]; hash_64[1930] += hash_64[1931];
	hash_64[1932] += hash_64[1933]; hash_64[1934] += hash_64[1935];
	hash_64[1920] += hash_64[1922]; hash_64[1924] += hash_64[1926];
	hash_64[1928] += hash_64[1930]; hash_64[1932] += hash_64[1934];
#endif
#if MEMORY_THREADS > 121
	hash_64[1936] += hash_64[1937]; hash_64[1938] += hash_64[1939];
	hash_64[1940] += hash_64[1941]; hash_64[1942] += hash_64[1943];
	hash_64[1944] += hash_64[1945]; hash_64[1946] += hash_64[1947];
	hash_64[1948] += hash_64[1949]; hash_64[1950] += hash_64[1951];
	hash_64[1936] += hash_64[1938]; hash_64[1940] += hash_64[1942];
	hash_64[1944] += hash_64[1946]; hash_64[1948] += hash_64[1950];
#endif
#if MEMORY_THREADS > 122
	hash_64[1952] += hash_64[1953]; hash_64[1954] += hash_64[1955];
	hash_64[1956] += hash_64[1957]; hash_64[1958] += hash_64[1959];
	hash_64[1960] += hash_64[1961]; hash_64[1962] += hash_64[1963];
	hash_64[1964] += hash_64[1965]; hash_64[1966] += hash_64[1967];
	hash_64[1952] += hash_64[1954]; hash_64[1956] += hash_64[1958];
	hash_64[1960] += hash_64[1962]; hash_64[1964] += hash_64[1966];
#endif
#if MEMORY_THREADS > 123
	hash_64[1968] += hash_64[1969]; hash_64[1970] += hash_64[1971];
	hash_64[1972] += hash_64[1973]; hash_64[1974] += hash_64[1975];
	hash_64[1976] += hash_64[1977]; hash_64[1978] += hash_64[1979];
	hash_64[1980] += hash_64[1981]; hash_64[1982] += hash_64[1983];
	hash_64[1968] += hash_64[1970]; hash_64[1972] += hash_64[1974];
	hash_64[1976] += hash_64[1978]; hash_64[1980] += hash_64[1982];
#endif
#if MEMORY_THREADS > 124
	hash_64[1984] += hash_64[1985]; hash_64[1986] += hash_64[1987];
	hash_64[1988] += hash_64[1989]; hash_64[1990] += hash_64[1991];
	hash_64[1992] += hash_64[1993]; hash_64[1994] += hash_64[1995];
	hash_64[1996] += hash_64[1997]; hash_64[1998] += hash_64[1999];
	hash_64[1984] += hash_64[1986]; hash_64[1988] += hash_64[1990];
	hash_64[1992] += hash_64[1994]; hash_64[1996] += hash_64[1998];
#endif
#if MEMORY_THREADS > 125
	hash_64[2000] += hash_64[2001]; hash_64[2002] += hash_64[2003];
	hash_64[2004] += hash_64[2005]; hash_64[2006] += hash_64[2007];
	hash_64[2008] += hash_64[2009]; hash_64[2010] += hash_64[2011];
	hash_64[2012] += hash_64[2013]; hash_64[2014] += hash_64[2015];
	hash_64[2000] += hash_64[2002]; hash_64[2004] += hash_64[2006];
	hash_64[2008] += hash_64[2010]; hash_64[2012] += hash_64[2014];
#endif
#if MEMORY_THREADS > 126
	hash_64[2016] += hash_64[2017]; hash_64[2018] += hash_64[2019];
	hash_64[2020] += hash_64[2021]; hash_64[2022] += hash_64[2023];
	hash_64[2024] += hash_64[2025]; hash_64[2026] += hash_64[2027];
	hash_64[2028] += hash_64[2029]; hash_64[2030] += hash_64[2031];
	hash_64[2016] += hash_64[2018]; hash_64[2020] += hash_64[2022];
	hash_64[2024] += hash_64[2026]; hash_64[2028] += hash_64[2030];
#endif
#if MEMORY_THREADS > 127
	hash_64[2032] += hash_64[2033]; hash_64[2034] += hash_64[2035];
	hash_64[2036] += hash_64[2037]; hash_64[2038] += hash_64[2039];
	hash_64[2040] += hash_64[2041]; hash_64[2042] += hash_64[2043];
	hash_64[2044] += hash_64[2045]; hash_64[2046] += hash_64[2047];
	hash_64[2032] += hash_64[2034]; hash_64[2036] += hash_64[2038];
	hash_64[2040] += hash_64[2042]; hash_64[2044] += hash_64[2046];
#endif
#if MEMORY_THREADS > 128
	hash_64[2048] += hash_64[2049]; hash_64[2050] += hash_64[2051];
	hash_64[2052] += hash_64[2053]; hash_64[2054] += hash_64[2055];
	hash_64[2056] += hash_64[2057]; hash_64[2058] += hash_64[2059];
	hash_64[2060] += hash_64[2061]; hash_64[2062] += hash_64[2063];
	hash_64[2048] += hash_64[2050]; hash_64[2052] += hash_64[2054];
	hash_64[2056] += hash_64[2058]; hash_64[2060] += hash_64[2062];
#endif
#if MEMORY_THREADS > 129
	hash_64[2064] += hash_64[2065]; hash_64[2066] += hash_64[2067];
	hash_64[2068] += hash_64[2069]; hash_64[2070] += hash_64[2071];
	hash_64[2072] += hash_64[2073]; hash_64[2074] += hash_64[2075];
	hash_64[2076] += hash_64[2077]; hash_64[2078] += hash_64[2079];
	hash_64[2064] += hash_64[2066]; hash_64[2068] += hash_64[2070];
	hash_64[2072] += hash_64[2074]; hash_64[2076] += hash_64[2078];
#endif
#if MEMORY_THREADS > 130
	hash_64[2080] += hash_64[2081]; hash_64[2082] += hash_64[2083];
	hash_64[2084] += hash_64[2085]; hash_64[2086] += hash_64[2087];
	hash_64[2088] += hash_64[2089]; hash_64[2090] += hash_64[2091];
	hash_64[2092] += hash_64[2093]; hash_64[2094] += hash_64[2095];
	hash_64[2080] += hash_64[2082]; hash_64[2084] += hash_64[2086];
	hash_64[2088] += hash_64[2090]; hash_64[2092] += hash_64[2094];
#endif
#if MEMORY_THREADS > 131
	hash_64[2096] += hash_64[2097]; hash_64[2098] += hash_64[2099];
	hash_64[2100] += hash_64[2101]; hash_64[2102] += hash_64[2103];
	hash_64[2104] += hash_64[2105]; hash_64[2106] += hash_64[2107];
	hash_64[2108] += hash_64[2109]; hash_64[2110] += hash_64[2111];
	hash_64[2096] += hash_64[2098]; hash_64[2100] += hash_64[2102];
	hash_64[2104] += hash_64[2106]; hash_64[2108] += hash_64[2110];
#endif
#if MEMORY_THREADS > 132
	hash_64[2112] += hash_64[2113]; hash_64[2114] += hash_64[2115];
	hash_64[2116] += hash_64[2117]; hash_64[2118] += hash_64[2119];
	hash_64[2120] += hash_64[2121]; hash_64[2122] += hash_64[2123];
	hash_64[2124] += hash_64[2125]; hash_64[2126] += hash_64[2127];
	hash_64[2112] += hash_64[2114]; hash_64[2116] += hash_64[2118];
	hash_64[2120] += hash_64[2122]; hash_64[2124] += hash_64[2126];
#endif
#if MEMORY_THREADS > 133
	hash_64[2128] += hash_64[2129]; hash_64[2130] += hash_64[2131];
	hash_64[2132] += hash_64[2133]; hash_64[2134] += hash_64[2135];
	hash_64[2136] += hash_64[2137]; hash_64[2138] += hash_64[2139];
	hash_64[2140] += hash_64[2141]; hash_64[2142] += hash_64[2143];
	hash_64[2128] += hash_64[2130]; hash_64[2132] += hash_64[2134];
	hash_64[2136] += hash_64[2138]; hash_64[2140] += hash_64[2142];
#endif
#if MEMORY_THREADS > 134
	hash_64[2144] += hash_64[2145]; hash_64[2146] += hash_64[2147];
	hash_64[2148] += hash_64[2149]; hash_64[2150] += hash_64[2151];
	hash_64[2152] += hash_64[2153]; hash_64[2154] += hash_64[2155];
	hash_64[2156] += hash_64[2157]; hash_64[2158] += hash_64[2159];
	hash_64[2144] += hash_64[2146]; hash_64[2148] += hash_64[2150];
	hash_64[2152] += hash_64[2154]; hash_64[2156] += hash_64[2158];
#endif
#if MEMORY_THREADS > 135
	hash_64[2160] += hash_64[2161]; hash_64[2162] += hash_64[2163];
	hash_64[2164] += hash_64[2165]; hash_64[2166] += hash_64[2167];
	hash_64[2168] += hash_64[2169]; hash_64[2170] += hash_64[2171];
	hash_64[2172] += hash_64[2173]; hash_64[2174] += hash_64[2175];
	hash_64[2160] += hash_64[2162]; hash_64[2164] += hash_64[2166];
	hash_64[2168] += hash_64[2170]; hash_64[2172] += hash_64[2174];
#endif
#if MEMORY_THREADS > 136
	hash_64[2176] += hash_64[2177]; hash_64[2178] += hash_64[2179];
	hash_64[2180] += hash_64[2181]; hash_64[2182] += hash_64[2183];
	hash_64[2184] += hash_64[2185]; hash_64[2186] += hash_64[2187];
	hash_64[2188] += hash_64[2189]; hash_64[2190] += hash_64[2191];
	hash_64[2176] += hash_64[2178]; hash_64[2180] += hash_64[2182];
	hash_64[2184] += hash_64[2186]; hash_64[2188] += hash_64[2190];
#endif
#if MEMORY_THREADS > 137
	hash_64[2192] += hash_64[2193]; hash_64[2194] += hash_64[2195];
	hash_64[2196] += hash_64[2197]; hash_64[2198] += hash_64[2199];
	hash_64[2200] += hash_64[2201]; hash_64[2202] += hash_64[2203];
	hash_64[2204] += hash_64[2205]; hash_64[2206] += hash_64[2207];
	hash_64[2192] += hash_64[2194]; hash_64[2196] += hash_64[2198];
	hash_64[2200] += hash_64[2202]; hash_64[2204] += hash_64[2206];
#endif
#if MEMORY_THREADS > 138
	hash_64[2208] += hash_64[2209]; hash_64[2210] += hash_64[2211];
	hash_64[2212] += hash_64[2213]; hash_64[2214] += hash_64[2215];
	hash_64[2216] += hash_64[2217]; hash_64[2218] += hash_64[2219];
	hash_64[2220] += hash_64[2221]; hash_64[2222] += hash_64[2223];
	hash_64[2208] += hash_64[2210]; hash_64[2212] += hash_64[2214];
	hash_64[2216] += hash_64[2218]; hash_64[2220] += hash_64[2222];
#endif
#if MEMORY_THREADS > 139
	hash_64[2224] += hash_64[2225]; hash_64[2226] += hash_64[2227];
	hash_64[2228] += hash_64[2229]; hash_64[2230] += hash_64[2231];
	hash_64[2232] += hash_64[2233]; hash_64[2234] += hash_64[2235];
	hash_64[2236] += hash_64[2237]; hash_64[2238] += hash_64[2239];
	hash_64[2224] += hash_64[2226]; hash_64[2228] += hash_64[2230];
	hash_64[2232] += hash_64[2234]; hash_64[2236] += hash_64[2238];
#endif
#if MEMORY_THREADS > 140
	hash_64[2240] += hash_64[2241]; hash_64[2242] += hash_64[2243];
	hash_64[2244] += hash_64[2245]; hash_64[2246] += hash_64[2247];
	hash_64[2248] += hash_64[2249]; hash_64[2250] += hash_64[2251];
	hash_64[2252] += hash_64[2253]; hash_64[2254] += hash_64[2255];
	hash_64[2240] += hash_64[2242]; hash_64[2244] += hash_64[2246];
	hash_64[2248] += hash_64[2250]; hash_64[2252] += hash_64[2254];
#endif
#if MEMORY_THREADS > 141
	hash_64[2256] += hash_64[2257]; hash_64[2258] += hash_64[2259];
	hash_64[2260] += hash_64[2261]; hash_64[2262] += hash_64[2263];
	hash_64[2264] += hash_64[2265]; hash_64[2266] += hash_64[2267];
	hash_64[2268] += hash_64[2269]; hash_64[2270] += hash_64[2271];
	hash_64[2256] += hash_64[2258]; hash_64[2260] += hash_64[2262];
	hash_64[2264] += hash_64[2266]; hash_64[2268] += hash_64[2270];
#endif
#if MEMORY_THREADS > 142
	hash_64[2272] += hash_64[2273]; hash_64[2274] += hash_64[2275];
	hash_64[2276] += hash_64[2277]; hash_64[2278] += hash_64[2279];
	hash_64[2280] += hash_64[2281]; hash_64[2282] += hash_64[2283];
	hash_64[2284] += hash_64[2285]; hash_64[2286] += hash_64[2287];
	hash_64[2272] += hash_64[2274]; hash_64[2276] += hash_64[2278];
	hash_64[2280] += hash_64[2282]; hash_64[2284] += hash_64[2286];
#endif
#if MEMORY_THREADS > 143
	hash_64[2288] += hash_64[2289]; hash_64[2290] += hash_64[2291];
	hash_64[2292] += hash_64[2293]; hash_64[2294] += hash_64[2295];
	hash_64[2296] += hash_64[2297]; hash_64[2298] += hash_64[2299];
	hash_64[2300] += hash_64[2301]; hash_64[2302] += hash_64[2303];
	hash_64[2288] += hash_64[2290]; hash_64[2292] += hash_64[2294];
	hash_64[2296] += hash_64[2298]; hash_64[2300] += hash_64[2302];
#endif
#if MEMORY_THREADS > 144
	hash_64[2304] += hash_64[2305]; hash_64[2306] += hash_64[2307];
	hash_64[2308] += hash_64[2309]; hash_64[2310] += hash_64[2311];
	hash_64[2312] += hash_64[2313]; hash_64[2314] += hash_64[2315];
	hash_64[2316] += hash_64[2317]; hash_64[2318] += hash_64[2319];
	hash_64[2304] += hash_64[2306]; hash_64[2308] += hash_64[2310];
	hash_64[2312] += hash_64[2314]; hash_64[2316] += hash_64[2318];
#endif
#if MEMORY_THREADS > 145
	hash_64[2320] += hash_64[2321]; hash_64[2322] += hash_64[2323];
	hash_64[2324] += hash_64[2325]; hash_64[2326] += hash_64[2327];
	hash_64[2328] += hash_64[2329]; hash_64[2330] += hash_64[2331];
	hash_64[2332] += hash_64[2333]; hash_64[2334] += hash_64[2335];
	hash_64[2320] += hash_64[2322]; hash_64[2324] += hash_64[2326];
	hash_64[2328] += hash_64[2330]; hash_64[2332] += hash_64[2334];
#endif
#if MEMORY_THREADS > 146
	hash_64[2336] += hash_64[2337]; hash_64[2338] += hash_64[2339];
	hash_64[2340] += hash_64[2341]; hash_64[2342] += hash_64[2343];
	hash_64[2344] += hash_64[2345]; hash_64[2346] += hash_64[2347];
	hash_64[2348] += hash_64[2349]; hash_64[2350] += hash_64[2351];
	hash_64[2336] += hash_64[2338]; hash_64[2340] += hash_64[2342];
	hash_64[2344] += hash_64[2346]; hash_64[2348] += hash_64[2350];
#endif
#if MEMORY_THREADS > 147
	hash_64[2352] += hash_64[2353]; hash_64[2354] += hash_64[2355];
	hash_64[2356] += hash_64[2357]; hash_64[2358] += hash_64[2359];
	hash_64[2360] += hash_64[2361]; hash_64[2362] += hash_64[2363];
	hash_64[2364] += hash_64[2365]; hash_64[2366] += hash_64[2367];
	hash_64[2352] += hash_64[2354]; hash_64[2356] += hash_64[2358];
	hash_64[2360] += hash_64[2362]; hash_64[2364] += hash_64[2366];
#endif
#if MEMORY_THREADS > 148
	hash_64[2368] += hash_64[2369]; hash_64[2370] += hash_64[2371];
	hash_64[2372] += hash_64[2373]; hash_64[2374] += hash_64[2375];
	hash_64[2376] += hash_64[2377]; hash_64[2378] += hash_64[2379];
	hash_64[2380] += hash_64[2381]; hash_64[2382] += hash_64[2383];
	hash_64[2368] += hash_64[2370]; hash_64[2372] += hash_64[2374];
	hash_64[2376] += hash_64[2378]; hash_64[2380] += hash_64[2382];
#endif
#if MEMORY_THREADS > 149
	hash_64[2384] += hash_64[2385]; hash_64[2386] += hash_64[2387];
	hash_64[2388] += hash_64[2389]; hash_64[2390] += hash_64[2391];
	hash_64[2392] += hash_64[2393]; hash_64[2394] += hash_64[2395];
	hash_64[2396] += hash_64[2397]; hash_64[2398] += hash_64[2399];
	hash_64[2384] += hash_64[2386]; hash_64[2388] += hash_64[2390];
	hash_64[2392] += hash_64[2394]; hash_64[2396] += hash_64[2398];
#endif
#if MEMORY_THREADS > 150
	hash_64[2400] += hash_64[2401]; hash_64[2402] += hash_64[2403];
	hash_64[2404] += hash_64[2405]; hash_64[2406] += hash_64[2407];
	hash_64[2408] += hash_64[2409]; hash_64[2410] += hash_64[2411];
	hash_64[2412] += hash_64[2413]; hash_64[2414] += hash_64[2415];
	hash_64[2400] += hash_64[2402]; hash_64[2404] += hash_64[2406];
	hash_64[2408] += hash_64[2410]; hash_64[2412] += hash_64[2414];
#endif
#if MEMORY_THREADS > 151
	hash_64[2416] += hash_64[2417]; hash_64[2418] += hash_64[2419];
	hash_64[2420] += hash_64[2421]; hash_64[2422] += hash_64[2423];
	hash_64[2424] += hash_64[2425]; hash_64[2426] += hash_64[2427];
	hash_64[2428] += hash_64[2429]; hash_64[2430] += hash_64[2431];
	hash_64[2416] += hash_64[2418]; hash_64[2420] += hash_64[2422];
	hash_64[2424] += hash_64[2426]; hash_64[2428] += hash_64[2430];
#endif
#if MEMORY_THREADS > 152
	hash_64[2432] += hash_64[2433]; hash_64[2434] += hash_64[2435];
	hash_64[2436] += hash_64[2437]; hash_64[2438] += hash_64[2439];
	hash_64[2440] += hash_64[2441]; hash_64[2442] += hash_64[2443];
	hash_64[2444] += hash_64[2445]; hash_64[2446] += hash_64[2447];
	hash_64[2432] += hash_64[2434]; hash_64[2436] += hash_64[2438];
	hash_64[2440] += hash_64[2442]; hash_64[2444] += hash_64[2446];
#endif
#if MEMORY_THREADS > 153
	hash_64[2448] += hash_64[2449]; hash_64[2450] += hash_64[2451];
	hash_64[2452] += hash_64[2453]; hash_64[2454] += hash_64[2455];
	hash_64[2456] += hash_64[2457]; hash_64[2458] += hash_64[2459];
	hash_64[2460] += hash_64[2461]; hash_64[2462] += hash_64[2463];
	hash_64[2448] += hash_64[2450]; hash_64[2452] += hash_64[2454];
	hash_64[2456] += hash_64[2458]; hash_64[2460] += hash_64[2462];
#endif
#if MEMORY_THREADS > 154
	hash_64[2464] += hash_64[2465]; hash_64[2466] += hash_64[2467];
	hash_64[2468] += hash_64[2469]; hash_64[2470] += hash_64[2471];
	hash_64[2472] += hash_64[2473]; hash_64[2474] += hash_64[2475];
	hash_64[2476] += hash_64[2477]; hash_64[2478] += hash_64[2479];
	hash_64[2464] += hash_64[2466]; hash_64[2468] += hash_64[2470];
	hash_64[2472] += hash_64[2474]; hash_64[2476] += hash_64[2478];
#endif
#if MEMORY_THREADS > 155
	hash_64[2480] += hash_64[2481]; hash_64[2482] += hash_64[2483];
	hash_64[2484] += hash_64[2485]; hash_64[2486] += hash_64[2487];
	hash_64[2488] += hash_64[2489]; hash_64[2490] += hash_64[2491];
	hash_64[2492] += hash_64[2493]; hash_64[2494] += hash_64[2495];
	hash_64[2480] += hash_64[2482]; hash_64[2484] += hash_64[2486];
	hash_64[2488] += hash_64[2490]; hash_64[2492] += hash_64[2494];
#endif
#if MEMORY_THREADS > 156
	hash_64[2496] += hash_64[2497]; hash_64[2498] += hash_64[2499];
	hash_64[2500] += hash_64[2501]; hash_64[2502] += hash_64[2503];
	hash_64[2504] += hash_64[2505]; hash_64[2506] += hash_64[2507];
	hash_64[2508] += hash_64[2509]; hash_64[2510] += hash_64[2511];
	hash_64[2496] += hash_64[2498]; hash_64[2500] += hash_64[2502];
	hash_64[2504] += hash_64[2506]; hash_64[2508] += hash_64[2510];
#endif
#if MEMORY_THREADS > 157
	hash_64[2512] += hash_64[2513]; hash_64[2514] += hash_64[2515];
	hash_64[2516] += hash_64[2517]; hash_64[2518] += hash_64[2519];
	hash_64[2520] += hash_64[2521]; hash_64[2522] += hash_64[2523];
	hash_64[2524] += hash_64[2525]; hash_64[2526] += hash_64[2527];
	hash_64[2512] += hash_64[2514]; hash_64[2516] += hash_64[2518];
	hash_64[2520] += hash_64[2522]; hash_64[2524] += hash_64[2526];
#endif
#if MEMORY_THREADS > 158
	hash_64[2528] += hash_64[2529]; hash_64[2530] += hash_64[2531];
	hash_64[2532] += hash_64[2533]; hash_64[2534] += hash_64[2535];
	hash_64[2536] += hash_64[2537]; hash_64[2538] += hash_64[2539];
	hash_64[2540] += hash_64[2541]; hash_64[2542] += hash_64[2543];
	hash_64[2528] += hash_64[2530]; hash_64[2532] += hash_64[2534];
	hash_64[2536] += hash_64[2538]; hash_64[2540] += hash_64[2542];
#endif
#if MEMORY_THREADS > 159
	hash_64[2544] += hash_64[2545]; hash_64[2546] += hash_64[2547];
	hash_64[2548] += hash_64[2549]; hash_64[2550] += hash_64[2551];
	hash_64[2552] += hash_64[2553]; hash_64[2554] += hash_64[2555];
	hash_64[2556] += hash_64[2557]; hash_64[2558] += hash_64[2559];
	hash_64[2544] += hash_64[2546]; hash_64[2548] += hash_64[2550];
	hash_64[2552] += hash_64[2554]; hash_64[2556] += hash_64[2558];
#endif
#if MEMORY_THREADS > 160
	hash_64[2560] += hash_64[2561]; hash_64[2562] += hash_64[2563];
	hash_64[2564] += hash_64[2565]; hash_64[2566] += hash_64[2567];
	hash_64[2568] += hash_64[2569]; hash_64[2570] += hash_64[2571];
	hash_64[2572] += hash_64[2573]; hash_64[2574] += hash_64[2575];
	hash_64[2560] += hash_64[2562]; hash_64[2564] += hash_64[2566];
	hash_64[2568] += hash_64[2570]; hash_64[2572] += hash_64[2574];
#endif
#if MEMORY_THREADS > 161
	hash_64[2576] += hash_64[2577]; hash_64[2578] += hash_64[2579];
	hash_64[2580] += hash_64[2581]; hash_64[2582] += hash_64[2583];
	hash_64[2584] += hash_64[2585]; hash_64[2586] += hash_64[2587];
	hash_64[2588] += hash_64[2589]; hash_64[2590] += hash_64[2591];
	hash_64[2576] += hash_64[2578]; hash_64[2580] += hash_64[2582];
	hash_64[2584] += hash_64[2586]; hash_64[2588] += hash_64[2590];
#endif
#if MEMORY_THREADS > 162
	hash_64[2592] += hash_64[2593]; hash_64[2594] += hash_64[2595];
	hash_64[2596] += hash_64[2597]; hash_64[2598] += hash_64[2599];
	hash_64[2600] += hash_64[2601]; hash_64[2602] += hash_64[2603];
	hash_64[2604] += hash_64[2605]; hash_64[2606] += hash_64[2607];
	hash_64[2592] += hash_64[2594]; hash_64[2596] += hash_64[2598];
	hash_64[2600] += hash_64[2602]; hash_64[2604] += hash_64[2606];
#endif
#if MEMORY_THREADS > 163
	hash_64[2608] += hash_64[2609]; hash_64[2610] += hash_64[2611];
	hash_64[2612] += hash_64[2613]; hash_64[2614] += hash_64[2615];
	hash_64[2616] += hash_64[2617]; hash_64[2618] += hash_64[2619];
	hash_64[2620] += hash_64[2621]; hash_64[2622] += hash_64[2623];
	hash_64[2608] += hash_64[2610]; hash_64[2612] += hash_64[2614];
	hash_64[2616] += hash_64[2618]; hash_64[2620] += hash_64[2622];
#endif
#if MEMORY_THREADS > 164
	hash_64[2624] += hash_64[2625]; hash_64[2626] += hash_64[2627];
	hash_64[2628] += hash_64[2629]; hash_64[2630] += hash_64[2631];
	hash_64[2632] += hash_64[2633]; hash_64[2634] += hash_64[2635];
	hash_64[2636] += hash_64[2637]; hash_64[2638] += hash_64[2639];
	hash_64[2624] += hash_64[2626]; hash_64[2628] += hash_64[2630];
	hash_64[2632] += hash_64[2634]; hash_64[2636] += hash_64[2638];
#endif
#if MEMORY_THREADS > 165
	hash_64[2640] += hash_64[2641]; hash_64[2642] += hash_64[2643];
	hash_64[2644] += hash_64[2645]; hash_64[2646] += hash_64[2647];
	hash_64[2648] += hash_64[2649]; hash_64[2650] += hash_64[2651];
	hash_64[2652] += hash_64[2653]; hash_64[2654] += hash_64[2655];
	hash_64[2640] += hash_64[2642]; hash_64[2644] += hash_64[2646];
	hash_64[2648] += hash_64[2650]; hash_64[2652] += hash_64[2654];
#endif
#if MEMORY_THREADS > 166
	hash_64[2656] += hash_64[2657]; hash_64[2658] += hash_64[2659];
	hash_64[2660] += hash_64[2661]; hash_64[2662] += hash_64[2663];
	hash_64[2664] += hash_64[2665]; hash_64[2666] += hash_64[2667];
	hash_64[2668] += hash_64[2669]; hash_64[2670] += hash_64[2671];
	hash_64[2656] += hash_64[2658]; hash_64[2660] += hash_64[2662];
	hash_64[2664] += hash_64[2666]; hash_64[2668] += hash_64[2670];
#endif
#if MEMORY_THREADS > 167
	hash_64[2672] += hash_64[2673]; hash_64[2674] += hash_64[2675];
	hash_64[2676] += hash_64[2677]; hash_64[2678] += hash_64[2679];
	hash_64[2680] += hash_64[2681]; hash_64[2682] += hash_64[2683];
	hash_64[2684] += hash_64[2685]; hash_64[2686] += hash_64[2687];
	hash_64[2672] += hash_64[2674]; hash_64[2676] += hash_64[2678];
	hash_64[2680] += hash_64[2682]; hash_64[2684] += hash_64[2686];
#endif
#if MEMORY_THREADS > 168
	hash_64[2688] += hash_64[2689]; hash_64[2690] += hash_64[2691];
	hash_64[2692] += hash_64[2693]; hash_64[2694] += hash_64[2695];
	hash_64[2696] += hash_64[2697]; hash_64[2698] += hash_64[2699];
	hash_64[2700] += hash_64[2701]; hash_64[2702] += hash_64[2703];
	hash_64[2688] += hash_64[2690]; hash_64[2692] += hash_64[2694];
	hash_64[2696] += hash_64[2698]; hash_64[2700] += hash_64[2702];
#endif
#if MEMORY_THREADS > 169
	hash_64[2704] += hash_64[2705]; hash_64[2706] += hash_64[2707];
	hash_64[2708] += hash_64[2709]; hash_64[2710] += hash_64[2711];
	hash_64[2712] += hash_64[2713]; hash_64[2714] += hash_64[2715];
	hash_64[2716] += hash_64[2717]; hash_64[2718] += hash_64[2719];
	hash_64[2704] += hash_64[2706]; hash_64[2708] += hash_64[2710];
	hash_64[2712] += hash_64[2714]; hash_64[2716] += hash_64[2718];
#endif
#if MEMORY_THREADS > 170
	hash_64[2720] += hash_64[2721]; hash_64[2722] += hash_64[2723];
	hash_64[2724] += hash_64[2725]; hash_64[2726] += hash_64[2727];
	hash_64[2728] += hash_64[2729]; hash_64[2730] += hash_64[2731];
	hash_64[2732] += hash_64[2733]; hash_64[2734] += hash_64[2735];
	hash_64[2720] += hash_64[2722]; hash_64[2724] += hash_64[2726];
	hash_64[2728] += hash_64[2730]; hash_64[2732] += hash_64[2734];
#endif
#if MEMORY_THREADS > 171
	hash_64[2736] += hash_64[2737]; hash_64[2738] += hash_64[2739];
	hash_64[2740] += hash_64[2741]; hash_64[2742] += hash_64[2743];
	hash_64[2744] += hash_64[2745]; hash_64[2746] += hash_64[2747];
	hash_64[2748] += hash_64[2749]; hash_64[2750] += hash_64[2751];
	hash_64[2736] += hash_64[2738]; hash_64[2740] += hash_64[2742];
	hash_64[2744] += hash_64[2746]; hash_64[2748] += hash_64[2750];
#endif
#if MEMORY_THREADS > 172
	hash_64[2752] += hash_64[2753]; hash_64[2754] += hash_64[2755];
	hash_64[2756] += hash_64[2757]; hash_64[2758] += hash_64[2759];
	hash_64[2760] += hash_64[2761]; hash_64[2762] += hash_64[2763];
	hash_64[2764] += hash_64[2765]; hash_64[2766] += hash_64[2767];
	hash_64[2752] += hash_64[2754]; hash_64[2756] += hash_64[2758];
	hash_64[2760] += hash_64[2762]; hash_64[2764] += hash_64[2766];
#endif
#if MEMORY_THREADS > 173
	hash_64[2768] += hash_64[2769]; hash_64[2770] += hash_64[2771];
	hash_64[2772] += hash_64[2773]; hash_64[2774] += hash_64[2775];
	hash_64[2776] += hash_64[2777]; hash_64[2778] += hash_64[2779];
	hash_64[2780] += hash_64[2781]; hash_64[2782] += hash_64[2783];
	hash_64[2768] += hash_64[2770]; hash_64[2772] += hash_64[2774];
	hash_64[2776] += hash_64[2778]; hash_64[2780] += hash_64[2782];
#endif
#if MEMORY_THREADS > 174
	hash_64[2784] += hash_64[2785]; hash_64[2786] += hash_64[2787];
	hash_64[2788] += hash_64[2789]; hash_64[2790] += hash_64[2791];
	hash_64[2792] += hash_64[2793]; hash_64[2794] += hash_64[2795];
	hash_64[2796] += hash_64[2797]; hash_64[2798] += hash_64[2799];
	hash_64[2784] += hash_64[2786]; hash_64[2788] += hash_64[2790];
	hash_64[2792] += hash_64[2794]; hash_64[2796] += hash_64[2798];
#endif
#if MEMORY_THREADS > 175
	hash_64[2800] += hash_64[2801]; hash_64[2802] += hash_64[2803];
	hash_64[2804] += hash_64[2805]; hash_64[2806] += hash_64[2807];
	hash_64[2808] += hash_64[2809]; hash_64[2810] += hash_64[2811];
	hash_64[2812] += hash_64[2813]; hash_64[2814] += hash_64[2815];
	hash_64[2800] += hash_64[2802]; hash_64[2804] += hash_64[2806];
	hash_64[2808] += hash_64[2810]; hash_64[2812] += hash_64[2814];
#endif
#if MEMORY_THREADS > 176
	hash_64[2816] += hash_64[2817]; hash_64[2818] += hash_64[2819];
	hash_64[2820] += hash_64[2821]; hash_64[2822] += hash_64[2823];
	hash_64[2824] += hash_64[2825]; hash_64[2826] += hash_64[2827];
	hash_64[2828] += hash_64[2829]; hash_64[2830] += hash_64[2831];
	hash_64[2816] += hash_64[2818]; hash_64[2820] += hash_64[2822];
	hash_64[2824] += hash_64[2826]; hash_64[2828] += hash_64[2830];
#endif
#if MEMORY_THREADS > 177
	hash_64[2832] += hash_64[2833]; hash_64[2834] += hash_64[2835];
	hash_64[2836] += hash_64[2837]; hash_64[2838] += hash_64[2839];
	hash_64[2840] += hash_64[2841]; hash_64[2842] += hash_64[2843];
	hash_64[2844] += hash_64[2845]; hash_64[2846] += hash_64[2847];
	hash_64[2832] += hash_64[2834]; hash_64[2836] += hash_64[2838];
	hash_64[2840] += hash_64[2842]; hash_64[2844] += hash_64[2846];
#endif
#if MEMORY_THREADS > 178
	hash_64[2848] += hash_64[2849]; hash_64[2850] += hash_64[2851];
	hash_64[2852] += hash_64[2853]; hash_64[2854] += hash_64[2855];
	hash_64[2856] += hash_64[2857]; hash_64[2858] += hash_64[2859];
	hash_64[2860] += hash_64[2861]; hash_64[2862] += hash_64[2863];
	hash_64[2848] += hash_64[2850]; hash_64[2852] += hash_64[2854];
	hash_64[2856] += hash_64[2858]; hash_64[2860] += hash_64[2862];
#endif
#if MEMORY_THREADS > 179
	hash_64[2864] += hash_64[2865]; hash_64[2866] += hash_64[2867];
	hash_64[2868] += hash_64[2869]; hash_64[2870] += hash_64[2871];
	hash_64[2872] += hash_64[2873]; hash_64[2874] += hash_64[2875];
	hash_64[2876] += hash_64[2877]; hash_64[2878] += hash_64[2879];
	hash_64[2864] += hash_64[2866]; hash_64[2868] += hash_64[2870];
	hash_64[2872] += hash_64[2874]; hash_64[2876] += hash_64[2878];
#endif
#if MEMORY_THREADS > 180
	hash_64[2880] += hash_64[2881]; hash_64[2882] += hash_64[2883];
	hash_64[2884] += hash_64[2885]; hash_64[2886] += hash_64[2887];
	hash_64[2888] += hash_64[2889]; hash_64[2890] += hash_64[2891];
	hash_64[2892] += hash_64[2893]; hash_64[2894] += hash_64[2895];
	hash_64[2880] += hash_64[2882]; hash_64[2884] += hash_64[2886];
	hash_64[2888] += hash_64[2890]; hash_64[2892] += hash_64[2894];
#endif
#if MEMORY_THREADS > 181
	hash_64[2896] += hash_64[2897]; hash_64[2898] += hash_64[2899];
	hash_64[2900] += hash_64[2901]; hash_64[2902] += hash_64[2903];
	hash_64[2904] += hash_64[2905]; hash_64[2906] += hash_64[2907];
	hash_64[2908] += hash_64[2909]; hash_64[2910] += hash_64[2911];
	hash_64[2896] += hash_64[2898]; hash_64[2900] += hash_64[2902];
	hash_64[2904] += hash_64[2906]; hash_64[2908] += hash_64[2910];
#endif
#if MEMORY_THREADS > 182
	hash_64[2912] += hash_64[2913]; hash_64[2914] += hash_64[2915];
	hash_64[2916] += hash_64[2917]; hash_64[2918] += hash_64[2919];
	hash_64[2920] += hash_64[2921]; hash_64[2922] += hash_64[2923];
	hash_64[2924] += hash_64[2925]; hash_64[2926] += hash_64[2927];
	hash_64[2912] += hash_64[2914]; hash_64[2916] += hash_64[2918];
	hash_64[2920] += hash_64[2922]; hash_64[2924] += hash_64[2926];
#endif
#if MEMORY_THREADS > 183
	hash_64[2928] += hash_64[2929]; hash_64[2930] += hash_64[2931];
	hash_64[2932] += hash_64[2933]; hash_64[2934] += hash_64[2935];
	hash_64[2936] += hash_64[2937]; hash_64[2938] += hash_64[2939];
	hash_64[2940] += hash_64[2941]; hash_64[2942] += hash_64[2943];
	hash_64[2928] += hash_64[2930]; hash_64[2932] += hash_64[2934];
	hash_64[2936] += hash_64[2938]; hash_64[2940] += hash_64[2942];
#endif
#if MEMORY_THREADS > 184
	hash_64[2944] += hash_64[2945]; hash_64[2946] += hash_64[2947];
	hash_64[2948] += hash_64[2949]; hash_64[2950] += hash_64[2951];
	hash_64[2952] += hash_64[2953]; hash_64[2954] += hash_64[2955];
	hash_64[2956] += hash_64[2957]; hash_64[2958] += hash_64[2959];
	hash_64[2944] += hash_64[2946]; hash_64[2948] += hash_64[2950];
	hash_64[2952] += hash_64[2954]; hash_64[2956] += hash_64[2958];
#endif
#if MEMORY_THREADS > 185
	hash_64[2960] += hash_64[2961]; hash_64[2962] += hash_64[2963];
	hash_64[2964] += hash_64[2965]; hash_64[2966] += hash_64[2967];
	hash_64[2968] += hash_64[2969]; hash_64[2970] += hash_64[2971];
	hash_64[2972] += hash_64[2973]; hash_64[2974] += hash_64[2975];
	hash_64[2960] += hash_64[2962]; hash_64[2964] += hash_64[2966];
	hash_64[2968] += hash_64[2970]; hash_64[2972] += hash_64[2974];
#endif
#if MEMORY_THREADS > 186
	hash_64[2976] += hash_64[2977]; hash_64[2978] += hash_64[2979];
	hash_64[2980] += hash_64[2981]; hash_64[2982] += hash_64[2983];
	hash_64[2984] += hash_64[2985]; hash_64[2986] += hash_64[2987];
	hash_64[2988] += hash_64[2989]; hash_64[2990] += hash_64[2991];
	hash_64[2976] += hash_64[2978]; hash_64[2980] += hash_64[2982];
	hash_64[2984] += hash_64[2986]; hash_64[2988] += hash_64[2990];
#endif
#if MEMORY_THREADS > 187
	hash_64[2992] += hash_64[2993]; hash_64[2994] += hash_64[2995];
	hash_64[2996] += hash_64[2997]; hash_64[2998] += hash_64[2999];
	hash_64[3000] += hash_64[3001]; hash_64[3002] += hash_64[3003];
	hash_64[3004] += hash_64[3005]; hash_64[3006] += hash_64[3007];
	hash_64[2992] += hash_64[2994]; hash_64[2996] += hash_64[2998];
	hash_64[3000] += hash_64[3002]; hash_64[3004] += hash_64[3006];
#endif
#if MEMORY_THREADS > 188
	hash_64[3008] += hash_64[3009]; hash_64[3010] += hash_64[3011];
	hash_64[3012] += hash_64[3013]; hash_64[3014] += hash_64[3015];
	hash_64[3016] += hash_64[3017]; hash_64[3018] += hash_64[3019];
	hash_64[3020] += hash_64[3021]; hash_64[3022] += hash_64[3023];
	hash_64[3008] += hash_64[3010]; hash_64[3012] += hash_64[3014];
	hash_64[3016] += hash_64[3018]; hash_64[3020] += hash_64[3022];
#endif
#if MEMORY_THREADS > 189
	hash_64[3024] += hash_64[3025]; hash_64[3026] += hash_64[3027];
	hash_64[3028] += hash_64[3029]; hash_64[3030] += hash_64[3031];
	hash_64[3032] += hash_64[3033]; hash_64[3034] += hash_64[3035];
	hash_64[3036] += hash_64[3037]; hash_64[3038] += hash_64[3039];
	hash_64[3024] += hash_64[3026]; hash_64[3028] += hash_64[3030];
	hash_64[3032] += hash_64[3034]; hash_64[3036] += hash_64[3038];
#endif
#if MEMORY_THREADS > 190
	hash_64[3040] += hash_64[3041]; hash_64[3042] += hash_64[3043];
	hash_64[3044] += hash_64[3045]; hash_64[3046] += hash_64[3047];
	hash_64[3048] += hash_64[3049]; hash_64[3050] += hash_64[3051];
	hash_64[3052] += hash_64[3053]; hash_64[3054] += hash_64[3055];
	hash_64[3040] += hash_64[3042]; hash_64[3044] += hash_64[3046];
	hash_64[3048] += hash_64[3050]; hash_64[3052] += hash_64[3054];
#endif
#if MEMORY_THREADS > 191
	hash_64[3056] += hash_64[3057]; hash_64[3058] += hash_64[3059];
	hash_64[3060] += hash_64[3061]; hash_64[3062] += hash_64[3063];
	hash_64[3064] += hash_64[3065]; hash_64[3066] += hash_64[3067];
	hash_64[3068] += hash_64[3069]; hash_64[3070] += hash_64[3071];
	hash_64[3056] += hash_64[3058]; hash_64[3060] += hash_64[3062];
	hash_64[3064] += hash_64[3066]; hash_64[3068] += hash_64[3070];
#endif
#if MEMORY_THREADS > 192
	hash_64[3072] += hash_64[3073]; hash_64[3074] += hash_64[3075];
	hash_64[3076] += hash_64[3077]; hash_64[3078] += hash_64[3079];
	hash_64[3080] += hash_64[3081]; hash_64[3082] += hash_64[3083];
	hash_64[3084] += hash_64[3085]; hash_64[3086] += hash_64[3087];
	hash_64[3072] += hash_64[3074]; hash_64[3076] += hash_64[3078];
	hash_64[3080] += hash_64[3082]; hash_64[3084] += hash_64[3086];
#endif
#if MEMORY_THREADS > 193
	hash_64[3088] += hash_64[3089]; hash_64[3090] += hash_64[3091];
	hash_64[3092] += hash_64[3093]; hash_64[3094] += hash_64[3095];
	hash_64[3096] += hash_64[3097]; hash_64[3098] += hash_64[3099];
	hash_64[3100] += hash_64[3101]; hash_64[3102] += hash_64[3103];
	hash_64[3088] += hash_64[3090]; hash_64[3092] += hash_64[3094];
	hash_64[3096] += hash_64[3098]; hash_64[3100] += hash_64[3102];
#endif
#if MEMORY_THREADS > 194
	hash_64[3104] += hash_64[3105]; hash_64[3106] += hash_64[3107];
	hash_64[3108] += hash_64[3109]; hash_64[3110] += hash_64[3111];
	hash_64[3112] += hash_64[3113]; hash_64[3114] += hash_64[3115];
	hash_64[3116] += hash_64[3117]; hash_64[3118] += hash_64[3119];
	hash_64[3104] += hash_64[3106]; hash_64[3108] += hash_64[3110];
	hash_64[3112] += hash_64[3114]; hash_64[3116] += hash_64[3118];
#endif
#if MEMORY_THREADS > 195
	hash_64[3120] += hash_64[3121]; hash_64[3122] += hash_64[3123];
	hash_64[3124] += hash_64[3125]; hash_64[3126] += hash_64[3127];
	hash_64[3128] += hash_64[3129]; hash_64[3130] += hash_64[3131];
	hash_64[3132] += hash_64[3133]; hash_64[3134] += hash_64[3135];
	hash_64[3120] += hash_64[3122]; hash_64[3124] += hash_64[3126];
	hash_64[3128] += hash_64[3130]; hash_64[3132] += hash_64[3134];
#endif
#if MEMORY_THREADS > 196
	hash_64[3136] += hash_64[3137]; hash_64[3138] += hash_64[3139];
	hash_64[3140] += hash_64[3141]; hash_64[3142] += hash_64[3143];
	hash_64[3144] += hash_64[3145]; hash_64[3146] += hash_64[3147];
	hash_64[3148] += hash_64[3149]; hash_64[3150] += hash_64[3151];
	hash_64[3136] += hash_64[3138]; hash_64[3140] += hash_64[3142];
	hash_64[3144] += hash_64[3146]; hash_64[3148] += hash_64[3150];
#endif
#if MEMORY_THREADS > 197
	hash_64[3152] += hash_64[3153]; hash_64[3154] += hash_64[3155];
	hash_64[3156] += hash_64[3157]; hash_64[3158] += hash_64[3159];
	hash_64[3160] += hash_64[3161]; hash_64[3162] += hash_64[3163];
	hash_64[3164] += hash_64[3165]; hash_64[3166] += hash_64[3167];
	hash_64[3152] += hash_64[3154]; hash_64[3156] += hash_64[3158];
	hash_64[3160] += hash_64[3162]; hash_64[3164] += hash_64[3166];
#endif
#if MEMORY_THREADS > 198
	hash_64[3168] += hash_64[3169]; hash_64[3170] += hash_64[3171];
	hash_64[3172] += hash_64[3173]; hash_64[3174] += hash_64[3175];
	hash_64[3176] += hash_64[3177]; hash_64[3178] += hash_64[3179];
	hash_64[3180] += hash_64[3181]; hash_64[3182] += hash_64[3183];
	hash_64[3168] += hash_64[3170]; hash_64[3172] += hash_64[3174];
	hash_64[3176] += hash_64[3178]; hash_64[3180] += hash_64[3182];
#endif
#if MEMORY_THREADS > 199
	hash_64[3184] += hash_64[3185]; hash_64[3186] += hash_64[3187];
	hash_64[3188] += hash_64[3189]; hash_64[3190] += hash_64[3191];
	hash_64[3192] += hash_64[3193]; hash_64[3194] += hash_64[3195];
	hash_64[3196] += hash_64[3197]; hash_64[3198] += hash_64[3199];
	hash_64[3184] += hash_64[3186]; hash_64[3188] += hash_64[3190];
	hash_64[3192] += hash_64[3194]; hash_64[3196] += hash_64[3198];
#endif
#if MEMORY_THREADS > 200
	hash_64[3200] += hash_64[3201]; hash_64[3202] += hash_64[3203];
	hash_64[3204] += hash_64[3205]; hash_64[3206] += hash_64[3207];
	hash_64[3208] += hash_64[3209]; hash_64[3210] += hash_64[3211];
	hash_64[3212] += hash_64[3213]; hash_64[3214] += hash_64[3215];
	hash_64[3200] += hash_64[3202]; hash_64[3204] += hash_64[3206];
	hash_64[3208] += hash_64[3210]; hash_64[3212] += hash_64[3214];
#endif
#if MEMORY_THREADS > 201
	hash_64[3216] += hash_64[3217]; hash_64[3218] += hash_64[3219];
	hash_64[3220] += hash_64[3221]; hash_64[3222] += hash_64[3223];
	hash_64[3224] += hash_64[3225]; hash_64[3226] += hash_64[3227];
	hash_64[3228] += hash_64[3229]; hash_64[3230] += hash_64[3231];
	hash_64[3216] += hash_64[3218]; hash_64[3220] += hash_64[3222];
	hash_64[3224] += hash_64[3226]; hash_64[3228] += hash_64[3230];
#endif
#if MEMORY_THREADS > 202
	hash_64[3232] += hash_64[3233]; hash_64[3234] += hash_64[3235];
	hash_64[3236] += hash_64[3237]; hash_64[3238] += hash_64[3239];
	hash_64[3240] += hash_64[3241]; hash_64[3242] += hash_64[3243];
	hash_64[3244] += hash_64[3245]; hash_64[3246] += hash_64[3247];
	hash_64[3232] += hash_64[3234]; hash_64[3236] += hash_64[3238];
	hash_64[3240] += hash_64[3242]; hash_64[3244] += hash_64[3246];
#endif
#if MEMORY_THREADS > 203
	hash_64[3248] += hash_64[3249]; hash_64[3250] += hash_64[3251];
	hash_64[3252] += hash_64[3253]; hash_64[3254] += hash_64[3255];
	hash_64[3256] += hash_64[3257]; hash_64[3258] += hash_64[3259];
	hash_64[3260] += hash_64[3261]; hash_64[3262] += hash_64[3263];
	hash_64[3248] += hash_64[3250]; hash_64[3252] += hash_64[3254];
	hash_64[3256] += hash_64[3258]; hash_64[3260] += hash_64[3262];
#endif
#if MEMORY_THREADS > 204
	hash_64[3264] += hash_64[3265]; hash_64[3266] += hash_64[3267];
	hash_64[3268] += hash_64[3269]; hash_64[3270] += hash_64[3271];
	hash_64[3272] += hash_64[3273]; hash_64[3274] += hash_64[3275];
	hash_64[3276] += hash_64[3277]; hash_64[3278] += hash_64[3279];
	hash_64[3264] += hash_64[3266]; hash_64[3268] += hash_64[3270];
	hash_64[3272] += hash_64[3274]; hash_64[3276] += hash_64[3278];
#endif
#if MEMORY_THREADS > 205
	hash_64[3280] += hash_64[3281]; hash_64[3282] += hash_64[3283];
	hash_64[3284] += hash_64[3285]; hash_64[3286] += hash_64[3287];
	hash_64[3288] += hash_64[3289]; hash_64[3290] += hash_64[3291];
	hash_64[3292] += hash_64[3293]; hash_64[3294] += hash_64[3295];
	hash_64[3280] += hash_64[3282]; hash_64[3284] += hash_64[3286];
	hash_64[3288] += hash_64[3290]; hash_64[3292] += hash_64[3294];
#endif
#if MEMORY_THREADS > 206
	hash_64[3296] += hash_64[3297]; hash_64[3298] += hash_64[3299];
	hash_64[3300] += hash_64[3301]; hash_64[3302] += hash_64[3303];
	hash_64[3304] += hash_64[3305]; hash_64[3306] += hash_64[3307];
	hash_64[3308] += hash_64[3309]; hash_64[3310] += hash_64[3311];
	hash_64[3296] += hash_64[3298]; hash_64[3300] += hash_64[3302];
	hash_64[3304] += hash_64[3306]; hash_64[3308] += hash_64[3310];
#endif
#if MEMORY_THREADS > 207
	hash_64[3312] += hash_64[3313]; hash_64[3314] += hash_64[3315];
	hash_64[3316] += hash_64[3317]; hash_64[3318] += hash_64[3319];
	hash_64[3320] += hash_64[3321]; hash_64[3322] += hash_64[3323];
	hash_64[3324] += hash_64[3325]; hash_64[3326] += hash_64[3327];
	hash_64[3312] += hash_64[3314]; hash_64[3316] += hash_64[3318];
	hash_64[3320] += hash_64[3322]; hash_64[3324] += hash_64[3326];
#endif
#if MEMORY_THREADS > 208
	hash_64[3328] += hash_64[3329]; hash_64[3330] += hash_64[3331];
	hash_64[3332] += hash_64[3333]; hash_64[3334] += hash_64[3335];
	hash_64[3336] += hash_64[3337]; hash_64[3338] += hash_64[3339];
	hash_64[3340] += hash_64[3341]; hash_64[3342] += hash_64[3343];
	hash_64[3328] += hash_64[3330]; hash_64[3332] += hash_64[3334];
	hash_64[3336] += hash_64[3338]; hash_64[3340] += hash_64[3342];
#endif
#if MEMORY_THREADS > 209
	hash_64[3344] += hash_64[3345]; hash_64[3346] += hash_64[3347];
	hash_64[3348] += hash_64[3349]; hash_64[3350] += hash_64[3351];
	hash_64[3352] += hash_64[3353]; hash_64[3354] += hash_64[3355];
	hash_64[3356] += hash_64[3357]; hash_64[3358] += hash_64[3359];
	hash_64[3344] += hash_64[3346]; hash_64[3348] += hash_64[3350];
	hash_64[3352] += hash_64[3354]; hash_64[3356] += hash_64[3358];
#endif
#if MEMORY_THREADS > 210
	hash_64[3360] += hash_64[3361]; hash_64[3362] += hash_64[3363];
	hash_64[3364] += hash_64[3365]; hash_64[3366] += hash_64[3367];
	hash_64[3368] += hash_64[3369]; hash_64[3370] += hash_64[3371];
	hash_64[3372] += hash_64[3373]; hash_64[3374] += hash_64[3375];
	hash_64[3360] += hash_64[3362]; hash_64[3364] += hash_64[3366];
	hash_64[3368] += hash_64[3370]; hash_64[3372] += hash_64[3374];
#endif
#if MEMORY_THREADS > 211
	hash_64[3376] += hash_64[3377]; hash_64[3378] += hash_64[3379];
	hash_64[3380] += hash_64[3381]; hash_64[3382] += hash_64[3383];
	hash_64[3384] += hash_64[3385]; hash_64[3386] += hash_64[3387];
	hash_64[3388] += hash_64[3389]; hash_64[3390] += hash_64[3391];
	hash_64[3376] += hash_64[3378]; hash_64[3380] += hash_64[3382];
	hash_64[3384] += hash_64[3386]; hash_64[3388] += hash_64[3390];
#endif
#if MEMORY_THREADS > 212
	hash_64[3392] += hash_64[3393]; hash_64[3394] += hash_64[3395];
	hash_64[3396] += hash_64[3397]; hash_64[3398] += hash_64[3399];
	hash_64[3400] += hash_64[3401]; hash_64[3402] += hash_64[3403];
	hash_64[3404] += hash_64[3405]; hash_64[3406] += hash_64[3407];
	hash_64[3392] += hash_64[3394]; hash_64[3396] += hash_64[3398];
	hash_64[3400] += hash_64[3402]; hash_64[3404] += hash_64[3406];
#endif
#if MEMORY_THREADS > 213
	hash_64[3408] += hash_64[3409]; hash_64[3410] += hash_64[3411];
	hash_64[3412] += hash_64[3413]; hash_64[3414] += hash_64[3415];
	hash_64[3416] += hash_64[3417]; hash_64[3418] += hash_64[3419];
	hash_64[3420] += hash_64[3421]; hash_64[3422] += hash_64[3423];
	hash_64[3408] += hash_64[3410]; hash_64[3412] += hash_64[3414];
	hash_64[3416] += hash_64[3418]; hash_64[3420] += hash_64[3422];
#endif
#if MEMORY_THREADS > 214
	hash_64[3424] += hash_64[3425]; hash_64[3426] += hash_64[3427];
	hash_64[3428] += hash_64[3429]; hash_64[3430] += hash_64[3431];
	hash_64[3432] += hash_64[3433]; hash_64[3434] += hash_64[3435];
	hash_64[3436] += hash_64[3437]; hash_64[3438] += hash_64[3439];
	hash_64[3424] += hash_64[3426]; hash_64[3428] += hash_64[3430];
	hash_64[3432] += hash_64[3434]; hash_64[3436] += hash_64[3438];
#endif
#if MEMORY_THREADS > 215
	hash_64[3440] += hash_64[3441]; hash_64[3442] += hash_64[3443];
	hash_64[3444] += hash_64[3445]; hash_64[3446] += hash_64[3447];
	hash_64[3448] += hash_64[3449]; hash_64[3450] += hash_64[3451];
	hash_64[3452] += hash_64[3453]; hash_64[3454] += hash_64[3455];
	hash_64[3440] += hash_64[3442]; hash_64[3444] += hash_64[3446];
	hash_64[3448] += hash_64[3450]; hash_64[3452] += hash_64[3454];
#endif
#if MEMORY_THREADS > 216
	hash_64[3456] += hash_64[3457]; hash_64[3458] += hash_64[3459];
	hash_64[3460] += hash_64[3461]; hash_64[3462] += hash_64[3463];
	hash_64[3464] += hash_64[3465]; hash_64[3466] += hash_64[3467];
	hash_64[3468] += hash_64[3469]; hash_64[3470] += hash_64[3471];
	hash_64[3456] += hash_64[3458]; hash_64[3460] += hash_64[3462];
	hash_64[3464] += hash_64[3466]; hash_64[3468] += hash_64[3470];
#endif
#if MEMORY_THREADS > 217
	hash_64[3472] += hash_64[3473]; hash_64[3474] += hash_64[3475];
	hash_64[3476] += hash_64[3477]; hash_64[3478] += hash_64[3479];
	hash_64[3480] += hash_64[3481]; hash_64[3482] += hash_64[3483];
	hash_64[3484] += hash_64[3485]; hash_64[3486] += hash_64[3487];
	hash_64[3472] += hash_64[3474]; hash_64[3476] += hash_64[3478];
	hash_64[3480] += hash_64[3482]; hash_64[3484] += hash_64[3486];
#endif
#if MEMORY_THREADS > 218
	hash_64[3488] += hash_64[3489]; hash_64[3490] += hash_64[3491];
	hash_64[3492] += hash_64[3493]; hash_64[3494] += hash_64[3495];
	hash_64[3496] += hash_64[3497]; hash_64[3498] += hash_64[3499];
	hash_64[3500] += hash_64[3501]; hash_64[3502] += hash_64[3503];
	hash_64[3488] += hash_64[3490]; hash_64[3492] += hash_64[3494];
	hash_64[3496] += hash_64[3498]; hash_64[3500] += hash_64[3502];
#endif
#if MEMORY_THREADS > 219
	hash_64[3504] += hash_64[3505]; hash_64[3506] += hash_64[3507];
	hash_64[3508] += hash_64[3509]; hash_64[3510] += hash_64[3511];
	hash_64[3512] += hash_64[3513]; hash_64[3514] += hash_64[3515];
	hash_64[3516] += hash_64[3517]; hash_64[3518] += hash_64[3519];
	hash_64[3504] += hash_64[3506]; hash_64[3508] += hash_64[3510];
	hash_64[3512] += hash_64[3514]; hash_64[3516] += hash_64[3518];
#endif
#if MEMORY_THREADS > 220
	hash_64[3520] += hash_64[3521]; hash_64[3522] += hash_64[3523];
	hash_64[3524] += hash_64[3525]; hash_64[3526] += hash_64[3527];
	hash_64[3528] += hash_64[3529]; hash_64[3530] += hash_64[3531];
	hash_64[3532] += hash_64[3533]; hash_64[3534] += hash_64[3535];
	hash_64[3520] += hash_64[3522]; hash_64[3524] += hash_64[3526];
	hash_64[3528] += hash_64[3530]; hash_64[3532] += hash_64[3534];
#endif
#if MEMORY_THREADS > 221
	hash_64[3536] += hash_64[3537]; hash_64[3538] += hash_64[3539];
	hash_64[3540] += hash_64[3541]; hash_64[3542] += hash_64[3543];
	hash_64[3544] += hash_64[3545]; hash_64[3546] += hash_64[3547];
	hash_64[3548] += hash_64[3549]; hash_64[3550] += hash_64[3551];
	hash_64[3536] += hash_64[3538]; hash_64[3540] += hash_64[3542];
	hash_64[3544] += hash_64[3546]; hash_64[3548] += hash_64[3550];
#endif
#if MEMORY_THREADS > 222
	hash_64[3552] += hash_64[3553]; hash_64[3554] += hash_64[3555];
	hash_64[3556] += hash_64[3557]; hash_64[3558] += hash_64[3559];
	hash_64[3560] += hash_64[3561]; hash_64[3562] += hash_64[3563];
	hash_64[3564] += hash_64[3565]; hash_64[3566] += hash_64[3567];
	hash_64[3552] += hash_64[3554]; hash_64[3556] += hash_64[3558];
	hash_64[3560] += hash_64[3562]; hash_64[3564] += hash_64[3566];
#endif
#if MEMORY_THREADS > 223
	hash_64[3568] += hash_64[3569]; hash_64[3570] += hash_64[3571];
	hash_64[3572] += hash_64[3573]; hash_64[3574] += hash_64[3575];
	hash_64[3576] += hash_64[3577]; hash_64[3578] += hash_64[3579];
	hash_64[3580] += hash_64[3581]; hash_64[3582] += hash_64[3583];
	hash_64[3568] += hash_64[3570]; hash_64[3572] += hash_64[3574];
	hash_64[3576] += hash_64[3578]; hash_64[3580] += hash_64[3582];
#endif
#if MEMORY_THREADS > 224
	hash_64[3584] += hash_64[3585]; hash_64[3586] += hash_64[3587];
	hash_64[3588] += hash_64[3589]; hash_64[3590] += hash_64[3591];
	hash_64[3592] += hash_64[3593]; hash_64[3594] += hash_64[3595];
	hash_64[3596] += hash_64[3597]; hash_64[3598] += hash_64[3599];
	hash_64[3584] += hash_64[3586]; hash_64[3588] += hash_64[3590];
	hash_64[3592] += hash_64[3594]; hash_64[3596] += hash_64[3598];
#endif
#if MEMORY_THREADS > 225
	hash_64[3600] += hash_64[3601]; hash_64[3602] += hash_64[3603];
	hash_64[3604] += hash_64[3605]; hash_64[3606] += hash_64[3607];
	hash_64[3608] += hash_64[3609]; hash_64[3610] += hash_64[3611];
	hash_64[3612] += hash_64[3613]; hash_64[3614] += hash_64[3615];
	hash_64[3600] += hash_64[3602]; hash_64[3604] += hash_64[3606];
	hash_64[3608] += hash_64[3610]; hash_64[3612] += hash_64[3614];
#endif
#if MEMORY_THREADS > 226
	hash_64[3616] += hash_64[3617]; hash_64[3618] += hash_64[3619];
	hash_64[3620] += hash_64[3621]; hash_64[3622] += hash_64[3623];
	hash_64[3624] += hash_64[3625]; hash_64[3626] += hash_64[3627];
	hash_64[3628] += hash_64[3629]; hash_64[3630] += hash_64[3631];
	hash_64[3616] += hash_64[3618]; hash_64[3620] += hash_64[3622];
	hash_64[3624] += hash_64[3626]; hash_64[3628] += hash_64[3630];
#endif
#if MEMORY_THREADS > 227
	hash_64[3632] += hash_64[3633]; hash_64[3634] += hash_64[3635];
	hash_64[3636] += hash_64[3637]; hash_64[3638] += hash_64[3639];
	hash_64[3640] += hash_64[3641]; hash_64[3642] += hash_64[3643];
	hash_64[3644] += hash_64[3645]; hash_64[3646] += hash_64[3647];
	hash_64[3632] += hash_64[3634]; hash_64[3636] += hash_64[3638];
	hash_64[3640] += hash_64[3642]; hash_64[3644] += hash_64[3646];
#endif
#if MEMORY_THREADS > 228
	hash_64[3648] += hash_64[3649]; hash_64[3650] += hash_64[3651];
	hash_64[3652] += hash_64[3653]; hash_64[3654] += hash_64[3655];
	hash_64[3656] += hash_64[3657]; hash_64[3658] += hash_64[3659];
	hash_64[3660] += hash_64[3661]; hash_64[3662] += hash_64[3663];
	hash_64[3648] += hash_64[3650]; hash_64[3652] += hash_64[3654];
	hash_64[3656] += hash_64[3658]; hash_64[3660] += hash_64[3662];
#endif
#if MEMORY_THREADS > 229
	hash_64[3664] += hash_64[3665]; hash_64[3666] += hash_64[3667];
	hash_64[3668] += hash_64[3669]; hash_64[3670] += hash_64[3671];
	hash_64[3672] += hash_64[3673]; hash_64[3674] += hash_64[3675];
	hash_64[3676] += hash_64[3677]; hash_64[3678] += hash_64[3679];
	hash_64[3664] += hash_64[3666]; hash_64[3668] += hash_64[3670];
	hash_64[3672] += hash_64[3674]; hash_64[3676] += hash_64[3678];
#endif
#if MEMORY_THREADS > 230
	hash_64[3680] += hash_64[3681]; hash_64[3682] += hash_64[3683];
	hash_64[3684] += hash_64[3685]; hash_64[3686] += hash_64[3687];
	hash_64[3688] += hash_64[3689]; hash_64[3690] += hash_64[3691];
	hash_64[3692] += hash_64[3693]; hash_64[3694] += hash_64[3695];
	hash_64[3680] += hash_64[3682]; hash_64[3684] += hash_64[3686];
	hash_64[3688] += hash_64[3690]; hash_64[3692] += hash_64[3694];
#endif
#if MEMORY_THREADS > 231
	hash_64[3696] += hash_64[3697]; hash_64[3698] += hash_64[3699];
	hash_64[3700] += hash_64[3701]; hash_64[3702] += hash_64[3703];
	hash_64[3704] += hash_64[3705]; hash_64[3706] += hash_64[3707];
	hash_64[3708] += hash_64[3709]; hash_64[3710] += hash_64[3711];
	hash_64[3696] += hash_64[3698]; hash_64[3700] += hash_64[3702];
	hash_64[3704] += hash_64[3706]; hash_64[3708] += hash_64[3710];
#endif
#if MEMORY_THREADS > 232
	hash_64[3712] += hash_64[3713]; hash_64[3714] += hash_64[3715];
	hash_64[3716] += hash_64[3717]; hash_64[3718] += hash_64[3719];
	hash_64[3720] += hash_64[3721]; hash_64[3722] += hash_64[3723];
	hash_64[3724] += hash_64[3725]; hash_64[3726] += hash_64[3727];
	hash_64[3712] += hash_64[3714]; hash_64[3716] += hash_64[3718];
	hash_64[3720] += hash_64[3722]; hash_64[3724] += hash_64[3726];
#endif
#if MEMORY_THREADS > 233
	hash_64[3728] += hash_64[3729]; hash_64[3730] += hash_64[3731];
	hash_64[3732] += hash_64[3733]; hash_64[3734] += hash_64[3735];
	hash_64[3736] += hash_64[3737]; hash_64[3738] += hash_64[3739];
	hash_64[3740] += hash_64[3741]; hash_64[3742] += hash_64[3743];
	hash_64[3728] += hash_64[3730]; hash_64[3732] += hash_64[3734];
	hash_64[3736] += hash_64[3738]; hash_64[3740] += hash_64[3742];
#endif
#if MEMORY_THREADS > 234
	hash_64[3744] += hash_64[3745]; hash_64[3746] += hash_64[3747];
	hash_64[3748] += hash_64[3749]; hash_64[3750] += hash_64[3751];
	hash_64[3752] += hash_64[3753]; hash_64[3754] += hash_64[3755];
	hash_64[3756] += hash_64[3757]; hash_64[3758] += hash_64[3759];
	hash_64[3744] += hash_64[3746]; hash_64[3748] += hash_64[3750];
	hash_64[3752] += hash_64[3754]; hash_64[3756] += hash_64[3758];
#endif
#if MEMORY_THREADS > 235
	hash_64[3760] += hash_64[3761]; hash_64[3762] += hash_64[3763];
	hash_64[3764] += hash_64[3765]; hash_64[3766] += hash_64[3767];
	hash_64[3768] += hash_64[3769]; hash_64[3770] += hash_64[3771];
	hash_64[3772] += hash_64[3773]; hash_64[3774] += hash_64[3775];
	hash_64[3760] += hash_64[3762]; hash_64[3764] += hash_64[3766];
	hash_64[3768] += hash_64[3770]; hash_64[3772] += hash_64[3774];
#endif
#if MEMORY_THREADS > 236
	hash_64[3776] += hash_64[3777]; hash_64[3778] += hash_64[3779];
	hash_64[3780] += hash_64[3781]; hash_64[3782] += hash_64[3783];
	hash_64[3784] += hash_64[3785]; hash_64[3786] += hash_64[3787];
	hash_64[3788] += hash_64[3789]; hash_64[3790] += hash_64[3791];
	hash_64[3776] += hash_64[3778]; hash_64[3780] += hash_64[3782];
	hash_64[3784] += hash_64[3786]; hash_64[3788] += hash_64[3790];
#endif
#if MEMORY_THREADS > 237
	hash_64[3792] += hash_64[3793]; hash_64[3794] += hash_64[3795];
	hash_64[3796] += hash_64[3797]; hash_64[3798] += hash_64[3799];
	hash_64[3800] += hash_64[3801]; hash_64[3802] += hash_64[3803];
	hash_64[3804] += hash_64[3805]; hash_64[3806] += hash_64[3807];
	hash_64[3792] += hash_64[3794]; hash_64[3796] += hash_64[3798];
	hash_64[3800] += hash_64[3802]; hash_64[3804] += hash_64[3806];
#endif
#if MEMORY_THREADS > 238
	hash_64[3808] += hash_64[3809]; hash_64[3810] += hash_64[3811];
	hash_64[3812] += hash_64[3813]; hash_64[3814] += hash_64[3815];
	hash_64[3816] += hash_64[3817]; hash_64[3818] += hash_64[3819];
	hash_64[3820] += hash_64[3821]; hash_64[3822] += hash_64[3823];
	hash_64[3808] += hash_64[3810]; hash_64[3812] += hash_64[3814];
	hash_64[3816] += hash_64[3818]; hash_64[3820] += hash_64[3822];
#endif
#if MEMORY_THREADS > 239
	hash_64[3824] += hash_64[3825]; hash_64[3826] += hash_64[3827];
	hash_64[3828] += hash_64[3829]; hash_64[3830] += hash_64[3831];
	hash_64[3832] += hash_64[3833]; hash_64[3834] += hash_64[3835];
	hash_64[3836] += hash_64[3837]; hash_64[3838] += hash_64[3839];
	hash_64[3824] += hash_64[3826]; hash_64[3828] += hash_64[3830];
	hash_64[3832] += hash_64[3834]; hash_64[3836] += hash_64[3838];
#endif
#if MEMORY_THREADS > 240
	hash_64[3840] += hash_64[3841]; hash_64[3842] += hash_64[3843];
	hash_64[3844] += hash_64[3845]; hash_64[3846] += hash_64[3847];
	hash_64[3848] += hash_64[3849]; hash_64[3850] += hash_64[3851];
	hash_64[3852] += hash_64[3853]; hash_64[3854] += hash_64[3855];
	hash_64[3840] += hash_64[3842]; hash_64[3844] += hash_64[3846];
	hash_64[3848] += hash_64[3850]; hash_64[3852] += hash_64[3854];
#endif
#if MEMORY_THREADS > 241
	hash_64[3856] += hash_64[3857]; hash_64[3858] += hash_64[3859];
	hash_64[3860] += hash_64[3861]; hash_64[3862] += hash_64[3863];
	hash_64[3864] += hash_64[3865]; hash_64[3866] += hash_64[3867];
	hash_64[3868] += hash_64[3869]; hash_64[3870] += hash_64[3871];
	hash_64[3856] += hash_64[3858]; hash_64[3860] += hash_64[3862];
	hash_64[3864] += hash_64[3866]; hash_64[3868] += hash_64[3870];
#endif
#if MEMORY_THREADS > 242
	hash_64[3872] += hash_64[3873]; hash_64[3874] += hash_64[3875];
	hash_64[3876] += hash_64[3877]; hash_64[3878] += hash_64[3879];
	hash_64[3880] += hash_64[3881]; hash_64[3882] += hash_64[3883];
	hash_64[3884] += hash_64[3885]; hash_64[3886] += hash_64[3887];
	hash_64[3872] += hash_64[3874]; hash_64[3876] += hash_64[3878];
	hash_64[3880] += hash_64[3882]; hash_64[3884] += hash_64[3886];
#endif
#if MEMORY_THREADS > 243
	hash_64[3888] += hash_64[3889]; hash_64[3890] += hash_64[3891];
	hash_64[3892] += hash_64[3893]; hash_64[3894] += hash_64[3895];
	hash_64[3896] += hash_64[3897]; hash_64[3898] += hash_64[3899];
	hash_64[3900] += hash_64[3901]; hash_64[3902] += hash_64[3903];
	hash_64[3888] += hash_64[3890]; hash_64[3892] += hash_64[3894];
	hash_64[3896] += hash_64[3898]; hash_64[3900] += hash_64[3902];
#endif
#if MEMORY_THREADS > 244
	hash_64[3904] += hash_64[3905]; hash_64[3906] += hash_64[3907];
	hash_64[3908] += hash_64[3909]; hash_64[3910] += hash_64[3911];
	hash_64[3912] += hash_64[3913]; hash_64[3914] += hash_64[3915];
	hash_64[3916] += hash_64[3917]; hash_64[3918] += hash_64[3919];
	hash_64[3904] += hash_64[3906]; hash_64[3908] += hash_64[3910];
	hash_64[3912] += hash_64[3914]; hash_64[3916] += hash_64[3918];
#endif
#if MEMORY_THREADS > 245
	hash_64[3920] += hash_64[3921]; hash_64[3922] += hash_64[3923];
	hash_64[3924] += hash_64[3925]; hash_64[3926] += hash_64[3927];
	hash_64[3928] += hash_64[3929]; hash_64[3930] += hash_64[3931];
	hash_64[3932] += hash_64[3933]; hash_64[3934] += hash_64[3935];
	hash_64[3920] += hash_64[3922]; hash_64[3924] += hash_64[3926];
	hash_64[3928] += hash_64[3930]; hash_64[3932] += hash_64[3934];
#endif
#if MEMORY_THREADS > 246
	hash_64[3936] += hash_64[3937]; hash_64[3938] += hash_64[3939];
	hash_64[3940] += hash_64[3941]; hash_64[3942] += hash_64[3943];
	hash_64[3944] += hash_64[3945]; hash_64[3946] += hash_64[3947];
	hash_64[3948] += hash_64[3949]; hash_64[3950] += hash_64[3951];
	hash_64[3936] += hash_64[3938]; hash_64[3940] += hash_64[3942];
	hash_64[3944] += hash_64[3946]; hash_64[3948] += hash_64[3950];
#endif
#if MEMORY_THREADS > 247
	hash_64[3952] += hash_64[3953]; hash_64[3954] += hash_64[3955];
	hash_64[3956] += hash_64[3957]; hash_64[3958] += hash_64[3959];
	hash_64[3960] += hash_64[3961]; hash_64[3962] += hash_64[3963];
	hash_64[3964] += hash_64[3965]; hash_64[3966] += hash_64[3967];
	hash_64[3952] += hash_64[3954]; hash_64[3956] += hash_64[3958];
	hash_64[3960] += hash_64[3962]; hash_64[3964] += hash_64[3966];
#endif
#if MEMORY_THREADS > 248
	hash_64[3968] += hash_64[3969]; hash_64[3970] += hash_64[3971];
	hash_64[3972] += hash_64[3973]; hash_64[3974] += hash_64[3975];
	hash_64[3976] += hash_64[3977]; hash_64[3978] += hash_64[3979];
	hash_64[3980] += hash_64[3981]; hash_64[3982] += hash_64[3983];
	hash_64[3968] += hash_64[3970]; hash_64[3972] += hash_64[3974];
	hash_64[3976] += hash_64[3978]; hash_64[3980] += hash_64[3982];
#endif
#if MEMORY_THREADS > 249
	hash_64[3984] += hash_64[3985]; hash_64[3986] += hash_64[3987];
	hash_64[3988] += hash_64[3989]; hash_64[3990] += hash_64[3991];
	hash_64[3992] += hash_64[3993]; hash_64[3994] += hash_64[3995];
	hash_64[3996] += hash_64[3997]; hash_64[3998] += hash_64[3999];
	hash_64[3984] += hash_64[3986]; hash_64[3988] += hash_64[3990];
	hash_64[3992] += hash_64[3994]; hash_64[3996] += hash_64[3998];
#endif
#if MEMORY_THREADS > 250
	hash_64[4000] += hash_64[4001]; hash_64[4002] += hash_64[4003];
	hash_64[4004] += hash_64[4005]; hash_64[4006] += hash_64[4007];
	hash_64[4008] += hash_64[4009]; hash_64[4010] += hash_64[4011];
	hash_64[4012] += hash_64[4013]; hash_64[4014] += hash_64[4015];
	hash_64[4000] += hash_64[4002]; hash_64[4004] += hash_64[4006];
	hash_64[4008] += hash_64[4010]; hash_64[4012] += hash_64[4014];
#endif
#if MEMORY_THREADS > 251
	hash_64[4016] += hash_64[4017]; hash_64[4018] += hash_64[4019];
	hash_64[4020] += hash_64[4021]; hash_64[4022] += hash_64[4023];
	hash_64[4024] += hash_64[4025]; hash_64[4026] += hash_64[4027];
	hash_64[4028] += hash_64[4029]; hash_64[4030] += hash_64[4031];
	hash_64[4016] += hash_64[4018]; hash_64[4020] += hash_64[4022];
	hash_64[4024] += hash_64[4026]; hash_64[4028] += hash_64[4030];
#endif
#if MEMORY_THREADS > 252
	hash_64[4032] += hash_64[4033]; hash_64[4034] += hash_64[4035];
	hash_64[4036] += hash_64[4037]; hash_64[4038] += hash_64[4039];
	hash_64[4040] += hash_64[4041]; hash_64[4042] += hash_64[4043];
	hash_64[4044] += hash_64[4045]; hash_64[4046] += hash_64[4047];
	hash_64[4032] += hash_64[4034]; hash_64[4036] += hash_64[4038];
	hash_64[4040] += hash_64[4042]; hash_64[4044] += hash_64[4046];
#endif
#if MEMORY_THREADS > 253
	hash_64[4048] += hash_64[4049]; hash_64[4050] += hash_64[4051];
	hash_64[4052] += hash_64[4053]; hash_64[4054] += hash_64[4055];
	hash_64[4056] += hash_64[4057]; hash_64[4058] += hash_64[4059];
	hash_64[4060] += hash_64[4061]; hash_64[4062] += hash_64[4063];
	hash_64[4048] += hash_64[4050]; hash_64[4052] += hash_64[4054];
	hash_64[4056] += hash_64[4058]; hash_64[4060] += hash_64[4062];
#endif
#if MEMORY_THREADS > 254
	hash_64[4064] += hash_64[4065]; hash_64[4066] += hash_64[4067];
	hash_64[4068] += hash_64[4069]; hash_64[4070] += hash_64[4071];
	hash_64[4072] += hash_64[4073]; hash_64[4074] += hash_64[4075];
	hash_64[4076] += hash_64[4077]; hash_64[4078] += hash_64[4079];
	hash_64[4064] += hash_64[4066]; hash_64[4068] += hash_64[4070];
	hash_64[4072] += hash_64[4074]; hash_64[4076] += hash_64[4078];
#endif
#if MEMORY_THREADS > 255
	hash_64[4080] += hash_64[4081]; hash_64[4082] += hash_64[4083];
	hash_64[4084] += hash_64[4085]; hash_64[4086] += hash_64[4087];
	hash_64[4088] += hash_64[4089]; hash_64[4090] += hash_64[4091];
	hash_64[4092] += hash_64[4093]; hash_64[4094] += hash_64[4095];
	hash_64[4080] += hash_64[4082]; hash_64[4084] += hash_64[4086];
	hash_64[4088] += hash_64[4090]; hash_64[4092] += hash_64[4094];
#endif
	*out_64   = hash_64[ 0]; out_64[1] = hash_64[ 4];
	out_64[2] = hash_64[ 8]; out_64[3] = hash_64[12];
#if MEMORY_THREADS > 1
	if(((hash_64[16])<=(*out_64  ))
	&& ((hash_64[20])<=(out_64[1]))
	&& ((hash_64[24])<=(out_64[2]))
	&& ((hash_64[28])<=(out_64[3]))){
		*out_64   = hash_64[16]; out_64[1] = hash_64[20];
		out_64[2] = hash_64[24]; out_64[3] = hash_64[28];
	}
#endif
#if MEMORY_THREADS > 2
	if(((hash_64[32])<=(*out_64  ))
	&& ((hash_64[36])<=(out_64[1]))
	&& ((hash_64[40])<=(out_64[2]))
	&& ((hash_64[44])<=(out_64[3]))){
		*out_64   = hash_64[32]; out_64[1] = hash_64[36];
		out_64[2] = hash_64[40]; out_64[3] = hash_64[44];
	}
#endif
#if MEMORY_THREADS > 3
	if(((hash_64[48])<=(*out_64  ))
	&& ((hash_64[52])<=(out_64[1]))
	&& ((hash_64[56])<=(out_64[2]))
	&& ((hash_64[60])<=(out_64[3]))){
		*out_64   = hash_64[48]; out_64[1] = hash_64[52];
		out_64[2] = hash_64[56]; out_64[3] = hash_64[60];
	}
#endif
#if MEMORY_THREADS > 4
	if(((hash_64[64])<=(*out_64  ))
	&& ((hash_64[68])<=(out_64[1]))
	&& ((hash_64[72])<=(out_64[2]))
	&& ((hash_64[76])<=(out_64[3]))){
		*out_64   = hash_64[64]; out_64[1] = hash_64[68];
		out_64[2] = hash_64[72]; out_64[3] = hash_64[76];
	}
#endif
#if MEMORY_THREADS > 5
	if(((hash_64[80])<=(*out_64  ))
	&& ((hash_64[84])<=(out_64[1]))
	&& ((hash_64[88])<=(out_64[2]))
	&& ((hash_64[92])<=(out_64[3]))){
		*out_64   = hash_64[80]; out_64[1] = hash_64[84];
		out_64[2] = hash_64[88]; out_64[3] = hash_64[92];
	}
#endif
#if MEMORY_THREADS > 6
	if(((hash_64[96])<=(*out_64  ))
	&& ((hash_64[100])<=(out_64[1]))
	&& ((hash_64[104])<=(out_64[2]))
	&& ((hash_64[108])<=(out_64[3]))){
		*out_64   = hash_64[96]; out_64[1] = hash_64[100];
		out_64[2] = hash_64[104]; out_64[3] = hash_64[108];
	}
#endif
#if MEMORY_THREADS > 7
	if(((hash_64[112])<=(*out_64  ))
	&& ((hash_64[116])<=(out_64[1]))
	&& ((hash_64[120])<=(out_64[2]))
	&& ((hash_64[124])<=(out_64[3]))){
		*out_64   = hash_64[112]; out_64[1] = hash_64[116];
		out_64[2] = hash_64[120]; out_64[3] = hash_64[124];
	}
#endif
#if MEMORY_THREADS > 8
	if(((hash_64[128])<=(*out_64  ))
	&& ((hash_64[132])<=(out_64[1]))
	&& ((hash_64[136])<=(out_64[2]))
	&& ((hash_64[140])<=(out_64[3]))){
		*out_64   = hash_64[128]; out_64[1] = hash_64[132];
		out_64[2] = hash_64[136]; out_64[3] = hash_64[140];
	}
#endif
#if MEMORY_THREADS > 9
	if(((hash_64[144])<=(*out_64  ))
	&& ((hash_64[148])<=(out_64[1]))
	&& ((hash_64[152])<=(out_64[2]))
	&& ((hash_64[156])<=(out_64[3]))){
		*out_64   = hash_64[144]; out_64[1] = hash_64[148];
		out_64[2] = hash_64[152]; out_64[3] = hash_64[156];
	}
#endif
#if MEMORY_THREADS > 10
	if(((hash_64[160])<=(*out_64  ))
	&& ((hash_64[164])<=(out_64[1]))
	&& ((hash_64[168])<=(out_64[2]))
	&& ((hash_64[172])<=(out_64[3]))){
		*out_64   = hash_64[160]; out_64[1] = hash_64[164];
		out_64[2] = hash_64[168]; out_64[3] = hash_64[172];
	}
#endif
#if MEMORY_THREADS > 11
	if(((hash_64[176])<=(*out_64  ))
	&& ((hash_64[180])<=(out_64[1]))
	&& ((hash_64[184])<=(out_64[2]))
	&& ((hash_64[188])<=(out_64[3]))){
		*out_64   = hash_64[176]; out_64[1] = hash_64[180];
		out_64[2] = hash_64[184]; out_64[3] = hash_64[188];
	}
#endif
#if MEMORY_THREADS > 12
	if(((hash_64[192])<=(*out_64  ))
	&& ((hash_64[196])<=(out_64[1]))
	&& ((hash_64[200])<=(out_64[2]))
	&& ((hash_64[204])<=(out_64[3]))){
		*out_64   = hash_64[192]; out_64[1] = hash_64[196];
		out_64[2] = hash_64[200]; out_64[3] = hash_64[204];
	}
#endif
#if MEMORY_THREADS > 13
	if(((hash_64[208])<=(*out_64  ))
	&& ((hash_64[212])<=(out_64[1]))
	&& ((hash_64[216])<=(out_64[2]))
	&& ((hash_64[220])<=(out_64[3]))){
		*out_64   = hash_64[208]; out_64[1] = hash_64[212];
		out_64[2] = hash_64[216]; out_64[3] = hash_64[220];
	}
#endif
#if MEMORY_THREADS > 14
	if(((hash_64[224])<=(*out_64  ))
	&& ((hash_64[228])<=(out_64[1]))
	&& ((hash_64[232])<=(out_64[2]))
	&& ((hash_64[236])<=(out_64[3]))){
		*out_64   = hash_64[224]; out_64[1] = hash_64[228];
		out_64[2] = hash_64[232]; out_64[3] = hash_64[236];
	}
#endif
#if MEMORY_THREADS > 15
	if(((hash_64[240])<=(*out_64  ))
	&& ((hash_64[244])<=(out_64[1]))
	&& ((hash_64[248])<=(out_64[2]))
	&& ((hash_64[252])<=(out_64[3]))){
		*out_64   = hash_64[240]; out_64[1] = hash_64[244];
		out_64[2] = hash_64[248]; out_64[3] = hash_64[252];
	}
#endif
#if MEMORY_THREADS > 16
	if(((hash_64[256])<=(*out_64  ))
	&& ((hash_64[260])<=(out_64[1]))
	&& ((hash_64[264])<=(out_64[2]))
	&& ((hash_64[268])<=(out_64[3]))){
		*out_64   = hash_64[256]; out_64[1] = hash_64[260];
		out_64[2] = hash_64[264]; out_64[3] = hash_64[268];
	}
#endif
#if MEMORY_THREADS > 17
	if(((hash_64[272])<=(*out_64  ))
	&& ((hash_64[276])<=(out_64[1]))
	&& ((hash_64[280])<=(out_64[2]))
	&& ((hash_64[284])<=(out_64[3]))){
		*out_64   = hash_64[272]; out_64[1] = hash_64[276];
		out_64[2] = hash_64[280]; out_64[3] = hash_64[284];
	}
#endif
#if MEMORY_THREADS > 18
	if(((hash_64[288])<=(*out_64  ))
	&& ((hash_64[292])<=(out_64[1]))
	&& ((hash_64[296])<=(out_64[2]))
	&& ((hash_64[300])<=(out_64[3]))){
		*out_64   = hash_64[288]; out_64[1] = hash_64[292];
		out_64[2] = hash_64[296]; out_64[3] = hash_64[300];
	}
#endif
#if MEMORY_THREADS > 19
	if(((hash_64[304])<=(*out_64  ))
	&& ((hash_64[308])<=(out_64[1]))
	&& ((hash_64[312])<=(out_64[2]))
	&& ((hash_64[316])<=(out_64[3]))){
		*out_64   = hash_64[304]; out_64[1] = hash_64[308];
		out_64[2] = hash_64[312]; out_64[3] = hash_64[316];
	}
#endif
#if MEMORY_THREADS > 20
	if(((hash_64[320])<=(*out_64  ))
	&& ((hash_64[324])<=(out_64[1]))
	&& ((hash_64[328])<=(out_64[2]))
	&& ((hash_64[332])<=(out_64[3]))){
		*out_64   = hash_64[320]; out_64[1] = hash_64[324];
		out_64[2] = hash_64[328]; out_64[3] = hash_64[332];
	}
#endif
#if MEMORY_THREADS > 21
	if(((hash_64[336])<=(*out_64  ))
	&& ((hash_64[340])<=(out_64[1]))
	&& ((hash_64[344])<=(out_64[2]))
	&& ((hash_64[348])<=(out_64[3]))){
		*out_64   = hash_64[336]; out_64[1] = hash_64[340];
		out_64[2] = hash_64[344]; out_64[3] = hash_64[348];
	}
#endif
#if MEMORY_THREADS > 22
	if(((hash_64[352])<=(*out_64  ))
	&& ((hash_64[356])<=(out_64[1]))
	&& ((hash_64[360])<=(out_64[2]))
	&& ((hash_64[364])<=(out_64[3]))){
		*out_64   = hash_64[352]; out_64[1] = hash_64[356];
		out_64[2] = hash_64[360]; out_64[3] = hash_64[364];
	}
#endif
#if MEMORY_THREADS > 23
	if(((hash_64[368])<=(*out_64  ))
	&& ((hash_64[372])<=(out_64[1]))
	&& ((hash_64[376])<=(out_64[2]))
	&& ((hash_64[380])<=(out_64[3]))){
		*out_64   = hash_64[368]; out_64[1] = hash_64[372];
		out_64[2] = hash_64[376]; out_64[3] = hash_64[380];
	}
#endif
#if MEMORY_THREADS > 24
	if(((hash_64[384])<=(*out_64  ))
	&& ((hash_64[388])<=(out_64[1]))
	&& ((hash_64[392])<=(out_64[2]))
	&& ((hash_64[396])<=(out_64[3]))){
		*out_64   = hash_64[384]; out_64[1] = hash_64[388];
		out_64[2] = hash_64[392]; out_64[3] = hash_64[396];
	}
#endif
#if MEMORY_THREADS > 25
	if(((hash_64[400])<=(*out_64  ))
	&& ((hash_64[404])<=(out_64[1]))
	&& ((hash_64[408])<=(out_64[2]))
	&& ((hash_64[412])<=(out_64[3]))){
		*out_64   = hash_64[400]; out_64[1] = hash_64[404];
		out_64[2] = hash_64[408]; out_64[3] = hash_64[412];
	}
#endif
#if MEMORY_THREADS > 26
	if(((hash_64[416])<=(*out_64  ))
	&& ((hash_64[420])<=(out_64[1]))
	&& ((hash_64[424])<=(out_64[2]))
	&& ((hash_64[428])<=(out_64[3]))){
		*out_64   = hash_64[416]; out_64[1] = hash_64[420];
		out_64[2] = hash_64[424]; out_64[3] = hash_64[428];
	}
#endif
#if MEMORY_THREADS > 27
	if(((hash_64[432])<=(*out_64  ))
	&& ((hash_64[436])<=(out_64[1]))
	&& ((hash_64[440])<=(out_64[2]))
	&& ((hash_64[444])<=(out_64[3]))){
		*out_64   = hash_64[432]; out_64[1] = hash_64[436];
		out_64[2] = hash_64[440]; out_64[3] = hash_64[444];
	}
#endif
#if MEMORY_THREADS > 28
	if(((hash_64[448])<=(*out_64  ))
	&& ((hash_64[452])<=(out_64[1]))
	&& ((hash_64[456])<=(out_64[2]))
	&& ((hash_64[460])<=(out_64[3]))){
		*out_64   = hash_64[448]; out_64[1] = hash_64[452];
		out_64[2] = hash_64[456]; out_64[3] = hash_64[460];
	}
#endif
#if MEMORY_THREADS > 29
	if(((hash_64[464])<=(*out_64  ))
	&& ((hash_64[468])<=(out_64[1]))
	&& ((hash_64[472])<=(out_64[2]))
	&& ((hash_64[476])<=(out_64[3]))){
		*out_64   = hash_64[464]; out_64[1] = hash_64[468];
		out_64[2] = hash_64[472]; out_64[3] = hash_64[476];
	}
#endif
#if MEMORY_THREADS > 30
	if(((hash_64[480])<=(*out_64  ))
	&& ((hash_64[484])<=(out_64[1]))
	&& ((hash_64[488])<=(out_64[2]))
	&& ((hash_64[492])<=(out_64[3]))){
		*out_64   = hash_64[480]; out_64[1] = hash_64[484];
		out_64[2] = hash_64[488]; out_64[3] = hash_64[492];
	}
#endif
#if MEMORY_THREADS > 31
	if(((hash_64[496])<=(*out_64  ))
	&& ((hash_64[500])<=(out_64[1]))
	&& ((hash_64[504])<=(out_64[2]))
	&& ((hash_64[508])<=(out_64[3]))){
		*out_64   = hash_64[496]; out_64[1] = hash_64[500];
		out_64[2] = hash_64[504]; out_64[3] = hash_64[508];
	}
#endif
#if MEMORY_THREADS > 32
	if(((hash_64[512])<=(*out_64  ))
	&& ((hash_64[516])<=(out_64[1]))
	&& ((hash_64[520])<=(out_64[2]))
	&& ((hash_64[524])<=(out_64[3]))){
		*out_64   = hash_64[512]; out_64[1] = hash_64[516];
		out_64[2] = hash_64[520]; out_64[3] = hash_64[524];
	}
#endif
#if MEMORY_THREADS > 33
	if(((hash_64[528])<=(*out_64  ))
	&& ((hash_64[532])<=(out_64[1]))
	&& ((hash_64[536])<=(out_64[2]))
	&& ((hash_64[540])<=(out_64[3]))){
		*out_64   = hash_64[528]; out_64[1] = hash_64[532];
		out_64[2] = hash_64[536]; out_64[3] = hash_64[540];
	}
#endif
#if MEMORY_THREADS > 34
	if(((hash_64[544])<=(*out_64  ))
	&& ((hash_64[548])<=(out_64[1]))
	&& ((hash_64[552])<=(out_64[2]))
	&& ((hash_64[556])<=(out_64[3]))){
		*out_64   = hash_64[544]; out_64[1] = hash_64[548];
		out_64[2] = hash_64[552]; out_64[3] = hash_64[556];
	}
#endif
#if MEMORY_THREADS > 35
	if(((hash_64[560])<=(*out_64  ))
	&& ((hash_64[564])<=(out_64[1]))
	&& ((hash_64[568])<=(out_64[2]))
	&& ((hash_64[572])<=(out_64[3]))){
		*out_64   = hash_64[560]; out_64[1] = hash_64[564];
		out_64[2] = hash_64[568]; out_64[3] = hash_64[572];
	}
#endif
#if MEMORY_THREADS > 36
	if(((hash_64[576])<=(*out_64  ))
	&& ((hash_64[580])<=(out_64[1]))
	&& ((hash_64[584])<=(out_64[2]))
	&& ((hash_64[588])<=(out_64[3]))){
		*out_64   = hash_64[576]; out_64[1] = hash_64[580];
		out_64[2] = hash_64[584]; out_64[3] = hash_64[588];
	}
#endif
#if MEMORY_THREADS > 37
	if(((hash_64[592])<=(*out_64  ))
	&& ((hash_64[596])<=(out_64[1]))
	&& ((hash_64[600])<=(out_64[2]))
	&& ((hash_64[604])<=(out_64[3]))){
		*out_64   = hash_64[592]; out_64[1] = hash_64[596];
		out_64[2] = hash_64[600]; out_64[3] = hash_64[604];
	}
#endif
#if MEMORY_THREADS > 38
	if(((hash_64[608])<=(*out_64  ))
	&& ((hash_64[612])<=(out_64[1]))
	&& ((hash_64[616])<=(out_64[2]))
	&& ((hash_64[620])<=(out_64[3]))){
		*out_64   = hash_64[608]; out_64[1] = hash_64[612];
		out_64[2] = hash_64[616]; out_64[3] = hash_64[620];
	}
#endif
#if MEMORY_THREADS > 39
	if(((hash_64[624])<=(*out_64  ))
	&& ((hash_64[628])<=(out_64[1]))
	&& ((hash_64[632])<=(out_64[2]))
	&& ((hash_64[636])<=(out_64[3]))){
		*out_64   = hash_64[624]; out_64[1] = hash_64[628];
		out_64[2] = hash_64[632]; out_64[3] = hash_64[636];
	}
#endif
#if MEMORY_THREADS > 40
	if(((hash_64[640])<=(*out_64  ))
	&& ((hash_64[644])<=(out_64[1]))
	&& ((hash_64[648])<=(out_64[2]))
	&& ((hash_64[652])<=(out_64[3]))){
		*out_64   = hash_64[640]; out_64[1] = hash_64[644];
		out_64[2] = hash_64[648]; out_64[3] = hash_64[652];
	}
#endif
#if MEMORY_THREADS > 41
	if(((hash_64[656])<=(*out_64  ))
	&& ((hash_64[660])<=(out_64[1]))
	&& ((hash_64[664])<=(out_64[2]))
	&& ((hash_64[668])<=(out_64[3]))){
		*out_64   = hash_64[656]; out_64[1] = hash_64[660];
		out_64[2] = hash_64[664]; out_64[3] = hash_64[668];
	}
#endif
#if MEMORY_THREADS > 42
	if(((hash_64[672])<=(*out_64  ))
	&& ((hash_64[676])<=(out_64[1]))
	&& ((hash_64[680])<=(out_64[2]))
	&& ((hash_64[684])<=(out_64[3]))){
		*out_64   = hash_64[672]; out_64[1] = hash_64[676];
		out_64[2] = hash_64[680]; out_64[3] = hash_64[684];
	}
#endif
#if MEMORY_THREADS > 43
	if(((hash_64[688])<=(*out_64  ))
	&& ((hash_64[692])<=(out_64[1]))
	&& ((hash_64[696])<=(out_64[2]))
	&& ((hash_64[700])<=(out_64[3]))){
		*out_64   = hash_64[688]; out_64[1] = hash_64[692];
		out_64[2] = hash_64[696]; out_64[3] = hash_64[700];
	}
#endif
#if MEMORY_THREADS > 44
	if(((hash_64[704])<=(*out_64  ))
	&& ((hash_64[708])<=(out_64[1]))
	&& ((hash_64[712])<=(out_64[2]))
	&& ((hash_64[716])<=(out_64[3]))){
		*out_64   = hash_64[704]; out_64[1] = hash_64[708];
		out_64[2] = hash_64[712]; out_64[3] = hash_64[716];
	}
#endif
#if MEMORY_THREADS > 45
	if(((hash_64[720])<=(*out_64  ))
	&& ((hash_64[724])<=(out_64[1]))
	&& ((hash_64[728])<=(out_64[2]))
	&& ((hash_64[732])<=(out_64[3]))){
		*out_64   = hash_64[720]; out_64[1] = hash_64[724];
		out_64[2] = hash_64[728]; out_64[3] = hash_64[732];
	}
#endif
#if MEMORY_THREADS > 46
	if(((hash_64[736])<=(*out_64  ))
	&& ((hash_64[740])<=(out_64[1]))
	&& ((hash_64[744])<=(out_64[2]))
	&& ((hash_64[748])<=(out_64[3]))){
		*out_64   = hash_64[736]; out_64[1] = hash_64[740];
		out_64[2] = hash_64[744]; out_64[3] = hash_64[748];
	}
#endif
#if MEMORY_THREADS > 47
	if(((hash_64[752])<=(*out_64  ))
	&& ((hash_64[756])<=(out_64[1]))
	&& ((hash_64[760])<=(out_64[2]))
	&& ((hash_64[764])<=(out_64[3]))){
		*out_64   = hash_64[752]; out_64[1] = hash_64[756];
		out_64[2] = hash_64[760]; out_64[3] = hash_64[764];
	}
#endif
#if MEMORY_THREADS > 48
	if(((hash_64[768])<=(*out_64  ))
	&& ((hash_64[772])<=(out_64[1]))
	&& ((hash_64[776])<=(out_64[2]))
	&& ((hash_64[780])<=(out_64[3]))){
		*out_64   = hash_64[768]; out_64[1] = hash_64[772];
		out_64[2] = hash_64[776]; out_64[3] = hash_64[780];
	}
#endif
#if MEMORY_THREADS > 49
	if(((hash_64[784])<=(*out_64  ))
	&& ((hash_64[788])<=(out_64[1]))
	&& ((hash_64[792])<=(out_64[2]))
	&& ((hash_64[796])<=(out_64[3]))){
		*out_64   = hash_64[784]; out_64[1] = hash_64[788];
		out_64[2] = hash_64[792]; out_64[3] = hash_64[796];
	}
#endif
#if MEMORY_THREADS > 50
	if(((hash_64[800])<=(*out_64  ))
	&& ((hash_64[804])<=(out_64[1]))
	&& ((hash_64[808])<=(out_64[2]))
	&& ((hash_64[812])<=(out_64[3]))){
		*out_64   = hash_64[800]; out_64[1] = hash_64[804];
		out_64[2] = hash_64[808]; out_64[3] = hash_64[812];
	}
#endif
#if MEMORY_THREADS > 51
	if(((hash_64[816])<=(*out_64  ))
	&& ((hash_64[820])<=(out_64[1]))
	&& ((hash_64[824])<=(out_64[2]))
	&& ((hash_64[828])<=(out_64[3]))){
		*out_64   = hash_64[816]; out_64[1] = hash_64[820];
		out_64[2] = hash_64[824]; out_64[3] = hash_64[828];
	}
#endif
#if MEMORY_THREADS > 52
	if(((hash_64[832])<=(*out_64  ))
	&& ((hash_64[836])<=(out_64[1]))
	&& ((hash_64[840])<=(out_64[2]))
	&& ((hash_64[844])<=(out_64[3]))){
		*out_64   = hash_64[832]; out_64[1] = hash_64[836];
		out_64[2] = hash_64[840]; out_64[3] = hash_64[844];
	}
#endif
#if MEMORY_THREADS > 53
	if(((hash_64[848])<=(*out_64  ))
	&& ((hash_64[852])<=(out_64[1]))
	&& ((hash_64[856])<=(out_64[2]))
	&& ((hash_64[860])<=(out_64[3]))){
		*out_64   = hash_64[848]; out_64[1] = hash_64[852];
		out_64[2] = hash_64[856]; out_64[3] = hash_64[860];
	}
#endif
#if MEMORY_THREADS > 54
	if(((hash_64[864])<=(*out_64  ))
	&& ((hash_64[868])<=(out_64[1]))
	&& ((hash_64[872])<=(out_64[2]))
	&& ((hash_64[876])<=(out_64[3]))){
		*out_64   = hash_64[864]; out_64[1] = hash_64[868];
		out_64[2] = hash_64[872]; out_64[3] = hash_64[876];
	}
#endif
#if MEMORY_THREADS > 55
	if(((hash_64[880])<=(*out_64  ))
	&& ((hash_64[884])<=(out_64[1]))
	&& ((hash_64[888])<=(out_64[2]))
	&& ((hash_64[892])<=(out_64[3]))){
		*out_64   = hash_64[880]; out_64[1] = hash_64[884];
		out_64[2] = hash_64[888]; out_64[3] = hash_64[892];
	}
#endif
#if MEMORY_THREADS > 56
	if(((hash_64[896])<=(*out_64  ))
	&& ((hash_64[900])<=(out_64[1]))
	&& ((hash_64[904])<=(out_64[2]))
	&& ((hash_64[908])<=(out_64[3]))){
		*out_64   = hash_64[896]; out_64[1] = hash_64[900];
		out_64[2] = hash_64[904]; out_64[3] = hash_64[908];
	}
#endif
#if MEMORY_THREADS > 57
	if(((hash_64[912])<=(*out_64  ))
	&& ((hash_64[916])<=(out_64[1]))
	&& ((hash_64[920])<=(out_64[2]))
	&& ((hash_64[924])<=(out_64[3]))){
		*out_64   = hash_64[912]; out_64[1] = hash_64[916];
		out_64[2] = hash_64[920]; out_64[3] = hash_64[924];
	}
#endif
#if MEMORY_THREADS > 58
	if(((hash_64[928])<=(*out_64  ))
	&& ((hash_64[932])<=(out_64[1]))
	&& ((hash_64[936])<=(out_64[2]))
	&& ((hash_64[940])<=(out_64[3]))){
		*out_64   = hash_64[928]; out_64[1] = hash_64[932];
		out_64[2] = hash_64[936]; out_64[3] = hash_64[940];
	}
#endif
#if MEMORY_THREADS > 59
	if(((hash_64[944])<=(*out_64  ))
	&& ((hash_64[948])<=(out_64[1]))
	&& ((hash_64[952])<=(out_64[2]))
	&& ((hash_64[956])<=(out_64[3]))){
		*out_64   = hash_64[944]; out_64[1] = hash_64[948];
		out_64[2] = hash_64[952]; out_64[3] = hash_64[956];
	}
#endif
#if MEMORY_THREADS > 60
	if(((hash_64[960])<=(*out_64  ))
	&& ((hash_64[964])<=(out_64[1]))
	&& ((hash_64[968])<=(out_64[2]))
	&& ((hash_64[972])<=(out_64[3]))){
		*out_64   = hash_64[960]; out_64[1] = hash_64[964];
		out_64[2] = hash_64[968]; out_64[3] = hash_64[972];
	}
#endif
#if MEMORY_THREADS > 61
	if(((hash_64[976])<=(*out_64  ))
	&& ((hash_64[980])<=(out_64[1]))
	&& ((hash_64[984])<=(out_64[2]))
	&& ((hash_64[988])<=(out_64[3]))){
		*out_64   = hash_64[976]; out_64[1] = hash_64[980];
		out_64[2] = hash_64[984]; out_64[3] = hash_64[988];
	}
#endif
#if MEMORY_THREADS > 62
	if(((hash_64[992])<=(*out_64  ))
	&& ((hash_64[996])<=(out_64[1]))
	&& ((hash_64[1000])<=(out_64[2]))
	&& ((hash_64[1004])<=(out_64[3]))){
		*out_64   = hash_64[992]; out_64[1] = hash_64[996];
		out_64[2] = hash_64[1000]; out_64[3] = hash_64[1004];
	}
#endif
#if MEMORY_THREADS > 63
	if(((hash_64[1008])<=(*out_64  ))
	&& ((hash_64[1012])<=(out_64[1]))
	&& ((hash_64[1016])<=(out_64[2]))
	&& ((hash_64[1020])<=(out_64[3]))){
		*out_64   = hash_64[1008]; out_64[1] = hash_64[1012];
		out_64[2] = hash_64[1016]; out_64[3] = hash_64[1020];
	}
#endif
#if MEMORY_THREADS > 64
	if(((hash_64[1024])<=(*out_64  ))
	&& ((hash_64[1028])<=(out_64[1]))
	&& ((hash_64[1032])<=(out_64[2]))
	&& ((hash_64[1036])<=(out_64[3]))){
		*out_64   = hash_64[1024]; out_64[1] = hash_64[1028];
		out_64[2] = hash_64[1032]; out_64[3] = hash_64[1036];
	}
#endif
#if MEMORY_THREADS > 65
	if(((hash_64[1040])<=(*out_64  ))
	&& ((hash_64[1044])<=(out_64[1]))
	&& ((hash_64[1048])<=(out_64[2]))
	&& ((hash_64[1052])<=(out_64[3]))){
		*out_64   = hash_64[1040]; out_64[1] = hash_64[1044];
		out_64[2] = hash_64[1048]; out_64[3] = hash_64[1052];
	}
#endif
#if MEMORY_THREADS > 66
	if(((hash_64[1056])<=(*out_64  ))
	&& ((hash_64[1060])<=(out_64[1]))
	&& ((hash_64[1064])<=(out_64[2]))
	&& ((hash_64[1068])<=(out_64[3]))){
		*out_64   = hash_64[1056]; out_64[1] = hash_64[1060];
		out_64[2] = hash_64[1064]; out_64[3] = hash_64[1068];
	}
#endif
#if MEMORY_THREADS > 67
	if(((hash_64[1072])<=(*out_64  ))
	&& ((hash_64[1076])<=(out_64[1]))
	&& ((hash_64[1080])<=(out_64[2]))
	&& ((hash_64[1084])<=(out_64[3]))){
		*out_64   = hash_64[1072]; out_64[1] = hash_64[1076];
		out_64[2] = hash_64[1080]; out_64[3] = hash_64[1084];
	}
#endif
#if MEMORY_THREADS > 68
	if(((hash_64[1088])<=(*out_64  ))
	&& ((hash_64[1092])<=(out_64[1]))
	&& ((hash_64[1096])<=(out_64[2]))
	&& ((hash_64[1100])<=(out_64[3]))){
		*out_64   = hash_64[1088]; out_64[1] = hash_64[1092];
		out_64[2] = hash_64[1096]; out_64[3] = hash_64[1100];
	}
#endif
#if MEMORY_THREADS > 69
	if(((hash_64[1104])<=(*out_64  ))
	&& ((hash_64[1108])<=(out_64[1]))
	&& ((hash_64[1112])<=(out_64[2]))
	&& ((hash_64[1116])<=(out_64[3]))){
		*out_64   = hash_64[1104]; out_64[1] = hash_64[1108];
		out_64[2] = hash_64[1112]; out_64[3] = hash_64[1116];
	}
#endif
#if MEMORY_THREADS > 70
	if(((hash_64[1120])<=(*out_64  ))
	&& ((hash_64[1124])<=(out_64[1]))
	&& ((hash_64[1128])<=(out_64[2]))
	&& ((hash_64[1132])<=(out_64[3]))){
		*out_64   = hash_64[1120]; out_64[1] = hash_64[1124];
		out_64[2] = hash_64[1128]; out_64[3] = hash_64[1132];
	}
#endif
#if MEMORY_THREADS > 71
	if(((hash_64[1136])<=(*out_64  ))
	&& ((hash_64[1140])<=(out_64[1]))
	&& ((hash_64[1144])<=(out_64[2]))
	&& ((hash_64[1148])<=(out_64[3]))){
		*out_64   = hash_64[1136]; out_64[1] = hash_64[1140];
		out_64[2] = hash_64[1144]; out_64[3] = hash_64[1148];
	}
#endif
#if MEMORY_THREADS > 72
	if(((hash_64[1152])<=(*out_64  ))
	&& ((hash_64[1156])<=(out_64[1]))
	&& ((hash_64[1160])<=(out_64[2]))
	&& ((hash_64[1164])<=(out_64[3]))){
		*out_64   = hash_64[1152]; out_64[1] = hash_64[1156];
		out_64[2] = hash_64[1160]; out_64[3] = hash_64[1164];
	}
#endif
#if MEMORY_THREADS > 73
	if(((hash_64[1168])<=(*out_64  ))
	&& ((hash_64[1172])<=(out_64[1]))
	&& ((hash_64[1176])<=(out_64[2]))
	&& ((hash_64[1180])<=(out_64[3]))){
		*out_64   = hash_64[1168]; out_64[1] = hash_64[1172];
		out_64[2] = hash_64[1176]; out_64[3] = hash_64[1180];
	}
#endif
#if MEMORY_THREADS > 74
	if(((hash_64[1184])<=(*out_64  ))
	&& ((hash_64[1188])<=(out_64[1]))
	&& ((hash_64[1192])<=(out_64[2]))
	&& ((hash_64[1196])<=(out_64[3]))){
		*out_64   = hash_64[1184]; out_64[1] = hash_64[1188];
		out_64[2] = hash_64[1192]; out_64[3] = hash_64[1196];
	}
#endif
#if MEMORY_THREADS > 75
	if(((hash_64[1200])<=(*out_64  ))
	&& ((hash_64[1204])<=(out_64[1]))
	&& ((hash_64[1208])<=(out_64[2]))
	&& ((hash_64[1212])<=(out_64[3]))){
		*out_64   = hash_64[1200]; out_64[1] = hash_64[1204];
		out_64[2] = hash_64[1208]; out_64[3] = hash_64[1212];
	}
#endif
#if MEMORY_THREADS > 76
	if(((hash_64[1216])<=(*out_64  ))
	&& ((hash_64[1220])<=(out_64[1]))
	&& ((hash_64[1224])<=(out_64[2]))
	&& ((hash_64[1228])<=(out_64[3]))){
		*out_64   = hash_64[1216]; out_64[1] = hash_64[1220];
		out_64[2] = hash_64[1224]; out_64[3] = hash_64[1228];
	}
#endif
#if MEMORY_THREADS > 77
	if(((hash_64[1232])<=(*out_64  ))
	&& ((hash_64[1236])<=(out_64[1]))
	&& ((hash_64[1240])<=(out_64[2]))
	&& ((hash_64[1244])<=(out_64[3]))){
		*out_64   = hash_64[1232]; out_64[1] = hash_64[1236];
		out_64[2] = hash_64[1240]; out_64[3] = hash_64[1244];
	}
#endif
#if MEMORY_THREADS > 78
	if(((hash_64[1248])<=(*out_64  ))
	&& ((hash_64[1252])<=(out_64[1]))
	&& ((hash_64[1256])<=(out_64[2]))
	&& ((hash_64[1260])<=(out_64[3]))){
		*out_64   = hash_64[1248]; out_64[1] = hash_64[1252];
		out_64[2] = hash_64[1256]; out_64[3] = hash_64[1260];
	}
#endif
#if MEMORY_THREADS > 79
	if(((hash_64[1264])<=(*out_64  ))
	&& ((hash_64[1268])<=(out_64[1]))
	&& ((hash_64[1272])<=(out_64[2]))
	&& ((hash_64[1276])<=(out_64[3]))){
		*out_64   = hash_64[1264]; out_64[1] = hash_64[1268];
		out_64[2] = hash_64[1272]; out_64[3] = hash_64[1276];
	}
#endif
#if MEMORY_THREADS > 80
	if(((hash_64[1280])<=(*out_64  ))
	&& ((hash_64[1284])<=(out_64[1]))
	&& ((hash_64[1288])<=(out_64[2]))
	&& ((hash_64[1292])<=(out_64[3]))){
		*out_64   = hash_64[1280]; out_64[1] = hash_64[1284];
		out_64[2] = hash_64[1288]; out_64[3] = hash_64[1292];
	}
#endif
#if MEMORY_THREADS > 81
	if(((hash_64[1296])<=(*out_64  ))
	&& ((hash_64[1300])<=(out_64[1]))
	&& ((hash_64[1304])<=(out_64[2]))
	&& ((hash_64[1308])<=(out_64[3]))){
		*out_64   = hash_64[1296]; out_64[1] = hash_64[1300];
		out_64[2] = hash_64[1304]; out_64[3] = hash_64[1308];
	}
#endif
#if MEMORY_THREADS > 82
	if(((hash_64[1312])<=(*out_64  ))
	&& ((hash_64[1316])<=(out_64[1]))
	&& ((hash_64[1320])<=(out_64[2]))
	&& ((hash_64[1324])<=(out_64[3]))){
		*out_64   = hash_64[1312]; out_64[1] = hash_64[1316];
		out_64[2] = hash_64[1320]; out_64[3] = hash_64[1324];
	}
#endif
#if MEMORY_THREADS > 83
	if(((hash_64[1328])<=(*out_64  ))
	&& ((hash_64[1332])<=(out_64[1]))
	&& ((hash_64[1336])<=(out_64[2]))
	&& ((hash_64[1340])<=(out_64[3]))){
		*out_64   = hash_64[1328]; out_64[1] = hash_64[1332];
		out_64[2] = hash_64[1336]; out_64[3] = hash_64[1340];
	}
#endif
#if MEMORY_THREADS > 84
	if(((hash_64[1344])<=(*out_64  ))
	&& ((hash_64[1348])<=(out_64[1]))
	&& ((hash_64[1352])<=(out_64[2]))
	&& ((hash_64[1356])<=(out_64[3]))){
		*out_64   = hash_64[1344]; out_64[1] = hash_64[1348];
		out_64[2] = hash_64[1352]; out_64[3] = hash_64[1356];
	}
#endif
#if MEMORY_THREADS > 85
	if(((hash_64[1360])<=(*out_64  ))
	&& ((hash_64[1364])<=(out_64[1]))
	&& ((hash_64[1368])<=(out_64[2]))
	&& ((hash_64[1372])<=(out_64[3]))){
		*out_64   = hash_64[1360]; out_64[1] = hash_64[1364];
		out_64[2] = hash_64[1368]; out_64[3] = hash_64[1372];
	}
#endif
#if MEMORY_THREADS > 86
	if(((hash_64[1376])<=(*out_64  ))
	&& ((hash_64[1380])<=(out_64[1]))
	&& ((hash_64[1384])<=(out_64[2]))
	&& ((hash_64[1388])<=(out_64[3]))){
		*out_64   = hash_64[1376]; out_64[1] = hash_64[1380];
		out_64[2] = hash_64[1384]; out_64[3] = hash_64[1388];
	}
#endif
#if MEMORY_THREADS > 87
	if(((hash_64[1392])<=(*out_64  ))
	&& ((hash_64[1396])<=(out_64[1]))
	&& ((hash_64[1400])<=(out_64[2]))
	&& ((hash_64[1404])<=(out_64[3]))){
		*out_64   = hash_64[1392]; out_64[1] = hash_64[1396];
		out_64[2] = hash_64[1400]; out_64[3] = hash_64[1404];
	}
#endif
#if MEMORY_THREADS > 88
	if(((hash_64[1408])<=(*out_64  ))
	&& ((hash_64[1412])<=(out_64[1]))
	&& ((hash_64[1416])<=(out_64[2]))
	&& ((hash_64[1420])<=(out_64[3]))){
		*out_64   = hash_64[1408]; out_64[1] = hash_64[1412];
		out_64[2] = hash_64[1416]; out_64[3] = hash_64[1420];
	}
#endif
#if MEMORY_THREADS > 89
	if(((hash_64[1424])<=(*out_64  ))
	&& ((hash_64[1428])<=(out_64[1]))
	&& ((hash_64[1432])<=(out_64[2]))
	&& ((hash_64[1436])<=(out_64[3]))){
		*out_64   = hash_64[1424]; out_64[1] = hash_64[1428];
		out_64[2] = hash_64[1432]; out_64[3] = hash_64[1436];
	}
#endif
#if MEMORY_THREADS > 90
	if(((hash_64[1440])<=(*out_64  ))
	&& ((hash_64[1444])<=(out_64[1]))
	&& ((hash_64[1448])<=(out_64[2]))
	&& ((hash_64[1452])<=(out_64[3]))){
		*out_64   = hash_64[1440]; out_64[1] = hash_64[1444];
		out_64[2] = hash_64[1448]; out_64[3] = hash_64[1452];
	}
#endif
#if MEMORY_THREADS > 91
	if(((hash_64[1456])<=(*out_64  ))
	&& ((hash_64[1460])<=(out_64[1]))
	&& ((hash_64[1464])<=(out_64[2]))
	&& ((hash_64[1468])<=(out_64[3]))){
		*out_64   = hash_64[1456]; out_64[1] = hash_64[1460];
		out_64[2] = hash_64[1464]; out_64[3] = hash_64[1468];
	}
#endif
#if MEMORY_THREADS > 92
	if(((hash_64[1472])<=(*out_64  ))
	&& ((hash_64[1476])<=(out_64[1]))
	&& ((hash_64[1480])<=(out_64[2]))
	&& ((hash_64[1484])<=(out_64[3]))){
		*out_64   = hash_64[1472]; out_64[1] = hash_64[1476];
		out_64[2] = hash_64[1480]; out_64[3] = hash_64[1484];
	}
#endif
#if MEMORY_THREADS > 93
	if(((hash_64[1488])<=(*out_64  ))
	&& ((hash_64[1492])<=(out_64[1]))
	&& ((hash_64[1496])<=(out_64[2]))
	&& ((hash_64[1500])<=(out_64[3]))){
		*out_64   = hash_64[1488]; out_64[1] = hash_64[1492];
		out_64[2] = hash_64[1496]; out_64[3] = hash_64[1500];
	}
#endif
#if MEMORY_THREADS > 94
	if(((hash_64[1504])<=(*out_64  ))
	&& ((hash_64[1508])<=(out_64[1]))
	&& ((hash_64[1512])<=(out_64[2]))
	&& ((hash_64[1516])<=(out_64[3]))){
		*out_64   = hash_64[1504]; out_64[1] = hash_64[1508];
		out_64[2] = hash_64[1512]; out_64[3] = hash_64[1516];
	}
#endif
#if MEMORY_THREADS > 95
	if(((hash_64[1520])<=(*out_64  ))
	&& ((hash_64[1524])<=(out_64[1]))
	&& ((hash_64[1528])<=(out_64[2]))
	&& ((hash_64[1532])<=(out_64[3]))){
		*out_64   = hash_64[1520]; out_64[1] = hash_64[1524];
		out_64[2] = hash_64[1528]; out_64[3] = hash_64[1532];
	}
#endif
#if MEMORY_THREADS > 96
	if(((hash_64[1536])<=(*out_64  ))
	&& ((hash_64[1540])<=(out_64[1]))
	&& ((hash_64[1544])<=(out_64[2]))
	&& ((hash_64[1548])<=(out_64[3]))){
		*out_64   = hash_64[1536]; out_64[1] = hash_64[1540];
		out_64[2] = hash_64[1544]; out_64[3] = hash_64[1548];
	}
#endif
#if MEMORY_THREADS > 97
	if(((hash_64[1552])<=(*out_64  ))
	&& ((hash_64[1556])<=(out_64[1]))
	&& ((hash_64[1560])<=(out_64[2]))
	&& ((hash_64[1564])<=(out_64[3]))){
		*out_64   = hash_64[1552]; out_64[1] = hash_64[1556];
		out_64[2] = hash_64[1560]; out_64[3] = hash_64[1564];
	}
#endif
#if MEMORY_THREADS > 98
	if(((hash_64[1568])<=(*out_64  ))
	&& ((hash_64[1572])<=(out_64[1]))
	&& ((hash_64[1576])<=(out_64[2]))
	&& ((hash_64[1580])<=(out_64[3]))){
		*out_64   = hash_64[1568]; out_64[1] = hash_64[1572];
		out_64[2] = hash_64[1576]; out_64[3] = hash_64[1580];
	}
#endif
#if MEMORY_THREADS > 99
	if(((hash_64[1584])<=(*out_64  ))
	&& ((hash_64[1588])<=(out_64[1]))
	&& ((hash_64[1592])<=(out_64[2]))
	&& ((hash_64[1596])<=(out_64[3]))){
		*out_64   = hash_64[1584]; out_64[1] = hash_64[1588];
		out_64[2] = hash_64[1592]; out_64[3] = hash_64[1596];
	}
#endif
#if MEMORY_THREADS > 100
	if(((hash_64[1600])<=(*out_64  ))
	&& ((hash_64[1604])<=(out_64[1]))
	&& ((hash_64[1608])<=(out_64[2]))
	&& ((hash_64[1612])<=(out_64[3]))){
		*out_64   = hash_64[1600]; out_64[1] = hash_64[1604];
		out_64[2] = hash_64[1608]; out_64[3] = hash_64[1612];
	}
#endif
#if MEMORY_THREADS > 101
	if(((hash_64[1616])<=(*out_64  ))
	&& ((hash_64[1620])<=(out_64[1]))
	&& ((hash_64[1624])<=(out_64[2]))
	&& ((hash_64[1628])<=(out_64[3]))){
		*out_64   = hash_64[1616]; out_64[1] = hash_64[1620];
		out_64[2] = hash_64[1624]; out_64[3] = hash_64[1628];
	}
#endif
#if MEMORY_THREADS > 102
	if(((hash_64[1632])<=(*out_64  ))
	&& ((hash_64[1636])<=(out_64[1]))
	&& ((hash_64[1640])<=(out_64[2]))
	&& ((hash_64[1644])<=(out_64[3]))){
		*out_64   = hash_64[1632]; out_64[1] = hash_64[1636];
		out_64[2] = hash_64[1640]; out_64[3] = hash_64[1644];
	}
#endif
#if MEMORY_THREADS > 103
	if(((hash_64[1648])<=(*out_64  ))
	&& ((hash_64[1652])<=(out_64[1]))
	&& ((hash_64[1656])<=(out_64[2]))
	&& ((hash_64[1660])<=(out_64[3]))){
		*out_64   = hash_64[1648]; out_64[1] = hash_64[1652];
		out_64[2] = hash_64[1656]; out_64[3] = hash_64[1660];
	}
#endif
#if MEMORY_THREADS > 104
	if(((hash_64[1664])<=(*out_64  ))
	&& ((hash_64[1668])<=(out_64[1]))
	&& ((hash_64[1672])<=(out_64[2]))
	&& ((hash_64[1676])<=(out_64[3]))){
		*out_64   = hash_64[1664]; out_64[1] = hash_64[1668];
		out_64[2] = hash_64[1672]; out_64[3] = hash_64[1676];
	}
#endif
#if MEMORY_THREADS > 105
	if(((hash_64[1680])<=(*out_64  ))
	&& ((hash_64[1684])<=(out_64[1]))
	&& ((hash_64[1688])<=(out_64[2]))
	&& ((hash_64[1692])<=(out_64[3]))){
		*out_64   = hash_64[1680]; out_64[1] = hash_64[1684];
		out_64[2] = hash_64[1688]; out_64[3] = hash_64[1692];
	}
#endif
#if MEMORY_THREADS > 106
	if(((hash_64[1696])<=(*out_64  ))
	&& ((hash_64[1700])<=(out_64[1]))
	&& ((hash_64[1704])<=(out_64[2]))
	&& ((hash_64[1708])<=(out_64[3]))){
		*out_64   = hash_64[1696]; out_64[1] = hash_64[1700];
		out_64[2] = hash_64[1704]; out_64[3] = hash_64[1708];
	}
#endif
#if MEMORY_THREADS > 107
	if(((hash_64[1712])<=(*out_64  ))
	&& ((hash_64[1716])<=(out_64[1]))
	&& ((hash_64[1720])<=(out_64[2]))
	&& ((hash_64[1724])<=(out_64[3]))){
		*out_64   = hash_64[1712]; out_64[1] = hash_64[1716];
		out_64[2] = hash_64[1720]; out_64[3] = hash_64[1724];
	}
#endif
#if MEMORY_THREADS > 108
	if(((hash_64[1728])<=(*out_64  ))
	&& ((hash_64[1732])<=(out_64[1]))
	&& ((hash_64[1736])<=(out_64[2]))
	&& ((hash_64[1740])<=(out_64[3]))){
		*out_64   = hash_64[1728]; out_64[1] = hash_64[1732];
		out_64[2] = hash_64[1736]; out_64[3] = hash_64[1740];
	}
#endif
#if MEMORY_THREADS > 109
	if(((hash_64[1744])<=(*out_64  ))
	&& ((hash_64[1748])<=(out_64[1]))
	&& ((hash_64[1752])<=(out_64[2]))
	&& ((hash_64[1756])<=(out_64[3]))){
		*out_64   = hash_64[1744]; out_64[1] = hash_64[1748];
		out_64[2] = hash_64[1752]; out_64[3] = hash_64[1756];
	}
#endif
#if MEMORY_THREADS > 110
	if(((hash_64[1760])<=(*out_64  ))
	&& ((hash_64[1764])<=(out_64[1]))
	&& ((hash_64[1768])<=(out_64[2]))
	&& ((hash_64[1772])<=(out_64[3]))){
		*out_64   = hash_64[1760]; out_64[1] = hash_64[1764];
		out_64[2] = hash_64[1768]; out_64[3] = hash_64[1772];
	}
#endif
#if MEMORY_THREADS > 111
	if(((hash_64[1776])<=(*out_64  ))
	&& ((hash_64[1780])<=(out_64[1]))
	&& ((hash_64[1784])<=(out_64[2]))
	&& ((hash_64[1788])<=(out_64[3]))){
		*out_64   = hash_64[1776]; out_64[1] = hash_64[1780];
		out_64[2] = hash_64[1784]; out_64[3] = hash_64[1788];
	}
#endif
#if MEMORY_THREADS > 112
	if(((hash_64[1792])<=(*out_64  ))
	&& ((hash_64[1796])<=(out_64[1]))
	&& ((hash_64[1800])<=(out_64[2]))
	&& ((hash_64[1804])<=(out_64[3]))){
		*out_64   = hash_64[1792]; out_64[1] = hash_64[1796];
		out_64[2] = hash_64[1800]; out_64[3] = hash_64[1804];
	}
#endif
#if MEMORY_THREADS > 113
	if(((hash_64[1808])<=(*out_64  ))
	&& ((hash_64[1812])<=(out_64[1]))
	&& ((hash_64[1816])<=(out_64[2]))
	&& ((hash_64[1820])<=(out_64[3]))){
		*out_64   = hash_64[1808]; out_64[1] = hash_64[1812];
		out_64[2] = hash_64[1816]; out_64[3] = hash_64[1820];
	}
#endif
#if MEMORY_THREADS > 114
	if(((hash_64[1824])<=(*out_64  ))
	&& ((hash_64[1828])<=(out_64[1]))
	&& ((hash_64[1832])<=(out_64[2]))
	&& ((hash_64[1836])<=(out_64[3]))){
		*out_64   = hash_64[1824]; out_64[1] = hash_64[1828];
		out_64[2] = hash_64[1832]; out_64[3] = hash_64[1836];
	}
#endif
#if MEMORY_THREADS > 115
	if(((hash_64[1840])<=(*out_64  ))
	&& ((hash_64[1844])<=(out_64[1]))
	&& ((hash_64[1848])<=(out_64[2]))
	&& ((hash_64[1852])<=(out_64[3]))){
		*out_64   = hash_64[1840]; out_64[1] = hash_64[1844];
		out_64[2] = hash_64[1848]; out_64[3] = hash_64[1852];
	}
#endif
#if MEMORY_THREADS > 116
	if(((hash_64[1856])<=(*out_64  ))
	&& ((hash_64[1860])<=(out_64[1]))
	&& ((hash_64[1864])<=(out_64[2]))
	&& ((hash_64[1868])<=(out_64[3]))){
		*out_64   = hash_64[1856]; out_64[1] = hash_64[1860];
		out_64[2] = hash_64[1864]; out_64[3] = hash_64[1868];
	}
#endif
#if MEMORY_THREADS > 117
	if(((hash_64[1872])<=(*out_64  ))
	&& ((hash_64[1876])<=(out_64[1]))
	&& ((hash_64[1880])<=(out_64[2]))
	&& ((hash_64[1884])<=(out_64[3]))){
		*out_64   = hash_64[1872]; out_64[1] = hash_64[1876];
		out_64[2] = hash_64[1880]; out_64[3] = hash_64[1884];
	}
#endif
#if MEMORY_THREADS > 118
	if(((hash_64[1888])<=(*out_64  ))
	&& ((hash_64[1892])<=(out_64[1]))
	&& ((hash_64[1896])<=(out_64[2]))
	&& ((hash_64[1900])<=(out_64[3]))){
		*out_64   = hash_64[1888]; out_64[1] = hash_64[1892];
		out_64[2] = hash_64[1896]; out_64[3] = hash_64[1900];
	}
#endif
#if MEMORY_THREADS > 119
	if(((hash_64[1904])<=(*out_64  ))
	&& ((hash_64[1908])<=(out_64[1]))
	&& ((hash_64[1912])<=(out_64[2]))
	&& ((hash_64[1916])<=(out_64[3]))){
		*out_64   = hash_64[1904]; out_64[1] = hash_64[1908];
		out_64[2] = hash_64[1912]; out_64[3] = hash_64[1916];
	}
#endif
#if MEMORY_THREADS > 120
	if(((hash_64[1920])<=(*out_64  ))
	&& ((hash_64[1924])<=(out_64[1]))
	&& ((hash_64[1928])<=(out_64[2]))
	&& ((hash_64[1932])<=(out_64[3]))){
		*out_64   = hash_64[1920]; out_64[1] = hash_64[1924];
		out_64[2] = hash_64[1928]; out_64[3] = hash_64[1932];
	}
#endif
#if MEMORY_THREADS > 121
	if(((hash_64[1936])<=(*out_64  ))
	&& ((hash_64[1940])<=(out_64[1]))
	&& ((hash_64[1944])<=(out_64[2]))
	&& ((hash_64[1948])<=(out_64[3]))){
		*out_64   = hash_64[1936]; out_64[1] = hash_64[1940];
		out_64[2] = hash_64[1944]; out_64[3] = hash_64[1948];
	}
#endif
#if MEMORY_THREADS > 122
	if(((hash_64[1952])<=(*out_64  ))
	&& ((hash_64[1956])<=(out_64[1]))
	&& ((hash_64[1960])<=(out_64[2]))
	&& ((hash_64[1964])<=(out_64[3]))){
		*out_64   = hash_64[1952]; out_64[1] = hash_64[1956];
		out_64[2] = hash_64[1960]; out_64[3] = hash_64[1964];
	}
#endif
#if MEMORY_THREADS > 123
	if(((hash_64[1968])<=(*out_64  ))
	&& ((hash_64[1972])<=(out_64[1]))
	&& ((hash_64[1976])<=(out_64[2]))
	&& ((hash_64[1980])<=(out_64[3]))){
		*out_64   = hash_64[1968]; out_64[1] = hash_64[1972];
		out_64[2] = hash_64[1976]; out_64[3] = hash_64[1980];
	}
#endif
#if MEMORY_THREADS > 124
	if(((hash_64[1984])<=(*out_64  ))
	&& ((hash_64[1988])<=(out_64[1]))
	&& ((hash_64[1992])<=(out_64[2]))
	&& ((hash_64[1996])<=(out_64[3]))){
		*out_64   = hash_64[1984]; out_64[1] = hash_64[1988];
		out_64[2] = hash_64[1992]; out_64[3] = hash_64[1996];
	}
#endif
#if MEMORY_THREADS > 125
	if(((hash_64[2000])<=(*out_64  ))
	&& ((hash_64[2004])<=(out_64[1]))
	&& ((hash_64[2008])<=(out_64[2]))
	&& ((hash_64[2012])<=(out_64[3]))){
		*out_64   = hash_64[2000]; out_64[1] = hash_64[2004];
		out_64[2] = hash_64[2008]; out_64[3] = hash_64[2012];
	}
#endif
#if MEMORY_THREADS > 126
	if(((hash_64[2016])<=(*out_64  ))
	&& ((hash_64[2020])<=(out_64[1]))
	&& ((hash_64[2024])<=(out_64[2]))
	&& ((hash_64[2028])<=(out_64[3]))){
		*out_64   = hash_64[2016]; out_64[1] = hash_64[2020];
		out_64[2] = hash_64[2024]; out_64[3] = hash_64[2028];
	}
#endif
#if MEMORY_THREADS > 127
	if(((hash_64[2032])<=(*out_64  ))
	&& ((hash_64[2036])<=(out_64[1]))
	&& ((hash_64[2040])<=(out_64[2]))
	&& ((hash_64[2044])<=(out_64[3]))){
		*out_64   = hash_64[2032]; out_64[1] = hash_64[2036];
		out_64[2] = hash_64[2040]; out_64[3] = hash_64[2044];
	}
#endif
#if MEMORY_THREADS > 128
	if(((hash_64[2048])<=(*out_64  ))
	&& ((hash_64[2052])<=(out_64[1]))
	&& ((hash_64[2056])<=(out_64[2]))
	&& ((hash_64[2060])<=(out_64[3]))){
		*out_64   = hash_64[2048]; out_64[1] = hash_64[2052];
		out_64[2] = hash_64[2056]; out_64[3] = hash_64[2060];
	}
#endif
#if MEMORY_THREADS > 129
	if(((hash_64[2064])<=(*out_64  ))
	&& ((hash_64[2068])<=(out_64[1]))
	&& ((hash_64[2072])<=(out_64[2]))
	&& ((hash_64[2076])<=(out_64[3]))){
		*out_64   = hash_64[2064]; out_64[1] = hash_64[2068];
		out_64[2] = hash_64[2072]; out_64[3] = hash_64[2076];
	}
#endif
#if MEMORY_THREADS > 130
	if(((hash_64[2080])<=(*out_64  ))
	&& ((hash_64[2084])<=(out_64[1]))
	&& ((hash_64[2088])<=(out_64[2]))
	&& ((hash_64[2092])<=(out_64[3]))){
		*out_64   = hash_64[2080]; out_64[1] = hash_64[2084];
		out_64[2] = hash_64[2088]; out_64[3] = hash_64[2092];
	}
#endif
#if MEMORY_THREADS > 131
	if(((hash_64[2096])<=(*out_64  ))
	&& ((hash_64[2100])<=(out_64[1]))
	&& ((hash_64[2104])<=(out_64[2]))
	&& ((hash_64[2108])<=(out_64[3]))){
		*out_64   = hash_64[2096]; out_64[1] = hash_64[2100];
		out_64[2] = hash_64[2104]; out_64[3] = hash_64[2108];
	}
#endif
#if MEMORY_THREADS > 132
	if(((hash_64[2112])<=(*out_64  ))
	&& ((hash_64[2116])<=(out_64[1]))
	&& ((hash_64[2120])<=(out_64[2]))
	&& ((hash_64[2124])<=(out_64[3]))){
		*out_64   = hash_64[2112]; out_64[1] = hash_64[2116];
		out_64[2] = hash_64[2120]; out_64[3] = hash_64[2124];
	}
#endif
#if MEMORY_THREADS > 133
	if(((hash_64[2128])<=(*out_64  ))
	&& ((hash_64[2132])<=(out_64[1]))
	&& ((hash_64[2136])<=(out_64[2]))
	&& ((hash_64[2140])<=(out_64[3]))){
		*out_64   = hash_64[2128]; out_64[1] = hash_64[2132];
		out_64[2] = hash_64[2136]; out_64[3] = hash_64[2140];
	}
#endif
#if MEMORY_THREADS > 134
	if(((hash_64[2144])<=(*out_64  ))
	&& ((hash_64[2148])<=(out_64[1]))
	&& ((hash_64[2152])<=(out_64[2]))
	&& ((hash_64[2156])<=(out_64[3]))){
		*out_64   = hash_64[2144]; out_64[1] = hash_64[2148];
		out_64[2] = hash_64[2152]; out_64[3] = hash_64[2156];
	}
#endif
#if MEMORY_THREADS > 135
	if(((hash_64[2160])<=(*out_64  ))
	&& ((hash_64[2164])<=(out_64[1]))
	&& ((hash_64[2168])<=(out_64[2]))
	&& ((hash_64[2172])<=(out_64[3]))){
		*out_64   = hash_64[2160]; out_64[1] = hash_64[2164];
		out_64[2] = hash_64[2168]; out_64[3] = hash_64[2172];
	}
#endif
#if MEMORY_THREADS > 136
	if(((hash_64[2176])<=(*out_64  ))
	&& ((hash_64[2180])<=(out_64[1]))
	&& ((hash_64[2184])<=(out_64[2]))
	&& ((hash_64[2188])<=(out_64[3]))){
		*out_64   = hash_64[2176]; out_64[1] = hash_64[2180];
		out_64[2] = hash_64[2184]; out_64[3] = hash_64[2188];
	}
#endif
#if MEMORY_THREADS > 137
	if(((hash_64[2192])<=(*out_64  ))
	&& ((hash_64[2196])<=(out_64[1]))
	&& ((hash_64[2200])<=(out_64[2]))
	&& ((hash_64[2204])<=(out_64[3]))){
		*out_64   = hash_64[2192]; out_64[1] = hash_64[2196];
		out_64[2] = hash_64[2200]; out_64[3] = hash_64[2204];
	}
#endif
#if MEMORY_THREADS > 138
	if(((hash_64[2208])<=(*out_64  ))
	&& ((hash_64[2212])<=(out_64[1]))
	&& ((hash_64[2216])<=(out_64[2]))
	&& ((hash_64[2220])<=(out_64[3]))){
		*out_64   = hash_64[2208]; out_64[1] = hash_64[2212];
		out_64[2] = hash_64[2216]; out_64[3] = hash_64[2220];
	}
#endif
#if MEMORY_THREADS > 139
	if(((hash_64[2224])<=(*out_64  ))
	&& ((hash_64[2228])<=(out_64[1]))
	&& ((hash_64[2232])<=(out_64[2]))
	&& ((hash_64[2236])<=(out_64[3]))){
		*out_64   = hash_64[2224]; out_64[1] = hash_64[2228];
		out_64[2] = hash_64[2232]; out_64[3] = hash_64[2236];
	}
#endif
#if MEMORY_THREADS > 140
	if(((hash_64[2240])<=(*out_64  ))
	&& ((hash_64[2244])<=(out_64[1]))
	&& ((hash_64[2248])<=(out_64[2]))
	&& ((hash_64[2252])<=(out_64[3]))){
		*out_64   = hash_64[2240]; out_64[1] = hash_64[2244];
		out_64[2] = hash_64[2248]; out_64[3] = hash_64[2252];
	}
#endif
#if MEMORY_THREADS > 141
	if(((hash_64[2256])<=(*out_64  ))
	&& ((hash_64[2260])<=(out_64[1]))
	&& ((hash_64[2264])<=(out_64[2]))
	&& ((hash_64[2268])<=(out_64[3]))){
		*out_64   = hash_64[2256]; out_64[1] = hash_64[2260];
		out_64[2] = hash_64[2264]; out_64[3] = hash_64[2268];
	}
#endif
#if MEMORY_THREADS > 142
	if(((hash_64[2272])<=(*out_64  ))
	&& ((hash_64[2276])<=(out_64[1]))
	&& ((hash_64[2280])<=(out_64[2]))
	&& ((hash_64[2284])<=(out_64[3]))){
		*out_64   = hash_64[2272]; out_64[1] = hash_64[2276];
		out_64[2] = hash_64[2280]; out_64[3] = hash_64[2284];
	}
#endif
#if MEMORY_THREADS > 143
	if(((hash_64[2288])<=(*out_64  ))
	&& ((hash_64[2292])<=(out_64[1]))
	&& ((hash_64[2296])<=(out_64[2]))
	&& ((hash_64[2300])<=(out_64[3]))){
		*out_64   = hash_64[2288]; out_64[1] = hash_64[2292];
		out_64[2] = hash_64[2296]; out_64[3] = hash_64[2300];
	}
#endif
#if MEMORY_THREADS > 144
	if(((hash_64[2304])<=(*out_64  ))
	&& ((hash_64[2308])<=(out_64[1]))
	&& ((hash_64[2312])<=(out_64[2]))
	&& ((hash_64[2316])<=(out_64[3]))){
		*out_64   = hash_64[2304]; out_64[1] = hash_64[2308];
		out_64[2] = hash_64[2312]; out_64[3] = hash_64[2316];
	}
#endif
#if MEMORY_THREADS > 145
	if(((hash_64[2320])<=(*out_64  ))
	&& ((hash_64[2324])<=(out_64[1]))
	&& ((hash_64[2328])<=(out_64[2]))
	&& ((hash_64[2332])<=(out_64[3]))){
		*out_64   = hash_64[2320]; out_64[1] = hash_64[2324];
		out_64[2] = hash_64[2328]; out_64[3] = hash_64[2332];
	}
#endif
#if MEMORY_THREADS > 146
	if(((hash_64[2336])<=(*out_64  ))
	&& ((hash_64[2340])<=(out_64[1]))
	&& ((hash_64[2344])<=(out_64[2]))
	&& ((hash_64[2348])<=(out_64[3]))){
		*out_64   = hash_64[2336]; out_64[1] = hash_64[2340];
		out_64[2] = hash_64[2344]; out_64[3] = hash_64[2348];
	}
#endif
#if MEMORY_THREADS > 147
	if(((hash_64[2352])<=(*out_64  ))
	&& ((hash_64[2356])<=(out_64[1]))
	&& ((hash_64[2360])<=(out_64[2]))
	&& ((hash_64[2364])<=(out_64[3]))){
		*out_64   = hash_64[2352]; out_64[1] = hash_64[2356];
		out_64[2] = hash_64[2360]; out_64[3] = hash_64[2364];
	}
#endif
#if MEMORY_THREADS > 148
	if(((hash_64[2368])<=(*out_64  ))
	&& ((hash_64[2372])<=(out_64[1]))
	&& ((hash_64[2376])<=(out_64[2]))
	&& ((hash_64[2380])<=(out_64[3]))){
		*out_64   = hash_64[2368]; out_64[1] = hash_64[2372];
		out_64[2] = hash_64[2376]; out_64[3] = hash_64[2380];
	}
#endif
#if MEMORY_THREADS > 149
	if(((hash_64[2384])<=(*out_64  ))
	&& ((hash_64[2388])<=(out_64[1]))
	&& ((hash_64[2392])<=(out_64[2]))
	&& ((hash_64[2396])<=(out_64[3]))){
		*out_64   = hash_64[2384]; out_64[1] = hash_64[2388];
		out_64[2] = hash_64[2392]; out_64[3] = hash_64[2396];
	}
#endif
#if MEMORY_THREADS > 150
	if(((hash_64[2400])<=(*out_64  ))
	&& ((hash_64[2404])<=(out_64[1]))
	&& ((hash_64[2408])<=(out_64[2]))
	&& ((hash_64[2412])<=(out_64[3]))){
		*out_64   = hash_64[2400]; out_64[1] = hash_64[2404];
		out_64[2] = hash_64[2408]; out_64[3] = hash_64[2412];
	}
#endif
#if MEMORY_THREADS > 151
	if(((hash_64[2416])<=(*out_64  ))
	&& ((hash_64[2420])<=(out_64[1]))
	&& ((hash_64[2424])<=(out_64[2]))
	&& ((hash_64[2428])<=(out_64[3]))){
		*out_64   = hash_64[2416]; out_64[1] = hash_64[2420];
		out_64[2] = hash_64[2424]; out_64[3] = hash_64[2428];
	}
#endif
#if MEMORY_THREADS > 152
	if(((hash_64[2432])<=(*out_64  ))
	&& ((hash_64[2436])<=(out_64[1]))
	&& ((hash_64[2440])<=(out_64[2]))
	&& ((hash_64[2444])<=(out_64[3]))){
		*out_64   = hash_64[2432]; out_64[1] = hash_64[2436];
		out_64[2] = hash_64[2440]; out_64[3] = hash_64[2444];
	}
#endif
#if MEMORY_THREADS > 153
	if(((hash_64[2448])<=(*out_64  ))
	&& ((hash_64[2452])<=(out_64[1]))
	&& ((hash_64[2456])<=(out_64[2]))
	&& ((hash_64[2460])<=(out_64[3]))){
		*out_64   = hash_64[2448]; out_64[1] = hash_64[2452];
		out_64[2] = hash_64[2456]; out_64[3] = hash_64[2460];
	}
#endif
#if MEMORY_THREADS > 154
	if(((hash_64[2464])<=(*out_64  ))
	&& ((hash_64[2468])<=(out_64[1]))
	&& ((hash_64[2472])<=(out_64[2]))
	&& ((hash_64[2476])<=(out_64[3]))){
		*out_64   = hash_64[2464]; out_64[1] = hash_64[2468];
		out_64[2] = hash_64[2472]; out_64[3] = hash_64[2476];
	}
#endif
#if MEMORY_THREADS > 155
	if(((hash_64[2480])<=(*out_64  ))
	&& ((hash_64[2484])<=(out_64[1]))
	&& ((hash_64[2488])<=(out_64[2]))
	&& ((hash_64[2492])<=(out_64[3]))){
		*out_64   = hash_64[2480]; out_64[1] = hash_64[2484];
		out_64[2] = hash_64[2488]; out_64[3] = hash_64[2492];
	}
#endif
#if MEMORY_THREADS > 156
	if(((hash_64[2496])<=(*out_64  ))
	&& ((hash_64[2500])<=(out_64[1]))
	&& ((hash_64[2504])<=(out_64[2]))
	&& ((hash_64[2508])<=(out_64[3]))){
		*out_64   = hash_64[2496]; out_64[1] = hash_64[2500];
		out_64[2] = hash_64[2504]; out_64[3] = hash_64[2508];
	}
#endif
#if MEMORY_THREADS > 157
	if(((hash_64[2512])<=(*out_64  ))
	&& ((hash_64[2516])<=(out_64[1]))
	&& ((hash_64[2520])<=(out_64[2]))
	&& ((hash_64[2524])<=(out_64[3]))){
		*out_64   = hash_64[2512]; out_64[1] = hash_64[2516];
		out_64[2] = hash_64[2520]; out_64[3] = hash_64[2524];
	}
#endif
#if MEMORY_THREADS > 158
	if(((hash_64[2528])<=(*out_64  ))
	&& ((hash_64[2532])<=(out_64[1]))
	&& ((hash_64[2536])<=(out_64[2]))
	&& ((hash_64[2540])<=(out_64[3]))){
		*out_64   = hash_64[2528]; out_64[1] = hash_64[2532];
		out_64[2] = hash_64[2536]; out_64[3] = hash_64[2540];
	}
#endif
#if MEMORY_THREADS > 159
	if(((hash_64[2544])<=(*out_64  ))
	&& ((hash_64[2548])<=(out_64[1]))
	&& ((hash_64[2552])<=(out_64[2]))
	&& ((hash_64[2556])<=(out_64[3]))){
		*out_64   = hash_64[2544]; out_64[1] = hash_64[2548];
		out_64[2] = hash_64[2552]; out_64[3] = hash_64[2556];
	}
#endif
#if MEMORY_THREADS > 160
	if(((hash_64[2560])<=(*out_64  ))
	&& ((hash_64[2564])<=(out_64[1]))
	&& ((hash_64[2568])<=(out_64[2]))
	&& ((hash_64[2572])<=(out_64[3]))){
		*out_64   = hash_64[2560]; out_64[1] = hash_64[2564];
		out_64[2] = hash_64[2568]; out_64[3] = hash_64[2572];
	}
#endif
#if MEMORY_THREADS > 161
	if(((hash_64[2576])<=(*out_64  ))
	&& ((hash_64[2580])<=(out_64[1]))
	&& ((hash_64[2584])<=(out_64[2]))
	&& ((hash_64[2588])<=(out_64[3]))){
		*out_64   = hash_64[2576]; out_64[1] = hash_64[2580];
		out_64[2] = hash_64[2584]; out_64[3] = hash_64[2588];
	}
#endif
#if MEMORY_THREADS > 162
	if(((hash_64[2592])<=(*out_64  ))
	&& ((hash_64[2596])<=(out_64[1]))
	&& ((hash_64[2600])<=(out_64[2]))
	&& ((hash_64[2604])<=(out_64[3]))){
		*out_64   = hash_64[2592]; out_64[1] = hash_64[2596];
		out_64[2] = hash_64[2600]; out_64[3] = hash_64[2604];
	}
#endif
#if MEMORY_THREADS > 163
	if(((hash_64[2608])<=(*out_64  ))
	&& ((hash_64[2612])<=(out_64[1]))
	&& ((hash_64[2616])<=(out_64[2]))
	&& ((hash_64[2620])<=(out_64[3]))){
		*out_64   = hash_64[2608]; out_64[1] = hash_64[2612];
		out_64[2] = hash_64[2616]; out_64[3] = hash_64[2620];
	}
#endif
#if MEMORY_THREADS > 164
	if(((hash_64[2624])<=(*out_64  ))
	&& ((hash_64[2628])<=(out_64[1]))
	&& ((hash_64[2632])<=(out_64[2]))
	&& ((hash_64[2636])<=(out_64[3]))){
		*out_64   = hash_64[2624]; out_64[1] = hash_64[2628];
		out_64[2] = hash_64[2632]; out_64[3] = hash_64[2636];
	}
#endif
#if MEMORY_THREADS > 165
	if(((hash_64[2640])<=(*out_64  ))
	&& ((hash_64[2644])<=(out_64[1]))
	&& ((hash_64[2648])<=(out_64[2]))
	&& ((hash_64[2652])<=(out_64[3]))){
		*out_64   = hash_64[2640]; out_64[1] = hash_64[2644];
		out_64[2] = hash_64[2648]; out_64[3] = hash_64[2652];
	}
#endif
#if MEMORY_THREADS > 166
	if(((hash_64[2656])<=(*out_64  ))
	&& ((hash_64[2660])<=(out_64[1]))
	&& ((hash_64[2664])<=(out_64[2]))
	&& ((hash_64[2668])<=(out_64[3]))){
		*out_64   = hash_64[2656]; out_64[1] = hash_64[2660];
		out_64[2] = hash_64[2664]; out_64[3] = hash_64[2668];
	}
#endif
#if MEMORY_THREADS > 167
	if(((hash_64[2672])<=(*out_64  ))
	&& ((hash_64[2676])<=(out_64[1]))
	&& ((hash_64[2680])<=(out_64[2]))
	&& ((hash_64[2684])<=(out_64[3]))){
		*out_64   = hash_64[2672]; out_64[1] = hash_64[2676];
		out_64[2] = hash_64[2680]; out_64[3] = hash_64[2684];
	}
#endif
#if MEMORY_THREADS > 168
	if(((hash_64[2688])<=(*out_64  ))
	&& ((hash_64[2692])<=(out_64[1]))
	&& ((hash_64[2696])<=(out_64[2]))
	&& ((hash_64[2700])<=(out_64[3]))){
		*out_64   = hash_64[2688]; out_64[1] = hash_64[2692];
		out_64[2] = hash_64[2696]; out_64[3] = hash_64[2700];
	}
#endif
#if MEMORY_THREADS > 169
	if(((hash_64[2704])<=(*out_64  ))
	&& ((hash_64[2708])<=(out_64[1]))
	&& ((hash_64[2712])<=(out_64[2]))
	&& ((hash_64[2716])<=(out_64[3]))){
		*out_64   = hash_64[2704]; out_64[1] = hash_64[2708];
		out_64[2] = hash_64[2712]; out_64[3] = hash_64[2716];
	}
#endif
#if MEMORY_THREADS > 170
	if(((hash_64[2720])<=(*out_64  ))
	&& ((hash_64[2724])<=(out_64[1]))
	&& ((hash_64[2728])<=(out_64[2]))
	&& ((hash_64[2732])<=(out_64[3]))){
		*out_64   = hash_64[2720]; out_64[1] = hash_64[2724];
		out_64[2] = hash_64[2728]; out_64[3] = hash_64[2732];
	}
#endif
#if MEMORY_THREADS > 171
	if(((hash_64[2736])<=(*out_64  ))
	&& ((hash_64[2740])<=(out_64[1]))
	&& ((hash_64[2744])<=(out_64[2]))
	&& ((hash_64[2748])<=(out_64[3]))){
		*out_64   = hash_64[2736]; out_64[1] = hash_64[2740];
		out_64[2] = hash_64[2744]; out_64[3] = hash_64[2748];
	}
#endif
#if MEMORY_THREADS > 172
	if(((hash_64[2752])<=(*out_64  ))
	&& ((hash_64[2756])<=(out_64[1]))
	&& ((hash_64[2760])<=(out_64[2]))
	&& ((hash_64[2764])<=(out_64[3]))){
		*out_64   = hash_64[2752]; out_64[1] = hash_64[2756];
		out_64[2] = hash_64[2760]; out_64[3] = hash_64[2764];
	}
#endif
#if MEMORY_THREADS > 173
	if(((hash_64[2768])<=(*out_64  ))
	&& ((hash_64[2772])<=(out_64[1]))
	&& ((hash_64[2776])<=(out_64[2]))
	&& ((hash_64[2780])<=(out_64[3]))){
		*out_64   = hash_64[2768]; out_64[1] = hash_64[2772];
		out_64[2] = hash_64[2776]; out_64[3] = hash_64[2780];
	}
#endif
#if MEMORY_THREADS > 174
	if(((hash_64[2784])<=(*out_64  ))
	&& ((hash_64[2788])<=(out_64[1]))
	&& ((hash_64[2792])<=(out_64[2]))
	&& ((hash_64[2796])<=(out_64[3]))){
		*out_64   = hash_64[2784]; out_64[1] = hash_64[2788];
		out_64[2] = hash_64[2792]; out_64[3] = hash_64[2796];
	}
#endif
#if MEMORY_THREADS > 175
	if(((hash_64[2800])<=(*out_64  ))
	&& ((hash_64[2804])<=(out_64[1]))
	&& ((hash_64[2808])<=(out_64[2]))
	&& ((hash_64[2812])<=(out_64[3]))){
		*out_64   = hash_64[2800]; out_64[1] = hash_64[2804];
		out_64[2] = hash_64[2808]; out_64[3] = hash_64[2812];
	}
#endif
#if MEMORY_THREADS > 176
	if(((hash_64[2816])<=(*out_64  ))
	&& ((hash_64[2820])<=(out_64[1]))
	&& ((hash_64[2824])<=(out_64[2]))
	&& ((hash_64[2828])<=(out_64[3]))){
		*out_64   = hash_64[2816]; out_64[1] = hash_64[2820];
		out_64[2] = hash_64[2824]; out_64[3] = hash_64[2828];
	}
#endif
#if MEMORY_THREADS > 177
	if(((hash_64[2832])<=(*out_64  ))
	&& ((hash_64[2836])<=(out_64[1]))
	&& ((hash_64[2840])<=(out_64[2]))
	&& ((hash_64[2844])<=(out_64[3]))){
		*out_64   = hash_64[2832]; out_64[1] = hash_64[2836];
		out_64[2] = hash_64[2840]; out_64[3] = hash_64[2844];
	}
#endif
#if MEMORY_THREADS > 178
	if(((hash_64[2848])<=(*out_64  ))
	&& ((hash_64[2852])<=(out_64[1]))
	&& ((hash_64[2856])<=(out_64[2]))
	&& ((hash_64[2860])<=(out_64[3]))){
		*out_64   = hash_64[2848]; out_64[1] = hash_64[2852];
		out_64[2] = hash_64[2856]; out_64[3] = hash_64[2860];
	}
#endif
#if MEMORY_THREADS > 179
	if(((hash_64[2864])<=(*out_64  ))
	&& ((hash_64[2868])<=(out_64[1]))
	&& ((hash_64[2872])<=(out_64[2]))
	&& ((hash_64[2876])<=(out_64[3]))){
		*out_64   = hash_64[2864]; out_64[1] = hash_64[2868];
		out_64[2] = hash_64[2872]; out_64[3] = hash_64[2876];
	}
#endif
#if MEMORY_THREADS > 180
	if(((hash_64[2880])<=(*out_64  ))
	&& ((hash_64[2884])<=(out_64[1]))
	&& ((hash_64[2888])<=(out_64[2]))
	&& ((hash_64[2892])<=(out_64[3]))){
		*out_64   = hash_64[2880]; out_64[1] = hash_64[2884];
		out_64[2] = hash_64[2888]; out_64[3] = hash_64[2892];
	}
#endif
#if MEMORY_THREADS > 181
	if(((hash_64[2896])<=(*out_64  ))
	&& ((hash_64[2900])<=(out_64[1]))
	&& ((hash_64[2904])<=(out_64[2]))
	&& ((hash_64[2908])<=(out_64[3]))){
		*out_64   = hash_64[2896]; out_64[1] = hash_64[2900];
		out_64[2] = hash_64[2904]; out_64[3] = hash_64[2908];
	}
#endif
#if MEMORY_THREADS > 182
	if(((hash_64[2912])<=(*out_64  ))
	&& ((hash_64[2916])<=(out_64[1]))
	&& ((hash_64[2920])<=(out_64[2]))
	&& ((hash_64[2924])<=(out_64[3]))){
		*out_64   = hash_64[2912]; out_64[1] = hash_64[2916];
		out_64[2] = hash_64[2920]; out_64[3] = hash_64[2924];
	}
#endif
#if MEMORY_THREADS > 183
	if(((hash_64[2928])<=(*out_64  ))
	&& ((hash_64[2932])<=(out_64[1]))
	&& ((hash_64[2936])<=(out_64[2]))
	&& ((hash_64[2940])<=(out_64[3]))){
		*out_64   = hash_64[2928]; out_64[1] = hash_64[2932];
		out_64[2] = hash_64[2936]; out_64[3] = hash_64[2940];
	}
#endif
#if MEMORY_THREADS > 184
	if(((hash_64[2944])<=(*out_64  ))
	&& ((hash_64[2948])<=(out_64[1]))
	&& ((hash_64[2952])<=(out_64[2]))
	&& ((hash_64[2956])<=(out_64[3]))){
		*out_64   = hash_64[2944]; out_64[1] = hash_64[2948];
		out_64[2] = hash_64[2952]; out_64[3] = hash_64[2956];
	}
#endif
#if MEMORY_THREADS > 185
	if(((hash_64[2960])<=(*out_64  ))
	&& ((hash_64[2964])<=(out_64[1]))
	&& ((hash_64[2968])<=(out_64[2]))
	&& ((hash_64[2972])<=(out_64[3]))){
		*out_64   = hash_64[2960]; out_64[1] = hash_64[2964];
		out_64[2] = hash_64[2968]; out_64[3] = hash_64[2972];
	}
#endif
#if MEMORY_THREADS > 186
	if(((hash_64[2976])<=(*out_64  ))
	&& ((hash_64[2980])<=(out_64[1]))
	&& ((hash_64[2984])<=(out_64[2]))
	&& ((hash_64[2988])<=(out_64[3]))){
		*out_64   = hash_64[2976]; out_64[1] = hash_64[2980];
		out_64[2] = hash_64[2984]; out_64[3] = hash_64[2988];
	}
#endif
#if MEMORY_THREADS > 187
	if(((hash_64[2992])<=(*out_64  ))
	&& ((hash_64[2996])<=(out_64[1]))
	&& ((hash_64[3000])<=(out_64[2]))
	&& ((hash_64[3004])<=(out_64[3]))){
		*out_64   = hash_64[2992]; out_64[1] = hash_64[2996];
		out_64[2] = hash_64[3000]; out_64[3] = hash_64[3004];
	}
#endif
#if MEMORY_THREADS > 188
	if(((hash_64[3008])<=(*out_64  ))
	&& ((hash_64[3012])<=(out_64[1]))
	&& ((hash_64[3016])<=(out_64[2]))
	&& ((hash_64[3020])<=(out_64[3]))){
		*out_64   = hash_64[3008]; out_64[1] = hash_64[3012];
		out_64[2] = hash_64[3016]; out_64[3] = hash_64[3020];
	}
#endif
#if MEMORY_THREADS > 189
	if(((hash_64[3024])<=(*out_64  ))
	&& ((hash_64[3028])<=(out_64[1]))
	&& ((hash_64[3032])<=(out_64[2]))
	&& ((hash_64[3036])<=(out_64[3]))){
		*out_64   = hash_64[3024]; out_64[1] = hash_64[3028];
		out_64[2] = hash_64[3032]; out_64[3] = hash_64[3036];
	}
#endif
#if MEMORY_THREADS > 190
	if(((hash_64[3040])<=(*out_64  ))
	&& ((hash_64[3044])<=(out_64[1]))
	&& ((hash_64[3048])<=(out_64[2]))
	&& ((hash_64[3052])<=(out_64[3]))){
		*out_64   = hash_64[3040]; out_64[1] = hash_64[3044];
		out_64[2] = hash_64[3048]; out_64[3] = hash_64[3052];
	}
#endif
#if MEMORY_THREADS > 191
	if(((hash_64[3056])<=(*out_64  ))
	&& ((hash_64[3060])<=(out_64[1]))
	&& ((hash_64[3064])<=(out_64[2]))
	&& ((hash_64[3068])<=(out_64[3]))){
		*out_64   = hash_64[3056]; out_64[1] = hash_64[3060];
		out_64[2] = hash_64[3064]; out_64[3] = hash_64[3068];
	}
#endif
#if MEMORY_THREADS > 192
	if(((hash_64[3072])<=(*out_64  ))
	&& ((hash_64[3076])<=(out_64[1]))
	&& ((hash_64[3080])<=(out_64[2]))
	&& ((hash_64[3084])<=(out_64[3]))){
		*out_64   = hash_64[3072]; out_64[1] = hash_64[3076];
		out_64[2] = hash_64[3080]; out_64[3] = hash_64[3084];
	}
#endif
#if MEMORY_THREADS > 193
	if(((hash_64[3088])<=(*out_64  ))
	&& ((hash_64[3092])<=(out_64[1]))
	&& ((hash_64[3096])<=(out_64[2]))
	&& ((hash_64[3100])<=(out_64[3]))){
		*out_64   = hash_64[3088]; out_64[1] = hash_64[3092];
		out_64[2] = hash_64[3096]; out_64[3] = hash_64[3100];
	}
#endif
#if MEMORY_THREADS > 194
	if(((hash_64[3104])<=(*out_64  ))
	&& ((hash_64[3108])<=(out_64[1]))
	&& ((hash_64[3112])<=(out_64[2]))
	&& ((hash_64[3116])<=(out_64[3]))){
		*out_64   = hash_64[3104]; out_64[1] = hash_64[3108];
		out_64[2] = hash_64[3112]; out_64[3] = hash_64[3116];
	}
#endif
#if MEMORY_THREADS > 195
	if(((hash_64[3120])<=(*out_64  ))
	&& ((hash_64[3124])<=(out_64[1]))
	&& ((hash_64[3128])<=(out_64[2]))
	&& ((hash_64[3132])<=(out_64[3]))){
		*out_64   = hash_64[3120]; out_64[1] = hash_64[3124];
		out_64[2] = hash_64[3128]; out_64[3] = hash_64[3132];
	}
#endif
#if MEMORY_THREADS > 196
	if(((hash_64[3136])<=(*out_64  ))
	&& ((hash_64[3140])<=(out_64[1]))
	&& ((hash_64[3144])<=(out_64[2]))
	&& ((hash_64[3148])<=(out_64[3]))){
		*out_64   = hash_64[3136]; out_64[1] = hash_64[3140];
		out_64[2] = hash_64[3144]; out_64[3] = hash_64[3148];
	}
#endif
#if MEMORY_THREADS > 197
	if(((hash_64[3152])<=(*out_64  ))
	&& ((hash_64[3156])<=(out_64[1]))
	&& ((hash_64[3160])<=(out_64[2]))
	&& ((hash_64[3164])<=(out_64[3]))){
		*out_64   = hash_64[3152]; out_64[1] = hash_64[3156];
		out_64[2] = hash_64[3160]; out_64[3] = hash_64[3164];
	}
#endif
#if MEMORY_THREADS > 198
	if(((hash_64[3168])<=(*out_64  ))
	&& ((hash_64[3172])<=(out_64[1]))
	&& ((hash_64[3176])<=(out_64[2]))
	&& ((hash_64[3180])<=(out_64[3]))){
		*out_64   = hash_64[3168]; out_64[1] = hash_64[3172];
		out_64[2] = hash_64[3176]; out_64[3] = hash_64[3180];
	}
#endif
#if MEMORY_THREADS > 199
	if(((hash_64[3184])<=(*out_64  ))
	&& ((hash_64[3188])<=(out_64[1]))
	&& ((hash_64[3192])<=(out_64[2]))
	&& ((hash_64[3196])<=(out_64[3]))){
		*out_64   = hash_64[3184]; out_64[1] = hash_64[3188];
		out_64[2] = hash_64[3192]; out_64[3] = hash_64[3196];
	}
#endif
#if MEMORY_THREADS > 200
	if(((hash_64[3200])<=(*out_64  ))
	&& ((hash_64[3204])<=(out_64[1]))
	&& ((hash_64[3208])<=(out_64[2]))
	&& ((hash_64[3212])<=(out_64[3]))){
		*out_64   = hash_64[3200]; out_64[1] = hash_64[3204];
		out_64[2] = hash_64[3208]; out_64[3] = hash_64[3212];
	}
#endif
#if MEMORY_THREADS > 201
	if(((hash_64[3216])<=(*out_64  ))
	&& ((hash_64[3220])<=(out_64[1]))
	&& ((hash_64[3224])<=(out_64[2]))
	&& ((hash_64[3228])<=(out_64[3]))){
		*out_64   = hash_64[3216]; out_64[1] = hash_64[3220];
		out_64[2] = hash_64[3224]; out_64[3] = hash_64[3228];
	}
#endif
#if MEMORY_THREADS > 202
	if(((hash_64[3232])<=(*out_64  ))
	&& ((hash_64[3236])<=(out_64[1]))
	&& ((hash_64[3240])<=(out_64[2]))
	&& ((hash_64[3244])<=(out_64[3]))){
		*out_64   = hash_64[3232]; out_64[1] = hash_64[3236];
		out_64[2] = hash_64[3240]; out_64[3] = hash_64[3244];
	}
#endif
#if MEMORY_THREADS > 203
	if(((hash_64[3248])<=(*out_64  ))
	&& ((hash_64[3252])<=(out_64[1]))
	&& ((hash_64[3256])<=(out_64[2]))
	&& ((hash_64[3260])<=(out_64[3]))){
		*out_64   = hash_64[3248]; out_64[1] = hash_64[3252];
		out_64[2] = hash_64[3256]; out_64[3] = hash_64[3260];
	}
#endif
#if MEMORY_THREADS > 204
	if(((hash_64[3264])<=(*out_64  ))
	&& ((hash_64[3268])<=(out_64[1]))
	&& ((hash_64[3272])<=(out_64[2]))
	&& ((hash_64[3276])<=(out_64[3]))){
		*out_64   = hash_64[3264]; out_64[1] = hash_64[3268];
		out_64[2] = hash_64[3272]; out_64[3] = hash_64[3276];
	}
#endif
#if MEMORY_THREADS > 205
	if(((hash_64[3280])<=(*out_64  ))
	&& ((hash_64[3284])<=(out_64[1]))
	&& ((hash_64[3288])<=(out_64[2]))
	&& ((hash_64[3292])<=(out_64[3]))){
		*out_64   = hash_64[3280]; out_64[1] = hash_64[3284];
		out_64[2] = hash_64[3288]; out_64[3] = hash_64[3292];
	}
#endif
#if MEMORY_THREADS > 206
	if(((hash_64[3296])<=(*out_64  ))
	&& ((hash_64[3300])<=(out_64[1]))
	&& ((hash_64[3304])<=(out_64[2]))
	&& ((hash_64[3308])<=(out_64[3]))){
		*out_64   = hash_64[3296]; out_64[1] = hash_64[3300];
		out_64[2] = hash_64[3304]; out_64[3] = hash_64[3308];
	}
#endif
#if MEMORY_THREADS > 207
	if(((hash_64[3312])<=(*out_64  ))
	&& ((hash_64[3316])<=(out_64[1]))
	&& ((hash_64[3320])<=(out_64[2]))
	&& ((hash_64[3324])<=(out_64[3]))){
		*out_64   = hash_64[3312]; out_64[1] = hash_64[3316];
		out_64[2] = hash_64[3320]; out_64[3] = hash_64[3324];
	}
#endif
#if MEMORY_THREADS > 208
	if(((hash_64[3328])<=(*out_64  ))
	&& ((hash_64[3332])<=(out_64[1]))
	&& ((hash_64[3336])<=(out_64[2]))
	&& ((hash_64[3340])<=(out_64[3]))){
		*out_64   = hash_64[3328]; out_64[1] = hash_64[3332];
		out_64[2] = hash_64[3336]; out_64[3] = hash_64[3340];
	}
#endif
#if MEMORY_THREADS > 209
	if(((hash_64[3344])<=(*out_64  ))
	&& ((hash_64[3348])<=(out_64[1]))
	&& ((hash_64[3352])<=(out_64[2]))
	&& ((hash_64[3356])<=(out_64[3]))){
		*out_64   = hash_64[3344]; out_64[1] = hash_64[3348];
		out_64[2] = hash_64[3352]; out_64[3] = hash_64[3356];
	}
#endif
#if MEMORY_THREADS > 210
	if(((hash_64[3360])<=(*out_64  ))
	&& ((hash_64[3364])<=(out_64[1]))
	&& ((hash_64[3368])<=(out_64[2]))
	&& ((hash_64[3372])<=(out_64[3]))){
		*out_64   = hash_64[3360]; out_64[1] = hash_64[3364];
		out_64[2] = hash_64[3368]; out_64[3] = hash_64[3372];
	}
#endif
#if MEMORY_THREADS > 211
	if(((hash_64[3376])<=(*out_64  ))
	&& ((hash_64[3380])<=(out_64[1]))
	&& ((hash_64[3384])<=(out_64[2]))
	&& ((hash_64[3388])<=(out_64[3]))){
		*out_64   = hash_64[3376]; out_64[1] = hash_64[3380];
		out_64[2] = hash_64[3384]; out_64[3] = hash_64[3388];
	}
#endif
#if MEMORY_THREADS > 212
	if(((hash_64[3392])<=(*out_64  ))
	&& ((hash_64[3396])<=(out_64[1]))
	&& ((hash_64[3400])<=(out_64[2]))
	&& ((hash_64[3404])<=(out_64[3]))){
		*out_64   = hash_64[3392]; out_64[1] = hash_64[3396];
		out_64[2] = hash_64[3400]; out_64[3] = hash_64[3404];
	}
#endif
#if MEMORY_THREADS > 213
	if(((hash_64[3408])<=(*out_64  ))
	&& ((hash_64[3412])<=(out_64[1]))
	&& ((hash_64[3416])<=(out_64[2]))
	&& ((hash_64[3420])<=(out_64[3]))){
		*out_64   = hash_64[3408]; out_64[1] = hash_64[3412];
		out_64[2] = hash_64[3416]; out_64[3] = hash_64[3420];
	}
#endif
#if MEMORY_THREADS > 214
	if(((hash_64[3424])<=(*out_64  ))
	&& ((hash_64[3428])<=(out_64[1]))
	&& ((hash_64[3432])<=(out_64[2]))
	&& ((hash_64[3436])<=(out_64[3]))){
		*out_64   = hash_64[3424]; out_64[1] = hash_64[3428];
		out_64[2] = hash_64[3432]; out_64[3] = hash_64[3436];
	}
#endif
#if MEMORY_THREADS > 215
	if(((hash_64[3440])<=(*out_64  ))
	&& ((hash_64[3444])<=(out_64[1]))
	&& ((hash_64[3448])<=(out_64[2]))
	&& ((hash_64[3452])<=(out_64[3]))){
		*out_64   = hash_64[3440]; out_64[1] = hash_64[3444];
		out_64[2] = hash_64[3448]; out_64[3] = hash_64[3452];
	}
#endif
#if MEMORY_THREADS > 216
	if(((hash_64[3456])<=(*out_64  ))
	&& ((hash_64[3460])<=(out_64[1]))
	&& ((hash_64[3464])<=(out_64[2]))
	&& ((hash_64[3468])<=(out_64[3]))){
		*out_64   = hash_64[3456]; out_64[1] = hash_64[3460];
		out_64[2] = hash_64[3464]; out_64[3] = hash_64[3468];
	}
#endif
#if MEMORY_THREADS > 217
	if(((hash_64[3472])<=(*out_64  ))
	&& ((hash_64[3476])<=(out_64[1]))
	&& ((hash_64[3480])<=(out_64[2]))
	&& ((hash_64[3484])<=(out_64[3]))){
		*out_64   = hash_64[3472]; out_64[1] = hash_64[3476];
		out_64[2] = hash_64[3480]; out_64[3] = hash_64[3484];
	}
#endif
#if MEMORY_THREADS > 218
	if(((hash_64[3488])<=(*out_64  ))
	&& ((hash_64[3492])<=(out_64[1]))
	&& ((hash_64[3496])<=(out_64[2]))
	&& ((hash_64[3500])<=(out_64[3]))){
		*out_64   = hash_64[3488]; out_64[1] = hash_64[3492];
		out_64[2] = hash_64[3496]; out_64[3] = hash_64[3500];
	}
#endif
#if MEMORY_THREADS > 219
	if(((hash_64[3504])<=(*out_64  ))
	&& ((hash_64[3508])<=(out_64[1]))
	&& ((hash_64[3512])<=(out_64[2]))
	&& ((hash_64[3516])<=(out_64[3]))){
		*out_64   = hash_64[3504]; out_64[1] = hash_64[3508];
		out_64[2] = hash_64[3512]; out_64[3] = hash_64[3516];
	}
#endif
#if MEMORY_THREADS > 220
	if(((hash_64[3520])<=(*out_64  ))
	&& ((hash_64[3524])<=(out_64[1]))
	&& ((hash_64[3528])<=(out_64[2]))
	&& ((hash_64[3532])<=(out_64[3]))){
		*out_64   = hash_64[3520]; out_64[1] = hash_64[3524];
		out_64[2] = hash_64[3528]; out_64[3] = hash_64[3532];
	}
#endif
#if MEMORY_THREADS > 221
	if(((hash_64[3536])<=(*out_64  ))
	&& ((hash_64[3540])<=(out_64[1]))
	&& ((hash_64[3544])<=(out_64[2]))
	&& ((hash_64[3548])<=(out_64[3]))){
		*out_64   = hash_64[3536]; out_64[1] = hash_64[3540];
		out_64[2] = hash_64[3544]; out_64[3] = hash_64[3548];
	}
#endif
#if MEMORY_THREADS > 222
	if(((hash_64[3552])<=(*out_64  ))
	&& ((hash_64[3556])<=(out_64[1]))
	&& ((hash_64[3560])<=(out_64[2]))
	&& ((hash_64[3564])<=(out_64[3]))){
		*out_64   = hash_64[3552]; out_64[1] = hash_64[3556];
		out_64[2] = hash_64[3560]; out_64[3] = hash_64[3564];
	}
#endif
#if MEMORY_THREADS > 223
	if(((hash_64[3568])<=(*out_64  ))
	&& ((hash_64[3572])<=(out_64[1]))
	&& ((hash_64[3576])<=(out_64[2]))
	&& ((hash_64[3580])<=(out_64[3]))){
		*out_64   = hash_64[3568]; out_64[1] = hash_64[3572];
		out_64[2] = hash_64[3576]; out_64[3] = hash_64[3580];
	}
#endif
#if MEMORY_THREADS > 224
	if(((hash_64[3584])<=(*out_64  ))
	&& ((hash_64[3588])<=(out_64[1]))
	&& ((hash_64[3592])<=(out_64[2]))
	&& ((hash_64[3596])<=(out_64[3]))){
		*out_64   = hash_64[3584]; out_64[1] = hash_64[3588];
		out_64[2] = hash_64[3592]; out_64[3] = hash_64[3596];
	}
#endif
#if MEMORY_THREADS > 225
	if(((hash_64[3600])<=(*out_64  ))
	&& ((hash_64[3604])<=(out_64[1]))
	&& ((hash_64[3608])<=(out_64[2]))
	&& ((hash_64[3612])<=(out_64[3]))){
		*out_64   = hash_64[3600]; out_64[1] = hash_64[3604];
		out_64[2] = hash_64[3608]; out_64[3] = hash_64[3612];
	}
#endif
#if MEMORY_THREADS > 226
	if(((hash_64[3616])<=(*out_64  ))
	&& ((hash_64[3620])<=(out_64[1]))
	&& ((hash_64[3624])<=(out_64[2]))
	&& ((hash_64[3628])<=(out_64[3]))){
		*out_64   = hash_64[3616]; out_64[1] = hash_64[3620];
		out_64[2] = hash_64[3624]; out_64[3] = hash_64[3628];
	}
#endif
#if MEMORY_THREADS > 227
	if(((hash_64[3632])<=(*out_64  ))
	&& ((hash_64[3636])<=(out_64[1]))
	&& ((hash_64[3640])<=(out_64[2]))
	&& ((hash_64[3644])<=(out_64[3]))){
		*out_64   = hash_64[3632]; out_64[1] = hash_64[3636];
		out_64[2] = hash_64[3640]; out_64[3] = hash_64[3644];
	}
#endif
#if MEMORY_THREADS > 228
	if(((hash_64[3648])<=(*out_64  ))
	&& ((hash_64[3652])<=(out_64[1]))
	&& ((hash_64[3656])<=(out_64[2]))
	&& ((hash_64[3660])<=(out_64[3]))){
		*out_64   = hash_64[3648]; out_64[1] = hash_64[3652];
		out_64[2] = hash_64[3656]; out_64[3] = hash_64[3660];
	}
#endif
#if MEMORY_THREADS > 229
	if(((hash_64[3664])<=(*out_64  ))
	&& ((hash_64[3668])<=(out_64[1]))
	&& ((hash_64[3672])<=(out_64[2]))
	&& ((hash_64[3676])<=(out_64[3]))){
		*out_64   = hash_64[3664]; out_64[1] = hash_64[3668];
		out_64[2] = hash_64[3672]; out_64[3] = hash_64[3676];
	}
#endif
#if MEMORY_THREADS > 230
	if(((hash_64[3680])<=(*out_64  ))
	&& ((hash_64[3684])<=(out_64[1]))
	&& ((hash_64[3688])<=(out_64[2]))
	&& ((hash_64[3692])<=(out_64[3]))){
		*out_64   = hash_64[3680]; out_64[1] = hash_64[3684];
		out_64[2] = hash_64[3688]; out_64[3] = hash_64[3692];
	}
#endif
#if MEMORY_THREADS > 231
	if(((hash_64[3696])<=(*out_64  ))
	&& ((hash_64[3700])<=(out_64[1]))
	&& ((hash_64[3704])<=(out_64[2]))
	&& ((hash_64[3708])<=(out_64[3]))){
		*out_64   = hash_64[3696]; out_64[1] = hash_64[3700];
		out_64[2] = hash_64[3704]; out_64[3] = hash_64[3708];
	}
#endif
#if MEMORY_THREADS > 232
	if(((hash_64[3712])<=(*out_64  ))
	&& ((hash_64[3716])<=(out_64[1]))
	&& ((hash_64[3720])<=(out_64[2]))
	&& ((hash_64[3724])<=(out_64[3]))){
		*out_64   = hash_64[3712]; out_64[1] = hash_64[3716];
		out_64[2] = hash_64[3720]; out_64[3] = hash_64[3724];
	}
#endif
#if MEMORY_THREADS > 233
	if(((hash_64[3728])<=(*out_64  ))
	&& ((hash_64[3732])<=(out_64[1]))
	&& ((hash_64[3736])<=(out_64[2]))
	&& ((hash_64[3740])<=(out_64[3]))){
		*out_64   = hash_64[3728]; out_64[1] = hash_64[3732];
		out_64[2] = hash_64[3736]; out_64[3] = hash_64[3740];
	}
#endif
#if MEMORY_THREADS > 234
	if(((hash_64[3744])<=(*out_64  ))
	&& ((hash_64[3748])<=(out_64[1]))
	&& ((hash_64[3752])<=(out_64[2]))
	&& ((hash_64[3756])<=(out_64[3]))){
		*out_64   = hash_64[3744]; out_64[1] = hash_64[3748];
		out_64[2] = hash_64[3752]; out_64[3] = hash_64[3756];
	}
#endif
#if MEMORY_THREADS > 235
	if(((hash_64[3760])<=(*out_64  ))
	&& ((hash_64[3764])<=(out_64[1]))
	&& ((hash_64[3768])<=(out_64[2]))
	&& ((hash_64[3772])<=(out_64[3]))){
		*out_64   = hash_64[3760]; out_64[1] = hash_64[3764];
		out_64[2] = hash_64[3768]; out_64[3] = hash_64[3772];
	}
#endif
#if MEMORY_THREADS > 236
	if(((hash_64[3776])<=(*out_64  ))
	&& ((hash_64[3780])<=(out_64[1]))
	&& ((hash_64[3784])<=(out_64[2]))
	&& ((hash_64[3788])<=(out_64[3]))){
		*out_64   = hash_64[3776]; out_64[1] = hash_64[3780];
		out_64[2] = hash_64[3784]; out_64[3] = hash_64[3788];
	}
#endif
#if MEMORY_THREADS > 237
	if(((hash_64[3792])<=(*out_64  ))
	&& ((hash_64[3796])<=(out_64[1]))
	&& ((hash_64[3800])<=(out_64[2]))
	&& ((hash_64[3804])<=(out_64[3]))){
		*out_64   = hash_64[3792]; out_64[1] = hash_64[3796];
		out_64[2] = hash_64[3800]; out_64[3] = hash_64[3804];
	}
#endif
#if MEMORY_THREADS > 238
	if(((hash_64[3808])<=(*out_64  ))
	&& ((hash_64[3812])<=(out_64[1]))
	&& ((hash_64[3816])<=(out_64[2]))
	&& ((hash_64[3820])<=(out_64[3]))){
		*out_64   = hash_64[3808]; out_64[1] = hash_64[3812];
		out_64[2] = hash_64[3816]; out_64[3] = hash_64[3820];
	}
#endif
#if MEMORY_THREADS > 239
	if(((hash_64[3824])<=(*out_64  ))
	&& ((hash_64[3828])<=(out_64[1]))
	&& ((hash_64[3832])<=(out_64[2]))
	&& ((hash_64[3836])<=(out_64[3]))){
		*out_64   = hash_64[3824]; out_64[1] = hash_64[3828];
		out_64[2] = hash_64[3832]; out_64[3] = hash_64[3836];
	}
#endif
#if MEMORY_THREADS > 240
	if(((hash_64[3840])<=(*out_64  ))
	&& ((hash_64[3844])<=(out_64[1]))
	&& ((hash_64[3848])<=(out_64[2]))
	&& ((hash_64[3852])<=(out_64[3]))){
		*out_64   = hash_64[3840]; out_64[1] = hash_64[3844];
		out_64[2] = hash_64[3848]; out_64[3] = hash_64[3852];
	}
#endif
#if MEMORY_THREADS > 241
	if(((hash_64[3856])<=(*out_64  ))
	&& ((hash_64[3860])<=(out_64[1]))
	&& ((hash_64[3864])<=(out_64[2]))
	&& ((hash_64[3868])<=(out_64[3]))){
		*out_64   = hash_64[3856]; out_64[1] = hash_64[3860];
		out_64[2] = hash_64[3864]; out_64[3] = hash_64[3868];
	}
#endif
#if MEMORY_THREADS > 242
	if(((hash_64[3872])<=(*out_64  ))
	&& ((hash_64[3876])<=(out_64[1]))
	&& ((hash_64[3880])<=(out_64[2]))
	&& ((hash_64[3884])<=(out_64[3]))){
		*out_64   = hash_64[3872]; out_64[1] = hash_64[3876];
		out_64[2] = hash_64[3880]; out_64[3] = hash_64[3884];
	}
#endif
#if MEMORY_THREADS > 243
	if(((hash_64[3888])<=(*out_64  ))
	&& ((hash_64[3892])<=(out_64[1]))
	&& ((hash_64[3896])<=(out_64[2]))
	&& ((hash_64[3900])<=(out_64[3]))){
		*out_64   = hash_64[3888]; out_64[1] = hash_64[3892];
		out_64[2] = hash_64[3896]; out_64[3] = hash_64[3900];
	}
#endif
#if MEMORY_THREADS > 244
	if(((hash_64[3904])<=(*out_64  ))
	&& ((hash_64[3908])<=(out_64[1]))
	&& ((hash_64[3912])<=(out_64[2]))
	&& ((hash_64[3916])<=(out_64[3]))){
		*out_64   = hash_64[3904]; out_64[1] = hash_64[3908];
		out_64[2] = hash_64[3912]; out_64[3] = hash_64[3916];
	}
#endif
#if MEMORY_THREADS > 245
	if(((hash_64[3920])<=(*out_64  ))
	&& ((hash_64[3924])<=(out_64[1]))
	&& ((hash_64[3928])<=(out_64[2]))
	&& ((hash_64[3932])<=(out_64[3]))){
		*out_64   = hash_64[3920]; out_64[1] = hash_64[3924];
		out_64[2] = hash_64[3928]; out_64[3] = hash_64[3932];
	}
#endif
#if MEMORY_THREADS > 246
	if(((hash_64[3936])<=(*out_64  ))
	&& ((hash_64[3940])<=(out_64[1]))
	&& ((hash_64[3944])<=(out_64[2]))
	&& ((hash_64[3948])<=(out_64[3]))){
		*out_64   = hash_64[3936]; out_64[1] = hash_64[3940];
		out_64[2] = hash_64[3944]; out_64[3] = hash_64[3948];
	}
#endif
#if MEMORY_THREADS > 247
	if(((hash_64[3952])<=(*out_64  ))
	&& ((hash_64[3956])<=(out_64[1]))
	&& ((hash_64[3960])<=(out_64[2]))
	&& ((hash_64[3964])<=(out_64[3]))){
		*out_64   = hash_64[3952]; out_64[1] = hash_64[3956];
		out_64[2] = hash_64[3960]; out_64[3] = hash_64[3964];
	}
#endif
#if MEMORY_THREADS > 248
	if(((hash_64[3968])<=(*out_64  ))
	&& ((hash_64[3972])<=(out_64[1]))
	&& ((hash_64[3976])<=(out_64[2]))
	&& ((hash_64[3980])<=(out_64[3]))){
		*out_64   = hash_64[3968]; out_64[1] = hash_64[3972];
		out_64[2] = hash_64[3976]; out_64[3] = hash_64[3980];
	}
#endif
#if MEMORY_THREADS > 249
	if(((hash_64[3984])<=(*out_64  ))
	&& ((hash_64[3988])<=(out_64[1]))
	&& ((hash_64[3992])<=(out_64[2]))
	&& ((hash_64[3996])<=(out_64[3]))){
		*out_64   = hash_64[3984]; out_64[1] = hash_64[3988];
		out_64[2] = hash_64[3992]; out_64[3] = hash_64[3996];
	}
#endif
#if MEMORY_THREADS > 250
	if(((hash_64[4000])<=(*out_64  ))
	&& ((hash_64[4004])<=(out_64[1]))
	&& ((hash_64[4008])<=(out_64[2]))
	&& ((hash_64[4012])<=(out_64[3]))){
		*out_64   = hash_64[4000]; out_64[1] = hash_64[4004];
		out_64[2] = hash_64[4008]; out_64[3] = hash_64[4012];
	}
#endif
#if MEMORY_THREADS > 251
	if(((hash_64[4016])<=(*out_64  ))
	&& ((hash_64[4020])<=(out_64[1]))
	&& ((hash_64[4024])<=(out_64[2]))
	&& ((hash_64[4028])<=(out_64[3]))){
		*out_64   = hash_64[4016]; out_64[1] = hash_64[4020];
		out_64[2] = hash_64[4024]; out_64[3] = hash_64[4028];
	}
#endif
#if MEMORY_THREADS > 252
	if(((hash_64[4032])<=(*out_64  ))
	&& ((hash_64[4036])<=(out_64[1]))
	&& ((hash_64[4040])<=(out_64[2]))
	&& ((hash_64[4044])<=(out_64[3]))){
		*out_64   = hash_64[4032]; out_64[1] = hash_64[4036];
		out_64[2] = hash_64[4040]; out_64[3] = hash_64[4044];
	}
#endif
#if MEMORY_THREADS > 253
	if(((hash_64[4048])<=(*out_64  ))
	&& ((hash_64[4052])<=(out_64[1]))
	&& ((hash_64[4056])<=(out_64[2]))
	&& ((hash_64[4060])<=(out_64[3]))){
		*out_64   = hash_64[4048]; out_64[1] = hash_64[4052];
		out_64[2] = hash_64[4056]; out_64[3] = hash_64[4060];
	}
#endif
#if MEMORY_THREADS > 254
	if(((hash_64[4064])<=(*out_64  ))
	&& ((hash_64[4068])<=(out_64[1]))
	&& ((hash_64[4072])<=(out_64[2]))
	&& ((hash_64[4076])<=(out_64[3]))){
		*out_64   = hash_64[4064]; out_64[1] = hash_64[4068];
		out_64[2] = hash_64[4072]; out_64[3] = hash_64[4076];
	}
#endif
#if MEMORY_THREADS > 255
	if(((hash_64[4080])<=(*out_64  ))
	&& ((hash_64[4084])<=(out_64[1]))
	&& ((hash_64[4088])<=(out_64[2]))
	&& ((hash_64[4092])<=(out_64[3]))){
		*out_64   = hash_64[4080]; out_64[1] = hash_64[4084];
		out_64[2] = hash_64[4088]; out_64[3] = hash_64[4092];
	}
#endif
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


