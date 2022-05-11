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

//	Задание 4. Среднее арифметическое число в массиве
//	
//	Что нужно сделать
//	
//	Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве скалярных чисел 
//	произвольного типа. Это может быть int, double, float и так далее.
//	
//	Ввод данных массива и вывод результата производится через стандартную консоль.
//	
//	
//	Рекомендации
//	
//	Для простоты можете реализовать подсчёт в массиве фиксированной длины.
//	
//	Функцию ввода данных массива тоже рекомендуется реализовать как шаблонную.
//	
//	Обе функции имеют похожую сигнатуру вида :
//	
//	template < typename T >
//	void input(T array[8]) {
//	    std::cout << "Fill the array (8):";
//	    for (int i = 0; i < 8; ++i) {
//	        /*ввод отдельных элементов*/
//	    }
//	}
//	
//	
//	Что оценивается
//	
//	Корректность работы программы при различных пользовательских данных и различных типах 
//	используемых данных массива.