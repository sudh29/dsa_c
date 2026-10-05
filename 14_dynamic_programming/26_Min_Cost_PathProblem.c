#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int maximumPath(int n, const int mat[][2]) {
    int dp[10][10];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            dp[r][c] = mat[r][c];

    for (int r = 1; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int left_up = (c > 0) ? dp[r - 1][c - 1] : 0;
            int up = dp[r - 1][c];
            int right_up = (c < n - 1) ? dp[r - 1][c + 1] : 0;
            dp[r][c] += max(left_up, max(up, right_up));
        }
    }
    int max_val = 0;
    for (int c = 0; c < n; c++) {
        max_val = max(max_val, dp[n - 1][c]);
    }
    return max_val;
}

int main(void) {
    int mat[2][2] = {
        {348, 391},
        {618, 420}
    };
    printf("Max path sum: %d (expected 1009)\n", maximumPath(2, mat));
    return 0;
}
