#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxHistArea(const int *hist, int n) {
    int *stack = (int*)malloc((n + 1) * sizeof(int));
    if (!stack) return 0;
    int top = -1;
    int max_area = 0;

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : hist[i];
        while (top >= 0 && hist[stack[top]] >= h) {
            int height = hist[stack[top--]];
            int width = (top < 0) ? i : i - stack[top] - 1;
            max_area = max(max_area, height * width);
        }
        stack[++top] = i;
    }
    free(stack);
    return max_area;
}

int maxRectangle(int r, int c, const int mat[r][c]) {
    if (r <= 0 || c <= 0) return 0;
    int *hist = (int*)calloc(c, sizeof(int));
    if (!hist) return 0;
    int max_area = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            hist[j] = (mat[i][j] == 0) ? 0 : hist[j] + 1;
        }
        max_area = max(max_area, maxHistArea(hist, c));
    }
    free(hist);
    return max_area;
}

int main(void) {
    int mat[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    printf("Max rectangle area: %d\n", maxRectangle(4, 4, mat));
    return 0;
}
