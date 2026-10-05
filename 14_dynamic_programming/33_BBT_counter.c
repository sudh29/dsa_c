#include <stdio.h>

long long countBT(int h) {
    const long long MOD = 1000000007;
    if (h == 0 || h == 1) return 1;

    long long dp[50] = {0};
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= h; i++) {
        dp[i] = ((dp[i - 1] * dp[i - 1]) % MOD + (2LL * dp[i - 1] * dp[i - 2]) % MOD) % MOD;
    }
    return dp[h];
}

int main(void) {
    printf("Balanced binary trees of height 2: %lld (expected 3)\n", countBT(2));
    printf("Balanced binary trees of height 3: %lld (expected 15)\n", countBT(3));
    return 0;
}
