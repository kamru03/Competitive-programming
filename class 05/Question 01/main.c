// singly queueu using array->enqeue and dequeue operations, isfull and isempty operations, display

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull()
{
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty()
{
    return front == -1 || front > rear;
}

// Enqueue operation
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);
    front++;

    // Reset queue when all elements are deleted
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Display operation
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Is Full\n");
        printf("4. Is Empty\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                if (isFull())
                    printf("Queue is Full\n");
                else
                    printf("Queue is Not Full\n");
                break;

            case 4:
                if (isEmpty())
                    printf("Queue is Empty\n");
                else
                    printf("Queue is Not Empty\n");
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}