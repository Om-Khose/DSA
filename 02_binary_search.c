#include <stdio.h>

int binary_search(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int recursive_binary_search(int a[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key)
        return recursive_binary_search(a, mid + 1, high, key);
    return recursive_binary_search(a, low, mid - 1, key);
}

int main(void) {
    int n, key;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int a[n];
    printf("Enter sorted elements in ascending order: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    printf("Iterative index: %d\n", binary_search(a, n, key));
    printf("Recursive index: %d\n", recursive_binary_search(a, 0, n - 1, key));
    return 0;
}
