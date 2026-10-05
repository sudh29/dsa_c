#include <stdio.h>

int maxEqualSum(const int S1[], int n1, const int S2[], int n2, const int S3[], int n3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; i++) sum1 += S1[i];
    for (int i = 0; i < n2; i++) sum2 += S2[i];
    for (int i = 0; i < n3; i++) sum3 += S3[i];

    int top1 = 0, top2 = 0, top3 = 0;
    while (1) {
        if (top1 == n1 || top2 == n2 || top3 == n3) return 0;
        if (sum1 == sum2 && sum2 == sum3) return sum1;

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= S1[top1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= S2[top2++];
        } else {
            sum3 -= S3[top3++];
        }
    }
}

int main(void) {
    int S1[] = {4, 2, 3};
    int S2[] = {1, 1, 2, 3};
    int S3[] = {1, 4};
    printf("Max equal sum: %d (expected 5)\n", maxEqualSum(S1, 3, S2, 4, S3, 2));

    int A1[] = {3, 2, 1, 1, 1};
    int A2[] = {4, 3, 2};
    int A3[] = {1, 1, 4, 1};
    printf("Max equal sum: %d (expected 5)\n", maxEqualSum(A1, 5, A2, 3, A3, 4));
    return 0;
}
