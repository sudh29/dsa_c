#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int low, high;
} Interval;

static int compareIntervals(const void *a, const void *b) {
    const Interval *ia = (const Interval *)a;
    const Interval *ib = (const Interval *)b;
    return ia->low - ib->low;
}

void printConflictingAppointments(Interval appt[], int n) {
    qsort(appt, n, sizeof(Interval), compareIntervals);

    printf("Conflicting appointments:\n");
    for (int i = 1; i < n; i++) {
        if (appt[i].low < appt[i - 1].high) {
            printf("[%d,%d] conflicts with [%d,%d]\n",
                   appt[i].low, appt[i].high, appt[i - 1].low, appt[i - 1].high);
        }
    }
}

int main(void) {
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt) / sizeof(appt[0]);
    printConflictingAppointments(appt, n);
    return 0;
}
