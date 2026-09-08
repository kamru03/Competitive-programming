//Implement insert function in binary search tree in pre order traversal way 


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Insert function
struct Node* insert(struct Node *root, int value) {

    if (root == NULL) {
        struct Node *newNode =
            (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Preorder Traversal
void preorder(struct Node *root) {

    if (root == NULL)
        return;

    printf("%d ", root->data);       // Root
    preorder(root->left);            // Left
    preorder(root->right);           // Right
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

    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}