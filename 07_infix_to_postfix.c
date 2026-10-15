
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 15

char stack[MAX];
int top = -1;


void push(char item)
{
    if (top >= MAX - 1)
    {
        printf("\nStack Overflow.");
        exit(1);
    }
    else
    {
        stack[++top] = item;
    }
}

// Function to pop an element from the stack
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}

int precedence(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        case '(': 
        case ')': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char item, x;

    push('(');

    if (strlen(infix) >= MAX - 1)
    {
        printf("Expression too long.\n");
        exit(1);
    }

    strcat(infix, ")");

    for (i = 0; infix[i] != '\0'; i++)
    {
        item = infix[i];

        if (item == '(')
        {
            push(item);
        }
        else if (isalnum((unsigned char)item))
        {
            postfix[j++] = item;
        }
        else if (item == '+' || item == '-' ||
                 item == '*' || item == '/')
        {
            x = pop();

            while (precedence(x) >= precedence(item))
            {
                postfix[j++] = x;
                x = pop();
            }

            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();

            while (x != '(')
            {
                postfix[j++] = x;
                x = pop();
            }
        }
        else if (item == ' ')
        {
            continue;
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            exit(1);
        }
    }

    postfix[j] = '\0';
}


int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter Infix expression: ");

    if (fgets(infix, sizeof(infix), stdin) == NULL)
        return 1;

    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: ");
    puts(postfix);

    return 0;
}
