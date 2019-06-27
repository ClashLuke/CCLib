#define ACCESS_ROUNDS 10
#define MEMORY_THREADS 1    // 256 is the absolute maximum
			    // with 256 memory threads, 32kb of L1 cache are used for storage
#define DATASET_PARENTS 1  // Determines dataset creation time and validation speed. The higher the slower.
//#define BENCHMARK           // XORing outputs of hash instead of checking for the best. Comment to check for best
