#include <stdio.h>

int rowWithMax1s(int n, int m, const int arr[n][m]) {
    int max_row_idx = -1;
    int j = m - 1;

    for (int i = 0; i < n; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            max_row_idx = i;
        }
    }
    return max_row_idx;
}

int main(void) {
    int arr[4][4] = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    printf("Row with max 1s: %d\n", rowWithMax1s(4, 4, arr));
    return 0;
}
