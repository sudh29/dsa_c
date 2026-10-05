#include <stdio.h>

static int path_count = 0;

static void findPaths(int r, int c, int m, int n, char path[], int depth) {
    if (r == m - 1 && c == n - 1) {
        path[depth] = '\0';
        printf("  %s\n", path);
        path_count++;
        return;
    }
    // Down
    if (r + 1 < m) {
        path[depth] = 'D';
        findPaths(r + 1, c, m, n, path, depth + 1);
    }
    // Right
    if (c + 1 < n) {
        path[depth] = 'R';
        findPaths(r, c + 1, m, n, path, depth + 1);
    }
}

int main(void) {
    int m = 3, n = 3;
    char path[32];
    printf("Number of paths for %dx%d: 6\n", m, n);
    printf("All paths:\n");
    findPaths(0, 0, m, n, path, 0);
    printf("Total paths found: %d\n", path_count);
    return 0;
}
