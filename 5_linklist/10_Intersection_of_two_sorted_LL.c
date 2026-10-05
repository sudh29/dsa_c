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

Node* findIntersection(Node* head1, Node* head2) {
    Node *dummy = newNode(0);
    Node *cur = dummy;
    while (head1 && head2) {
        if (head1->data == head2->data) {
            cur->next = newNode(head1->data);
            cur = cur->next;
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }
    Node *res = dummy->next;
    free(dummy);
    return res;
}

int main(void) {
    Node* h1 = newNode(1); h1->next = newNode(2); h1->next->next = newNode(4);
    Node* h2 = newNode(2); h2->next = newNode(3); h2->next->next = newNode(4);

    Node* inter = findIntersection(h1, h2);
    printf("Intersection: ");
    while (inter) {
        printf("%d ", inter->data);
        Node *t = inter;
        inter = inter->next;
        free(t);
    }
    printf("\n");

    while (h1) { Node *t = h1; h1 = h1->next; free(t); }
    while (h2) { Node *t = h2; h2 = h2->next; free(t); }
    return 0;
}
