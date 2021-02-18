#include "StaticHashing.h"
#include <iostream>

HashTable::HashTable(int bucketSize)
{
	if (bucketSize <= 0)
		return;
	this->bucketSize = bucketSize;
	currentElementCount = 0;
	pElement = new HashElement[bucketSize];
	if (!pElement)
		return;
	HashElement element = { "None", EMPTY };
	for (int i = 0; i < bucketSize; i++)
	{
		pElement[i] = element;
	}
}

HashTable::~HashTable()
{
	deleteHashTable();
}

void HashTable::addElement(HashElement element)
{
	int bucketIndex = hashFunction(element.key, bucketSize);
	if (bucketIndex < 0 || bucketIndex >= bucketSize)
	{
		std::cout << "해쉬 테이블 주소 오류." << std::endl;
		return;
	}
	int tempIndex = bucketIndex;
	int inc = 1;
	do
	{
		if (isEmptyOrDeletedBucket(&(pElement[tempIndex])) == true)
		{
			pElement[tempIndex] = element;
			pElement[tempIndex].status = USED;
			currentElementCount++;
			break;
		}
		else
		{
			if (strcmp(pElement[tempIndex].key, element.key) == 0)
			{
				std::cout << "중복된 키." << std::endl;
				break;
			}
			else
			{
				tempIndex = (tempIndex + inc) % bucketSize;
				if (tempIndex == bucketIndex)
				{
					std::cout << "해쉬 테이블이 가득 참." << std::endl;
					break;
				}
			}
		}
	} while (tempIndex != bucketIndex);
}

void HashTable::deleteElement(char* pKey)
{
	HashElement* pHashElement = search(pKey);
	if (pHashElement)
	{
		pHashElement->status = DELETED;
		pHashElement->key[0] = '\0';
		pHashElement->value = 0;
		currentElementCount--;
		return;
	}
	else
	{
		std::cout << "존재하지 않는 키." << std::endl;
	}
	return;
}

void HashTable::deleteHashTable()
{
	delete[]pElement;
}

int HashTable::hashFunction(char* pKey, int bucketSize)
{
	int index = -1;
	if (pKey == NULL)
		return index;
	unsigned int tempKey = stringToInt(pKey);
	if (bucketSize > 0)
		index = tempKey % bucketSize;

	return index;
}

bool HashTable::isEmptyOrDeletedBucket(HashElement* pElement)
{
	if (pElement->status == EMPTY || pElement->status == DELETED)
		return true;
	return false;
}

HashElement* HashTable::search(char* pKey)
{
	int bucketIndex = hashFunction(pKey, bucketSize);
	if (bucketIndex < 0 || bucketIndex >= bucketSize)
	{
		std::cout << "해쉬 테이블 주소 오류." << std::endl;
		return nullptr;
	}
	int tempIndex = bucketIndex;
	int inc = 1;
	do
	{
		if (isEmptyOrDeletedBucket(&(pElement[tempIndex])) == true)
		{
			std::cout << "존재하지 않는 키." << std::endl;
			return nullptr;
			break;
		}
		else
		{
			if (pElement[tempIndex].status == USED && strcmp(pElement[tempIndex].key, pKey) == 0)
			{
				return &pElement[tempIndex];
				break;
			}
			else
			{
				tempIndex = (tempIndex + inc) % bucketSize;
				if (tempIndex == bucketIndex)
				{
					std::cout << "존재하지 않는 키." << std::endl;
					return nullptr;
					break;
				}
			}
		}
	} while (tempIndex != bucketIndex);
	return nullptr;
}

int HashTable::getElementCount()
{
	return currentElementCount;
}

void HashTable::displayHashTable()
{
	for (int i = 0; i < bucketSize; i++)
		std::cout << i << ": " << pElement[i].key <<", "<<pElement[i].value << std::endl;
}

unsigned int stringToInt(char* pKey)
{
	unsigned int ret = 0;
	while (*pKey != '\0')
	{
		ret = (ret * 31) + (*pKey);
		pKey = pKey + 1;
	}
	return ret;
}
