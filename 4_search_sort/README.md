# 4_Search_Sort: Searching & Sorting Algorithms (C11 Standard)

Complete implementations of classic sorting and searching algorithms in pure **C (C11 standard)**.

## Sorting Algorithms (C11)
| File | Algorithm | Time Complexity (Avg / Worst) | Space Complexity |
|------|-----------|-------------------------------|------------------|
| [bubble_sort.c](bubble_sort.c) | Bubble Sort | $O(n^2)$ / $O(n^2)$ | $O(1)$ |
| [selection_sort.c](selection_sort.c) | Selection Sort | $O(n^2)$ / $O(n^2)$ | $O(1)$ |
| [insertion_sort.c](insertion_sort.c) | Insertion Sort | $O(n^2)$ / $O(n^2)$ | $O(1)$ |
| [merge_sort.c](merge_sort.c) | Merge Sort | $O(n \log n)$ / $O(n \log n)$ | $O(n)$ |
| [quick_sort.c](quick_sort.c) | Quick Sort | $O(n \log n)$ / $O(n^2)$ | $O(\log n)$ |
| [heap_sort.c](heap_sort.c) | Heap Sort | $O(n \log n)$ / $O(n \log n)$ | $O(1)$ |

## Searching & Sorting Problems (C11)
| File | Problem Description / Pattern |
|------|--------------------------------|
| [0_First_and_last_occurrences_of_x.c](0_First_and_last_occurrences_of_x.c) | Binary Search (First/Last Occurrence) |
| [1_Value_equal_to_index_value.c](1_Value_equal_to_index_value.c) | Linear Traversal / 1-based indexing |
| [2_Search_in_a_rotated_sorted_array.c](2_Search_in_a_rotated_sorted_array.c) | Modified Binary Search on Rotated Array |
| [3_Count_Squares.c](3_Count_Squares.c) | Binary Search integer square root counting |
| [4_Find_min_and_max_element_in_an_array.c](4_Find_min_and_max_element_in_an_array.c) | Min/Max element extraction |
| [6_Find_Missing_And_Repeating.c](6_Find_Missing_And_Repeating.c) | In-place array negation / Index mapping |
| [7_Majority_Element.c](7_Majority_Element.c) | Boyer-Moore Voting Algorithm |
| [8_Searching_in_an_array_where_adjacent_differ_by_at_most_k.c](8_Searching_in_an_array_where_adjacent_differ_by_at_most_k.c) | Step Jump Search ($O(n/k)$) |
| [9_Find_Pair_Given_Difference.c](9_Find_Pair_Given_Difference.c) | Sorting + Two Pointers |
| [10_Find_All_Four_Sum_Numbers.c](10_Find_All_Four_Sum_Numbers.c) | 4Sum with Two Pointers & Duplicate Avoidance |
| [11_maximum_sum_such_that_no_2_elements_are_adjacent.c](11_maximum_sum_such_that_no_2_elements_are_adjacent.c) | House Robber / DP without Adjacent |
| [12_Count_triplets_with_sum_smaller_than_X.c](12_Count_triplets_with_sum_smaller_than_X.c) | Two Pointer Triplet Counting |
| [13_merge_two_sorted_arrays.c](13_merge_two_sorted_arrays.c) | Merge procedure of two sorted arrays |
| [14_Zero_Sum_Subarrays.c](14_Zero_Sum_Subarrays.c) | Prefix Sum Hash Table counting |
| [15_Product_array_puzzle.c](15_Product_array_puzzle.c) | Prefix and Suffix product accumulators |
| [16_Sort_by_Set_Bit_Count.c](16_Sort_by_Set_Bit_Count.c) | Stable sort with `__builtin_popcount` |
| [17_Minimum_Swaps_to_Sort.c](17_Minimum_Swaps_to_Sort.c) | Graph Cycle Decomposition |
| [18_Bishu_and_Soldiers.c](18_Bishu_and_Soldiers.c) | Binary Search `upper_bound` + Prefix Sum |
| [20_Kth_smallest_number_again.c](20_Kth_smallest_number_again.c) | Interval Merging & k-th query resolution |
| [21_Find_pivot_element_in_a_sorted_array.c](21_Find_pivot_element_in_a_sorted_array.c) | Binary Search for Inflection Point |
| [22_Kth_element_of_two_sorted_Arrays.c](22_Kth_element_of_two_sorted_Arrays.c) | Binary Search Partitioning on Two Arrays |
| [23_Aggressive_cows.c](23_Aggressive_cows.c) | Binary Search on Answer (Min distance placement) |
| [26_Job_Scheduling_Algo.c](26_Job_Scheduling_Algo.c) | Greedy Deadline Slotting |
| [27_Arithmetic_Number.c](27_Arithmetic_Number.c) | Arithmetic Progression check |
| [28_Smallest_factorial_number.c](28_Smallest_factorial_number.c) | Binary Search on trailing zeros |
| [33_Count_Inversions.c](33_Count_Inversions.c) | Modified Merge Sort Inversion Counter |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 2_Search_in_a_rotated_sorted_array.c -o search && ./search

# Run module test suite
make test MODULE=4_search_sort
```
