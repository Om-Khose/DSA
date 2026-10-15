
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
    int i, j;

    for (i = 0; i < 15; i++)
    {
        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter SGPA: ");
        scanf("%f", &s[i].sgpa);
    }

    for (i = 0; i < 14; i++)
    {
        for (j = 0; j < 14 - i; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nRoll Call List:\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "SGPA");

    for (i = 0; i < 15; i++)
    {
        printf("%-10d %-25s %-10.2f\n",
               s[i].roll, s[i].name, s[i].sgpa);
    }

    return 0;
}
