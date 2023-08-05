# Empirical Runtime Analysis

In converting code from Python to C++, we rely on theoretical assumptions. Here we test those assumptions empirically.

Empirical analysis of speed of various programming languages.

## Languages

- `C++`
- `Python`

## Build


Each implementation runs $n$ operations of a combination of $k$ algorithms & data structure manipulations, all wrapped in a CPU profiler. The results are writen to a `.prof` file that is then profiled externally (see my `psuedo-profiler` tool for assistance).

The algorithms select are common data structures & algorithms that widely used in practice and have well understood theoretical time and space complexity, serving as great benchmarks.



---
```
 : Zach Wolpe
 : zach.wolpe@medibio.com.au
```
---
