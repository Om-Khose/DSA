#include <stdio.h>

int linear_search(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int recursive_search(int a[], int n, int key, int i) {
    if (i == n) return -1;
    if (a[i] == key) return i;
    return recursive_search(a, n, key, i + 1);
}

int main(void) {
    int n, key;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);

    int x = linear_search(a, n, key);
    int y = recursive_search(a, n, key, 0);
    if (x == -1) printf("Iterative: Not found\n");
    else printf("Iterative: Found at index %d\n", x);
    if (y == -1) printf("Recursive: Not found\n");
    else printf("Recursive: Found at index %d\n", y);
    return 0;
}
