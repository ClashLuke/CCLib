A quick-to-verify hash entirely dependent on the memory.

Recommended way of compiling: `gcc -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall *.c -funroll-loops`
SSE2 and SSE4.2 are not used in the code, but allow the compiler to use these extensions. It may increase the performance.
`-Ofast` and `-march=native` are standard optimisations, `-flto`, `-fwhole-program` and `-funroll-loops` are optimisations which can create minor improvements in this particular case.
`-Wall` is used to ensure there are no major issues, a compiler can detect.

Memory threads are only recommended if you validate hashes and check whether or not they are "better" than another hash, instead of benchmarking the hash. An improvement of 5% can be achieved by using 256 memory-threads in favour of using one thread.
Calculating everything in batches of 256 nonces and finding a nonce that solves the block in the first try but continueing to calculate all other nonces instead of pushing the nonce out right after it was found is no issue. It will have a maximum slowdown of 0.02% (compared to checking and broadcasting it instantly) but adds a 5% speedup on top of that.

Those are the benchmarking results, when using the code as-is on a Xeon E3-1225v2.
```Parameters
	Progressbar: yes
	Iterations
		Full:  1073741824
		Light: 16777216
	Seed: 89abcdef
	Memory-Threads: 1
Mining
        Dataset generation took: 250s                                           
        Calculation of 1073741824 hashes took: 699s                             
	Hashrate is approximately: 1536111H/s
	Result: bc7048295c38a7b1,4fe4a2cac88d7cf5,4e3961f1de653702,cf457a9297902126
Validation
	Cache generation took: 0s
Benchmarking: [##                                                              ]        Calculation of 16777216 hashes took: 804s                               
	Hashrate is approximately: 20867H/s
	Result: d1b5b09b7e14377f,142432f68f2b1d2c,708f4aa171a5485b,71820a8c4785bca5

```
