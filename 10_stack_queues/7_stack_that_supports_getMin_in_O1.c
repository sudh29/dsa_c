#include <stdio.h>

typedef struct {
    int s[100];
    int top;
    int minEle;
} SpecialStack;

void push(SpecialStack *st, int x) {
    if (st->top == 0) {
        st->minEle = x;
        st->s[st->top++] = x;
    } else if (x < st->minEle) {
        st->s[st->top++] = 2 * x - st->minEle;
        st->minEle = x;
    } else {
        st->s[st->top++] = x;
    }
}

int pop(SpecialStack *st) {
    if (st->top == 0) return -1;
    int t = st->s[--st->top];
    if (t < st->minEle) {
        int prevMin = st->minEle;
        st->minEle = 2 * st->minEle - t;
        return prevMin;
    }
    return t;
}

int getMin(const SpecialStack *st) {
    if (st->top == 0) return -1;
    return st->minEle;
}

int main(void) {
    SpecialStack s = {.top = 0, .minEle = 0};
    push(&s, 18);
    push(&s, 19);
    push(&s, 29);
    push(&s, 15);
    push(&s, 16);
    printf("Current Min: %d\n", getMin(&s)); // 15
    pop(&s);
    pop(&s);
    printf("Min after popping 16 and 15: %d\n", getMin(&s)); // 18
    return 0;
}
