#include "LinkedGraph.h"
#include <iostream>

LinkedGraph::LinkedGraph(int maxVertexCount, GraphType type)
{
	this->maxVertexCount = maxVertexCount;
	currentVertexCount = 0;
	currentEdgeCount = 0;
	graphType = type;
	pVertex = new int[maxVertexCount];
	for (int i = 0; i < maxVertexCount; i++)
		pVertex[i] = 0;
	ppAdjcantEdge = new LinkedList * [maxVertexCount];
	for (int i = 0; i < maxVertexCount; i++)
		ppAdjcantEdge[i] = new LinkedList();
}

LinkedGraph::~LinkedGraph()
{
	deleteGraph();
}

void LinkedGraph::deleteGraph()
{
	delete pVertex;
	delete ppAdjcantEdge;
}

bool LinkedGraph::isEmpty()
{
	if (currentVertexCount == 0)
		return true;
	return false;
}

void LinkedGraph::addVertex(int vertexID)
{
	if (vertexID < maxVertexCount)
	{
		if (pVertex[vertexID] == 0)
		{
			pVertex[vertexID] = 1;
			currentVertexCount++;
			
			return;
		}
	}
	std::cout << "노드 추가 에러." << std::endl;
}

void LinkedGraph::addEdge(int fromVertexID, int toVertexID)
{
	addWeightedEdge(fromVertexID, toVertexID, 1);
}

void LinkedGraph::addListElementForVertex(LinkedList* pList, int position, GraphVertex vertex)
{
	ListNode node{ 0, };
	node.data = vertex;
	pList->addElement(position, node);
}

void LinkedGraph::addWeightedEdge(int fromVertexID, int toVertexID, int weight)
{
	if (checkVertexValid(fromVertexID) && checkVertexValid(toVertexID))
	{
		GraphVertex toNode = { 0, };
		toNode.vertexID = toVertexID;
		toNode.weight = weight;
		addListElementForVertex(ppAdjcantEdge[fromVertexID], 0, toNode);
		currentEdgeCount++;

		if (graphType == undirected)
		{
			GraphVertex fromNode = { 0, };
			fromNode.vertexID = fromVertexID;
			fromNode.weight = weight;
			addListElementForVertex(ppAdjcantEdge[toVertexID], 0, fromNode);
			currentEdgeCount++;
		}
	}
}

bool LinkedGraph::checkVertexValid(int vertexID)
{
	if (vertexID >= maxVertexCount || pVertex[vertexID] == 0)
		return false;
	return true;
}

void LinkedGraph::removeVertex(int vertexID)
{
	if (checkVertexValid(vertexID))
	{
		for (int i = 0; i < maxVertexCount; i++)
		{
			removeEdge(vertexID, i);
			removeEdge(i, vertexID);
		}
		pVertex[vertexID] = 0;
		currentVertexCount--;
	}
}

void LinkedGraph::removeEdge(int fromVertexID, int toVertexID)
{
	if (checkVertexValid(fromVertexID) && checkVertexValid(toVertexID))
	{
		deleteGraphNode(ppAdjcantEdge[fromVertexID], toVertexID);
		if (graphType == undirected)
			deleteGraphNode(ppAdjcantEdge[toVertexID], fromVertexID);
	}
}

void LinkedGraph::deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int position = findGraphNodePosition(pList, delVertexID);
	pList->removeElement(position);
	currentEdgeCount--;
}

int LinkedGraph::findGraphNodePosition(LinkedList* pList, int vertexID)
{
	int position = 0;
	ListNode* curNode = pList->getHeaderNode().pLink;
	while (curNode != nullptr)
	{
		if (curNode->data.vertexID == vertexID)
			return position;
		curNode = curNode->pLink;
		position++;
	}
	return -1;
}

void LinkedGraph::displayGraph()
{
	std::cout << "Graph Type: " << graphType << std::endl;
	for (int i = 0; i < maxVertexCount; i++)
	{
		std::cout << "[" << i << "]";
		ppAdjcantEdge[i]->displayList();
	}
	std::cout << std::endl;
}

void LinkedGraph::traversalDFS(int startVertexID)
{
	LinkedStack* pStack = new LinkedStack();
	bool* pVisited = new bool[maxVertexCount];

	for (int i = 0; i < maxVertexCount; i++)
		pVisited[i] = false;
	pVisited[startVertexID] = true;
	pushForDFS(pStack, startVertexID);

	StackNode* pStackNode = nullptr;
	ListNode* pListNode = nullptr;
	int curVertexID = 0;
	while (!pStack->isEmpty())
	{
		pStackNode = pStack->pop();
		if (pStackNode)
		{
			curVertexID = pStackNode->data;
			std::cout << "[" << curVertexID << "] " << "방문" << std::endl;

			pListNode = ppAdjcantEdge[curVertexID]->getHeaderNode().pLink;
			while (pListNode != nullptr)
			{
				int vertexID = pListNode->data.vertexID;
				if (pVisited[vertexID] == false)
				{
					pVisited[vertexID] = true;
					pushForDFS(pStack, vertexID);
				}
				pListNode = pListNode->pLink;
			}
		}
	}
	delete []pVisited;
	delete pStack;
}

void LinkedGraph::pushForDFS(LinkedStack* pStack, int nodeID)
{
	StackNode node = { 0, };
	node.data = nodeID;
	pStack->push(node);
}

void LinkedGraph::traversalBFS(int startVertexID)
{
}
