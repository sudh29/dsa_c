#include <stdio.h>
#include <string.h>

void countAndSay(int n, char *out, size_t out_sz) {
    if (n <= 0) {
        out[0] = '\0';
        return;
    }
    char cur[4096] = "1";
    char next[4096];

    for (int step = 1; step < n; step++) {
        int len = (int)strlen(cur);
        int next_idx = 0;
        int i = 0;
        while (i < len) {
            int count = 1;
            while (i + 1 < len && cur[i] == cur[i + 1]) {
                count++;
                i++;
            }
            next_idx += snprintf(next + next_idx, sizeof(next) - next_idx, "%d%c", count, cur[i]);
            i++;
        }
        snprintf(cur, sizeof(cur), "%s", next);
    }
    snprintf(out, out_sz, "%s", cur);
}

int main(void) {
    char buf[256];
    countAndSay(4, buf, sizeof(buf));
    printf("Count and Say (4): %s\n", buf);
    return 0;
}
