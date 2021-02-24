#include "BTree.h"
#include <iostream>

BTree::BTree()
{
	pRootNode = nullptr;
}

BTree::~BTree()
{
	deleteBTree();
}

BTreeNode* BTree::createBTreeNode(BTreeNodeData element)
{
	BTreeNode* pReturn = new BTreeNode;
	if (!pReturn)
		return nullptr;
	pReturn->element[0] = element;
	pReturn->elementCount = 0;
}

void BTree::deleteBTree()
{
	deleteBTreeNode(pRootNode);
}

void BTree::deleteBTreeNode(BTreeNode* pDelNode)
{
	if (pDelNode != nullptr)
	{
		for (int i = 0; i <= pDelNode->elementCount; i++)
			deleteBTreeNode(pDelNode->pChildren[i]);
		delete pDelNode;
	}
}

BTreeNodeData* BTree::search(int key)
{
	BTreeNode* pCurrentNode = nullptr;

	pCurrentNode = pRootNode;
	int i = 0;
	while (pCurrentNode != nullptr)
	{
		for (i = 0; i < pCurrentNode->elementCount; i++)
		{
			int parentKey = pCurrentNode->element[i].key;
			if (key == parentKey)
			{
				return &pCurrentNode->element[i];
			}
			else if (key < parentKey)
				break;
		}
		pCurrentNode = pCurrentNode->pChildren[i];
	}
	return nullptr;
}

void BTree::insertNode(BTreeNodeData element)
{
	BTreeNode* pParentNode = nullptr, * pCurrentNode = nullptr, * pNewNode = nullptr;
	BTreeLinkedStack* pStack = nullptr;
	pStack = new BTreeLinkedStack();
	if (!pStack)
		return;

	pCurrentNode = pRootNode;
	int i = 0;
	while (pCurrentNode != nullptr)
	{
		pParentNode = pCurrentNode;
		pushBTreeNode(pStack, pParentNode);
		for (i = 0; i < pCurrentNode->elementCount; i++)
		{
			int parentKey = pCurrentNode->element[i].key;
			if (element.key == parentKey)
			{
				pStack->deleteStack();
				delete pStack;
				return;
			}
			else if (element.key < parentKey)
				break;
		}
		pCurrentNode = pCurrentNode->pChildren[i];
	}

	if (pParentNode == nullptr)
	{
		pRootNode = createBTreeNode(element);
	}
	else
	{
		insertNodeElement(pParentNode, element, nullptr);
		splitNode(pStack);
	}
	pStack->deleteStack();
	delete pStack;
}

void BTree::insertNodeElement(BTreeNode* pCurrentNode, BTreeNodeData element, BTreeNode* pChildNode)
{
	int i = 0;
	for (i = pCurrentNode->elementCount - 1; i >= 0; i--)
	{
		int tempKey = pCurrentNode->element[i].key;
		if (element.key < tempKey)
		{
			pCurrentNode->element[i + 1] = pCurrentNode->element[i];
			pCurrentNode->element[i + 2] = pCurrentNode->element[i + 1];
		}
		else
			break;
	}
	pChildNode->element[i + 1] = element;
	pChildNode->pChildren[i + 2] = pChildNode;
	pChildNode->elementCount++;
}

void BTree::deleteNode(int key)
{
	BTreeNode* pParentNode = nullptr, * pCurrentNdoe = nullptr, * pDelNode = nullptr;
	BTreeLinkedStack* pStack = nullptr;
	bool isFind = false, isFinish = false;
	pStack = new BTreeLinkedStack();
	if (!pStack)
		return;

	pCurrentNdoe = pRootNode;
	int i = 0;
	while (pCurrentNdoe != nullptr && isFind == false)
	{
		pParentNode = pCurrentNdoe;
		pushBTreeNode(pStack, pParentNode);

		for (i = 0; i < pCurrentNdoe->elementCount; i++)
		{
			int parentKey = pCurrentNdoe->element[i].key;
			if (key == parentKey)
			{
				isFind = true;
				break;
			}
			else if (key < parentKey)
				break;
		}
		pCurrentNdoe = pCurrentNdoe->pChildren[i];
	}
	if (isFind == true)
	{
		if (isLeafNode(pParentNode) == false)
			pParentNode = replaceLeafNode(pParentNode, i, pStack);
		else
			deleteKey(pParentNode, i);
		if (pParentNode->elementCount < BTREE_ORDER / 2)
			balanceBTree(pStack);
	}
	pStack->deleteStack();
	delete pStack;
}

