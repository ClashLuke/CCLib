A CPU-only interpretation of the popular [balloon hashing algorithm](https://crypto.stanford.edu/balloon/).

Benchmarking results using one thread on a Xeon E3-1225v2 are the following
```
Parameters
	Progressbar: yes
	Iterations: 16384
	Seed: 89abcdef
Config
	Cache Size: 2048KiB
	Mixing Iterations: 1048576
	Input Size: 32 Byte
	Output Size: 32 Byte
Mining
        Calculation of 16384 hashes took: 104s                                  
	Hashrate is approximately: 157H/s
	Result: f9095a6235a9c980,d9f5648708861472,d515fc861ea16c24,73ac5075161a3a60
```
Research by the initial cryptonote developers suggests that the number of iterations should not be drastically lowered. They also suggest that, when increasing the cache size, the number of iterations to mix over it has to be increased. Sumokoin, Loki and Aeon as well as many other cryptocurrencies ignored this and warning and changed the iterations to their liking without experiencing anything close to an issue.
Therefore the iteration parameter is equal to a time-cost parameter, while the cache size is a memory-cost parameter. It is not recommended to go below 2MB, since this would make ASICs easier and allow GPUs to utilise significantly more threads than a CPU can. 2MB are designed to be as close as possible to the average amount of L3 cache per CPU core.
