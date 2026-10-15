
#include <stdio.h>

#define MAX 10

int main()
{
    int graph[MAX][MAX];
    int n, i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
