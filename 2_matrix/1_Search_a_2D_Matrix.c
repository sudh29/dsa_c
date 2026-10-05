#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int m, int n, const int mat[m][n], int target) {
    if (m <= 0 || n <= 0) return false;
    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / n, c = mid % n;
        if (mat[r][c] == target) return true;
        if (mat[r][c] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main(void) {
    int mat[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    printf("Search %d: %s\n", target, searchMatrix(3, 4, mat, target) ? "Found" : "Not Found");
    return 0;
}
