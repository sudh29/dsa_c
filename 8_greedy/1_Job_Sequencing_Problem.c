#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int dead;
    int profit;
} Job;

static int cmp_jobs(const void *a, const void *b) {
    const Job *ja = (const Job*)a;
    const Job *jb = (const Job*)b;
    return (jb->profit - ja->profit);
}

static inline int max(int a, int b) { return a > b ? a : b; }

void JobScheduling(Job arr[], int n, int *out_count, int *out_profit) {
    qsort(arr, n, sizeof(Job), cmp_jobs);
    int max_dead = 0;
    for (int i = 0; i < n; i++) max_dead = max(max_dead, arr[i].dead);

    int *slot = (int*)malloc((max_dead + 1) * sizeof(int));
    if (!slot) return;
    for (int i = 0; i <= max_dead; i++) slot[i] = -1;

    int count = 0, total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                count++;
                total_profit += arr[i].profit;
                break;
            }
        }
    }
    free(slot);
    *out_count = count;
    *out_profit = total_profit;
}

int main(void) {
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int count = 0, profit = 0;
    JobScheduling(arr, 4, &count, &profit);
    printf("Jobs scheduled: %d, Total Profit: %d\n", count, profit);
    return 0;
}
