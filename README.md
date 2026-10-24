# 📦 Simple Algorithms in C
 
 
Welcome to the repository containing basic mathematical algorithms written in C.
 
The project will expand over time.
 
---
 
## 📁 Repository Structure
 
```
simplest-algorithms/
├── sorting/
│   ├── BubbleSort.c
│   ├── SelectionSort.c
│   ├── InsertionSort.c
│   ├── MergeSort.c
│   └── QuickSort.c
├── searching/
│   ├── BinSearch.c
│   └── find_pair_sum.c
├── graphs/
│   └── BFS.c
├── number-theory/
│   ├── Sieve-of-Eratosthenes.c
│   ├── prime_factorization.c
│   ├── pif3.c
│   └── bin_power.c
├── matrices/
│   ├── matrixfib.c
│   └── matrixuppertriangular.c
├── strings/
│   ├── RLE.c
│   └── deRLE.c
└── encryption/
    ├── caesar_cipher.c
    └── vigenere_cipher.c
```
 
---
 
## 📊 Implemented Algorithms Overview
 
 
### 🔢 Sorting
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **1** | [`sorting/BubbleSort.c`](sorting/BubbleSort.c) | Bubble Sort algorithm with an early-exit flag |
| **2** | [`sorting/SelectionSort.c`](sorting/SelectionSort.c) | Selection Sort algorithm |
| **3** | [`sorting/InsertionSort.c`](sorting/InsertionSort.c) | Insertion Sort algorithm |
| **4** | [`sorting/MergeSort.c`](sorting/MergeSort.c) | Merge Sort algorithm using a divide-and-conquer strategy |
| **5** | [`sorting/QuickSort.c`](sorting/QuickSort.c) | Quick Sort algorithm |
 
### 🔍 Searching
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **6** | [`searching/BinSearch.c`](searching/BinSearch.c) | Recursive and Iterative Binary Search algorithms |
| **7** | [`searching/find_pair_sum.c`](searching/find_pair_sum.c) | Two-Sum problem solver using Merge Sort and a Two-Pointer technique |
 
### 🕸️ Graphs
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **8** | [`graphs/BFS.c`](graphs/BFS.c) | Breadth-First Search (BFS) algorithm on a graph using static arrays |
 
### 🧮 Number Theory
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **9** | [`number-theory/Sieve-of-Eratosthenes.c`](number-theory/Sieve-of-Eratosthenes.c) | Finding all prime numbers up to a specified limit $n$ |
| **10** | [`number-theory/prime_factorization.c`](number-theory/prime_factorization.c) | Prime factorization of an integer |
| **11** | [`number-theory/pif3.c`](number-theory/pif3.c) | Ternary tree generation of primitive Pythagorean triples |
| **12** | [`number-theory/bin_power.c`](number-theory/bin_power.c) | Binary exponentiation: computing $a^n$ in $O(\log n)$ multiplications |
 
### 📐 Matrices
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **13** | [`matrices/matrixfib.c`](matrices/matrixfib.c) | Fast Fibonacci number computation using matrix exponentiation |
| **14** | [`matrices/matrixuppertriangular.c`](matrices/matrixuppertriangular.c) | Gaussian elimination method for matrix triangularization |
 
### 🔤 Strings
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **15** | [`strings/RLE.c`](strings/RLE.c) | Run-Length Encoding (RLE) for text compression |
| **16** | [`strings/deRLE.c`](strings/deRLE.c) | RLE decoder: restoring the original string from its encoded form |
 
### 🔐 Encryption
 
| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **17** | [`encryption/caesar_cipher.c`](encryption/caesar_cipher.c) | Caesar cipher: shifting Latin letters by a fixed amount |
| **18** | [`encryption/vigenere_cipher.c`](encryption/vigenere_cipher.c) | Vigenère cipher: Caesar shifts driven by a repeating keyword |
 
---
 
## 🧬 Detailed Module Descriptions
 
 
## 🔢 Sorting
 
### 1. Bubble Sort ([`sorting/BubbleSort.c`](sorting/BubbleSort.c))
 
*   **How it works:** 
    1. The program reads an integer $n$, followed by $n$ elements to populate a Variable-Length Array `arr[n]`.
    2. It prints the original array, executes the sorting routine, and then outputs the final sorted array.
    3. The `BubbleSort` function uses nested loops to compare adjacent elements and swap them if they are in the wrong order (`a[i] > a[i + 1]`).
