## AES-ICC
AES IV cypher chain mode is a new, super fast AES mode.

- [Algorithm](#Algorithm)
- [Speed](#Speed)
- [Analysis](#Analysis)
	- [Security](#Security)
	- [Decryption](#Decryption)
	- [Parallelism](#Parallelism)
- [Implications](#Implications)

### Algorithm
AES-ICC is designed to iterate by iteself instead of relying on the predefined AES iterations. Therefore a key expansion algorithm is not necessary which saves many cycles and allows faster procesing. The ICC mode takes in a 256bit key, 256bit IV and a message with a lenght dividable by 32 byte. This is needed to process the message in 256bit blocks, more exact, two 128bit blocks in parallel on one CPU core. Therefore by utilising the natural CPU delays AES-ICC is naturally twice as fast as other encryption algorithms. Instead of encrypting the message blocks in a chain dependant on the previous block (like the CBC mode does), ICC encrypts the IV many times and XORes it with the current message block. This allows an optimised usage of the AES-NI aswell as optimisation of the CPU delays. After one iteration over the current message, it jumps back to the start and performs another encryption round over the entire message. Therefore the entire message is encrypted 16 times with different keys and one AES round, which differentiates this mode from other modes.

### Speed
As mentioned above, by utilising two sequential optimised encryptions, the encoding speed doubles. Additionally a key generation is not necessary which additionaly halves the time needed. In combination with the optimised XORing. On a [Xeon E3-1225v2](https://ark.intel.com/content/www/us/en/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html) using the 256 bit encryption, its 16 rounds and one core, the following speeds can be achieved:
```
Calculation of 1024 iterations of encrypting 2147483648 bytes took: 4469s
Average throughput: 492.061592MB/s
```
For comparision, this is what the results from the OpenSSL speed test look like:
```
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes  16384 bytes
aes-128 cbc     120770.69k   132570.88k   135177.62k   136638.80k   137251.43k   137132.38k
aes-192 cbc     104438.74k   111237.49k   112918.61k   113265.12k   113962.34k   113673.21k
aes-256 cbc      89156.66k    95723.47k    96961.02k    97594.37k    97230.85k    97326.42k
```
This results in 6.5 cycles per byte on an Ivy Bridge CPU for ICC, 23.3 cycles per byte (16KiB blocks, 128 bit security) for AES CBC.

### Analysis
#### Security
AES ICC is a variant of AES CBC, thefore the security of both is nearly equivalent. Encrypting two 128 bit blocks with two 128 bit keys using one AES round multiple times is more secure than using multiple AES rounds on the same 256bit with the same key. This is because the message that has to be encrypted changes drastically after every AES round and it is also dependant on the lenght of the message. Therefore by padding the message to a different lenght, its encryption result will change.

#### Decryption
Since the encryption is already covered above, the decryption has to be covered aswell. To be able to encrypt a part of the message, every temporary IV has to be calculated. This can be done by simply traversing the message from the beginning to the end, just like it was done in the encryption. The IV still gets encrypted step by step and every block still gets XORed. Thanks to the properties of XOR, this reverts the message to its original state. This also implies that the encryption and decryption speeds are identical.

#### Parallelism
Since every block depends on the previous block, parallelism is not possible. While it would be possible to preprocess data to have two concurrent threads where one encrypts and the other one is just a little faster, this would be a waste of energy since the XOR operation is very fast compared to the AES operation.

### Implications
For anyone to be able to decrypt a message, they would need access to the whole message aswell as IV and Key, which is strongly different to AES CBC, GCM or other frequently used modes. In those, you can always decrypt a message if you only hold parts of it (of course, in CBC only if you hold the beginning).
