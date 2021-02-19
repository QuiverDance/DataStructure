#pragma once
#include "HashingLinkedList.h"

class ChainingHashTable
{
public:
	ChainingHashTable(int bucketSize);
	~ChainingHashTable();
	void addElement(HashElement element);
	void deleteElement(char* key);
	void deleteHashTable();
	int hashFunction(char* key);
	HashElement* search(char* key);
	HashingLinkedList* searchBucket(char* key);
	HashElement* searchSlot(HashingLinkedList* pList, char* key, int* pPosition);
	int getElementCount();
	void displayHashTable();
private:
	int bucketSize;
	int currentElementCount;
	HashingLinkedList** ppElement;
};

unsigned int stringToInt(char* key);