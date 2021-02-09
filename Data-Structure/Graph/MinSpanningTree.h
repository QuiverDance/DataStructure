#pragma once
#include "LinkedGraph.h"
#include "GraphLinkedList.h"
#include "GraphLinkedStack.h"
#include "GraphArrayHeap.h"

#define MAX_Weight 9999

LinkedGraph* mstKruskal(LinkedGraph* pGraph); // Kruskal 알고리즘
ArrayMinHeap* orderEdges(LinkedGraph* pGraph);
bool checkCycle(LinkedGraph* pGraph, int formVertexID, int toVertexID);
void pushForDFS(LinkedStack* pStack, int nodeID);


typedef struct GraphEdgeType
{
	int vertexIDFrom;
	int vertexIDTo;
	int weight;
} GraphEdge;

LinkedGraph* mstPrim(LinkedGraph* pGraph, int startVertexID);
void getMinWeightEdge(LinkedGraph* pGraph, LinkedGraph* pMST, int mstVertexID, GraphEdge* pMinWeightEdge);
bool checkEdge(LinkedGraph* pGraph, int fromVertexID, int toVertexID);