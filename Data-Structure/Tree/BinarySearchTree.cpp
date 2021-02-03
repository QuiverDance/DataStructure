#include "BinarySearchTree.h"
#include <iostream>

BinSearchTree::BinSearchTree()
{
	pRootNode = nullptr;
}

BinSearchTree::~BinSearchTree()
{
	deleteTree(pRootNode);
}

void BinSearchTree::insertElement(BinSearchTreeNode element)
{
	BinSearchTreeNode* pParentNode = pRootNode;
	BinSearchTreeNode* pNewNode = nullptr;
	while (pParentNode != nullptr)
	{
		if (element.key == pParentNode->key)
		{
			std::cout << "중복된 키." << std::endl;
			return;
		}
		else if(element.key < pParentNode->key)
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
	pNewNode = new BinSearchTreeNode;
	if (pNewNode)
	{
		*pNewNode = element;
		pNewNode->pLeftChild = nullptr;
		pNewNode->pRightChild = nullptr;

		if (pParentNode == nullptr)
			pRootNode = pNewNode;
		else
		{
			if (pNewNode->key < pParentNode->key)
				pParentNode->pLeftChild = pNewNode;
			else
				pParentNode->pRightChild = pNewNode;
		}
		std::cout << "데이터 추가 성공." << std::endl;
		return;
	}
	std::cout << "데이터 추가 실패." << std::endl;
}

void BinSearchTree::deleteElement(int key)
{
	BinSearchTreeNode* pParentNode = nullptr;
	BinSearchTreeNode* pDelNode = pRootNode;
	while (pDelNode != nullptr)
	{
		if (key == pDelNode->key)
			break;
		pParentNode = pDelNode;
		if (key < pDelNode->key)
			pDelNode = pDelNode->pLeftChild;
		else
			pDelNode = pDelNode->pRightChild;
	}
	if (pDelNode == nullptr)
	{
		std::cout << "존재하지 않는 키." << std::endl;
		return;
	}
	
	if (pDelNode->pLeftChild == nullptr && pDelNode->pRightChild == nullptr)
	{
		if (pParentNode == nullptr)
			pRootNode = nullptr;
		else
		{
			if (pParentNode->pLeftChild == pDelNode)
				pParentNode->pLeftChild = nullptr;
			else
				pParentNode->pRightChild = nullptr;
		}
	}
	else if (pDelNode->pLeftChild != nullptr && pDelNode->pRightChild != nullptr)
	{
		BinSearchTreeNode* pPredecessor = nullptr;
		BinSearchTreeNode* pSuccessor = nullptr;
		pPredecessor = pDelNode;
		pSuccessor = pDelNode->pLeftChild;
		while (pSuccessor->pRightChild != nullptr)
		{
			pPredecessor = pSuccessor;
			pSuccessor = pSuccessor->pRightChild;
		}

		pPredecessor->pRightChild = pSuccessor->pLeftChild;
		pSuccessor->pLeftChild = pDelNode->pLeftChild;
		pSuccessor->pRightChild = pDelNode->pRightChild;

		if (pParentNode == nullptr)
			pRootNode = pSuccessor;
		else
		{
			if (pParentNode->pLeftChild == pDelNode)
				pParentNode->pLeftChild = pSuccessor;
			else
				pParentNode->pRightChild = pSuccessor;
		}
	}
	else
	{
		BinSearchTreeNode* pChildNode = nullptr;
		if (pDelNode->pLeftChild != nullptr)
			pChildNode = pDelNode->pLeftChild;
		else
			pChildNode = pDelNode->pRightChild;

		if (pParentNode == nullptr)
			pRootNode = pChildNode;
		else
		{
			if (pParentNode->pLeftChild == pDelNode)
				pParentNode->pLeftChild = pChildNode;
			else
				pParentNode->pRightChild = pChildNode;
		}
	}
	delete pDelNode;
	std::cout << "데이터 제거 성공." << std::endl;
	return;
}

BinSearchTreeNode* BinSearchTree::search(int key)
{
	BinSearchTreeNode* pSearchNode = pRootNode;
	while (pSearchNode != nullptr)
	{
		if (key == pSearchNode->key)
			break;
		else if (key < pSearchNode->key)
			pSearchNode = pSearchNode->pLeftChild;
		else
			pSearchNode = pSearchNode->pRightChild;
	}
	return pSearchNode;
}

BinSearchTreeNode* BinSearchTree::getRootNode()
{
	if(pRootNode)
		return pRootNode;
}

void BinSearchTree::deleteTree(BinSearchTreeNode* pParentNode)
{
	if (pParentNode != nullptr)
	{
		deleteTree(pParentNode->pLeftChild);
		deleteTree(pParentNode->pRightChild);
		delete pParentNode;
	}
}

void BinSearchTree::displayTree(BinSearchTreeNode* pParentNode, int level, char type)
{
	for (int i = 0; i < level; i++)
		std::cout << "	";

	if (pParentNode)
	{
		std::cout << "[" << level << ", " << type << "] " << pParentNode->key << std::endl;
		displayTree(pParentNode->pLeftChild, level + 1, 'L');
		displayTree(pParentNode->pRightChild, level + 1, 'R');
	}
	else
		std::cout << "NULL" << std::endl;
}
