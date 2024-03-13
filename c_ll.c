/*
 * Circular Linked List
 */

#include "common.h"

struct node *head = NULL;
struct node *current = NULL;

int is_empty(void) {
	return (head) ? FALSE : TRUE;
}

void insert(int val) {
	struct node *tmp = NULL;

	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->val = val;
	tmp->next = NULL;

	if (is_empty()) {
		head = tmp;
		head->next = tmp;
	} else {
		tmp->next = head;
		head = tmp;
	}
}

void delete(void) {
	// not yet
}

void print(void) {
	struct node *tmp = head;

	while (tmp && tmp->next != tmp) {
		printf("%d > ", tmp->val);
		tmp = tmp->next;
	}

	printf("> end\n");
}


int main(void) {
	insert(1);
	insert(2);
	insert(3);
	insert(4);

	print();
	return 0;
}
