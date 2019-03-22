#include <stdint.h>
#include <string.h>
#include <stdio.h>

void get_current_header(uint8_t* header_out){
	/* Currently a dummy function
	Extracts the header of the data
	of the block at a given height */
	// Obtain header data
	uint8_t header[80] =  {[0 ... 79] = 6};
	memcpy(header_out, header, 80);
}
void getheader(uint64_t block_height, uint8_t* header_out){
	/* Currently a dummy function
	Returns the block header of a previous
	Block, stored in the chain. */
	// Obtain header data
	uint8_t header[80] =  {[0 ... 79] = 6};
	memcpy(header_out, header, 80);
}
void gethash(uint64_t block_height, uint8_t* hash_out){
	/* Currently a dummy function
	Extracts the block hash of the data
	of the block at a given height */
	// Get Block Hash
	uint8_t hash[32] =  {[0 ... 31] = 6};
	memcpy(hash_out, hash, 32);
}
uint64_t getdifficulty(uint64_t block_height){
	/* Currently a dummy function
	Calculates the difficulty for a given
	block height. You can calculate up to
	one block in advance. */
	// Get difficulty
	uint64_t out = 1<<16;
	//out = out<<2;
	return out;
}
void submitblock(uint8_t* header, uint64_t nonce){
	/* Currently a dummy function
	Submits the block to the network
	and adds it to the own chain */
	// Assemble Block
	printf("%016jx\n",nonce);
}

uint64_t getnonce(uint64_t block_height){
	/* Currently a dummy function
	Extracts the nonce of the data
	of the block at given height */
	// Get difficulty
	return 1024;
}

