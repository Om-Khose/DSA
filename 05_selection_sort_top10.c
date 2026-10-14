#include <stdio.h>

struct Student { int roll; char name[30]; float sgpa; };

int main(void) {
    struct Student s[15] = {
        {12,"Aarav",8.1}, {3,"Aditi",9.2}, {15,"Kabir",7.8},
        {1,"Anaya",9.5}, {9,"Ishaan",8.7}, {6,"Diya",9.0},
        {14,"Rohan",7.6}, {2,"Meera",9.1}, {11,"Vivaan",8.3},
        {5,"Sara",8.9}, {8,"Arjun",8.0}, {4,"Ira",9.4},
        {10,"Neha",8.5}, {7,"Reyansh",7.9}, {13,"Kavya",8.8}
    };
    for (int i = 0; i < 14; i++) {
        int best = i;
        for (int j = i + 1; j < 15; j++)
            if (s[j].sgpa > s[best].sgpa) best = j;
        if (best != i) {
            struct Student t = s[i]; s[i] = s[best]; s[best] = t;
        }
    }
    printf("Top 10 students:\nRoll No\tName\tSGPA\n");
    for (int i = 0; i < 10; i++)
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].sgpa);
    return 0;
}
