#include <stdio.h>
#include <stdlib.h>

void segregateElements(int arr[], int n) {
    int *temp = (int*)malloc(n * sizeof(int));
    if (!temp) return;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) temp[k++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) temp[k++] = arr[i];
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    free(temp);
}

int main(void) {
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    segregateElements(arr, n);
    printf("Segregated array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
