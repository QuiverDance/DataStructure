#include "BTreeLinkedStack.h"
#include <iostream>

BTreeLinkedStack::BTreeLinkedStack()
{
	currentElementCount = 0;
	pTopElement = new StackNode;
	pTopElement = nullptr;
}

BTreeLinkedStack::~BTreeLinkedStack()
{
	deleteStack();
}

void BTreeLinkedStack::push(StackNode element)
{
	if (true)
	{
		StackNode* pNewNode = new StackNode;
		*pNewNode = element;
		pNewNode->pLink = pTopElement;
		pTopElement = pNewNode;
		currentElementCount++;

		std::cout << "push ����." << std::endl;
		return;
	}
	std::cout << "push ����." << std::endl;
}

StackNode* BTreeLinkedStack::pop()
{
	if (!isEmpty())
	{
		StackNode* pPopNode = pTopElement;
		pTopElement = pTopElement->pLink;
		pPopNode->pLink = nullptr;
		currentElementCount--;

		std::cout << "pop ����." << std::endl;
		return pPopNode;
	}
	std::cout << "pop ����." << std::endl;
}

StackNode* BTreeLinkedStack::peek()
{
	if (!isEmpty())
	{
		std::cout << "peek ����." << std::endl;
		return pTopElement;
	}
	std::cout << "peek ����." << std::endl;
}

void BTreeLinkedStack::deleteStack()
{
	if (!isEmpty())
	{
		StackNode* pDelNode = pTopElement;
		pTopElement = pTopElement->pLink;

		delete pDelNode;

		currentElementCount = 0;
		delete pTopElement;
	}
}

bool BTreeLinkedStack::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void BTreeLinkedStack::displayStack()
{
	if (!isEmpty())
	{
		StackNode* pCurNode = pTopElement;
		while (pCurNode != nullptr)
		{
			//std::cout << "Data: " << pCurNode->data.value << std::endl;
			pCurNode = pCurNode->pLink;
		}
	}
}
