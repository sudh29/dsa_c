#include <stdio.h>
#include <stdbool.h>

static bool isSafe(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

static bool solveSudoku(int grid[9][9]) {
    int row = -1, col = -1;
    bool isEmpty = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) break;
    }
    if (isEmpty) return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(void) {
    int grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid)) {
        printf("Sudoku solved successfully:\n");
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }
    return 0;
}
