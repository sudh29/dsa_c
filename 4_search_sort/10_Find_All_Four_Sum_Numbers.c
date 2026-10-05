#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void fourSum(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), cmp_int);
    printf("Four sum quadruplets summing to %d:\n", k);

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            int left = j + 1, right = n - 1;
            while (left < right) {
                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == k) {
                    printf("[%d, %d, %d, %d]\n", arr[i], arr[j], arr[left], arr[right]);
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < k) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
}

int main(void) {
    int arr[] = {1, 0, -1, 0, -2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    fourSum(arr, n, k);
    return 0;
}
