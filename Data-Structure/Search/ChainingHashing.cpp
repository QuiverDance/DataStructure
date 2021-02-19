#include "ChainingHashing.h"
#include <iostream>

ChainingHashTable::ChainingHashTable(int bucketSize)
{
	if (bucketSize < 0)
		return;
	this->bucketSize = bucketSize;
	currentElementCount = 0;

	ppElement = new HashingLinkedList *[bucketSize];
	if (!ppElement)
		return;
	for (int i = 0; i < bucketSize; i++)
	{
		ppElement[i] = new HashingLinkedList();
		if (!ppElement[i])
			return;
	}
}

ChainingHashTable::~ChainingHashTable()
{
	deleteHashTable();
}

void ChainingHashTable::addElement(HashElement element)
{
	HashingLinkedList* pList = searchBucket(element.key);
	ListNode listNode = { 0, };
	if (pList)
	{
		listNode.data = element;
		pList->addElement(pList->getListLength(), listNode);
		currentElementCount++;
		return;
	}
	std::cout << "데이터 추가 실패." << std::endl;
	return;
}

void ChainingHashTable::deleteElement(char* key)
{
	HashElement* pElement = nullptr;
	HashingLinkedList* pList = nullptr;
	int position = 0;
	pList = searchBucket(key);
	if (pList)
	{
		pElement = searchSlot(pList, key, &position);
		if (pElement)
		{
			pList->removeElement(position);
			currentElementCount--;
			return;
		}
	}
	std::cout << "삭제 실패." << std::endl;
	return;
}

void ChainingHashTable::deleteHashTable()
{
	for (int i = 0; i < bucketSize; i++)
		ppElement[i]->deleteList();
	delete[]ppElement;
}

int ChainingHashTable::hashFunction(char* key)
{
	int index = -1;
	if (key == NULL)
		return index;
	unsigned int tempKey = stringToInt(key);
	if (bucketSize > 0)
		index = tempKey % bucketSize;

	return index;
}

HashElement* ChainingHashTable::search(char* key)
{
	HashingLinkedList* pList = searchBucket(key);
	int position = 0;

	HashElement* pElement = searchSlot(pList, key, &position);
	return pElement;
}

HashingLinkedList* ChainingHashTable::searchBucket(char* key)
{
	HashingLinkedList* pBucket = nullptr;
	int bucketIndex = hashFunction(key);
	if (bucketIndex >= 0)
	{
		pBucket = ppElement[bucketIndex];
		return pBucket;
	}
	std::cout << "잘못된 해쉬 테이블 주소." << std::endl;
	return nullptr;
}

HashElement* ChainingHashTable::searchSlot(HashingLinkedList* pList, char* key, int* pPosition)
{
	HashElement* pElement = nullptr;
	ListNode* pNode = nullptr;
	int position = 0;
	if (pPosition)
	{
		pNode = pList->getElement(0);
		while (pNode != nullptr)
		{
			if (strcmp(pNode->data.key, key) == 0)
			{
				pElement = &(pNode->data);
				*pPosition = position;
				return pElement;
				break;
			}
			pNode = pNode->pLink;
			position++;
		}
		std::cout << "존재하지 않는 키" << std::endl;
	}
}

int ChainingHashTable::getElementCount()
{
	return currentElementCount;
}

void ChainingHashTable::displayHashTable()
{
	for (int i = 0; i < bucketSize; i++)
		ppElement[i]->displayList();
}
