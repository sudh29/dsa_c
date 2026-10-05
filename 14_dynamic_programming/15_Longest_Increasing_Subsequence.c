#include <stdio.h>

int longestSubsequence(int n, const int a[]) {
    int tails[100];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int l = 0, r = size;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (tails[mid] >= x) r = mid;
            else l = mid + 1;
        }
        tails[l] = x;
        if (l == size) size++;
    }
    return size;
}

int main(void) {
    int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(a) / sizeof(a[0]);
    printf("LIS length: %d (expected 6)\n", longestSubsequence(n, a));
    return 0;
}
