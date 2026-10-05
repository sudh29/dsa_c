#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static int sol_count = 0;

static bool isSafe(const int board[], int row, int col) {
    for (int prev_col = 0; prev_col < col; prev_col++) {
        int prev_row = board[prev_col];
        if (prev_row == row || abs(prev_row - row) == abs(prev_col - col)) {
            return false;
        }
    }
    return true;
}

static void solveNQ(int board[], int col, int n, int print_mode) {
    if (col == n) {
        sol_count++;
        if (print_mode) {
            printf("[ ");
            for (int i = 0; i < n; i++) printf("%d ", board[i]);
            printf("]\n");
        }
        return;
    }
    for (int row = 1; row <= n; row++) {
        if (isSafe(board, row, col)) {
            board[col] = row;
            solveNQ(board, col + 1, n, print_mode);
        }
    }
}

int main(void) {
    int n = 4;
    int board[4];

    sol_count = 0;
    solveNQ(board, 0, n, 0);
    printf("N-Queens (n=4) solutions count: %d\n", sol_count);

    solveNQ(board, 0, n, 1);
    return 0;
}
