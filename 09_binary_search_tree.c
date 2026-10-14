#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };

struct Node *new_node(int x) {
    struct Node *n = malloc(sizeof *n);
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = x; n->left = n->right = NULL; return n;
}
struct Node *insert_node(struct Node *r, int x) {
    if (!r) return new_node(x);
    if (x < r->data) r->left = insert_node(r->left, x);
    else if (x > r->data) r->right = insert_node(r->right, x);
    return r;
}
int search_node(struct Node *r, int key) {
    if (!r) return 0;
    if (r->data == key) return 1;
    return key < r->data ? search_node(r->left, key) : search_node(r->right, key);
}
struct Node *minimum_node(struct Node *r) {
    while (r && r->left) r = r->left;
    return r;
}
struct Node *delete_node(struct Node *r, int key) {
    if (!r) return NULL;
    if (key < r->data) r->left = delete_node(r->left, key);
    else if (key > r->data) r->right = delete_node(r->right, key);
    else {
        if (!r->left) { struct Node *p = r->right; free(r); return p; }
        if (!r->right) { struct Node *p = r->left; free(r); return p; }
        struct Node *s = minimum_node(r->right);
        r->data = s->data; r->right = delete_node(r->right, s->data);
    }
    return r;
}
void inorder(struct Node *r) {
    if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); }
}
void free_tree(struct Node *r) {
    if (r) { free_tree(r->left); free_tree(r->right); free(r); }
}
int main(void) {
    struct Node *root = NULL; int choice, x;
    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Display inorder 5.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) { free_tree(root); return 1; }
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &x); root = insert_node(root, x); break;
            case 2: printf("Value to delete: "); scanf("%d", &x); root = delete_node(root, x); break;
            case 3: printf("Key to search: "); scanf("%d", &x); printf("%s\n", search_node(root, x) ? "Found" : "Not found"); break;
            case 4: inorder(root); printf("\n"); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
    free_tree(root); return 0;
}
