# Data Structures & Algorithms in Pure C (C11)

[![Language: C11](https://img.shields.io/badge/Language-C11-blue.svg)](https://en.wikipedia.org/wiki/C11_(C_version))
[![Compiler: GCC](https://img.shields.io/badge/Compiler-GCC%2011%2B-green.svg)](https://gcc.gnu.org/)
[![Compiler: Clang](https://img.shields.io/badge/Compiler-Clang%2013%2B-purple.svg)](https://clang.llvm.org/)
[![Problems: 390](https://img.shields.io/badge/DSA%20Problems-390%20Verified-brightgreen.svg)](#repository-architecture)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A comprehensive, production-grade repository of **390 Data Structures and Algorithms** implementations written in pure, modern **C (C11 standard)**.

All programs are self-contained, high-performance C source files adhering strictly to the C11 standard, compiled cleanly with `-Wall -Wextra -Werror -O2`, and featuring built-in non-interactive test suites with automated verification.

---

## Table of Contents
- [Repository Architecture](#repository-architecture)
- [Module Highlights](#module-highlights)
- [Standards & Best Practices](#standards--best-practices)
- [Build and Testing](#build-and-testing)
  - [Run Complete Test Suite](#1-run-complete-test-suite)
  - [Test Specific Module](#2-test-a-single-module)
  - [Compile Individual Program](#3-compile-an-individual-file)
  - [Clean Build Artifacts](#4-clean-artifacts)
- [Repository Structure](#repository-structure)
- [License](#license)

---

## Repository Architecture

The repository is organized into 16 canonical DSA modules, covering fundamental to advanced computer science concepts:

| # | Directory | Focus Area | Language | Programs | Guide |
|---|-----------|------------|----------|----------|-------|
| `0` | [0_basics/](0_basics/) | C Fundamentals, Pointers, Memory Management, Structs, File I/O | C11 | 16 | [README](0_basics/README.md) |
| `1` | [1_array/](1_array/) | Arrays, Two Pointers, Sliding Window, Prefix Sums, Kadane's | C11 | 35 | [README](1_array/README.md) |
| `2` | [2_matrix/](2_matrix/) | 2D Matrices, Rotations, Spiral Traversals, Matrix Search | C11 | 10 | [README](2_matrix/README.md) |
| `3` | [3_string/](3_string/) | String Manipulation, Palindromes, KMP, Rabin-Karp, Substrings | C11 | 35 | [README](3_string/README.md) |
| `4` | [4_search_sort/](4_search_sort/) | Search & Sort Algorithms (Quick, Merge, Heap, Binary Search) | C11 | 32 | [README](4_search_sort/README.md) |
| `5` | [5_linklist/](5_linklist/) | Singly, Doubly & Circular Linked Lists, Fast/Slow Pointers | C11 | 29 | [README](5_linklist/README.md) |
| `6` | [6_binary_tree/](6_binary_tree/) | Binary Trees, Traversals (Morris, Level-order), LCA, Views | C11 | 41 | [README](6_binary_tree/README.md) |
| `7` | [7_bst/](7_bst/) | Binary Search Trees, Balanced Trees, AVL Trees, Conversions | C11 | 24 | [README](7_bst/README.md) |
| `8` | [8_greedy/](8_greedy/) | Greedy Algorithms, Activity Selection, Huffman, Interval Scheduling | C11 | 27 | [README](8_greedy/README.md) |
| `9` | [9_backtracking/](9_backtracking/) | Backtracking, N-Queens, Sudoku, Maze, Permutations | C11 | 20 | [README](9_backtracking/README.md) |
| `10` | [10_stack_queues/](10_stack_queues/) | Stacks & Queues, Monotonic Stacks, LRU Cache, Sliding Max | C11 | 15 | [README](10_stack_queues/README.md) |
| `11` | [11_heap/](11_heap/) | Min/Max Heaps, Priority Queues, K-way Merges, Median Finding | C11 | 20 | [README](11_heap/README.md) |
| `12` | [12_graph/](12_graph/) | Graphs, BFS, DFS, Dijkstra, Kruskal, Kahn's Algo, Floyd-Warshall | C11 | 20 | [README](12_graph/README.md) |
| `13` | [13_Trie/](13_Trie/) | Prefix Trees, Word Dictionaries, Maximum XOR Pair Search | C11 | 6 | [README](13_Trie/README.md) |
| `14` | [14_dynamic_programming/](14_dynamic_programming/) | Dynamic Programming, Knapsack, LCS, LIS, Matrix DP, MCM | C11 | 50 | [README](14_dynamic_programming/README.md) |
| `15` | [15_bit_manipulation/](15_bit_manipulation/) | Bit Manipulation, Bitmasks, Power Sets, Bitwise Arithmetic | C11 | 10 | [README](15_bit_manipulation/README.md) |
| **Total** | | | | **390** | |

---

## Module Highlights

- **`0_basics/`**: Foundational language mechanics in C11 (`struct`, dynamic heap memory, pointer arithmetic, function pointers, preprocessor directives, encapsulation patterns, dynamic arrays).
- **`1_array/` & `2_matrix/`**: Core linear and multi-dimensional techniques: Kadane's algorithm, Dutch National Flag algorithm, Boyer-Moore Voting, Trapping Rain Water, Next Permutation, Median of Two Sorted Arrays, Spiral Matrix, Search in Sorted Matrix.
- **`3_string/`**: Comprehensive string search and manipulation in C: KMP algorithm (LPS table), Rabin-Karp polynomial rolling hash, Longest Palindromic Substring, Word Wrap, Smallest Window containing all characters.
- **`4_search_sort/`**: Classic sorting (Bubble, Insertion, Selection, Merge, Quick, Heap sort) and algorithmic search patterns (Binary Search on Answer, Allocate Minimum Pages, Painter's Partition, Aggressive Cows).
- **`5_linklist/`**: Complete pointer manipulation: Reverse in K-groups, Detect & Remove Cycle (Floyd's Tortoise and Hare), Flatten Multilevel Linked List, Merge K Sorted Lists, Add Two Numbers.
- **`6_binary_tree/` & `7_bst/`**: Tree algorithms: Morris Inorder/Preorder Traversals ($O(1)$ auxiliary space), Top/Bottom/Left/Right Views, Lowest Common Ancestor (LCA), Diameter of Tree, AVL Tree Rotations, BST Insert/Delete/Search, Balance BST.
- **`8_greedy/`**: Optimal substructure choices: Activity Selection, Job Sequencing with Deadlines, Huffman Coding, Fractional Knapsack, Minimum Platforms, Wine Trading in Gergovia.
- **`9_backtracking/`**: Exhaustive search with state restoration: Rat in a Maze, N-Queens problem, Sudoku Solver, Graph $m$-Coloring, Palindromic Partitions, K-th Permutation Sequence.
- **`10_stack_queues/`**: Monotonic stack & queue applications: Next Greater Element, Largest Rectangle in Histogram, Min Stack ($O(1)$), LRU Cache using Doubly Linked List and Hash Table, Circular Queue.
- **`11_heap/`**: Priority queue paradigms: Heap Sort, Merge K Sorted Arrays/Lists, Find Median from Data Stream (Two Heaps), K Largest Elements, Rearrange Characters.
- **`12_graph/`**: Graph theory algorithms: BFS, DFS, Cycle Detection (Directed & Undirected), Dijkstra's Shortest Path, Kahn's Topological Sort, Kruskal's MST with Disjoint Set Union (DSU with rank & path compression), Floyd-Warshall All-Pairs Shortest Path.
- **`13_Trie/`**: Prefix tree representations: Insertion, Search, Prefix Matching, Word Break using Trie, Maximum XOR of Two Numbers.
- **`14_dynamic_programming/`**: 50 dynamic programming solutions: 0/1 Knapsack, Unbounded Knapsack, Longest Common Subsequence (LCS), Longest Increasing Subsequence (LIS in $O(n \log n)$), Matrix Chain Multiplication, Catalan Numbers, Egg Dropping, Optimal Game Strategy, Stock Buy/Sell with $K$ transactions.
- **`15_bit_manipulation/`**: Low-level bitwise operations: Brian Kernighan's bit-counting algorithm, Single Number (XOR), Power Set generation, Count set bits from 1 to $N$, Bitwise division without multiplication/division operators.

---

## Standards & Best Practices

- **Standard Adherence**: Every program adheres strictly to the **C11 standard** (`-std=c11`).
- **Standard Library Only**: Uses official ISO C library headers (`<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<stdbool.h>`, `<stdint.h>`, `<limits.h>`, `<math.h>`, etc.). Non-standard or GCC-specific headers have been deliberately avoided.
- **Standalone Verification Drivers**: Every `.c` file contains its own self-contained `int main()` driver executing real test cases with assertion-style validations, ensuring instant verification without requiring manual input.
- **Type Safety & Bounds**: Numerical overflows are mitigated using 64-bit integers (`long long` / `int64_t`) and standard sizes (`size_t`).
- **Memory Safety**: Clean pointer handling, explicit allocation tracking, and resource deallocation.

---

## Build and Testing

### 1. Run Complete Test Suite
Run the automated test runner across all 390 programs (automatically utilizing multi-core parallelism):
```bash
make test
# Or with strict -Werror mode:
make test STRICT=1
# Or directly via the bash test runner:
./scripts/compile_and_test.sh -j 12 --strict
```

### 2. Test a Single Module or File
You can verify any individual module or specific source file:
```bash
make test MODULE=0_basics
# Or directly via the test runner:
./scripts/compile_and_test.sh 4_search_sort
./scripts/compile_and_test.sh 1_array/7_Kadanes_Algorithm.c
./scripts/compile_and_test.sh 12_graph 14_dynamic_programming
```

### 3. Compile an Individual File
Compile any individual C file directly using GCC or Clang:
```bash
# Pure C implementation (C11):
gcc -std=c11 -Wall -Wextra -O2 4_search_sort/quick_sort.c -o quick_sort
./quick_sort

# Or with Clang:
clang -std=c11 -Wall -Wextra -O2 14_dynamic_programming/13_Longest_Common_Subsequence.c -o lcs
./lcs
```

### 4. Clean Artifacts
Remove temporary binaries and build directories:
```bash
make clean
```

---

## Repository Structure

```text
dsa_c/
├── 0_basics/                 # C11 language fundamentals & memory management (16 files)
├── 1_array/                  # Array manipulations & algorithms (35 files)
├── 2_matrix/                 # 2D matrix algorithms (10 files)
├── 3_string/                 # String algorithms & pattern matching (35 files)
├── 4_search_sort/            # Classic sorting & searching algorithms (32 files)
├── 5_linklist/               # Singly, doubly, circular linked lists (29 files)
├── 6_binary_tree/            # Binary tree traversals, properties, views (41 files)
├── 7_bst/                    # Binary search trees & balanced trees (24 files)
├── 8_greedy/                 # Greedy algorithm strategies (27 files)
├── 9_backtracking/           # Backtracking problem solutions (20 files)
├── 10_stack_queues/          # Stack and Queue data structures (15 files)
├── 11_heap/                  # Binary heaps & priority queues (20 files)
├── 12_graph/                 # Graph algorithms & representations (20 files)
├── 13_Trie/                  # Trie data structures & bitwise trie (6 files)
├── 14_dynamic_programming/   # Tabulation, memoization & DP paradigms (50 files)
├── 15_bit_manipulation/      # Bitwise algorithms & bitmasks (10 files)
├── scripts/
│   └── compile_and_test.sh   # Comprehensive pure C11 test suite runner
├── Makefile                  # Build automation (test, clean, help)
├── LICENSE                   # MIT License
└── README.md                 # Primary repository documentation
```

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.