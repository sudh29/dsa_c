#include <stdio.h>
#include <string.h>

void FirstNonRepeating(const char *A, char *ans) {
    int freq[26] = {0};
    char q[100];
    int front = 0, rear = 0;
    int idx = 0;

    for (int i = 0; A[i] != '\0'; i++) {
        char c = A[i];
        freq[c - 'a']++;
        q[rear++] = c;

        while (front < rear && freq[q[front] - 'a'] > 1) {
            front++;
        }

        if (front == rear) {
            ans[idx++] = '#';
        } else {
            ans[idx++] = q[front];
        }
    }
    ans[idx] = '\0';
}

int main(void) {
    const char *stream = "aabc";
    char ans[32];
    FirstNonRepeating(stream, ans);
    printf("Stream: %s -> First non-repeating stream: %s\n", stream, ans);
    return 0;
}
