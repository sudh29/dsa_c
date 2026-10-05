#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int topIndex;
    int capacity;
} Stack;

Stack* createStack(int cap) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->capacity = cap;
    s->topIndex = -1;
    s->arr = (int*)malloc(cap * sizeof(int));
    return s;
}

void freeStack(Stack *s) {
    if (!s) return;
    free(s->arr);
    free(s);
}

bool push(Stack *s, int x) {
    if (s->topIndex >= s->capacity - 1) {
        printf("Stack Overflow\n");
        return false;
    }
    s->arr[++s->topIndex] = x;
    return true;
}

int pop(Stack *s) {
    if (s->topIndex < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->topIndex--];
}

int peek(const Stack *s) {
    if (s->topIndex < 0) return -1;
    return s->arr[s->topIndex];
}

bool isEmpty(const Stack *s) {
    return s->topIndex < 0;
}

int size(const Stack *s) {
    return s->topIndex + 1;
}

int main(void) {
    Stack *s = createStack(5);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("Top element: %d\n", peek(s));
    printf("Popped: %d\n", pop(s));
    printf("Top after pop: %d\n", peek(s));
    freeStack(s);
    return 0;
}
