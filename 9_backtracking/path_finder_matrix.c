#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int r;
    int c;
} Point;

static bool findPath(int n, int matrix[n][n], int r, int c, Point path[], int *depth) {
    if (r == n - 1 && c == n - 1) {
        path[(*depth)++] = (Point){r, c};
        return true;
    }
    if (r >= 0 && r < n && c >= 0 && c < n && matrix[r][c] == 1) {
        path[(*depth)++] = (Point){r, c};
        if (findPath(n, matrix, r + 1, c, path, depth)) return true;
        if (findPath(n, matrix, r, c + 1, path, depth)) return true;
        (*depth)--;
    }
    return false;
}

int main(void) {
    int matrix[5][5] = {
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    Point path[32];
    int depth = 0;

    if (matrix[0][0] == 1 && findPath(5, matrix, 0, 0, path, &depth)) {
        printf("Path found: ");
        for (int i = 0; i < depth; i++) {
            printf("(%d, %d) ", path[i].r, path[i].c);
        }
        printf("\n");
    } else {
        printf("No path exists\n");
    }
    return 0;
}
