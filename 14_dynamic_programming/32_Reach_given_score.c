#include <stdio.h>

long long countWays(int n) {
    long long dp[100] = {0};
    dp[0] = 1;
    int moves[] = {3, 5, 10};

    for (int m = 0; m < 3; m++) {
        int move = moves[m];
        for (int i = move; i <= n; i++) {
            dp[i] += dp[i - move];
        }
    }
    return dp[n];
}

int main(void) {
    printf("Ways to reach 20: %lld (expected 4)\n", countWays(20));
    printf("Ways to reach 13: %lld (expected 2)\n", countWays(13));
    return 0;
}
