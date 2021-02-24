#pragma once
#include "BTreeLinkedStack.h"

class BTree
{
public:
	BTree();
	~BTree();
	BTreeNode* createBTreeNode(BTreeNodeData element);
	void deleteBTree();
	void deleteBTreeNode(BTreeNode* pDelNode);
	BTreeNodeData* search(int key);
	void insertNode(BTreeNodeData element);
	void insertNodeElement(BTreeNode* pCurrentNode, BTreeNodeData element, BTreeNode* pChildNode);
	void deleteNode(int key);
	void splitNode(BTreeLinkedStack* pStack);
	bool isLeafNode(BTreeNode* pParentNode);
	int getIndexInfo(BTreeNode* pParentNode, BTreeNode* pCurrentNode);
	BTreeNode* replaceLeafNode(BTreeNode* pDelNode, int index, BTreeLinkedStack* pStack);
	void balanceBTree(BTreeLinkedStack* pStack);
	void deleteKey(BTreeNode* pNode, int index);
	void borrowRightNode(BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index, BTreeNode* pRightNode);
	void borrowLeftNode(BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index, BTreeNode* pLeftNode);
	void mergeNode(BTreeLinkedStack* pStack, BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index);
	void pushBTreeNode(BTreeLinkedStack* pStack, BTreeNode* pData);
	void displayTree();
	void displayTreeNode(BTreeNode* pNode);
private:
	BTreeNode* pRootNode;
};