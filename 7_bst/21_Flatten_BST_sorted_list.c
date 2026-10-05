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

void inorderFlatten(Node* cur, Node** prev) {
    if (!cur) return;
    inorderFlatten(cur->left, prev);
    (*prev)->left = NULL;
    (*prev)->right = cur;
    *prev = cur;
    inorderFlatten(cur->right, prev);
}

Node* flatten(Node* root) {
    Node dummy;
    dummy.data = -1;
    dummy.left = dummy.right = NULL;
    Node* prev = &dummy;
    inorderFlatten(root, &prev);
    prev->left = NULL;
    prev->right = NULL;
    return dummy.right;
}

int main(void) {
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);

    Node* flat = flatten(root);
    printf("Flattened sorted list: ");
    Node* cur = flat;
    while (cur) {
        printf("%d ", cur->data);
        Node* tmp = cur;
        cur = cur->right;
        free(tmp);
    }
    printf("\n");
    return 0;
}
