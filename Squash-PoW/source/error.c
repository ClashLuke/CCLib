// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void error_exit(uint8_t code){
	printf("Error, exiting program. Code: %u\n", code);
	if(code==1) printf("Memory could not be initialised, insufficient RAM?\n");
	exit(-1);
}
