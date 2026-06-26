# DAY 5: String Algorithms

This directory contains implementations of fundamental string manipulation algorithms, including palindrome validation, anagram detection, anagram grouping, and finding the longest palindromic substring.

## 1. Valid Palindrome
**File:** [validPalindrome.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_5/validPalindrome.cpp)

### Description
Checks if a string is a palindrome, considering only alphanumeric characters and ignoring cases.

### Logic & Important Notes
- **Pre-processing:** The input string is first cleaned by iterating through it and copying only alphanumeric characters. During this, uppercase characters are converted to lowercase by adding 32 to their ASCII value.
- **Verification:** A two-pointer approach (`l` starting at `0` and `h` starting at `temp.length() - 1`) is used to compare characters from both ends moving inward. If all matching characters are identical, the string is a palindrome.
- **Improvement Note:** The current implementation uses an auxiliary string `temp` which takes $O(N)$ extra space. This can be optimized to $O(1)$ auxiliary space by skipping non-alphanumeric characters on the fly using pointers directly on the original string.

### Complexity
- **Time Complexity:** $O(N)$ where $N$ is the length of the string.
- **Space Complexity:** $O(N)$ due to storing the filtered string `temp`.

### Test Cases
- **Input:** `"A man, a plan, a canal: Panama"`
  - **Cleaned:** `"amanaplanacanalpanama"`
  - **Output:** `1` (True)
- **Input:** `"race a car"`
  - **Cleaned:** `"raceacar"`
  - **Output:** `0` (False)
- **Input:** `" "` (empty / only spaces)
  - **Cleaned:** `""`
  - **Output:** `1` (True)

---

## 2. Valid Anagram
**File:** [anagram.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_5/anagram.cpp)

### Description
Determines if two strings are anagrams of each other (contain the exact same character frequencies).

### Logic & Important Notes
- **Length Check:** If the lengths of the two strings differ, they cannot be anagrams, returning `false` immediately.
- **Frequency Counter:** A single array of size 26 is used to track character frequencies. Characters in `s1` increment the corresponding count, while characters in `s2` decrement the count.
- **Validation:** The frequency array is checked to verify if all counts are 0.
- **Important Implementation Notes:** 
  1. The code initializes the array with `for(int i=0;i<25;i++)arr[i]=0;`, which misses the index 25 (character 'z'). It should initialize up to 26.
  2. The validation checks `if(arr[i]==1) return false;` instead of checking if any count is non-zero (i.e., `arr[i] != 0`), which may fail if counts are negative or greater than 1.

### Complexity
- **Time Complexity:** $O(N)$ where $N$ is the length of the strings.
- **Space Complexity:** $O(1)$ as the frequency array is of fixed size (26).

### Test Cases
- **Input:** `s1 = "anagram"`, `s2 = "nagaram"`
  - **Output:** `1` (True)
- **Input:** `s1 = "rat"`, `s2 = "car"`
  - **Output:** `0` (False)

---

## 3. Group Anagrams
**File:** [groupAnagrams.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_5/groupAnagrams.cpp)

### Description
Groups an array of strings such that all anagrams are placed in the same group.

### Logic & Important Notes
- **Categorization by Sorting:** For each string in the input vector, a copy is made and sorted. The sorted string is used as a unique key for the anagram group.
- **Hash Map Storage:** An `unordered_map<string, vector<string>>` maps the sorted key to its original unsorted strings.
- **Result Construction:** All the grouped vectors from the hash map are pushed into the final 2D result vector.

### Complexity
- **Time Complexity:** $O(N \cdot K \log K)$ where $N$ is the number of strings and $K$ is the maximum length of a string, due to sorting each string.
- **Space Complexity:** $O(N \cdot K)$ to store the grouped strings in the hash map.

### Test Cases
- **Input:** `{"eat", "tea", "tan", "ate", "nat", "bat"}`
  - **Output:**
    ```text
    Group 1: [ bat ]
    Group 2: [ tan, nat ]
    Group 3: [ eat, tea, ate ]
    ```
- **Input:** `{"a"}`
  - **Output:**
    ```text
    Group 1: [ a ]
    ```

---

## 4. Longest Palindromic Substring
**File:** [longestPalindromicSubstring.cpp](file:///Users/vedant/Desktop/DSA_Revise/DAY_5/longestPalindromicSubstring.cpp)

### Description
Finds the longest contiguous substring that is a palindrome.

### Logic & Important Notes
- **Expand Around Center:** Palindromes are symmetric. For each index in the string, we expand outwards as long as the characters match:
  - **Odd length palindromes:** The center is a single character (starting with `l = i`, `r = i`).
  - **Even length palindromes:** The center is the gap between two characters (starting with `l = i`, `r = i + 1`).
- **Tracking Maximum:** During expansion, if the current palindrome length (`r - l + 1`) is greater than the previous maximum `resLen`, `resIdx` and `resLen` are updated.
- **Substring Extraction:** The function returns `s.substr(resIdx, resLen)`.

### Complexity
- **Time Complexity:** $O(N^2)$ where $N$ is the length of the string, since there are $2N - 1$ centers and expansion takes $O(N)$ time per center.
- **Space Complexity:** $O(1)$ auxiliary space as we only store pointers and indices.

### Test Cases
- **Input:** `"babad"`
  - **Output:** `"bab"` (or `"aba"`)
- **Input:** `"cbbd"`
  - **Output:** `"bb"`
- **Input:** `"abbc"`
  - **Output:** `"bb"`

---

## Compilation & Execution
To compile and execute any of these C++ files, run the following commands in the terminal:

```bash
# Example to run validPalindrome
g++ validPalindrome.cpp -o validPalindrome
./validPalindrome
```
