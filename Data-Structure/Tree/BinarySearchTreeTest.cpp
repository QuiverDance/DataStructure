#include "BinarySearchTree.h"
#include <iostream>

int main(void)
{
	BinSearchTree* tree = new BinSearchTree();
	BinSearchTreeNode* pRootNode = nullptr;
	BinSearchTreeNode node1 = { 15 };
	BinSearchTreeNode node2 = { 55 };
	BinSearchTreeNode node3 = { 11 };
	BinSearchTreeNode node4 = { 5 };
	BinSearchTreeNode node5 = { 7 };
	BinSearchTreeNode node6 = { 65 };
	BinSearchTreeNode node7 = { 13 };
	BinSearchTreeNode node8 = { 75 };
	BinSearchTreeNode node9 = { 1 };
	BinSearchTreeNode node10 = { 10 };

	tree->insertElement(node1);
	tree->insertElement(node2);
	tree->insertElement(node3);
	tree->insertElement(node4);
	tree->insertElement(node5);
	tree->insertElement(node6);
	tree->insertElement(node7);
	tree->insertElement(node8);
	tree->insertElement(node9);
	tree->insertElement(node10);

	pRootNode = tree->getRootNode();
	tree->displayTree(pRootNode, 1, 'A');

	tree->deleteElement(15);
	tree->displayTree(pRootNode, 1, 'A');
}