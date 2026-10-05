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

void inorder(Node* root, int *k, int *ans) {
    if (!root || *k <= 0) return;
    inorder(root->left, k, ans);
    (*k)--;
    if (*k == 0) {
        *ans = root->data;
        return;
    }
    inorder(root->right, k, ans);
}

int KthSmallestElement(Node *root, int K) {
    int ans = -1;
    inorder(root, &K, &ans);
    return ans;
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(9);
    root->left->left = newNode(1);

    printf("2nd smallest element: %d\n", KthSmallestElement(root, 2));
    freeTree(root);
    return 0;
}
