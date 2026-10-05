#include <stdio.h>
#include <string.h>

static int max(int a, int b) { return a > b ? a : b; }

int lcsSpaceOptimized(const char *X, const char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[2][100] = {0};

    for (int i = 1; i <= m; i++) {
        int curr = i % 2;
        int prev = 1 - curr;
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[curr][j] = dp[prev][j - 1] + 1;
            } else {
                dp[curr][j] = max(dp[prev][j], dp[curr][j - 1]);
            }
        }
    }
    return dp[m % 2][n];
}

int main(void) {
    const char *s1 = "AGGTAB";
    const char *s2 = "GXTXAYB";
    printf("Space-optimized LCS: %d (expected 4)\n", lcsSpaceOptimized(s1, s2));
    return 0;
}
