// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef CONFIG_H
#define CONFIG_H


#define SIZE (1<<21)  // Bytes, stored in cache
#define ITER (1<<16)  // Iterations to move over the cache
#define INPUT_SIZE  8 // In  8-byte blocks, maximum is 16
#define OUTPUT_SIZE 2 // In 16-byte blocks, maximum is  4
#define USE_CRC       // Comment to disable the usage of CRC32C
		      // in cache generation

#endif
