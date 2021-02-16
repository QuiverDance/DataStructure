#include "SortQueue.h"
#include <iostream>

SortQueue::SortQueue()
{
	currentElementCount = 0;
	pFrontNode = nullptr;
	pRearNode = pFrontNode;
}

SortQueue::~SortQueue()
{
	deleteQueue();
}

void SortQueue::enqueue(QueueNode element)
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
		return;
	}
	std::cout << "Enqueue 실패." << std::endl;
}

QueueNode* SortQueue::dequeue()
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

		return pDeQueueNode;
	}
	std::cout << "Dequeue 실패." << std::endl;
}

QueueNode* SortQueue::peek()
{
	if (!isEmpty())
	{
		QueueNode* pPeekNode = pFrontNode;
		return pFrontNode;
	}
	std::cout << "peek 실패." << std::endl;
}

void SortQueue::deleteQueue()
{
	QueueNode* pDelNode = nullptr;
	while (pFrontNode != nullptr)
	{
		pDelNode = pFrontNode;
		pFrontNode = pFrontNode->pLink;
		delete pDelNode;
	}
}

bool SortQueue::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void SortQueue::displayQueue()
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
