// Implement a stack using queue

#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

// Push operation
void push(int value)
{
    // Check overflow
    if (rear1 == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    // Insert new element into q2
    rear2++;
    q2[rear2] = value;

    // Move all elements from q1 to q2
    while (front1 <= rear1)
    {
        rear2++;
        q2[rear2] = q1[front1];
        front1++;
    }

    // Copy q2 back to q1
    front1 = 0;
    rear1 = rear2;

    for (int i = 0; i <= rear2; i++)
    {
        q1[i] = q2[i];
    }

    // Reset q2
    front2 = 0;
    rear2 = -1;

    printf("%d pushed into stack.\n", value);
}

// Pop operation
void pop()
{
    if (front1 > rear1)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("%d popped from stack.\n", q1[front1]);

    front1++;

    // If stack becomes empty, reset
    if (front1 > rear1)
    {
        front1 = 0;
        rear1 = -1;
    }
}

// Display operation
void display()
{
    if (front1 > rear1)
    {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack: ");

    for (int i = front1; i <= rear1; i++)
    {
        printf("%d ", q1[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Stack Using Queue ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}