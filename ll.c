/*
 * Linked List implementation
 */
#include "common.h"

void insert(struct node **head, int val) {
	struct node *tmp = NULL;

	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->val = val;
	tmp->next = NULL;

	tmp->next = (*head);
	*head = tmp;
}

void append(struct node **head, int val) {
	struct node *ptr = *head;
	struct node *tmp = NULL;

	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->val = val;
	tmp->next = NULL;

	if (!ptr) {
		*head = tmp;
	} else {
		while (ptr->next)
			ptr = ptr->next;

		ptr->next = tmp;
	}
}

int search(struct node **head, int val) {
	struct node *ptr = *head;

	while (ptr) {
		if (ptr->val == val)
			return TRUE;
		ptr = ptr->next;
	}

	return FALSE;
}

void print(struct node **head) {
	struct node *tmp = *head;

	while (tmp) {
		printf("%d > ", tmp->val);
		tmp = tmp->next;
	}

	printf("NULL\n");
}

int length_iter(struct node **head) {
	int len = 0;
	struct node *ptr = *head;

	while (ptr) {
		ptr = ptr->next;
		len++;
	}

	return len;
}

int length_recur(struct node **head) {
	struct node *ptr = *head;
	int len = 0;

	if (!ptr)
		return 0;

	len = 1 + length_recur(&ptr->next);
	return len;
}

/* 
 * reverse a linked list in recursive way
 * 1. check wether the ptr is null or not. if null, return!
 * 2. if ptr->next is null, head should set to ptr and return ptr
 * 3. call the API in recursive way. pass "ptr->next" to make it traverse all the way down to last node
 * 4. return of the API should be previous "node" ptr.
 * 5. after return, prev node's next should set to "curr" node
 */
struct node* reverse_recur(struct node **head, struct node *ptr) {
	struct node *tmp = NULL;

	if (!ptr)
		return NULL;

	if (!ptr->next) {
		*head = ptr;
		return ptr;
	}

	tmp = reverse_recur(head, ptr->next);
	tmp->next = ptr;

	return ptr;
}

/*
 * reverse the linked list in iterative way
 * 1. set next to curr->next (which is next)
 * 2. set curr->next to prev (set the next ptr in reverse way)
 * 3. since curr is now previous, set prev to curr
 * 4. move on curr to next. set curr to next
 * 5. at the end of the loop, set head to prev
 */
void reverse_iter(struct node **head) {
	struct node *prev, *curr, *next;

	if (*head == NULL)
		return;

	prev = next = NULL;
	curr = *head;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

int main(void) {
	struct node *head = NULL;
	struct node *tmp = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	print(&head);

	append(&head, 5);
	append(&head, 6);

	print(&head);

	insert(&head, 7);

	print(&head);

	printf("2? = %s\n", search(&head, 2) ? "TRUE" : "FALSE");
	printf("9? = %s\n", search(&head, 9) ? "TRUE" : "FALSE");

	printf("list len(iter)  = %d\n", length_iter(&head));
	printf("list len(recur) = %d\n", length_recur(&head));

	tmp = reverse_recur(&head, head);
	tmp->next = NULL;

	print(&head);

	reverse_iter(&head);
	print(&head);

	return 0;
}
