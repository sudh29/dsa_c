#include <stdio.h>

static int min(int a, int b) { return a < b ? a : b; }
static int max(int a, int b) { return a > b ? a : b; }

int maxProfit(int n, const int price[]) {
    if (n <= 1) return 0;

    int left_profit[50] = {0};
    int right_profit[50] = {0};

    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        min_price = min(min_price, price[i]);
        left_profit[i] = max(left_profit[i - 1], price[i] - min_price);
    }

    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        max_price = max(max_price, price[i]);
        right_profit[i] = max(right_profit[i + 1], max_price - price[i]);
    }

    int total_max = 0;
    for (int i = 0; i < n; i++) {
        total_max = max(total_max, left_profit[i] + right_profit[i]);
    }
    return total_max;
}

int main(void) {
    int prices[] = {10, 22, 5, 75, 65, 80};
    printf("Max profit at most twice: %d (expected 87)\n", maxProfit(6, prices));
    return 0;
}
