#pragma once

typedef struct QueueNodeType {
	char data;
	struct QueueNodeType* pLink;
} QueueNode;

class LinkedQueue {
public:
	LinkedQueue();
	~LinkedQueue();
	void enqueue(QueueNode element);
	QueueNode* dequeue();
	QueueNode* peek();
	void deleteQueue();
	bool isEmpty();
	void displayQueue();
private:
	int currentElementCount;
	QueueNode* pFrontNode;
	QueueNode* pRearNode;
};