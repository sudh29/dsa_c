#include <stdio.h>
#include <stdbool.h>

static int rowNum[] = {-1, 1, 0, 0};
static int colNum[] = {0, 0, -1, 1};

static inline int max(int a, int b) { return a > b ? a : b; }

static void findLongestPath(int n, int m, int mat[n][m], bool visited[n][m], int i, int j, int dest_x, int dest_y, int dist, int *max_dist) {
    if (i == dest_x && j == dest_y) {
        *max_dist = max(*max_dist, dist);
        return;
    }

    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int r = i + rowNum[k], c = j + colNum[k];
        if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 1 && !visited[r][c]) {
            findLongestPath(n, m, mat, visited, r, c, dest_x, dest_y, dist + 1, max_dist);
        }
    }
    visited[i][j] = false;
}

int main(void) {
    int mat[3][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    bool visited[3][10] = {{false}};
    int max_dist = -1;

    findLongestPath(3, 10, mat, visited, 0, 0, 1, 7, 0, &max_dist);
    printf("Longest path length: %d (expected 24)\n", max_dist);
    return 0;
}
