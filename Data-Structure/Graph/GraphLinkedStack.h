#pragma once

typedef struct StackNodeType {
	int data;
	struct StackNodeType* pLink;
}StackNode;

class LinkedStack
{
public:
	LinkedStack();
	~LinkedStack();
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