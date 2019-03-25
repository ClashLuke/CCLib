**Contents**
- [Compiling](#Compiling)
- [Benchmarking Results](#Results)

### Compiling
Before compiling the source code, make sure you run the latest GCC build, since those can give high performance boosts. Please note that on some devices, clang is rebranded to GCC by default. Clang is about 25% slower than GCC, both during compilation but more importantly during execution. </br>
There are three programs one can compile. 
* The **miner**, which generates the full 4GiB dataset and "mines" with its support.
* The **validator**, which generates the cache and, when needed, the items of the 4GiB dataset.
* The **benchmark**, which runs both miner and validator for a given number of iterations, shows the resulting hashrate and the time it needed to do either of these things.
The compilation of those programs is OS specific. Click here to skip forward.
- [Windows, x86](#Windows, x86)
- [Windows, ARM](#Unix, ARM)
- [Unix, x86](#Unix, x86)
- [Unix, ARM](#Unix, ARM)

#### Windows, x86
* Miner: `gcc -O3 -march=native squash.c blockchain.c aes.c pow.c mine.c blake2/sse/blake2b.c -maes -msse2 -msse4.2 -mavx -o miner.exe`
* Validator: `gcc -O3 -march=native squash.c blockchain.c aes.c pow.c validate.c blake2/sse/blake2b.c -maes -msse2 -msse4.2 -mavx -o validator.exe`
* Benchmark: `gcc -O3 -march=native squash.c blockchain.c aes.c pow.c benchmark.c blake2/sse/blake2b.c -maes -msse2 -msse4.2 -mavx -o benchmark.exe`
The executables can then be double-clicked or run via `miner.exe`, `validator.exe` or `benchmark.exe` respectively.

#### Windows, ARM
* Miner: `gcc -O3 -march=native squash.c blockchain.c aes.c mine.c blake2/neon/blake2b.c pow.c -marm -mfpu=neon -o miner.exe`
* Validator: `gcc -O3 -march=native squash.c blockchain.c aes.c validate.c blake2/neon/blake2b.c pow.c -marm -mfpu=neon -o validator.exe`
* Benchmark: `gcc -O3 -march=native squash.c blockchain.c aes.c benchmark.c blake2/neon/blake2b.c pow.c -marm -mfpu=neon -o benchmark.exe`
The executables can then be double-clicked or run via `miner.exe`, `validator.exe` or `benchmark.exe` respectively.

#### Windows, x86
* Miner: `gcc -O3 -march=native squash.c blockchain.c aes.c pow.c mine.c blake2/sse/blake2b.c -maes -msse2 -msse4.2 -mavx -o miner.exe`
* Validator: `gcc -O3 -march=native squash.c blockchain.c aes.c pow.c validate.c blake2/sse/blake2b.c -maes -msse2 -msse4.2 -mavx -o validator.exe`
* Benchmark: `gcc -O3 -march=native squash.c blockchain.c aes.c pow.c benchmark.c blake2/sse/blake2b.c -maes -msse2 -msse4.2 -mavx -o benchmark.exe`
The executables can then be run via `./miner`, `./validator` or `./benchmark` respectively.

#### Unix, ARM
* Miner: `gcc -O3 -march=native squash.c blockchain.c aes.c mine.c blake2/neon/blake2b.c pow.c -marm -mfpu=neon -o miner`
* Validator: `gcc -O3 -march=native squash.c blockchain.c aes.c validate.c blake2/neon/blake2b.c pow.c -marm -mfpu=neon -o validator`
* Benchmark: `gcc -O3 -march=native squash.c blockchain.c aes.c benchmark.c blake2/neon/blake2b.c pow.c -marm -mfpu=neon -o benchmark`
The executables can then be run via `./miner`, `./validator` or `./benchmark` respectively.

### Results
The following results were achieved on an [Xeon E3-1225v2](https://ark.intel.com/content/www/us/en/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html) with DDR3-1333 memory on one thread.

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
