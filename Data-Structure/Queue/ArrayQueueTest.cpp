#include "ArrayQueue.h"
#include <iostream>

int main(void)
{
	ArrayQueue queue = ArrayQueue(10);
	ArrayQueueNode node;
	node.element = NULL;
	
	for (int i = 0; i < 5; i++)
	{
		node.element = 'a' + i;
		queue.enqueue(node);
	}
	queue.displayQueue();

	ArrayQueueNode* pDelNode;
	pDelNode = queue.dequeue();
	std::cout << "Dequeue: " << pDelNode->element << std::endl;
	std::cout << "Peek: " << queue.peek()->element << std::endl;
	
	delete pDelNode;
	queue.displayQueue();

	for (int i = 5; i < 11; i++)
	{
		node.element = 'a' + i;
		queue.enqueue(node);
	}
	queue.displayQueue();
	for (int i = 0; i < 5; i++)
	{
		pDelNode = queue.dequeue();
		delete pDelNode;
	}
	queue.displayQueue();
	for (int i = 11; i < 16; i++)
	{
		node.element = 'a' + i;
		queue.enqueue(node);
	}
	queue.displayQueue();
} 