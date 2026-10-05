#include <stdio.h>

long long countWays(int n, int k) {
    const long long MOD = 1000000007;
    if (n == 1) return k;
    if (n == 2) return (1LL * k * k) % MOD;

    long long prev2 = k;
    long long prev1 = (1LL * k * k) % MOD;

    for (int i = 3; i <= n; i++) {
        long long curr = ((k - 1) * ((prev1 + prev2) % MOD)) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(void) {
    printf("Fence ways n=3, k=2: %lld (expected 6)\n", countWays(3, 2));
    printf("Fence ways n=2, k=4: %lld (expected 16)\n", countWays(2, 4));
    return 0;
}
