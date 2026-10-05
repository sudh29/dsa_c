#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

static int compareJobs(const void *a, const void *b) {
    const Job *ja = (const Job *)a;
    const Job *jb = (const Job *)b;
    return jb->profit - ja->profit;
}

static int min(int a, int b) { return a < b ? a : b; }
static int max(int a, int b) { return a > b ? a : b; }

void JobScheduling(Job jobs[], int n, int *outCount, int *outProfit) {
    qsort(jobs, n, sizeof(Job), compareJobs);

    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    int slot[100];
    for (int i = 0; i <= max_deadline; i++) slot[i] = -1;

    int count = 0, total_profit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(max_deadline, jobs[i].deadline); j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                count++;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }
    *outCount = count;
    *outProfit = total_profit;
}

int main(void) {
    Job jobs[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int cnt = 0, profit = 0;
    JobScheduling(jobs, 4, &cnt, &profit);
    printf("Scheduled jobs: %d, Total profit: %d (expected 2, 60)\n", cnt, profit);
    return 0;
}
