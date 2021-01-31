#pragma once

typedef struct HeapElementType {
	int key;
	char data;
} HeapNode;

class ArrayMaxHeap {
public:
	ArrayMaxHeap(int maxElementCount);
	~ArrayMaxHeap();
	void deleteHeap();
	void intsetHeap(HeapNode element);
	HeapNode* deleteElement();
	void displayHeap();
private:
	int maxElementCount;
	int currentElementCount;
	HeapNode* pElement;
};