#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char title[100];
    float duration;
    struct node *next;
} *head = NULL;

void addSong() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter song title: ");
    fgets(newnode->title, 100, stdin);
    newnode->title[strcspn(newnode->title, "\n")] = '\0';

    printf("Enter duration in minutes: ");
    scanf("%f", &newnode->duration);
    getchar();

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Song added successfully.\n");
}

void removeSong() {
    struct node *temp = head, *prev = NULL;
    char title[100];

    printf("Enter song title to remove: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Song removed successfully.\n");
}

void displayPlaylist() {
    struct node *temp = head;

    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\nMusic Playlist:\n");

    while (temp != NULL) {
        printf("Song: %s | Duration: %.2f minutes\n",
               temp->title, temp->duration);
        temp = temp->next;
    }
}

void playSong() {
    struct node *temp = head;
    char title[100];

    printf("Enter song title to play: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Now playing: %s (%.2f minutes)\n",
                   temp->title, temp->duration);
            return;
        }

        temp = temp->next;
    }

    printf("Song not found in playlist.\n");
}

int main() {
    int choice;

    do {
        printf("\n----- Music Playlist -----\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addSong();
                break;

            case 2:
                removeSong();
                break;

            case 3:
                displayPlaylist();
                break;

            case 4:
                playSong();
                break;

            case 5:
                printf("Exiting playlist.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
