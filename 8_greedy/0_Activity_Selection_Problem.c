#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

static int cmp_act(const void *a, const void *b) {
    const Activity *aa = (const Activity*)a;
    const Activity *ab = (const Activity*)b;
    return (aa->end - ab->end);
}

int activitySelection(const int start[], const int end[], int n) {
    Activity *acts = (Activity*)malloc(n * sizeof(Activity));
    if (!acts) return 0;
    for (int i = 0; i < n; i++) {
        acts[i].start = start[i];
        acts[i].end = end[i];
    }
    qsort(acts, n, sizeof(Activity), cmp_act);

    int count = 1;
    int last_end = acts[0].end;
    for (int i = 1; i < n; i++) {
        if (acts[i].start > last_end) {
            count++;
            last_end = acts[i].end;
        }
    }
    free(acts);
    return count;
}

int main(void) {
    int start[] = {1, 3, 2, 5};
    int end[] = {2, 4, 3, 6};
    printf("Max activities: %d\n", activitySelection(start, end, 4));
    return 0;
}
