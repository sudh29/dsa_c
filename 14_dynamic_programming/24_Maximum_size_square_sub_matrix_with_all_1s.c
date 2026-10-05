#include <stdio.h>

static int min(int a, int b) { return a < b ? a : b; }
static int max(int a, int b) { return a > b ? a : b; }

int maxSquare(int n, int m, const int mat[][5]) {
    int dp[10][10] = {0};
    int max_side = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
    }
    return max_side;
}

int main(void) {
    int mat[6][5] = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    printf("Max square side with all 1s: %d (expected 3)\n", maxSquare(6, 5, mat));
    return 0;
}
