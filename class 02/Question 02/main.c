// Summation of lower digonal elements

#include <stdio.h>

#define MAX 100

int main(void) {
    int n, i, j;
    long long sum = 0;
    int a[MAX][MAX];

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j) {
                sum += a[i][j];
            }
        }
    }

    printf("Sum of lower diagonal elements: %lld\n", sum);
    return 0;
}

