## AES-Hash
The simplest of all hashes, the AES hash.

- [Design](#Design)
- [Speed](#Speed)

### Design
The AES-Hash function uses nothin but AES. It uses the AES single round function (which performs one AES round) to iterate over the input and encrypt a seed with every 256bit block of the message. The result is a 256bit hash value (in the seed variable).

### Speed
Since x86 and ARMv8 are heavily use the AES-NI, both architectures achieve very throughputs. The tests, which can be in hash.c, were run on a [Xeon E3-1225v2](https://ark.intel.com/content/www/us/en/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html) and resulted in the following output:
```
Calculation of 256 iterations of encrypting 2147483648 bytes took: 79s
Average throughput: 6958.934353MB/s
Result: 194ce79752edf3bc.9ce020c307023ff8:7bb12bae9b64c2b0.d3d6f4fb6c0695ed
```
Therefore the algorithm uses approximately 0.46 cycles per byte (2.17 bytes per cycle). Compared to blake2 and other fast hashing algorithms, this is a strong speed. Yet it is not enough to beat [CRC256](https://github.com/ClashLuke/CCLib/tree/master/CRC256).
