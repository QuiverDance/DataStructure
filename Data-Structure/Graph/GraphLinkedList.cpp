#include "GraphLinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	currentElementCount = 0;
	headerNode.pLink = new ListNode;
	headerNode.data = {0, 0};
	headerNode.pLink = nullptr;
}

void LinkedList::addElement(int position, ListNode element)
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
		//std::cout << "노드 추가 성공." << std::endl;
		return;
	}
	std::cout << "Error: 노드 추가 실패." << std::endl;
}

void LinkedList::removeElement(int position)
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
		//std::cout << "노드 제거 성공." << std::endl;
		return;
	}
	//std::cout << "Error: 노드 제거 실패." << std::endl;
}

ListNode* LinkedList::getElement(int positon)
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

ListNode LinkedList::getHeaderNode()
{
	return headerNode;
}

void LinkedList::clearList()
{
	for (int i = 0; i < currentElementCount; i++)
	{
		removeElement(i);
	}
}

int LinkedList::getListLength()
{
	return currentElementCount;
}

void LinkedList::deleteList()
{
	clearList();
}

void LinkedList::displayList()
{
	ListNode* pPreNode = &headerNode;
	for (int i = 0; i < currentElementCount; i++)
	{
		pPreNode = pPreNode->pLink;
		std::cout << "VertexID: "<<pPreNode->data.vertexID<< " Weigth: " << pPreNode->data.weight;
	}
	std::cout << std::endl;
}

LinkedList::~LinkedList()
{
	deleteList();
}

