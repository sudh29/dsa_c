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

void inorder(Node* root, int res[], int *count) {
    if (!root) return;
    inorder(root->left, res, count);
    res[(*count)++] = root->data;
    inorder(root->right, res, count);
}

void mergeBSTs(Node *root1, Node *root2, int res[], int *resCount) {
    int a[100], b[100];
    int countA = 0, countB = 0;
    inorder(root1, a, &countA);
    inorder(root2, b, &countB);

    int i = 0, j = 0;
    *resCount = 0;
    while (i < countA && j < countB) {
        if (a[i] <= b[j]) res[(*resCount)++] = a[i++];
        else res[(*resCount)++] = b[j++];
    }
    while (i < countA) res[(*resCount)++] = a[i++];
    while (j < countB) res[(*resCount)++] = b[j++];
}

int main(void) {
    Node* r1 = newNode(3); r1->left = newNode(1); r1->right = newNode(5);
    Node* r2 = newNode(4); r2->left = newNode(2); r2->right = newNode(6);

    int merged[200];
    int count = 0;
    mergeBSTs(r1, r2, merged, &count);

    printf("Merged two BSTs elements: ");
    for (int i = 0; i < count; i++) printf("%d ", merged[i]);
    printf("\n");

    freeTree(r1);
    freeTree(r2);
    return 0;
}
