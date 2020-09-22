// Updating an existing element from the array at a given index.
#include <stdio.h>

int main(void) {
	int LA[] = { 1, 3, 5, 7, 9 };
	int k = 3, n = 5, item = 10;
	int i, j;

	printf("Array elements are :\n");

	for (i = 0; i < n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}

	LA[k - 1] = item;

	printf("Elements after updateion :\n");

	for (i = 0; i < n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}
}
