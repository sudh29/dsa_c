#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

bool find3Numbers(int A[], int n, int X) {
    qsort(A, n, sizeof(int), cmp_int);
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = A[i] + A[l] + A[r];
            if (sum == X) return true;
            if (sum < X) l++;
            else r--;
        }
    }
    return false;
}

int main(void) {
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 13;
    printf("Triplet sum equal to %d: %s\n", x, find3Numbers(A, n, x) ? "Found" : "Not Found");
    return 0;
}
