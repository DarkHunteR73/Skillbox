#pragma once

#include <vector>
#include <cassert>

enum Type { MATRIX, LIST };

class IGraph {
	const Type adjtype;
public:
	virtual ~IGraph() {}

	IGraph(Type _type);

	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;
	Type getType();
};

class ListGraph :public IGraph {
	std::vector<std::vector<int>> adjList;
public:
	ListGraph(int countOfVertices);
	ListGraph(IGraph* _oth);

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
	MatrixGraph(IGraph* _oth);

	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override;
	virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
	virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
	const std::vector<std::vector<bool>>& GetGraph() const;
};