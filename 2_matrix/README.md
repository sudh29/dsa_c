# 2_Matrix: 2D Grid & Matrix Algorithms (C11 Standard)

Complete pure C (C11 standard) implementations for classic 2D matrix manipulation, searches, and dynamic programming patterns.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Spirally_traversing_a_matrix.c](0_Spirally_traversing_a_matrix.c) | Simulation | Boundary-based spiral unwinding |
| [1_Search_a_2D_Matrix.c](1_Search_a_2D_Matrix.c) | Binary Search | Virtual 1D index mapping ($O(\log(mn))$) |
| [2_Median_in_a_row_wise_sorted_Matrix.c](2_Median_in_a_row_wise_sorted_Matrix.c) | Binary Search on Value | Counting smaller elements with binary search upper bound |
| [3_Row_with_max_1s.c](3_Row_with_max_1s.c) | Top-Right Traversal | Staircase scan from top-right in $O(m + n)$ |
| [4_Sorted_matrix.c](4_Sorted_matrix.c) | Flattening & Sort | Flatten matrix, `qsort()`, and reshape |
| [5_Maximum_size_rectangle.c](5_Maximum_size_rectangle.c) | Histogram Stack DP | Largest rectangle of 1s using monotonic stack |
| [6_Find_a_specific_pair_in_matrix.c](6_Find_a_specific_pair_in_matrix.c) | 2D Suffix Max DP | Finding max $\text{mat}[c][d] - \text{mat}[a][b]$ |
| [7_Rotate_by_90_degree_anti.c](7_Rotate_by_90_degree_anti.c) | In-place Matrix Math | Transposition followed by column reversal |
| [8_Kth_element_in_Matrix.c](8_Kth_element_in_Matrix.c) | Min-Heap | K-way merge using custom binary min-heap |
| [9_Common_elements_in_all_rows_of_a_given_matrix.c](9_Common_elements_in_all_rows_of_a_given_matrix.c) | Hash Table | Tracking occurrences row-by-row with hash table |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 0_Spirally_traversing_a_matrix.c -o spiral && ./spiral

# Run module test suite
make test MODULE=2_matrix
```
