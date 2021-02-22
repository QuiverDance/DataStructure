#include "AVLLinkedStack.h"
#include <iostream>

AVLLinkedListStack::AVLLinkedListStack()
{
	currentElementCount = 0;
	pTopElement = new StackNode;
	pTopElement = nullptr;
}

AVLLinkedListStack::~AVLLinkedListStack()
{
	deleteStack();
}

void AVLLinkedListStack::push(StackNode element)
{
	if (true)
	{
		StackNode* pNewNode = new StackNode;
		*pNewNode = element;
		pNewNode->pLink = pTopElement;
		pTopElement = pNewNode;
		currentElementCount++;

		std::cout << "push 성공." << std::endl;
		return;
	}
	std::cout << "push 실패." << std::endl;
}

StackNode* AVLLinkedListStack::pop()
{
	if (!isEmpty())
	{
		StackNode* pPopNode = pTopElement;
		pTopElement = pTopElement->pLink;
		pPopNode->pLink = nullptr;
		currentElementCount--;

		std::cout << "pop 성공." << std::endl;
		return pPopNode;
	}
	std::cout << "pop 실패." << std::endl;
}

StackNode* AVLLinkedListStack::peek()
{
	if (!isEmpty())
	{
		std::cout << "peek 성공." << std::endl;
		return pTopElement;
	}
	std::cout << "peek 실패." << std::endl;
}

void AVLLinkedListStack::deleteStack()
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

bool AVLLinkedListStack::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void AVLLinkedListStack::displayStack()
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