*   **Optimization:** A `flag` variable tracks whether any swaps occurred during an inner loop pass. If a full pass completes with `flag == 1`, the array is already fully sorted, and the algorithm triggers an early `break` to save redundant operations.
*   **Complexity:** 
    *   **Worst-case / Average-case Time:** $O(n^2)$ when the array is reversed or unsorted.
    *   **Best-case Time:** $O(n)$ when the input array is already sorted (thanks to the optimization flag).
### 2. Selection Sort ([`sorting/SelectionSort.c`](sorting/SelectionSort.c))
An implementation of the **Selection Sort** algorithm.
 
*   **How it works:** 
    1. The program safely reads an integer $n$. If the input is invalid or $n \le 0$, it terminates early to prevent undefined behavior.
    2. A Variable-Length Array (VLA) `a[n]` is populated with integers, backed by `scanf` success checks.
    3. The `SelectionSort` function divides the array into a sorted and an unsorted region.
    4. In each pass, it scans the unsorted part to find the minimum element. If the minimum element is not already at the starting position (`min != i`), it swaps it into its correct place.
### 3. Insertion Sort ([`sorting/InsertionSort.c`](sorting/InsertionSort.c))
An implementation of the **Insertion Sort** algorithm, which builds the final sorted array one item at a time.
 
*   **How it works:** 
    1. The program  reads the array size $n$ and its elements.
    2. The `InsertionSort` function iterates through the array from left to right.
    3. For each element (`nonsorted`), it scans backwards through the sorted sub-array to find its correct position.
    4. Elements greater than the current key are shifted one position to the right to clear space, and the key is placed in its valid sorted slot.
### 4. Merge Sort ([`sorting/MergeSort.c`](sorting/MergeSort.c))
An implementation of the **Merge Sort** algorithm, which uses the divide-and-conquer paradigm to sort an array efficiently.
 
*   **How it works:** 
    1. The program  reads the array size $n$ and its elements.
    2. The `MergeSort` function recursively splits the array into two halves until sub-arrays of size 1 or 0 are reached.
    3. The `merge` function then combines the sorted sub-arrays back together into a single sorted unit using a temporary buffer.
### 5. Quick Sort ([`sorting/QuickSort.c`](sorting/QuickSort.c))
An implementation of the **Quick Sort** algorithm: the array is partitioned around a pivot element, and both parts are sorted independently.
 
*   **How it works:** 
    1. The program reads the array size $n$ and its elements.
    2. **Pivot choice:** the `partition` function takes the middle element (`mid = low + (high - low) / 2`), moves it to the end of the sub-array and uses it as the `pivot`.
    3. **Lomuto partition:** the index `i` marks the border of the "smaller" zone. The index `j` scans the sub-array, and every element smaller than the pivot is swapped into that zone. Finally, the pivot is placed at position `i` — its final position in the sorted array.
    4. The `qs` function sorts the parts `[low, p - 1]` and `[p + 1, high]` the same way.
    5. `quick_sort(n, a)` is a wrapper that calls `qs(a, 0, n - 1)`.
## 🔍 Searching
 
### 6. Binary Search ([`searching/BinSearch.c`](searching/BinSearch.c))
An implementation of the **Binary Search** algorithm, showcasing both iterative and recursive approaches to search for a target element within a sorted array.
 
*   **How it works:** 
    1. The program read the sorted array size n, its elements, and the target number (`searchednum`).
    2. **Iterative Approach (`BinSearchLeftRight`):** Uses a `while` loop with moving `left` and `right` pointers to shrink the search space by half each iteration.
    3. **Recursive Approach (`BinSearchRecursion`):** Achieves the same divide-and-conquer logic through explicit self-invocation, passing updated boundaries down the call stack.
### 7. Two-Sum Pair Solver ([`searching/find_pair_sum.c`](searching/find_pair_sum.c))
An efficient solver for the **Two-Sum problem** using a combination of sorting and a two-pointer approach.
 
*   **How it works:** 
    1. **Data Structure:** Uses a custom `element` structure to store both the integer `value` and its original 0-based `index` so that position data is not lost during sorting.
    2. **Sorting Phase:** Applies the `MergeSort` routine to sort the elements by value in \(O(n \log n)\) time.
    3. **Two-Pointer Scan:** Places two pointers (`right` at the beginning and `left` at the end) of the sorted array. The pointers converge based on the current sum relative to the `target`, finding the matching pair in a single \(O(n)\) linear scan.
