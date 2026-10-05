# 9_Backtracking: Backtracking Algorithms (C11 Standard)

Complete pure C (C11 standard) implementations of classic backtracking algorithms covering N-Queens, Sudoku, graph coloring, palindromic partitions, and grid route optimization.

## Problems & Solutions

| File | Problem | Pattern(s) |
|------|---------|------------|
| [0_Rat_maze_Problem.c](0_Rat_maze_Problem.c) | Rat in a Maze Problem | Backtracking / DFS on Grid |
| [1_Printing_all_solutions_N-Queen_Problem.c](1_Printing_all_solutions_N-Queen_Problem.c) | N-Queen Problem | Backtracking / Constraint Checking |
| [3_Remove_Invalid_Parentheses.c](3_Remove_Invalid_Parentheses.c) | Remove Invalid Parentheses | Backtracking / Expression Pruning |
| [4_Sudoku_Solver.c](4_Sudoku_Solver.c) | Sudoku Solver | Backtracking / Constraint Propagation |
| [5_m_Coloring_Problem.c](5_m_Coloring_Problem.c) | m-Coloring Problem | Backtracking / Graph Vertex Coloring |
| [6_Print_all_palindromic_partitions_string.c](6_Print_all_palindromic_partitions_string.c) | Palindromic Partitions of String | Backtracking / Palindrome Verification |
| [7_Partition_Equal_Subset_Sum.c](7_Partition_Equal_Subset_Sum.c) | Partition Equal Subset Sum | Backtracking / Subset Sum |
| [10_Find_shortest_safe_route_matrix.c](10_Find_shortest_safe_route_matrix.c) | Shortest Safe Route in Matrix | Backtracking / Safety Grid Traversal |
| [11_Combination_Sum.c](11_Combination_Sum.c) | Combination Sum | Backtracking / Recursive Combinations |
| [12_Largest_number_K_swaps.c](12_Largest_number_K_swaps.c) | Largest Number with K Swaps | Backtracking / Greedy Swap Choices |
| [13_Print_all_permutations_string.c](13_Print_all_permutations_string.c) | Print All Permutations of String | Backtracking / In-place Swapping |
| [14_Path_greater_than_equal_to_k_length.c](14_Path_greater_than_equal_to_k_length.c) | Path of Length >= K | Backtracking / DFS on Weighted Graph |
| [15_Longest_Possible_Route_Matrix_with_Hurdles.c](15_Longest_Possible_Route_Matrix_with_Hurdles.c) | Longest Route with Hurdles | Backtracking / Grid Traversal |
| [16_Print_all_possible_paths_from_top_left_bottom_right_mXn_matrix.c](16_Print_all_possible_paths_from_top_left_bottom_right_mXn_matrix.c) | All Paths in m x n Matrix | Backtracking / Grid Paths |
| [17_Partition_array_to_K_subsets.c](17_Partition_array_to_K_subsets.c) | Partition Array to K Subsets | Backtracking / K-Partitioning |
| [18_Find_K-th_Permutation_Sequence_first_N_natural_numbers.c](18_Find_K-th_Permutation_Sequence_first_N_natural_numbers.c) | K-th Permutation Sequence | Backtracking / Factorial Number System |
| [combination_strings.c](combination_strings.c) | All Character Combinations of Length K | Recursion / Permutations with Repetition |
| [path_finder_matrix.c](path_finder_matrix.c) | Matrix Path Finder | Backtracking / Grid Exploration |
| [sorted_array_check.c](sorted_array_check.c) | Check If Array is Sorted | Recursion / Array Inspection |
| [tower_of_hanoi.c](tower_of_hanoi.c) | Tower of Hanoi | Classic Recursion / Divide & Conquer |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 4_Sudoku_Solver.c -o sudoku && ./sudoku

# Run module test suite
make test MODULE=9_backtracking
```
