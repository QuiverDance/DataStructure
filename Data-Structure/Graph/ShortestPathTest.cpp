#include "ShortestPath.h"
#include <iostream>

int main(void)
{
	LinkedGraph* graph = new LinkedGraph(6, undirected);
	int* pShortestPath = nullptr;
	if (!graph)
		return 0;

	for (int i = 0; i < 6; i++)
		graph->addVertex(i);

	graph->addWeightedEdge(0, 1, 1);
	graph->addWeightedEdge(0, 2, 4);
	graph->addWeightedEdge(1, 2, 2);
	graph->addWeightedEdge(2, 3, 1);
	graph->addWeightedEdge(3, 4, 8);
	graph->addWeightedEdge(3, 5, 3);
	graph->addWeightedEdge(4, 5, 4);

	graph->displayGraph();

	pShortestPath = shortestPathDijkstra(graph, 0);

	delete graph;
}