#include "LinkedGraph.h"

int main(void)
{
	LinkedGraph* graph1 = new LinkedGraph(6, undirected);
	LinkedGraph* graph2 = new LinkedGraph(6, directed);
	LinkedGraph* graph3 = new LinkedGraph(6, directed);

	for (int i = 0; i < 6; i++)
	{
		graph1->addVertex(i);
		graph2->addVertex(i);
		graph3->addVertex(i);
	}
	graph1->addEdge(0, 1);
	graph1->addEdge(0, 2);
	graph1->addEdge(1, 2);
	graph1->addEdge(2, 3);
	graph1->addEdge(3, 4);
	graph1->addEdge(3, 5);
	graph1->addEdge(4, 5);

	graph2->addEdge(0, 1);
	graph2->addEdge(1, 2);
	graph2->addEdge(2, 0);
	graph2->addEdge(2, 1);
	graph2->addEdge(2, 3);
	graph2->addEdge(3, 2);
	graph2->addEdge(3, 4);
	graph2->addEdge(4, 5);
	graph2->addEdge(5, 3);

	graph3->addWeightedEdge(0, 1, 4);
	graph3->addWeightedEdge(1, 2, 1);
	graph3->addWeightedEdge(2, 0, 2);
	graph3->addWeightedEdge(2, 1, 3);
	graph3->addWeightedEdge(2, 3, 2);
	graph3->addWeightedEdge(3, 2, 1);
	graph3->addWeightedEdge(3, 4, 1);
	graph3->addWeightedEdge(4, 5, 1);
	graph3->addWeightedEdge(5, 3, 2);

	graph1->displayGraph();
	graph2->displayGraph();
	graph3->displayGraph();

	graph1->removeVertex(2);
	graph1->removeEdge(3, 5);
	graph1->displayGraph();
	delete graph1;
	delete graph2;
	delete graph3;

}