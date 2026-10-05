#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAP 100

typedef struct {
    void* elements[MAX_CAP];
    int front;
    int rear;
    int size;
} GenericQueue;

void initQueue(GenericQueue *q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void enqueue(GenericQueue *q, void *val) {
    if (q->size >= MAX_CAP) return;
    q->elements[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_CAP;
    q->size++;
}

void* dequeue(GenericQueue *q) {
    if (q->size == 0) return NULL;
    void *item = q->elements[q->front];
    q->front = (q->front + 1) % MAX_CAP;
    q->size--;
    return item;
}

bool empty(const GenericQueue *q) {
    return q->size == 0;
}

int main(void) {
    GenericQueue intQueue;
    initQueue(&intQueue);

    int a = 100, b = 200, c = 300;
    enqueue(&intQueue, &a);
    enqueue(&intQueue, &b);
    enqueue(&intQueue, &c);

    while (!empty(&intQueue)) {
        int *val = (int*)dequeue(&intQueue);
        printf("%d ", *val);
    }
    printf("\n");
    return 0;
}
