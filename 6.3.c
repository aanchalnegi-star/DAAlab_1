#include <stdio.h>

int hasCycle = 0;

void DFS(int graph[100][100], int visited[],
         int recStack[], int node, int n) {

    visited[node] = 1;
    recStack[node] = 1;

    int i;

    for(i = 0; i < n; i++) {

        if(graph[node][i]) {

            if(!visited[i]) {
                DFS(graph, visited, recStack, i, n);
            }

            else if(recStack[i]) {
                hasCycle = 1;
                return;
            }
        }
    }

    recStack[node] = 0;
}

int main() {

    int n, i, j;

    scanf("%d", &n);

    int graph[100][100];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[100] = {0};
    int recStack[100] = {0};

    for(i = 0; i < n; i++) {

        if(!visited[i]) {
            DFS(graph, visited, recStack, i, n);
        }
    }

    if(hasCycle)
        printf("Yes Cycle Exists");
    else
        printf("No Cycle Exists");

    return 0;
}