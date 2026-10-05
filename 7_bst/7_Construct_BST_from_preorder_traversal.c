#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

static TreeNode* newTreeNode(int x) {
    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->val = x;
    n->left = n->right = NULL;
    return n;
}

static void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

TreeNode* build(const int preorder[], int n, int *idx, int bound) {
    if (*idx == n || preorder[*idx] > bound) return NULL;
    TreeNode* root = newTreeNode(preorder[(*idx)++]);
    root->left = build(preorder, n, idx, root->val);
    root->right = build(preorder, n, idx, bound);
    return root;
}

TreeNode* bstFromPreorder(const int preorder[], int n) {
    int idx = 0;
    return build(preorder, n, &idx, INT_MAX);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main(void) {
    int pre[] = {8, 5, 1, 7, 10, 12};
    int n = sizeof(pre) / sizeof(pre[0]);
    TreeNode* root = bstFromPreorder(pre, n);
    printf("Inorder of constructed BST: ");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