## 🕸️ Graphs
 
### 8. Breadth-First Search ([`graphs/BFS.c`](graphs/BFS.c))
An implementation of the **Breadth-First Search (BFS)** algorithm to traverse or search a graph level by level.
 
*   **How it works:** 
    1. The program utilizes custom `edge`, `vertex`, and `graph` structures, storing relations using static adjacency arrays embedded within each vertex structure.
    2. It reads the number of vertices V and edges from the standard input, constructing the directed graph sequentially.
    3. An array-based queue (`queue`) and a traversal flag tracker (`visited`) are initialized. The algorithm pushes the initial starting vertex into the queue and marks it as visited.
    4. While the queue is not empty, the current node is popped, printed, and all its unvisited direct neighbors are discovered, marked as visited, and appended to the queue.
*   **Input format:** 
```
    [Total Vertices] [Total Edges]
    [Source Vertex 1] [Destination Vertex 1]
    [Source Vertex 2] [Destination Vertex 2]
    ...
    [Starting Vertex for BFS]
```
 
*   **Example:**
    For a graph with 4 vertices (0, 1, 2, 3) and 4 directed edges (0→1, 0→2, 1→3, 2→3), starting the traversal from vertex 0:
```
    Input:
    4 4
    0 1
    0 2
    1 3
    2 3
    0
 
    Output:
    0 1 2 3 
```
 
 
## 🧮 Number Theory
 
### 9. Sieve of Eratosthenes ([`number-theory/Sieve-of-Eratosthenes.c`](number-theory/Sieve-of-Eratosthenes.c))
A classical, highly efficient algorithm to find all prime numbers up to a specified limit $n$.
 
*   **How it works:** 
    1. An array of flags of size $n$ is initialized, where all elements are initially set to `1` (true). Array index `i` logically maps to the target number $i + 2$.
    2. The algorithm iterates starting from the first prime ($2$). For each prime encountered, all its composite multiples (starting directly from its square $num^2$) are marked as `0` (false).
    3. The loop is mathematically optimized to terminate early as soon as $(i + 2)^2 > n$.
    4. Finally, all array elements remaining as `1` are printed as verified prime numbers alongside the total count.
### 10. Prime Factorization ([`number-theory/prime_factorization.c`](number-theory/prime_factorization.c))
Implementation to compute the **prime factorization of an integer**.
 
*   **How it works:** 
    1. The program isolates the smallest prime number (\(2\)) inside a `while` loop, extracting all even factors from the number completely.
    2. The algorithm then iterates through an optimized `for` loop executing only odd numbers from \(3\) up to \(\sqrt{num}\). If any odd number completely divides the remaining value, it is printed and divided recursively.
    3. **Mathematical Optimization:** If the remaining value of `num` after loop bounds is greater than \(1\), it is inherently a prime number itself and is printed as the final factor.
### 11. Tree of Pythagorean Triples Generator ([`number-theory/pif3.c`](number-theory/pif3.c))
Generates a ternary (three-branch) tree of **primitive Pythagorean triples** based on Berggren's linear algebraic transformations.
 
*   **How it works:** Any primitive Pythagorean triple (a set of three coprime integers where $a^2 + b^2 = c^2$) can be uniquely generated starting from the root node triple `(3, 4, 5)`. 
    A recursive Depth-First Search (DFS) function multiplies the parent triple vector by three specialized transformation matrices to discover three unique child triples per node:
    
    $$v_{\text{child}} = T_i \cdot v_{\text{parent}}$$
    
    The process continues recursively up to a maximum depth $n$.
*   **Output format:** The program prints comma-separated values mapping the parent node to its children (`parent;child`).
📐 Berggren Matrices for Pythagorean Triples
 
The following constant $3 \times 3$ matrices are utilized to generate child nodes inside `pif3.c`:
 
$$
A = \begin{pmatrix} 
1 & -2 & 2 \\ 
2 & -1 & 2 \\ 
2 & -2 & 3 
\end{pmatrix}, \quad
B = \begin{pmatrix} 
1 & 2 & 2 \\ 
2 & 1 & 2 \\ 
2 & 2 & 3 
\end{pmatrix}, \quad
C = \begin{pmatrix} 
-1 & 2 & 2 \\ 
-2 & 1 & 2 \\ 
-2 & 2 & 3 
\end{pmatrix}
$$
 
