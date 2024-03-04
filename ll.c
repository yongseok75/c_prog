/*
 * Linked List implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct list_node {
	int val;
	struct list_node *next;
};

struct list_node *head = (struct list_node *)NULL;

void add(int val) {
	struct list_node *tmp = (struct list_node *)malloc(sizeof(struct list_node));

	tmp->next = head->next;
	tmp->val = val;
	head->next = tmp;
}

void del(int val) {
	struct list_node *tmp, *prev;

	tmp = head->next;
	prev = head;

	if (!tmp)
		return;

	while (tmp) {
		if (tmp->val == val) {
			prev->next = tmp->next;
			free(tmp);
			break;
		}
		tmp = tmp->next;
		prev = prev->next;
	}
}

void list(void) {
	struct list_node *tmp = head->next;

	while(tmp) {
		printf("%d > ", tmp->val);
		tmp = tmp->next;
	}

	printf("NULL\n");
}

struct list_node *reverse(struct list_node *node) {
	struct list_node *tmp;

	if (!node)
		return NULL;

	/* header should point a new 1st node (last) */
	if (!node->next) {
		head->next = node;
		return node;
	}

	/* tmp is a next node from the original order */
	tmp = reverse(node->next);
	tmp->next = node;
	return node;
}

void iter_reverse(void) {
	struct list_node *prev, *curr, *next;

	if (!head->next)
		return;

	/* initialization is key
	 * curr -> first node in the list (not head)
	 * next -> should be curr->next
	 * prev - it should be null since it is at the beginning
	 */
	curr = head->next;
	next = curr->next;
	prev = NULL;


	while (curr) {
		/* logic is simple.
		 * next should always moved first. and pointing curr->next
		 * curr->next is the one that has to be "reversed". reverse operation
		 * works with "curr" only.
		 * move curr to next
		 * move prev to cur
		 * Key is, prev and next is just moving and record the previous and next one
		 * curr is the one to revsere the link
		 */
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	/* head should point prev since curr is already NULL at this moment */
	head->next = prev;
}

int main(void) {
	struct list_node *tmp;

	head = (struct list_node *)malloc(sizeof(struct list_node));
	head->next = NULL;

	add (1);
	add (2);
	add (3);
	add (4);
	list();
	tmp = reverse(head->next);
	tmp->next = NULL;
	list();
	iter_reverse();
	list();
	return 0;
}
