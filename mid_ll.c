/*
 * Find a middle node in a linked list
 */

#include "common.h"

struct node *head = NULL;

void add(int val) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	tmp->next = head->next;
	head->next = tmp;
	tmp->val = val;
}

void print(void) {
	struct node *tmp = head->next;

	while (tmp) {
		printf("%d > ", tmp->val);
		tmp = tmp->next;
	}
	printf(" NULL\n");
}

struct node *find_middle(void) {
	struct node *tmp1 = head->next;
	struct node *tmp2 = head->next;

	while (tmp2 && tmp2->next) {
		tmp1 = tmp1->next;
		tmp2 = tmp2->next->next;
	}

	return tmp1;
}

int main(void) {
	struct node *tmp;
	
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;

	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	add(6);
	print();

	tmp = find_middle();
	printf("val=%d\n", tmp->val);

	return 0;
}
