#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int pos;
} Meeting;

static int cmp_meetings(const void *a, const void *b) {
    const Meeting *ma = (const Meeting*)a;
    const Meeting *mb = (const Meeting*)b;
    if (ma->end != mb->end)
        return (ma->end - mb->end);
    return (ma->pos - mb->pos);
}

void maxMeetings(int n, const int start[], const int end[]) {
    Meeting *m = (Meeting*)malloc(n * sizeof(Meeting));
    if (!m) return;
    for (int i = 0; i < n; i++) {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos = i + 1;
    }
    qsort(m, n, sizeof(Meeting), cmp_meetings);

    printf("Selected meeting indices: ");
    printf("%d ", m[0].pos);
    int time_limit = m[0].end;

    for (int i = 1; i < n; i++) {
        if (m[i].start > time_limit) {
            printf("%d ", m[i].pos);
            time_limit = m[i].end;
        }
    }
    printf("\n");
    free(m);
}

int main(void) {
    int s[] = {1, 3, 0, 5, 8, 5};
    int e[] = {2, 4, 6, 7, 9, 9};
    maxMeetings(6, s, e);
    return 0;
}
