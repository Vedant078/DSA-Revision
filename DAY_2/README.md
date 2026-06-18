# DAY 2: Dutch National Flag (DNF) Algorithm variations

This directory contains three different variations of the **Dutch National Flag (DNF) algorithm** implemented in C++.

## Files

### 1. [DNF_1.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_2/DNF_1.cpp)
* **Goal:** Classic 3-way partitioning to sort an array containing `0`s, `1`s, and `2`s in-place with a single pass ($O(N)$ time complexity and $O(1)$ space complexity).
* **Core Logic:** Uses three pointers (`l` for low, `h` for high, and `mid` for current traversal).

### 2. [DNF_II.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_2/DNF_II.cpp)
* **Goal:** Sorts an array of `0`s, `1`s, and `2`s and counts the **minimum number of swaps** required to sort the array.
* **Core Logic:** Extends the classic DNF algorithm by incrementing a `swap_count` whenever a valid element swap occurs (skipping redundant swaps where indices are the same).

### 3. [DNF_III.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_2/DNF_III.cpp)
* **Goal:** 4-way classification algorithm that sorts an array containing four values: `0`s, `1`s, `2`s, and `3`s.
* **Core Logic:** Implements three binary-partitioning passes:
  1. **Pass 1:** Groups elements $\le 1$ on the left and $> 1$ on the right.
  2. **Pass 2:** Partitions the left section into `0`s and `1`s.
  3. **Pass 3:** Partitions the right section into `2`s and `3`s.

---

## Compilation and Usage

You can compile any of the files using `g++`:

```bash
# Compile
g++ DNF_1.cpp -o DNF_1
g++ DNF_II.cpp -o DNF_II
g++ DNF_III.cpp -o DNF_III

# Run
./DNF_1
```

### Input Format
Each program expects the input size $N$ followed by the $N$ space-separated array elements.

For example, to test [DNF_III.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_2/DNF_III.cpp):
```bash
echo "8\n0 1 3 3 2 1 2 0" | ./DNF_III
# Output: 0 0 1 1 2 2 3 3 
```
