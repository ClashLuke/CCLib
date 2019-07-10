## Bidash
A bi-assymetric hash combining the birthday problem with dagger.

**Contents**

- [General](#General)
	- [Concept](#Concept)
	- [Speed](#Speed)
	- [Difficulty](#Difficulty)
- [Security](#Security)
	- [Dataset](#Dataset)
	- [Birthday-Paradox](#Birthday-Paradox)
	- [Memory](#Memory)
	- [Time-Memory-Tradeoff](#Time-Memory-Tradeoff)
- [Comparision](#Comparision)
	- [Equihash](#Equihash)
	- [Dagger](#Dagger)
	- [Balloon](#Balloon)
- [Resistance](#Resistance)
	- [ASIC](#ASIC)
	- [FPGA](#FPGA)
	- [GPU](#GPU)
- [ToDo](#ToDo)

### General
#### Concept
Bidash is a bi-assymetric hash algorithm combining the research of the [birthday problem](#Birthday-Paradox) and [dagger](https://webcache.googleusercontent.com/search?q=cache:bmDsAGmmcG8J:www.hashcash.org/papers/dagger.html+).

In bidash, the most important thing is memory-dependency. Say `m` is the variable determining the memory intensity (for the purpose of accurate and recreatable calculations, m is measured in bytes). Unfortunately with a background of the equihash and the birthday paradox, the time complexity `t` for the algorithm to find a solution, assuming that there are no memory optimisations and a complete randomness, is equal to `2*m*(m-1)` CPU cycles in a best-case scenario. This best-case scenario assumes that all memory is on-cache and checks are performed in one CPU cycle. Considering that a minimum of 4 GiB (2^32 bytes) are recommended to achieve strong ASIC and botnet resistance, the minimum time spent calculating one nonce, assuming that there are no memory optimisations possible for the algorithm, is `t = 2*m*(m-1) = 2^65-2^33` CPU cycles. Converting CPU cycles to seconds, on a normal 4GiHz CPU with one active thread, the average best-case execution time for the algorithm to create one subnonce to one nonce is 272 years. (Further reading: [A generalized Birthday Problem](https://link.springer.com/content/pdf/10.1007%2F3-540-45708-9_19.pdf), [Lattice Problem](https://cseweb.ucsd.edu/~daniele/papers/SVP.pdf))

Therefore a different approach has to be used, which skips a lot of work yet requires the entire dataset to be existent.

The dataset is tied to 4GB (or (2^32)-31 elements of 32bit size) and generated once for every "seed hash". The seed hash is the hash of the block header including the transactions and the nonce and therefore can be changed quickly. A dataset of 4GB for mining is not enforced, but recommended to achieve the optimal performance. The upper limit is 4GiB.

Dataset generation: 4.5s/4GiB

After sub-nonces to the major nonce are found, they are attached to the block and hashed with any fast hash such as blake2s or AES-hash.

Thanks to the underlying design of the birthday paradox, an ASIC for this algorithm would be a chip with on-chip memory and a large memory bus.

Using this design, bidash is botnet resistant, has heavy ASIC resistance and low dataset generation times while being extremely fast verifyable, provably assymetric and provably secure.

Difficulty works perfectly fine. Diff * 2 = Time * 2. Minimum recommended difficulty: 2^32. 

GPUs can't mine, because a CPU finishes one nonce in 1s (dataset generation) + 3s (calculation) but a GPU needs 5+ seconds to generate the dataset itself. When copying the dataset generated on CPU to GPU, 1+ second is needed only for the process of copying it. The GPU would then have up to 2s to check all items in the dataset in parallel, find a solution and broadcast it back to the CPU. This appears to be very unlikely.

```
Parameters
	Progressbar:  yes
	Iterations
		Full:  1024
		Light:  68719476736
	Seed:  89abcdef
	Difficulty:  4294967296
Mining
        Calculation of 1024 solutions took:  3710s                              
	Hashrate is approximately:  5 s/sol
	Found 649 solutions for 1024 nonces. Rate: 63%
	Result:  a19231ee,715c0c64
Validation
        Calculation of 67108864 hashes took:  80s                               
	Hashrate is approximately:  838860.8 H/s
	Result:  0000000000000000

```

###ToDo
- [ ] **General Optimisations**
- [ ] Merge stacked seed CRCing into code
- [ ] Add dataset item calculation optimisation
- [ ] Get rid of CRCing of seed
- [ ] Implement cn_slow\_hash AES code
- [ ] **Readme**
- [ ] Add "the lower the memory the lower the chance of finding a solution (exponentially)"-text
- [ ] Explain where the expontial growth of time complexity comes from (when reducing the dataset size linearly)
- [ ] Add explanation that difficulty is inside the function itself, not about a hash outside of it
- [ ] Explain how that's an improvement compared to equihash
- [ ] Explain new approach properly
- [ ] Add references
- [ ] Add proper benchmark
- [ ] Improve GPU part
- [ ] Explain difficulty minimum of 2^32

