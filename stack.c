/*
 * An implementation of stack with array
 * @top  : stack's top
 * @data : stack 
 */
#include "common.h"

#define MAX_STACK_SIZE 10

struct stack {
	int top;
	int *data;
};

int is_empty(struct stack *stack) {
	return (stack->top == -1) ? TRUE : FALSE;
}

int is_full(struct stack *stack) {
	return (stack->top == MAX_STACK_SIZE - 1) ? TRUE : FALSE;
}

int pop(struct stack *stack) {
	if (is_empty(stack)) {
		printf("stack is empty!\n");
		return stack->top;
	}

	return stack->data[stack->top--];
}

void push(struct stack *stack, int val) {
	if (is_full(stack)) {
		printf("stack is full!\n");
		return;
	}

	stack->data[++stack->top] = val;
}

struct stack *init() {
	struct stack *tmp = NULL;

	tmp = (struct stack *)malloc(sizeof(struct stack));
	tmp->data = (int *)malloc(sizeof(int) * MAX_STACK_SIZE);
	tmp->top = -1;

	return tmp;
}

int top(struct stack *stack) {
	return stack->top;
}

int main(void) {
	int i;
	struct stack *stack = init();

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);

	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));
	printf("%d\n", pop(stack));

	printf("%s, top=%d\n", is_empty(stack) ? "TRUE" : "FALSE", stack->top);

	push(stack, 10);
	push(stack, 9);
	push(stack, 8);
	push(stack, 7);
	push(stack, 6);
	push(stack, 5);
	push(stack, 4);
	push(stack, 3);
	push(stack, 2);
	push(stack, 1);
	push(stack, 0);

	for (i = 0; i < MAX_STACK_SIZE; i++) {
		printf("%d\n", pop(stack));
	}

	pop(stack);

	printf("top = %d\n", stack->top);
	return 0;
}
