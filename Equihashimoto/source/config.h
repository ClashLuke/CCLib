// Copyright (c) 2019, The CCLib Developers
//
// Please see the included LICENSE file for more information.


#ifndef CONFIG_H
#define CONFIG_H

#define ITEMS  0xffffffff  // Total number of items in the dataset
                           // may be changed to achieve a different
                           // dataset size.
 
#define BLOCK  (1<<20)     // Size of blocks retrieved from memory.
			   // Bigger blocks allow for less memory
			   // accesses (less bound to memory latency)
			   // of larger blocks (more bound to memory
			   // bandwidth) yet also need more cache.
			   // Specifically BLOCK*2+12 bytes are
			   // required per thread.
			   // Changing this will change the speed of
			   // the algorithm but not its result. It may
			   // be used to tune it to its ideal
			   // parameters on a specific machine.

#define COUNT 32          // Total number of dataset generations before
			   // calculating the average of all.

#endif
