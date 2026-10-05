#include <stdio.h>
#include <limits.h>

static int max(int a, int b) { return a > b ? a : b; }

int kadane(const int arr[], int n) {
    int max_so_far = arr[0];
    int curr = arr[0];
    for (int i = 1; i < n; i++) {
        curr = max(arr[i], curr + arr[i]);
        max_so_far = max(max_so_far, curr);
    }
    return max_so_far;
}

int maximumSumRectangle(int R, int C, const int M[][5]) {
    int max_sum = INT_MIN;

    for (int top = 0; top < R; top++) {
        int temp[50] = {0};
        for (int bottom = top; bottom < R; bottom++) {
            for (int i = 0; i < C; i++) {
                temp[i] += M[bottom][i];
            }
            max_sum = max(max_sum, kadane(temp, C));
        }
    }
    return max_sum;
}

int main(void) {
    int mat[4][5] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    printf("Max sum rectangle: %d (expected 29)\n", maximumSumRectangle(4, 5, mat));
    return 0;
}
