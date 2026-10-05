#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

static inline int max(int a, int b) { return a > b ? a : b; }

int findLongestConseqSubseq(int arr[], int N) {
    if (N <= 0) return 0;
    qsort(arr, N, sizeof(int), cmp_int);

    int ans = 1, count = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i - 1]) continue;
        if (arr[i] == arr[i - 1] + 1) {
            count++;
        } else {
            ans = max(ans, count);
            count = 1;
        }
    }
    return max(ans, count);
}

int main(void) {
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Longest consecutive subsequence length: %d\n", findLongestConseqSubseq(arr, n));
    return 0;
}
