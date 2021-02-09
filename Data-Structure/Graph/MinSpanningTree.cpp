#include "MinSpanningTree.h"
#include <iostream>

LinkedGraph* mstKruskal(LinkedGraph* pGraph)
{
	if (pGraph == nullptr)
		return nullptr;
	LinkedGraph* pMinSpanningTree = nullptr;
	int maxNodeCount = pGraph->getMaxVertexCount();
	int currentNodeCount = pGraph->getCurrentVertexCount();
	int currentEdgeCount = pGraph->getCurrentEdgeCount();

	pMinSpanningTree = new LinkedGraph(maxNodeCount, undirected);
	if (pMinSpanningTree == nullptr)
		return nullptr;

	ArrayMinHeap* pMinHeap = nullptr;
	pMinHeap = orderEdges(pGraph);
	if (pMinHeap == nullptr)
		return nullptr;

	HeapNode* pHeapNode = nullptr;
	bool isCycle = true;

	for (int i = 0; i < currentEdgeCount; i++)
	{
		pHeapNode = pMinHeap->deleteElement();
		if (pHeapNode)
		{
			isCycle = checkCycle(pMinSpanningTree, pHeapNode->fromVertexID, pHeapNode->toVertexID);

			if (isCycle == false)
			{
				pMinSpanningTree->addVertex(pHeapNode->fromVertexID);
				pMinSpanningTree->addVertex(pHeapNode->toVertexID);

				pMinSpanningTree->addWeightedEdge(pHeapNode->fromVertexID, pHeapNode->toVertexID, pHeapNode->key);
				std::cout << i << ": " << "[" << pHeapNode->fromVertexID << ", " << pHeapNode->toVertexID << "], " << pHeapNode->key << std::endl;
			}
			delete pHeapNode;

			if (pMinSpanningTree->getCurrentVertexCount() == currentNodeCount)
				break;
		}
	}
	return pMinSpanningTree;
}

ArrayMinHeap* orderEdges(LinkedGraph* pGraph)
{
	if (pGraph == nullptr)
		return nullptr;

	int edgeCount = pGraph->getCurrentEdgeCount();
	ArrayMinHeap* pOrderEdge = nullptr;
	pOrderEdge = new ArrayMinHeap(edgeCount);
	if (pOrderEdge == nullptr)
		return nullptr;

	int maxVertexCount = pGraph->getMaxVertexCount();
	ListNode* pListNode = nullptr;
	LinkedList* pEdgeList = nullptr;
	for (int i = 0; i < maxVertexCount; i++)
	{
		if (pGraph->checkVertexValid(i))
		{
			pEdgeList = pGraph->GetppEdge()[i];
			pListNode = pEdgeList->getHeaderNode().pLink;
			while (pListNode != nullptr)
			{
				int vertexID = pListNode->data.vertexID;
				int weight = pListNode->data.weight;
				if (pGraph->getGraphType() == directed || (pGraph->getGraphType() == undirected && i < vertexID))
				{
					HeapNode heapNode = { 0, };
					heapNode.fromVertexID = i;
					heapNode.toVertexID = vertexID;
					heapNode.key = weight;
					pOrderEdge->insertHeap(heapNode);
				}
				pListNode = pListNode->pLink;
			}
		}
	}
	return pOrderEdge;
}

