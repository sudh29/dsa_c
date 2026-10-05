#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areIsomorphic(const char *str1, const char *str2) {
    int m = (int)strlen(str1), n = (int)strlen(str2);
    if (m != n) return false;

    int map1[256], map2[256];
    for (int i = 0; i < 256; i++) {
        map1[i] = -1;
        map2[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        unsigned char c1 = (unsigned char)str1[i];
        unsigned char c2 = (unsigned char)str2[i];

        if (map1[c1] == -1 && map2[c2] == -1) {
            map1[c1] = c2;
            map2[c2] = c1;
        } else if (map1[c1] != c2 || map2[c2] != c1) {
            return false;
        }
    }
    return true;
}

int main(void) {
    printf("aab & xxy isomorphic: %s\n", areIsomorphic("aab", "xxy") ? "Yes" : "No");
    printf("aab & xyz isomorphic: %s\n", areIsomorphic("aab", "xyz") ? "Yes" : "No");
    return 0;
}
