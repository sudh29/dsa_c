#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long countPS(const char *str) {
    int N = (int)strlen(str);
    long long dp[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) dp[i][i] = 1;

    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N - L; i++) {
            int j = i + L - 1;
            if (str[i] == str[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }
    return dp[0][N - 1];
}

int main(void) {
    const char *s = "abcd";
    printf("Palindromic subsequences in '%s': %lld\n", s, countPS(s));
    return 0;
}
