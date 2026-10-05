#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ispar(const char *x) {
    char stack[100];
    int top = 0;

    for (int i = 0; x[i] != '\0'; i++) {
        char c = x[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[top++] = c;
        } else {
            if (top == 0) return false;
            char t = stack[top - 1];
            if ((c == ')' && t == '(') ||
                (c == '}' && t == '{') ||
                (c == ']' && t == '[')) {
                top--;
            } else {
                return false;
            }
        }
    }
    return top == 0;
}

int main(void) {
    const char *s1 = "{([])}";
    const char *s2 = "([)]";
    printf("%s: %s\n", s1, ispar(s1) ? "Balanced" : "Not Balanced");
    printf("%s: %s\n", s2, ispar(s2) ? "Balanced" : "Not Balanced");
    return 0;
}
