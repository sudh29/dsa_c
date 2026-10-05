#include <stdio.h>

void dfs(int image[][3], int r, int c, int n, int m, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= n || c >= m) return;
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, n, m, oldColor, newColor);
    dfs(image, r - 1, c, n, m, oldColor, newColor);
    dfs(image, r, c + 1, n, m, oldColor, newColor);
    dfs(image, r, c - 1, n, m, oldColor, newColor);
}

void floodFill(int image[][3], int n, int m, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor != newColor) {
        dfs(image, sr, sc, n, m, oldColor, newColor);
    }
}

int main(void) {
    int image[3][3] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    floodFill(image, 3, 3, 1, 1, 2);

    printf("Flood Fill result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}
