**Contents**

- [CRC32](#fnv)
- [Parameters](#parameters)

Ethash is intended to satisfy the following goals:

1. **IO saturation**: The algorithm should consume nearly the entire available memory access bandwidth (this is a strategy toward achieving ASIC resistance, the argument being that commodity RAM, especially in GPUs, is much closer to the theoretical optimum than commodity computing capacity)
2. **CPU friendliness**: Targeting CPUs is difficult due to existing issues such as botnets, GPUs and ASICs. To decrease their performance, the algorithm uses special CPU features that already are there in modern CPUs but are missing in modern GPUs and are costly to implement in ASICs. Since GPUs have a bigger memory bus, the tradeoff is an almost equal situation between GPUs and CPUs.
3. **Light client verifiability**: a light client should be able to verify a round of mining in under 0.03 seconds on a desktop in C. With 1-hour blocktargets, this would mean that a validator is able to validate the blocks of a day in one second.
4. **Light client slowdown**: the process of running the algorithm with a light client should be much slower than the process with a full client, to the point that the light client algorithm is not an economically viable route toward making a mining implementation, including via specialized hardware.
5. **Light client fast startup**: a light client should be able to become fully operational and able to verify blocks within 2 seconds in C.

### CRC32

CRC32 was used to provide a data aggregation function which is (i) non-associative, and (ii) easy to compute. A commutative and associative alternative to CRC32 would be XOR. Furthermore, a CRC has the advantage of already being implemented in CPU hardware which makes it difficult to compute for GPUs and expensive for specialised hardware.

### Parameters

* A 64 MB cache was chosen because a smaller cache would allow for an ASIC to be produced far too easily using the light-evaluation method. The 64 MB cache still requires a very high bandwidth of cache reading, whereas a smaller cache could be much more easily optimized. A larger cache would lead to validation nodes requiring more RAM which is not feasable at certain points. 
* 256 parents per DAG item was chosen in order to ensure that time-memory tradeoffs can only be made at a worse-than-1:1 ratio. It is not higher to assure a fast verification for validators. It is possible to reduce the accesses and increase the dataset parents to have the same resulting speed for a validator, increased speed for the miner but lower ASIC resistance.
* The 4GiB DAG size was chosen in order to require a level of memory larger than the size at which most specialized memories and caches are built, but still small enough for ordinary computers to be able to mine with it.
* In contrast to ethash, there is no multiplator to suit the changes associated with moores law. This is done since 1) most people dont upgrade their computers, and this applies to ASICs only and 2) moores law seems to not apply anymore, which means that there is more observation over the next three years needed. Especially considering that intels [3D stacked CPUs](https://en.wikipedia.org/wiki/Three-dimensional_integrated_circuit) might speed up everything up once they are released.
* 1024 accesses was chosen to bound the speed of the algorithm completely to the IO. This was done in order to reduce the risk of ASICs which may not improve the memory speed further than what is available to GPUs.
* The epoch length cannot be infinite (ie. constant dataset) because then the algorithm could be optimized via ROM, and very long epoch lengths make it easier to create memory which is designed to be updated very infrequently and only read often. Excessively short epochs would increase barriers to entry as weak machines would need to spend much of their time on a fixed cost of updating the dataset. The epoch length can probably be reduced or increased substantially if design considerations require it.
</br></br>
The SquashPoW algorithm and this file are heavily inspired by ethash.
* [Ethash Design Rationale](https://github.com/ethereum/wiki/wiki/Ethash-Design-Rationale)
* [Ethash Function Explanation](https://github.com/ethereum/wiki/wiki/Ethash)
