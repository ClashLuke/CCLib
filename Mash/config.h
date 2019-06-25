//#define ACCESS_ROUNDS 256 // Access rounds make hashing slower for everyone by a defined factor, comment it to have the greatest speed. 
#define MEMORY_THREADS 1    // 256 is the absolute maximum
			    // with 256 memory threads, 32kb of L1 cache are used for storage
#define DATASET_PARENTS 16  // Determines dataset creation time and validation speed. The higher the slower.
//#define BENCHMARK           // XORing outputs of hash instead of checking for the best. Comment to check for best
