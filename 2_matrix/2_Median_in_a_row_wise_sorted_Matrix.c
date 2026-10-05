#include <stdio.h>

static int upper_bound(const int *row, int n, int mid) {
    int low = 0, high = n;
    while (low < high) {
        int m = low + (high - low) / 2;
        if (row[m] <= mid) {
            low = m + 1;
        } else {
            high = m;
        }
    }
    return low;
}

int median(int r, int c, const int matrix[r][c]) {
    int low = 1, high = 1000000000;
    int desired = (r * c + 1) / 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < r; i++) {
            count += upper_bound(matrix[i], c, mid);
        }
        if (count < desired) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main(void) {
    int mat[3][3] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    printf("Median in row-wise sorted matrix: %d\n", median(3, 3, mat));
    return 0;
}
