#include <stdio.h>
#include <string.h>

static int max(int a, int b) { return a > b ? a : b; }

int longestRepeatedSubsequence(const char *str) {
    int n = strlen(str);
    int dp[50][50] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main(void) {
    const char *s = "axxxxy";
    printf("LRS length of 'axxxxy': %d (expected 2)\n", longestRepeatedSubsequence(s));
    return 0;
}
