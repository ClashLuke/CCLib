// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

uint32_t crc32(uint32_t msg);
void squash_0(uint8_t* data, uint8_t* out);
void squash_1(uint8_t* data, uint8_t* scratchpad, uint8_t* out);
void squash_2(uint8_t* data, uint8_t* scratchpad, uint8_t* out);
void squash_3_full(uint8_t* data, uint64_t* dataset, uint8_t* out);
void squash_3_light(uint8_t* data, uint8_t* cache, uint8_t* out);
