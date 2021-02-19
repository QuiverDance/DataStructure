#pragma once

#define HASH_KEY_SIZE 30

typedef struct HashElementType
{
	char key[HASH_KEY_SIZE + 1];
	int value;
}HashElement;

typedef struct ListNodeType
{
	HashElement data;
	struct ListNodeType* pLink;
} ListNode;

class HashingLinkedList {

public:
	HashingLinkedList();
	void addElement(int positon, ListNode element);
	void removeElement(int position);
	ListNode* getElement(int positon);
	ListNode getHeaderNode();
	void clearList();
	int getListLength();
	void deleteList();
	void displayList();

	~HashingLinkedList();
private:
	int currentElementCount;
	ListNode headerNode;
};
