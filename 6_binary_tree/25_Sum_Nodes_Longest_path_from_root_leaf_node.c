#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

static Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

static void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

static int max(int a, int b) { return a > b ? a : b; }

void solve(Node* root, int len, int sum, int *maxLen, int *maxSum) {
    if (!root) return;
    sum += root->data;
    if (!root->left && !root->right) {
        if (len > *maxLen) {
            *maxLen = len;
            *maxSum = sum;
        } else if (len == *maxLen) {
            *maxSum = max(*maxSum, sum);
        }
        return;
    }
    solve(root->left, len + 1, sum, maxLen, maxSum);
    solve(root->right, len + 1, sum, maxLen, maxSum);
}

int sumOfLongRootToLeafPath(Node *root) {
    int maxLen = 0, maxSum = 0;
    solve(root, 1, 0, &maxLen, &maxSum);
    return maxSum;
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(7);
    root->left->right = newNode(1);
    root->right->left = newNode(2);
    root->right->right = newNode(3);
    root->left->right->left = newNode(6);

    printf("Sum of nodes on longest root-to-leaf path: %d\n", sumOfLongRootToLeafPath(root));
    freeTree(root);
    return 0;
}
