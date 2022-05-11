#include <iostream>
#include <vector>
#include <initializer_list>
#include <type_traits>

template <typename T>
double mean(std::initializer_list<T> list) 
requires std::is_arithmetic<T>::value && std::is_scalar<T>::value {
	std::vector<T> vec{ list };
	double result{ 0 };

	for (auto i : vec) {
		result += i;
	}

	return result / static_cast<double>(vec.size());
}

int main() {
	std::cout << mean<int>({ 8,0,12,4555,899,34,12 }) << std::endl;
	std::cout << mean<double>({ 8.54,0.0001,12.45,-4555.12,899.0,34.0,12.1 }) << std::endl;
}

//	������� 4. ������� �������������� ����� � �������
//	
//	��� ����� �������
//	
//	���������� ��������� ������� �������� �������� ��������������� ����� � ������� ��������� ����� 
//	������������� ����. ��� ����� ���� int, double, float � ��� �����.
//	
//	���� ������ ������� � ����� ���������� ������������ ����� ����������� �������.
//	
//	
//	������������
//	
//	��� �������� ������ ����������� ������� � ������� ������������� �����.
//	
//	������� ����� ������ ������� ���� ������������� ����������� ��� ���������.
//	
//	��� ������� ����� ������� ��������� ���� :
//	
//	template < typename T >
//	void input(T array[8]) {
//	    std::cout << "Fill the array (8):";
//	    for (int i = 0; i < 8; ++i) {
//	        /*���� ��������� ���������*/
//	    }
//	}
//	
//	
//	��� �����������
//	
//	������������ ������ ��������� ��� ��������� ���������������� ������ � ��������� ����� 
//	������������ ������ �������.