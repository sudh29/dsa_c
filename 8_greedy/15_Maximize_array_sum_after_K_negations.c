#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int cmp_ll(const void *a, const void *b) {
    long long ia = *(const long long*)a;
    long long ib = *(const long long*)b;
    return (ia > ib) - (ia < ib);
}

long long maximizeSum(long long a[], int n, int k) {
    qsort(a, n, sizeof(long long), cmp_ll);
    for (int i = 0; i < n && k > 0; i++) {
        if (a[i] < 0) {
            a[i] = -a[i];
            k--;
        }
    }
    long long sum = 0;
    long long min_val = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] < min_val) min_val = a[i];
    }
    if (k % 2 != 0) {
        sum -= 2 * min_val;
    }
    return sum;
}

int main(void) {
    long long arr1[] = {-2, -3, 4, 1};
    printf("Max sum after k=2: %lld (expected 10)\n", maximizeSum(arr1, 4, 2));

    long long arr2[] = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20};
    printf("Max sum after k=5: %lld (expected 68)\n", maximizeSum(arr2, 10, 5));
    return 0;
}
