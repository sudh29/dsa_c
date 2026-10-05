#include <stdio.h>

int majorityElement(const int a[], int size) {
    int candidate = -1, count = 0;
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = a[i];
            count = 1;
        } else if (a[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    // Verification
    int freq = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == candidate) freq++;
    }
    return (freq > size / 2) ? candidate : -1;
}

int main(void) {
    int arr[] = {3, 1, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Majority element: %d\n", majorityElement(arr, n));
    return 0;
}
