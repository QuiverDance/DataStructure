#include "MinSpanningTree.h"
#include <iostream>

int main(void)
{
    LinkedGraph* pG1 = nullptr;
    LinkedGraph* pMST1 = nullptr;
    LinkedGraph* pMST2 = nullptr;

    pG1 = new LinkedGraph(6, undirected);
    if (pG1 != nullptr) {

        for (int i = 0; i < 6; i++) {
            pG1->addVertex(i);
        }

        pG1->addWeightedEdge(0, 1, 4);
        pG1->addWeightedEdge(0, 2, 3);
        pG1->addWeightedEdge(1, 2, 2);
        pG1->addWeightedEdge(2, 3, 1);
        pG1->addWeightedEdge(3, 4, 1);
        pG1->addWeightedEdge(3, 5, 5);
        pG1->addWeightedEdge(4, 5, 6);
        
        pG1->displayGraph();

        std::cout << std::endl << "Kruskal MST: " << std::endl;
        pMST1 = mstKruskal(pG1);
        pMST1->displayGraph();
        
        std::cout << std::endl << "Prim MST: " << std::endl;
        pMST2 = mstPrim(pG1, 1);
        pMST2->displayGraph();

        delete pG1;
        delete pMST1;
        delete pMST2;
    }
}
