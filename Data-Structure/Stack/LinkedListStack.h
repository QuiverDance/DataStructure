#pragma once

typedef enum PreceDenceType { lparen, rparen, times, divide, plus, minus, operand } Precedence;

typedef struct ExprTokenType {
	float value;
	Precedence type;
} ExprToken;

typedef struct StackNodeType {
	ExprToken data;
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