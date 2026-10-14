#include <stdio.h>
#define MAX 50
void dfs(int u, int n, int adj[MAX][MAX], int visited[MAX], char city[MAX][50]) {
    visited[u] = 1; printf("%s ", city[u]);
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !visited[v]) dfs(v, n, adj, visited, city);
}
int main(void) {
    int n, e, adj[MAX][MAX] = {{0}}, visited[MAX] = {0};
    char city[MAX][50];
    printf("Number of cities (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) return 1;
    for (int i = 0; i < n; i++) { printf("City %d (no spaces): ", i); scanf("%49s", city[i]); }
    printf("Number of connections: "); scanf("%d", &e);
    printf("Enter connected index pairs 0 to %d:\n", n - 1);
    for (int i = 0; i < e; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) adj[u][v] = adj[v][u] = 1;
    }
    int start; printf("Starting city index: "); scanf("%d", &start);
    if (start < 0 || start >= n) { printf("Invalid start index.\n"); return 1; }
    printf("Cities reachable from %s: ", city[start]);
    dfs(start, n, adj, visited, city); printf("\n");
    return 0;
}
