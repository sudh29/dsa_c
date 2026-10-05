#include <stdio.h>

int countBitsFlip(int a, int b) {
    int xor_val = a ^ b;
    return __builtin_popcount(xor_val);
}

int main(void) {
    int a = 10, b = 20;
    printf("Bits to flip from %d to %d: %d\n", a, b, countBitsFlip(a, b));
    return 0;
}
