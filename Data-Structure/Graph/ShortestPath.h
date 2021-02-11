#pragma once
#include "LinkedGraph.h"
#include "GraphLinkedList.h"

#define MAX_INT 9999

int* shortestPathDijkstra(LinkedGraph* pGraph, int startVertexID);
int getMinDistance(int* distance, bool* isSelected, int maxNodeCount);
int getEdgeWeight(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

int** shortestPathFloyd(LinkedGraph* pGraph);
int** pathReachability(LinkedGraph* pGraph);
void printMatrix(int** A, int maxNodeCount);