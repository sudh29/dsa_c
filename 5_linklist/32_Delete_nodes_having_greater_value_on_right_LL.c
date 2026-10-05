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

Node* compute(Node *head) {
    head = reverse(head);
    Node *cur = head;
    int max_val = head->data;
    Node *prev = head;
    cur = head->next;

    while (cur) {
        if (cur->data >= max_val) {
            max_val = cur->data;
            prev = cur;
            cur = cur->next;
        } else {
            Node *del = cur;
            prev->next = cur->next;
            cur = cur->next;
            free(del);
        }
    }
    return reverse(head);
}

int main(void) {
    Node* head = newNode(12);
    head->next = newNode(15);
    head->next->next = newNode(10);
    head->next->next->next = newNode(11);

    head = compute(head);
    printf("Nodes after deleting rightward smaller: ");
    while (head) {
        printf("%d ", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
