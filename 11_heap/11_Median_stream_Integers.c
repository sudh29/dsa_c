#include <stdio.h>
#include <stdlib.h>

static int compareAsc(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b);
}

typedef struct {
    int arr[100];
    int size;
} MedianFinder;

void insert(MedianFinder *mf, int x) {
    mf->arr[mf->size++] = x;
    qsort(mf->arr, mf->size, sizeof(int), compareAsc);
}

double getMedian(const MedianFinder *mf) {
    int n = mf->size;
    if (n % 2 != 0) return (double)mf->arr[n / 2];
    return (double)(mf->arr[(n / 2) - 1] + mf->arr[n / 2]) / 2.0;
}

int main(void) {
    MedianFinder mf = {.size = 0};
    int stream[] = {5, 15, 1, 3};
    for (int i = 0; i < 4; i++) {
        insert(&mf, stream[i]);
        printf("Added %d -> Median: %g\n", stream[i], getMedian(&mf));
    }
    return 0;
}
