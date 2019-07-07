A CPU-only interpretation of the popular [balloon hashing algorithm](https://crypto.stanford.edu/balloon/).

Benchmarking results using one thread on a Xeon E3-1225v2 are the following
```
Parameters
	Progressbar: yes
	Iterations: 1048576
	Seed: 89abcdef
Config
	Cache Size: 1024KiB
	Mixing Iterations: 65536
	Input Size: 64 Byte
	Output Size: 32 Byte
Mining
	Calculation of 1048576 hashes took: 463s
	Hashrate is approximately: 2264H/s
	Result: 38ab41958d6d5a0f,179c7e0871e349e5,3fadd2e246b2319e,f375ad305540957c
```
Research by the initial cryptonote developers suggests that the number of iterations should not be drastically lowered. They also suggest that, when increasing the cache size, the number of iterations to mix over it has to be increased. Sumokoin, Loki and Aeon as well as many other cryptocurrencies ignored this and warning and changed the iterations to their liking without experiencing anything close to an issue.
Therefore the iteration parameter is equal to a time-cost parameter, while the cache size is a memory-cost parameter. It is not recommended to go below 2MB, since this would make ASICs easier and allow GPUs to utilise significantly more threads than a CPU can. 2MB are designed to be as close as possible to the average amount of L3 cache per CPU core.
