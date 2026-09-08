//Implement insert function in binary search tree in iterative way 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Iterative insertion
struct Node* insert(struct Node *root, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // If tree is empty
    if (root == NULL) {
        return newNode;
    }

    struct Node *current = root;
    struct Node *parent = NULL;

    // Find the correct position
    while (current != NULL) {
        parent = current;

        if (value < current->data) {
            current = current->left;
        }
        else if (value > current->data) {
            current = current->right;
        }
        else {
            // Duplicate value
            free(newNode);
            return root;
        }
    }

    // Attach new node
    if (value < parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return root;
}

// Inorder traversal
void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal of BST: ");
    inorder(root);

    return 0;
}