#include "GraphLinkedQueue.h"
#include <iostream>

LinkedQueue::LinkedQueue()
{
	currentElementCount = 0;
	pFrontNode = nullptr;
	pRearNode = pFrontNode;
}

LinkedQueue::~LinkedQueue()
{
	deleteQueue();
}

void LinkedQueue::enqueue(QueueNode element)
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
		std::cout << "Enqueue ����." << std::endl;
		return;
	}
	std::cout << "Enqueue ����." << std::endl;
}

QueueNode* LinkedQueue::dequeue()
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

		std::cout << "Dequeue ����." << std::endl;
		return pDeQueueNode;
	}
	std::cout << "Dequeue ����." << std::endl;
}

QueueNode* LinkedQueue::peek()
{
	if (!isEmpty())
	{
		QueueNode* pPeekNode = pFrontNode;
		std::cout << "peek ����." << std::endl;
		return pFrontNode;
	}
	std::cout << "peek ����." << std::endl;
}

void LinkedQueue::deleteQueue()
{
	QueueNode* pDelNode = nullptr;
	while (pFrontNode != nullptr)
	{
		pDelNode = pFrontNode;
		pFrontNode = pFrontNode->pLink;
		delete pDelNode;
	}
}

bool LinkedQueue::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void LinkedQueue::displayQueue()
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
