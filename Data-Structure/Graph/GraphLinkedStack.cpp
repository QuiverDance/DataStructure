#include "GraphLinkedStack.h"
#include <iostream>

LinkedStack::LinkedStack()
{
	currentElementCount = 0;
	pTopElement = new StackNode;
	pTopElement = nullptr;
}

LinkedStack::~LinkedStack()
{
	deleteStack();
}

void LinkedStack::push(StackNode element)
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

StackNode* LinkedStack::pop()
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

StackNode* LinkedStack::peek()
{
	if (!isEmpty())
	{
		std::cout << "peek ����." << std::endl;
		return pTopElement;
	}
	std::cout << "peek ����." << std::endl;
}

void LinkedStack::deleteStack()
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

bool LinkedStack::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void LinkedStack::displayStack()
{
	if (!isEmpty())
	{
		StackNode* pCurNode = pTopElement;
		while (pCurNode != nullptr)
		{
			std::cout << "Data: " << pCurNode->data << std::endl;
			pCurNode = pCurNode->pLink;
		}
	}
}
