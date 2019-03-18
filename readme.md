*This readme will be replaced*

# Squash
A provably fast and expensive hash algorithm</br>

## ToDo
The following things have to be done
- [ ] Security Analysis (Review)
- [ ] Benchmark on ARMv8, SSE4.2 compatible CPU and AMD GPUs.

## Benchmarking
To test out squash, it is recommended to use the shipped python scripts which can be found in `tests/`. Please note that the C code in this folder writes to a file and therefore is a lot slower than the C code in squash.c.
### Parameters
Atleast one algorithm has to be tested, atleast one test option has to be specified. 
```
Algorithm options


Test options
-b, --bit                 Enable bit histogram
-B, --bucket              Enable bucket histogram
-c, --collisions          Enable collision testing
-i, --iterations number   Set the number of iterations
-t, --time                Enable runtime testing
Output options
-o, --out directory       Specify out directory
-P, --plot                Show plots instead of writing them
-w, --write               Write to a file instead of console outputs

-h, --help                Display this help message
```
By default the out directory is set to "results" and iterations are set to 65536 to enable quick, relatively accurate testing. All other values are disabled by default.</br>
An example for a command could be the following: `python3 tests.py -s -i 65536 -t -c -w -b -B`. It performs all tests on squash while using 65536 (2**16) iterations.</br>
**ATTENTION** Since the "similarity" test is obsolete and relies on eyeballing, it has been removed. To check the similarity of the hashes with similar inputs, go to docs/hash_sample.txt or generate one yourself using the python module in tests/.


### Dependencies
Those scripts use [Python3.7](https://www.python.org/downloads/release/python-372/), please make sure you use it instead of the older versions.
To create plots (bucket histogram and bit histogram), you will need to install [matplotlib](https://matplotlib.org/).
You can install it using the following command `python3.7 -m pip install matplotlib`.</br>
A CPU has to be capable of performing 64bit operations, speedups for the [AES-NI](https://en.wikipedia.org/wiki/AES_instruction_set) and ARMv8 are available.

### Plots
The plots have no labeling and therefore are described in here.</br> 
In the bit histogram you can see the average value of a group of four bits at a specific position. The Y-Axis shows the average value where the X-Axis displays the position. Ideally it is a straight line at the value of 8.</br>
The bucket histogram cuts of the first part of every hash value and only takes the last 16bit. Those are then used to fit everything into a bucket. The X-Axis displays the buckets, where each bucket corresponds to a value (such as 0, 1 or 65535). The Y-Axis corresponds to the absolute number of entities in this bucket. Ideally this is a straight line aswell at ITERATIONS/65536.</br>

### Speed
On a [Xeon E3-1225v2](https://ark.intel.com/content/www/us/en/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html), the algorithm has an average speed of 47ns. For comparision, keccak takes about 800ns on average. Which results in 4.7 cpb for squash, 80 cpb for keccak - on an Ivy Bridge CPU.<br>
On a [Raspberry Pi 3b+](https://www.raspberrypi.org/magpi/raspberry-pi-specs-benchmarks/), the calculation of one hash takes about 1534ns on average, which results in 33.5 cpb. For comparision, one keccak execution takes about 15467ns which results in 338 cpb.

### Compilation
To get the optimal speed, it is recommended to compile using the `-O3 -march=native` (5x speed) flags aswell as `-maes` (9x speed) if supported by the CPU. Additionally it is recommended to use GCC instead of Clang. The compilation process will take about 20% less time and the execution of the hash will be about 25% faster. Differences in execution speed from GCC-6, GCC-7 and GCC-8 are very low, but GCC-7 consistantly gets the fastest results.
**Please note, that this Project is still under development. It works perfectly fine on all machines machines**

If you have got any issues, please open a case.
If you know how to improve parts of the code, make sure to send a pull request.





