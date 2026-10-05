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

void inorder(Node* root, Node* nodes[], int *count) {
    if (!root) return;
    inorder(root->left, nodes, count);
    nodes[(*count)++] = root;
    inorder(root->right, nodes, count);
}

Node* buildBalanced(Node* nodes[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = nodes[mid];
    root->left = buildBalanced(nodes, start, mid - 1);
    root->right = buildBalanced(nodes, mid + 1, end);
    return root;
}

Node* buildBalancedTree(Node* root) {
    Node* nodes[100];
    int count = 0;
    inorder(root, nodes, &count);
    return buildBalanced(nodes, 0, count - 1);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void) {
    Node* root = newNode(4);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);

    root = buildBalancedTree(root);
    printf("Preorder of balanced BST: ");
    preorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
