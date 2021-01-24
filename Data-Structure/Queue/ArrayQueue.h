#pragma once

typedef struct ArrayQueueNodeType {
	char element;
} ArrayQueueNode;

class ArrayQueue {
public:
	ArrayQueue(int maxElementCount);
	~ArrayQueue();
	void enqueue(ArrayQueueNode element);
	ArrayQueueNode* dequeue();
	ArrayQueueNode* peek();
	void deleteQueue();
	bool isFull();
	bool isEmpty();
	void displayQueue();
private:
	int maxElementCount;
	int currentElementCount;
	int front;
	int rear;
	ArrayQueueNode* pElement;
};