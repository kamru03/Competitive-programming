//Implement insert function in binary search tree in recurcive way 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Recursive insertion function
struct Node* insert(struct Node *root, int value) {

    // If tree is empty, create a new node
    if (root == NULL) {
        struct Node *newNode =
            (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    // If value is smaller, insert in left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }

    // If value is greater, insert in right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // If duplicate, do nothing
    else {
        printf("Duplicate value %d not inserted.\n", value);
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

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}