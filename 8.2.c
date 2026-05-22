#include <stdio.h>

#define MAX 100

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Edge edges[MAX];

int parent[MAX];

int edgeCount = 0;

int find(int i) {

    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int u, int v) {

    int uParent = find(u);
    int vParent = find(v);

    parent[uParent] = vParent;
}

void sortEdges() {

    int i, j;

    for(i = 0; i < edgeCount - 1; i++) {

        for(j = 0; j < edgeCount - i - 1; j++) {

            if(edges[j].weight > edges[j + 1].weight) {

                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(int V) {

    sortEdges();

    int i;

    for(i = 0; i < V; i++)
        parent[i] = i;

    int minWeight = 0;
    int edgesUsed = 0;

    for(i = 0; i < edgeCount; i++) {

        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(u);
        int setV = find(v);

        if(setU != setV) {

            unionSet(setU, setV);

            minWeight += edges[i].weight;

            edgesUsed++;

            if(edgesUsed == V - 1)
                break;
        }
    }

    printf("Minimum Spanning Weight: %d",
           minWeight);
}

int main() {

    int V, i, j;

    scanf("%d", &V);

    int graph[MAX][MAX];

    for(i = 0; i < V; i++) {

        for(j = 0; j < V; j++) {

            scanf("%d", &graph[i][j]);

            if(graph[i][j] != 0 && i < j) {

                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];

                edgeCount++;
            }
        }
    }

    kruskal(V);

    return 0;
}