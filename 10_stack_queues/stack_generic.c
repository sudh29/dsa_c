#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAP 100

typedef struct {
    void* elements[MAX_CAP];
    int top;
} GenericStack;

void initStack(GenericStack *s) {
    s->top = 0;
}

void push(GenericStack *s, void *val) {
    if (s->top >= MAX_CAP) return;
    s->elements[s->top++] = val;
}

void* pop(GenericStack *s) {
    if (s->top == 0) return NULL;
    return s->elements[--s->top];
}

bool empty(const GenericStack *s) {
    return s->top == 0;
}

int main(void) {
    GenericStack strStack;
    initStack(&strStack);

    push(&strStack, "Hello");
    push(&strStack, "Modern");
    push(&strStack, "C");

    while (!empty(&strStack)) {
        const char *val = (const char*)pop(&strStack);
        printf("%s ", val);
    }
    printf("\n");
    return 0;
}
