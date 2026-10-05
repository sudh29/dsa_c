# 8_Greedy: Greedy Algorithms (C11 Standard)

Complete pure C (C11 standard) implementations of classic greedy algorithms covering activity selection, knapsack, platform scheduling, Huffman coding, and interval optimization.

## Problems & Solutions

| File | Problem | Pattern(s) |
|------|---------|------------|
| [0_Activity_Selection_Problem.c](0_Activity_Selection_Problem.c) | Activity Selection Problem | Greedy / Sorting by Finish Time |
| [1_Job_Sequencing_Problem.c](1_Job_Sequencing_Problem.c) | Job Sequencing Problem | Greedy / Deadline Sorting |
| [2_Huffman_Coding.c](2_Huffman_Coding.c) | Huffman Coding | Greedy / Min Heap |
| [3_Water_Connection_Problem.c](3_Water_Connection_Problem.c) | Water Connection Problem | Graph / DFS / Greedy |
| [4_Fractional_Knapsack_Problem.c](4_Fractional_Knapsack_Problem.c) | Fractional Knapsack | Greedy / Sorting by Value-to-Weight Ratio |
| [5_Choose_and_Swap.c](5_Choose_and_Swap.c) | Choose and Swap | Greedy / Lexicographical Matching |
| [6_Maximum_trains_for_which_stoppage_provided.c](6_Maximum_trains_for_which_stoppage_provided.c) | Max Trains with Stoppage | Greedy / Multi-platform Interval Scheduling |
| [7_Minimum_Platforms_Problem.c](7_Minimum_Platforms_Problem.c) | Minimum Platforms Problem | Greedy / Event Sorting / Two Pointers |
| [8_Buy_Maximum_Stocks_i_stocks_bought_i-th_day.c](8_Buy_Maximum_Stocks_i_stocks_bought_i-th_day.c) | Buy Maximum Stocks on i-th Day | Greedy / Sorting by Price |
| [9_Find_minimum_maximum_amount_to_buy_all_N_candies.c](9_Find_minimum_maximum_amount_to_buy_all_N_candies.c) | Shop in Candy Store | Greedy / Extremum Selection |
| [11_Minimum_Cost_cut_board_into_squares.c](11_Minimum_Cost_cut_board_into_squares.c) | Minimum Cost to Cut Board | Greedy / Multi-dimensional Cutting |
| [12_Check_possible_survive_island.c](12_Check_possible_survive_island.c) | Check Survival on Island | Greedy / Mathematical Simulation |
| [13_Find_maximum_meetings_one_room.c](13_Find_maximum_meetings_one_room.c) | Max Meetings in One Room | Greedy / Activity Selection |
| [14_Maximum_product_subset_array.c](14_Maximum_product_subset_array.c) | Maximum Product Subset | Greedy / Sign Analysis |
| [15_Maximize_array_sum_after_K_negations.c](15_Maximize_array_sum_after_K_negations.c) | Maximize Sum After K Negations | Greedy / Sorting & Min Element Inversion |
| [16_Maximize_sum_arr_i_i.c](16_Maximize_sum_arr_i_i.c) | Maximize Sum `arr[i] * i` | Greedy / Sorting Ascending |
| [17_Maximum_sum_absolute_difference_array.c](17_Maximum_sum_absolute_difference_array.c) | Max Sum Absolute Difference | Greedy / Interleaving Extrema |
| [18_Maximize_sum_consecutive_differences_circular_array.c](18_Maximize_sum_consecutive_differences_circular_array.c) | Max Circular Consecutive Differences | Greedy / Reordering Extrema |
| [19_Minimum_sum_absolute_difference_pairs_two_arrays.c](19_Minimum_sum_absolute_difference_pairs_two_arrays.c) | Min Sum Absolute Differences in Pairs | Greedy / Dual Array Sorting |
| [21_Page_Faults_LRU.c](21_Page_Faults_LRU.c) | Page Faults in LRU Cache | Greedy / LRU Cache Simulation |
| [22_Smallest_subset_with_sum_greater_than_all_other_elements.c](22_Smallest_subset_with_sum_greater_than_all_other_elements.c) | Smallest Subset with Larger Sum | Greedy / Suffix vs Prefix Accumulation |
| [23_Chocolate_Distribution_Problem.c](23_Chocolate_Distribution_Problem.c) | Chocolate Distribution Problem | Greedy / Sliding Window of Sorted Elements |
| [26_GERGOVIA_Wine_trading_Gergovia.c](26_GERGOVIA_Wine_trading_Gergovia.c) | Wine Trading in Gergovia | Greedy / Prefix Demand Accumulation |
| [31_Minimum_Cost_ropes.c](31_Minimum_Cost_ropes.c) | Minimum Cost of Ropes | Greedy / Min Heap (Huffman-like merge) |
| [32_Find_smallest_number_given_number_digits_sum_digits.c](32_Find_smallest_number_given_number_digits_sum_digits.c) | Smallest Number with Sum and Digits | Greedy / Reverse Digit Filling |
| [33_Rearrange_characters.c](33_Rearrange_characters.c) | Rearrange Characters | Greedy / Frequency Interleaving |
| [34_Find_Maximum_Equal_sum_Three_Stack.c](34_Find_Maximum_Equal_sum_Three_Stack.c) | Find Maximum Equal Sum of Three Stacks | Greedy / Multi-pointer Stack Trimming |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 0_Activity_Selection_Problem.c -o act && ./act

# Run module test suite
make test MODULE=8_greedy
```