void BTree::splitNode(BTreeLinkedStack* pStack)
{
	if (pStack == nullptr)
		return;
	StackNode* pParentStackNode = nullptr, * pCurrentStackNode = nullptr;
	BTreeNode* pParentNode = nullptr, * pCurrentNode = nullptr, * pNewNode = nullptr;
	BTreeNodeData pivotElement = { 0, };
	int pivotIndex = BTREE_ORDER / 2;

	pCurrentStackNode = pStack->pop();
	int i = 0;
	while (pCurrentNode != nullptr);
	{
		pCurrentNode = pCurrentStackNode->data;
		if (pCurrentNode->elementCount >= BTREE_ORDER)
		{
			pNewNode = new BTreeNode;
			if (!pNewNode)
				return;
			pivotElement = pCurrentNode->element[pivotIndex];
			
			for (i = pivotIndex + 1; i < BTREE_ORDER; i++)
			{
				pNewNode->element[i - pivotIndex - 1] = pCurrentNode->element[i];
				pNewNode->pChildren[i - pivotIndex - 1] = pCurrentNode->pChildren[i];

				pCurrentNode->pChildren[i] = nullptr;
			}
			pNewNode->pChildren[i - pivotIndex - 1] = pCurrentNode->pChildren[i];
			pCurrentNode->pChildren[i] = nullptr;
			pNewNode->elementCount = BTREE_ORDER - pivotIndex - 1;
			pCurrentNode->elementCount = pivotIndex;

			pParentStackNode = pStack->pop();
			if (pParentStackNode != nullptr)
				insertNodeElement(pParentStackNode->data, pivotElement, pNewNode);
			else
			{
				pRootNode = createBTreeNode(pivotElement);
				pRootNode->pChildren[0] = pCurrentNode;
				pRootNode->pChildren[1] = pNewNode;
			}
		}
	}

}

bool BTree::isLeafNode(BTreeNode* pParentNode)
{
	if (pParentNode != nullptr)
	{
		if (pParentNode->pChildren[0] == nullptr)
			return true;
	}
	return false;
}

int BTree::getIndexInfo(BTreeNode* pParentNode, BTreeNode* pCurrentNode)
{
	if (pParentNode != nullptr)
	{
		for (int i = 0; i <= pParentNode->elementCount; i++)
		{
			if (pParentNode->pChildren[i] == pCurrentNode)
			{
				return i;
				break;
			}
		}
	}
	return 0;
}

BTreeNode* BTree::replaceLeafNode(BTreeNode* pDelNode, int index, BTreeLinkedStack* pStack)
{
	BTreeNodeData leafNodeElement = { 0, };
	BTreeNode* pParentNode = pDelNode, * pChildNode = nullptr;
	int elementCount = index;

	if (pDelNode == nullptr)
		return nullptr;

	do
	{
		pChildNode = pParentNode->pChildren[elementCount];
		pushBTreeNode(pStack, pChildNode);

		elementCount = pChildNode->elementCount;
		pParentNode = pChildNode;
	} while (pChildNode->pChildren[elementCount] != nullptr);

	leafNodeElement = pChildNode->element[elementCount - 1];
	pDelNode->element[index] = leafNodeElement;
	deleteKey(pChildNode, elementCount - 1);

	return pChildNode;
}

void BTree::balanceBTree(BTreeLinkedStack* pStack)
{
	if (pStack == nullptr)
		return;
	StackNode* pParentStackNode = nullptr, * pCurrentStackNode = nullptr;
	BTreeNode* pParentNode = nullptr, * pCurrentNode = nullptr, * pNewNode = nullptr;
	BTreeNode* pLeftNode = nullptr, * pRightNode = nullptr;
	BTreeNodeData pivotElement = { 0, };
	int pivotIndex = BTREE_ORDER / 2;

	int i = 0, index = 0;

	pCurrentStackNode = pStack->pop();
	if (!pCurrentStackNode)
		return;

	pCurrentNode = pCurrentStackNode->data;
	if (pCurrentNode->elementCount >= BTREE_ORDER / 2)
	{
		delete pCurrentStackNode;
		return;
	}

	pParentStackNode = pStack->pop();
	if (!pParentStackNode)
	{
		delete pCurrentStackNode;
		return;
	}

	pParentNode = pParentStackNode->data;
	index = getIndexInfo(pParentNode, pCurrentNode);
	if (index < pParentNode->elementCount && pParentNode->pChildren[index + 1]->elementCount >= BTREE_ORDER / 2 + 1)
		borrowRightNode(pParentNode, pCurrentNode, index, pParentNode->pChildren[index + 1]);
	else if (index > 0 && pParentNode->pChildren[index - 1]->elementCount >= BTREE_ORDER / 2 + 1)
		borrowRightNode(pParentNode, pCurrentNode, index, pParentNode->pChildren[index - 1]);
	else
		mergeNode(pStack, pParentNode, pCurrentNode, index);

	if (pCurrentNode != nullptr)
		delete pCurrentStackNode;
	if (pParentNode != nullptr)
		delete pParentStackNode;
}

