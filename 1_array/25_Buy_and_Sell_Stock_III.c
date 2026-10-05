#include <stdio.h>
#include <limits.h>

static inline int min(int a, int b) { return a < b ? a : b; }
static inline int max(int a, int b) { return a > b ? a : b; }

int maxProfit(const int *prices, int n) {
    int buy1 = INT_MAX, buy2 = INT_MAX;
    int profit1 = 0, profit2 = 0;

    for (int i = 0; i < n; i++) {
        int p = prices[i];
        buy1 = min(buy1, p);
        profit1 = max(profit1, p - buy1);
        buy2 = min(buy2, p - profit1);
        profit2 = max(profit2, p - buy2);
    }
    return profit2;
}

int main(void) {
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    printf("Max profit with 2 transactions: %d\n", maxProfit(prices, n));
    return 0;
}
