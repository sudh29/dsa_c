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

int getCount(Node *root, int l, int h) {
    if (!root) return 0;
    if (root->data >= l && root->data <= h) {
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    } else if (root->data < l) {
        return getCount(root->right, l, h);
    } else {
        return getCount(root->left, l, h);
    }
}

int main(void) {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(50);
    root->left->left = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);

    printf("Count in range [5, 45]: %d\n", getCount(root, 5, 45));
    freeTree(root);
    return 0;
}
