uint64_t equihashimoto_full(uint8_t* hash, uint8_t* dataset, uint64_t difficulty);
uint64_t equihashimoto_light(uint8_t* hash, uint8_t* dataset, uint64_t difficulty);
uint8_t equihashimoto_verify(uint8_t* hash, uint64_t nonce, uint8_t* cache);
