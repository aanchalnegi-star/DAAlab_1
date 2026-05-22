#include <stdio.h>

#define INF 99999
#define MAX 100

struct Node {
    int dist;
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

void bellmanFord(int graph[MAX][MAX], int V, int src) {

    struct Node vertex[MAX];

    int i, j, u, v;

    for(i = 0; i < V; i++) {

        vertex[i].dist = INF;
        vertex[i].parent = -1;
    }

    vertex[src].dist = 0;

    for(i = 1; i < V; i++) {

        for(u = 0; u < V; u++) {

            for(v = 0; v < V; v++) {

                if(graph[u][v] &&
                   vertex[u].dist != INF &&
                   vertex[u].dist + graph[u][v]
                   < vertex[v].dist) {

                    vertex[v].dist =
                    vertex[u].dist + graph[u][v];

                    vertex[v].parent = u;
                }
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

    bellmanFord(graph, V, src - 1);

    return 0;
}