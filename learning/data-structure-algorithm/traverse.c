// Traverse through the elements of an array.

#include <stdio.h>
int main(void) {
	int LA[] = { 1, 3, 5, 7, 8 };
	int item = 10, k = 3, n = 5;
	int i = 0, j = n;
	printf("Array elements are :\n");

	for (i = 0; i < n; i++) {
		printf("LA[%d] = %d \n", i, LA[i]);
	}
	return 0;
}
