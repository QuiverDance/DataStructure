#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree()
{
	pRootNode = new AVLTreeNode;
	pRootNode = { 0, };
}

AVLTree::~AVLTree()
{
	deleteTree();
}

void AVLTree::deleteTree()
{
	deleteTreeNode(pRootNode);
}

void AVLTree::deleteTreeNode(AVLTreeNode* pAVLTreeNode)
{
	if (pAVLTreeNode == nullptr)
		return;
	deleteTreeNode(pAVLTreeNode->pLeftChild);
	deleteTreeNode(pAVLTreeNode->pRightChild);
	delete pAVLTreeNode;
}

void AVLTree::insertNodeAVL(AVLTreeNodeData element)
{
	AVLTreeNode* pParentNode = nullptr;
	AVLTreeNode* pNewNode = nullptr;
	AVLLinkedListStack* pStack = nullptr;

	pStack = new AVLLinkedListStack();
	if (!pStack)
		return;

	pParentNode = pRootNode;
	while (pParentNode != nullptr)
	{
		pushAVLTreeNode(pStack, pParentNode);
		if (pParentNode->data.key == element.key)
		{
			pStack->deleteStack();
			delete pStack;
			return;
		}
		else if (element.key < pParentNode->data.key)
		{
			if (pParentNode->pLeftChild == nullptr)
				break;
			else
				pParentNode = pParentNode->pLeftChild;
		}
		else
		{
			if (pParentNode->pRightChild == nullptr)
				break;
			else
				pParentNode = pParentNode->pRightChild;
		}
	}
	pNewNode = new AVLTreeNode;
	if (!pNewNode)
	{
		pStack->deleteStack();
		delete pStack;
		return;
	}
	pNewNode->data = element;
	pNewNode->height = 1;
	if (pParentNode == nullptr)
		pRootNode = pNewNode;
	else
	{
		if (pNewNode->data.key < pParentNode->data.key)
			pParentNode->pLeftChild = pNewNode;
		else
			pParentNode->pRightChild = pNewNode;
	}
	balanceAVLTree(pStack);
	pStack->deleteStack();
	delete pStack;
}

void AVLTree::deleteNode(int key)
{
	AVLTreeNode* pDelNode = nullptr, * pParentNode = nullptr, * pPredecessor = nullptr, * pSuccessor = nullptr, * pChild = nullptr;
	AVLLinkedListStack* pStackMain = nullptr, * pStackSub = nullptr;
	
	pStackMain = new AVLLinkedListStack();
	pStackSub = new AVLLinkedListStack();
	if (pStackMain == nullptr || pStackSub == nullptr)
		return;

	pDelNode = pRootNode;
	while (pDelNode)
	{
		if (key == pDelNode->data.key) {
			break;
		}
		pParentNode = pDelNode;
		pushAVLTreeNode(pStackMain, pParentNode);
		if (key < pDelNode->data.key) {
			pDelNode = pDelNode->pLeftChild;
		}
		else {
			pDelNode = pDelNode->pRightChild;
		}
	}
	if (pDelNode == nullptr)
	{
		pStackMain->deleteStack();
		pStackSub->deleteStack();
		return;
	}
	if (pDelNode->pLeftChild == nullptr && pDelNode->pRightChild == nullptr)
	{
		if (pParentNode)
		{
			if (pParentNode->pLeftChild == pDelNode)
				pParentNode->pLeftChild = nullptr;
			else
				pParentNode->pRightChild = nullptr;
		}
		else
			pRootNode = nullptr;
	}
	else if (pDelNode->pLeftChild != nullptr && pDelNode->pRightChild != nullptr)
	{
		pPredecessor = nullptr;
		pSuccessor = pDelNode->pLeftChild;
		pushAVLTreeNode(pStackSub, pSuccessor);

		while (pSuccessor->pRightChild) 
		{
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRightChild;
			pushAVLTreeNode(pStackSub, pSuccessor);
		}
		pushAVLTreeNode(pStackMain, popAVLTreeNode(pStackSub));
		if (pPredecessor)
		{
			pPredecessor->pRightChild = pSuccessor->pLeftChild;
			pSuccessor->pLeftChild = pDelNode->pLeftChild;
			pushAVLTreeNode(pStackSub, pPredecessor->pRightChild);
		}
		pSuccessor->pRightChild = pDelNode->pRightChild;
		if (pParentNode)
		{
			if (pParentNode->pLeftChild == pDelNode)
				pParentNode->pLeftChild = pSuccessor;
			else
				pParentNode->pRightChild = pSuccessor;
		}
		else
			pRootNode = pSuccessor;
	}
	else
	{
		if (pDelNode->pLeftChild)
			pChild = pDelNode->pLeftChild;
		else
			pChild = pDelNode->pRightChild;
		if (pParentNode)
		{
			if (pParentNode->pLeftChild == pDelNode)
				pParentNode->pLeftChild = pChild;
			else
				pParentNode->pRightChild = pChild;
		}
		else
			pRootNode = pChild;
	}
	delete pDelNode;

	balanceAVLTree(pStackSub);
	balanceAVLTree(pStackMain);
	pStackMain->deleteStack();
	pStackSub->deleteStack();
}

