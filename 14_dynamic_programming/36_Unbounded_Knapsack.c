#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int knapSackUnbounded(int N, int W, const int val[], const int wt[]) {
    int dp[100] = {0};

    for (int i = 0; i < N; i++) {
        for (int w = wt[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main(void) {
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int W = 8;
    printf("Unbounded knapsack max val: %d (expected 11)\n", knapSackUnbounded(4, W, val, wt));
    return 0;
}
