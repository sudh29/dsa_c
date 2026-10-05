#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void *a, const void *b) {
    long long ia = *(const long long*)a;
    long long ib = *(const long long*)b;
    return (ia > ib) - (ia < ib);
}

long long countTriplets(long long arr[], int n, long long sum) {
    qsort(arr, n, sizeof(long long), cmp_ll);
    long long count = 0;
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            if (arr[i] + arr[j] + arr[k] < sum) {
                count += (k - j);
                j++;
            } else {
                k--;
            }
        }
    }
    return count;
}

int main(void) {
    long long arr[] = {-2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long sum = 2;
    printf("Triplets with sum < %lld: %lld\n", sum, countTriplets(arr, n, sum));
    return 0;
}
