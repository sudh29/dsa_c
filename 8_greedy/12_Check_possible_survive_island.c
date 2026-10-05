#include <stdio.h>

int minimumDays(int S, int N, int M) {
    if (M > N) return -1;
    if (S > 6 && (N - M) * 6 < M) return -1;
    int total_food = S * M;
    int days = total_food / N;
    if (total_food % N != 0) days++;
    return days;
}

int main(void) {
    printf("Min days to survive (S=10, N=16, M=2): %d\n", minimumDays(10, 16, 2));
    return 0;
}
