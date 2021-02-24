#include "BTree.h"
#include <iostream>

int main(void)
{
	BTree* pTree = nullptr;
	BTreeNodeData* pSearchElement = nullptr;
	int key = 0;

	BTreeNodeData eA = { 3, 'A' };
	BTreeNodeData eB = { 9, 'B' };
	BTreeNodeData eC = { 1, 'C' };
	BTreeNodeData eD = { 35, 'D' };
	BTreeNodeData eE = { 43, 'E' };
	BTreeNodeData eF = { 24, 'F' };
	BTreeNodeData eG = { 56, 'G' };
	BTreeNodeData eH = { 85, 'H' };
	BTreeNodeData eI = { 27, 'I' };
	BTreeNodeData eJ = { 54, 'J' };

	pTree = new BTree();
	if (!pTree)
		return 0;

	pTree->insertNode(eA);
	pTree->insertNode(eB);
	pTree->insertNode(eC);
	pTree->insertNode(eD);
	pTree->insertNode(eE);
	pTree->insertNode(eF);
	pTree->insertNode(eG);
	pTree->insertNode(eH);
	pTree->insertNode(eI);
	pTree->insertNode(eJ);

	pTree->displayTree();
	return 0;
}