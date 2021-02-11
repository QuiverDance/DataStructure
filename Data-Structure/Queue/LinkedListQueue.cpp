#include "LinkedListQueue.h"
#include <iostream>

LinkedListQueue::LinkedListQueue()
{
	currentElementCount = 0;
	pFrontNode = nullptr;
	pRearNode = pFrontNode;
}

LinkedListQueue::~LinkedListQueue()
{
	deleteQueue();
}

void LinkedListQueue::enqueue(QueueNode element)
{
	QueueNode* pNewNode = new QueueNode;
	if (pNewNode)
	{
		*pNewNode = element;
		pNewNode->pLink = nullptr;

		if (isEmpty())
		{
			pFrontNode = pNewNode;
			pRearNode = pNewNode;
		}
		else
		{
			pRearNode->pLink = pNewNode;
			pRearNode = pNewNode;
		}
		currentElementCount++;
		std::cout << "Enqueue 성공." << std::endl;
		return;
	}
	std::cout << "Enqueue 실패." << std::endl;
}

QueueNode* LinkedListQueue::dequeue()
{
	if (!isEmpty())
	{
		QueueNode* pDeQueueNode = new QueueNode;
		if (pDeQueueNode)
		{
			pDeQueueNode = pFrontNode;
			pFrontNode = pFrontNode->pLink;
			pDeQueueNode->pLink = nullptr;
		}
		currentElementCount--;
		if (isEmpty())
			pRearNode = nullptr;

		std::cout << "Dequeue 성공." << std::endl;
		return pDeQueueNode;
	}
	std::cout << "Dequeue 실패." << std::endl;
}

QueueNode* LinkedListQueue::peek()
{
	if (!isEmpty())
	{
		QueueNode* pPeekNode = pFrontNode;
		std::cout << "peek 성공." << std::endl;
		return pFrontNode;
	}
	std::cout << "peek 실패." << std::endl;
}

void LinkedListQueue::deleteQueue()
{
	QueueNode* pDelNode = nullptr;
	while (pFrontNode != nullptr)
	{
		pDelNode = pFrontNode;
		pFrontNode = pFrontNode->pLink;
		delete pDelNode;
	}
}

bool LinkedListQueue::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void LinkedListQueue::displayQueue()
{
	QueueNode* pCurNode = pFrontNode;
	int i = 0;
	
	while (pCurNode != nullptr)
	{
		std::cout << i << " Data: " << pCurNode->data << std::endl;
		pCurNode = pCurNode->pLink;
		i++;
	}
}
