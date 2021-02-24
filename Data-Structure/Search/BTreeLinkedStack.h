#pragma once

#define BTREE_ORDER 5

typedef struct BTreeNodeDataType
{
	int key;
	char value;
}BTreeNodeData;

typedef struct BTreeNodeType
{
	int elementCount;
	BTreeNodeData element[BTREE_ORDER];
	struct BTreeNodeType* pChildren[BTREE_ORDER + 1];
}BTreeNode;

typedef struct StackNodeType {
	BTreeNode* data;
	struct StackNodeType* pLink;
}StackNode;

class BTreeLinkedStack
{
public:
	BTreeLinkedStack();
	~BTreeLinkedStack();
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
