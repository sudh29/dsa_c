#include <stdio.h>
#include <stdbool.h>

static int dR[] = {1, 0, 0, -1};
static int dC[] = {0, -1, 1, 0};
static char dName[] = {'D', 'L', 'R', 'U'};

static void solveMaze(int r, int c, int n, int mat[4][4], bool vis[4][4], char path[], int depth) {
    if (r == n - 1 && c == n - 1) {
        path[depth] = '\0';
        printf("%s ", path);
        return;
    }
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dR[i];
        int nc = c + dC[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && mat[nr][nc] == 1 && !vis[nr][nc]) {
            path[depth] = dName[i];
            solveMaze(nr, nc, n, mat, vis, path, depth + 1);
        }
    }
    vis[r][c] = false;
}

int main(void) {
    int mat[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    bool vis[4][4] = {{false}};
    char path[32];

    printf("Rat in a maze paths: ");
    if (mat[0][0] == 1) {
        solveMaze(0, 0, n, mat, vis, path, 0);
    }
    printf("\n");
    return 0;
}
