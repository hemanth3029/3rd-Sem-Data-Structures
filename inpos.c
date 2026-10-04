#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stk[SIZE];
int top = -1;

void push(char x)
{
    if (top == SIZE - 1)
        return;

    top++;
    stk[top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stk[top--];
}

char topElement()
{
    if (top == -1)
        return '\0';

    return stk[top];
}

int priority(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int operatorCheck(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;

    return 0;
}

void convert(char infix[], char postfix[])
{
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (ch == ' ' || ch == '\t')
            continue;

        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && topElement() != '(')
            {
                postfix[k++] = pop();
            }

            if (top != -1)
                pop();
        }
        else if (operatorCheck(ch))
        {
            while (top != -1 &&
                   topElement() != '(' &&
                   priority(topElement()) >= priority(ch))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    fgets(infix, SIZE, stdin);

    infix[strcspn(infix, "\n")] = '\0';

    convert(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}