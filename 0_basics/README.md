# 0_Basics: C Fundamentals (C11 Standard)

This module covers core foundational programming constructs in pure C (C11 standard), focusing on memory management, pointers, object-oriented encapsulation patterns in C, file I/O, and essential algorithms.

## Programs

| File | Topic / Concept |
|------|-----------------|
| [c_syntax_and_types.c](c_syntax_and_types.c) | Data types, type sizes, limits, arithmetic operators |
| [c_pointers_and_memory.c](c_pointers_and_memory.c) | Pointers, dereferencing, manual dynamic allocation (`malloc`/`free`) |
| [c_structs_and_typedefs.c](c_structs_and_typedefs.c) | Custom `struct` definitions, `typedef`, pass-by-pointer |
| [swap_two_numbers.c](swap_two_numbers.c) | In-place swapping via pointers and bitwise XOR |
| [prime_check.c](prime_check.c) | Optimized trial division primality test ($O(\sqrt{n})$) |
| [count_set_bits.c](count_set_bits.c) | Brian Kernighan's set-bit counting algorithm |
| [c_hello_and_io.c](c_hello_and_io.c) | Standard I/O streams (`printf`, `snprintf`), formatted output |
| [c_three_way_comparison.c](c_three_way_comparison.c) | Idiomatic C three-way comparisons (`strcmp`, `qsort` comparator convention) |
| [c_pointers_and_references.c](c_pointers_and_references.c) | Pass-by-reference simulation via pointers, function pointers & callbacks |
| [c_classes_and_oop.c](c_classes_and_oop.c) | Object-oriented patterns, encapsulation, and struct methods via function pointers |
| [c_dynamic_array.c](c_dynamic_array.c) | Resizable dynamic array (vector ADT) with `malloc`/`realloc`/`free` |
| [c_anagrams.c](c_anagrams.c) | Anagram validation using frequency hashing in C |
| [c_pattern_count.c](c_pattern_count.c) | Substring search and pattern occurrence counting via `strstr` |
| [c_grid_paths.c](c_grid_paths.c) | Unique grid paths via Dynamic Programming |
| [c_file_io.c](c_file_io.c) | C file operations with `fopen`, `fputs`, `fgets`, and `fclose` |
| [system_details.c](system_details.c) | Compiler identification, `__STDC_VERSION__`, architecture pointer size |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 c_syntax_and_types.c -o syntax && ./syntax

# Run module test suite
make test MODULE=0_basics
```
