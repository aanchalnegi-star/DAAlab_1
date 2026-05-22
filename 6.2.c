#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
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

    int color[100];

    for(i = 0; i < n; i++)
        color[i] = -1;

    color[0] = 0;

    enqueue(0);

    int bipartite = 1;

    while(!isEmpty()) {

        int u = dequeue();

        for(i = 0; i < n; i++) {

            if(graph[u][i]) {

                if(color[i] == -1) {
                    color[i] = 1 - color[u];
                    enqueue(i);
                }

                else if(color[i] == color[u]) {
                    bipartite = 0;
                    break;
                }
            }
        }
    }

    if(bipartite)
        printf("Yes Bipartite");
    else
        printf("Not Bipartite");

    return 0;
}