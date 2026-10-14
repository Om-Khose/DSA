#include <stdio.h>
#include <ctype.h>
#define MAX 256

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
int main(void) {
    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1, k = 0;
    printf("Enter infix expression (no spaces): ");
    if (scanf("%255s", infix) != 1) return 1;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum((unsigned char)c)) postfix[k++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') postfix[k++] = stack[top--];
            if (top >= 0) top--;
        } else {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && c != '^')))
                postfix[k++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top >= 0) postfix[k++] = stack[top--];
    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
