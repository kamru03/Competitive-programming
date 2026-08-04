// Print sum of each row separately from user input

#include <stdio.h>

int main() {
    int rows, cols, i, j, sum;

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

    printf("\nSum of each row:\n");
    for(i = 0; i < rows; i++) {
        sum = 0;
        for(j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        printf("Row %d = %d\n", i + 1, sum);
    }

    return 0;
}