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

---

## 📐 Berggren Matrices for Pythagorean Triples

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
