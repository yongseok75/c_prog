/*
 * coverting ascii number to integer
 * MAX_DISIGS 10
 * Currently, it cannot cover INT_MAX value overflow
 */

#include "common.h"
#include <limits.h>

#define MAX_DIGITS 10

int is_valid_num(char *num) {
	int i;
	int len = strlen(num);

	if (len > MAX_DIGITS) {
		printf("too big number\n");
		return FALSE;
	}

	for (i = 0; i < len; i++) {
		if (num[i] < '0' && num[i] > '9') {
			printf("invalid charater. only numbers allowed\n");
			return FALSE;
		}
	}

	return TRUE;
}

int main(void) {
	int i;
	int number = 0;
	char num_str[MAX_DIGITS+1];
	int len = 0;

	memset(num_str, 0, sizeof(num_str));
	printf("Input a number: ");
	scanf("%s", num_str);
	getchar();

	if (!is_valid_num(num_str))
		return 1;

	printf("%s\n", num_str);
	len = strlen(num_str);

	for (i = 0; i < len; i++)
		number += (num_str[i] - '0') * pow(10, len-i-1);
	
	printf("%d\n", number);
	
	return 0;
}