bool checkCycle(LinkedGraph* pGraph, int formVertexID, int toVertexID)
{
	if (pGraph == nullptr)
		return NULL;

	LinkedStack* pStack = new LinkedStack();
	if (pStack == nullptr)
		return NULL;

	int maxVertexCount = pGraph->getMaxVertexCount();
	bool* pVisited = new bool[maxVertexCount];
	if (pVisited == nullptr)
	{
		pStack->deleteStack();
		return NULL;
	}

	for (int i = 0; i < maxVertexCount; i++)
		pVisited[i] = false;
	pVisited[formVertexID] = true;
	pushForDFS(pStack, formVertexID);

	StackNode* pStackNode = nullptr;
	ListNode* pListNode = nullptr;
	int curVertexID = 0;
	while (!pStack->isEmpty())
	{
		pStackNode = pStack->pop();
		if (pStackNode)
		{
			curVertexID = pStackNode->data;
			if (curVertexID == toVertexID)
			{
				return true;
				break;
			}

			pListNode = pGraph->GetppEdge()[curVertexID]->getHeaderNode().pLink;
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
	delete[]pVisited;
	delete pStack;
	return false;
}

void pushForDFS(LinkedStack* pStack, int nodeID)
{
	StackNode node = { 0, };
	node.data = nodeID;
	pStack->push(node);
}

LinkedGraph* mstPrim(LinkedGraph* pGraph, int startVertexID)
{
	if (pGraph == nullptr)
		return nullptr;
	LinkedGraph* pMinSpanningTree = nullptr;
	int maxNodeCount = pGraph->getMaxVertexCount();
	int currentNodeCount = pGraph->getCurrentVertexCount();

	pMinSpanningTree = new LinkedGraph(maxNodeCount, undirected);
	if (pMinSpanningTree == nullptr)
		return nullptr;
	pMinSpanningTree->addVertex(startVertexID);
	
	GraphEdge minWeightEdge = { 0, };
	int fromVertexID = 0;
	int mstNodeCount = pMinSpanningTree->getCurrentVertexCount();
	while (mstNodeCount < currentNodeCount)
	{
		minWeightEdge = { 0, 0, MAX_Weight };
		for (int i = 0; i < maxNodeCount; i++)
		{
			if (pMinSpanningTree->GetpVertex()[i] == true)
			{
				fromVertexID = i;
				getMinWeightEdge(pGraph, pMinSpanningTree, fromVertexID, &minWeightEdge);
			}
		}
		std::cout << mstNodeCount << ": " << "[" << minWeightEdge.vertexIDFrom << ", " << minWeightEdge.vertexIDTo << "], " << minWeightEdge.weight << std::endl;
		pMinSpanningTree->addVertex(minWeightEdge.vertexIDTo);
		pMinSpanningTree->addWeightedEdge(minWeightEdge.vertexIDFrom, minWeightEdge.vertexIDTo, minWeightEdge.weight);

		mstNodeCount = pMinSpanningTree->getCurrentEdgeCount();
	}
	return pMinSpanningTree;
}

void getMinWeightEdge(LinkedGraph* pGraph, LinkedGraph* pMST, int fromVertexID, GraphEdge* pMinWeightEdge)
{
	ListNode* pListNode = nullptr;
	bool isCycle = NULL;
	bool isAlready = NULL;
	LinkedList* pEdgeList = pGraph->GetppEdge()[fromVertexID];

	pListNode = pEdgeList->getHeaderNode().pLink;
	while (pListNode != nullptr)
	{
		int vertexID = pListNode->data.vertexID;
		int weight = pListNode->data.weight;
		if (pListNode->data.weight < pMinWeightEdge->weight)
		{
			isAlready = checkEdge(pMST, fromVertexID, vertexID);
			if (isAlready == false)
			{
				isCycle = checkCycle(pMST, fromVertexID, vertexID);
			}
			if (isAlready == false && isCycle == false)
			{
				pMinWeightEdge->vertexIDFrom = fromVertexID;
				pMinWeightEdge->vertexIDTo = vertexID;
				pMinWeightEdge->weight = weight;
			}
		}
		pListNode = pListNode->pLink;
	}
}

bool checkEdge(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == nullptr)
		return NULL;
	LinkedList* pEdgeList = nullptr;
	int position = 0;
	
	pEdgeList = pGraph->GetppEdge()[fromVertexID];
	position = pGraph->findGraphNodePosition(pEdgeList, toVertexID);
	if (position >= 0)
		return true;
	return false;
}
