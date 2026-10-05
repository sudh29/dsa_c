#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isInterleave(const char *A, const char *B, const char *C) {
    int n = strlen(A);
    int m = strlen(B);
    int l = strlen(C);
    if (n + m != l) return false;

    bool dp[50][50] = {false};
    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] && (B[j - 1] == C[j - 1]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] && (A[i - 1] == C[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] && A[i - 1] == C[i + j - 1]) ||
                       (dp[i][j - 1] && B[j - 1] == C[i + j - 1]);
        }
    }
    return dp[n][m];
}

int main(void) {
    const char *A = "aabcc", *B = "dbbca", *C = "aadbbcbcac";
    printf("Is interleaved: %s (expected YES)\n", isInterleave(A, B, C) ? "YES" : "NO");
    printf("Is interleaved: %s (expected NO)\n", isInterleave("aabcc", "dbbca", "aadbbbaccc") ? "YES" : "NO");
    return 0;
}
