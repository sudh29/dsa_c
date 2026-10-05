#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

long long maxSum(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp_int);
    long long sum = 0;
    for (int i = 0; i < n / 2; i++) {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - 1 - i]);
    }
    return sum;
}

int main(void) {
    int arr[] = {4, 2, 1, 8};
    printf("Max sum circular diff: %lld (expected 18)\n", maxSum(arr, 4));
    return 0;
}
