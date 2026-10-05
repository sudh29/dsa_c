#include <stdio.h>

void nextLargerElement(const long long arr[], int n, long long res[]) {
    long long stack[100];
    int top = 0;

    for (int i = 0; i < n; i++) res[i] = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top > 0 && stack[top - 1] <= arr[i]) {
            top--;
        }
        if (top > 0) {
            res[i] = stack[top - 1];
        }
        stack[top++] = arr[i];
    }
}

int main(void) {
    long long arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long res[4];
    nextLargerElement(arr, n, res);

    printf("Next greater elements: ");
    for (int i = 0; i < n; i++) printf("%lld ", res[i]);
    printf("\n");
    return 0;
}
