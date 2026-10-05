#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int maximizeTheCuts(int n, int x, int y, int z) {
    int dp[100];
    for (int i = 0; i <= n; i++) dp[i] = -1;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i >= x && dp[i - x] != -1) dp[i] = max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1) dp[i] = max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1) dp[i] = max(dp[i], dp[i - z] + 1);
    }
    return max(dp[n], 0);
}

int main(void) {
    printf("Max cuts for n=4, cuts=(2,1,1): %d (expected 4)\n", maximizeTheCuts(4, 2, 1, 1));
    printf("Max cuts for n=5, cuts=(5,3,2): %d (expected 2)\n", maximizeTheCuts(5, 5, 3, 2));
    return 0;
}
