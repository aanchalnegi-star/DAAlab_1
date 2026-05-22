#include <stdio.h>

#define INF 99999

int shortestPath(int graph[100][100],
                 int V,
                 int src,
                 int dest,
                 int k) {

    int dp[100][100][100];

    int i, j, e, a;

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            for(e = 0; e <= k; e++) {
                dp[i][j][e] = INF;
            }
        }
    }

    for(i = 0; i < V; i++)
        dp[i][i][0] = 0;

    for(e = 1; e <= k; e++) {

        for(i = 0; i < V; i++) {

            for(j = 0; j < V; j++) {

                for(a = 0; a < V; a++) {

                    if(graph[i][a] != 0 &&
                       dp[a][j][e - 1] != INF) {

                        int value =
                        graph[i][a] +
                        dp[a][j][e - 1];

                        if(value < dp[i][j][e]) {
                            dp[i][j][e] = value;
                        }
                    }
                }
            }
        }
    }

    return dp[src][dest][k];
}

int main() {

    int V, i, j;

    scanf("%d", &V);

    int graph[100][100];

    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src, dest, k;

    scanf("%d %d", &src, &dest);

    scanf("%d", &k);

    int ans =
    shortestPath(graph, V, src - 1, dest - 1, k);

    if(ans == INF) {
        printf("no path of length k is available");
    }
    else {
        printf("Weight of shortest path from (%d,%d) with %d edges : %d",
               src, dest, k, ans);
    }

    return 0;
}