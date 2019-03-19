To compile squashimoto (hashimoto-squash variant), you will have to run the following command `gcc -O3 -march=native squash.c aes.c squashimoto.c prime_test.c blake2/blake2b.c -o cache.o`. </br>
`squash.c` contains all squash functions, which can be adapted for other algorithms or simply picked as a hash algorithm. </br>
**Coming soon:** SquashPoW. Squash-Optimised memory-intense assymetric proof of work hash. Inspired by hashimoto.
