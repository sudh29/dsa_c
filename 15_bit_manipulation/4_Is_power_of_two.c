#include <stdio.h>
#include <stdbool.h>

bool isPowerofTwo(long long n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main(void) {
    long long n1 = 16, n2 = 18;
    printf("%lld is power of 2: %s\n", n1, isPowerofTwo(n1) ? "Yes" : "No");
    printf("%lld is power of 2: %s\n", n2, isPowerofTwo(n2) ? "Yes" : "No");
    return 0;
}
