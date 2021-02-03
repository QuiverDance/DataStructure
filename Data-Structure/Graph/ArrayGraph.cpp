#include "ArrayGraph.h"
#include <iostream>

ArrayGraph::ArrayGraph(int maxVertexCount, GraphType type)
{
	if (maxVertexCount > 0)
	{
		this->maxVertexCount = maxVertexCount;
		this->graphType = type;
		this->currentVertexCount = 0;

		pVertex = new int[maxVertexCount];
		for (int i = 0; i < maxVertexCount; i++)
			pVertex[i] = 0;
		
		ppAdjacentEdge = new int* [maxVertexCount];
		for (int i = 0; i < maxVertexCount; i++)
		{
			ppAdjacentEdge[i] = new int[maxVertexCount];
			for (int j = 0; j < maxVertexCount; j++)
				ppAdjacentEdge[i][j] = 0;
		}
	}
}

ArrayGraph::~ArrayGraph()
{
	deleteGraph();
}

void ArrayGraph::deleteGraph()
{
	delete pVertex;
	delete ppAdjacentEdge;
}

bool ArrayGraph::isEmpty()
{
	if (currentVertexCount == 0)
		return true;
	return false;
}

void ArrayGraph::addVertex(int vertexID)
{
	if (vertexID < maxVertexCount)
	{
		if (pVertex[vertexID] == 0)
		{
			pVertex[vertexID] = 1;
			currentVertexCount++;
			return;
		}
		else
		{
			std::cout << "이미 존재하는 코드." << std::endl;
			return;
		}
	}
	std::cout << "최대 노드 개수 초과." << std::endl;
}

void ArrayGraph::addEdge(int fromVerTexID, int toVertexID)
{
	addWeightedEdge(fromVerTexID, toVertexID, 1);
}

void ArrayGraph::addWeightedEdge(int fromVerTexID, int toVertexID, int weight)
{
	if (checkVertexValid(fromVerTexID) && checkVertexValid(toVertexID))
	{
		ppAdjacentEdge[fromVerTexID][toVertexID] = weight;
		if (graphType == undirected)
			ppAdjacentEdge[toVertexID][fromVerTexID] = weight;
	}
}

bool ArrayGraph::checkVertexValid(int vertexID)
{
	if (vertexID >= maxVertexCount || pVertex[vertexID] == 0)
		return false;
	return true;
}

void ArrayGraph::removeVertex(int vertexID)
{
	if (checkVertexValid(vertexID))
	{
		for (int i = 0; i < maxVertexCount; i++)
		{
			removeEdge(vertexID, i);
			removeEdge(i, vertexID);
		}
		pVertex[vertexID] = 0;
	}
}

void ArrayGraph::removeEdge(int fromVertexID, int toVerTexID)
{
	if (checkVertexValid(fromVertexID) && checkVertexValid(toVerTexID))
	{
		ppAdjacentEdge[fromVertexID][toVerTexID] = 0;
		if (graphType == undirected)
			ppAdjacentEdge[toVerTexID][fromVertexID] = 0;
	}
}

void ArrayGraph::displayGraph()
{
	std::cout << "Graph Type: " << graphType << std::endl;
	for (int i = 0; i < maxVertexCount; i++)
	{
		for (int j = 0; j < maxVertexCount; j++)
			std::cout << ppAdjacentEdge[i][j] << " ";
		std::cout << std::endl;
	}
}
