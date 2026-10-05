#include <stdio.h>
#include <string.h>

long long countPS(const char *str) {
    int n = strlen(str);
    const long long MOD = 1000000007;
    long long dp[50][50] = {0};

    for (int i = 0; i < n; i++) dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }
    return dp[0][n - 1];
}

int main(void) {
    printf("Count PS of 'abcd': %lld (expected 4)\n", countPS("abcd"));
    printf("Count PS of 'aab': %lld (expected 4)\n", countPS("aab"));
    return 0;
}
