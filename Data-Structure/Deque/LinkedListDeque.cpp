#include "LinkedListDeque.h"
#include <iostream>

LinkedDeque::LinkedDeque()
{
	currentElementCount = 0;
	pFrontNode = nullptr;
	pRearNode = pFrontNode;
}

LinkedDeque::~LinkedDeque()
{
	deleteDeque();
}

void LinkedDeque::insertFront(DequeNode element)
{
	DequeNode* pNewNode = new DequeNode;
	if (pNewNode)
	{
		*pNewNode = element;
		element.pLLink = nullptr;
		element.pRLink = nullptr;
		if (isEmpty())
		{
			pFrontNode = pNewNode;
			pRearNode = pFrontNode;
		}
		else
		{
			pFrontNode->pLLink = pNewNode;
			pNewNode->pRLink = pFrontNode;
			pFrontNode = pNewNode;
		}
		currentElementCount++;

		std::cout << "InsertFront 성공." << std::endl;
		return;
	}
	std::cout << "InsertFront 실패." << std::endl;
}

void LinkedDeque::insertRear(DequeNode element)
{
	DequeNode* pNewNode = new DequeNode;
	if (pNewNode)
	{
		*pNewNode = element;
		element.pLLink = nullptr;
		element.pRLink = nullptr;
		if (isEmpty())
		{
			pFrontNode = pNewNode;
			pRearNode = pFrontNode;
		}
		else
		{
			pRearNode->pRLink = pNewNode;
			pNewNode->pLLink = pRearNode;
			pRearNode = pNewNode;
		}
		currentElementCount++;

		std::cout << "insertRear 성공." << std::endl;
		return;
	}
	std::cout << "insertRear 실패." << std::endl;
}

DequeNode* LinkedDeque::deleteFront()
{
	if (!isEmpty())
	{
		DequeNode* pDelNode = pFrontNode;
		pFrontNode = pDelNode->pRLink;
		pDelNode->pRLink = nullptr;
		
		currentElementCount--;
		if (isEmpty())
		{
			pRearNode = nullptr;
		}
		else
		{
			pFrontNode->pLLink = nullptr;
		}
		std::cout << "deleteFront 성공." << std::endl;
		return pDelNode;
	}
	std::cout << "deleteFront 실패." << std::endl;
}

DequeNode* LinkedDeque::deleteRear()
{
	if (!isEmpty())
	{
		DequeNode* pDelNode = pRearNode;
		pRearNode = pDelNode->pLLink;
		pDelNode->pLLink = nullptr;

		currentElementCount--;
		if (isEmpty())
		{
			pFrontNode = nullptr;
		}
		else
		{
			pRearNode->pRLink = nullptr;
		}
		std::cout << "deleteRear 성공." << std::endl;
		return pDelNode;
	}
	std::cout << "deleteRear 실패." << std::endl;
}

DequeNode* LinkedDeque::peekFront()
{
	if (!isEmpty())
	{
		DequeNode* pPeekNode = pFrontNode;
		std::cout << "peekFront 성공." << std::endl;
		return pPeekNode;
	}
	std::cout << "peekFront 실패." << std::endl;

}

DequeNode* LinkedDeque::peekRear()
{
	if (!isEmpty())
	{
		DequeNode* pPeekNode = pRearNode;
		std::cout << "peekRear 성공." << std::endl;
		return pPeekNode;
	}
	std::cout << "peekRear 실패." << std::endl;
}

void LinkedDeque::deleteDeque()
{
	DequeNode* pCurNode = pFrontNode;
	DequeNode* pDelNode = nullptr;
	while (pCurNode != nullptr)
	{
		pDelNode = pCurNode;
		pCurNode = pCurNode->pRLink;
		delete pDelNode;
	}
}

bool LinkedDeque::isEmpty()
{
	if (currentElementCount == 0)
		return true;
	return false;
}

void LinkedDeque::displayDeque()
{
	DequeNode* pCurNode = pFrontNode;
	for (int i = 0; i < currentElementCount; i++)
	{
		std::cout << i << " Data: " << pCurNode->data << std::endl;
		pCurNode = pCurNode->pRLink;
	}
}
