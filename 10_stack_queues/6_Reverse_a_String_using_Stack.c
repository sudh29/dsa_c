#include <stdio.h>
#include <string.h>

void reverseString(const char *str, char *res) {
    int n = strlen(str);
    char stack[100];
    int top = 0;

    for (int i = 0; i < n; i++) stack[top++] = str[i];
    int idx = 0;
    while (top > 0) {
        res[idx++] = stack[--top];
    }
    res[idx] = '\0';
}

int main(void) {
    const char *str = "GeeksforGeeks";
    char rev[32];
    reverseString(str, rev);
    printf("Original: %s | Reversed: %s\n", str, rev);
    return 0;
}
