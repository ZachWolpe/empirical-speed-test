# Empirical Runtime Analysis

Empirical analysis of speed of various programming languages.

## Languages

- `C++`
- `Python`

`Rust` & `Golang` are coming soon.

## Build


Each implementation runs $n$ operations of a combination of $k$ [data structure & algorithm implementations](https://github.com/ZachWolpe/Data-Structures-and-Algorithms), all wrapped in a CPU profiler. The results are writen to a `.prof` file that is then profiled externally ([Using my `psuedo-profiler` tool](https://github.com/ZachWolpe/Pseudo-Profiler) for assistance).

The algorithms select are common data structures & algorithms that widely used in practice and have well understood theoretical time and space complexity, serving as great benchmarks.

`Machine:: Macbook M1 Pro, 16GB RAM, 10 cores, 2021`

## Empirical Results

*_Runtime Performance:_*

Note how the Python runtime explodes in the number of iterations. This is due to the fact that Python is an interpreted language, and the interpreter is running the same code over and over again. The C++ code is compiled to machine code, and thus runs much faster & is optimized to reduced superfluous calculations.

![cpyrt](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/empirical-performance.png "C++ vs Python Empirical Runtime Performance")



Python Profiles:


![10-ops](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/prof-10.png "Python Profiler: 10 operation.")

![100-ops](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/prof-10.png "Python Profiler: 100 operation.")

![1000-ops](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/prof-10.png "Python Profiler: 1000 operation.")

![10000-ops](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/prof-10.png "Python Profiler: 10000 operation.")

![100000-ops](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/prof-10.png "Python Profiler: 100000 operation.")


C++ Profile(s):

![cpp-profiler](https://github.com/ZachWolpe/empirical-speed-test/blob/main/assets/cpp-profile.png "C++ Full Runtime Profiler: i:{10,100,1000,10000,100000}")


---
```
 : Zach Wolpe
 : zach.wolpe@medibio.com.au
```
---
