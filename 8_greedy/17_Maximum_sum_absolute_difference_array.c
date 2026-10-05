#include <stdio.h>
#include <stdlib.h>

long long maxSumPermutation(long long N) {
    return (N * (N - 1)) / 2;
}

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int maxConsecutiveDiffSum(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp_int);
    int temp[n];
    int l = 0, r = n - 1, idx = 0;
    while (l <= r) {
        temp[idx++] = arr[l++];
        if (l <= r) temp[idx++] = arr[r--];
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += abs(temp[i] - temp[i + 1]);
    }
    sum += abs(temp[n - 1] - temp[0]);
    return sum;
}

int main(void) {
    printf("Max sum for permutation 1..N (N=4): %lld\n", maxSumPermutation(4));
    int arr[] = {1, 2, 4, 8};
    printf("Max sum absolute diff (array {1, 2, 4, 8}): %d\n", maxConsecutiveDiffSum(arr, 4));
    return 0;
}
