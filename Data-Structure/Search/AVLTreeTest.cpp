#include "AVLTree.h"
#include <iostream>

int main()
{
    AVLTree* pTree = nullptr;

    AVLTreeNodeData eB = { 9, "9" };
    AVLTreeNodeData eG = { 3, "3" };
    AVLTreeNodeData eE = { 1, "1" };
    AVLTreeNodeData eC = { 10, "10" };
    AVLTreeNodeData eL = { 12, "12" };
    AVLTreeNodeData eH = { 6, "6" };
    AVLTreeNodeData eI = { 4, "4" };
    AVLTreeNodeData eF = { 5, "5" };

    pTree = new AVLTree();
    if (!pTree)
        return 0;

    pTree->insertNodeAVL(eB);
    pTree->insertNodeAVL(eG);
    pTree->insertNodeAVL(eE);
    pTree->insertNodeAVL(eC);
    pTree->insertNodeAVL(eL);
    pTree->insertNodeAVL(eH);
    pTree->insertNodeAVL(eI);
    pTree->insertNodeAVL(eF);

    pTree->deleteNode(5);
    pTree->displayAVLTree();

    pTree->deleteTree();
    delete pTree;
    return 0;
}