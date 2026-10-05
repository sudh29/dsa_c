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

void diagonal(Node *root) {
    if (!root) return;
    Node* q[200];
    int front = 0, rear = 0;
    q[rear++] = root;

    printf("Diagonal traversal: ");
    while (front < rear) {
        Node* cur = q[front++];
        while (cur) {
            printf("%d ", cur->data);
            if (cur->left) q[rear++] = cur->left;
            cur = cur->right;
        }
    }
    printf("\n");
}

int main(void) {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);

    diagonal(root);
    freeTree(root);
    return 0;
}
