

To compile the miner, you will have to run `gcc -O3 -march=native squash.c blockchain.c aes.c mine.c blake2/sse/blake2b.c xxHash/xxhash.c pow.c -o mine.o`. </br>
To compile the validator (used for synchronising nodes), you will have to run `gcc -O3 -march=native squash.c blockchain.c aes.c validate.c blake2/sse/blake2b.c xxHash/xxhash.c pow.c -o validate.o`. </br>
`squash.c` contains all squash functions, which can be adapted for other algorithms or simply picked as a hash algorithm. </br>

Benchmarking results:

```
Mining
	Seed calculation took: 0s
	Dataset generation took: 10s
	Calculation of 268435456 hashes took: 1828s
	Hashrate is about: 146846H/s
	Result: f27ddd9627fcf5b9

Validation
	Seed calculation took: 0s
	Cache generation took: 1s
	Calculation of 2097152 hashes took: 2087s
	Hashrate is about: 1004H/s
	Result: a9caeb21899ee322
```
