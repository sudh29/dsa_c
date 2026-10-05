#include <stdio.h>
#include <string.h>

int maxSubStr(const char *str) {
    int count0 = 0, count1 = 0, ans = 0;
    int n = (int)strlen(str);

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') count0++;
        else count1++;
        if (count0 == count1) ans++;
    }
    if (count0 != count1) return -1;
    return ans;
}

int main(void) {
    const char *s = "0100110101";
    printf("Max 0/1 substrings for %s: %d\n", s, maxSubStr(s));
    return 0;
}
