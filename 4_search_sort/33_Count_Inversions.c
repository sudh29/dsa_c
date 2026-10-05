#include <stdio.h>
#include <stdlib.h>

static long long merge(long long arr[], long long l, long long m, long long r) {
    long long ci = 0;
    long long i = l, j = m + 1, k = 0;
    long long *temp = (long long*)malloc((r - l + 1) * sizeof(long long));
    if (!temp) return 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            ci += (m - i + 1);
        }
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (long long p = 0; p < k; p++) arr[l + p] = temp[p];
    free(temp);
    return ci;
}

static long long mergesort(long long arr[], long long low, long long high) {
    long long ci = 0;
    if (low < high) {
        long long mid = low + (high - low) / 2;
        ci += mergesort(arr, low, mid);
        ci += mergesort(arr, mid + 1, high);
        ci += merge(arr, low, mid, high);
    }
    return ci;
}

long long inversionCount(long long arr[], long long N) {
    return mergesort(arr, 0, N - 1);
}

int main(void) {
    long long arr[] = {2, 4, 1, 3, 5};
    long long n = sizeof(arr) / sizeof(arr[0]);
    printf("Inversion count: %lld\n", inversionCount(arr, n));
    return 0;
}
