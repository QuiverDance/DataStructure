#pragma once

typedef struct ArrayStackNodeType {
	char data;
} ArrayStackNode;

class ArrayStack {
public:
	ArrayStack(int maxElementCount);
	void push(ArrayStackNode element);
	ArrayStackNode* pop();
	ArrayStackNode* peek();
	void deleteStack();
	bool isFull();
	bool isEmpty();

	void displayStack();

	~ArrayStack();
private:
	int maxElementCount;
	int currentElementCount;
	ArrayStackNode* pElement;
};