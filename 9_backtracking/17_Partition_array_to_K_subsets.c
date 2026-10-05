#include <stdio.h>
#include <stdbool.h>

static bool canPartition(const int a[], int n, int k, int subsetSum[], bool visited[], int target, int cur_idx, int limit_idx) {
    if (subsetSum[cur_idx] == target) {
        if (cur_idx == k - 2) return true;
        return canPartition(a, n, k, subsetSum, visited, target, cur_idx + 1, n - 1);
    }

    for (int i = limit_idx; i >= 0; i--) {
        if (visited[i]) continue;
        int tmp = subsetSum[cur_idx] + a[i];

        if (tmp <= target) {
            visited[i] = true;
            subsetSum[cur_idx] += a[i];
            if (canPartition(a, n, k, subsetSum, visited, target, cur_idx, i - 1))
                return true;
            visited[i] = false;
            subsetSum[cur_idx] -= a[i];
        }
    }
    return false;
}

bool isKPartitionPossible(const int a[], int n, int k) {
    if (k == 1) return true;
    if (n < k) return false;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum % k != 0) return false;

    int target = sum / k;
    int subsetSum[k];
    bool visited[n];
    for (int i = 0; i < k; i++) subsetSum[i] = 0;
    for (int i = 0; i < n; i++) visited[i] = false;

    subsetSum[0] = a[n - 1];
    visited[n - 1] = true;

    return canPartition(a, n, k, subsetSum, visited, target, 0, n - 1);
}

int main(void) {
    int a1[] = {2, 1, 4, 5, 6};
    printf("Can partition into 3 subsets: %s (1)\n", isKPartitionPossible(a1, 5, 3) ? "YES" : "NO");

    int a2[] = {2, 1, 5, 5, 6};
    printf("Can partition into 3 subsets: %s (0)\n", isKPartitionPossible(a2, 5, 3) ? "YES" : "NO");
    return 0;
}
