#pragma once
#include "GraphLinkedList.h"
#include "GraphLinkedStack.h"
#include "GraphLinkedQueue.h"

enum GraphType
{
	undirected, directed
};

class LinkedGraph
{
public:
	LinkedGraph(int maxVertexCount, GraphType type);
	~LinkedGraph();
	void deleteGraph();
	bool isEmpty();
	void addVertex(int vertexID);
	void addEdge(int fromVertexID, int toVertexID);
	void addListElementForVertex(LinkedList* pList, int position, GraphVertex vertex);
	void addWeightedEdge(int fromVertexID, int toVertexID, int weight);
	bool checkVertexValid(int vertexID);
	void removeVertex(int vertexID);
	void removeEdge(int fromVertexID, int toVertexID);
	void deleteGraphNode(LinkedList* pList, int delVertexID);
	int findGraphNodePosition(LinkedList* pList, int vertexID);
	void displayGraph();

	void traversalDFS(int startVertexID);
	void pushForDFS(LinkedStack* pStack, int nodeID);
	void traversalBFS(int startVertexID);
	void enqueueForBFS(LinkedQueue* pQueue, int nodeID);
private:
	int maxVertexCount;
	int currentVertexCount;
	int currentEdgeCount;
	GraphType graphType;
	LinkedList** ppAdjcantEdge;
	int* pVertex;
};