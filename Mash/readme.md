A quick-to-verify hash entirely dependent on the memory.

Recommended way of compiling: `gcc -Ofast -msse2 -msse4.2 -march=native -flto -fwhole-program -Wall *.c -funroll-loops`
SSE2 and SSE4.2 are not used in the code, but allow the compiler to use these extensions. It may increase the performance.
`-Ofast` and `-march=native` are standard optimisations, `-flto`, `-fwhole-program` and `-funroll-loops` are optimisations which can create minor improvements in this particular case.
`-Wall` is used to ensure there are no major issues, a compiler can detect.
