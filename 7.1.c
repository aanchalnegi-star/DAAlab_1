#include <stdio.h>

#define INF 99999
#define MAX 100

struct Node {
    int dist;
    int visited;
    int parent;
};

void printPath(struct Node vertex[], int j) {

    if(vertex[j].parent == -1) {
        printf("%d ", j + 1);
        return;
    }

    printPath(vertex, vertex[j].parent);

    printf("%d ", j + 1);
}

int minDistance(struct Node vertex[], int V) {

    int min = INF;
    int minIndex = -1;

    int i;

    for(i = 0; i < V; i++) {

        if(vertex[i].visited == 0 &&
           vertex[i].dist < min) {

            min = vertex[i].dist;
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int V, int src) {

    struct Node vertex[MAX];

    int i, count, v;

    for(i = 0; i < V; i++) {

        vertex[i].dist = INF;
        vertex[i].visited = 0;
        vertex[i].parent = -1;
    }

    vertex[src].dist = 0;

    for(count = 0; count < V - 1; count++) {

        int u = minDistance(vertex, V);

        vertex[u].visited = 1;

        for(v = 0; v < V; v++) {

            if(graph[u][v] &&
               vertex[v].visited == 0 &&
               vertex[u].dist + graph[u][v] < vertex[v].dist) {

                vertex[v].dist =
                vertex[u].dist + graph[u][v];

                vertex[v].parent = u;
            }
        }
    }

    for(i = 0; i < V; i++) {

        if(i != src) {

            printPath(vertex, i);

            printf(":%d\n", vertex[i].dist);
        }
    }
}

int main() {

    int V, i, j;

    scanf("%d", &V);

    int graph[MAX][MAX];

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {

            scanf("%d", &graph[i][j]);
        }
    }

    int src;

    scanf("%d", &src);

    dijkstra(graph, V, src - 1);

    return 0;
}