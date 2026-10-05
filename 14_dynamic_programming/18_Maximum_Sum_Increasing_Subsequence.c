#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int maxSumIS(const int arr[], int n) {
    int dp[100];
    for (int i = 0; i < n; i++) dp[i] = arr[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    int max_sum = 0;
    for (int i = 0; i < n; i++) max_sum = max(max_sum, dp[i]);
    return max_sum;
}

int main(void) {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max Sum Increasing Subsequence: %d (expected 106)\n", maxSumIS(arr, n));
    return 0;
}
