
#ifndef SRC_LIB_STACK_H_
#define SRC_LIB_STACK_H_

struct Stack {
	int data;
	Stack *next;
};

extern Stack *S;

bool stackEmpty();
void pushStack(int);
int popStack();

#endif /* SRC_LIB_STACK_H_ */
