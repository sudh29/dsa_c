#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int knapSack(int W, const int wt[], const int val[], int n) {
    int dp[100] = {0};

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main(void) {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    printf("Max 0-1 Knapsack value: %d (expected 220)\n", knapSack(W, wt, val, 3));
    return 0;
}
