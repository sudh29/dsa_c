#include <stdio.h>
#include <string.h>

static int starting[20];
static int ending[20];
static int diameter[20];

static int dfs(int w, int *min_dia) {
    if (starting[w] == 0) return w;
    if (diameter[w] < *min_dia) *min_dia = diameter[w];
    return dfs(starting[w], min_dia);
}

int main(void) {
    int n = 9, p = 6;
    int a[] = {7, 5, 4, 2, 9, 3};
    int b[] = {4, 9, 6, 8, 7, 1};
    int d[] = {98, 72, 10, 22, 17, 66};

    memset(starting, 0, sizeof(starting));
    memset(ending, 0, sizeof(ending));
    memset(diameter, 0, sizeof(diameter));

    for (int i = 0; i < p; i++) {
        int u = a[i], v = b[i], w = d[i];
        starting[u] = v;
        ending[v] = u;
        diameter[u] = w;
    }

    int count = 0;
    for (int j = 1; j <= n; j++) {
        if (ending[j] == 0 && starting[j]) {
            int min_dia = 10000000;
            dfs(j, &min_dia);
            count++;
        }
    }
    printf("Water connection components count: %d\n", count);
    return 0;
}
