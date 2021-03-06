#pragma once

typedef struct BinTreeNodeType {
	char data;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

class BinaryTree {
public:
	BinaryTree(BinTreeNode rootNode);
	~BinaryTree();
	BinTreeNode* getRootNode();
	BinTreeNode* insertLeftChildNode(BinTreeNode* pParentNode, BinTreeNode element);
	BinTreeNode* insertRightChildNode(BinTreeNode* pParentNode, BinTreeNode element);
	BinTreeNode* getLeftChildNode(BinTreeNode* pParentNode);
	BinTreeNode* getRightChildNode(BinTreeNode* pParentNode);
	void deleteTree();
	void deleteTreeNode(BinTreeNode* pDelNode);
	void preorderTraversalRecursiveTree(BinTreeNode* pParentNode);
	void inorderTraversalRecursiveTree(BinTreeNode* pParentNode);
	void postorderTraversalRecursiveTree(BinTreeNode* pParentNode);
	int getNodeCount(BinTreeNode* pParentNode);
	int getLeafNodeCount(BinTreeNode* pParentNode);
	int getHeight(BinTreeNode* pParentNode);
	void displayTree(BinTreeNode* pParentNode, int level, char type);
private:
	BinTreeNode* pRootNode;
};