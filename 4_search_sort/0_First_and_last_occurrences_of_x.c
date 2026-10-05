#include <stdio.h>

void find(const int arr[], int n, int x, int *first, int *last) {
    int start = 0, end = n - 1, mid, temp = -1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == x) {
            temp = mid;
            break;
        } else if (arr[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if (temp == -1) {
        *first = -1;
        *last = -1;
        return;
    }

    int f = temp, l = temp;
    while (f > 0 && arr[f - 1] == x) f--;
    while (l < n - 1 && arr[l + 1] == x) l++;
    *first = f;
    *last = l;
}

int main(void) {
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int first, last;
    find(arr, n, x, &first, &last);
    printf("First and last occurrences of %d: [%d, %d]\n", x, first, last);
    return 0;
}
