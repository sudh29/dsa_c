#include <stdio.h>

long long countSubArrayProductLessThanK(const int a[], int n, long long k) {
    if (k <= 1) return 0;
    long long prod = 1;
    long long count = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        prod *= a[end];
        while (start <= end && prod >= k) {
            prod /= a[start++];
        }
        count += (end - start + 1);
    }
    return count;
}

int main(void) {
    int a[] = {1, 2, 3, 4};
    int k = 10;
    printf("Subarrays with product < 10: %lld (expected 7)\n", countSubArrayProductLessThanK(a, 4, k));
    return 0;
}