### 12. Binary Exponentiation ([`number-theory/bin_power.c`](number-theory/bin_power.c))
Computes $a^n$ using **binary exponentiation** (exponentiation by squaring), which needs only $O(\log n)$ multiplications instead of $n - 1$.
 
*   **How it works:** 
    1. The program reads the base `base` (`long long`) and the exponent `exp` (`int`). If the input is invalid or `exp < 0`, it terminates early.
    2. The `bin_power` function starts with `res = 1` and repeats while `exp > 0`:
        *   if `exp` is **even**, the base is squared and the exponent is halved, since $a^{2k} = (a^2)^k$;
        *   if `exp` is **odd**, the current base is multiplied into the result and the exponent is decreased by one, since $a^{2k+1} = a \cdot a^{2k}$.
    3. Throughout the loop the value $res \cdot base^{exp}$ stays equal to the original $a^n$, so when `exp` reaches `0`, `res` holds the answer.
*   **Note:** the base is squared only when the exponent is even and positive, so every squared value is actually used later — there is no extra squaring after the last step.
*   **Complexity:** $O(\log n)$ multiplications.
*   **Constraints:** The result must fit into a signed 64-bit `long long` (from $-2^{63}$ to $2^{63} - 1$). For example, $2^{62}$, $10^{18}$ and $3^{39}$ are computed correctly, while $2^{63}$ or $3^{40}$ cause signed overflow (undefined behavior in C).
*   **Example:**
```
    Input:
    2 10
 
    Output:
    1024
```
 
 
## 📐 Matrices
 
### 13. Matrix Fibonacci Solver ([`matrices/matrixfib.c`](matrices/matrixfib.c))
Calculates the $n$-th Fibonacci number using **matrix exponentiation**.
 
*   **How it works:** The relationship between adjacent Fibonacci numbers can be expressed as a clean matrix equation:
    
$$
\begin{pmatrix} 
F_{n+1} \\ 
F_{n} 
\end{pmatrix} = 
\begin{pmatrix} 
0 & 1 \\ 
1 & 1 
\end{pmatrix}^n 
\begin{pmatrix} 
F_1 \\ 
F_0 
\end{pmatrix}
$$
    
 
*   **Constraints:** Supports $0 \le n \le 91$ because the 92nd Fibonacci number exceeds the maximum safe limit of standard `long long` 64-bit signed integers in C.
### 14. Matrix Upper Triangularization ([`matrices/matrixuppertriangular.c`](matrices/matrixuppertriangular.c))
Transforms a square matrix into an **upper triangular matrix** using Gaussian elimination row operations.
 
*   **How it works:** 
    1. The program  reads the matrix size `len`. 
    2. A Variable-Length 2D Array `arr[len][len]` is populated with double-precision floating-point numbers from standard input.
    3. The `gauss_method` function iterates down through each pivot row. For every row below the active pivot, it calculates a structural multiplier factor k.
    
    4. The algorithm then subtracts from the current lower row to zero out the elements below the main diagonal, building an upper triangular shape.
    5. The final matrix is printed out with values rounded to two decimal places.
## 🔤 Strings
 
### 15. Run-Length Encoding ([`strings/RLE.c`](strings/RLE.c))
 
Compresses a string by replacing consecutive sequences of identical characters with the character followed by the number of repetitions.
 
*   **How it works:** The algorithm scans the input string from left to right. When a sequence of identical characters ends, the character and its repetition count are written to the result string.
*   **Example:**
```
    Input:  AAABBCCCZ
    Output: A3B2C3Z1
```
 
*   **Output format:** Each group is represented as:
```
    character + number of repetitions
```
 
*   **Complexity:** The algorithm processes each input character once, so its time complexity is $O(n)$, where $n$ is the input length.
*   **Memory usage:** The result buffer requires additional memory for the encoded string. In the worst case, its size is approximately `2n + 1`.
### 16. RLE Decoder ([`strings/deRLE.c`](strings/deRLE.c))
The inverse operation to [`RLE.c`](strings/RLE.c): restores the original string from its **Run-Length Encoded** form.
 
