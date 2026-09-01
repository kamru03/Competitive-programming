// Check whether parenthesis are balanced or not 

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push into stack
void push(char ch)
{
    stack[++top] = ch;
}

// Pop from stack
char pop()
{
    return stack[top--];
}

// Check matching brackets
int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

int main()
{
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        // If opening bracket, push it
        if (expression[i] == '(' ||
            expression[i] == '{' ||
            expression[i] == '[')
        {
            push(expression[i]);
        }

        // If closing bracket
        else if (expression[i] == ')' ||
                 expression[i] == '}' ||
                 expression[i] == ']')
        {
            // No opening bracket available
            if (top == -1)
            {
                printf("Parentheses are NOT Balanced\n");
                return 0;
            }

            // Check matching bracket
            if (!isMatching(pop(), expression[i]))
            {
                printf("Parentheses are NOT Balanced\n");
                return 0;
            }
        }
    }

    // Stack should be empty
    if (top == -1)
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are NOT Balanced\n");

    return 0;
}