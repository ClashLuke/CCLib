void make_scratchpad(uint8_t* seed, uint8_t* scratchpad);
void make_cache(uint8_t* scratchpad, uint8_t* cache);
void calc_dataset_item(uint8_t* cache, uint32_t item_number, uint8_t* out);
void calc_dataset(uint8_t* cache, uint8_t* out);
void squash_pow_full(uint8_t* header, uint64_t nonce, uint8_t* dataset, uint8_t* result);
void squash_pow_light(uint8_t* header, uint64_t nonce, uint8_t* cache, uint8_t* result);
void get_seedhash(uint64_t block_number, uint8_t* seed);
void cache_from_seed(uint8_t* seed, uint8_t* dataset);
void dataset_from_seed(uint8_t* seed, uint8_t* dataset);
