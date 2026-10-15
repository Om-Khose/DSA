#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[30];
    float sgpa;
};

int main()
{
    struct student s[15], key;
    int i, j;

    for (i = 0; i < 15; i++)
    {
        printf("Enter Roll No, Name and SGPA: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].sgpa);
    }

    for (i = 1; i < 15; i++)
    {
        key = s[i];
        j = i - 1;

        while (j >= 0 && strcmp(s[j].name, key.name) > 0)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }

    printf("\nRoll No\tName\tSGPA\n");

    for (i = 0; i < 15; i++)
    {
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].sgpa);
    }

    return 0;
}
