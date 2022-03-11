#include "IGraph.h"

int main() {
	ListGraph lg(6);
	lg.AddEdge(0, 1);
	lg.AddEdge(0, 2);
	lg.AddEdge(0, 3);
	lg.AddEdge(1, 2);
	lg.AddEdge(1, 4);
	lg.AddEdge(2, 3);
	lg.AddEdge(2, 5);
	lg.AddEdge(3, 4);
	lg.AddEdge(4, 5);
	ListGraph lll = lg;
	MatrixGraph mg(&lg);

	std::vector<int> result;
	lg.GetPrevVertices(3, result);
}

//	������ 2. ���������� ������ �����
//	
//	
//	��� ����� ������� :
//	
//	� ����� ��������� ��������� ����������, ��� ����� ����� � ���������� ���������� � ��� ���� ����� 
//	����������� � ���������(��� ����� ������� ��������� � ������ ���������)
//	
//	��� ��� ������� ��������� ��� ������������� ���������������� �����
//	
//	���������� �������� ��� ���������� ���������� :
//	
//	ListGraph, �������� ���� � ���� ������� ������� ���������,
//	MatrixGraph, �������� ���� � ���� ������� ���������,
//	
//	����� ���������� ����������� �����������, ����������� IGraph* .����� ����������� ������ ����������� 
//	���������� ���� � ����������� ������(�������� ��������, ��� ������ � ���� ���������� ����� 
//	���������� ������) ���������� � ��� ����� ��� ������������ ����� � ��������� ������������, ���� ����������.
//	
//	
//	class IGraph {
//	
//	public:
//	
//	    virtual ~IGraph() {}
//	
//	    IGraph() {};
//	
//	    IGraph(IGraph* _oth) {};
//	
//	    virtual void AddEdge(int from, int to) = 0; // ����� ��������� ������� ������ � ����� ����� � ��������� �����
//	
//	    virtual int VerticesCount() const = 0; // ����� ������ ������� ������� ���������� ������
//	
//	    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0; // ��� ���������� ������� ����� ������� � ������ ��������� ��� �������, � ������� ����� ����� �� ����� �� ������
//	
//	    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0; // ��� ���������� ������� ����� ������� � ������ ��������� ��� �������, �� ������� ����� ����� �� ����� � ������
//	
//	};
//	
//	��� - ���� ��� �������� ������
//	
//	����������� ��� ������ - ����������, ���������������� ���������� ��������� ������ � ������
//	��� � �������� ��������� � �������� ���������