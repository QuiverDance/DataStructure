#pragma once
#include "LinkedGraph.h"
#include "GraphLinkedList.h"
#include "GraphLinkedStack.h"
#include "GraphArrayHeap.h"

LinkedGraph* mstKruskal(LinkedGraph* pGraph); // Kruskal 알고리즘
ArrayMinHeap* orderEdges(LinkedGraph* pGraph);
bool checkCycle(LinkedGraph* pGraph, int formVertexID, int toVertexID);
void pushForDFS(LinkedStack* pStack, int nodeID);

