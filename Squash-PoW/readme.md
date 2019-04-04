# SquashPoW
A cryptocurrency hash algorithm derived from squash and the [ethash](https://github.com/ethereum/wiki/wiki/Ethash) design, to provide strong resistance against ASICs and FPGAs.

**Contents**
- [General](#General)
	- [Speed](#Speed)
	- [Reference](#Reference)
- [Design](#Design)
	- [CRC32](#CRC32)
	- [Parameters](#parameters)
- [ASICs](#ASICs)
	- [Light-Evaluation-Method](#Light-Evaluation-Method)
	- [Full-Evaluation-Method](#Full-Evaluation-Method)


## General

### Speed
The same Xeon E3-1225v2 as mentioned above has about 100kH/s (single-threaded, using DDR3-1333 RAM) using the 4GiB dataset, 11H/s using the light mode and a 64MiB cache. An IoT device such as a rapsberry pi 3B+ achieves an average hashrate of 0.9H/s on one thread. This is because they utilise much slower CPUs to allow huge power savings as well as tiny amounts of RAM, forcing the device to run in validation mode - even while mining. Therefore this speed difference can be seen as a way to lock out low-power devices, which would otherwise create rising prices for users of these as well as increasing the risk of an attack by a botnet. Mobile phones are not the most secure devices.

### Reference
A reference implementation for cryptonote based currencies can be seen in [this](https://github.com/Tax-Project/Clash/pull/1) pull request made for Clash, a Turtlecoin fork. The squash.c file used in there can be seen in here aswell, as onefile.c. The same source can be found in the `source/` directory, written in multiple files, to increase readability.

## Design
SquashPoW is intended to satisfy the following goals, derived from [ethash](https://github.com/ethereum/wiki/wiki/Ethash-Design-Rationale).

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

## ASICs

Asic Resistance is one of the main concerns in the cryptocurrency industry. To provide a strong security against them while also providing several [design considerations](#design) is the core achievement of the SquashPoW algorithm. The following two methods can be used to create an ASIC for this algorithm:

## Light-Evaluation-Method
The first method an ASIC might use, is called the "Light Evaluation Method" because an ASIC uses many concurrent threads and stores a 64MiB cache instead of the full 4GiB dataset per thread. This method relies entirely on the speed of the generation of one dataset item. If an ASIC is able to generate an item faster than a CPU/GPU can, so much faster that it is not needed to store the 4GiB scratchpad but instead calculate every item when needed. To fight against this method being used on CPU/GPU, the dataset generation is made to be computationally expensive. For an ASIC, a repetitive algorithm can be implemented easily. Which is why the dataset generation uses an algorithm which already is ASICed for CPUs. CRC32 is hardware-implemented in ARMv8 CPUs, which means that an ASIC wont get be faster than a modern CPU. Since a CPU needs about 4'600x more time computing each dataset item at runtime compared to reading from the RAM, we can assume that the same goes for an ASIC. If an ASIC would use 4GiB RAM, it would be 72 times slower using the Light Evaluation Method and need 64x more computational energy compared to it using the Full Evaluation Method.

## Full-Evaluation-Method
Using this variation, an ASIC wont run the code a validator will but instead precomputate the dataset to iterate over it and read from it. Since the dataset changes every epoch, and epochs are designed to happen every hour, it is unlikely to be some kind of ROM. Instead, an ASIC would have to use RAM such as HBM2.1. Assuming that GPU vendors already use top-of-the-line RAM, an ASIC will not get any advantages there. Which means the only possible speed improval would be the computational part. Since the computational part of the algorithm takes about one one-hundreth (on ARMv8) of the total time, there is a potential gain of 1% (assuming a manufacturer would be able to reduce this part to literally nothing). Since this is not the case, an ASIC would most likely be an ARMv8 CPU with fast HBM RAM.
