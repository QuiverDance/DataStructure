#pragma once

typedef struct StackNodeType {
	char data;
	struct StackNodeType* pLink;
}StackNode;

class LinkedListStack
{
public:
	LinkedListStack();
	~LinkedListStack();
	void push(StackNode element);
	StackNode* pop();
	StackNode* peek();
	void deleteStack();
	bool isEmpty();
	void displayStack();
private:
	int currentElementCount;
	StackNode* pTopElement;
};