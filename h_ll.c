/*
 * Generic Linked List
 * data type is unset
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum data_type {
	NONE = 0,
	INT,
	CHAR,
	STR
};

struct node {
	void *data;
	int type;
	struct node *next;
};

struct node *head = NULL;

void add(int type, void *ptr) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	int len = 0;

	switch (type) {
		case NONE:
			printf("cannot add without type\n");
			free(tmp);
			break;
		case INT:
			tmp->next = head->next;
			head->next = tmp;
			tmp->type = INT;
			tmp->data = (int *)malloc(sizeof(int));
			*((int *)tmp->data) = *(int *)ptr;
			break;
		case CHAR:
			tmp->next = head->next;
			head->next = tmp;
			tmp->type = CHAR;
			tmp->data = (char *)malloc(sizeof(char));
			*((char *)tmp->data) = *(char *)ptr;
			break;
		case STR:
			tmp->next = head->next;
			head->next = tmp;
			tmp->type = STR;
			len = strlen((char *)ptr) + 1;
			tmp->data = (char *)malloc(len);
			memset(tmp->data, 0, len);
			memcpy(tmp->data, ptr, len);
			break;
		default:
			break;
	}
}

void print(void) {
	struct node *tmp = head->next;

	while (tmp) {
		switch (tmp->type) {
			case NONE:
				break;
			case INT:
				printf("%d > ", *(int *)(tmp->data));
				break;
			case CHAR:
				printf("%c > ", *(char *)(tmp->data));
				break;
			case STR:
				printf("\"%s\" > ", (char *)tmp->data);
				break;
			default:
				break;
		}
		tmp = tmp->next;
	}
	printf(" NULL\n");
}

int main(void) {
	int a = 1;
	char b = 'c';
	char *str = "test";
	
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	head->type = NONE;
	head->data = (void *)NULL;

	add(INT, &a);
	add(CHAR, &b);
	add(STR, str);

	print();
	return 0;
}