void BTree::deleteKey(BTreeNode* pNode, int index)
{
	if (pNode != nullptr)
	{
		for (int i = index + 1; i < pNode->elementCount; i++)
		{
			pNode->element[i - 1] = pNode->element[i];
			pNode->pChildren[i] = pNode->pChildren[i + 1];
		}
		pNode->pChildren[pNode->elementCount] = nullptr;

		pNode->elementCount--;
	}
}

void BTree::borrowRightNode(BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index, BTreeNode* pRightNode)
{
	if (pParentNode == nullptr || pCurrentNode == nullptr || pRightNode == nullptr)
		return;
	int elementCount = 0;

	elementCount = pCurrentNode->elementCount;
	pCurrentNode->element[elementCount] = pParentNode->element[index];
	pCurrentNode->elementCount++;

	pParentNode->element[index] = pRightNode->element[0];

	deleteKey(pRightNode, 0);
}

void BTree::borrowLeftNode(BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index, BTreeNode* pLeftNode)
{
	if (pParentNode == nullptr || pCurrentNode == nullptr || pRootNode == nullptr)
		return;
	int elementCount = 0;
	BTreeNodeData leftElement = { 0, };
	BTreeNodeData parentElement = { 0, };

	elementCount = pLeftNode->elementCount;
	leftElement = pLeftNode->element[elementCount - 1];
	parentElement = pParentNode->element[index - 1];
	deleteKey(pLeftNode, elementCount - 1);

	insertNodeElement(pCurrentNode, parentElement, nullptr);
}

void BTree::mergeNode(BTreeLinkedStack* pStack, BTreeNode* pParentNode, BTreeNode* pCurrentNode, int index)
{
	if (pStack == nullptr || pParentNode == nullptr || pCurrentNode == nullptr)
		return;
	StackNode* pParentStackNode = { 0, };
	BTreeNode* pParentParentNode = nullptr, * pLeftNode = nullptr, * pRightNode = nullptr;
	BTreeNodeData parentElement = { 0, };

	int pivotIndex = 0;
	if (index < pParentNode->elementCount)
	{
		pLeftNode = pCurrentNode;
		pRightNode = pParentNode->pChildren[index + 1];
		pivotIndex = index;
		parentElement = pParentNode->element[pivotIndex];
	}
	else
	{
		pLeftNode = pParentNode->pChildren[index - 1];
		pRightNode = pCurrentNode;
		pivotIndex = index - 1;
		parentElement = pParentNode->element[pivotIndex];
	}

	insertNodeElement(pLeftNode, parentElement, pRightNode->pChildren[0]);

	for (int i = 0; i < pRightNode->elementCount; i++)
		insertNodeElement(pLeftNode, pRightNode->element[i], pRightNode->pChildren[i + 1]);

	deleteKey(pParentNode, pivotIndex);
	delete pRightNode;

	if (pParentNode->elementCount < BTREE_ORDER / 2)
	{
		int idx = 0;
		pParentStackNode = pStack->pop();
		if (pParentStackNode != nullptr)
		{
			pParentParentNode = pParentStackNode->data;
			idx = getIndexInfo(pParentParentNode, pParentNode);

			mergeNode(pStack, pParentParentNode, pParentNode, idx);
			delete(pParentStackNode);
		}
		else
		{
			if (pParentNode->elementCount == 0)
			{
				delete pRootNode;
				pRootNode = pLeftNode;
			}
		}
	}
}

void BTree::pushBTreeNode(BTreeLinkedStack* pStack, BTreeNode* pData)
{
	StackNode data = { 0, };
	data.data = pData;
	pStack->push(data);
}

void BTree::displayTree()
{
	displayTreeNode(pRootNode);
}

void BTree::displayTreeNode(BTreeNode* pNode)
{
	static int x = 0;
	if (pNode != nullptr)
	{
		x += 2;
		for (int i = 2; i < x; i++)
			std::cout << "    ";
		for (int i = 0; i < pNode->elementCount; i++)
			std::cout << "(" << pNode->element[i].key << ", " << pNode->element[i].value << ") ";
		std::cout << std::endl;
		for (int i = 0; i < pNode->elementCount + 1; i++)
			displayTreeNode(pNode->pChildren[i]);

		x -= 2;
	}
}
