// Removing an existing element from the array and re-organizing all elements of an array.

#include <stdio.h>

int main(void) {
	int LA[] = { 1, 3, 5, 7, 8 };
	int k = 3, n = 5;
	int i, j;

	printf("Array elements are : \n");

	for (i = 0; i < n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}

	j = k;

	while (j < n) {
		LA[j - 1] = LA[j];
		j = j + 1;
	}

	n = n - 1;

	printf("Array elements after deletion :\n");

	for (i = 0; i < n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}
}
