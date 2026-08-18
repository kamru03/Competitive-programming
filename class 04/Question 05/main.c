// Find the nth node of a single LL

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Find nth node
void findNthNode(int n) {
    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < n) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
    }
    else {
        printf("Nth node = %d\n", temp->data);
    }
}

// Display
void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int n, value, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertBeginning(value);
    }

    printf("Linked List: ");
    display();

    printf("Enter position of node: ");
    scanf("%d", &position);

    findNthNode(position);

    return 0;
}