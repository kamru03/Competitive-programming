// Matrix subtraction user input

#include <stdio.h>

int main(void)
{
	int r, c, i, j;
	int a[100][100], b[100][100], result[100][100];

	printf("Enter number of rows and columns: ");
	if (scanf("%d %d", &r, &c) != 2) {
		return 1;
	}

	printf("Enter elements of first matrix:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter elements of second matrix:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	printf("Resultant matrix after subtraction:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			result[i][j] = a[i][j] - b[i][j];
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}