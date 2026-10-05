#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int currentSize;
} Queue;

Queue* createQueue(int cap) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = cap;
    q->frontIndex = 0;
    q->rearIndex = cap - 1;
    q->currentSize = 0;
    q->arr = (int*)malloc(cap * sizeof(int));
    return q;
}

void freeQueue(Queue *q) {
    if (!q) return;
    free(q->arr);
    free(q);
}

bool isFull(const Queue *q) { return q->currentSize == q->capacity; }
bool isEmpty(const Queue *q) { return q->currentSize == 0; }

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rearIndex = (q->rearIndex + 1) % q->capacity;
    q->arr[q->rearIndex] = item;
    q->currentSize++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->arr[q->frontIndex];
    q->frontIndex = (q->frontIndex + 1) % q->capacity;
    q->currentSize--;
    return item;
}

int front(const Queue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->frontIndex];
}

int rear(const Queue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->rearIndex];
}

int main(void) {
    Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Front: %d | Rear: %d\n", front(q), rear(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("New Front: %d\n", front(q));
    freeQueue(q);
    return 0;
}
