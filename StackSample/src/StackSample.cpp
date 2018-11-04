//============================================================================
// Name        : StackSample.cpp
// Author      : Harrison
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef int ElementData;
typedef struct StackNode* Pos;
typedef struct StackNode* Stack;

struct StackNode {
	ElementData element;
	Pos next;
};

Stack init_stack(void);
void delete_stack(Stack);
ElementData top(Stack);
void push(Stack, ElementData);
ElementData pop(Stack);
int is_null(Stack);

int main() {
	cout << "!!! Start Stack Test !!!" << endl;

	Stack st = init_stack();

	push(st, 1);
	push(st, 2);
	push(st, 3);

	cout << "Stack is null? " << is_null(st) << endl;

	for (int i = 0; i < 3; i++) {
		ElementData data = pop(st);
		cout << "pop: " << data << endl;
	}

	cout << "Stack is null? " << is_null(st) << endl;
	delete_stack(st);
	return 0;
}

Stack init_stack(void) {
	Stack st;

	st = new StackNode();
	st->next = NULL;

	return st;
}

void delete_stack(Stack st) {
	while (!is_null(st)) {
		pop(st);
	}

	delete st;
}

ElementData top(Stack st) {
	return st->next->element;
}

void push(Stack st, ElementData data) {
	Pos np = NULL;

	np = new StackNode();

	np->element = data;
	np->next = st->next;

	st->next = np;
}

ElementData pop(Stack st) {
	Pos top = NULL, newTop = NULL;
	ElementData element = 0;

	if (is_null(st)) {
		cout << "pop() on an empty stack, no data" << endl;
		exit(1);
	}
	else {
		top = st->next;
		element = top->element;
		newTop = top->next;
		st->next = newTop;
		delete top;
	}

	return element;
}

int is_null(Stack st) {
	return st->next == NULL;
}
