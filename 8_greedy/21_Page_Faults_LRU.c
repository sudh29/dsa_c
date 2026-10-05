#include <stdio.h>

int pageFaults(int N, int C, const int pages[]) {
    int memory[C];
    int time[C];
    for (int i = 0; i < C; i++) {
        memory[i] = -1;
        time[i] = -1;
    }

    int faults = 0;
    for (int t = 0; t < N; t++) {
        int page = pages[t];
        int found = 0;
        for (int i = 0; i < C; i++) {
            if (memory[i] == page) {
                found = 1;
                time[i] = t;
                break;
            }
        }
        if (!found) {
            faults++;
            int lru_idx = 0;
            for (int i = 1; i < C; i++) {
                if (memory[i] == -1) {
                    lru_idx = i;
                    break;
                }
                if (time[i] < time[lru_idx]) {
                    lru_idx = i;
                }
            }
            memory[lru_idx] = page;
            time[lru_idx] = t;
        }
    }
    return faults;
}

int main(void) {
    int pages[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    int C = 4;
    printf("Page faults: %d (expected 8)\n", pageFaults(9, C, pages));
    return 0;
}
