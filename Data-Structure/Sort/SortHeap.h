#pragma once

typedef struct HeapElementType {
	int key;
	char data;
} HeapNode;

class ArrayHeap {
public:
	ArrayHeap(int maxElementCount);
	~ArrayHeap();
	void deleteHeap();
	void intsetMaxHeap(HeapNode element);
	HeapNode* deleteMaxElement();
	void intsetMinHeap(HeapNode element);
	HeapNode* deleteMinElement();
	void displayHeap();
private:
	int maxElementCount;
	int currentElementCount;
	HeapNode* pElement;
};