**Contents**

- [Squash 0](#Squash_0)
- [Squash 1](#Squash_1)

SquashPoWs security relies entirely on the underlying squash function. Since squash 2 and 3 are variations of squash 1 with a larger scratchpad, we will we will focus on the squash variants 0 and 1 in here.

## Squash_0

### Step 1 - CRC32
Assuming that there is a perfect CRC, a 32bit redundancy check (with random 32bit inputs) has 2^16 collisions. We calculate the CRC four times to have delays according to the inner-CPU delays. [1](https://github.com/JuliaLang/julia/blob/master/src/crc32c.c#L111) Now 128bit of the input are processed, resulting in 128bit output with 64bit collision-resistance. Code: `crc_32[0] = crc32(data_32[0]);` CRCs are heavily optimised on ARM CPUs since they are an addition to the instructionset. They are relatively expensive for ASICs to implement. [2](https://www.slideshare.net/bschn2/the-rainforest-algorithm)

### Step 2 - Integer Math
The next 128bit are calculated using two times two 64bit integer arithmetics. First, the next 64bit of input data are used to be added to the first two CRCs. Since an addition is a XOR with carry, it can be assumed that the first bit is a casual XOR, all following bits are a doubled XOR. This results in a slightly increased probability for high results - which, since the highest bit is cut off, does not matter. To even the first few bits out, a division of the previous data (3rd 64bit of the input, 1st 64bit of the CRC results) is added to the previous result using a XOR. The resulting expression looks like this `crc_64[2] = (data_64[2] + crc_64[0]) ^ (data_64[2] / crc_64[0]);`. This results in another 128bit with 64bit collision-resistance (assuming that the ADD operator is cryptographically insecure). While those 64bit operations are easy for a modern CPU, it is difficult for ASICs to implement those [2](https://www.slideshare.net/bschn2/the-rainforest-algorithm)

### Step 3 - Bit Moving
A bit reverse and a byteswap of existing data are additionally added, since those require one cycle but significantly increase GPU and ASIC resistance. None of these increases entropy nor collision resistance, but the byteswap is optimised for x86 and ARM instructionsets, which results in a slowdown for GPUs. Additionally the bit reverse is optimised in the ARM instructionset as [rbit](http://www.keil.com/support/man/docs/armasm/armasm_dom1361289889382.htm), which increases performance for low-power devices such as [ARM Server CPUs](https://www.arm.com/products/silicon-ip-cpu/neoverse/neoverse-n1) or smartphones.

### Step 4 - Rotation
Compared to the previous operations, the rotations are relatively cheap. `key[1][0] = (out_64[0]>>shift[0]) | (out_64[0]<<(shift[1]));` Two 64bit rotations in each direction are used to obtain keys to encrypt the previously generated 256bit with. Those are variable rotations, the number of bits to shift is obtained by reading from the first/last byte of the previous 256bit. Since those dont change fundamentally change data but instead are a fancy copy mechanism which provides additional protection against ASICs but cost nothing on a casual CPU [2](https://www.slideshare.net/bschn2/the-rainforest-algorithm).

### Step 5 - Encryption
The last step, an AES ECB encryption, is there to increase entropy, GPU resistance and ASIC resistance as seen [here](https://www.slideshare.net/bschn2/the-rainforest-algorithm). It does not fundamentally increase collision resistance or security. The encryption is performed using the first 128bit of the previous results (the CRC results) and encrypts them with the key obtained from the integer math. The code looks like this: `aes(out, (uint8_t*)key[0]);`. The same thing goes for the second 128bit encrypted with the rotated CRC.

## Squash_1

### Differences to Squash 0
Squash 1 has the same steps as Squash 0, just another step inserted after the first CRC and a slightly changed integer math.

### Step 1.5 - Scratchpad
Right after the first step, four CRC32s, their data is taken to read from a read-only scratchpad. In Squash 1, the first 8bit are used to read from a 256 Byte scratchpad, Squash 2 uses the first 16bit of each CRC to read from a 64KiB scratchpad, Squash 3 uses the full 32bit of each CRC to read from a 4GiB scratchpad. The data obtained from Cache/RAM is then stored as the next 128bit of the data, like this `crc_32[4] = ((uint32_t*)&scratchpad[crc_8[ 0]])[0];`, so that there are two 128bit blocks totalling in 256bit. This step is solely used to force an attacker to store the (ideally pseudorandom) scratchpad. In case of Squash 3, there are iterations of reading, to have the hash be I/O bound instead of processing bound. Since this step heavily relies on the previous CRC, it cannot be better than the CRC32, which results in 64bit collision resistance for the read 128bit.

### Step 2 - Integer Math
Since the second 128bit already are assigned, it would not be useful to reassign them, ignoring their data. Thats why the result of the two 64bit math operations is calculated using 128bit of the previous data `divr[0] = (data_64[2] + crc_64[2]) ^ (data_64[2] / crc_64[0]);` and then XORed with two 64bit blocks `out_64[0] = crc_64[0]^divr[0]; out_64[1] = crc_64[1]^divr[0];`. There are different blocks XORed than used for calculation to increase the variaty of results.

## Conclusions
To sum everything up, Squash is a hash with 128bit collision resistance, a high speed of 5.8 cycles per byte (Ivy Bridge, 4.0 cpb on Zen). In contrast to other hashes, Squash relies on 256bit inputs but is also able to provide a decent level of ASIC resistance. To further increase the ASIC resistance without decreasing the speeds below a [certain level](https://github.com/ethereum/wiki/wiki/Ethash-Design-Rationale), SquashPoW was introduced.
