#include <stdio.h>
#include <stdlib.h>

// Count unique paths from top-left to bottom-right in an m x n grid
int unique_paths(int m, int n) {
    if (m <= 0 || n <= 0) return 0;
    int *dp = (int*)malloc(n * sizeof(int));
    if (!dp) return 0;
    for (int j = 0; j < n; j++) dp[j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    int result = dp[n - 1];
    free(dp);
    return result;
}

int main(void) {
    printf("=== Unique Grid Paths (Dynamic Programming in C) ===\n");
    int m = 3, n = 7;
    printf("Grid %dx%d unique paths: %d\n", m, n, unique_paths(m, n));
    return 0;
}
