#include <stdio.h>
#include <string.h>

void reverseString(char *s) {
    int left = 0, right = (int)strlen(s) - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main(void) {
    char s[] = "hello";
    printf("Original: %s | ", s);
    reverseString(s);
    printf("Reversed: %s\n", s);
    return 0;
}
