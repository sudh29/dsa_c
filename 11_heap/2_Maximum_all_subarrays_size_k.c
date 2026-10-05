#include <stdio.h>

void max_of_subarrays(const int arr[], int n, int k, int res[], int *resLen) {
    int dq[100];
    int front = 0, rear = 0;
    *resLen = 0;

    for (int i = 0; i < n; i++) {
        if (front < rear && dq[front] == i - k) front++;
        while (front < rear && arr[dq[rear - 1]] <= arr[i]) rear--;
        dq[rear++] = i;

        if (i >= k - 1) {
            res[(*resLen)++] = arr[dq[front]];
        }
    }
}

int main(void) {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res[100];
    int resLen = 0;
    max_of_subarrays(arr, n, 3, res, &resLen);

    printf("Max of subarrays of size 3: ");
    for (int i = 0; i < resLen; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
