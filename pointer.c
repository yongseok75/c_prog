#include <stdio.h>
#include <stdlib.h>

void ptr_test(char *tmp) {
	printf("%p=tmp's addr, %p=tmp's value, %c=tmp's deref\n", &tmp, tmp, *tmp);
}

int main(void) {
	char *ptr = NULL;
	char **dptr = NULL;
	char val = 'c';

	/* pointer's address and value - value is address */
	printf("%p=ptr's addr, %p=ptr's value\n", &ptr, ptr);
	/* value's address and value - we cannot change value's address */
	printf("%p=val's addr, %c=val's value\n", &val, val);

	ptr = &val;

	printf("%p=ptr's addr, %p=ptr's value, %c=ptr's deref\n", &ptr, ptr, *ptr);

	dptr = &ptr;
	printf("%p=dptr's addr, %p=dptr's value %p=dptr's deref %c=dptr's de-deref\n", &dptr, dptr, *dptr, **dptr);

	ptr_test(ptr);

	return 0;
}
