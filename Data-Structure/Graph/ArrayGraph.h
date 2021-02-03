#pragma once

enum GraphType
{
	undirected, directed
};
class ArrayGraph
{
public:
	ArrayGraph(int maxVertexCount, GraphType type);
	~ArrayGraph();
	void deleteGraph();
	bool isEmpty();
	void addVertex(int vertexID);
	void addEdge(int fromVerTexID, int toVertexID);
	void addWeightedEdge(int fromVerTexID, int toVertexID, int weight);
	bool checkVertexValid(int vertexID);
	void removeVertex(int vertexID);
	void removeEdge(int fromVertexID, int toVerTexID);
	void displayGraph();
private:
	int maxVertexCount;
	int currentVertexCount;
	GraphType graphType;
	int** ppAdjacentEdge;
	int* pVertex;
};