#include <stdio.h>

static inline void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void rotateby90(int n, int matrix[n][n]) {
    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
    // Reverse each column for 90 degree anti-clockwise
    for (int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            swap(&matrix[top][j], &matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
}

int main(void) {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateby90(3, mat);
    printf("Rotated 90 deg anti-clockwise [0][0]: %d, [0][2]: %d\n", mat[0][0], mat[0][2]);
    return 0;
}
