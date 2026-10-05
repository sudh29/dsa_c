#include <stdio.h>
#include <string.h>

static int max(int a, int b) { return a > b ? a : b; }

int LCSof3(const char *A, const char *B, const char *C) {
    int n1 = strlen(A);
    int n2 = strlen(B);
    int n3 = strlen(C);
    int dp[30][30][30] = {0};

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            for (int k = 1; k <= n3; k++) {
                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

int main(void) {
    const char *s1 = "geeks";
    const char *s2 = "geeksfor";
    const char *s3 = "geeksforgeeks";
    printf("LCS of 3 strings: %d (expected 5)\n", LCSof3(s1, s2, s3));
    return 0;
}
