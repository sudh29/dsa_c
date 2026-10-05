#include <stdio.h>

long long countFriendsPairings(int n) {
    const long long MOD = 1000000007;
    if (n <= 1) return 1;
    if (n == 2) return 2;

    long long prev2 = 1;
    long long prev1 = 2;

    for (int i = 3; i <= n; i++) {
        long long curr = (prev1 + (1LL * (i - 1) * prev2) % MOD) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(void) {
    printf("Friends pairing for 3: %lld (expected 4)\n", countFriendsPairings(3));
    printf("Friends pairing for 4: %lld (expected 10)\n", countFriendsPairings(4));
    return 0;
}
