# DAY 1: Kadane's Algorithm & Variations

This directory contains implementations of Kadane's Algorithm for finding the maximum subarray sum, including variations for tracking indices and handling circular arrays.

## 1. Kadane's Algorithm (Standard)
**File:** `Kadanes.cpp`

### Description
The standard Kadane's algorithm finds the maximum possible sum of a contiguous subarray within a one-dimensional array of numbers.

### Logic
- Maintains a `sum` of the current subarray.
- Updates `maxSum` whenever `sum` exceeds it.
- If `sum` becomes negative, it resets to `0` because any subarray starting with a negative sum will only decrease the potential maximum.

### Complexity
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$

---

## 2. Kadane's Algorithm with Indices
**File:** `KadanesII.cpp`

### Description
An extension of the standard algorithm that not only finds the maximum sum but also identifies the **start** and **end** indices of that subarray.

### Logic
- Uses a `temp` pointer to track the potential start of a new subarray whenever `sum` resets to 0.
- Updates `start` and `end` variables whenever a new `maxSum` is found.

### Complexity
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$ (ignoring the output vector)

---

## 3. Maximum Circular Subarray Sum
**File:** `Kadanes_circular.cpp`

### Description
Finds the maximum subarray sum in a circular array. The maximum sum can either be a normal contiguous subarray or "wrap around" the end of the array.

### Logic
1. **Case 1 (Non-circular):** Use standard Kadane's to find the max subarray sum.
2. **Case 2 (Circular):** The maximum circular sum is found by subtracting the minimum subarray sum from the total array sum.
   - `Wrapped Sum = Total Sum - Minimum Subarray Sum`
3. **Edge Case:** If all elements are negative, the result is the same as the standard Kadane's max.
4. **Result:** `max(Non-circular Max, Wrapped Sum)`

### Complexity
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$

---

## Compilation & Execution
To compile and run any of these files, use a C++ compiler like `g++`:

```bash
# Example for standard Kadane's
g++ Kadanes.cpp -o Kadanes
./Kadanes
```
