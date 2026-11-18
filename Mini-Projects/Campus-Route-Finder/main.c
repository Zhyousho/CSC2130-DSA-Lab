#include <stdio.h>

#define V 5

static void bfs(int graph[V][V], int start, int target) {
    int visited[V] = {0}, parent[V];
    int queue[V], front = 0, rear = 0;

    for (int i = 0; i < V; i++) parent[i] = -1;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        if (u == target) break;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                queue[rear++] = v;
            }
        }
    }

    if (!visited[target]) {
        puts("No route found.");
        return;
    }

    {
        int path[V], count = 0, x = target;
        while (x != -1) {
            path[count++] = x;
            x = parent[x];
        }
        printf("Route: ");
        for (int i = count - 1; i >= 0; i--)
            printf("%d%s", path[i], i ? " -> " : "\n");
    }
}

int main(void) {
    int graph[V][V] = {{0}};
    /* 0=Gate, 1=Library, 2=Canteen, 3=Lab, 4=Auditorium */
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][4] = graph[4][3] = 1;

    bfs(graph, 0, 4);
    return 0;
}
