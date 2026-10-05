#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long first;
    long long second;
} Interval;

static int cmp_interval(const void *a, const void *b) {
    const Interval *ia = (const Interval*)a;
    const Interval *ib = (const Interval*)b;
    if (ia->first != ib->first)
        return (ia->first > ib->first) - (ia->first < ib->first);
    return (ia->second > ib->second) - (ia->second < ib->second);
}

static inline long long max_ll(long long a, long long b) { return a > b ? a : b; }

long long findKth(Interval intervals[], int n, long long k) {
    qsort(intervals, n, sizeof(Interval), cmp_interval);
    Interval merged[n];
    int m_count = 0;

    for (int i = 0; i < n; i++) {
        if (m_count == 0 || merged[m_count - 1].second < intervals[i].first) {
            merged[m_count++] = intervals[i];
        } else {
            merged[m_count - 1].second = max_ll(merged[m_count - 1].second, intervals[i].second);
        }
    }

    for (int i = 0; i < m_count; i++) {
        long long count = merged[i].second - merged[i].first + 1;
        if (k <= count) {
            return merged[i].first + k - 1;
        }
        k -= count;
    }
    return -1;
}

int main(void) {
    Interval intervals[] = {{1, 5}, {10, 15}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    long long k = 6;
    printf("Kth element (k=%lld): %lld\n", k, findKth(intervals, n, k));
    return 0;
}
