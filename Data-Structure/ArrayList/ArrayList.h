#pragma once

typedef struct ArrayListNodeType {
	int data;
} ArrayListNode; 

class ArrayList {
public:
	ArrayList(int maxElementCount);
	void deleteList();
	bool isFull();
	void addElement(int positon, ArrayListNode element);
	void removeElement(int positon);
	void clearList();
	void displayList();
	int getListLength();
	ArrayListNode getElement(int positon);

private:
	int maxElementCount;
	int currentElementCount;
	ArrayListNode* pElement;
};