#include <stdio.h>
#include <limits.h>

static inline int max(int a, int b) { return a > b ? a : b; }
static inline int min(int a, int b) { return a < b ? a : b; }

double MedianOfArrays(const int array1[], int n1, const int array2[], int n2) {
    if (n1 > n2) return MedianOfArrays(array2, n2, array1, n1);

    int low = 0, high = n1;
    while (low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : array1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : array2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : array1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : array2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n1 + n2) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else {
                return max(left1, left2);
            }
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main(void) {
    int a1[] = {1, 5, 9};
    int a2[] = {2, 3, 6, 7};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);
    printf("Median of two sorted arrays: %g\n", MedianOfArrays(a1, n1, a2, n2));
    return 0;
}
