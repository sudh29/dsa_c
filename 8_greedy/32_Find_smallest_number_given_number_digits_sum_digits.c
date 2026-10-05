#include <stdio.h>

void smallestNumber(int S, int D, char *out, size_t out_sz) {
    if (S == 0) {
        if (D == 1) {
            snprintf(out, out_sz, "0");
        } else {
            snprintf(out, out_sz, "-1");
        }
        return;
    }
    if (S > 9 * D) {
        snprintf(out, out_sz, "-1");
        return;
    }

    int res[D];
    S -= 1; // Reserve 1 for the most significant digit

    for (int i = D - 1; i > 0; i--) {
        if (S > 9) {
            res[i] = 9;
            S -= 9;
        } else {
            res[i] = S;
            S = 0;
        }
    }
    res[0] = S + 1;

    int idx = 0;
    for (int i = 0; i < D && (size_t)idx + 1 < out_sz; i++) {
        out[idx++] = (char)('0' + res[i]);
    }
    out[idx] = '\0';
}

int main(void) {
    char buf[32];
    smallestNumber(9, 2, buf, sizeof(buf));
    printf("Smallest number (S=9, D=2): %s (expected 18)\n", buf);
    smallestNumber(20, 3, buf, sizeof(buf));
    printf("Smallest number (S=20, D=3): %s (expected 299)\n", buf);
    smallestNumber(25, 2, buf, sizeof(buf));
    printf("Smallest number (S=25, D=2): %s (expected -1)\n", buf);
    return 0;
}
