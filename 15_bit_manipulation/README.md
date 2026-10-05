# 15_Bit_Manipulation: Bitwise Operations & Tricks (C11 Standard)

Complete pure C (C11 standard) implementations of fundamental bit manipulation algorithms, maskings, and bitwise arithmetic.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Number_of_1_Bits.c](0_Number_of_1_Bits.c) | Brian Kernighan | $O(\text{set bits})$ counting via $n \& (n-1)$ |
| [1_Non_Repeating_Numbers.c](1_Non_Repeating_Numbers.c) | 2 Unique Elements | XOR partition by rightmost set bit ($x \& (-x)$) |
| [2_Bit_Difference.c](2_Bit_Difference.c) | Hamming Distance | `__builtin_popcount(a ^ b)` |
| [3_Count_total_set_bits.c](3_Count_total_set_bits.c) | MSB Power Partition | Recursive counting in range $[1, n]$ |
| [4_Is_power_of_two.c](4_Is_power_of_two.c) | Bitwise AND | Single bit validation $(n \& (n - 1)) == 0$ |
| [5_Find_position_of_the_only_set_bit.c](5_Find_position_of_the_only_set_bit.c) | Bit Scanning | Locating index of lone set bit |
| [6_Set_all_the_bits_in_given_range_of_a_number.c](6_Set_all_the_bits_in_given_range_of_a_number.c) | Bit Masking | Range mask creation: $((1 \ll R) - 1) \oplus ((1 \ll (L - 1)) - 1)$ |
| [7_Division_without_using_multiplication_division_and_mod_operator.c](7_Division_without_using_multiplication_division_and_mod_operator.c) | Bitwise Long Division | Subtracting divisor shifted by $2^i$ |
| [8_Calculate_square_of_a_number_without_using_*_pow.c](8_Calculate_square_of_a_number_without_using_*_pow.c) | Bit Shifting | Odd/even decomposition: $(2x+1)^2 = 4(x^2+x)+1$ |
| [9_Power_Set.c](9_Power_Set.c) | Bitmask Subsets | Iterating bitmasks from $1$ to $2^n-1$ |

## Compilation & Execution
```bash
# Compile and run individual program
gcc -std=c11 -Wall -Wextra -O2 0_Number_of_1_Bits.c -o setbits && ./setbits

# Run module test suite
make test MODULE=15_bit_manipulation
```
