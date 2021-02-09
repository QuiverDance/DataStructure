#pragma once

typedef struct HeapElementType {
	int key;
	int fromVertexID;
	int toVertexID;
} HeapNode;

class ArrayMinHeap {
public:
	ArrayMinHeap(int maxElementCount);
	~ArrayMinHeap();
	void deleteHeap();
	void insertHeap(HeapNode element);
	HeapNode* deleteElement();
	void displayHeap();
private:
	int maxElementCount;
	int currentElementCount;
	HeapNode* pElement;
};