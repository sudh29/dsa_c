#include <stdio.h>

static inline int min(int a, int b) { return a < b ? a : b; }
static inline int max(int a, int b) { return a > b ? a : b; }

int maxProfit(const int *prices, int n) {
    int min_price = 1000000000, max_profit = 0;
    for (int i = 0; i < n; i++) {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}

int main(void) {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    printf("Max stock profit: %d\n", maxProfit(prices, n));
    return 0;
}
