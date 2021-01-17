#include "DoublyLinkedList.h"
#include <iostream>

int main(void)
{
	DoublyLinkedList simpleLinkedList = DoublyLinkedList();
	ListNode node;
	node.data = 0;
	node.pRLink = nullptr;

	for (int i = 0; i < 5; i++)
	{
		simpleLinkedList.addElement(i, node);
		node.data++;
	}

	simpleLinkedList.removeElement(0);
	node.data = 10;
	simpleLinkedList.addElement(4, node);
	simpleLinkedList.displayList();

	std::cout << simpleLinkedList.getElement(3)->data << std::endl;
	std::cout << "Length: " << simpleLinkedList.getListLength() << std::endl;
}