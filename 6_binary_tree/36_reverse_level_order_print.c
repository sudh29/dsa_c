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

void reverseLevelOrderPrint(Node* root) {
    if (!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    int stack[100];
    int top = 0;

    queue[rear++] = root;
    while (front < rear) {
        Node* cur = queue[front++];
        stack[top++] = cur->data;
        if (cur->right) queue[rear++] = cur->right;
        if (cur->left) queue[rear++] = cur->left;
    }

    printf("Reverse level order print: ");
    while (top > 0) {
        printf("%d ", stack[--top]);
    }
    printf("\n");
}

int main(void) {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    reverseLevelOrderPrint(root);
    freeTree(root);
    return 0;
}
