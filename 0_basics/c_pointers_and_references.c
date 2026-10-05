#include <stdio.h>

// Pass-by-reference simulated via pointer indirection
void swap_pointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function pointer simulating callbacks / higher-order functions
typedef int (*BinaryOp)(int, int);

int multiply(int p, int q) {
    return p * q;
}

int apply_op(int p, int q, BinaryOp op) {
    return op(p, q);
}

int main(void) {
    printf("=== C Pointers and Function Pointers ===\n");
    int x = 50, y = 100;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap_pointers(&x, &y);
    printf("After swap:  x=%d, y=%d\n", x, y);

    // Higher-order function invocation via function pointer
    int result = apply_op(6, 7, multiply);
    printf("Function pointer multiply(6, 7): %d\n", result);

    return 0;
}