*   **How it works:** 
    1. **First pass (`len_RLE`):** the encoded string is scanned group by group — one character followed by its repetition count. The counts are summed to get the exact length of the decoded string.
    2. Memory for the result is allocated dynamically with `malloc(len + 1)` (one extra byte for `'\0'`). Unlike a Variable-Length Array on the stack, this works safely even for very long outputs such as `A1000000`.
    3. **Second pass (`deRLE`):** for every group, the character is saved, its count is read, and the character is written into the result `count` times.
    4. **Multi-digit counts:** the number is built digit by digit with `count = count * 10 + (digit - '0')`, so `B10` is decoded as ten `B`s, not as `B1` + `0`.
*   **Example:**
```
    Input:  A3B10S3
    Output: AAABBBBBBBBBBSSS
```
*   **Complexity:** $O(n + m)$, where $n$ is the length of the encoded string and $m$ is the length of the decoded one.
*   **Constraints:** The original text must not contain digits, since in this format a digit cannot be told apart from a repetition count (`A31` is ambiguous). A character without a count is treated as repeated $0$ times.
## 🔐 Encryption
 
### 17. Caesar Cipher ([`encryption/caesar_cipher.c`](encryption/caesar_cipher.c))
An implementation of the **Caesar cipher** — a classic substitution cipher in which every letter is replaced by the letter a fixed number of positions further down the alphabet.
 
*   **How it works:** 
    1. The program reads an integer `shift` from standard input and encrypts the built-in string `"The Quick Brown Fox Jumps Over The Lazy Dog"` (a pangram, so every letter of the alphabet is shifted).
    2. **Shift normalization:** `shift %= 26` reduces the shift to the range $(-26, 26)$, and a negative result is moved into $[0, 25]$ by adding $26$. Any `int` value is accepted, including negative ones, without risk of overflow.
    3. For each character, the `caesar_cipher` function checks whether it is an uppercase or a lowercase Latin letter and applies
    $$c' = \text{base} + (c - \text{base} + \text{shift}) \bmod 26$$
    where `base` is `'A'` or `'a'`. Letter case is preserved; spaces, digits and punctuation stay unchanged.
*   **Decryption:** encrypting with the shift $-k$ (or $26 - k$) restores the original text. A shift of $13$ gives **ROT13**, which is its own inverse.
*   **Complexity:** $O(n)$, where $n$ is the string length; the string is modified in place.
*   **Example:**
```
    Input:
    3
 
    Output:
    Wkh Txlfn Eurzq Ira Mxpsv Ryhu Wkh Odcb Grj
```
 
### 18. Vigenère Cipher ([`encryption/vigenere_cipher.c`](encryption/vigenere_cipher.c))
An implementation of the **Vigenère cipher** — a polyalphabetic substitution cipher that generalizes the Caesar cipher: instead of one fixed shift, each letter is shifted by the corresponding letter of a repeating keyword.
 
*   **How it works:** 
    1. The program encrypts the built-in string `text` with the built-in keyword `key` (uppercase Latin letters).
    2. The keyword is converted into an array of shifts `intkey`, where `'A'` → $0$, `'B'` → $1$, …, `'Z'` → $25$. For example, `LEMON` gives the shifts $11, 4, 12, 14, 13$.
    3. A separate counter `j` tracks the position in the keyword. For each Latin letter of the text, the shift `intkey[j % key_len]` is applied:
    $$c'_i = \text{base} + (c_i - \text{base} + k_{j \bmod m}) \bmod 26$$
    where `base` is `'A'` or `'a'` and $m$ is the keyword length.
    4. `j` is incremented **only after a letter** is encrypted, so spaces and punctuation do not consume keyword letters. Letter case is preserved; non-letter characters stay unchanged.
    5. An empty keyword is rejected early to avoid a zero-length array and division by zero in `j % key_len`.
*   **Decryption:** applying the shifts $26 - k$ instead of $k$ restores the original text.
*   **Complexity:** $O(n + m)$, where $n$ is the text length and $m$ is the keyword length; the text is modified in place.
*   **Constraints:** The keyword must consist of uppercase Latin letters `A`–`Z`.
*   **Example:**
```
    Text:   ATTACKATDAWN
    Key:    LEMON
 
    Output:
    LXFOPVEFRNHR
```
 
---