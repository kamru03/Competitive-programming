//a library storres book categories bAased on id in hierarchial order,write a program to insert category ids,and disply in assemply order

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int id) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->id = id;
        root->left = root->right = NULL;
    }
    else if (id < root->id)
        root->left = insert(root->left, id);
    else
        root->right = insert(root->right, id);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->id);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, id;

    printf("Enter number of categories: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        root = insert(root, id);
    }

    printf("Categories in ascending order: ");
    inorder(root);

    return 0;
}