/*
 * remove duplicate element in the arry
 * key is "shift" 
 * Input is always ordered
 */

#include <stdio.h>
#include <stdlib.h>

void list(int *arr, int size) {
	int i;

	for (i = 0; i < size; i++) 
		printf("%d ", arr[i]);

	printf("\n");
}

void shift(int *arr, int size) {
	int i;

	for (i = 0; i < size-1; i++) {
		arr[i] = arr[i+1];
	}
}

int removeDuplicates(int *nums, int numsSize) {
	int i, j;
	int returnSize = numsSize;

	for (i = 0; i < numsSize; i++) {
		for (j = i+1; j < numsSize; j++) {
			if (nums[i] == nums[j]) {
				shift(&nums[j], numsSize-j);
				numsSize--;
				j--;
			}
			printf("%d(%d): ", j, numsSize);
			list(nums, numsSize);
		}
	}

	printf("%d = returnSize\n", numsSize);
	return numsSize;
}

int main(void) {
	int nums[11] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int size = 0;

	size = removeDuplicates(nums, 11);
	list(nums, size);

	return 0;
}
