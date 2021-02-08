#include "GraphArrayHeap.h"
#include <iostream>

ArrayMinHeap::ArrayMinHeap(int maxElementCount)
{
	this->maxElementCount = maxElementCount;
	currentElementCount = 0;
	pElement = new HeapNode[maxElementCount + 1];
}

ArrayMinHeap::~ArrayMinHeap()
{
	deleteHeap();
}

void ArrayMinHeap::deleteHeap()
{
	delete pElement;
}

void ArrayMinHeap::intsetHeap(HeapNode element)
{
	if (currentElementCount == maxElementCount)
	{
		std::cout << "It is full." << std::endl;
		return;
	}
	currentElementCount++;
	int index = currentElementCount;
	while (index != 1 && element.key < pElement[index / 2].key)
	{
		pElement[index] = pElement[index / 2];
		index /= 2;
	}
	pElement[index] = element;
	std::cout << "원소 추가 성공." << std::endl;
}

HeapNode* ArrayMinHeap::deleteElement()
{
	if (currentElementCount > 0)
	{
		HeapNode* pDelNode = new HeapNode;
		if (pDelNode)
		{
			*pDelNode = pElement[1];
			HeapNode* pLastNode = &pElement[currentElementCount];
			currentElementCount--;

			int parent = 1;
			int child = 2;
			while (child <= currentElementCount)
			{
				if (child < currentElementCount && pElement[child].key > pElement[child + 1].key)
					child++;

				if (pLastNode->key <= pElement[child].key)
					break;

				pElement[parent] = pElement[child];
				parent = child;
				child *= 2;
			}
			pElement[parent] = *pLastNode;
			std::cout << "원소 제거 성공." << std::endl;
			return pDelNode;
		}
	}
	std::cout << "원소 제거 실패." << std::endl;
}

void ArrayMinHeap::displayHeap()
{
	for (int i = 1; i <= currentElementCount; i++)
	{
		std::cout << "[" << i << "] " << pElement[i].key << std::endl;
	}
}
