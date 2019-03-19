#include <stdint.h>

uint8_t* getheader(){
	/* Currently a dummy function
	Extracts the header of the data
	of the block at a given height */
	uint8_t header[80] = {0};
	// Obtain header data
	header = {[0 ... 79] = 6};
	return header;
}
uint8_t* getheader(uint64_t block_height){
	/* Currently a dummy function
	Returns the block header of a previous
	Block, stored in the chain. */
	uint8_t header[80] = {0};
	// Obtain header data
	header = {[0 ... 79] = 6};
	return header;
}
void gethash(uint64_t block_height){
	/* Currently a dummy function
	Extracts the block hash of the data
	of the block at a given height */
	// Get difficulty
	return 1024;
}
uint64_t getdifficulty(uint64_t block_height){
	/* Currently a dummy function
	Calculates the difficulty for a given
	block height. You can calculate up to
	one block in advance. */
	// Get difficulty
	return 1024;
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

