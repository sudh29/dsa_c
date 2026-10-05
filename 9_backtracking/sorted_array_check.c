#include <stdio.h>
#include <stdbool.h>

bool isSorted(const int A[], int n, int idx) {
    if (idx >= n - 1) return true;
    if (A[idx] > A[idx + 1]) return false;
    return isSorted(A, n, idx + 1);
}

int main(void) {
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    printf("Array A sorted: %s\n", isSorted(A, 7, 0) ? "true" : "false");

    int B[] = {1, 5, 671, 1, 6, 3, 2, 0};
    printf("Array B sorted: %s\n", isSorted(B, 8, 0) ? "true" : "false");
    return 0;
}
