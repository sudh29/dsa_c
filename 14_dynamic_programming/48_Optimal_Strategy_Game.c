#include <stdio.h>

static long long minLL(long long a, long long b) { return a < b ? a : b; }
static long long maxLL(long long a, long long b) { return a > b ? a : b; }

long long optimalStrategyOfGame(int n, const int arr[]) {
    long long dp[50][50] = {0};

    for (int i = 0; i < n; i++) dp[i][i] = arr[i];
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = maxLL(arr[i], arr[i + 1]);

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            long long take_i = arr[i] + minLL(dp[i + 2][j], dp[i + 1][j - 1]);
            long long take_j = arr[j] + minLL(dp[i + 1][j - 1], dp[i][j - 2]);
            dp[i][j] = maxLL(take_i, take_j);
        }
    }
    return dp[0][n - 1];
}

int main(void) {
    int arr[] = {5, 3, 7, 10};
    printf("Optimal game score: %lld (expected 15)\n", optimalStrategyOfGame(4, arr));
    return 0;
}
