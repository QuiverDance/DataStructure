#include "LinkedListStack.h"
#include <iostream>

int main(void)
{
	LinkedListStack arrStack = LinkedListStack();
	StackNode node;
	for (int i = 0; i < 5; i++)
	{
		node.data = 'a' + i;
		arrStack.push(node);
	}
	arrStack.displayStack();

	std::cout << "pop data: " << arrStack.pop()->data << std::endl;
	arrStack.displayStack();

	std::cout << "peek data: " << arrStack.peek()->data << std::endl;
	arrStack.displayStack();

	arrStack.deleteStack();
	arrStack.displayStack();
}