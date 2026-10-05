#include <stdio.h>
#include <stdlib.h>

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

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main(void) {
    TreeNode* root = newTreeNode(5);
    root->left = newTreeNode(3);
    root->right = newTreeNode(6);
    root->left->left = newTreeNode(2);
    root->left->right = newTreeNode(4);

    root = deleteNode(root, 3);
    printf("BST after deleting 3: ");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
