
#include <stdio.h>

#define MAX 20

struct Edge
{
    int src, dest, cost;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int u, int v)
{
    parent[u] = v;
}

int main()
{
    struct Edge edges[MAX], temp;
    int n, e, i, j;
    int u, v, count = 0, totalCost = 0;

    printf("Enter number of offices: ");
    scanf("%d", &n);

    printf("Enter number of possible connections: ");
    scanf("%d", &e);

    printf("Enter source, destination and cost of each edge:\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].cost);
    }

    // Sort edges by cost using Bubble Sort
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - 1 - i; j++)
        {
            if (edges[j].cost > edges[j + 1].cost)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    // Kruskal's Algorithm
    for (i = 0; i < e && count < n - 1; i++)
    {
        u = find(edges[i].src);
        v = find(edges[i].dest);

        if (u != v)
        {
            printf("%d - %d : %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].cost);

            totalCost += edges[i].cost;
            unionSet(u, v);
            count++;
        }
    }

    if (count == n - 1)
        printf("Total cost of laying cables: %d\n", totalCost);
    else
        printf("Network cannot be fully connected.\n");

    return 0;
}
