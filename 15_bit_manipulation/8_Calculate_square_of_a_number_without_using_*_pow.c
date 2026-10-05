#include <stdio.h>

int square(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;

    int x = n >> 1;
    if (n & 1) { // odd: (2x+1)^2 = 4x^2 + 4x + 1 = 4(x^2 + x) + 1
        return ((square(x) + x) << 2) + 1;
    } else { // even: (2x)^2 = 4x^2
        return square(x) << 2;
    }
}

int main(void) {
    int test_cases[] = {5, 7, 12, 15};
    int n = sizeof(test_cases) / sizeof(test_cases[0]);
    for (int i = 0; i < n; i++) {
        printf("Square of %d: %d\n", test_cases[i], square(test_cases[i]));
    }
    return 0;
}
