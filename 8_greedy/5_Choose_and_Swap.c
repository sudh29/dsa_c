#include <stdio.h>
#include <string.h>

void chooseAndSwap(char *A) {
    int chk[26];
    memset(chk, -1, sizeof(chk));
    int n = (int)strlen(A);

    for (int i = 0; i < n; i++) {
        if (chk[A[i] - 'a'] == -1) {
            chk[A[i] - 'a'] = i;
        }
    }

    int i, j;
    for (i = 0; i < n; i++) {
        int flag = 0;
        for (j = 0; j < A[i] - 'a'; j++) {
            if (chk[j] > chk[A[i] - 'a']) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }

    if (i < n) {
        char ch1 = A[i];
        char ch2 = (char)('a' + j);
        for (int k = 0; k < n; k++) {
            if (A[k] == ch1) A[k] = ch2;
            else if (A[k] == ch2) A[k] = ch1;
        }
    }
}

int main(void) {
    char s[] = "ccad";
    chooseAndSwap(s);
    printf("Choose and swap 'ccad': %s\n", s);
    return 0;
}
