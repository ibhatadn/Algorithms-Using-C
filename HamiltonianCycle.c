
#include <stdio.h>
#include <stdbool.h>

#define V 10

int graph[V][V];
int path[V];

bool isSafe(int v, int pos, int path[], int n) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int path[], int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos, path, n)) {
            path[pos] = v;
            if (hamCycleUtil(path, pos + 1, n))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(path, 1, n)) {
        printf("Hamiltonian Cycle Exists:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle exists\n");
    }

    return 0;
}
