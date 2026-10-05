#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

static int cmp_interval(const void *a, const void *b) {
    const Interval *ia = (const Interval*)a;
    const Interval *ib = (const Interval*)b;
    if (ia->start != ib->start)
        return (ia->start > ib->start) - (ia->start < ib->start);
    return (ia->end > ib->end) - (ia->end < ib->end);
}

static inline int max(int a, int b) { return a > b ? a : b; }

int mergeIntervals(Interval intervals[], int n, Interval out[]) {
    if (n <= 0) return 0;
    qsort(intervals, n, sizeof(Interval), cmp_interval);

    int out_count = 0;
    out[out_count++] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= out[out_count - 1].end) {
            out[out_count - 1].end = max(out[out_count - 1].end, intervals[i].end);
        } else {
            out[out_count++] = intervals[i];
        }
    }
    return out_count;
}

int main(void) {
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    Interval out[4];
    int res_count = mergeIntervals(intervals, n, out);
    printf("Merged intervals: ");
    for (int i = 0; i < res_count; i++) {
        printf("[%d, %d] ", out[i].start, out[i].end);
    }
    printf("\n");
    return 0;
}
