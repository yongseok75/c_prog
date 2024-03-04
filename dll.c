/*
 * Doubly Linked List Implementation
 */

#include "common.h"

struct d_node *head = NULL;
struct d_node *last = NULL;

/* add a node from the 1st pos */
void add(int val) {
	struct d_node *tmp = (struct d_node *)malloc(sizeof(struct d_node));

	tmp->val = val;

	if (head->next) {
		head->next->prev = tmp;
		if (head->next->next == NULL)
			last = head->next;
	}


	tmp->next = head->next;
	head->next = tmp;
	tmp->prev = NULL;
}

/* check whether head has next node or not by proving "last" */
void add_last(int val) {
	struct d_node *tmp = (struct d_node *)malloc(sizeof(struct d_node));

	if (!last) {
		head->next = tmp;
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->val = val;
	} else {
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		tmp->val = val;
	}

	last = tmp;
}

/* delete a node from the 1st pos */
void delete(void) {
	struct d_node *tmp = head->next;
	head->next = tmp->next;
	tmp->next->prev = NULL;
	free(tmp);
}

void delete_last() {
	struct d_node *tmp = last;

	if (last) {
		last->prev->next = NULL;
		last = tmp->prev;
		free(tmp);
	}
}

/* print all nodes except head */
void print(void) {
	struct d_node *tmp = head->next;

	while (tmp) {
		printf("%d > ", tmp->val);
		tmp = tmp->next;
	}

	printf("NULL\n");
}

void print_last(void) {
	printf("%d = last value\n", last->val);
}

void print_reverse(void) {
	struct d_node *tmp = last;
	while(tmp) {
		printf("%d < ", tmp->val);
		tmp = tmp->prev;
	}

	printf("NULL\n");
}

int main(void) {
	head = (struct d_node *)malloc(sizeof(struct d_node));
	head->next = NULL;
	head->prev = NULL; // no need to set

	add(1);
	add(2);
	add(3);
	add(4);

	print();
	print_last();
	print_reverse();

	delete();
	delete();
	add_last(3);
	add_last(4);

	print();
	print_last();
	print_reverse();

	delete_last();
	delete_last();

	print();
	print_last();
	print_reverse();

	return 0;
}
