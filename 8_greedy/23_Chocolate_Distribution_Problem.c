#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int cmp_ll(const void *a, const void *b) {
    long long ia = *(const long long*)a;
    long long ib = *(const long long*)b;
    return (ia > ib) - (ia < ib);
}

static inline long long min_ll(long long a, long long b) { return a < b ? a : b; }

long long findMinDiff(long long a[], int n, int m) {
    if (m == 0 || n == 0 || m > n) return 0;
    qsort(a, n, sizeof(long long), cmp_ll);
    long long min_diff = LLONG_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
        long long diff = a[i + m - 1] - a[i];
        min_diff = min_ll(min_diff, diff);
    }
    return min_diff;
}

int main(void) {
    long long A[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int M = 5;
    printf("Min chocolate diff: %lld (expected 6)\n", findMinDiff(A, 8, M));
    return 0;
}
