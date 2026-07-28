// Second max in an array of 5 elements

#include <stdio.h>
int main() {
    int arr[5];
    int i, max, second_max;

    printf("Enter 5 elements:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    max = second_max = arr[0]; 
    for (i = 1; i < 5; i++) {
        if (arr[i] > max) {
            second_max = max; 
            max = arr[i]; 
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i]; 
        }
    }

    printf("The second maximum element is: %d\n", second_max);

    return 0;
}