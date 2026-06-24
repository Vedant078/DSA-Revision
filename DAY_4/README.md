# DSA Revision: Day 4 - Bit Manipulation Algorithms

This directory contains C++ source code implementations, compiled binaries, and verified test cases for fundamental Bit Manipulation algorithms and bitwise arithmetic problems.

---

## 1. Directory Structure

| Program Name | Source File | Executable Binary | Description |
| :--- | :--- | :--- | :--- |
| Count Set Bits | [CountSetBits.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/CountSetBits.cpp) | [CountSetBits](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/CountSetBits) | Counts the number of set bits ($1$s) in an integer using brute force and optimized approaches. |
| Power of Two | [powerofTwo.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/powerofTwo.cpp) | [powerofTwo](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/powerofTwo) | Checks if a given integer is a power of 2 using a bitwise check. |
| Single Number I | [singleNumber.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumber.cpp) | [singleNumber](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumber) | Finds the unique element in an array where every other element appears twice. |
| Single Number II | [singleNumberII.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumberII.cpp) | [singleNumberII](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumberII) | Finds the unique element in an array where every other element appears three times. |

---

## 2. Core Concepts & Key Bitwise Algorithms

Bit manipulation utilizes bitwise operators directly on the binary representation of integers, yielding highly optimized, $O(1)$ space, and extremely fast runtimes.

### A. Counting Set Bits & Brian Kernighan's Algorithm
* **Source Reference:** [CountSetBits.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/CountSetBits.cpp)
* **Brute Force Approach ([CountBrute](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/CountSetBits.cpp#L4)):** Loops through all bits of the number by shifting it right one bit at a time (`n >> 1`) and checking if the lowest bit is $1$ (`n & 1`).
  * **Time Complexity:** $O(\log n)$ (dependent on the position of the highest set bit).
* **Brian Kernighan's Algorithm ([CountOptimised](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/CountSetBits.cpp#L15)):** Subtracting $1$ from a number flips all the bits to the right of the rightmost set bit (including the set bit itself). Performing a bitwise AND between `n` and `n - 1` clears the lowest set bit.
  * **Formula:** `n = n & (n - 1)`
  * **Time Complexity:** $O(k)$ where $k$ is the number of set bits (highly efficient for sparse bit arrays).

### B. Power of Two Verification
* **Source Reference:** [powerofTwo.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/powerofTwo.cpp)
* **Mathematical Property ([isPowerOf2](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/powerofTwo.cpp#L3)):** A positive integer is a power of 2 if and only if it has exactly one set bit in its binary representation (e.g., $8 = 1000_2$). 
* **Optimized Check:** If $x$ is a power of two, $x - 1$ will have all bits to the right of the original set bit flipped to $1$ (e.g., $7 = 0111_2$). Consequently:
  * `(x & (x - 1)) == 0` evaluates to true.
  * We handle $x = 0$ as a special case returning `false`.
  * **Time Complexity:** $O(1)$

### C. Single Number I (XOR Cancellation)
* **Source Reference:** [singleNumber.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumber.cpp)
* **Logic ([singleInt](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumber.cpp#L4)):** Given an array where every element appears twice except one, we can exploit the algebraic properties of the bitwise XOR ($\oplus$) operator:
  1. $A \oplus A = 0$ (Self-inverse)
  2. $A \oplus 0 = A$ (Identity element)
  3. Commutativity & Associativity (Ordering of XOR operations does not matter)
* **Application:** By XOR-ing all elements in the array, all duplicate pairs cancel out to $0$, leaving the single unique number.
  * **Time Complexity:** $O(N)$
  * **Space Complexity:** $O(1)$

### D. Single Number II (Bit Sum Modulo 3)
* **Source Reference:** [singleNumberII.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumberII.cpp)
* **Logic ([Solution::singleNumber](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumberII.cpp#L6)):** Given an array where every element appears three times except one, simple XOR does not work. Instead, we can examine the bit-frequency at each bit position (from 0 to 30 for 32-bit integers):
  1. For each bit position, count how many numbers in the array have that bit set.
  2. Since duplicate elements appear three times, they contribute a count of $3$ (or a multiple of $3$) to the bit sum at any position where they have a set bit.
  3. If the sum of set bits at a position is not a multiple of 3 (specifically, $cnt \pmod 3 == 1$), it implies the single number must have a set bit at that position.
  4. We reconstruct the target unique integer by setting the corresponding bits.
  * **Time Complexity:** $O(32 \cdot N) = O(N)$
  * **Space Complexity:** $O(1)$

---

## 3. Verified Test Cases

### Count Set Bits
* **Source Reference:** [CountSetBits.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/CountSetBits.cpp)

#### Test Case 1.1: Standard Test Run
* **Input:**
  ```text
  2
  7
  16
  ```
* **Expected Output:**
  ```text
  Enter number (decimal) :3
  Enter number (decimal) :1
  ```
  *(Explanation: $7 = 0111_2 \implies 3$ set bits; $16 = 10000_2 \implies 1$ set bit)*

---

### Power of Two Check
* **Source Reference:** [powerofTwo.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/powerofTwo.cpp)

#### Test Case 2.1: Positive Power of Two
* **Input:**
  ```text
  64
  ```
* **Expected Output:**
  ```text
  Enter the value of (n):1
  ```

#### Test Case 2.2: Non Power of Two
* **Input:**
  ```text
  14
  ```
* **Expected Output:**
  ```text
  Enter the value of (n):0
  ```

#### Test Case 2.3: Zero Case
* **Input:**
  ```text
  0
  ```
* **Expected Output:**
  ```text
  Enter the value of (n):0
  ```

---

### Single Number I
* **Source Reference:** [singleNumber.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumber.cpp)

#### Test Case 3.1: Standard Case
* **Input:**
  ```text
  1
  5
  4 1 2 1 2
  ```
* **Expected Output:**
  ```text
  Enter size of array: Number Appearing for only one time :4
  ```

#### Test Case 3.2: Multi-digit Numbers
* **Input:**
  ```text
  1
  7
  10 25 10 99 99 25 7
  ```
* **Expected Output:**
  ```text
  Enter size of array: Number Appearing for only one time :7
  ```

---

### Single Number II
* **Source Reference:** [singleNumberII.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_4/singleNumberII.cpp)

#### Test Case 4.1: Hardcoded Vector Execution
* **Configured Vector in Main:**
  ```cpp
  vector<int> arr = {2, 2, 2, 3, 3, 4};
  ```
* **Expected Output:**
  ```text
  4
  ```
  *(Explanation: 2 appears 3 times. 3 appears 2 times. 4 appears 1 time. The bit sum modulo 3 detects that bit 2 is set ($1 \pmod 3 = 1$), resulting in $4$)*

---

## 4. Compilation and Execution Instructions

To compile and run any of these files manually using a C++ compiler:

```bash
# Compilation Syntax
g++ -O3 -std=c++17 <filename>.cpp -o <filename>

# Execution Syntax
./<filename>
```
