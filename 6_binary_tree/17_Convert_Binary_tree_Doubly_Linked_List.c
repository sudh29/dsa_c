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

void bToDLLUtil(Node* root, Node** head, Node** prev) {
    if (!root) return;
    bToDLLUtil(root->left, head, prev);
    if (!*prev) {
        *head = root;
    } else {
        root->left = *prev;
        (*prev)->right = root;
    }
    *prev = root;
    bToDLLUtil(root->right, head, prev);
}

Node *bToDLL(Node *root) {
    Node *head = NULL, *prev = NULL;
    bToDLLUtil(root, &head, &prev);
    return head;
}

int main(void) {
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);

    Node* dll = bToDLL(root);
    printf("Binary tree to DLL: ");
    Node* cur = dll;
    while (cur) {
        printf("%d ", cur->data);
        Node* tmp = cur;
        cur = cur->right;
        free(tmp);
    }
    printf("\n");
    return 0;
}
