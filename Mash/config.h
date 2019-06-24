//#define ACCESS_ROUNDS 256
#define MEMORY_THREADS 16 // 256 is the absolute maximum
			   // with 256 memory threads, 32kb of L1 cache are used for storage
#define BENCHMARK
#define DATASET_PARENTS 1                 // Determines dataset creation time and validation speed. The higher the slower.
