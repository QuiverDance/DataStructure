#include "ShortestPath.h"
#include <iostream>

int* shortestPathDijkstra(LinkedGraph* pGraph, int startVertexID)
{
	if (pGraph == nullptr)
		return NULL;
	int* pShortestPath = nullptr;
	bool* pSelected = nullptr;
	int nodeCount = pGraph->getCurrentVertexCount();
	int maxNodeCount = pGraph->getMaxVertexCount();
	pShortestPath = new int[maxNodeCount];
	pSelected = new bool[maxNodeCount];

	if (!pShortestPath || !pSelected)
		return NULL;
	
	for (int i = 0; i < maxNodeCount; i++)
	{
		if (i == startVertexID)
		{
			pShortestPath[i] = 0;
		}
		else
		{
			if (pGraph->GetpVertex()[i] == 1)
			{
				pSelected[i] = true;
				pShortestPath[i] = getEdgeWeight(pGraph, startVertexID, i);
			}
			else
			{
				pSelected[i] = false;
				pShortestPath[i] = MAX_INT;
			}
		}
	}
	for (int i = 0; i < maxNodeCount; i++)
		std::cout << "(" << startVertexID << ", " << i << " ) -> " << pShortestPath[i] << std::endl;
	
	ListNode* pListNode = nullptr;
	LinkedList* pEdgeList = nullptr;
	int vertexID = 0, y_w = 0, y_v = 0;
	for (int i = 0; i < nodeCount - 1; i++)
	{
		std::cout << "[" << i + 1 << "]" << std::endl;
		vertexID = getMinDistance(pShortestPath, pSelected, maxNodeCount);
		pSelected[vertexID] = false;

		pEdgeList = pGraph->GetppEdge()[vertexID];
		pListNode = pEdgeList->getHeaderNode().pLink;
		while (pListNode != nullptr)
		{
			int toVertexID = pListNode->data.vertexID;
			int weight = pListNode->data.weight;

			y_v = pShortestPath[vertexID];
			y_w = pShortestPath[toVertexID];
			if (y_v + weight < y_w)
			{
				pShortestPath[toVertexID] = y_v + weight;
			}
			pListNode = pListNode->pLink;
		}

		for(int j = 0; j<maxNodeCount; j++)
			std::cout << "(" << startVertexID << ", " << j << " ) -> " << pShortestPath[j] << std::endl;
	}
	delete[]pSelected;
	return pShortestPath;
}

int getMinDistance(int* distance, bool* isSelected, int maxNodeCount)
{
	int minDistance = MAX_INT;
	int minVertexID = 0;

	for (int i = 0; i < maxNodeCount; i++)
	{
		if (isSelected[i])
		{
			if (distance[i] < minDistance)
			{
				minDistance = distance[i];
				minVertexID = i;
			}
		}
	}

	return minVertexID;
}

int getEdgeWeight(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode* pListNode = nullptr;
	LinkedList* pEdgeList = nullptr;
	pEdgeList = pGraph->GetppEdge()[fromVertexID];
	
	int position = pGraph->findGraphNodePosition(pEdgeList, toVertexID);
	if (position >= 0)
	{
		pListNode = pEdgeList->getElement(position);
		return pListNode->data.weight;
	}
	return MAX_INT;
}
