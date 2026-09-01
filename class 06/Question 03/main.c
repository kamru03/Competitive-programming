// Implement two stack in a single array

#include <stdio.h>

#define MAX 10

int arr[MAX];

int top1 = -1;
int top2 = MAX;

void push1(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow!\n");
        return;
    }

    top1++;
    arr[top1] = value;

    printf("%d pushed into Stack 1\n", value);
}

void push2(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow!\n");
        return;
    }

    top2--;
    arr[top2] = value;

    printf("%d pushed into Stack 2\n", value);
}

void pop1()
{
    if (top1 == -1)
    {
        printf("Stack 1 is Empty!\n");
        return;
    }

    printf("%d popped from Stack 1\n", arr[top1]);
    top1--;
}

void pop2()
{
    if (top2 == MAX)
    {
        printf("Stack 2 is Empty!\n");
        return;
    }

    printf("%d popped from Stack 2\n", arr[top2]);
    top2++;
}

void display1()
{
    if (top1 == -1)
    {
        printf("Stack 1 is Empty!\n");
        return;
    }

    printf("Stack 1: ");

    for (int i = top1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void display2()
{
    if (top2 == MAX)
    {
        printf("Stack 2 is Empty!\n");
        return;
    }

    printf("Stack 2: ");

    for (int i = top2; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== TWO STACKS IN ONE ARRAY =====\n");

        printf("1. Push in Stack 1\n");
        printf("2. Push in Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}