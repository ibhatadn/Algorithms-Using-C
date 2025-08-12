
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(start);
    return 0;
}
