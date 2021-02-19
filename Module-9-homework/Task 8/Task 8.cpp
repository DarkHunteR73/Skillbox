#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Сокращаем дроби\n\n";
    int tmpM, tmpN;
    do
    {
        std::cout << "Введите числитель и знаменатель дроби: ";
        std::cin >> tmpM >> tmpN;
        if (tmpM > 0 && tmpN > 0) break;
        std::cout << "Ошибка!\n";
    } while (tmpM == 0 || tmpN == 0);
  
    int m = tmpM, n = tmpN;
    while (tmpM != 0 && tmpN != 0)
    {
        if (tmpM > tmpN) tmpM %= tmpN;
        else tmpN %= tmpM;
    }   

    m /= (tmpM + tmpN); 
    n /= (tmpM + tmpN);

    if (n > 1) std::cout << "Дробь можно сократить до значения " << m << "/" << n << "\n";
    else std::cout << "Дробь можно сократить до целого значения " << m << "\n";
    return 0;
}