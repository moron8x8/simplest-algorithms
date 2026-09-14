# 📦 Simple Algorithms in C


Welcome to the repository containing basic mathematical algorithms written in C.

The project will expand over time.

---

## 📊 Implemented Algorithms Overview

| # | File | Algorithm Description |
| :---: | :--- | :--- |
| **1** | `matrixfib.c` | Fast Fibonacci number computation using matrix exponentiation |
| **2** | `Sieve-of-Eratosthenes.c` | Finding all prime numbers up to a specified limit $n$ |
| **3** | `pif3.c` | Ternary tree generation of primitive Pythagorean triples |
| **4** | `RLE.c` | Run-Length Encoding (RLE) for text compression |
| **5** | `BubbleSort.c` | Bubble Sort algorithm with an early-exit flag |
| **6** | `SelectionSort.c` | Selection Sort algorithm |


---

## 🧬 Detailed Module Descriptions

### 1. Matrix Fibonacci Solver (`matrixfib.c`)
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

### 2. Sieve of Eratosthenes (`Sieve-of-Eratosthenes.c`)
A classical, highly efficient algorithm to find all prime numbers up to a specified limit $n$.

*   **How it works:** 
    1. An array of flags of size $n$ is initialized, where all elements are initially set to `1` (true). Array index `i` logically maps to the target number $i + 2$.
    2. The algorithm iterates starting from the first prime ($2$). For each prime encountered, all its composite multiples (starting directly from its square $num^2$) are marked as `0` (false).
    3. The loop is mathematically optimized to terminate early as soon as $(i + 2)^2 > n$.
    4. Finally, all array elements remaining as `1` are printed as verified prime numbers alongside the total count.

### 3. Tree of Pythagorean Triples Generator (`pif3.c`)
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

### 4. Run-Length Encoding (`RLE.c`)

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

### 5. Bubble Sort (`BubbleSort.c`)

*   **How it works:** 
    1. The program reads an integer $n$, followed by $n$ elements to populate a Variable-Length Array `arr[n]`.
    2. It prints the original array, executes the sorting routine, and then outputs the final sorted array.
    3. The `BubbleSort` function uses nested loops to compare adjacent elements and swap them if they are in the wrong order (`a[i] > a[i + 1]`).
*   **Optimization:** A `flag` variable tracks whether any swaps occurred during an inner loop pass. If a full pass completes with `flag == 1`, the array is already fully sorted, and the algorithm triggers an early `break` to save redundant operations.
*   **Complexity:** 
    *   **Worst-case / Average-case Time:** $O(n^2)$ when the array is reversed or unsorted.
    *   **Best-case Time:** $O(n)$ when the input array is already sorted (thanks to the optimization flag).
  
### 6. Selection Sort (`SelectionSort.c`)
An implementation of the **Selection Sort** algorithm.

*   **How it works:** 
    1. The program safely reads an integer $n$. If the input is invalid or $n \le 0$, it terminates early to prevent undefined behavior.
    2. A Variable-Length Array (VLA) `a[n]` is populated with integers, backed by `scanf` success checks.
    3. The `SelectionSort` function divides the array into a sorted and an unsorted region.
    4. In each pass, it scans the unsorted part to find the minimum element. If the minimum element is not already at the starting position (`min != i`), it swaps it into its correct place.


---