#include <stdio.h>
#include <string.h>

static int max(int a, int b) { return a > b ? a : b; }

int longestPalinSubseq(const char *S) {
    int n = strlen(S);
    int dp[50][50] = {0};

    for (int i = 0; i < n; i++) dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (S[i] == S[j]) {
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main(void) {
    const char *s = "bbabcbcab";
    printf("LPS length of 'bbabcbcab': %d (expected 7)\n", longestPalinSubseq(s));
    return 0;
}
