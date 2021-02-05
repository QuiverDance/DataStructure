#include "LinkedGraph.h"
#include <iostream>

int main(void)
{
	LinkedGraph* graph1 = new LinkedGraph(8, undirected);
	for (int i = 0; i < 8; i++)
		graph1->addVertex(i);

	graph1->addEdge(0, 1);
	graph1->addEdge(0, 2);
	graph1->addEdge(1, 3);
	graph1->addEdge(1, 4);
	graph1->addEdge(2, 5);
	graph1->addEdge(2, 6);
	graph1->addEdge(3, 7);
	graph1->addEdge(4, 5);
	
	graph1->displayGraph();

	std::cout << "DFS Traversal: " << std::endl;
	graph1->traversalDFS(0);
	delete graph1;

}