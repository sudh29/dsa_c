#include <stdio.h>
#include <string.h>

static int max(int a, int b) { return a > b ? a : b; }

int longestCommonSubstr(const char *str1, const char *str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int dp[50][50] = {0};
    int max_len = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_len = max(max_len, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return max_len;
}

int main(void) {
    const char *s1 = "ABCDGH";
    const char *s2 = "ACDGHR";
    printf("Longest common substring: %d (expected 4)\n", longestCommonSubstr(s1, s2));
    return 0;
}
