// Find out the element which has no repetation in an array by user

#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Elements with no repetition:\n");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            printf("%d\n", arr[i]);
        }
    }
    
    return 0;
}

