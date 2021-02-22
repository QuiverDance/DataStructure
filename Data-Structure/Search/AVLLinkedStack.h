#pragma once

#define VALUE_SIZE 100

typedef struct AVLTreeNodeDataType
{
	int key;
	char value[VALUE_SIZE + 1];
}AVLTreeNodeData;

typedef struct AVLTreeNodeType
{
	AVLTreeNodeData data;

	int balance;
	int height;
	struct AVLTreeNodeType* pLeftChild;
	struct AVLTreeNodeType* pRightChild;
}AVLTreeNode;

typedef struct StackNodeType {
	AVLTreeNode* data;
	struct StackNodeType* pLink;
}StackNode;

class AVLLinkedListStack
{
public:
	AVLLinkedListStack();
	~AVLLinkedListStack();
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
