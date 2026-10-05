#include <stdio.h>
#include <string.h>

static inline int max(int a, int b) { return a > b ? a : b; }

int lcs(int x, int y, const char *s1, const char *s2) {
    int dp[x + 1][y + 1];
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}

int main(void) {
    const char *s1 = "ABCDGH", *s2 = "AEDFHR";
    printf("LCS length: %d\n", lcs((int)strlen(s1), (int)strlen(s2), s1, s2));
    return 0;
}
