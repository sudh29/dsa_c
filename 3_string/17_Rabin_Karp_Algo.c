#include <stdio.h>
#include <string.h>

#define D 256
#define Q 101

void searchRabinKarp(const char *pat, const char *txt) {
    int M = (int)strlen(pat);
    int N = (int)strlen(txt);
    int p = 0; // hash for pattern
    int t = 0; // hash for text
    int h = 1;

    for (int i = 0; i < M - 1; i++) {
        h = (h * D) % Q;
    }

    for (int i = 0; i < M; i++) {
        p = (D * p + (unsigned char)pat[i]) % Q;
        t = (D * t + (unsigned char)txt[i]) % Q;
    }

    printf("Rabin-Karp matches: ");
    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if (j == M) {
                printf("%d ", i);
            }
        }
        if (i < N - M) {
            t = (D * (t - (unsigned char)txt[i] * h) + (unsigned char)txt[i + M]) % Q;
            if (t < 0) t += Q;
        }
    }
    printf("\n");
}

int main(void) {
    const char *txt = "GEEKS FOR GEEKS";
    const char *pat = "GEEK";
    searchRabinKarp(pat, txt);
    return 0;
}
