#pragma once

#include <vector>
#include <cassert>

class IGraph {
public:
	virtual ~IGraph() {}

	IGraph() {};

	IGraph(IGraph* _oth) {};

	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;
};

class ListGraph :public IGraph {
	std::vector<std::vector<int>> adjList;
public:
	ListGraph(int countOfVertices);
	ListGraph(const ListGraph* _oth);
	ListGraph(const class MatrixGraph* _oth);

	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
	const std::vector<std::vector<int>>& GetGraph() const;
};

class MatrixGraph :public IGraph {
	std::vector<std::vector<bool>> adjMatrix;
public:
	MatrixGraph(int countOfVertices);
	MatrixGraph(const MatrixGraph* _oth);
	MatrixGraph(const ListGraph* _oth);

	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
	const std::vector<std::vector<bool>>& GetGraph() const;
};