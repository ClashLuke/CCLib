*This readme will be replaced*

# Squash
A provably fast and expensive hash algorithm</br>
It is recommended to use the python scripts since the C script is a lot slower. (1'300ns vs 300'000'000ns)

## Parameters
Atleast one algorithm has to be tested, atleast one test option has to be specified. 
```
Algorithm options
-k, --keccak              Perform tests on keccak
-s, --squash              Perform tests on squash
-i, --iterations number   Set the number of iterations
-t, --threads num         Specify the number of threads to use (Squash only)


Test options
-t, --time                Enable runtime testing
-c, --collisions          Enable collision testing
-p, --probability         Enable testing of value probabilities
-S, --similarity          Enable testing of hash similarities
-b, --bit                 Enable bit histogram
-B, --bucket              Enable bucket histogram

Output options
-w, --write               Write to a file instead of console outputs
-P, --plot                Show plots instead of writing them
-o, --out directory       Specify out directory

-h, --help                Display this help message
```
By default the out directory is set to "results" and iterations are set to 65536 to enable quick, relatively accurate testing. All other values are disabled by default.</br>
An example for a command could be the following: `python3 tests.py -s -i 65536 -t 2 -T -c -p -S -w -b -B`. It performs all tests on squash while using a total of two threads and 65536 (2**16) iterations.


## Dependencies
Those scripts use Python3, please make sure you use it instead of the older versions.
You will need to download the following libraries:

	matplotlib
	pycrypto

You can install those dependencies using the following command `python3 -m pip install matplotlib pycrypto`.

## Plots
The plots have no labeling and therefore are described in here.</br> 
In the bit histogram you can see the average value of a group of four bits at a specific position. The Y-Axis shows the average value where the X-Axis displays the position. Ideally it is a straight line at the value of 8.</br>
The bucket histogram cuts of the first part of every hash value and only takes the last 16bit. Those are then used to fit everything into a bucket. The X-Axis displays the buckets, where each bucket corresponds to a value (such as 0, 1 or 65535). The Y-Axis corresponds to the absolute number of entities in this bucket. Ideally this is a straight line aswell at ITERATIONS/65536.</br>

**Please note, that this Project is still under development. It works perfectly fine on all machines machines**

If you have got any issues, please open a case.
If you know how to improve parts of the code, make sure to send a pull request.




