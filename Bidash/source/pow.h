// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef POW_H
#define POW_H

uint32_t calcItem32(uint8_t* seed, uint32_t itemNumber);
uint64_t calcItem64(uint8_t* seed, uint32_t i);
void calcDataset(uint8_t* seed, uint8_t* out);
void get_seedhash(uint64_t block_number, uint8_t* seed);
uint8_t bidash_verify(uint32_t* data);
void bidash_light(uint8_t* seed);

#endif
