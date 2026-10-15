#include <stdio.h>

struct student
{
    int roll;
    char name[30];
    float sgpa;
};

int main()
{
    struct student s[15], temp;
    int i, j, max;

    for (i = 0; i < 15; i++)
    {
        printf("Enter Roll No, Name and SGPA: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].sgpa);
    }

    for (i = 0; i < 14; i++)
    {
        max = i;

        for (j = i + 1; j < 15; j++)
        {
            if (s[j].sgpa > s[max].sgpa)
                max = j;
        }

        temp = s[i];
        s[i] = s[max];
        s[max] = temp;
    }

    printf("\nTop 10 Toppers:\n");
    printf("Roll No\tName\tSGPA\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d\t%s\t%.2f\n",
               s[i].roll, s[i].name, s[i].sgpa);
    }

    return 0;
}
