#include "HashingLinkedList.h"
#include <iostream>

HashingLinkedList::HashingLinkedList()
{
	currentElementCount = 0;
	headerNode.pLink = new ListNode;
	headerNode.data = { 0, 0 };
	headerNode.pLink = nullptr;
}

void HashingLinkedList::addElement(int position, ListNode element)
{
	if (position >= 0 && position <= currentElementCount)
	{
		ListNode* pNewNode = new ListNode;
		*pNewNode = element;
		ListNode* pPreNode = &headerNode;

		for (int i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pLink;
		}

		pNewNode->pLink = pPreNode->pLink;
		pPreNode->pLink = pNewNode;

		currentElementCount++;
		return;
	}
	std::cout << "Error: 노드 추가 실패." << std::endl;
}

void HashingLinkedList::removeElement(int position)
{
	if (position >= 0 && position < currentElementCount)
	{
		ListNode* pPreNode = &headerNode;
		for (int i = 0; i < position; i++)
		{
			pPreNode = pPreNode->pLink;
		}
		ListNode* pDelNode = pPreNode->pLink;
		pPreNode->pLink = pDelNode->pLink;
		pDelNode->pLink = nullptr;

		delete pDelNode;
		currentElementCount--;

		return;
	}
	std::cout << "Error: 노드 제거 실패." << std::endl;
}

ListNode* HashingLinkedList::getElement(int positon)
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

ListNode HashingLinkedList::getHeaderNode()
{
	return headerNode;
}

void HashingLinkedList::clearList()
{

	for (int i = 0; i < currentElementCount; i++)
	{
		removeElement(i);
	}
}

int HashingLinkedList::getListLength()
{
	return currentElementCount;
}

void HashingLinkedList::deleteList()
{
	clearList();
}

void HashingLinkedList::displayList()
{
	ListNode* pPreNode = &headerNode;
	for (int i = 0; i < currentElementCount; i++)
	{
		pPreNode = pPreNode->pLink;
		std::cout << "Key: " << pPreNode->data.key << " Value: " << pPreNode->data.value << "  ";
	}
	std::cout << std::endl;
}

HashingLinkedList::~HashingLinkedList()
{
	deleteList();
}

