#include <stdio.h>

static int min(int a, int b) { return a < b ? a : b; }

int nCr(int n, int r) {
    if (r > n) return 0;
    const int MOD = 1000000007;
    int dp[100] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    return dp[r];
}

int main(void) {
    printf("C(5, 2): %d (expected 10)\n", nCr(5, 2));
    printf("C(3, 2): %d (expected 3)\n", nCr(3, 2));
    return 0;
}
