#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

const char* isSubset(int a1[], int a2[], int n, int m) {
    qsort(a1, n, sizeof(int), cmp_int);
    qsort(a2, m, sizeof(int), cmp_int);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a1[i] < a2[j]) {
            i++;
        } else if (a1[i] == a2[j]) {
            i++;
            j++;
        } else {
            return "No";
        }
    }
    return (j == m) ? "Yes" : "No";
}

int main(void) {
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};
    printf("Is a2 subset of a1: %s\n", isSubset(a1, a2, 6, 4));
    return 0;
}
