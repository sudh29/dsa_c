#include <stdio.h>

void kthPermutation(int n, int k, char *out, size_t out_sz) {
    int fact = 1;
    int numbers[n];
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers[i - 1] = i;
    }
    numbers[n - 1] = n;
    k = k - 1;

    int num_left = n;
    int idx = 0;

    while (1) {
        int pos = k / fact;
        idx += snprintf(out + idx, out_sz - idx, "%d", numbers[pos]);
        for (int i = pos; i < num_left - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
        num_left--;
        if (num_left == 0) break;
        k = k % fact;
        fact = fact / num_left;
    }
}

int main(void) {
    char res1[16], res2[16];
    kthPermutation(3, 3, res1, sizeof(res1));
    printf("3rd permutation of N=3: %s (expected 213)\n", res1);
    kthPermutation(4, 4, res2, sizeof(res2));
    printf("4th permutation of N=4: %s (expected 1342)\n", res2);
    return 0;
}
