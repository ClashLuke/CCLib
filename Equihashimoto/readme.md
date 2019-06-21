Generate dataset of 4GiB

calculate hash of block header (excl. nonce) (64 bytes->16x 4 bytes)

blockheaderhash64[i] += nonce64 (repeat for all 8 values for i)
read 16 8 bit blocks from random positions (random, not &0x40)
read 4 64 bit blocks from random positions (random, not &0x40)
xor 4 64 bit blocks to get result r
if r is equal to 0, return nonce
else blockheaderhash64[i] += 1 (repeat for all 8 values for i)16 
