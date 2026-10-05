#include <stdio.h>
#include <string.h>

void reverseWord(char *str) {
    int left = 0, right = (int)strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main(void) {
    char s[] = "Geeks";
    printf("Original: %s | ", s);
    reverseWord(s);
    printf("Reversed: %s\n", s);
    return 0;
}
