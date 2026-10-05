#include <stdio.h>

void factorial(int N) {
    int res[5000];
    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= N; x++) {
        int carry = 0;
        for (int i = 0; i < res_size; i++) {
            int prod = res[i] * x + carry;
            res[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            res[res_size++] = carry % 10;
            carry /= 10;
        }
    }

    printf("%d! = ", N);
    for (int i = res_size - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 10;
    factorial(n);
    return 0;
}
