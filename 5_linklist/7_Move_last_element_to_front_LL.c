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

Node* moveToFront(Node *head) {
    if (!head || !head->next) return head;
    Node *secLast = NULL, *last = head;
    while (last->next) {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head;
    return last;
}

int main(void) {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    head = moveToFront(head);
    printf("Moved last to front: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
