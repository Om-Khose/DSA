#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 1000
struct Edge { int u, v, weight; };
int parent[MAXV], rank_value[MAXV];

int compare_edges(const void *a, const void *b) {
    const struct Edge *x = a, *y = b;
    return (x->weight > y->weight) - (x->weight < y->weight);
}
int find_set(int x) {
    if (parent[x] != x) parent[x] = find_set(parent[x]);
    return parent[x];
}
int union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a == b) return 0;
    if (rank_value[a] < rank_value[b]) { int t = a; a = b; b = t; }
    parent[b] = a;
    if (rank_value[a] == rank_value[b]) rank_value[a]++;
    return 1;
}
int main(void) {
    int n, m; struct Edge edges[MAXE];
    printf("Number of offices (vertices, 1-%d): ", MAXV);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXV) return 1;
    printf("Number of possible cables (edges, 0-%d): ", MAXE);
    if (scanf("%d", &m) != 1 || m < 0 || m > MAXE) return 1;
    printf("Enter each edge: office1 office2 cost (indices 0 to %d)\n", n - 1);
    for (int i = 0; i < m; i++)
        if (scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].weight) != 3) return 1;
    for (int i = 0; i < n; i++) { parent[i] = i; rank_value[i] = 0; }
    qsort(edges, m, sizeof edges[0], compare_edges);
    int total = 0, selected = 0;
    printf("Edges selected for MST:\n");
    for (int i = 0; i < m && selected < n - 1; i++) {
        if (edges[i].u < 0 || edges[i].u >= n || edges[i].v < 0 || edges[i].v >= n) continue;
        if (union_sets(edges[i].u, edges[i].v)) {
            printf("%d -- %d : cost %d\n", edges[i].u, edges[i].v, edges[i].weight);
            total += edges[i].weight; selected++;
        }
    }
    if (selected != n - 1) printf("Graph is disconnected; a complete MST does not exist.\n");
    else printf("Total minimum cost: %d\n", total);
    return 0;
}
