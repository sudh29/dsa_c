#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x, y, dist;
} Cell;

int minStepToReachTarget(int startX, int startY, int targetX, int targetY, int N) {
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    bool visited[50][50] = {false};
    Cell q[2500];
    int front = 0, rear = 0;

    q[rear++] = (Cell){startX, startY, 0};
    visited[startX][startY] = true;

    while (front < rear) {
        Cell cur = q[front++];
        if (cur.x == targetX && cur.y == targetY) {
            return cur.dist;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q[rear++] = (Cell){nx, ny, cur.dist + 1};
            }
        }
    }
    return -1;
}

int main(void) {
    int N = 6;
    printf("Minimum steps by Knight on %dx%d: %d (expected 3)\n",
           N, N, minStepToReachTarget(4, 5, 1, 1, N));
    return 0;
}
