#include <stdio.h>

typedef struct {
    int arr[100];
    int top;
} Stack;

void sortedInsert(Stack *s, int element) {
    if (s->top == 0 || element > s->arr[s->top - 1]) {
        s->arr[s->top++] = element;
        return;
    }
    int temp = s->arr[--s->top];
    sortedInsert(s, element);
    s->arr[s->top++] = temp;
}

void sortStack(Stack *s) {
    if (s->top > 0) {
        int temp = s->arr[--s->top];
        sortStack(s);
        sortedInsert(s, temp);
    }
}

int main(void) {
    Stack s = {.top = 0};
    s.arr[s.top++] = 30;
    s.arr[s.top++] = -5;
    s.arr[s.top++] = 18;
    s.arr[s.top++] = 14;
    s.arr[s.top++] = -3;

    sortStack(&s);
    printf("Sorted stack (top to bottom): ");
    while (s.top > 0) {
        printf("%d ", s.arr[--s.top]);
    }
    printf("\n");
    return 0;
}
