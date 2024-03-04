/*
 * Very simple Palindrome test
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *s) {
	int i = 0;
	int j = 0;
	
	char *buf = (char *)malloc(strlen(s)+1);

	while(i < strlen(s)) {
		if ((s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= 'A' && s[i] <= 'Z')) {
			buf[j] = tolower(s[i]);
			j++;
		}
		i++;
	}

	printf("%s => %s\n", s, buf);

	if (j == 0)
		return 1;

	for (i = 0; i < j/2; i++) {
		if (buf[i] != buf[j-i-1])
			return 0;
	}

	return 1;
}

int main(void) {
	printf("%d\n", isPalindrome(" "));
	printf("%d\n", isPalindrome("race a car"));
	printf("%d\n", isPalindrome("A man, a plan, a canal: Panama"));
	printf("%d\n", isPalindrome("0P"));

	return 0;
}
