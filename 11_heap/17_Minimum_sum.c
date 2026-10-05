#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compareAsc(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b);
}

void solve(int arr[], int n, char *out) {
    qsort(arr, n, sizeof(int), compareAsc);
    char n1[50], n2[50];
    int len1 = 0, len2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) n1[len1++] = (char)('0' + arr[i]);
        else n2[len2++] = (char)('0' + arr[i]);
    }
    n1[len1] = '\0';
    n2[len2] = '\0';

    // Add n1 and n2
    char sumBuf[100];
    int i = len1 - 1, j = len2 - 1, carry = 0, k = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += n1[i--] - '0';
        if (j >= 0) sum += n2[j--] - '0';
        sumBuf[k++] = (char)('0' + (sum % 10));
        carry = sum / 10;
    }
    while (k > 1 && sumBuf[k - 1] == '0') k--;
    for (int idx = 0; idx < k; idx++) {
        out[idx] = sumBuf[k - 1 - idx];
    }
    out[k] = '\0';
    if (k == 0) strcpy(out, "0");
}

int main(void) {
    int arr[] = {6, 8, 4, 5, 2, 3};
    char out[100];
    solve(arr, 6, out);
    printf("Minimum sum of two formed numbers: %s\n", out);
    return 0;
}
