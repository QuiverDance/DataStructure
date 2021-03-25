#include "BinaryTree.h"
#include <iostream>

int main(void)
{
	BinaryTree* tree = nullptr;
	BinTreeNode* pNodeA = nullptr, * pNodeB = nullptr, * pNodeC = nullptr;
	BinTreeNode* pNodeD = nullptr, * pNodeE = nullptr, * pNodeF = nullptr;
	BinTreeNode node = { 'A', nullptr, nullptr };

	tree = new BinaryTree(node);
	pNodeA = tree->getRootNode();
	
	node.data = 'B';
	pNodeB = tree->insertLeftChildNode(pNodeA, node);
	node.data = 'C';
	pNodeC = tree->insertRightChildNode(pNodeA, node);

	node.data = 'D';
	pNodeD = tree->insertLeftChildNode(pNodeB, node);

	node.data = 'E';
	pNodeE = tree->insertLeftChildNode(pNodeC, node);
	node.data = 'F';
	pNodeF = tree->insertRightChildNode(pNodeC, node);

	std::cout << "preorder: ";
	tree->preorderTraversalRecursiveTree(pNodeA); std::cout << std::endl;
	std::cout << "inorder: ";
	tree->inorderTraversalRecursiveTree(pNodeA); std::cout << std::endl;
	std::cout << "postorder: ";
	tree->postorderTraversalRecursiveTree(pNodeA); std::cout << std::endl;
	std::cout << "Node count: " << tree->getNodeCount(pNodeA) << std::endl;
	std::cout << "Leaf node count: " << tree->getLeafNodeCount(pNodeA) << std::endl;
	std::cout << "Height of tree: " << tree->getHeight(pNodeA) << std::endl;

	tree->displayTree(pNodeA, 1, 'A');
	delete tree;
}
