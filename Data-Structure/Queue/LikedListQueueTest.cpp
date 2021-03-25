#include "LinkedListQueue.h"
#include <iostream>

int main(void)
{
	LinkedQueue* queue = new LinkedQueue();
	QueueNode node;
	node.data = 'a';

	for (int i = 0; i < 7; i++)
	{
		node.data = 'a' + i;
		queue->enqueue(node);
	}
	queue->displayQueue();
	
	QueueNode* pDequeueNode = queue->dequeue();
	std::cout << "Dequeue: " << pDequeueNode->data << std::endl;
	delete pDequeueNode;
	std::cout << "peek: " << queue->peek()->data << std::endl;

	queue->displayQueue();
	delete queue;
}
