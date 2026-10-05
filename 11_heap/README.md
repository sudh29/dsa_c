# 11_Heap: Binary Heap & Priority Queue Algorithms

Complete C11 implementations of Max-Heap, Min-Heap, priority queues, and classic streaming/median algorithms.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Implement_Maxheap_MinHeap_arrays_recursion.c](0_Implement_Maxheap_MinHeap_arrays_recursion.c) | Heap Construction | Recursive heapify & array heap builder |
| [1_Sort_Array_using_heap_sort.c](1_Sort_Array_using_heap_sort.c) | Sorting | In-place $O(n \log n)$ Heap Sort |
| [2_Maximum_all_subarrays_size_k.c](2_Maximum_all_subarrays_size_k.c) | Sliding Window | Monotonic deque max tracker |
| [3_k_largest_element_array.c](3_k_largest_element_array.c) | Top-K Filter | Sorting / tracking top $k$ elements |
| [4_Kth_smallest_largest_element_unsorted_array.c](4_Kth_smallest_largest_element_unsorted_array.c) | Selection Filter | Tracking $k$-th smallest element |
| [5_Merge_k_Sorted_Arrays.c](5_Merge_k_Sorted_Arrays.c) | K-Way Merge | Min-heap of size $k$ merging sorted rows |
| [6_Merge_2_Binary_Max_Heaps.c](6_Merge_2_Binary_Max_Heaps.c) | Array Concat & Heapify | Merging two arrays into a unified max-heap |
| [7_Kth_largest_sum_continuous_subarrays.c](7_Kth_largest_sum_continuous_subarrays.c) | Subarray Sums | Tracking top $k$ subarray sums |
| [8_Reorganize_String.c](8_Reorganize_String.c) | Greedy Placement | Alternating character placement by frequency |
| [9_Merge_K_sorted_linked_lists.c](9_Merge_K_sorted_linked_lists.c) | K-Way Pointer Merge | Merging $K$ linked lists |
| [10_Smallest_range_in_K_lists.c](10_Smallest_range_in_K_lists.c) | Sliding Range | Tracking min & max across $K$ sorted streams |
| [11_Median_stream_Integers.c](11_Median_stream_Integers.c) | Streaming Median | Insertion and median retrieval from rolling stream |
| [12_Is_Binary_Tree_Heap.c](12_Is_Binary_Tree_Heap.c) | Tree Validation | Completeness + parent $\ge$ child invariant |
| [13_Minimum_Cost_of_ropes.c](13_Minimum_Cost_of_ropes.c) | Huffman Greedy | Combining smallest two ropes with min-heap |
| [14_Convert_BST_to_Min_Max_Heap.c](14_Convert_BST_to_Min_Max_Heap.c) | Tree Traversal Order | Inorder to preorder conversion |
| [15_Convert_Min_Heap_Max_Heap.c](15_Convert_Min_Heap_Max_Heap.c) | Re-Heapify | Downward max-heapify from $(n-2)/2$ down to $0$ |
| [16_Rearrange_characters.c](16_Rearrange_characters.c) | Frequency Placement | Adjacent distinct character rearrangement |
| [17_Minimum_sum.c](17_Minimum_sum.c) | Greedy Partition | Forming two numbers from sorted digits |
| [max_heap_fundamentals.c](max_heap_fundamentals.c) | Max-Heap ADT | Custom max-heap struct (`insertMax`, `extractMax`) |
| [min_heap_fundamentals.c](min_heap_fundamentals.c) | Min-Heap ADT | Custom min-heap struct (`insertMin`, `extractMin`) |

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 11_Median_stream_Integers.c -o median && ./median
```
