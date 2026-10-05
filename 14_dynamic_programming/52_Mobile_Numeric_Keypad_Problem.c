#include <stdio.h>

long long getCount(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 10;

    int moves[10][6] = {
        {0, 8, -1},                // 0
        {1, 2, 4, -1},             // 1
        {2, 1, 3, 5, -1},          // 2
        {3, 2, 6, -1},             // 3
        {4, 1, 5, 7, -1},          // 4
        {5, 2, 4, 6, 8, -1},       // 5
        {6, 3, 5, 9, -1},          // 6
        {7, 4, 8, -1},             // 7
        {8, 5, 7, 9, 0, -1},       // 8
        {9, 6, 8, -1}              // 9
    };

    long long dp[50][10] = {0};
    for (int j = 0; j < 10; j++) dp[1][j] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int m = 0; moves[j][m] != -1; m++) {
                int k = moves[j][m];
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    long long total = 0;
    for (int j = 0; j < 10; j++) total += dp[n][j];
    return total;
}

int main(void) {
    printf("Keypad count n=1: %lld (expected 10)\n", getCount(1));
    printf("Keypad count n=2: %lld (expected 36)\n", getCount(2));
    return 0;
}
