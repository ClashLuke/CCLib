uint8_t* getheader();
uint8_t* getheader(uint64_t block_height);
uint64_t getdifficulty(uint64_t block_height);
void submitblock(uint8_t* header, uint64_t nonce);
uint64_t getnonce(uint64_t block_height);
