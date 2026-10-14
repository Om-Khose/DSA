#include <stdio.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;

void insert_element(char x) {
    if ((rear + 1) % MAX == front) { printf("Overflow: queue is full.\n"); return; }
    if (front == -1) front = rear = 0; else rear = (rear + 1) % MAX;
    queue[rear] = x; printf("Inserted %c\n", x);
}
void delete_element(void) {
    if (front == -1) { printf("Underflow: queue is empty.\n"); return; }
    printf("Deleted %c\n", queue[front]);
    if (front == rear) front = rear = -1; else front = (front + 1) % MAX;
}
void display(void) {
    if (front == -1) { printf("Queue is empty.\n"); return; }
    printf("Queue: "); int i = front;
    while (1) { printf("%c ", queue[i]); if (i == rear) break; i = (i + 1) % MAX; }
    printf("\n");
}
int main(void) {
    int choice; char x;
    do {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1: printf("Character: "); scanf(" %c", &x); insert_element(x); break;
            case 2: delete_element(); break;
            case 3: display(); break;
            case 4: printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
