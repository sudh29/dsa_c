#include <stdio.h>
#include <stdlib.h>

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

static Node* reverse(Node *head) {
    Node *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);
    Node *dummy = newNode(0);
    Node *cur = dummy;
    int carry = 0;

    while (first || second || carry) {
        int sum = carry;
        if (first) { sum += first->data; first = first->next; }
        if (second) { sum += second->data; second = second->next; }
        cur->next = newNode(sum % 10);
        carry = sum / 10;
        cur = cur->next;
    }
    Node *res = reverse(dummy->next);
    free(dummy);
    return res;
}

int main(void) {
    Node* a = newNode(4); a->next = newNode(5);
    Node* b = newNode(3); b->next = newNode(4); b->next->next = newNode(5);

    Node* sum = addTwoLists(a, b);
    printf("Sum of lists: ");
    while (sum) {
        printf("%d", sum->data);
        Node* tmp = sum;
        sum = sum->next;
        free(tmp);
    }
    printf("\n");

    while (a) { Node *t = a; a = a->next; free(t); }
    while (b) { Node *t = b; b = b->next; free(t); }
    return 0;
}
