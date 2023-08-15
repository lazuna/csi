// Search for an array element based on its value or its index.
#include <stdio.h>

int main(void) {
	int LA[] = { 1, 3, 5, 7, 8 };
	int item = 5, n = 5;
	int i = 0, j = 0;

	printf("Array elements are :\n");

	for (i = 0; i < n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}

	while (j < n) {
		if (LA[j] == item) {
			break;
		}
		j = j + 1;
	}

	printf("Found element %d at index %d and position %d\n", item, j, j + 1);
}
