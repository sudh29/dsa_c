#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int checkSumTree(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;

    int ls = checkSumTree(root->left);
    if (ls == -1) return -1;
    int rs = checkSumTree(root->right);
    if (rs == -1) return -1;

    if (root->data == ls + rs) return 2 * root->data;
    return -1;
}

bool isSumTree(Node* root) {
    return checkSumTree(root) != -1;
}

int main(void) {
    Node* root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    printf("Is sum tree: %s\n", isSumTree(root) ? "Yes" : "No");
    freeTree(root);
    return 0;
}
