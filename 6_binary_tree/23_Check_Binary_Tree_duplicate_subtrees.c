#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

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

static bool areIdentical(Node* r1, Node* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    return (r1->data == r2->data) &&
           areIdentical(r1->left, r2->left) &&
           areIdentical(r1->right, r2->right);
}

static int treeSize(Node* root) {
    if (!root) return 0;
    return 1 + treeSize(root->left) + treeSize(root->right);
}

static void collectSubtrees(Node* root, Node* list[], int *count) {
    if (!root) return;
    if (treeSize(root) >= 2) {
        list[(*count)++] = root;
    }
    collectSubtrees(root->left, list, count);
    collectSubtrees(root->right, list, count);
}

int dupSub(Node *root) {
    Node* list[MAX_NODES];
    int count = 0;
    collectSubtrees(root, list, &count);
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (areIdentical(list[i], list[j])) return 1;
        }
    }
    return 0;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(2);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(5);

    printf("Contains duplicate subtree (size >= 2): %s\n", dupSub(root) ? "Yes" : "No");
    freeTree(root);
    return 0;
}
