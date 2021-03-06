#include "ArrayQueue.h"
#include <iostream>

ArrayQueue::ArrayQueue(int maxElementCount)
{
	this->maxElementCount = maxElementCount;
	currentElementCount = 0;
	front = -1;
	rear = front;
	pElement = new ArrayQueueNode[maxElementCount];
}

ArrayQueue::~ArrayQueue()
{
	deleteQueue();
}

void ArrayQueue::enqueue(ArrayQueueNode element)
{
	if (pElement && !isFull())
	{
		if (element.element)
		{
			rear = (rear + 1) % maxElementCount;
			pElement[rear] = element;
			currentElementCount++;
			std::cout << "Enqueue 성공." << std::endl;
			return;
		}
	}
	std::cout << "Enqueue 실패." << std::endl;
}

ArrayQueueNode* ArrayQueue::dequeue()
{
	if (pElement && !isEmpty())
	{
		ArrayQueueNode* pDequeueNode = new ArrayQueueNode;
		if (pDequeueNode)
		{
			front = (front + 1) % maxElementCount;
			pDequeueNode->element = pElement[front].element;
			currentElementCount--;
			std::cout << "Dequeue 성공." << std::endl;
			return pDequeueNode;
		}
	}
	std::cout << "Dequeue 실패." << std::endl;
}

ArrayQueueNode* ArrayQueue::peek()
{
	if (pElement && !isEmpty())
	{
		ArrayQueueNode* pPeekNode;
		pPeekNode = &pElement[front + 1];
		std::cout << "Peek 성공." << std::endl;
		return pPeekNode;
	}
	std::cout << "Peek 실패." << std::endl;
}

void ArrayQueue::deleteQueue()
{
	if (pElement)
	{
		delete pElement;
	}
}

bool ArrayQueue::isFull()
{
	if (currentElementCount == maxElementCount)
		return true;
	return false;
}

bool ArrayQueue::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void ArrayQueue::displayQueue()
{
	std::cout << "Front: " << front << " Rear: " << rear << std::endl;
	int maxIndex = front + currentElementCount;
	int index = 0;
	for (int i = front + 1; i <= maxIndex; i++)
	{
		index = i % maxElementCount;
		std::cout << index << " Data :" << pElement[index].element << std::endl;
	}
} 
