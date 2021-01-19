#include "ArrayStack.h"
#include <iostream>

ArrayStack::ArrayStack(int maxElementCount)
{
	this->maxElementCount = maxElementCount;
	this->currentElementCount = 0;
	this->pElement = new ArrayStackNode[maxElementCount];
}

void ArrayStack::push(ArrayStackNode element)
{
	if (!isFull())
	{
		pElement[currentElementCount] = element;
		currentElementCount++;
		std::cout << "Push 성공." << std::endl;
	}
}

ArrayStackNode* ArrayStack::pop()
{
	if (!isEmpty())
	{
		ArrayStackNode returnNode = pElement[currentElementCount - 1];
		pElement[currentElementCount - 1].data = NULL;
		currentElementCount--;
		std::cout << "Pop 성공." << std::endl;
		return &returnNode;
	}
}

ArrayStackNode* ArrayStack::peek()
{
	if (!isEmpty())
	{
		ArrayStackNode returnNode = pElement[currentElementCount - 1];
		std::cout << "Peek 성공." << std::endl;
		return &returnNode;
	}
}

void ArrayStack::deleteStack()
{
	delete pElement;
}

bool ArrayStack::isFull()
{
	if (currentElementCount == maxElementCount)
	{
		std::cout << "is full." << std::endl;
		return true;
	}
	else
		return false;
}

bool ArrayStack::isEmpty()
{
	if (currentElementCount == 0)
	{
		std::cout << "is empty." << std::endl;
		return true;
	}
	else
		return false;
}

void ArrayStack::displayStack()
{
	for (int i = 0; i < currentElementCount; i++)
		std::cout << i << " : " << pElement[i].data << std::endl;
}

ArrayStack::~ArrayStack()
{
	deleteStack();
}
