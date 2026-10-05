#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

Node* treeFromStringHelper(const char *s, int *i) {
    if (s[*i] == '\0') return NULL;

    int num = 0, sign = 1;
    if (s[*i] == '-') { sign = -1; (*i)++; }
    while (s[*i] != '\0' && isdigit((unsigned char)s[*i])) {
        num = num * 10 + (s[*i] - '0');
        (*i)++;
    }
    Node* root = newNode(sign * num);

    if (s[*i] == '(') {
        (*i)++; // consume '('
        root->left = treeFromStringHelper(s, i);
        (*i)++; // consume ')'
    }
    if (s[*i] == '(') {
        (*i)++; // consume '('
        root->right = treeFromStringHelper(s, i);
        (*i)++; // consume ')'
    }
    return root;
}

Node *treeFromString(const char *s) {
    int i = 0;
    return treeFromStringHelper(s, &i);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    const char *s = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(s);
    printf("Inorder of bracket constructed tree: ");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
