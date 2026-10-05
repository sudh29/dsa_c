# 7_BST: Binary Search Tree & Self-Balancing Trees

Complete C11 implementations of Binary Search Tree algorithms, predecessor/successor lookups, interval conflicts, balancing, and AVL Tree self-balancing rotations.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Find_value_BST.c](0_Find_value_BST.c) | Search | Logarithmic traversal on BST invariant ($O(h)$) |
| [1_Deletion_node_BST.c](1_Deletion_node_BST.c) | Deletion | 0, 1, and 2-child cases using inorder successor |
| [2_Find_min_and_max_value_BST.c](2_Find_min_and_max_value_BST.c) | Min/Max Extremes | Extreme left and right pointer traversals |
| [3_Find_inorder_successor_and_inorder_predecessor_BST.c](3_Find_inorder_successor_and_inorder_predecessor_BST.c) | Predecessor/Successor | Inorder navigation without extra memory |
| [4_Check_if_tree_BST_or_not.c](4_Check_if_tree_BST_or_not.c) | Range Validation | Bounding subtrees with $(\text{min}, \text{max})$ |
| [5_Populate_Inorder_successor_all_nodes.c](5_Populate_Inorder_successor_all_nodes.c) | Reverse Inorder | Setting `next` pointer in reverse inorder |
| [6_Find_LCA_2_nodes_BST.c](6_Find_LCA_2_nodes_BST.c) | Lowest Common Ancestor | Divergence point of $n_1$ and $n_2$ |
| [7_Construct_BST_from_preorder_traversal.c](7_Construct_BST_from_preorder_traversal.c) | Construction | Upper-bound recursion in $O(n)$ |
| [8_Convert_Binary_tree_into_BST.c](8_Convert_Binary_tree_into_BST.c) | Inorder Sorting | Preserving tree topology while ordering keys |
| [9_Convert_normal_BST_into_Balanced_BST.c](9_Convert_normal_BST_into_Balanced_BST.c) | D&C Balancing | Rebuilding balanced tree from inorder array |
| [10_Merge_two_BST.c](10_Merge_two_BST.c) | Two Pointer Merge | Merging inorder traversals of two BSTs |
| [11_Find_Kth_largest_element_BST.c](11_Find_Kth_largest_element_BST.c) | Reverse Inorder | Reverse traversal with step count $k$ |
| [12_Find_Kth_smallest_element_BST.c](12_Find_Kth_smallest_element_BST.c) | Inorder Traversal | Standard inorder counting to $k$ |
| [13_Count_pairs_from_2_BST_sum_equal_X.c](13_Count_pairs_from_2_BST_sum_equal_X.c) | Sorted Array Two Pointer | Matching nodes across two independent trees |
| [14_Find_the_median_BST.c](14_Find_the_median_BST.c) | Median | Median value of sorted inorder sequence |
| [15_Count_BST_nodes_lie_range.c](15_Count_BST_nodes_lie_range.c) | Range Pruning | Pruning subtrees outside $[L, R]$ |
| [16_Replace_every_element_least_greater_element_right.c](16_Replace_every_element_least_greater_element_right.c) | BST Insertion Tracking | Predecessor/successor retrieval during build |
| [17_Given_n_appointments_find_conflicting_appointments.c](17_Given_n_appointments_find_conflicting_appointments.c) | Interval Sort & Scan | Detecting overlapping appointment intervals |
| [18_Check_preorder_valid_not.c](18_Check_preorder_valid_not.c) | Monotonic Stack | Validating preorder sequence of a BST |
| [19_Check_whether_BST_contains_Dead_end.c](19_Check_whether_BST_contains_Dead_end.c) | Value Table | Checking leaves bounded by $val-1$ and $val+1$ |
| [20_Largest_BST_Binary_Tree.c](20_Largest_BST_Binary_Tree.c) | Bottom-Up Tree DP | Finding max size valid BST subtree in $O(n)$ |
| [21_Flatten_BST_sorted_list.c](21_Flatten_BST_sorted_list.c) | Relinking | Transforming BST into sorted right-skewed list |
| [22_AVL_Tree_Operations.c](22_AVL_Tree_Operations.c) | Self-Balancing | LL, RR, LR, RL rotation implementations |
| [23_BST_Insert_Delete_Search.c](23_BST_Insert_Delete_Search.c) | BST ADT | Complete insertion, deletion, search operations |

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 22_AVL_Tree_Operations.c -o avl && ./avl
```
