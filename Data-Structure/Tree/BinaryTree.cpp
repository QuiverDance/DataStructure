#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree(BinTreeNode rootNode)
{
	pRootNode = new BinTreeNode;
	if (pRootNode)
	{
		*pRootNode = rootNode;
		pRootNode->pLeftChild = nullptr;
		pRootNode->pRightChild = nullptr;
	}
}

BinaryTree::~BinaryTree()
{
	deleteTree();
}

BinTreeNode* BinaryTree::getRootNode()
{
	if (pRootNode)
	{
		return pRootNode;
	}
}

BinTreeNode* BinaryTree::insertLeftChildNode(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode && pParentNode->pLeftChild == nullptr)
	{
		pParentNode->pLeftChild = new BinTreeNode;
		if (pParentNode->pLeftChild)
		{
			*(pParentNode->pLeftChild) = element;
			pParentNode->pLeftChild->pLeftChild = nullptr;
			pParentNode->pLeftChild->pRightChild = nullptr;

			BinTreeNode* pNewNode = pParentNode->pLeftChild;
			std::cout << "Left Node is inserted." << std::endl;
			return pNewNode;
		}
	}
	std::cout << "Left Node is not inserted." << std::endl;
}

BinTreeNode* BinaryTree::insertRightChildNode(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode && pParentNode->pRightChild == nullptr)
	{
		pParentNode->pRightChild = new BinTreeNode;
		if (pParentNode->pRightChild)
		{
			*(pParentNode->pRightChild) = element;
			pParentNode->pRightChild->pLeftChild = nullptr;
			pParentNode->pRightChild->pRightChild = nullptr;

			BinTreeNode* pNewNode = pParentNode->pRightChild;
			std::cout << "Right Node is inserted." << std::endl;
			return pNewNode;
		}
	}
	std::cout << "Right Node is not inserted." << std::endl;
}

BinTreeNode* BinaryTree::getLeftChildNode(BinTreeNode* pParentNode)
{
	if (pParentNode)
	{
		return pParentNode->pLeftChild;
	}
}

BinTreeNode* BinaryTree::getRightChildNode(BinTreeNode* pParentNode)
{
	if (pParentNode)
	{
		return pParentNode->pRightChild;
	}
}

void BinaryTree::deleteTree()
{
	deleteTreeNode(pRootNode);
}

void BinaryTree::deleteTreeNode(BinTreeNode* pDelNode)
{
	if (pDelNode)
	{
		deleteTreeNode(pDelNode->pLeftChild);
		deleteTreeNode(pDelNode->pRightChild);
		delete pDelNode;
	}
}

void BinaryTree::preorderTraversalRecursiveTree(BinTreeNode* pParentNode)
{
	if (pParentNode != nullptr)
	{
		std::cout << pParentNode->data << " ";
		preorderTraversalRecursiveTree(pParentNode->pLeftChild);
		preorderTraversalRecursiveTree(pParentNode->pRightChild);
	}
}

void BinaryTree::inorderTraversalRecursiveTree(BinTreeNode* pParentNode)
{
	if (pParentNode != nullptr)
	{
		inorderTraversalRecursiveTree(pParentNode->pLeftChild);
		std::cout << pParentNode->data << " ";
		inorderTraversalRecursiveTree(pParentNode->pRightChild);
	}
}

void BinaryTree::postorderTraversalRecursiveTree(BinTreeNode* pParentNode)
{
	if (pParentNode != nullptr)
	{
		postorderTraversalRecursiveTree(pParentNode->pLeftChild);
		postorderTraversalRecursiveTree(pParentNode->pRightChild);
		std::cout << pParentNode->data << " ";
	}
}

int BinaryTree::getNodeCount(BinTreeNode* pParentNode)
{
	int count = 0;
	if (pParentNode != nullptr)
	{
		count = getNodeCount(pParentNode->pLeftChild) + getNodeCount(pParentNode->pRightChild) + 1;
	}
	return count;
}

int BinaryTree::getLeafNodeCount(BinTreeNode* pParentNode)
{
	int count = 0;
	if (pParentNode)
	{
		if (pParentNode->pLeftChild == nullptr && pParentNode->pRightChild == nullptr)
		{
			return 1;
		}
		else
		{
			count = getLeafNodeCount(pParentNode->pLeftChild) + getLeafNodeCount(pParentNode->pRightChild);
		}
	}
	return count;
}

int BinaryTree::getHeight(BinTreeNode* pParentNode)
{
	int height = 0;
	if (pParentNode)
	{
		if (pParentNode->pLeftChild == nullptr && pParentNode->pRightChild == nullptr)
		{
			return 1;
		}
		else
		{
			int leftChildHeight = getHeight(pParentNode->pLeftChild);
			int rightChildHeight = getHeight(pParentNode->pRightChild);
			if (leftChildHeight > rightChildHeight)
				height = leftChildHeight + 1;
			else
				height = rightChildHeight + 1;
		}
	}
	return height;
}

void BinaryTree::displayTree(BinTreeNode* pParentNode, int level, char type)
{
	for (int i = 0; i < level; i++)
	{
		std::cout << "    ";
	}
	if (pParentNode)
	{
		std::cout << "[" << level << "," << type << "] " << pParentNode->data << std::endl;
		displayTree(pParentNode->pLeftChild, level + 1, 'L');
		displayTree(pParentNode->pRightChild, level + 1, 'R');
	}
	else
	{
		std::cout << "Null" << std::endl;
	}
}
