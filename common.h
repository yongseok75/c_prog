/* common header file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

/* linked list */
struct node {
	int val;
	struct node *next;
};

struct d_node {
	int val;
	struct d_node *next;
	struct d_node *prev;
};
