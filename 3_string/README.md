# 3_String: String Processing & Pattern Matching (C11 Standard)

Complete pure C (C11 standard) implementations of the classic 35 string algorithms covering pattern matching (KMP, Rabin-Karp, Boyer-Moore), palindromes, anagrams, permutations, and DP string alignment.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Reverse_String.c](0_Reverse_String.c) | Two Pointer | In-place character array reversal |
| [1_Palindrome_String.c](1_Palindrome_String.c) | Two Pointer | Symmetric character comparison |
| [2_Find_Duplicate_characters_in_a_string.c](2_Find_Duplicate_characters_in_a_string.c) | Frequency Array | Counting character occurrences |
| [4_Strings_are_rotations_of_other.c](4_Strings_are_rotations_of_other.c) | String Concatenation | Substring check in $s_1 + s_1$ |
| [5_Checking_valid_shuffle_of_two_Strings.c](5_Checking_valid_shuffle_of_two_Strings.c) | Character Counting | Valid interleaved shuffle verification |
| [6_Count_and_Say_problem.c](6_Count_and_Say_problem.c) | Run-Length Encoding | Look-and-say sequence generator |
| [7_Longest_Palindrome_String.c](7_Longest_Palindrome_String.c) | Expand Around Center | Longest palindromic substring in $O(n^2)$ |
| [8_Find_Longest_Recurring_Subsequence_String.c](8_Find_Longest_Recurring_Subsequence_String.c) | Dynamic Programming | Modified LCS where $i \neq j$ |
| [9_Print_all_Subsequences_string.c](9_Print_all_Subsequences_string.c) | Backtracking / Recursion | Pick and don't-pick enumeration |
| [10_All_permutations_string.c](10_All_permutations_string.c) | Backtracking | In-place swapping permutation generator |
| [11_Split_binary_string_0s_and_1s.c](11_Split_binary_string_0s_and_1s.c) | Greedy Scan | Splitting into maximum equal 0/1 substrings |
| [14_Next_Permutation.c](14_Next_Permutation.c) | Lexicographical Next | Pivot element swapping & suffix reversal |
| [15_Balanced_Parenthesis_problem_Imp.c](15_Balanced_Parenthesis_problem_Imp.c) | Stack | Bracket balance validation |
| [16_Word_break_Problem_Very_Imp.c](16_Word_break_Problem_Very_Imp.c) | Dynamic Programming | Segmenting string into dictionary words |
| [17_Rabin_Karp_Algo.c](17_Rabin_Karp_Algo.c) | Rolling Hash | Rolling polynomial hash pattern search |
| [18_KMP_Algo.c](18_KMP_Algo.c) | Knuth-Morris-Pratt | $O(n + m)$ search using LPS array |
| [19_Convert_sentence_into_its_equivalent_mobile_numeric_keypad_sequence.c](19_Convert_sentence_into_its_equivalent_mobile_numeric_keypad_sequence.c) | Lookup Table | Old mobile keypad numeric conversion |
| [20_Count_the_Reversals.c](20_Count_the_Reversals.c) | Greedy Stack | Minimum bracket reversals to balance |
| [21_Count_Palindromic_Subsequences.c](21_Count_Palindromic_Subsequences.c) | 2D Dynamic Programming | Inclusion-exclusion DP on intervals |
| [23_Search_Word_2D_Grid_characters.c](23_Search_Word_2D_Grid_characters.c) | 8-Directional Search | Word search in character matrix |
| [24_Boyer_Moore_Algorithm_Pattern_Searching.c](24_Boyer_Moore_Algorithm_Pattern_Searching.c) | Bad Character Heuristic | Right-to-left scanning with character skips |
| [25_Converting_Roman_Numerals_to_Decimal.c](25_Converting_Roman_Numerals_to_Decimal.c) | Lookahead Subtraction | Roman numeral value accumulation |
| [26_Longest_Common_Prefix.c](26_Longest_Common_Prefix.c) | Horizontal Scanning | Rolling common prefix reduction |
| [27_Number_flips_make_binary_string_alternate.c](27_Number_flips_make_binary_string_alternate.c) | Parity Check | Distance to alternating patterns "0101..." / "1010..." |
| [28_Find_the_first_repeated_word_in_string.c](28_Find_the_first_repeated_word_in_string.c) | String Tokenization | First recurring word lookup |
| [29_Minimum_swaps_bracket_balancing.c](29_Minimum_swaps_bracket_balancing.c) | Two Pointer Greedy | Unbalanced bracket position swapping |
| [30_Longest_Common_Subsequence.c](30_Longest_Common_Subsequence.c) | Classic 2D DP | Finding LCS length of two strings |
| [32_Smallest_distinct_window.c](32_Smallest_distinct_window.c) | Sliding Window | Minimum window containing all unique characters |
| [33_Rearrange_characters_string_no_two_adjacent_are_same.c](33_Rearrange_characters_string_no_two_adjacent_are_same.c) | Greedy Placement | Alternating character placement by highest frequency |
| [34_Minimum_characters_added_front_make_string_palindrome.c](34_Minimum_characters_added_front_make_string_palindrome.c) | KMP LPS Array | Finding longest palindromic prefix |
| [35_Given_sequence_words_print_all_anagrams_together.c](35_Given_sequence_words_print_all_anagrams_together.c) | Sorting & Word Pairs | Grouping anagrams |
| [37_Remove_Consecutive_Characters.c](37_Remove_Consecutive_Characters.c) | Linear Filtering | Deduplicating adjacent identical characters |
| [41_Isomorphic_Strings.c](41_Isomorphic_Strings.c) | Dual Mapping Tables | Bijective character mapping validation |
| [42_Recursively_print_all_sentences_formed_from_list_word_lists.c](42_Recursively_print_all_sentences_formed_from_list_word_lists.c) | DFS / Backtracking | Cartesian product sentence generator |
| [string1.c](string1.c) | Brute Force Search | Baseline $O(n \cdot m)$ pattern finder |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 18_KMP_Algo.c -o kmp && ./kmp

# Run module test suite
make test MODULE=3_string
```
