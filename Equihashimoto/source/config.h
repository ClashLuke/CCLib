// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef CONFIG_H
#define CONFIG_H

#define ACCESS_ROUNDS 64  // Determines speed of both full and light client. Linear slowdown for both (10 accessrounds -> 10x slower than 1 access round).
#define DATASET_PARENTS 4   // Determines dataset creation time and validation speed. The higher the slower.
//#define BENCHMARK           // XORing outputs of hash instead of checking for the best. Comment to check for best

#endif
