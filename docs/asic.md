**Contents**

- [Light-Evaluation-Method](#Light-Evaluation-Method)
- [Full-Evaluation-Method](#Full-Evaluation-Method)

Asic Resistance is one of the main concerns at Squash. To provide a strong security against them while also providing several design considerations is the core goal for Squash.

## Light-Evaluation-Method
The first method an ASIC might use, is called the "Light Evaluation Method" because an ASIC uses many concurrent threads and stores a 64MiB cache instead of the full 4GiB dataset per thread. This method relies entirely on the speed of the generation of one dataset item. If an ASIC is able to generate an item faster than a CPU/GPU can, so much faster that it is not needed to store the 4GiB scratchpad but instead calculate every item when needed. To fight against this method being used on CPU/GPU, the dataset generation is made to be computationally expensive. For an ASIC, a repetitive algorithm can be implemented easily. Which is why the dataset generation uses an algorithm which already is ASICed for CPUs. CRC32 is hardware-implemented in ARMv8 CPUs, which means that an ASIC wont get be faster than a modern CPU. Since a CPU needs about 4'600x more time computing each dataset item at runtime compared to reading from the RAM, we can assume that the same goes for an ASIC. If an ASIC would use 4GiB RAM, it would be 72 times slower using the Light Evaluation Method and need 64x more computational energy compared to it using the Full Evaluation Method.

## Full-Evaluation-Method
Using this variation, an ASIC wont run the code a validator will but instead precomputate the dataset to iterate over it and read from it. Since the dataset changes every epoch, and epochs are designed to happen every hour, it is unlikely to be some kind of ROM. Instead, an ASIC would have to use RAM such as HBM2.1. Assuming that GPU vendors already use top-of-the-line RAM, an ASIC will not get any advantages there. Which means the only possible speed improval would be the computational part. Since the computational part of the algorithm takes about one one-hundreth (on ARMv8) of the total time, there is a potential gain of 1% (assuming a manufacturer would be able to reduce this part to literally nothing). Since this is not the case, an ASIC would most likely be an ARMv8 CPU with fast HBM RAM.
