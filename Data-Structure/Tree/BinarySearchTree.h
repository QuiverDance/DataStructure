#pragma once

typedef struct BinSearchTreeNodeType 
{
	int key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

class BinSearchTree
{
public:
	BinSearchTree();
	~BinSearchTree();
	void insertElement(BinSearchTreeNode element);
	void deleteElement(int key);
	BinSearchTreeNode* search(int key);
	BinSearchTreeNode* getRootNode();
	void deleteTree(BinSearchTreeNode* pParentNode);
	void displayTree(BinSearchTreeNode* pParentNode, int level, char type);
private:
	BinSearchTreeNode* pRootNode;
};