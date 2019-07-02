// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef CONFIG_H
#define CONFIG_H

#define ROUNDS 2 // Rounds are equal to the number of birthdays that 
		 // have to be equal in the birthday paradox.
#define LARGEB 1 // when activated, 64bit memory accesses are used instead of 32bit memory accesses
		 // much less likely to find a potential solution but also much faster traversing
		 // through the entire memory. Can be used as an alternative to using a high round 
		 // number

#endif
