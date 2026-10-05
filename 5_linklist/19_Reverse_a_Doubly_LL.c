#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

static Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    return temp;
}

Node* reverseDLL(Node *head) {
    Node *temp = NULL, *current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) head = temp->prev;
    return head;
}

int main(void) {
    Node* head = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(3);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;

    head = reverseDLL(head);
    printf("Reversed DLL: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
