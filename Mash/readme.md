A quick-to-verify hash entirely dependent on the memory bandwidth

Those are the benchmarking results, when using the code as-is on a Xeon E3-1225v2.
```
Parameters
	Progressbar: yes
	Iterations
		Full:  1048576
		Light: 16384
	Seed: 89abcdef
Config
	Access Rounds: 64
	Dataset Parents: 4
	Benchmark: no
Mining
        Dataset generation took: 61s                                            
        Calculation of 1048576 hashes took: 167s                                
	Hashrate is approximately: 6278H/s
	Result: 375a81e77f7f2794,c51dfdea938b5a48,484a4722e8abe589,42fbcab1dec6a4b6
Validation
	Cache generation took: 0s
        Calculation of 16384 hashes took: 39s                                   
	Hashrate is approximately: 420H/s
	Result: b7f279906ee37bf1,6006b426afd688d0,82e9b4a163024a51,2e92d6521302bb5a


```

An easy-to-plug-in single-file solution can be found in `onefile.c`, all functions required to call use selfexplanatory names and can be seen in `onefile.h`. To test this algorithm and achieve benchmarking results like above, it is recommended to compile the files in the `source/` folder.

Recommended way of compiling: `gcc -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall *.c -funroll-loops`
SSE2 and SSE4.2 are not used in the code, but allow the compiler to use these extensions. It may increase the performance.
`-Ofast` and `-march=native` are standard optimisations, `-flto`, `-fwhole-program` and `-funroll-loops` are optimisations which can create minor improvements in this particular case.
`-Wall` is used to ensure there are no major issues, a compiler can detect.

In case the configuration is supposed to be tweaked, please read through the following section:
Memory threads are only recommended if you validate hashes and check whether or not they are "better" than another hash, instead of benchmarking the hash. An improvement of 5% can be achieved by using 256 memory-threads in favour of using one thread.
Calculating everything in batches of 256 nonces and finding a nonce that solves the block in the first try but continueing to calculate all other nonces instead of pushing the nonce out right after it was found is no issue. It will have a maximum slowdown of 0.02% (compared to checking and broadcasting it instantly) but adds a 5% speedup on top of that.
