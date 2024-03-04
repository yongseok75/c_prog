/*
 * figuring out whether smaller string is substring of 
 * longer one. 
 * Key is, finding the value one by one in nested loop
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_sub_seq(char *s, char *t) {
	int i = 0;
	int j = 0;
	int k = 0;

	char *s1 = NULL;
	char *s2 = NULL;

	if (strlen(s) > strlen(t)) {
		s1 = s;
		s2 = t;
	} else {
		s1 = t;
		s2 = s;
	}

	char *tmp = (char *)malloc(strlen(s1) + 1);

	while (i < strlen(s2)) {
		while (j < strlen(s1)) {
			if (s1[j] == s2[i]) {
				tmp[k] = s1[j];
				j++;
				k++;
				break;
			}
			j++;
		}
		i++;
	}

	if (!strcmp(tmp, s2))
		return 1;
	else
		return 0;
}

int main(void) {
	printf("%d\n", is_sub_seq("abc", "ahbgdc"));
	printf("%d\n", is_sub_seq("axc", "ahbgdc"));

	return 0;
}
