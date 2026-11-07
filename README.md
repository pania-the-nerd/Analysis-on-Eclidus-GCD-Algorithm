# GCD Algorithms — Implementation and Analysis

## Overview

This project explores three different approaches to finding the **Greatest Common Divisor (GCD)** of two integers using C++.

It includes the source-code implementations as well as a mathematical analysis of the algorithms, with a focus on their time complexity and the reasoning behind their behavior.

## Algorithms

### 1. Brute Force — `the-hard-way.cpp`

This approach finds all divisors of each input number, stores them in two vectors, and compares the vectors to determine the greatest common divisor.

**Main idea:**
1. Find and store every divisor of the first number.
2. Find and store every divisor of the second number.
3. Compare the two lists and keep the largest common divisor.

**Time complexity:** \(O(a+b+ab)\), which is \(O(ab)\) for positive inputs, due to the nested comparison loops.

**Space complexity:** \(O(a+b)\), for storing the divisors.

### 2. Subtraction Algorithm — `subtractionGCD.cpp`

This method repeatedly subtracts the smaller number from the larger one until both values become equal.

The key property is:

\[
\gcd(a,b)=
\begin{cases}
\gcd(a-b,b), & a>b\\
\gcd(a,b-a), & b>a
\end{cases}
\]

The algorithm stops when \(a=b\); that value is the GCD.

**Time complexity:** \(\Theta(N)\) in the worst case, where \(N\) is the larger input value. For example, inputs \(N\) and \(1\) require \(N-1\) iterations.

### 3. Euclidean Algorithm — `Division.cpp`

This implementation uses the remainder (modulo) operation to reduce the problem:

\[
\gcd(a,b)=\gcd(b,a\bmod b)
\]

The process continues until the remainder becomes zero. At that point, the other value is the GCD.

**Time complexity:** \(O(\log a)\) for \(a \ge b > 0\). The number of iterations is logarithmic; consecutive Fibonacci numbers give a worst-case sequence of inputs for this algorithm.

## Complexity Comparison

| Algorithm | Time Complexity | Auxiliary Space |
|---|---:|---:|
| Brute Force | \(O(ab)\) | \(O(a+b)\) |
| Subtraction | \(\Theta(N)\) worst case | \(O(1)\) |
| Euclidean (Modulo) | \(O(\log a)\) | \(O(1)\) |

Here, \(a\) and \(b\) are positive integer inputs, and \(N\) denotes the larger input in the subtraction analysis.

## Repository Structure

```text
.
├── Division.cpp
├── subtractionGCD.cpp
├── the-hard-way.cpp
├── analysis.pdf
└── README.md
```

- `Division.cpp` — Euclidean algorithm using modulo.
- `subtractionGCD.cpp` — GCD using repeated subtraction.
- `the-hard-way.cpp` — Brute-force divisor enumeration and comparison.
- `analysis.pdf` — Mathematical explanation and time-complexity analysis.

## How to Compile and Run

Compile any implementation with a C++ compiler:

```bash
g++ -std=c++17 Division.cpp -o gcd_division
```

Run it:

```bash
./gcd_division
```

For the other implementations, replace `Division.cpp` with the desired source filename and choose a corresponding output name.

The program reads two integers from standard input. For example:

```text
48 18
```

Expected output:

```text
the gcd is: 6
```

## Notes

- The implementations are intended for positive integer inputs.
- The subtraction implementation is much slower than the modulo-based Euclidean algorithm for some inputs.
- The PDF contains the detailed mathematical reasoning, including the linear worst case for subtraction and the Fibonacci recurrence associated with the Euclidean algorithm.

## Author

Created as an algorithm implementation and analysis project.
