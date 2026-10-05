#include <stdio.h>
#include <string.h>

static inline int max(int a, int b) { return a > b ? a : b; }

int LongestRepeatingSubsequence(const char *str) {
    int n = (int)strlen(str);
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

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
    const char *s = "axxzxy";
    printf("Longest repeating subsequence length: %d\n", LongestRepeatingSubsequence(s));
    return 0;
}
