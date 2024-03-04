/*
 * regular bubble sort
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int arr[] = { 4, 1, 2, 5, 8, 3, 2 };

int main(void) {
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;

	printf("orginal ");
	for (k = 0; k < SIZE; k++) {
		printf("%d ", arr[k]);
	}
	printf("\n");

	for (i = 0; i < SIZE; i++) {
		for (j = i+1; j < SIZE; j++){
			if (arr[i] > arr[j]) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp; 
			}
		}
		for (k = 0; k < SIZE; k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	printf("final ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}
