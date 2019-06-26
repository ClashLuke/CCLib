#ifndef MASH_H
#define MASH_H

void cache_from_seed(uint8_t* seed, uint8_t* cache);
void dataset_from_seed(uint8_t* seed, uint64_t* dataset);
void mash_full(uint8_t* data, uint8_t* dataset, uint8_t* out);
void mash_light(uint8_t* data, uint8_t* cache, uint8_t* out);

#endif
