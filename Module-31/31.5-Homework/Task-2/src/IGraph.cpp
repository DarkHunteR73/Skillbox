#include "IGraph.h"

MatrixGraph::MatrixGraph(int countOfVertices) 
	:IGraph(MATRIX), 
	adjMatrix(countOfVertices, std::vector<bool>(countOfVertices, false)) {}

MatrixGraph::MatrixGraph(IGraph* _oth) 
	:MatrixGraph(_oth->VerticesCount()) {
	if (_oth->getType() == MATRIX) {
		adjMatrix = static_cast<MatrixGraph*>(_oth)->adjMatrix;
	} else {
		const auto tmp(static_cast<ListGraph*>(_oth)->GetGraph());

		for (int i = 0; i < adjMatrix.size(); ++i) {
			for (int j = 0; j < tmp[i].size(); ++j) {
				adjMatrix[i][tmp[i][j]] = true;
			}
		}
	}
}

void MatrixGraph::AddEdge(int from, int to) {
	assert(from != to);
	assert(from >= 0 && from < adjMatrix.size() 
		   && to >= 0 && to < adjMatrix.size());

	if (!adjMatrix[from][to])
		adjMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const { return adjMatrix.size(); }

void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
	assert(vertex >= 0 && vertex < adjMatrix.size());

	for (int i = 0; adjMatrix[vertex].size(); ++i) {
		if (adjMatrix[vertex][i]) vertices.push_back(i);
	}
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
	assert(vertex >= 0 && vertex < adjMatrix.size());

	for (int i = 0; i < adjMatrix.size(); ++i) {
		if (adjMatrix[i][vertex]) vertices.push_back(i);
	}
}

const std::vector<std::vector<bool>>& MatrixGraph::GetGraph() const { return adjMatrix; }

ListGraph::ListGraph(int countOfVertices) 
	:IGraph(LIST),
	adjList(countOfVertices) {}

ListGraph::ListGraph(IGraph* _oth) 
	:ListGraph(_oth->VerticesCount()) {
	if (_oth->getType() == LIST) {
		adjList = static_cast<ListGraph*>(_oth)->adjList;
	} else {
		const auto tmp(static_cast<MatrixGraph*>(_oth)->GetGraph());

		for (int i = 0; i < adjList.size(); ++i) {
			for (int j = 0; j < tmp[i].size(); ++j) {
				if (tmp[i][j]) adjList[i].push_back(j);
			}
		}
	}
}

void ListGraph::AddEdge(int from, int to) {
	assert(from != to);
	assert(from >= 0 && from < adjList.size()
		   && to >= 0 && to < adjList.size());

	bool found = false;
	for (int i = 0; i < adjList[from].size(); ++i) {
		if (to == i) found = true;
	}

	if (!found) {
		adjList[from].push_back(to);
	}
}

int ListGraph::VerticesCount() const { return adjList.size(); }

void ListGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
	assert(vertex >= 0 && vertex < adjList.size());

	for (int i = 0; i < adjList[vertex].size(); ++i) {
		vertices.push_back(adjList[vertex][i]);
	}
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
	assert(vertex >= 0 && vertex < adjList.size());

	for (int i = 0; i < adjList.size(); ++i) {
		if (i == vertex) continue;
		for (int j = 0; j < adjList[i].size(); ++j) {
			if (adjList[i][j] == vertex) {
				vertices.push_back(i);
				break;
			}
		}
	}
}

const std::vector<std::vector<int>>& ListGraph::GetGraph() const { return adjList; }

IGraph::IGraph(Type _type) :adjtype(_type) {}

Type IGraph::getType() { return adjtype; }
