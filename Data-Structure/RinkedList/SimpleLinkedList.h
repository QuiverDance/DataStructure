#pragma once

typedef struct ListNodeType {
	int data;
	struct ListNodeType* pLink;
}ListNode;

class SimpleLinkedList {

public:
	SimpleLinkedList();
	void addElement(int positon, ListNode element);
	void removeElement(int position);
	ListNode* getElement(int positon);
	void clearList();
	int getListLength();
	void deleteList();
	void displayList();
private:
	int currentElementCount;
	ListNode headerNode;
};