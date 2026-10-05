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

Node* addOne(Node *head) {
    head = reverse(head);
    Node *cur = head, *prev = NULL;
    int carry = 1;
    while (cur && carry) {
        int sum = cur->data + carry;
        cur->data = sum % 10;
        carry = sum / 10;
        prev = cur;
        cur = cur->next;
    }
    if (carry) {
        prev->next = newNode(carry);
    }
    return reverse(head);
}

int main(void) {
    Node* head = newNode(4);
    head->next = newNode(5);
    head->next->next = newNode(9);

    head = addOne(head);
    printf("Added 1 to list: ");
    while (head) {
        printf("%d", head->data);
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n");
    return 0;
}
