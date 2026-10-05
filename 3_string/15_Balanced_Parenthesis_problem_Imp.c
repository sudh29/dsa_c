#include <stdio.h>
#include <stdbool.h>

bool ispar(const char *x) {
    char stack[1000];
    int top = -1;

    for (int i = 0; x[i]; i++) {
        char c = x[i];
        if (c == '{' || c == '(' || c == '[') {
            stack[++top] = c;
        } else {
            if (top < 0) return false;
            char t = stack[top--];
            if (c == '}' && t != '{') return false;
            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
        }
    }
    return top == -1;
}

int main(void) {
    const char *s = "{([])}";
    printf("%s is balanced: %s\n", s, ispar(s) ? "Yes" : "No");
    return 0;
}
