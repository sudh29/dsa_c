# 13_Trie: Prefix Trees & Retrieval

Complete C11 implementations of Trie data structures, prefix queries, dictionary word break, phone directory auto-completion, and binary matrix deduplication.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Construct_trie_from_scratch.c](0_Construct_trie_from_scratch.c) | Trie ADT | Fixed 26-ary tree (`insert`, `search`) |
| [1_Shortest_Unique_prefix_for_every_word.c](1_Shortest_Unique_prefix_for_every_word.c) | Node Frequency | Finding earliest node with prefix frequency 1 |
| [2_Word_Break_Problem_Trie_solution.c](2_Word_Break_Problem_Trie_solution.c) | Trie + Memoization | Prefix matching for sentence segmentation |
| [3_Print_Anagrams_Together.c](3_Print_Anagrams_Together.c) | Grouping | Sorting anagram keys and grouping entries |
| [4_Phone_directory.c](4_Phone_directory.c) | Auto-Complete | Prefix query returning sorted contact set |
| [5_Unique_rows_boolean_matrix.c](5_Unique_rows_boolean_matrix.c) | Binary Trie | 2-ary Trie deduplicating matrix bit vectors |

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 0_Construct_trie_from_scratch.c -o trie && ./trie
```
