#include <stdio.h>
#include <stdlib.h>

static int compareAsc(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b);
}

static int max(int a, int b) { return a > b ? a : b; }

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
    qsort(arr, N, sizeof(int), compareAsc);
    int dp[100] = {0};

    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (arr[i] - arr[i - 1] < K) {
            int prev = (i >= 2) ? dp[i - 2] : 0;
            dp[i] = max(dp[i], prev + arr[i] + arr[i - 1]);
        }
    }
    return dp[N - 1];
}

int main(void) {
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
    printf("Max sum pair diff < %d: %d (expected 62)\n",
           K, maxSumPairWithDifferenceLessThanK(arr, n, K));
    return 0;
}
