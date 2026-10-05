#include <stdio.h>
#include <limits.h>

int matrixMultiplication(int N, const int arr[]) {
    int dp[50][50] = {0};

    for (int l = 2; l < N; l++) {
        for (int i = 1; i < N - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][N - 1];
}

int main(void) {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Min matrix mult operations: %d (expected 26000)\n", matrixMultiplication(n, arr));
    return 0;
}
