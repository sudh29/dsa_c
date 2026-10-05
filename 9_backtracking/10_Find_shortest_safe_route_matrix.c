#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define R 4
#define C 5

static int rowNum[] = {-1, 1, 0, 0};
static int colNum[] = {0, 0, -1, 1};

static inline int min(int a, int b) { return a < b ? a : b; }

static void findShortestPathUtil(int mat[R][C], bool visited[R][C], int i, int j, int dist, int *min_dist) {
    if (j == C - 1) {
        *min_dist = min(*min_dist, dist);
        return;
    }
    if (dist >= *min_dist) return;

    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int r = i + rowNum[k], c = j + colNum[k];
        if (r >= 0 && r < R && c >= 0 && c < C && mat[r][c] == 1 && !visited[r][c]) {
            findShortestPathUtil(mat, visited, r, c, dist + 1, min_dist);
        }
    }
    visited[i][j] = false;
}

int findShortestPath(int mat[R][C]) {
    // Mark adjacent cells of 0 as unsafe
    int safe[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) safe[i][j] = mat[i][j];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int r = i + rowNum[k], c = j + colNum[k];
                    if (r >= 0 && r < R && c >= 0 && c < C) safe[r][c] = 0;
                }
            }
        }
    }

    int min_dist = INT_MAX;
    bool visited[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) visited[i][j] = false;
    }

    for (int i = 0; i < R; i++) {
        if (safe[i][0] == 1) {
            findShortestPathUtil(safe, visited, i, 0, 1, &min_dist);
        }
    }
    return (min_dist == INT_MAX) ? -1 : min_dist;
}

int main(void) {
    int mat[R][C] = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    printf("Shortest safe path length: %d\n", findShortestPath(mat));
    return 0;
}
