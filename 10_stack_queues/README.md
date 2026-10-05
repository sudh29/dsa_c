# 10_Stack_Queues: Stacks & Queues

Comprehensive implementations of Stack and Queue data structures and classic problems in **C11**.

## Problems & Implementations

| File | Data Structure / Pattern | Key Concept |
|------|--------------------------|-------------|
| [0_Implement_Stack.c](0_Implement_Stack.c) | Stack | Array-based fixed capacity stack (`push`, `pop`, `peek`) |
| [1_Implement_Queue.c](1_Implement_Queue.c) | Circular Queue | Array-based circular queue with modulo indexing |
| [2_Implement_2_stack_in_an_array.c](2_Implement_2_stack_in_an_array.c) | Space Optimization | 2 stacks growing towards each other in 1 array |
| [3_find_the_middle_element_of_a_stack.c](3_find_the_middle_element_of_a_stack.c) | Mid Tracking | Doubly linked list stack with $O(1)$ `findMiddle()` |
| [4_Implement_N_stacks_in_an_Array.c](4_Implement_N_stacks_in_an_Array.c) | Space-Efficient Design | $K$ stacks in an array of size $N$ using `next` array |
| [5_Parenthesis_Checker.c](5_Parenthesis_Checker.c) | Stack Pattern | Bracket balance validation using stack |
| [6_Reverse_a_String_using_Stack.c](6_Reverse_a_String_using_Stack.c) | LIFO Property | Reversing characters using stack |
| [7_stack_that_supports_getMin_in_O1.c](7_stack_that_supports_getMin_in_O1.c) | Auxiliary Math Min | Special stack supporting `getMin()` in $O(1)$ time & space |
| [8_Find_the_next_Greater_element.c](8_Find_the_next_Greater_element.c) | Monotonic Stack | Nearest greater element to the right |
| [11_Evaluation_of_Postfix_Expression.c](11_Evaluation_of_Postfix_Expression.c) | Arithmetic Parsing | Evaluating Reverse Polish Notation (RPN) |
| [14_Sort_a_Stack_using_recursion.c](14_Sort_a_Stack_using_recursion.c) | Pure Recursion | Sorting stack without loops or external data structures |
| [15_Merge_Overlapping_Intervals.c](15_Merge_Overlapping_Intervals.c) | Interval Greedy | Sorting and merging intervals |
| [36_First_non-repeating_character_in_a_stream.c](36_First_non-repeating_character_in_a_stream.c) | Queue Stream | Tracking first non-repeating character in stream |
| [stack_generic.c](stack_generic.c) | Generic Stack | Generic `void*` Stack ADT |
| [queue_generic.c](queue_generic.c) | Generic Queue | Generic `void*` Queue ADT |

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 0_Implement_Stack.c -o stack && ./stack
gcc -std=c11 -Wall -Wextra -Werror -O2 8_Find_the_next_Greater_element.c -o nge && ./nge
```
