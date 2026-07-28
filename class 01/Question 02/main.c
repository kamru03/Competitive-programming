// Calculate sum of  elements in an array

#include <stdio.h>
int main() {    
    
    int arr[5];
    int i, sum = 0;

    printf("Enter 5 elements:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }

    printf("The sum of the elements is: %d\n", sum);

    return 0;
}