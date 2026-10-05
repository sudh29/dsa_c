#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int solve(Node* root, int *ans) {
    if (!root) return 0;
    int curSum = root->data + solve(root->left, ans) + solve(root->right, ans);
    *ans = max(*ans, curSum);
    return curSum;
}

int findLargestSubtreeSum(Node* root) {
    int ans = INT_MIN;
    solve(root, &ans);
    return ans;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    printf("Largest subtree sum: %d\n", findLargestSubtreeSum(root));
    freeTree(root);
    return 0;
}
