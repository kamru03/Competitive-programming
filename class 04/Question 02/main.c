// insert from begining and delete from last in circular linked list in  c   

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
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Delete from last
void deleteLast() {
    struct Node *temp;
    struct Node *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Display
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertBeginning(value);
    }

    printf("Circular linked list: ");
    display();

    deleteLast();

    printf("After deleting last: ");
    display();

    return 0;
}