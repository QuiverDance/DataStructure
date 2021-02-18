#pragma once

#define HASH_KEY_SIZE 30

typedef enum HashElementStatusType
{ EMPTY, USED, DELETED} HashElementStatus;

typedef struct HashElementType
{
	char key[HASH_KEY_SIZE + 1];
	int value;
	HashElementStatus status;
}HashElement;

class HashTable
{
public:
	HashTable(int bucketSize);
	~HashTable();
	void addElement(HashElement element);
	void deleteElement(char* pKey);
	void deleteHashTable();
	int hashFunction(char* pKey, int bucketSize);
	bool isEmptyOrDeletedBucket(HashElement* pElement);
	HashElement* search(char* pKey);
	int getElementCount();
	void displayHashTable();
private:
	int bucketSize;
	int currentElementCount;
	HashElement* pElement;
};

unsigned int stringToInt(char* pKey);