#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr;
    int dep;
    int platform;
} Train;

static int cmp_trains(const void *a, const void *b) {
    const Train *ta = (const Train*)a;
    const Train *tb = (const Train*)b;
    return (ta->dep - tb->dep);
}

int maxStop(int n, int m, Train trains[]) {
    qsort(trains, m, sizeof(Train), cmp_trains);
    int *last_dep = (int*)calloc(n + 1, sizeof(int));
    if (!last_dep) return 0;

    int count = 0;
    for (int i = 0; i < m; i++) {
        int p = trains[i].platform;
        if (trains[i].arr >= last_dep[p]) {
            count++;
            last_dep[p] = trains[i].dep;
        }
    }
    free(last_dep);
    return count;
}

int main(void) {
    Train trains[] = {
        {1000, 1030, 1},
        {1010, 1020, 1},
        {1025, 1040, 1},
        {1130, 1145, 2},
        {1130, 1140, 2}
    };
    printf("Max stopped trains: %d\n", maxStop(2, 5, trains));
    return 0;
}
