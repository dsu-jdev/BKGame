#include "queue.h"

Queue *Q = 0x0;

bool queueEmpty() {
	if (Q == 0x0) {
		return true;
	}

	return false;
}

void pushQueue(int x) {
	Queue *t = new Queue;
	t->data = x;
	t->next = 0x0;
	Queue *q = Q;
	if (queueEmpty()) {
		Q = t;
	} else {
		while (q->next != 0x0) {
			q = q->next;
		}
		q->next = t;
	}
}

int popQueue() {
	int x = Q->data;
	Q = Q->next;
	return x;
}
