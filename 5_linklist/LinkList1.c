#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

static Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(LinkedList *list, int val) {
    Node* n = newNode(val);
    if (!list->head) {
        list->head = n;
        return;
    }
    Node* cur = list->head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void push(LinkedList *list, int val) {
    Node* n = newNode(val);
    n->next = list->head;
    list->head = n;
}

void deleteNode(LinkedList *list, int key) {
    Node *temp = list->head, *prev = NULL;
    if (temp && temp->data == key) {
        list->head = temp->next;
        free(temp);
        return;
    }
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    prev->next = temp->next;
    free(temp);
}

void printList(const LinkedList *list) {
    Node* cur = list->head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void freeList(LinkedList *list) {
    Node* cur = list->head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    list->head = NULL;
}

int main(void) {
    LinkedList list = {NULL};
    append(&list, 10);
    append(&list, 20);
    push(&list, 5);
    printList(&list); // 5 -> 10 -> 20 -> NULL
    deleteNode(&list, 10);
    printList(&list); // 5 -> 20 -> NULL
    freeList(&list);
    return 0;
}
