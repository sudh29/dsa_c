#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BSTNode;

static BSTNode* newBSTNode(int val) {
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

static void freeBST(BSTNode* root) {
    if (!root) return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

BSTNode* insert(BSTNode* root, int val) {
    if (!root) return newBSTNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

bool search(BSTNode* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

BSTNode* findMin(BSTNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode* removeNode(BSTNode* root, int val) {
    if (!root) return NULL;
    if (val < root->data) root->left = removeNode(root->left, val);
    else if (val > root->data) root->right = removeNode(root->right, val);
    else {
        if (!root->left) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    BSTNode* root = NULL;
    int vals[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(vals) / sizeof(vals[0]);
    for (int i = 0; i < n; i++) root = insert(root, vals[i]);

    printf("Inorder: ");
    inorder(root);
    printf("\nSearch 40: %s\n", search(root, 40) ? "Found" : "Not Found");

    root = removeNode(root, 20);
    printf("After removing 20: ");
    inorder(root);
    printf("\n");
    freeBST(root);
    return 0;
}
