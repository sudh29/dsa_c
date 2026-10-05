#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int findMaxSum(const int arr[], int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    if (n == 2) return arr[0] + arr[1];
    if (n == 3) return max(arr[0] + arr[1], max(arr[1] + arr[2], arr[0] + arr[2]));

    int dp[100] = {0};
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[1], max(arr[1] + arr[2], arr[0] + arr[2]));

    for (int i = 3; i < n; i++) {
        int opt1 = dp[i - 1];
        int opt2 = dp[i - 2] + arr[i];
        int opt3 = dp[i - 3] + arr[i] + arr[i - 1];
        dp[i] = max(opt1, max(opt2, opt3));
    }
    return dp[n - 1];
}

int main(void) {
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max sum without 3 adjacent: %d (expected 2101)\n", findMaxSum(arr, n));
    return 0;
}
