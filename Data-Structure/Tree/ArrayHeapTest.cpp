#include "ArrayHeap.h"
#include <iostream>

int main(void)
{
	ArrayMaxHeap* maxHeap = new ArrayMaxHeap(10);
	HeapNode node1 = { 1 };
	HeapNode node2 = { 4 };
	HeapNode node3 = { 3 };
	HeapNode node4 = { 7 };
	HeapNode node5 = { 9 };
	HeapNode node6 = { 8 };
	
	maxHeap->intsetHeap(node1);
	maxHeap->intsetHeap(node2);
	maxHeap->intsetHeap(node3);
	maxHeap->intsetHeap(node4);
	maxHeap->intsetHeap(node5);
	maxHeap->intsetHeap(node6);

	maxHeap->displayHeap();

	HeapNode* node;
	for (int i = 0; i < 6; i++)
	{
		node = maxHeap->deleteElement();
		std::cout << node->key << std::endl;
		delete node;
	}
	delete maxHeap;
}