
#ifndef SRC_LIB_QUEUE_H_
#define SRC_LIB_QUEUE_H_

struct Queue {
	int data;
	Queue *next;
};

extern Queue *Q;

bool queueEmpty();
void pushQueue(int);
int popQueue();

#endif /* SRC_LIB_QUEUE_H_ */