void AVLTree::balanceAVLTree(AVLLinkedListStack* pStack)
{
	AVLTreeNode* pParentNode = nullptr;
	AVLTreeNode* pChildNode = nullptr;
	AVLTreeNode* pNode = nullptr;
	AVLTreeNode* pNewNode = nullptr;
	if (!pStack)
		return;
	while (pStack->isEmpty() == false)
	{
		pNode = popAVLTreeNode(pStack);
		if (pNode)
		{
			updateHeightAndBalanceAVL(pNode);
			if (pNode->balance >= -1 && pNode->balance <= 1)
				continue;
			if (pNode->balance > 1)
			{
				pChildNode = pNode->pLeftChild;
				if (pChildNode->balance > 0)
					pNewNode = rotateLL(pNode);
				else
					pNewNode = rotateLR(pNode);
			}
			else if (pNode->balance < -1)
			{
				pChildNode = pNode->pRightChild;
				if (pChildNode->balance < 0)
					pNewNode = rotateRR(pNode);
				else
					pNewNode = rotateRL(pNode);
			}
			pParentNode = peekAVLTreeNode(pStack);
			if (pParentNode)
			{
				if (pParentNode->pLeftChild == pNode)
					pParentNode->pLeftChild = pNewNode;
				else
					pParentNode->pRightChild = pNewNode;
			}
			else
				pRootNode = pNewNode;
		}
	}
}

void AVLTree::pushAVLTreeNode(AVLLinkedListStack* pStack, AVLTreeNode* data)
{
	StackNode node = { 0, };
	node.data = data;
	pStack->push(node);
}

AVLTreeNode* AVLTree::popAVLTreeNode(AVLLinkedListStack* pStack)
{
	AVLTreeNode* popNode = nullptr;
	if (pStack->isEmpty() == false)
	{
		StackNode* pNode = pStack->pop();
		if (pNode)
		{
			popNode = pNode->data;
			delete pNode;
		}
	}
	return popNode;
}

AVLTreeNode* AVLTree::peekAVLTreeNode(AVLLinkedListStack* pStack)
{
	AVLTreeNode* peekNode = nullptr;
	if (pStack->isEmpty() == false)
	{
		StackNode* pNode = pStack->peek();
		if (pNode)
		{
			peekNode = pNode->data;
		}
	}
	return peekNode;
}

AVLTreeNode* AVLTree::rotateLL(AVLTreeNode* pParentNode)
{
	AVLTreeNode* pLeftNode = nullptr;
	if (pParentNode)
	{
		pLeftNode = pParentNode->pLeftChild;
		pParentNode->pLeftChild = pLeftNode->pRightChild;
		pLeftNode->pRightChild = pParentNode;

		updateHeightAndBalanceAVL(pParentNode);
		updateHeightAndBalanceAVL(pLeftNode);
	}
	return pLeftNode;
}

AVLTreeNode* AVLTree::rotateLR(AVLTreeNode* pParentNode)
{
	AVLTreeNode* pReturn = nullptr;
	AVLTreeNode* pLeftNode = nullptr;
	if (pParentNode)
	{
		pLeftNode - pParentNode->pLeftChild;
		pParentNode->pLeftChild = rotateRR(pLeftNode);
		pReturn = rotateLL(pParentNode);
	}
	return pReturn;
}

AVLTreeNode* AVLTree::rotateRR(AVLTreeNode* pParentNode)
{
	AVLTreeNode* pRightNode = nullptr;
	if (pParentNode)
	{
		pRightNode = pParentNode->pLeftChild;
		pParentNode->pRightChild = pRightNode->pLeftChild;
		pRightNode->pLeftChild = pParentNode;

		updateHeightAndBalanceAVL(pParentNode);
		updateHeightAndBalanceAVL(pRightNode);
	}
	return pRightNode;
}

AVLTreeNode* AVLTree::rotateRL(AVLTreeNode* pParentNode)
{
	AVLTreeNode* pReturn = nullptr;
	AVLTreeNode* pRightNode = nullptr;
	if (pParentNode)
	{
		pRightNode - pParentNode->pLeftChild;
		pParentNode->pLeftChild = rotateRR(pRightNode);
		pReturn = rotateLL(pParentNode);
	}
	return pReturn;
}

void AVLTree::updateHeightAndBalanceAVL(AVLTreeNode* pNode)
{
	int leftHeight = 0;
	int RightHeight = 0;
	if (pNode)
	{
		if (pNode->pLeftChild)
			leftHeight = pNode->pLeftChild->height;
		if (pNode->pRightChild)
			RightHeight = pNode->pRightChild->height;

		if (leftHeight > RightHeight)
			pNode->height = leftHeight + 1;
		else
			pNode->height = RightHeight + 1;

		pNode->balance = leftHeight - RightHeight;
	}
}

AVLTreeNode* AVLTree::search(int key)
{
	AVLTreeNode* pReturn = nullptr;
	AVLTreeNode* pNode = nullptr;
	
	pNode = pRootNode;
	if (pNode == nullptr)
		return nullptr;
	while (pNode) {
		if (key == pNode->data.key) {
			pReturn = pNode;
		}
		else if (key < pNode->data.key) {
			pNode = pNode->pLeftChild;
		}
		else {
			pNode = pNode->pRightChild;
		}
	}
	return pReturn;
}

void AVLTree::displayAVLTree()
{
	displayAVLTreeInternal(pRootNode, 0, ' ');
}

void AVLTree::displayAVLTreeInternal(AVLTreeNode* pParentNode, int level, char type)
{
	for (int i = 0; i < level; i++)
		std::cout<<"    ";
	if (pParentNode)
	{
		std::cout << "[" << level << ", " << type << "] " << pParentNode->data.key << std::endl;
		displayAVLTreeInternal(pParentNode->pLeftChild, level + 1, 'L');
		displayAVLTreeInternal(pParentNode->pRightChild, level + 1, 'R');
	}
	else
		std::cout << "NULL" << std::endl;
}
