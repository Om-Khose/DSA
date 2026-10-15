
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

// BFS function
void BFS(int start)
{
    int front = 0, rear = 0;
    int i, city;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        city = queue[front++];
        printf("%d ", city);

        for (i = 0; i < n; i++)
        {
            if (graph[city][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

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

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter starting city (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Cities reachable from city %d: ", start);
    BFS(start);

    printf("\n");

    return 0;
}
