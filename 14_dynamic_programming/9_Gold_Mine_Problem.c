#include <stdio.h>

static int max(int a, int b) { return a > b ? a : b; }

int maxGold(int n, int m, int M[][3]) {
    for (int col = m - 2; col >= 0; col--) {
        for (int row = 0; row < n; row++) {
            int right = M[row][col + 1];
            int right_up = (row > 0) ? M[row - 1][col + 1] : 0;
            int right_down = (row < n - 1) ? M[row + 1][col + 1] : 0;
            M[row][col] += max(right, max(right_up, right_down));
        }
    }
    int max_gold = 0;
    for (int row = 0; row < n; row++) {
        max_gold = max(max_gold, M[row][0]);
    }
    return max_gold;
}

int main(void) {
    int mine[3][3] = {
        {1, 3, 3},
        {2, 1, 4},
        {0, 6, 4}
    };
    printf("Max gold: %d (expected 12)\n", maxGold(3, 3, mine));
    return 0;
}
