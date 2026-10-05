#include <stdio.h>

void valueEqualToIndex(const int arr[], int n) {
    printf("Values equal to 1-based index: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] == i + 1) { // 1-based indexing
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int arr[] = {15, 2, 45, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    valueEqualToIndex(arr, n);
    return 0;
}
