#include <stdio.h>
#include <limits.h>

static int min(int a, int b) { return a < b ? a : b; }

int minimumCost(int n, int w, const int cost[]) {
    int dp[100];
    for (int i = 0; i <= w; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (cost[i - 1] != -1) {
            for (int j = i; j <= w; j++) {
                if (dp[j - i] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - i] + cost[i - 1]);
                }
            }
        }
    }
    return dp[w] == INT_MAX ? -1 : dp[w];
}

int main(void) {
    int cost[] = {20, 10, 4, 50, 100};
    int w = 5;
    printf("Minimum cost to fill bag: %d (expected 14)\n", minimumCost(5, w, cost));
    return 0;
}
