#pragma once
#include "LinkedGraph.h"
#include "GraphLinkedList.h"
#include "GraphLinkedStack.h"
#include "GraphArrayHeap.h"

LinkedGraph* mstKruskal(LinkedGraph* pGraph); // Kruskal �˰���
ArrayMinHeap* orderEdges(LinkedGraph* pGraph);
bool checkCycle(LinkedGraph* pGraph, int formVertexID, int toVertexID);
void pushForDFS(LinkedStack* pStack, int nodeID);

