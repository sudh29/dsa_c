#include <stdio.h>

long long findCatalan(int N) {
    const long long MOD = 1000000007;
    long long dp[100] = {0};
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % MOD) % MOD;
        }
    }
    return dp[N];
}

int main(void) {
    printf("Catalan(5): %lld (expected 42)\n", findCatalan(5));
    printf("Catalan(4): %lld (expected 14)\n", findCatalan(4));
    return 0;
}
