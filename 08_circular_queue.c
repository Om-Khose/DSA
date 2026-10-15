
#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

// Insertion
void enqueue(char value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("%c inserted\n", value);
}

// Deletion
void dequeue()
{
    char value;

    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    value = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("%c deleted\n", value);
}

// Display
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Circular Queue: ");

    for (i = front; i != rear; i = (i + 1) % MAX)
        printf("%c ", queue[i]);

    printf("%c\n", queue[rear]);
}

// Main function
int main()
{
    int choice;
    char value;

    while (1)
    {
        printf("\n--- Circular Queue ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Demonstrate Overflow/Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter character: ");
                scanf(" %c", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if ((rear + 1) % MAX == front)
                    printf("Queue Overflow\n");
                else if (front == -1)
                    printf("Queue Underflow: Queue is Empty\n");
                else
                    printf("Queue is neither Full nor Empty\n");
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
