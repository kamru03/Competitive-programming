// Find the longest element of 2D array each display the position of the element

#include <stdio.h>

int main() {
    int rows, cols, i, j;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("Enter the matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int max = arr[0][0];
    int row = 0, col = 0;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
                row = i;
                col = j;
            }
        }
    }

    printf("\nLargest element = %d\n", max);
    printf("Position = Row %d, Column %d\n", row + 1, col + 1);

    return 0;
}