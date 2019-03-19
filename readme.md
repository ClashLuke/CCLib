*This readme will be replaced*

# Squash
A provably fast and expensive hash algorithm</br>

## ToDo
The following things have to be done
- [ ] Security Analysis (Review)
- [ ] Benchmark on ARMv8, SSE4.2 compatible CPU and AMD GPUs.

## Tests
Tests and sample results can be found in the [Tests Branch](https://github.com/ClashLuke/Squash-Hash/tree/tests). Head over there for further instructions.

## Speed
On a [Xeon E3-1225v2](https://ark.intel.com/content/www/us/en/ark/products/65733/intel-xeon-processor-e3-1225-v2-8m-cache-3-20-ghz.html), the algorithm has an average speed of 58.5ns. For comparision, keccak takes about 800ns on average. Which results in 5.8 cpb for squash, 80 cpb for keccak - on an Ivy Bridge CPU.<br>
On a [Raspberry Pi 3b+](https://www.raspberrypi.org/magpi/raspberry-pi-specs-benchmarks/), the calculation of one hash takes about 1534ns on average, which results in 33.5 cpb. For comparision, one keccak execution takes about 15467ns which results in 338 cpb.

## Compilation
To get the optimal speed, it is recommended to compile using the `-O3 -march=native` (5x speed) flags aswell as `-maes` (9x speed) if supported by the CPU. Additionally it is recommended to use GCC instead of Clang. The compilation process will take about 20% less time and the execution of the hash will be about 25% faster. Differences in execution speed from GCC-6, GCC-7 and GCC-8 are very low, but GCC-7 consistantly gets the fastest results.
**Please note, that this Project is still under development. It works perfectly fine on all machines machines**

If you have got any issues, please open a case.
If you know how to improve parts of the code, make sure to send a pull request.





