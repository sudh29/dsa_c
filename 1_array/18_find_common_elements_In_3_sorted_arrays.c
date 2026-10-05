#include <stdio.h>

void commonElements(const int A[], const int B[], const int C[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0;
    int last = -1;
    int first = 1;

    printf("Common in 3 sorted arrays: ");
    while (i < n1 && j < n2 && k < n3) {
        if (A[i] == B[j] && B[j] == C[k]) {
            if (first || last != A[i]) {
                printf("%d ", A[i]);
                last = A[i];
                first = 0;
            }
            i++; j++; k++;
        } else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }
    printf("\n");
}

int main(void) {
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    commonElements(A, B, C, 6, 5, 8);
    return 0;
}
