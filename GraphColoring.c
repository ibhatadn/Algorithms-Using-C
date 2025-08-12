
#include <stdio.h>
#include <stdbool.h>

#define V 10

int graph[V][V];
int color[V];

bool isSafe(int v, int c, int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoring(int v, int m, int n) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, n)) {
            color[v] = c;
            if (graphColoring(v + 1, m, n))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (graphColoring(0, m, n)) {
        printf("Solution exists. Assigned colors:\n");
        for (int i = 0; i < n; i++)
            printf("Vertex %d ---> Color %d\n", i, color[i]);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
