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

int** shortestPathFloyd(LinkedGraph* pGraph)
{
	if (pGraph == nullptr)
		return NULL;
	int** pShortestPath = nullptr;
	int maxCount = pGraph->getMaxVertexCount();
	pShortestPath = new int* [maxCount];
	if (!pShortestPath)
		return nullptr;

	for (int r = 0; r < maxCount; r++)
	{
		pShortestPath[r] = new int[maxCount];
		if (!pShortestPath[r])
			return nullptr;
	}

	for (int r = 0; r < maxCount; r++)
	{
		for (int s = 0; s < maxCount; s++)
		{
			if (r == s)
				pShortestPath[r][s] = 0;
			else
				pShortestPath[r][s] = getEdgeWeight(pGraph, r, s);
		}
	}
	printMatrix(pShortestPath, maxCount);

	for (int v = 0; v < maxCount; v++)
	{
		for (int r = 0; r < maxCount; r++)
		{
			for (int s = 0; s < maxCount; s++)
			{
				if (pShortestPath[r][v] + pShortestPath[v][s] < pShortestPath[r][s])
					pShortestPath[r][s] = pShortestPath[r][v] + pShortestPath[v][s];
			}
		}
		std::cout << "[" << v + 1 << "]" << std::endl;
		printMatrix(pShortestPath, maxCount);
	}
	return pShortestPath;
}

int** pathReachability(LinkedGraph* pGraph)
{
	if (pGraph == nullptr)
		return NULL;
	int** pShortestPath = nullptr;
	int maxCount = pGraph->getMaxVertexCount();
	pShortestPath = new int* [maxCount];
	if (!pShortestPath)
		return nullptr;

	for (int r = 0; r < maxCount; r++)
	{
		pShortestPath[r] = new int[maxCount];
		if (!pShortestPath[r])
			return nullptr;
	}

	for (int r = 0; r < maxCount; r++)
	{
		for (int s = 0; s < maxCount; s++)
		{
			if (getEdgeWeight(pGraph, r, s) < MAX_INT)
				pShortestPath[r][s] = 1;
			else
			pShortestPath[r][s] = 0;
		}
	}

	for (int v = 0; v < maxCount; v++)
	{
		for (int r = 0; r < maxCount; r++)
		{
			if (pShortestPath[r][v] > 0)
			{
				for (int s = 0; s < maxCount; s++)
				{
					if (pShortestPath[v][s] > 0)
						pShortestPath[r][s] = 1;
				}
			}
		}
	}
	printMatrix(pShortestPath, maxCount);
	return pShortestPath;
}

void printMatrix(int** A, int maxNodeCount)
{
	if (A == nullptr)
		return;

	for (int i = 0; i < maxNodeCount; i++)
	{
		for (int j = 0; j < maxNodeCount; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
