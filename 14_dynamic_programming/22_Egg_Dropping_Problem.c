#include <stdio.h>
#include <limits.h>

static int min(int a, int b) { return a < b ? a : b; }
static int max(int a, int b) { return a > b ? a : b; }

int eggDrop(int N, int K) {
    if (N == 1) return K;
    if (K == 0 || K == 1) return K;

    int dp[20][50] = {0};

    for (int i = 1; i <= N; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (int j = 1; j <= K; j++) {
        dp[1][j] = j;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }
    return dp[N][K];
}

int main(void) {
    printf("Egg drop N=2, K=10: %d (expected 4)\n", eggDrop(2, 10));
    printf("Egg drop N=1, K=2: %d (expected 2)\n", eggDrop(1, 2));
    return 0;
}
