#include "CircularLinkedList.h"
#include <iostream>

CircularLinkedList::CircularLinkedList()
{
	currentElementCount = 0;
	headerNode.pLink = new ListNode;
	headerNode.pLink = nullptr;
	headerNode.data = 0;
}

void CircularLinkedList::addElement(int position, ListNode element)
{
	ListNode* pNewNode = new ListNode;
	*pNewNode = element;
	pNewNode->pLink = nullptr;

	if (position >= 0 && position <= currentElementCount)
	{
		if (position == 0)
		{
			if (currentElementCount == 0)
			{
				headerNode.pLink = pNewNode;
				pNewNode->pLink = pNewNode;
			}
			else
			{
				ListNode* pLastNode = headerNode.pLink;
				while (!(pLastNode->pLink == headerNode.pLink))
				{
					pLastNode = pLastNode->pLink;
				}
				headerNode.pLink = pNewNode;
				pNewNode->pLink = pLastNode->pLink;
				pLastNode->pLink = pNewNode;
			}
		}

		else
		{
			ListNode* pPreNode = &headerNode;
			for (int i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pLink;
			}
			pNewNode->pLink = pPreNode->pLink;
			pPreNode->pLink = pNewNode;
		}

		currentElementCount++;
		std::cout << "노드 추가 성공." << std::endl;
		return;
	}
	std::cout << "Error: 노드 추가 실패." << std::endl;
}

void CircularLinkedList::removeElement(int position)
{
	if (position >= 0 && position < currentElementCount)
	{
		ListNode* pDelNode;
		if (position == 0)
		{
			pDelNode = headerNode.pLink;
			if (currentElementCount == 1)
			{
				headerNode.pLink = nullptr;
			}
			else
			{
				ListNode* pLastNode = headerNode.pLink;
				while (!(pLastNode->pLink == headerNode.pLink))
				{
					pLastNode = pLastNode->pLink;
				}
				pLastNode->pLink = pDelNode->pLink;
				headerNode.pLink = pDelNode->pLink;
			}
		}
		else
		{
			ListNode* pPreNode = &headerNode;
			for (int i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pLink;
			}
			pDelNode = pPreNode->pLink;
			pPreNode->pLink = pDelNode->pLink;
		}

		delete pDelNode;
		currentElementCount--;
		std::cout << "노드 제거 성공." << std::endl;
		return;
	}
	std::cout << "Error: 노드 제거 실패." << std::endl;
}

ListNode* CircularLinkedList::getElement(int positon)
{
	if (positon >= 0 && positon <= currentElementCount)
	{
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < positon; i++)
		{
			pPreNode = pPreNode->pLink;
		}

		return pPreNode->pLink;
	}
}

void CircularLinkedList::clearList()
{
	for (int i = 0; i < currentElementCount; i++)
	{
		CircularLinkedList::removeElement(i);
	}
}

int CircularLinkedList::getListLength()
{
	return currentElementCount;
}

void CircularLinkedList::deleteList()
{
	CircularLinkedList::clearList();
	delete &headerNode;
}

void CircularLinkedList::displayList()
{
	ListNode* pPreNode = &headerNode;
	for (int i = 0; i < currentElementCount; i++)
	{
		pPreNode = pPreNode->pLink;
		std::cout << "Data: " << pPreNode->data << std::endl;
	}
}
