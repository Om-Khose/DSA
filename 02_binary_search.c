
#include <stdio.h>

int binarySearchRecursive(int a[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (a[mid] == key)
        return mid;

    else if (key < a[mid])
        return binarySearchRecursive(a, low, mid - 1, key);

    else
        return binarySearchRecursive(a, mid + 1, high, key);
}

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;

        else if (key < a[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int key = 50;

    int result = binarySearchRecursive(a, 0, n - 1, key);

    if (result == -1)
        printf("Recursive: Element not found\n");
    else
        printf("Recursive: Element found at index %d\n", result);

    result = binarySearch(a, n, key);

    if (result == -1)
        printf("Non-recursive: Element not found\n");
    else
        printf("Non-recursive: Element found at index %d\n", result);

    return 0;
}
