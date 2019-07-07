// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef POW_H
#define POW_H

uint32_t calcItem32(uint32_t* seed, uint32_t itemNumber);
void calcDataset(const uint8_t* seed, uint8_t* out);
void get_seedhash(uint64_t block_number, uint8_t* seed);
inline uint8_t mash_light(uint32_t* data, uint64_t difficulty){
	return (calcItem32(data, data[8]) ^ calcItem32(data, data[9])) < difficulty;
}


#endif
