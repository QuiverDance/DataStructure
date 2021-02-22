#pragma once
#include "AVLLinkedStack.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void deleteTree();
	void deleteTreeNode(AVLTreeNode* pAVLTreeNode);
	void insertNodeAVL(AVLTreeNodeData element);
	void deleteNode(int key);
	void balanceAVLTree(AVLLinkedListStack* pStack);
	void pushAVLTreeNode(AVLLinkedListStack* pStack, AVLTreeNode* data);
	AVLTreeNode* popAVLTreeNode(AVLLinkedListStack* pStack);
	AVLTreeNode* peekAVLTreeNode(AVLLinkedListStack* pStack);
	AVLTreeNode* rotateLL(AVLTreeNode* pParentNode);
	AVLTreeNode* rotateLR(AVLTreeNode* pParentNode);
	AVLTreeNode* rotateRR(AVLTreeNode* pParentNode);
	AVLTreeNode* rotateRL(AVLTreeNode* pParentNode);
	void updateHeightAndBalanceAVL(AVLTreeNode* pNode);
	AVLTreeNode* search(int key);
	void displayAVLTree();
	void displayAVLTreeInternal(AVLTreeNode* pTreeNode, int level, char type);
private:
	AVLTreeNode* pRootNode;
};