
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1, n;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
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

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    bfs(start);
    return 0;
}
