In Equihashimoto, the most important thing is memory-dependency. Say `m` is the variable determining the memory intensity (for the purpose of accurate and recreatable calculations, m is measured in bytes). The time complexity `t` for the algorithm to find a solution, assuming that there are no memory optimisations and a complete randomness, is equal to `2*m*(m-1)` CPU cycles in a best-case scenario. This best-case scenario assumes that all memory is on-cache and checks are performed in one CPU cycle. Considering that a minimum of 4 GiB (2^32 bytes) are recommended to achieve strong ASIC and botnet resistance, the minimum time spent calculating one nonce, assuming that there are no memory optimisations possible for the algorithm, is `t = 2*m*(m-1) = 2^65-2^33` CPU cycles. Converting CPU cycles to seconds, on a normal 4GiHz CPU with one active thread, the average best-case execution time for the algorithm to create one subnonce to one nonce is 272 years. 

Since this is not feasable, further research has to be done.

The dataset is tied to 4GB (or (2^32)-31 elements of 32bit size) and generated once for every "seed hash". The seed hash is the hash of the block header including the transactions and the nonce and therefore can be changed quickly. A dataset of 4GB for mining is not enforced, but recommended to achieve the optimal performance. The upper limit is 4GiB.

Dataset generation: 4.5s/4GiB

Recommended Rounds: 5 or 6.

The number of rounds determines how many items have to be equal to eachother. Research of the birthday paradox indicates that with n days in a year and a group of n/2 people, you already have a probability of 50% of finding one one possible solution if the number of rounds is equal to four, which could lead to memory optimisations. When the number of rounds is five, you need n people to achieve a 75% probability of finding a fitting solution with your current dataset. The next best optimisation in the case of five rounds would be a probability of 50% of finding a possible solution to the birthday paradox when using a 3.4GiB dataset. Further increasing the number of rounds to 6 would allow a 12.5% chance for every miner (per thread) to find one nonce on a 4GiB dataset. When using a smaller dataset such as 2GiB, the probability is in the low 0%-area.

Please note that increasing the rounds heavily increases the time needed for the successful finding of the required amount of sub-nonces to the previous nonce and with that also increases the minimum required block time.

With four rounds, the minimum required block time would be 8s. (3s is the average time required for finding a nonce, 4.5s is the average dataset generation time).

After sub-nonces to the major nonce are found, they are attached to the block and hashed with any fast hash such as blake2s or AES-hash, if the result meets the difficulty requirements, it can be submitted.

Using six rounds, the minimum required block time would be 20 minutes, since the dataset takes five seconds to generate and it takes approximately 19 minutes on average to find a solution to the underlying birthday paradox. While six rounds definitely provide a strong security against memory optimisations, they cant be used by most currencies due to their time intesity of read-only memory accesses. 

Thanks to the underlying design of the birthday paradox, an ASIC for this algorithm would be a chip with on-chip memory and a large memory bus.

Using this design, equihashimoto is botnet resistant, has heavy ASIC resistance and low dataset generation times while being extremely fast verifyable (18M Validations/s). Additionally it's provably assymetric and provably secure.

Possible optimisations
- [ ] memcpy large blocks to cache instead of accessing one item at a time
- [ ] improve dataset generation time (maybe not AES?)
- [ ] improve dataset generation (smaller blocks -> getting 32bit blocks is faster)

