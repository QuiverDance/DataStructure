#include "LinkedListDeque.h"
#include <iostream>

int main(void)
{
	LinkedDeque* deque = new LinkedDeque();
	DequeNode node = {'a', nullptr, nullptr};

	for (int i = 0; i < 3; i++)
	{
		node.data = 'a' + i;
		deque->insertFront(node);
	}
	for (int i = 3; i < 6; i++)
	{
		node.data = 'a' + i;
		deque->insertRear(node);
	}
	deque->displayDeque();

	DequeNode* pFrontNode = deque->deleteFront();
	DequeNode* pRearNode = deque->deleteRear();
	std::cout << "Del Front : " << pFrontNode->data << std::endl;
	std::cout << "Del Rear : " << pRearNode->data << std::endl;

	std::cout << "Peek Front : " << deque->peekFront()->data << std::endl;
	std::cout << "Peek Rear : " << deque->peekRear()->data << std::endl;
	deque->displayDeque();
}