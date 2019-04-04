# CRC256
A secure 256 bit cyclic redundancy check, faster than blake2.

- [General](#General)
	- [Speed](#Speed)
	- [Security](#Security)
	- [Compilation](#Compilation)
- [Design](#Design)

## General
### Speed
Since CRC32s already are very fast, a CRC256 is very fast aswell. Why the speed of the CRC32 matters can be seen in the [design](#design) section below. To get to the numbers, with about 54GiB/s processing speed on a [Xeon E3-1225v2](https://ark.intel.com/content/www/us/en/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html), we have an average speed of 16.9 bytes per CPU cycle (or 0.06 cycles per byte). On a [Huawei P9 Lite](https://en.wikipedia.org/wiki/Huawei_P9) which utilises the [Cortex A53](https://www.arm.com/products/silicon-ip-cpu/cortex-a/cortex-a53), the total throughput is 30% lower with 30.1 GiB/s with its 1.4GHz ARMv8 CPU. This results in 0.043 cycles per byte on an optimised architecture (or 23 bytes per cycle). To put that into context, CRC256 is about twice as fast as the already fast Blake2b on a x86, and about ten times faster on ARMv8 CPUs. 

### Security
Whenever a drastic speed improvement is proposed, the security of it has to be proven aswell. Luckily this is relatively simple, because this algorithm relies entirely on CRC32 and does nothing but optimising throughput by utilising parallel calculations (optimising CPU-delays) aswell as increasing the size to 256 bit by having eight simultanious streams of CRCs. This allows a parallel execution on two threads to further optimise the speed (more threads would require more memory to be used. Proportional growth). Since the security aswell as the limitiations of CRC256 depends on its [design](#design), it is covered in there.

### Compilation
When compiling or including this code, the compiler should be passed the `-O3` flag aswell as the `-march=native` flag on most devices. For ARMv8 devices, it is recommended to utilise `-march=armv8+crc` to achieve the best speeds. The API, as seen in the header file `crc256.h` is `void crc256(uint8_t* in, uint32_t len, uint8_t* out);`, where `in` aswell as `out` have to be allocated before calling the function. Both have to be aligned to accessed as 8byte addresses on non-x86 CPUs. The lenght has to be given in bytes and also be dividable by 32. If it is not, the last bytes (len%32) will be ignored. Therefore the input has to be padded to this lenght aswell. This is because internally the algorithm uses 256 bit blocks to calculate the data sequentially.

## Design
Under the assumption that a CRC32 has 16 bit collision resistance, two CRC32s of different data have 32 bit collision resistance, eight CRC32s with a total size of 256 bit have a collision resistance of 128 bit. Therefore, by using eight CRC32s to calculate one 256 bit block, this block posesses similar properties to CRC. Internally, the code calculates eight CRC32s like this 
`for(int i=0;i<8;i++) temp_32[i] = crc32(in_32[i]);` and then aggregates the results to the previous result by performing `out_64[i] ^= temp_64[i]` for every 256 bit (32 byte) block of the input. This implies that this implementation still posesses all features of CRC32C, which means that it is up to you whether or not you want to use a longer and better CRC instead of a hash function in your project. [This](https://stackoverflow.com/questions/10953958/can-crc32-be-used-as-a-hash-function#10962213) StackOverflow comment might help answering the question.
