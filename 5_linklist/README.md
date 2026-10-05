# 5_Linklist: Linked List Algorithms

Complete C11 implementations of the classic 29 linked list problems covering singly linked lists, doubly linked lists, circular lists, intersection algorithms, cycle detection, and memory management.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Reverse_a_linked_list.c](0_Reverse_a_linked_list.c) | Pointer Reversal | Iterative 3-pointer list reversal ($O(n)$) |
| [1_Reverse_Linked_List_groups_given_size.c](1_Reverse_Linked_List_groups_given_size.c) | Chunk Reversal | Reversing $k$ elements recursively |
| [2_Detect_Loop_in_linked_list.c](2_Detect_Loop_in_linked_list.c) | Floyd's Cycle Finding | Slow and fast pointer collision |
| [3_Remove_loop_LL.c](3_Remove_loop_LL.c) | Cycle Breaking | Finding cycle length and resetting loop pointer |
| [4_Find_first_node_of_loop_LL.c](4_Find_first_node_of_loop_LL.c) | Cycle Inception | Locating entry node to cycle |
| [5_Remove_duplicate_element_from_sorted_LL.c](5_Remove_duplicate_element_from_sorted_LL.c) | Deduplication | Skipping consecutive equal values |
| [6_Remove_duplicates_from_an_unsorted_LL.c](6_Remove_duplicates_from_an_unsorted_LL.c) | Hash Set | Deleting seen values in single pass |
| [7_Move_last_element_to_front_LL.c](7_Move_last_element_to_front_LL.c) | Pointer Relinking | Tail detachment and head insertion |
| [8_Add_1_to_a_number_represented_LL.c](8_Add_1_to_a_number_represented_LL.c) | Arithmetic Traversal | Reverse, propagate carry, and re-reverse |
| [9_Add_two_numbers_represented_LL.c](9_Add_two_numbers_represented_LL.c) | Multi-digit Addition | Summing two digit lists with carry |
| [10_Intersection_of_two_sorted_LL.c](10_Intersection_of_two_sorted_LL.c) | Two Pointer | Merged intersection of sorted lists |
| [11_Intersection_Point_in_Y_Shapped_LL.c](11_Intersection_Point_in_Y_Shapped_LL.c) | Pointer Alignment | Equalizing path lengths to finding merge point |
| [14_Middle_of_the_LL.c](14_Middle_of_the_LL.c) | Tortoise & Hare | $O(n)$ single pass mid-node retrieval |
| [15_Check_If_Circular_LL.c](15_Check_If_Circular_LL.c) | Cycle Check | Verifying circular termination |
| [16_Split_a_Circular_LL_into_two_halves.c](16_Split_a_Circular_LL_into_two_halves.c) | Circular Partition | Splitting circular list at midpoint |
| [17_Check_if_LL_is_Palindrome.c](17_Check_if_LL_is_Palindrome.c) | Mid Reversal | Comparing first half with reversed second half |
| [18_Deletion_and_Reverse_LL.c](18_Deletion_and_Reverse_LL.c) | Circular LL Manipulation | Node deletion and reverse in circular LL |
| [19_Reverse_a_Doubly_LL.c](19_Reverse_a_Doubly_LL.c) | DLL Pointer Swap | Swapping `next` and `prev` pointers |
| [20_Find_pairs_with_given_sum_in_doubly_LL.c](20_Find_pairs_with_given_sum_in_doubly_LL.c) | DLL Two Pointer | Meeting pointers from head and tail in sorted DLL |
| [21_Count_triplets_in_a_sorted_doubly_LL.c](21_Count_triplets_in_a_sorted_doubly_LL.c) | DLL 3Sum | Finding triplets with given target sum |
| [23_Rotate_doubly_LL.c](23_Rotate_doubly_LL.c) | DLL Block Shift | Rotating doubly linked list by $p$ nodes |
| [27_Flattening_a_LL.c](27_Flattening_a_LL.c) | Multilevel Merge | Merging 2D bottom-linked structures |
| [28_Sort_a_LL_of_0s_1s_and_2s.c](28_Sort_a_LL_of_0s_1s_and_2s.c) | Counting Sort | In-place value rewriting based on frequencies |
| [31_Multiply_two_LL.c](31_Multiply_two_LL.c) | Big Number Math | Modular arithmetic product of two list numbers |
| [32_Delete_nodes_having_greater_value_on_right_LL.c](32_Delete_nodes_having_greater_value_on_right_LL.c) | Suffix Max | Monotonic non-decreasing rightward filtering |
| [33_Segregate_even_and_odd_nodes_in_a_LL.c](33_Segregate_even_and_odd_nodes_in_a_LL.c) | Stable Partition | Appending even and odd nodes to separate tails |
| [34_Nth_node_from_end_of_LL.c](34_Nth_node_from_end_of_LL.c) | Fast/Slow Offset | Gap of $n$ nodes to track end distance |
| [35_First_non-repeating_character_in_a_stream.c](35_First_non-repeating_character_in_a_stream.c) | Queue Stream | Character frequency queue tracking |
| [LinkList1.c](LinkList1.c) | Linked List ADT | Complete C struct and function implementation |

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 0_Reverse_a_linked_list.c -o reverse && ./reverse
```
