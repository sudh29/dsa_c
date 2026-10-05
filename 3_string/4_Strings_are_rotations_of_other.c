#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areRotations(const char *s1, const char *s2) {
    if (strlen(s1) != strlen(s2)) return false;
    char temp[512];
    snprintf(temp, sizeof(temp), "%s%s", s1, s1);
    return strstr(temp, s2) != NULL;
}

int main(void) {
    const char *s1 = "ABCD", *s2 = "CDAB";
    printf("%s is rotation of %s: %s\n", s2, s1, areRotations(s1, s2) ? "Yes" : "No");
    return 0;
}
