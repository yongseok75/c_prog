/*
 * coverting ascii number to integer
 * MAX_DISIGS 10
 * Currently, it cannot cover INT_MAX value overflow
 */

#include "common.h"
#include <limits.h>

#define MAX_DIGITS 10

int simple_atoi(char *num) {
	int i = 0;

	while (*num) {
		i = (i<<3) + (i<<1) + (*num - '0');
		num++;
	}

	return i;
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

	len = strlen(num_str);

	number = simple_atoi(num_str);

	printf("%d\n", number);
	
	return 0;
}
