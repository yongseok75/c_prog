/*
 * Very simple recursion test
 */

#include <stdio.h>
#include <stdlib.h>

int recur(int num) {
	int tmp = 0;
	printf("start %d ", num);

	if (num == 0)
		return 0;

	num--;
	tmp = recur(num);
	printf("end %d  tmp %d /", num, tmp);
	return num;
}

int main(void) {
	int tmp = 0;
	tmp = recur(10);
	printf("\n");
	return 0;
}
