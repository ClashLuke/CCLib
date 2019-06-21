// Copyright (c) Luke Parker, distributed under the MIT License. For more information, see LICENSE.
// Copyright (c) 2019, The Aptum Project

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

uint8_t* urand(int length) {
    uint8_t* bytes = (uint8_t*) calloc(1, length);
#if defined(_WIN32) || defined(_WIN64)
    HCRYPTPROV hcp;
    CryptAcquireContext(&hcp,NULL,NULL,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT or CRYPT_SILENT);
    CryptGenRandom(hcp, length, bytes);
    CryptReleaseContext(hcp, 0);
#else
    FILE* urand = fopen("/dev/urandom", "r");
    if(!fread(bytes, 1, length, urand)) exit(1);
    fclose(urand);
#endif
    return bytes;
}

uint64_t urand64(){
	uint64_t bytes_64 = 0;
	uint8_t* bytes    = (uint8_t*)&bytes_64;
#if defined(_WIN32) || defined(_WIN64)
	HCRYPTPROV hcp;
	CryptAcquireContext(&hcp,NULL,NULL,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT or CRYPT_SILENT);
	CryptGenRandom(hcp, 8, bytes);
	CryptReleaseContext(hcp, 0);
#else
	FILE* urand = fopen("/dev/urandom", "r");
	if(!fread(bytes, 1, 8, urand)) exit(1);
	fclose(urand);
#endif
	return bytes_64;
}
