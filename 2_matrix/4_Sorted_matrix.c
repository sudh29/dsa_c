#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void sortedMatrix(int n, int mat[n][n]) {
    int total = n * n;
    int *temp = (int*)malloc(total * sizeof(int));
    if (!temp) return;

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[k++] = mat[i][j];
        }
    }

    qsort(temp, total, sizeof(int), cmp_int);

    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = temp[k++];
        }
    }
    free(temp);
}

int main(void) {
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    sortedMatrix(4, mat);
    printf("Sorted Matrix [0][0]: %d, [3][3]: %d\n", mat[0][0], mat[3][3]);
    return 0;
}
