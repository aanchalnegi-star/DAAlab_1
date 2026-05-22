#include <stdio.h>

int found = 0;

void DFS(int graph[100][100], int visited[], int v, int dest, int n) {

    visited[v] = 1;

    if(v == dest) {
        found = 1;
        return;
    }

    int i;

    for(i = 0; i < n; i++) {

        if(graph[v][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, i, dest, n);
        }
    }
}

int main() {

    int n, i, j;

    scanf("%d", &n);

    int graph[100][100];
    int visited[100] = {0};

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source, destination;

    scanf("%d %d", &source, &destination);

    DFS(graph, visited, source, destination, n);

    if(found)
        printf("Yes Path Exists");
    else
        printf("No Such Path Exists");

    return 0;
}