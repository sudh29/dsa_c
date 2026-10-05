#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

long long findMaxProduct(const int a[], int n) {
    if (n == 1) return a[0];

    int neg_count = 0, zero_count = 0;
    int max_neg = INT_MIN;
    long long prod = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zero_count++;
            continue;
        }
        if (a[i] < 0) {
            neg_count++;
            if (a[i] > max_neg) max_neg = a[i];
        }
        prod = (prod * a[i]) % MOD;
    }

    if (zero_count == n) return 0;
    if (neg_count == 1 && zero_count + neg_count == n) return 0;

    if (neg_count % 2 != 0) {
        prod = (prod / max_neg);
    }
    return (prod % MOD + MOD) % MOD;
}

int main(void) {
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Max product subset: %lld\n", findMaxProduct(a, n));
    return 0;
}
