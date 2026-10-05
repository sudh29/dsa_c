#include <stdio.h>
#include <stdlib.h>

void findTwoElement(int arr[], int n, int *repeating, int *missing) {
    *repeating = -1;
    *missing = -1;
    for (int i = 0; i < n; i++) {
        int idx = abs(arr[i]) - 1;
        if (arr[idx] < 0) {
            *repeating = abs(arr[i]);
        } else {
            arr[idx] = -arr[idx];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            *missing = i + 1;
            break;
        }
    }
}

int main(void) {
    int arr[] = {1, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rep, mis;
    findTwoElement(arr, n, &rep, &mis);
    printf("Repeating: %d | Missing: %d\n", rep, mis);
    return 0;
}
