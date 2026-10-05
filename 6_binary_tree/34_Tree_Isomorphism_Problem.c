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

bool isIsomorphic(Node *root1, Node *root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->data != root2->data) return false;

    bool same = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool swapped = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
    return same || swapped;
}

int main(void) {
    Node* r1 = newNode(1); r1->left = newNode(2); r1->right = newNode(3);
    Node* r2 = newNode(1); r2->left = newNode(3); r2->right = newNode(2);

    printf("Trees are isomorphic: %s\n", isIsomorphic(r1, r2) ? "Yes" : "No");
    freeTree(r1);
    freeTree(r2);
    return 0;
}
