//  Detect the cycle in a single LL

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

// Detect cycle
void detectCycle() {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Cycle detected\n");
            return;
        }
    }

    printf("No cycle detected\n");
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
    int n, value, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertBeginning(value);
    }

    printf("Linked List: ");
    display();

    printf("\nDo you want to create a cycle? (1-Yes / 0-No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Create cycle: last node points to head
        struct Node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;
    }

    detectCycle();

    return 0;
}