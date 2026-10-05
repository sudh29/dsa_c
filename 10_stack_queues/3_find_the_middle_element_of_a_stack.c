#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* mid;
    int count;
} MidStack;

static Node* newNode(int d) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = d;
    n->prev = n->next = NULL;
    return n;
}

void push(MidStack *ms, int data) {
    Node* n = newNode(data);
    n->prev = NULL;
    n->next = ms->head;
    ms->count++;

    if (ms->count == 1) {
        ms->mid = n;
    } else {
        ms->head->prev = n;
        if (ms->count % 2 != 0) {
            ms->mid = ms->mid->prev;
        }
    }
    ms->head = n;
}

int pop(MidStack *ms) {
    if (ms->count == 0) return -1;
    Node* temp = ms->head;
    int item = temp->data;
    ms->head = ms->head->next;
    if (ms->head != NULL) ms->head->prev = NULL;
    ms->count--;

    if (ms->count % 2 == 0 && ms->mid != NULL) {
        ms->mid = ms->mid->next;
    }
    free(temp);
    return item;
}

int findMiddle(const MidStack *ms) {
    if (ms->count == 0) return -1;
    return ms->mid->data;
}

void freeMidStack(MidStack *ms) {
    while (ms->count > 0) pop(ms);
}

int main(void) {
    MidStack ms = {NULL, NULL, 0};
    push(&ms, 11);
    push(&ms, 22);
    push(&ms, 33);
    push(&ms, 44);
    push(&ms, 55);

    printf("Middle element: %d\n", findMiddle(&ms)); // 33
    printf("Popped: %d\n", pop(&ms));
    printf("New Middle element: %d\n", findMiddle(&ms)); // 33
    freeMidStack(&ms);
    return 0;
}
