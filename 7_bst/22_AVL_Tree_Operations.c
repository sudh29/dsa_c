#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key, height;
    struct AVLNode *left, *right;
} AVLNode;

static AVLNode* newAVLNode(int k) {
    AVLNode* n = (AVLNode*)malloc(sizeof(AVLNode));
    n->key = k;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}

static void freeAVL(AVLNode* root) {
    if (!root) return;
    freeAVL(root->left);
    freeAVL(root->right);
    free(root);
}

static int max(int a, int b) { return a > b ? a : b; }
static int height(AVLNode *N) { return N ? N->height : 0; }
static int getBalance(AVLNode *N) { return N ? height(N->left) - height(N->right) : 0; }

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insertAVL(AVLNode* node, int key) {
    if (!node) return newAVLNode(key);
    if (key < node->key) node->left = insertAVL(node->left, key);
    else if (key > node->key) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->key) return rightRotate(node);
    // Right Right
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(AVLNode *root) {
    if (!root) return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main(void) {
    AVLNode *root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) root = insertAVL(root, keys[i]);

    printf("Preorder of balanced AVL tree: ");
    preOrder(root);
    printf("\n");
    freeAVL(root);
    return 0;
}
