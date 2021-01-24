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

	std::cout << "Dequeue: " << queue.dequeue()->element << std::endl;
	std::cout << "Peek: " << queue.peek()->element << std::endl;

	queue.displayQueue();
}