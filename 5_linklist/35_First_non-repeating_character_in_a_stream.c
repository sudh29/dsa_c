#include <stdio.h>
#include <string.h>

void FirstNonRepeating(const char *stream, char *out, size_t out_sz) {
    int count[26] = {0};
    char queue[1024];
    int q_head = 0, q_tail = 0;
    int idx = 0;

    for (int i = 0; stream[i]; i++) {
        char c = stream[i];
        count[c - 'a']++;
        queue[q_tail++] = c;

        while (q_head < q_tail && count[queue[q_head] - 'a'] > 1) {
            q_head++;
        }

        if ((size_t)idx + 1 < out_sz) {
            out[idx++] = (q_head < q_tail) ? queue[q_head] : '#';
        }
    }
    out[idx] = '\0';
}

int main(void) {
    const char *stream = "aabc";
    char res[32];
    FirstNonRepeating(stream, res, sizeof(res));
    printf("Stream: %s -> %s\n", stream, res);
    return 0;
}
