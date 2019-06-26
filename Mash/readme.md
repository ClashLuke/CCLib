A quick-to-verify hash entirely dependent on the memory bandwidth.

Recommended way of compiling: `gcc -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall *.c -funroll-loops`
SSE2 and SSE4.2 are not used in the code, but allow the compiler to use these extensions. It may increase the performance.
`-Ofast` and `-march=native` are standard optimisations, `-flto`, `-fwhole-program` and `-funroll-loops` are optimisations which can create minor improvements in this particular case.
`-Wall` is used to ensure there are no major issues, a compiler can detect.

Memory threads are only recommended if you validate hashes and check whether or not they are "better" than another hash, instead of benchmarking the hash. An improvement of 5% can be achieved by using 256 memory-threads in favour of using one thread.
Calculating everything in batches of 256 nonces and finding a nonce that solves the block in the first try but continueing to calculate all other nonces instead of pushing the nonce out right after it was found is no issue. It will have a maximum slowdown of 0.02% (compared to checking and broadcasting it instantly) but adds a 5% speedup on top of that.

Those are the benchmarking results, when using the code as-is on a Xeon E3-1225v2.
```
Parameters
	Progressbar: yes
	Iterations
		Full:  67108864
		Light: 1048576
	Seed: 89abcdef
Config
	Memory-Threads: 1
	Access Rounds: 128
	Dataset Parents: 1
	Benchmark: no
Mining
        Dataset generation took: 13s                                            
        Calculation of 67108864 hashes took: 99s                                
	Hashrate is approximately: 677867H/s
	Result: 08478f1a3a6ebde6,b06ea9923f42490f,8f711f81e9350220,79936f3969b8f716
Validation
	Cache generation took: 0s
        Calculation of 1048576 hashes took: 1577s                               
	Hashrate is approximately: 664H/s
	Result: 031a9f57fc194560,da16e57a8a19faea,2b023914b752f4b6,dbe87d9d0ac012c5

```
