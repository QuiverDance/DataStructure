#pragma once

typedef struct ListNodeType {
	int data;
	struct ListNodeType* pRLink;
	struct ListNodeType* pLLink;
}ListNode;

class DoublyLinkedList {
public:
	DoublyLinkedList();
	void addElement(int positon, ListNode element);
	void removeElement(int position);
	ListNode* getElement(int positon);
	void clearList();
	int getListLength();
	void deleteList();
	void displayList();
	
	~DoublyLinkedList();
private:
	int currentElementCount;
	ListNode headerNode;
};
