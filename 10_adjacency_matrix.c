#include <stdio.h>
#define MAX 50
int main(void) {
    int n, adj[MAX][MAX] = {{0}};
    char city[MAX][50];
    printf("Number of cities (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    for (int i = 0; i < n; i++) {
        printf("Name of city %d (no spaces): ", i); scanf("%49s", city[i]);
    }
    int e; printf("Number of direct connections: "); scanf("%d", &e);
    printf("Enter connection pairs using indices 0 to %d:\n", n - 1);
    for (int i = 0; i < e; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) adj[u][v] = adj[v][u] = 1;
        else printf("Invalid pair skipped.\n");
    }
    printf("\nAdjacency Matrix:\n\t");
    for (int i = 0; i < n; i++) printf("%s\t", city[i]);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t", city[i]);
        for (int j = 0; j < n; j++) printf("%d\t", adj[i][j]);
        printf("\n");
    }
    return 0;
}
