void get_current_header(uint8_t* header_out);
void getheader(uint64_t block_height, uint8_t* header_out);
void gethash(uint64_t block_height, uint8_t* hash_out);
uint64_t getdifficulty(uint64_t block_height);
void submitblock(uint8_t* header, uint64_t nonce);
uint64_t getnonce(uint64_t block_height);
