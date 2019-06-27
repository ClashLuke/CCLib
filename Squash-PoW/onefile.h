// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef SQUASHPOW_H
#define SQUASHPOW_H


void squash_pow_full(uint8_t* data, uint32_t lenght, uint64_t* dataset, uint8_t* result);
void squash_pow_light(uint8_t* data, uint32_t lenght, uint8_t* cache, uint8_t* result);
void cache_from_seed(uint8_t* seed, uint8_t* cache);
void dataset_from_seed(uint8_t* seed, uint64_t* dataset);

#endif
