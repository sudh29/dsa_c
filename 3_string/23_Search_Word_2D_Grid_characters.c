#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static int x_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
static int y_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

static bool search2D(int R, int C, const char grid[R][C], int row, int col, const char *word) {
    if (grid[row][col] != word[0]) return false;
    int len = (int)strlen(word);

    for (int dir = 0; dir < 8; dir++) {
        int k, rd = row + x_dir[dir], cd = col + y_dir[dir];
        for (k = 1; k < len; k++) {
            if (rd < 0 || rd >= R || cd < 0 || cd >= C) break;
            if (grid[rd][cd] != word[k]) break;
            rd += x_dir[dir];
            cd += y_dir[dir];
        }
        if (k == len) return true;
    }
    return false;
}

int main(void) {
    char grid[3][3] = {
        {'a', 'b', 'c'},
        {'d', 'r', 'f'},
        {'g', 'h', 'i'}
    };
    const char *word = "abc";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (search2D(3, 3, grid, r, c, word)) {
                printf("Word found starting at: [%d, %d]\n", r, c);
                return 0;
            }
        }
    }
    return 0;
}
