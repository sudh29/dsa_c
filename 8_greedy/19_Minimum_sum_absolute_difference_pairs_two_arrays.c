#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void *a, const void *b) {
    long long ia = *(const long long*)a;
    long long ib = *(const long long*)b;
    return (ia > ib) - (ia < ib);
}

long long findMinSum(long long A[], long long B[], int n) {
    qsort(A, n, sizeof(long long), cmp_ll);
    qsort(B, n, sizeof(long long), cmp_ll);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += llabs(A[i] - B[i]);
    }
    return sum;
}

int main(void) {
    long long A[] = {4, 1, 8, 7};
    long long B[] = {2, 3, 6, 5};
    printf("Min sum abs diff: %lld (expected 6)\n", findMinSum(A, B, 4));
    return 0;
}
