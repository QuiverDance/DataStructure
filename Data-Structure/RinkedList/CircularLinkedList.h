#pragma once

typedef struct ListNodeType {
	int data;
	struct ListNodeType* pLink;
}ListNode;

class CircularLinkedList {
public:
	CircularLinkedList();
	void addElement(int positon, ListNode element);
	void removeElement(int position);
	ListNode* getElement(int positon);
	void clearList();
	int getListLength();
	void deleteList();
	void displayList();
	
	~CircularLinkedList();
private:
	int currentElementCount;
	ListNode headerNode;
}; 
