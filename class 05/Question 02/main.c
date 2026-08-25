// circular linked list queue using array->enqeue and dequeue operations,rear & peak,  isfull and isempty operations, display

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if Queue is Empty
int isEmpty()
{
    return (front == -1);
}

// Check if Queue is Full
int isFull()
{
    return ((rear + 1) % MAX == front);
}

// Enqueue
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    // First element
    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("%d inserted into queue\n", value);
}

// Dequeue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);

    // If only one element is present
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Peek - shows front element
void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front element = %d\n", queue[front]);
}

// Rear - shows last element
void rearElement()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Rear element = %d\n", queue[rear]);
}

// Display
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- CIRCULAR QUEUE -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Rear\n");
        printf("5. IsFull\n");
        printf("6. IsEmpty\n");
        printf("7. Display\n");
        printf("8. Exit\n");

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
                peek();
                break;

            case 4:
                rearElement();
                break;

            case 5:
                if (isFull())
                    printf("Queue is Full\n");
                else
                    printf("Queue is Not Full\n");
                break;

            case 6:
                if (isEmpty())
                    printf("Queue is Empty\n");
                else
                    printf("Queue is Not Empty\n");
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}