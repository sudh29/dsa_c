#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

static int cmp_items(const void *a, const void *b) {
    const Item *ia = (const Item*)a;
    const Item *ib = (const Item*)b;
    double r1 = (double)ia->value / ia->weight;
    double r2 = (double)ib->value / ib->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    qsort(arr, n, sizeof(Item), cmp_items);
    double curWeight = 0.0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        } else {
            int remain = W - (int)curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main(void) {
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Max fractional value: %g\n", fractionalKnapsack(50, arr, n));
    return 0;
}
