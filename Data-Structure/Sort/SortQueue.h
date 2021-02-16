#pragma once

typedef struct QueueNodeType {
	int data;
	struct QueueNodeType* pLink;
} QueueNode;

class SortQueue {
public:
	SortQueue();
	~SortQueue();
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