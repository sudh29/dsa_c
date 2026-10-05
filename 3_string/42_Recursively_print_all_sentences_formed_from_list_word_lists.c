#include <stdio.h>

static void printSentencesRec(int R, int C, const char *words[R][C], int row, const char *current[]) {
    if (row == R) {
        for (int i = 0; i < R; i++) {
            printf("%s ", current[i]);
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < C; c++) {
        current[row] = words[row][c];
        printSentencesRec(R, C, words, row + 1, current);
    }
}

int main(void) {
    const char *words[3][2] = {
        {"you", "we"},
        {"have", "are"},
        {"sleep", "eat"}
    };
    const char *current[3];
    printf("Generated sentences:\n");
    printSentencesRec(3, 2, words, 0, current);
    return 0;
}
