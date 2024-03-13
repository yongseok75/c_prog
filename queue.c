/*
 * An implementation of queue
 *
 * F ----------------- R
 * N1 > N2 > N3 > N4 > N5 > NULL
 *
 * @rear - end of queue
 * @front - beginning of queue
 * @size - capacity
 */
#include "common.h"

#define MAX_QUEUE_SIZE 10

// no extra data linked list buffer required
struct queue {
	int size;
	struct node *rear, *front;
};

// init the q sructure
struct queue *init(void) {
	struct queue *tmp = (struct queue *)malloc(sizeof(struct queue));
	tmp->size = 0;
	tmp->rear = tmp->front = NULL;

	return tmp;
}

int is_full(struct queue *q) {
	return ((q->size == MAX_QUEUE_SIZE) ? TRUE : FALSE);
}

int is_empty(struct queue *q) {
	// we can check rear or front is null, too
	return (q->size == 0 ? TRUE : FALSE);
}

// adding a new node after rear
void enqueue(struct queue *q, int val) {
	struct node *tmp = NULL;

	if (is_full(q)) {
		printf("queue is full(%d)!!\n", q->size);
		return;
	}

	// initialization
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->val = val;
	tmp->next = NULL;
	
	// insert data to the queue
	if (!q->rear) {
		q->front = q->rear = tmp;
	} else {
		q->rear->next = tmp;
		q->rear = tmp;
	}

	q->size++;
}

// removing a node from front
int dequeue(struct queue *q) {
	struct node *tmp = NULL;
	int val;

	if (is_empty(q)) {
		printf("queue is empty(%d)!!\n", q->size);
		return -1;
	}

	val = q->front->val;
	tmp = q->front;
	q->front = q->front->next;
	q->size--;

	free(tmp);

	if (!q->front)
		q->rear = q->front;

	return val;
}

int rear(struct queue *q) {
	if (is_empty(q)) {
		printf("queue is empty(%d)!!\n", q->size);
		return -1;
	}

	return q->rear->val;
}

int front(struct queue *q) {
	if (is_empty(q)) {
		printf("queue is empty(%d)!!\n", q->size);
		return -1;
	}

	return q->front->val;
}

int main(void) {
	struct queue *q = init();

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);

	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	enqueue(q, 6);
	enqueue(q, 7);
	enqueue(q, 8);
	enqueue(q, 9);
	enqueue(q, 10);
	enqueue(q, 11);

	printf("front: %d\n", front(q));
	printf("rear : %d\n", rear(q));

	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));
	printf("deq : %d\n", dequeue(q));

	return 0;
}
