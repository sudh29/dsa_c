#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

static int compareIntervals(const void *a, const void *b) {
    const Interval *ia = (const Interval *)a;
    const Interval *ib = (const Interval *)b;
    return ia->start - ib->start;
}

static int max(int a, int b) { return a > b ? a : b; }

int mergeIntervals(Interval intervals[], int n, Interval res[]) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    res[0] = intervals[0];
    int resCount = 1;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= res[resCount - 1].end) {
            res[resCount - 1].end = max(res[resCount - 1].end, intervals[i].end);
        } else {
            res[resCount++] = intervals[i];
        }
    }
    return resCount;
}

int main(void) {
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    Interval res[4];
    int count = mergeIntervals(intervals, n, res);

    printf("Merged intervals:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
    return 0;
}
