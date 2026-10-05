#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

long long multiplyTwoList(Node *first, Node *second) {
    long long num1 = 0, num2 = 0;
    while (first || second) {
        if (first) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }
        if (second) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }
    }
    return (num1 * num2) % MOD;
}

int main(void) {
    Node* a = newNode(3); a->next = newNode(2);
    Node* b = newNode(2);
    printf("Product of two lists (32 * 2): %lld\n", multiplyTwoList(a, b));

    free(a->next); free(a);
    free(b);
    return 0;
}
