#pragma once

typedef struct DequeNodeType {
	char data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

class LinkedDeque {
public:
	LinkedDeque();
	~LinkedDeque();
	void insertFront(DequeNode element);
	void insertRear(DequeNode element);
	DequeNode* deleteFront();
	DequeNode* deleteRear();
	DequeNode* peekFront();
	DequeNode* peekRear();
	void deleteDeque();
	bool isEmpty();
	void displayDeque();
private:
	int currentElementCount;
	DequeNode* pFrontNode;
	DequeNode* pRearNode;
};