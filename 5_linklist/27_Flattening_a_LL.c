#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;
} Node;

static Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp->bottom = NULL;
    return temp;
}

static Node* merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    Node *res;
    if (a->data < b->data) {
        res = a;
        res->bottom = merge(a->bottom, b);
    } else {
        res = b;
        res->bottom = merge(a, b->bottom);
    }
    res->next = NULL;
    return res;
}

Node* flatten(Node *root) {
    if (!root || !root->next) return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

int main(void) {
    Node* root = newNode(5);
    root->bottom = newNode(7);
    root->bottom->bottom = newNode(8);

    root->next = newNode(10);
    root->next->bottom = newNode(20);

    root = flatten(root);
    printf("Flattened list: ");
    Node* cur = root;
    while (cur) {
        printf("%d ", cur->data);
        Node* tmp = cur;
        cur = cur->bottom;
        free(tmp);
    }
    printf("\n");
    return 0;
}
