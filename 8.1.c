#include <stdio.h>

#define MAX 100
#define INF 99999

struct Node {
    int vertex;
    int key;
};

struct Node pq[MAX];
int size = 0;

void swap(struct Node *a, struct Node *b) {

    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void insert(struct Node value) {

    int i = size;

    pq[size++] = value;

    while(i > 0 &&
          pq[(i - 1) / 2].key > pq[i].key) {

        swap(&pq[i], &pq[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

struct Node extractMin() {

    struct Node minNode = pq[0];

    pq[0] = pq[--size];

    int i = 0;

    while(1) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if(left < size &&
           pq[left].key < pq[smallest].key)

            smallest = left;

        if(right < size &&
           pq[right].key < pq[smallest].key)

            smallest = right;

        if(smallest != i) {

            swap(&pq[i], &pq[smallest]);

            i = smallest;
        }
        else {
            break;
        }
    }

    return minNode;
}

void prims(int graph[MAX][MAX], int V) {

    int parent[MAX];
    int key[MAX];
    int mst[MAX] = {0};

    int i, v;

    for(i = 0; i < V; i++) {

        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    struct Node start;
    start.vertex = 0;
    start.key = 0;

    insert(start);

    while(size > 0) {

        struct Node current = extractMin();

        int u = current.vertex;

        mst[u] = 1;

        for(v = 0; v < V; v++) {

            if(graph[u][v] &&
               mst[v] == 0 &&
               graph[u][v] < key[v]) {

                key[v] = graph[u][v];

                parent[v] = u;

                struct Node temp;
                temp.vertex = v;
                temp.key = key[v];

                insert(temp);
            }
        }
    }

    int totalCost = 0;

    printf("Edges in MST:\n");

    for(i = 1; i < V; i++) {

        printf("%d - %d : %d\n",
               parent[i] + 1,
               i + 1,
               graph[i][parent[i]]);

        totalCost += graph[i][parent[i]];
    }

    printf("Minimum Cost = %d", totalCost);
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

    prims(graph, V);

    return 0;
}