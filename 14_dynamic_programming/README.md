# Dynamic Programming in Pure C (C11)

This directory contains classic and advanced problems solved using **Dynamic Programming (DP)** techniques in pure C11, demonstrating tabulation, memoization, space optimization, and classic paradigm variants (Knapsack, LCS, LIS, Interval DP, Grid DP).

| File | Problem | Pattern(s) |
|------|---------|------------|
| [0_Coin_Change.c](0_Coin_Change.c) | Coin Change (Ways to Make Change) | DP / Unbounded Knapsack |
| [1_0-1_Knapsack_Problem.c](1_0-1_Knapsack_Problem.c) | 0-1 Knapsack Problem | DP / 0-1 Knapsack |
| [2_Binomial_CoefficientProblem.c](2_Binomial_CoefficientProblem.c) | Binomial Coefficient (nCr) | DP / Pascal's Identity |
| [3_Permutation_CoefficientProblem.c](3_Permutation_CoefficientProblem.c) | Permutation Coefficient P(n, k) | DP / Combinatorics |
| [4_Program_for_nth_Catalan_Number.c](4_Program_for_nth_Catalan_Number.c) | N-th Catalan Number | DP / Convolution Recurrence |
| [5_Matrix_Chain_Multiplication.c](5_Matrix_Chain_Multiplication.c) | Matrix Chain Multiplication | DP / Interval DP |
| [7_Subset_Sum_Problem.c](7_Subset_Sum_Problem.c) | Subset Sum Problem | DP / 0-1 Knapsack |
| [8_Friends_Pairing_Problem.c](8_Friends_Pairing_Problem.c) | Friends Pairing Problem | DP / Recurrence Relation |
| [9_Gold_Mine_Problem.c](9_Gold_Mine_Problem.c) | Gold Mine Problem | DP / 2D Grid Traversal |
| [11_Painting_the_Fenceproblem.c](11_Painting_the_Fenceproblem.c) | Painting the Fence Problem | DP / Color Combinations |
| [12_Maximize_The_Cut_Segments.c](12_Maximize_The_Cut_Segments.c) | Maximize Cut Segments | DP / Unbounded Knapsack |
| [13_Longest_Common_Subsequence.c](13_Longest_Common_Subsequence.c) | Longest Common Subsequence | DP / LCS |
| [14_Longest_Repeated_Subsequence.c](14_Longest_Repeated_Subsequence.c) | Longest Repeated Subsequence | DP / LCS Variation |
| [15_Longest_Increasing_Subsequence.c](15_Longest_Increasing_Subsequence.c) | Longest Increasing Subsequence | DP / Binary Search (Patience Sort) |
| [16_Space_Optimized_Solution_LCS.c](16_Space_Optimized_Solution_LCS.c) | Space-Optimized LCS | DP / Two-Row Space Optimization |
| [17_LCS_of_three_strings.c](17_LCS_of_three_strings.c) | LCS of Three Strings | DP / 3D DP |
| [18_Maximum_Sum_Increasing_Subsequence.c](18_Maximum_Sum_Increasing_Subsequence.c) | Maximum Sum Increasing Subsequence | DP / LIS Variant |
| [19_Count_all_subsequences_product_less_than_K.c](19_Count_all_subsequences_product_less_than_K.c) | Subarrays with Product Less than K | Two Pointers / Sliding Window DP |
| [20_Longest_subsequence_1.c](20_Longest_subsequence_1.c) | Longest Subsequence with Difference 1 | DP / LIS Variation |
| [21_Max_Sum_without_Adjacents_2.c](21_Max_Sum_without_Adjacents_2.c) | Max Sum with No 3 Adjacent | DP / House Robber Variant |
| [22_Egg_Dropping_Problem.c](22_Egg_Dropping_Problem.c) | Egg Dropping Problem | DP / Minimax Optimization |
| [23_Max_length_chain.c](23_Max_length_chain.c) | Max Length Chain of Pairs | Greedy / Interval Scheduling |
| [24_Maximum_size_square_sub_matrix_with_all_1s.c](24_Maximum_size_square_sub_matrix_with_all_1s.c) | Maximum Square Sub-matrix with 1s | DP / 2D Matrix DP |
| [25_Maximum_sum_pairs_specific_difference.c](25_Maximum_sum_pairs_specific_difference.c) | Max Sum Pairs with Difference < K | DP / Pair Matching |
| [26_Min_Cost_PathProblem.c](26_Min_Cost_PathProblem.c) | Maximum / Minimum Path in Grid | DP / Grid Traversal |
| [27_Maximum_difference_zeros_and_ones_binary_string.c](27_Maximum_difference_zeros_and_ones_binary_string.c) | Max Difference 0s and 1s in Substring | DP / Kadane's Algorithm |
| [28_Minimum_number_jumps_reach_end.c](28_Minimum_number_jumps_reach_end.c) | Minimum Jumps to Reach End | Greedy / BFS / DP |
| [29_Minimum_cost_fill_weight_bag.c](29_Minimum_cost_fill_weight_bag.c) | Minimum Cost to Fill Weight Bag | DP / Unbounded Knapsack |
| [30_Array_Removals.c](30_Array_Removals.c) | Minimum Removals for Difference <= K | Sorting / Sliding Window |
| [31_Longest_Common_Substring.c](31_Longest_Common_Substring.c) | Longest Common Substring | DP / 2D Matrix Matching |
| [32_Reach_given_score.c](32_Reach_given_score.c) | Reach Given Score | DP / Coin Change Variant |
| [33_BBT_counter.c](33_BBT_counter.c) | Count Balanced Binary Trees of Height H | DP / Tree Counting |
| [34_LargestSum_Contiguous_Subarray.c](34_LargestSum_Contiguous_Subarray.c) | Largest Sum Contiguous Subarray | Kadane's Algorithm |
| [35_Smallest_sum_contiguous_subarray.c](35_Smallest_sum_contiguous_subarray.c) | Smallest Sum Contiguous Subarray | Kadane's Algorithm Min Variant |
| [36_Unbounded_Knapsack.c](36_Unbounded_Knapsack.c) | Unbounded Knapsack Problem | DP / 1D Array Optimization |
| [37_Word_Break_Problem.c](37_Word_Break_Problem.c) | Word Break Problem | DP / Hash Set |
| [38_Largest_Independent_Set_Problem.c](38_Largest_Independent_Set_Problem.c) | Largest Independent Set in Tree | Tree DP / Memoization |
| [39_Partition_problem.c](39_Partition_problem.c) | Partition Equal Subset Sum | DP / 0-1 Knapsack |
| [40_Longest_Palindromic_Subsequence.c](40_Longest_Palindromic_Subsequence.c) | Longest Palindromic Subsequence | DP / Interval DP |
| [41_Count_Palindromic_Subsequences.c](41_Count_Palindromic_Subsequences.c) | Count Palindromic Subsequences | DP / Inclusion-Exclusion Interval DP |
| [42_Longest_Palindromic_Substring.c](42_Longest_Palindromic_Substring.c) | Longest Palindromic Substring | Two Pointers / Center Expansion |
| [43_Longest_alternating_subsequence.c](43_Longest_alternating_subsequence.c) | Longest Alternating Subsequence | DP / Peak-Valley Transition |
| [44_Weighted_Job_Scheduling.c](44_Weighted_Job_Scheduling.c) | Job Sequencing with Deadlines & Profits | Greedy / Disjoint Slot Scheduling |
| [47_Buy_and_Sell_Share_at_most_twice.c](47_Buy_and_Sell_Share_at_most_twice.c) | Stock Buy & Sell at Most Twice | DP / Bidirectional Prefix-Suffix |
| [48_Optimal_Strategy_Game.c](48_Optimal_Strategy_Game.c) | Optimal Strategy for a Game | DP / Minimax Interval DP |
| [52_Mobile_Numeric_Keypad_Problem.c](52_Mobile_Numeric_Keypad_Problem.c) | Mobile Numeric Keypad Problem | DP / State Transition Matrix |
| [56_Maximum_sum_Rectangle.c](56_Maximum_sum_Rectangle.c) | Maximum Sum Rectangle in 2D Matrix | DP / 2D Kadane's Algorithm |
| [57_Stock_Buy_Sell_Max_K_Transactions_Allowed.c](57_Stock_Buy_Sell_Max_K_Transactions_Allowed.c) | Stock Buy & Sell with Max K Transactions | DP / State Optimization |
| [58_Interleaved_Strings.c](58_Interleaved_Strings.c) | Interleaved Strings | DP / 2D Grid Matching |
| [59_Maximum_Length_of_Pair_Chain.c](59_Maximum_Length_of_Pair_Chain.c) | Maximum Length of Pair Chain | Greedy / Interval Scheduling |

## Compilation
All programs can be compiled using modern C11:
```bash
gcc -std=c11 -Wall -Wextra -O2 filename.c -o app
./app
```
