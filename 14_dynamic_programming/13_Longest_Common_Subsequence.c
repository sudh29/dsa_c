#include <stdio.h>
#include <string.h>

static int max(int a, int b) { return a > b ? a : b; }

int lcs(const char *s1, const char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int dp[50][50] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main(void) {
    const char *s1 = "ABCDGH";
    const char *s2 = "AEDFHR";
    printf("LCS length: %d (expected 3)\n", lcs(s1, s2));
    return 0;
}
