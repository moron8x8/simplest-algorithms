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
| **7** | `InsertionSort.c` | Insertion Sort algorithm |
| **8** | `MergeSort.c` | Merge Sort algorithm using a divide-and-conquer strategy |
| **9** | `BinarySearch.c` | Recursive and Iterative Binary Search algorithms  |
| **10** | `prime_factorization.c` | Prime factorization of an integer |
| **11** | `find_pair_sum.c` | Two-Sum problem solver using Merge Sort and a Two-Pointer technique |
| **12** | `matrixuppertriangular.c` | Gaussian elimination method for matrix triangularization |
| **13** | `BFS.c` | Breadth-First Search (BFS) algorithm on a graph using static arrays |



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

### 7. Insertion Sort (`InsertionSort.c`)
An implementation of the **Insertion Sort** algorithm, which builds the final sorted array one item at a time.

*   **How it works:** 
    1. The program  reads the array size $n$ and its elements.
    2. The `InsertionSort` function iterates through the array from left to right.
    3. For each element (`nonsorted`), it scans backwards through the sorted sub-array to find its correct position.
    4. Elements greater than the current key are shifted one position to the right to clear space, and the key is placed in its valid sorted slot.

### 8. Merge Sort (`MergeSort.c`)
An implementation of the **Merge Sort** algorithm, which uses the divide-and-conquer paradigm to sort an array efficiently.

*   **How it works:** 
    1. The program  reads the array size $n$ and its elements.
    2. The `MergeSort` function recursively splits the array into two halves until sub-arrays of size 1 or 0 are reached.
    3. The `merge` function then combines the sorted sub-arrays back together into a single sorted unit using a temporary buffer.

### 9. Binary Search (`BinarySearch.c`)
An implementation of the **Binary Search** algorithm, showcasing both iterative and recursive approaches to search for a target element within a sorted array.

*   **How it works:** 
    1. The program read the sorted array size n, its elements, and the target number (`searchednum`).
    2. **Iterative Approach (`BinSearchLeftRight`):** Uses a `while` loop with moving `left` and `right` pointers to shrink the search space by half each iteration.
    3. **Recursive Approach (`BinSearchRecursion`):** Achieves the same divide-and-conquer logic through explicit self-invocation, passing updated boundaries down the call stack.

### 10. Prime Factorization (`prime_factorization.c`)
Implementation to compute the **prime factorization of an integer**.

*   **How it works:** 
    1. The program isolates the smallest prime number (\(2\)) inside a `while` loop, extracting all even factors from the number completely.
    2. The algorithm then iterates through an optimized `for` loop executing only odd numbers from \(3\) up to \(\sqrt{num}\). If any odd number completely divides the remaining value, it is printed and divided recursively.
    3. **Mathematical Optimization:** If the remaining value of `num` after loop bounds is greater than \(1\), it is inherently a prime number itself and is printed as the final factor.

### 11. Two-Sum Pair Solver (`find_pair_sum.c`)
An efficient solver for the **Two-Sum problem** using a combination of sorting and a two-pointer approach.

*   **How it works:** 
    1. **Data Structure:** Uses a custom `element` structure to store both the integer `value` and its original 0-based `index` so that position data is not lost during sorting.
    2. **Sorting Phase:** Applies the `MergeSort` routine to sort the elements by value in \(O(n \log n)\) time.
    3. **Two-Pointer Scan:** Places two pointers (`right` at the beginning and `left` at the end) of the sorted array. The pointers converge based on the current sum relative to the `target`, finding the matching pair in a single \(O(n)\) linear scan.

### 12. Matrix Upper Triangularization (`matrixuppertriangular.c`)
Transforms a square matrix into an **upper triangular matrix** using Gaussian elimination row operations.

*   **How it works:** 
    1. The program  reads the matrix size `len`. 
    2. A Variable-Length 2D Array `arr[len][len]` is populated with double-precision floating-point numbers from standard input.
    3. The `gauss_method` function iterates down through each pivot row. For every row below the active pivot, it calculates a structural multiplier factor k.
    
    4. The algorithm then subtracts from the current lower row to zero out the elements below the main diagonal, building an upper triangular shape.
    5. The final matrix is printed out with values rounded to two decimal places.

### 13. Breadth-First Search (`BFS.c`)
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
---