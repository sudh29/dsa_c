#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool canRepresentBST(const int pre[], int n) {
    int stack[100];
    int top = 0;
    int root = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre[i] < root) return false;
        while (top > 0 && stack[top - 1] < pre[i]) {
            root = stack[--top];
        }
        stack[top++] = pre[i];
    }
    return true;
}

int main(void) {
    int pre1[] = {40, 30, 35, 80, 100};
    int pre2[] = {40, 30, 35, 20, 80, 100};
    printf("pre1 is valid BST: %s\n", canRepresentBST(pre1, 5) ? "Yes" : "No");
    printf("pre2 is valid BST: %s\n", canRepresentBST(pre2, 6) ? "Yes" : "No");
    return 0;
}
