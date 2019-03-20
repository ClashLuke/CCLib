To compile the miner, you will have to run `gcc -O3 -march=native squash.c blockchain.c aes.c mine.c blake2/blake2b.c pow.c -o mine.o`. </br>
To compile the validator (used for synchronising nodes), you will have to run `gcc -O3 -march=native squash.c blockchain.c aes.c validate.c blake2/blake2b.c pow.c -o validate.o`. </br>
`squash.c` contains all squash functions, which can be adapted for other algorithms or simply picked as a hash algorithm. </br>
