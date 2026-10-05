#include <stdio.h>

void dfs(char grid[][10], int r, int c, int n, int m) {
    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != '1') return;

    grid[r][c] = '0'; // mark visited

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int d = 0; d < 8; d++) {
        dfs(grid, r + dr[d], c + dc[d], n, m);
    }
}

int numIslands(char grid[][10], int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, n, m);
            }
        }
    }
    return count;
}

int main(void) {
    char grid[2][10] = {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

    printf("Number of islands (8-connected): %d (expected 2)\n", numIslands(grid, 2, 7));
    return 0;
}
