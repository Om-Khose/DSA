#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { char title[100]; int duration; struct Node *next; };

void read_line(char s[], int size) {
    if (fgets(s, size, stdin)) {
        size_t n = strlen(s);
        if (n && s[n - 1] == '\n') s[n - 1] = '\0';
    }
}
void add_song(struct Node **head, const char title[], int duration) {
    struct Node *n = malloc(sizeof *n);
    if (!n) { printf("Memory allocation failed.\n"); return; }
    snprintf(n->title, sizeof n->title, "%s", title);
    n->duration = duration; n->next = NULL;
    if (!*head) { *head = n; return; }
    struct Node *p = *head;
    while (p->next) p = p->next;
    p->next = n;
}
void display(struct Node *p) {
    int i = 1;
    if (!p) { printf("Playlist is empty.\n"); return; }
    while (p) { printf("%d. %s (%d sec)\n", i++, p->title, p->duration); p = p->next; }
}
void remove_song(struct Node **head, const char title[]) {
    struct Node *p = *head, *prev = NULL;
    while (p && strcmp(p->title, title) != 0) { prev = p; p = p->next; }
    if (!p) { printf("Song not found.\n"); return; }
    if (prev) prev->next = p->next; else *head = p->next;
    free(p); printf("Song removed.\n");
}
void play_song(struct Node *p, const char title[]) {
    while (p && strcmp(p->title, title) != 0) p = p->next;
    if (p) printf("Playing: %s\n", p->title); else printf("Song not found.\n");
}
int main(void) {
    struct Node *head = NULL;
    int choice = 0, duration;
    char title[100], line[30];
    do {
        printf("\n1.Add song 2.Remove song 3.Display playlist 4.Play song 5.Exit\nChoice: ");
        if (!fgets(line, sizeof line, stdin)) break;
        if (sscanf(line, "%d", &choice) != 1) { printf("Invalid choice.\n"); continue; }
        switch (choice) {
            case 1:
                printf("Song title: "); read_line(title, sizeof title);
                printf("Duration in seconds: ");
                if (!fgets(line, sizeof line, stdin) || sscanf(line, "%d", &duration) != 1 || duration < 0) {
                    printf("Invalid duration.\n"); break;
                }
                add_song(&head, title, duration); break;
            case 2: printf("Title to remove: "); read_line(title, sizeof title); remove_song(&head, title); break;
            case 3: display(head); break;
            case 4: printf("Title to play: "); read_line(title, sizeof title); play_song(head, title); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
    while (head) { struct Node *t = head; head = head->next; free(t); }
    return 0;
}
