
#include <stdio.h>

int searchRecursive(int a[], int i, int n, int key)
{
    if (i == n)
        return -1;

    if (a[i] == key)
        return i;

    return searchRecursive(a, i + 1, n, key);
}

int search(int a[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int key = 40;

    int result = searchRecursive(a, 0, 5, key);

    if (result == -1)
        printf("Recursive: Key not found\n");
    else
        printf("Recursive: Key found at index %d\n", result);

    result = search(a, 5, key);

    if (result == -1)
        printf("Non-recursive: Key not found\n");
    else
        printf("Non-recursive: Key found at index %d\n", result);

    return 0;
}
