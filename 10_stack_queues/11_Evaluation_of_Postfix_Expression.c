#include <stdio.h>
#include <ctype.h>

int evaluatePostfix(const char *S) {
    int s[100];
    int top = 0;

    for (int i = 0; S[i] != '\0'; i++) {
        char c = S[i];
        if (isdigit((unsigned char)c)) {
            s[top++] = c - '0';
        } else {
            int val1 = s[--top];
            int val2 = s[--top];
            switch (c) {
                case '+': s[top++] = val2 + val1; break;
                case '-': s[top++] = val2 - val1; break;
                case '*': s[top++] = val2 * val1; break;
                case '/': s[top++] = val2 / val1; break;
            }
        }
    }
    return s[top - 1];
}

int main(void) {
    const char *exp = "231*+9-";
    printf("Evaluation of postfix %s: %d\n", exp, evaluatePostfix(exp));
    return 0;
}
