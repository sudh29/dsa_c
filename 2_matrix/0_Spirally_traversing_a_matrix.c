#include <stdio.h>
#include <stdlib.h>

void spirallyTraverse(int r, int c, const int mat[r][c], int *out, int *out_len) {
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int idx = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) out[idx++] = mat[top][i];
        top++;

        for (int i = top; i <= bottom; i++) out[idx++] = mat[i][right];
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) out[idx++] = mat[bottom][i];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) out[idx++] = mat[i][left];
            left++;
        }
    }
    *out_len = idx;
}

int main(void) {
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int res[16];
    int len = 0;
    spirallyTraverse(4, 4, mat, res, &len);

    printf("Spiral traversal: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
