// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

void make_scratchpad(uint8_t* seed, uint8_t* scratchpad);
void make_cache(uint8_t* scratchpad, uint8_t* cache);
void calc_dataset_item(uint8_t* cache, uint32_t item_number, uint64_t* out);
void calc_dataset(uint8_t* cache, uint64_t* out);
void cache_from_seed(uint8_t* seed, uint8_t* dataset);
void dataset_from_seed(uint8_t* seed, uint64_t* dataset);
