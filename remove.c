/*
 * removing all '2' in the array
 * shifting the value to front is the key
 */

#include <stdio.h>
#include <stdlib.h>

int arr[] = { 0, 1, 2, 2, 3, 0, 4, 2 };

void arr_move(int *nums, int size) {
	int i;

	for (i = 0; i < size; i++)
		nums[i] = nums[i+1];
}

int main(void) {
	int i,j;
	int hit = 0;
	int size = 8;

	for (i = 0; i < size; i++) {
		if (arr[i] == 2) {
			arr_move(&arr[i], size-i-1);
			hit++;
			i--;
			size--;
		}
	}

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nhit = %d\n", hit);

	return 0;
}
