#include <stdio.h>
#include <stdlib.h>

long long calculateWorkUnits(int n, const long long demands[]) {
    long long work = 0;
    long long prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix += demands[i];
        work += llabs(prefix);
    }
    return work;
}

int main(void) {
    long long demands[] = {5, -4, 1, -3, 1};
    printf("GERGOVIA wine trading work units: %lld (expected 9)\n", calculateWorkUnits(5, demands));

    long long demands2[] = {-1000, -1000, -1000, 3000};
    printf("GERGOVIA work units 2: %lld (expected 6000)\n", calculateWorkUnits(4, demands2));
    return 0;
}
