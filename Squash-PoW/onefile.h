// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include <stdint.h>

void error_exit(uint8_t code);
static void add_round_key(uint8_t * state, uint8_t * rkey);
static void sub_bytes(uint8_t * state);
static void shift_rows(uint8_t * state);
static void mix_columns(uint8_t * state);
void aesSingleRound(uint8_t* state, uint8_t* key);
uint32_t crc32(uint32_t msg);
uint32_t reverse(uint32_t x);
uint64_t swap(uint64_t v);
void calc_dataset_item(uint8_t* cache, uint32_t item_number, uint64_t* out);
void squash_0(uint8_t* data, uint8_t* out);
void squash_1(uint8_t* data, uint8_t* scratchpad, uint8_t* out);
void squash_2(uint8_t* data, uint8_t* scratchpad, uint8_t* out);
void squash_3_full(uint8_t* data, uint64_t* dataset, uint8_t* out);
void squash_3_light(uint8_t* data, uint8_t* cache, uint8_t* out);
void make_scratchpad(uint8_t* seed, uint8_t* scratchpad);
void make_cache(uint8_t* scratchpad, uint8_t* cache);
void calc_dataset(uint8_t* cache, uint64_t* out);
void squash_pow_full(uint8_t* data, uint32_t lenght, uint64_t* dataset, uint8_t* result);
void squash_pow_light(uint8_t* data, uint32_t lenght, uint8_t* cache, uint8_t* result);
void get_seedhash(uint32_t block_number, uint8_t* seed);
void cache_from_height(uint32_t height, uint8_t* cache);
void dataset_from_height(uint32_t height, uint64_t* dataset);
