# DSA Revision: Day 3 - Binary Search Algorithms

This directory contains C++ source code implementations, compiled binaries, and verified test cases for classical Binary Search algorithms and their variants.

---

## 1. Directory Structure

| Program Name | Source File | Executable Binary | Description |
| :--- | :--- | :--- | :--- |
| Standard Binary Search | [BinarySearch.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/BinarySearch.cpp) | [BinarySearch](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/BinarySearch) | Locates a target value in a sorted vector. |
| First & Last Occurrence | [FirstAndLast.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/FirstAndLast.cpp) | [FirstAndLast](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/FirstAndLast) | Finds the start and end indices of a target value. |
| Minimum in Rotated Sorted Array | [MinimumInRSA.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/MinimumInRSA.cpp) | [MinimumInRSA](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/MinimumInRSA) | Finds the minimum element in a rotated sorted array. |
| Search in Rotated Sorted Array | [RotatedSorted.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/RotatedSorted.cpp) | [RotatedSorted](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/RotatedSorted) | Searches for a target element in a rotated sorted array. |

---

## 2. Technical Code Corrections

During test execution, critical logical bugs were identified and corrected in two of the source files to ensure correct algorithmic behavior:

### BinarySearch.cpp
* **Bug Details:** The pointer update logic in the binary search implementation was configured for a descending-sorted array (setting `l = mid + 1` when `arr[mid] > target` and `h = mid - 1` when `arr[mid] < target`). However, the input array is sorted in ascending order via `std::sort` in the main routine. This mismatch caused searches to fail on valid elements.
* **Correction:** Adjusted the branch updates to conform to standard ascending order logic:
  ```cpp
  if (arr[mid] > target) {
      h = mid - 1;
  } else {
      l = mid + 1;
  }
  ```

### RotatedSorted.cpp
* **Bug Details:** The search did not perform a direct equality check (`arr[mid] == target`) at the start of each iteration. Instead, it eagerly saved the index (`ans = mid`) within the partition check boundaries even if the value at that index did not match the target. This resulted in false positive index returns for targets absent from the array.
* **Correction:** Refactored the core search block to immediately return `mid` if the target is found, and accurately narrowed search boundaries on subsequent comparisons:
  ```cpp
  if (arr[mid] == target) return mid;
  ```

---

## 3. Verified Test Cases

The following test suites were executed on the compiled binaries to confirm correctness:

### Standard Binary Search
* **Source Reference:** [BinarySearch.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/BinarySearch.cpp)

#### Test Case 1.1: Target Element Present
* **Input:**
  ```text
  5
  3 1 4 2 5
  2
  ```
* **Expected Output:**
  ```text
  1
  ```
  *(Note: Array is sorted internally to `[1, 2, 3, 4, 5]`, element `2` resides at index `1`)*

#### Test Case 1.2: Target Element Absent
* **Input:**
  ```text
  5
  3 1 4 2 5
  6
  ```
* **Expected Output:**
  ```text
  Error 404! Element not found
  ```

---

### First & Last Occurrence
* **Source Reference:** [FirstAndLast.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/FirstAndLast.cpp)

#### Test Case 2.1: Target Appears Multiple Times
* **Input:**
  ```text
  5
  1 2 2 2 3
  2
  ```
* **Expected Output:**
  ```text
  [1,3]
  ```

#### Test Case 2.2: Target Element Absent
* **Input:**
  ```text
  5
  1 2 2 2 3
  4
  ```
* **Expected Output:**
  ```text
  [-1,-1]
  ```

---

### Minimum in Rotated Sorted Array
* **Source Reference:** [MinimumInRSA.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/MinimumInRSA.cpp)

#### Test Case 3.1: Pivot in Middle Sector
* **Input:**
  ```text
  7
  4 5 6 7 0 1 2
  ```
* **Expected Output:**
  ```text
  0
  ```

#### Test Case 3.2: Pivot in Terminal Sector
* **Input:**
  ```text
  5
  3 4 5 1 2
  ```
* **Expected Output:**
  ```text
  1
  ```

#### Test Case 3.3: Ascending Sorted (0-degree Rotation)
* **Input:**
  ```text
  5
  1 2 3 4 5
  ```
* **Expected Output:**
  ```text
  1
  ```

---

### Search in Rotated Sorted Array
* **Source Reference:** [RotatedSorted.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_3/RotatedSorted.cpp)

#### Test Case 4.1: Target Element Absent
* **Input:**
  ```text
  6
  4 6 7 0 1 2
  5
  ```
* **Expected Output:**
  ```text
  Error 404! Element not found
  ```

#### Test Case 4.2: Target Located in Left Subarray
* **Input:**
  ```text
  7
  4 5 6 7 0 1 2
  5
  ```
* **Expected Output:**
  ```text
  1
  ```

#### Test Case 4.3: Target Located in Right Subarray
* **Input:**
  ```text
  7
  4 5 6 7 0 1 2
  2
  ```
* **Expected Output:**
  ```text
  6
  ```

---

## 4. Compilation and Execution Instructions

To compile and run any of these files manually using a C++ compiler:

```bash
# Compilation Syntax
g++ -O3 -std=c++17 <filename>.cpp -o <filename>

# Execution Syntax
./<filename>
```
