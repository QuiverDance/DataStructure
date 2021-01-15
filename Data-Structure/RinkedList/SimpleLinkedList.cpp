#include "SimpleLinkedList.h"
#include <iostream>

SimpleLinkedList::SimpleLinkedList()
{
	currentElementCount = 0;
	headerNode.pLink = new ListNode;
	headerNode.data = 0;
	headerNode.pLink = nullptr;
}

void SimpleLinkedList::addElement(int positon, ListNode element)
{
	ListNode* pNewNode = new ListNode;
	*pNewNode = element;
	pNewNode->pLink = nullptr;
	
	if (positon >= 0 && positon <= currentElementCount)
	{
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < positon; i++)
		{
			pPreNode = pPreNode->pLink;
		}

		pNewNode->pLink = pPreNode->pLink;
		pPreNode->pLink = pNewNode;

		currentElementCount++;
		std::cout << "��� �߰� ����." << std::endl;
		return;
	}
	std::cout << "Error: ��� �߰� ����." << std::endl;
}

void SimpleLinkedList::removeElement(int position)
{
	if (position >= 0 && position < currentElementCount)
	{
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pLink;
		}
		ListNode* pOldElement = pPreNode->pLink;
		pPreNode->pLink = pOldElement->pLink;
		pOldElement->pLink = nullptr;

		delete pOldElement;
		currentElementCount--;
		std::cout << "��� ���� ����." << std::endl;
		return;
	}
	std::cout << "Error: ��� ���� ����." << std::endl;
}

ListNode* SimpleLinkedList::getElement(int positon)
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

void SimpleLinkedList::clearList()
{
	for (int i = 0; i < currentElementCount; i++)
	{
		SimpleLinkedList::removeElement(i);
	}
}

int SimpleLinkedList::getListLength()
{
	return currentElementCount;
}

void SimpleLinkedList::deleteList()
{
	SimpleLinkedList::clearList();
	delete &headerNode;
}

void SimpleLinkedList::displayList()
{
	ListNode* pPreNode = &headerNode;
	for (int i = 0; i < currentElementCount; i++)
	{
		pPreNode = pPreNode->pLink;
		std::cout << "Data: " << pPreNode->data << std::endl;
	}
}
