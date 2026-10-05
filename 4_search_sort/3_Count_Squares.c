#include <stdio.h>

int countSquares(int N) {
    if (N <= 1) return 0;
    long long low = 1, high = N - 1, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid < N) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (int)ans;
}

int main(void) {
    int n = 9;
    printf("Count of perfect squares less than %d: %d\n", n, countSquares(n));
    return 0;
}
