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

bool checkLevel(Node* root, int level, int *leafLevel) {
    if (!root) return true;
    if (!root->left && !root->right) {
        if (*leafLevel == 0) {
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }
    return checkLevel(root->left, level + 1, leafLevel) &&
           checkLevel(root->right, level + 1, leafLevel);
}

bool check(Node *root) {
    int leafLevel = 0;
    return checkLevel(root, 1, &leafLevel);
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);

    printf("Leaves at same level: %s\n", check(root) ? "Yes" : "No");
    freeTree(root);
    return 0;
}
