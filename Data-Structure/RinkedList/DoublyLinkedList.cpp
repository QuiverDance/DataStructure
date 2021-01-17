#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
	currentElementCount = 0;
	headerNode.pRLink = new ListNode;
	headerNode.pLLink = new ListNode;
	headerNode.pRLink = &headerNode;
	headerNode.pLLink = &headerNode;
	headerNode.data = 0;
}

void DoublyLinkedList::addElement(int position, ListNode element)
{
	if (position >= 0 && position <= currentElementCount)
	{
		ListNode* pNewNode = new ListNode;
		*pNewNode = element;
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pRLink;
		}
		pNewNode->pRLink = pPreNode->pRLink;
		pNewNode->pLLink = pPreNode;
		pPreNode->pRLink = pNewNode;
		pPreNode->pRLink->pLLink = pNewNode;

		currentElementCount++;
		std::cout << "노드 추가 성공." << std::endl;
		return;
	}
	std::cout << "Error: 노드 추가 실패." << std::endl;
}

void DoublyLinkedList::removeElement(int position)
{
	if (position >= 0 && position < currentElementCount)
	{
		ListNode* pDelNode;
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pRLink;
		}
		pDelNode = pPreNode->pRLink;
		pPreNode->pRLink = pDelNode->pRLink;
		pDelNode->pRLink->pLLink = pPreNode;

		delete pDelNode;
		currentElementCount--;
		std::cout << "노드 제거 성공." << std::endl;
		return;
	}
	std::cout << "Error: 노드 제거 실패." << std::endl;
}

ListNode* DoublyLinkedList::getElement(int positon)
{
	if (positon >= 0 && positon <= currentElementCount)
	{
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < positon; i++)
		{
			pPreNode = pPreNode->pRLink;
		}

		return pPreNode->pRLink;
	}
}

void DoublyLinkedList::clearList()
{
	for (int i = 0; i < currentElementCount; i++)
	{
		DoublyLinkedList::removeElement(i);
	}
}

int DoublyLinkedList::getListLength()
{
	return currentElementCount;
}

void DoublyLinkedList::deleteList()
{
	DoublyLinkedList::clearList();
	delete& headerNode;
}

void DoublyLinkedList::displayList()
{
	ListNode* pPreNode = &headerNode;
	for (int i = 0; i < currentElementCount; i++)
	{
		pPreNode = pPreNode->pRLink;
		std::cout << "Data: " << pPreNode->data << std::endl;
	}
}
