#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

long long divide(long long dividend, long long divisor) {
    if (divisor == 0) return LLONG_MAX;
    if (dividend == 0) return 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    unsigned long long dvd = (unsigned long long)llabs(dividend);
    unsigned long long dvs = (unsigned long long)llabs(divisor);
    unsigned long long quotient = 0;

    for (int i = 62; i >= 0; i--) {
        if ((dvd >> i) >= dvs) {
            dvd -= (dvs << i);
            quotient += (1ULL << i);
        }
    }
    return sign * (long long)quotient;
}

int main(void) {
    printf("10 / 3 = %lld\n", divide(10, 3));
    printf("43 / -8 = %lld\n", divide(43, -8));
    printf("1000000000000 / 2 = %lld\n", divide(1000000000000LL, 2LL));
    assert(divide(10, 3) == 3);
    assert(divide(43, -8) == -5);
    assert(divide(1000000000000LL, 2LL) == 500000000000LL);
    return 0;
}
