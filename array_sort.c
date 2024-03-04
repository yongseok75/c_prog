/*
 * sorting array with bubble sort
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int arr[6][2] = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};

int main(void) {
	int i, j;
	int tmp_ptr[2];

	for (i = 0; i < SIZE; i++){
		for (j = i+1; j < SIZE; j++) {
			if (arr[i][0] > arr[j][0]) {
				tmp_ptr[0] = arr[j][0];
				tmp_ptr[1] = arr[j][1];
				arr[j][0] = arr[i][0];
				arr[j][1] = arr[i][1];
				arr[i][0] = tmp_ptr[0];
				arr[i][1] = tmp_ptr[1];
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("(%d, %d) ", arr[i][0], arr[i][1]);
	}
	printf("\n");

	return 0;
}
