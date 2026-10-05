#include <stdio.h>
#include <limits.h>

typedef struct {
    int start;
    int end;
} Range;

Range findSmallestRange(const int arr[][5], int n, int k) {
    int ptrs[10] = {0};
    int min_range = INT_MAX;
    int best_start = -1, best_end = -1;

    while (1) {
        int min_val = INT_MAX, max_val = INT_MIN;
        int min_list = -1;

        for (int i = 0; i < k; i++) {
            int val = arr[i][ptrs[i]];
            if (val < min_val) {
                min_val = val;
                min_list = i;
            }
            if (val > max_val) {
                max_val = val;
            }
        }

        if (max_val - min_val < min_range) {
            min_range = max_val - min_val;
            best_start = min_val;
            best_end = max_val;
        }

        ptrs[min_list]++;
        if (ptrs[min_list] == n) break;
    }

    return (Range){best_start, best_end};
}

int main(void) {
    int arr[3][5] = {
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}
    };
    Range r = findSmallestRange(arr, 5, 3);
    printf("Smallest range covering all K lists: [%d, %d]\n", r.start, r.end);
    return 0;
}
