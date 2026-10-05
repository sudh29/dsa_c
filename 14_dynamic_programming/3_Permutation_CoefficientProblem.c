#include <stdio.h>

static int min(int a, int b) { return a < b ? a : b; }

long long permutationCoeff(int n, int k) {
    if (k > n) return 0;
    const long long MOD = 1000000007;
    long long dp[100] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = (dp[j] + (1LL * j * dp[j - 1]) % MOD) % MOD;
        }
    }
    return dp[k];
}

int main(void) {
    printf("P(10, 2): %lld (expected 90)\n", permutationCoeff(10, 2));
    printf("P(10, 3): %lld (expected 720)\n", permutationCoeff(10, 3));
    return 0;
}
