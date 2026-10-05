# 6_Binary_Tree: Binary Tree Algorithms

Complete C11 implementations of the classic 41 binary tree problems covering traversals (level order, boundary, diagonal, zigzag), views (left, right, top, bottom), construction, transformations, LCA, and subtree dynamic programming.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Level_order_traversal.c](0_Level_order_traversal.c) | BFS Queue | Standard breadth-first level order traversal |
| [1_Reverse_Level_Order_traversal.c](1_Reverse_Level_Order_traversal.c) | Queue + Stack | Bottom-up level order traversal |
| [2_Height_of_a_tree.c](2_Height_of_a_tree.c) | Recursion | Max depth of binary tree ($1 + \max(lh, rh)$) |
| [3_Diameter_of_a_tree.c](3_Diameter_of_a_tree.c) | Tree DP | Longest path between two leaves in $O(n)$ |
| [4_Mirror_of_a_tree.c](4_Mirror_of_a_tree.c) | Invert Tree | Swapping left and right pointers recursively |
| [5_Inorder_Traversal.c](5_Inorder_Traversal.c) | Tree DFS | Left-Root-Right traversal |
| [6_Preorder_Traversal.c](6_Preorder_Traversal.c) | Tree DFS | Root-Left-Right traversal |
| [7_Postorder_Traversal.c](7_Postorder_Traversal.c) | Tree DFS | Left-Right-Root traversal |
| [8_Left_View_tree.c](8_Left_View_tree.c) | Level Tracking | First node visible from the left |
| [9_Right_View_Tree.c](9_Right_View_Tree.c) | Level Tracking | First node visible from the right |
| [10_Top_View_tree.c](10_Top_View_tree.c) | Horizontal Distance | First node at each horizontal offset using hash/table |
| [11_Bottom_View_tree.c](11_Bottom_View_tree.c) | Horizontal Distance | Last node at each horizontal offset |
| [12_Zig_Zag_tree.c](12_Zig_Zag_tree.c) | Level Alternation | Reversing alternating levels in BFS |
| [13_Check_tree_balanced_or_not.c](13_Check_tree_balanced_or_not.c) | Height Balance | Height difference $\le 1$ at every node |
| [14_Diagonal_Traversal_tree.c](14_Diagonal_Traversal_tree.c) | Slope Traversal | Traversing right child chains via queue |
| [15_Boundary_traversal_tree.c](15_Boundary_traversal_tree.c) | Perimeter Walk | Left boundary + leaves + reverse right boundary |
| [16_Construct_Binary_Tree_String_Bracket_Representation.c](16_Construct_Binary_Tree_String_Bracket_Representation.c) | Parsing | Deserializing string bracket representation |
| [17_Convert_Binary_tree_Doubly_Linked_List.c](17_Convert_Binary_tree_Doubly_Linked_List.c) | In-place Relinking | Transforming binary tree into sorted DLL |
| [18_Convert_Binary_tree_Sum_tree.c](18_Convert_Binary_tree_Sum_tree.c) | Postorder Mutation | Node value replaced by sum of subtrees |
| [19_Construct_Binary_tree_from_Inorder_and_preorder_traversal.c](19_Construct_Binary_tree_from_Inorder_and_preorder_traversal.c) | D&C Reconstruction | Preorder root partition on Inorder search |
| [20_Find_minimum_swaps_required_convert_Binary_tree_into_BST.c](20_Find_minimum_swaps_required_convert_Binary_tree_into_BST.c) | Array Cycles | Minimum swaps to sort inorder array |
| [21_Check_if_Binary_tree_is_Sum_tree_or_not.c](21_Check_if_Binary_tree_is_Sum_tree_or_not.c) | Sum Validation | Verifying $node = left\_sum + right\_sum$ |
| [22_Leaf_at_same_leve.c](22_Leaf_at_same_leve.c) | Leaf Depth | Validating uniform depth across all leaves |
| [23_Check_Binary_Tree_duplicate_subtrees.c](23_Check_Binary_Tree_duplicate_subtrees.c) | Subtree Structure | Finding duplicate subtrees of size $\ge 2$ |
| [24_Check_Mirror_N-ary_tree.c](24_Check_Mirror_N-ary_tree.c) | Edge Symmetry | Testing mirror symmetry across N-ary edges |
| [25_Sum_Nodes_Longest_path_from_root_leaf_node.c](25_Sum_Nodes_Longest_path_from_root_leaf_node.c) | Path Accumulation | Max sum along paths of maximum length |
| [26_Check_graph_tree_or_not.c](26_Check_graph_tree_or_not.c) | Graph Cycle & Connect | Cycle detection + single component check |
| [27_Find_Largest_subtree_sum_tree.c](27_Find_Largest_subtree_sum_tree.c) | Subtree DP | Maximum subtree node sum |
| [28_Maximum_Sum_nodes_Binary_tree_adjacent.c](28_Maximum_Sum_nodes_Binary_tree_adjacent.c) | Independent Set DP | House Robber III pattern on trees |
| [29_Print_all_K_Sum_paths_Binary_tree.c](29_Print_all_K_Sum_paths_Binary_tree.c) | Backtracking Path | Counting any downward path summing to $k$ |
| [30_Find_LCA_Binary_tree.c](30_Find_LCA_Binary_tree.c) | Lowest Common Ancestor | Divergence node in non-BST binary tree |
| [31_Find_distance_between_nodes_Binary_tree.c](31_Find_distance_between_nodes_Binary_tree.c) | LCA Distance | $dist(LCA, a) + dist(LCA, b)$ |
| [32_Kth_Ancestor_node_Binary_tree.c](32_Kth_Ancestor_node_Binary_tree.c) | Ancestor Tracing | Node at $k$ steps up from target |
| [33_Find_all_Duplicate_subtrees_Binary_tree.c](33_Find_all_Duplicate_subtrees_Binary_tree.c) | Structural Subtree Match | Structural comparison finding identical subtrees |
| [34_Tree_Isomorphism_Problem.c](34_Tree_Isomorphism_Problem.c) | Structural Isomorphism | Validating tree equality under child flips |
| [35_tree_traversals_all.c](35_tree_traversals_all.c) | Basic Traversals | Inorder, Preorder, Postorder reference |
| [36_reverse_level_order_print.c](36_reverse_level_order_print.c) | BFS Stack Print | Printing level order from bottom to top |
| [37_find_max_element_binary_tree.c](37_find_max_element_binary_tree.c) | Tree Extrema | Global maximum node search |
| [38_max_sum_level_binary_tree.c](38_max_sum_level_binary_tree.c) | Iterative Level Sum | Finding level with maximum accumulated sum |
| [39_max_sum_level_recursive.c](39_max_sum_level_recursive.c) | Recursive Level Sum | Depth-indexed array accumulation |
| [40_search_element_binary_tree.c](40_search_element_binary_tree.c) | DFS Search | Linear search in unsorted binary tree |

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 30_Find_LCA_Binary_tree.c -o lca && ./lca
```
