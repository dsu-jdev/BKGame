#include "stack.h"

Stack *S = 0x0;

bool stackEmpty() {
	if (S == 0x0) {
		return true;
	}

	return false;
}

void pushStack(int x) {
	Stack *t = new Stack;
	t->data = x;
	t->next = S;
	S = t;
}

int popStack() {
	int x = S->data;
	S = S->next;
	return x;
}
