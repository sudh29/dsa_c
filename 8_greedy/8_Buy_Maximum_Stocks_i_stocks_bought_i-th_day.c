#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int price;
    int day;
} Stock;

static int cmp_stocks(const void *a, const void *b) {
    const Stock *sa = (const Stock*)a;
    const Stock *sb = (const Stock*)b;
    return (sa->price - sb->price);
}

static inline int min(int a, int b) { return a < b ? a : b; }

int buyMaximumProducts(int n, int k, const int price[]) {
    Stock *stocks = (Stock*)malloc(n * sizeof(Stock));
    if (!stocks) return 0;
    for (int i = 0; i < n; i++) {
        stocks[i].price = price[i];
        stocks[i].day = i + 1;
    }
    qsort(stocks, n, sizeof(Stock), cmp_stocks);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num = min(stocks[i].day, k / stocks[i].price);
        ans += num;
        k -= num * stocks[i].price;
    }
    free(stocks);
    return ans;
}

int main(void) {
    int price[] = {10, 7, 19};
    printf("Max stocks bought with $45: %d\n", buyMaximumProducts(3, 45, price));
    return 0;
}
