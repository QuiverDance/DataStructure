#pragma once

typedef struct GraphVertexType
{
	int vertexID;
	int weight;
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType* pLink;
} ListNode;

class LinkedList {

public:
	LinkedList();
	void addElement(int positon, ListNode element);
	void removeElement(int position);
	ListNode* getElement(int positon);
	ListNode getHeaderNode();
	void clearList();
	int getListLength();
	void deleteList();
	void displayList();

	~LinkedList();
private:
	int currentElementCount;
	ListNode headerNode;
};
