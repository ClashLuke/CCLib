// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef POW_H
#define POW_H

uint32_t calcItem32(uint8_t* seed, uint32_t itemNumber);
uint64_t calcItem64(uint8_t* seed, uint32_t i);
void calcDataset(uint8_t* seed, uint8_t* out);
void get_seedhash(uint64_t block_number, uint8_t* seed);
inline uint8_t bidash_light(uint32_t* data, uint64_t difficulty){
	uint8_t* data8 = (uint8_t*)data;
	uint64_t item2 = calcItem64(data8, data[17]);
	uint64_t item  = *(uint64_t*)&data[18];
	uint64_t diff  = *(uint64_t*)&data[20];
	if((calcItem64(data8, data[16]) ^ item) < diff){
		item ^= calcItem64(data8, data[16]+8);
		if((calcItem64(data8, data[17]) ^ item) < diff){
			return 1;
		}
	}
	return 0;
}


#endif
