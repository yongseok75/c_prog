/*
 * Linked list comparison
 */

#include "common.h"

struct node *head1 = NULL;
struct node *head2 = NULL;


void add(struct node *head, int val) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	tmp->val = val;
	tmp->next = head->next;
	head->next = tmp;
}

void print(struct node *head) {
	struct node *tmp = head->next;

	while (tmp) {
		printf("%d > ", tmp->val);
		tmp = tmp->next;
	}

	printf(" NULL\n");
}

int compare(void) {
	struct node *tmp1 = head1->next;
	struct node *tmp2 = head2->next;


	while (tmp1 && tmp2) {
		if (tmp1->val != tmp2->val)
			return FALSE;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	if (!tmp1 && !tmp2)
		return TRUE;
	else
		return FALSE;
}

int main(void) {
	head1 = (struct node *)malloc(sizeof(struct node));
	head2 = (struct node *)malloc(sizeof(struct node));
	head1->next = NULL;
	head2->next = NULL;

	add(head1, 1);
	add(head2, 1);
	add(head1, 2);
	add(head2, 2);
	add(head1, 3);
	add(head2, 3);
	add(head1, 4);
	add(head2, 4);

	print(head1);
	print(head2);

	printf("compare = %d\n", compare());

	add(head1, 5);
	add(head2, 6);

	printf("compare = %d\n", compare());

	add(head1, 7);

	printf("compare = %d\n", compare());

	add(head2, 8);
	add(head2, 9);

	printf("compare = %d\n", compare());

	print(head1);
	print(head2);

	return 0;
}
