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

static int max(int a, int b) { return a > b ? a : b; }

int heightAndDiameter(Node* root, int *dia) {
    if (!root) return 0;
    int lh = heightAndDiameter(root->left, dia);
    int rh = heightAndDiameter(root->right, dia);
    if (1 + lh + rh > *dia) *dia = 1 + lh + rh;
    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    int dia = 0;
    heightAndDiameter(root, &dia);
    return dia;
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of tree: %d\n", diameter(root));
    freeTree(root);
    return 0;
}
