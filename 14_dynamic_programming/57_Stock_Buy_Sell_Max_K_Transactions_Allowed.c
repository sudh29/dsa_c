#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int K, int N, const int A[]) {
    if (N <= 1 || K == 0) return 0;

    int dp[10][50] = {0};

    for (int t = 1; t <= K; t++) {
        int max_diff = -A[0];
        for (int d = 1; d < N; d++) {
            dp[t][d] = max(dp[t][d - 1], A[d] + max_diff);
            max_diff = max(max_diff, dp[t - 1][d] - A[d]);
        }
    }
    return dp[K][N - 1];
}

int main(void) {
    int A[] = {10, 22, 5, 75, 65, 80};
    int K = 2;
    printf("Max profit with K=2: %d (expected 87)\n", maxProfit(K, 6, A));
    return 0;
}
