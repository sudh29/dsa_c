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

int intersectPoint(Node* head1, Node* head2) {
    Node *ptr1 = head1, *ptr2 = head2;
    while (ptr1 != ptr2) {
        ptr1 = ptr1 ? ptr1->next : head2;
        ptr2 = ptr2 ? ptr2->next : head1;
    }
    return ptr1 ? ptr1->data : -1;
}

int main(void) {
    Node* common = newNode(15);
    common->next = newNode(30);

    Node* h1 = newNode(3);
    h1->next = newNode(6);
    h1->next->next = newNode(9);
    h1->next->next->next = common;

    Node* h2 = newNode(10);
    h2->next = common;

    printf("Intersection Point: %d\n", intersectPoint(h1, h2));

    free(h1->next->next);
    free(h1->next);
    free(h1);
    free(h2);
    free(common->next);
    free(common);
    return 0;
}
