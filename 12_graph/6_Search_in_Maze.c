#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 10
#define MAX_PATHS 20
#define PATH_LEN 50

static char allPaths[MAX_PATHS][PATH_LEN];
static int pathCount = 0;

void dfs(const int m[][MAX_N], int n, char curr[], int currLen, int r, int c, bool visited[][MAX_N]) {
    if (r < 0 || c < 0 || r >= n || c >= n) return;
    if (m[r][c] == 0 || visited[r][c]) return;

    if (r == n - 1 && c == n - 1) {
        curr[currLen] = '\0';
        if (pathCount < MAX_PATHS) {
            snprintf(allPaths[pathCount++], PATH_LEN, "%s", curr);
        }
        return;
    }

    visited[r][c] = true;

    // D, L, R, U (lexicographic order)
    curr[currLen] = 'D'; dfs(m, n, curr, currLen + 1, r + 1, c, visited);
    curr[currLen] = 'L'; dfs(m, n, curr, currLen + 1, r, c - 1, visited);
    curr[currLen] = 'R'; dfs(m, n, curr, currLen + 1, r, c + 1, visited);
    curr[currLen] = 'U'; dfs(m, n, curr, currLen + 1, r - 1, c, visited);

    visited[r][c] = false;
}

int main(void) {
    int m[MAX_N][MAX_N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    bool visited[MAX_N][MAX_N] = {false};
    char curr[PATH_LEN];
    pathCount = 0;

    dfs(m, 4, curr, 0, 0, 0, visited);

    printf("Paths in maze: ");
    for (int i = 0; i < pathCount; i++) {
        printf("%s ", allPaths[i]);
    }
    printf("\n");
    return 0;
}
