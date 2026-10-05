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

Node* rotateDLL(Node *head, int N) {
    if (!head || N == 0) return head;
    Node *cur = head;
    int count = 1;
    while (count < N && cur) {
        cur = cur->next;
        count++;
    }
    if (!cur || !cur->next) return head;

    Node *nthNode = cur;
    while (cur->next) cur = cur->next;

    cur->next = head;
    head->prev = cur;
    head = nthNode->next;
    head->prev = NULL;
    nthNode->next = NULL;
    return head;
}

int main(void) {
    Node* head = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(3);
    Node* n4 = newNode(4);
    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    head = rotateDLL(head, 2);
    printf("Rotated DLL by 2: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
