// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef MASH_H
#define MASH_H


void mash_full(uint8_t* data, uint8_t* dataset, uint64_t item, uint64_t difficulty, uint32_t* out);
uint8_t mash_light(uint8_t* data, uint64_t difficulty);

#endif
