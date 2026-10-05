# 1_Array: Array Algorithms & Patterns (C11 Standard)

Complete pure C (C11 standard) implementations of the classic 35 array problems covering two-pointer techniques, sliding windows, interval manipulation, cycle detection, and greedy strategies.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Reverse_the_array.c](0_Reverse_the_array.c) | Two Pointer | In-place swapping ($O(n)$) |
| [1_Find_max_min_element_array.c](1_Find_max_min_element_array.c) | Linear Scan | Min/Max tracking in single pass |
| [2_Kth_smallest_element.c](2_Kth_smallest_element.c) | Selection | Sorting / QuickSelect |
| [3_Sort_an_array_of_0s,_1s_and_2s.c](3_Sort_an_array_of_0s,_1s_and_2s.c) | Dutch National Flag | 3-way partition in single pass |
| [4_Move_all_negative_elements_to_end.c](4_Move_all_negative_elements_to_end.c) | Two Pointer / Partition | Stable segregation of positive & negative |
| [5_Union_of_two_arrays.c](5_Union_of_two_arrays.c) | Sorting / Hashing | Union counting via sorted merger |
| [6_Cyclically_rotate_an_array_by_one.c](6_Cyclically_rotate_an_array_by_one.c) | In-place Shift | Clockwise rotation by 1 |
| [7_Kadanes_Algorithm.c](7_Kadanes_Algorithm.c) | Dynamic Programming | Maximum contiguous subarray sum |
| [8_Minimize_the_Heights_II.c](8_Minimize_the_Heights_II.c) | Greedy | Height difference minimization after $\pm k$ |
| [9_Minimum_number_of_jumps.c](9_Minimum_number_of_jumps.c) | Greedy Jump | Tracking max reachable index |
| [10_Find_the_Duplicate_Number.c](10_Find_the_Duplicate_Number.c) | Cycle Detection | Floyd's Tortoise & Hare algorithm |
| [11_Merge_Without_Extra_Space.c](11_Merge_Without_Extra_Space.c) | Shell Sort Gap Method | In-place merging of two sorted arrays |
| [13_Merge_Intervals.c](13_Merge_Intervals.c) | Interval Greedy | Sorting intervals and merging overlaps |
| [14_Next_Permutation.c](14_Next_Permutation.c) | Permutation Logic | Finding lexicographically next permutation |
| [15_Count_Inversions.c](15_Count_Inversions.c) | Divide & Conquer | Enhanced Merge Sort inversion counter |
| [16_Best_Time_to_Buy_and_Sell_Stock.c](16_Best_Time_to_Buy_and_Sell_Stock.c) | Single Pass Greedy | Tracking rolling minimum price |
| [17_Count_pairs_with_given_sum.c](17_Count_pairs_with_given_sum.c) | Hash Table | Pair sum counting with complement table |
| [18_find_common_elements_In_3_sorted_arrays.c](18_find_common_elements_In_3_sorted_arrays.c) | Three Pointer | Intersection of 3 sorted arrays |
| [19_Alternate_positive_and_negative_numbers.c](19_Alternate_positive_and_negative_numbers.c) | Rearrangement | Interleaving positive and negative elements |
| [20_Subarray_with_0_sum.c](20_Subarray_with_0_sum.c) | Prefix Sum Hash Table | Detecting zero-sum subarrays |
| [21_Factorials_of_large_numbers.c](21_Factorials_of_large_numbers.c) | Big Int Simulation | Digit array multiplication for large factorials |
| [22_Maximum_Product_Subarray.c](22_Maximum_Product_Subarray.c) | Dynamic Programming | Tracking rolling min & max products |
| [23_Longest_consecutive_subsequence.c](23_Longest_consecutive_subsequence.c) | Sorting / Scanning | Longest sequence of consecutive integers |
| [24_Majority_Element_II_k_n.c](24_Majority_Element_II_k_n.c) | Sorting / Frequency | Elements appearing $> n/k$ times |
| [25_Buy_and_Sell_Stock_III.c](25_Buy_and_Sell_Stock_III.c) | State Machine DP | Max profit with at most 2 transactions |
| [26_Array_Subset_of_another_array.c](26_Array_Subset_of_another_array.c) | Sorting + Two Pointers | Multiset inclusion validation |
| [27_Triplet_Sum_in_Array.c](27_Triplet_Sum_in_Array.c) | Sorting + Two Pointer | 3Sum exact target check |
| [28_Trapping_Rain_Water.c](28_Trapping_Rain_Water.c) | Two Pointer / Prefix Max | Calculating trapped water volume |
| [29_Chocolate_Distribution_Problem.c](29_Chocolate_Distribution_Problem.c) | Sliding Window | Minimizing difference in sorted packet window |
| [30_Minimum_Size_Subarray_Sum.c](30_Minimum_Size_Subarray_Sum.c) | Sliding Window | Smallest subarray with sum $\ge \text{target}$ |
| [31_Three_way_partitioning.c](31_Three_way_partitioning.c) | Dutch National Flag | Partitioning around a range $[a, b]$ |
| [32_Minimum_swaps_and_K_together.c](32_Minimum_swaps_and_K_together.c) | Sliding Window | Swapping elements $\le k$ into a contiguous block |
| [33_Form_a_palindrome.c](33_Form_a_palindrome.c) | Longest Palindromic Subsequence | Minimum insertions via 2D DP |
| [34_Find_the_median.c](34_Find_the_median.c) | Sorting | Median of an odd/even sized array |
| [35_Median_of_2_Sorted_Arrays_of_Different_Sizes.c](35_Median_of_2_Sorted_Arrays_of_Different_Sizes.c) | Binary Search Partitioning | $O(\log(\min(n_1, n_2)))$ median across 2 arrays |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 7_Kadanes_Algorithm.c -o kadane && ./kadane

# Run module test suite
make test MODULE=1_array
```
