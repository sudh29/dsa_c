#include <stdio.h>

long long countWays(const int coins[], int n, int sum) {
    long long dp[100] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int coin = coins[i];
        for (int amount = coin; amount <= sum; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }
    return dp[sum];
}

int main(void) {
    int coins[] = {1, 2, 3};
    int sum = 4;
    printf("Ways to make change for 4: %lld (expected 4)\n", countWays(coins, 3, sum));
    return 0;
}
