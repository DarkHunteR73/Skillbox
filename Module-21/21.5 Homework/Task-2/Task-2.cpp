#include <iostream>
#include <vector>
#include <conio.h>

enum BuildingType
{
    LIVING_HOUSE = 1,
    GARAGE,
    BARN,
    BATHHOUSE
};

enum RoomType
{
    BEDROOM = 1,
    KITCHEN,
    BATHROOM,
    CHILDREN_ROOM,
    LIVING_ROOM
};

struct Room
{
    int roomType = 0;
    double area = 0;
};

struct Floor
{
    bool exist = false;
    int countOfRooms = 0;
    double height = 0;
    Room rooms[4];
};

struct LivingHouse
{
    int countOfFloors = 1;
    bool chimney = false;
    Floor floor[3];
};

struct Garage
{
    bool exist = false;
    double area = 0;
};

struct Barn
{
    bool exist = false;
    double area = 0;
};

struct Bathhouse
{
    bool exist = false;
    double area = 0;
    bool chimney = false;
};

struct Sector
{
    unsigned int id;

    LivingHouse livingHouse;
    Garage garage;
    Barn barn;
    Bathhouse bathhouse;
};

//Функция для получения числа в заданном диапазоне
template <class T> T getNumber(T, T);

//Функция для получения ответа "Да/Нет"
bool getAnswer();

//Функция для заполнения экземпляра структуры
void fillStruct(Sector&);

bool checkID(std::vector<Sector>& sector, int count);

int main()
{
    std::cout << "Please input number of sectors: ";
    int numOfSectors;
    std::cin >> numOfSectors;
    std::vector<Sector> sector(numOfSectors);

    for (int i = 0; i < sector.size(); ++i)
    {
        do
        {
            std::cout << "Please enter a unique sector number: ";
            sector[i].id = getNumber(1u, UINT32_MAX);
        } while (!checkID(sector, i));

        fillStruct(sector[i]);
    }
}

template <class T> T getNumber(T rangeMin, T rangeMax)
{
    T num;

    while (true)
    {
        std::cin >> num;

        if (num >= rangeMin && num <= rangeMax)
        {
            return num;
        }
        else
        {
            std::cerr << "Out of range! Input number between " << rangeMin << " and " << rangeMax << ": ";
        }
    }
}

bool getAnswer()
{
    char ch = ' ';

    while (ch != 'y' && ch != 'n')
    {
        ch = _getch();
    }

    if (ch == 'y')
    {
        return true;
    }

    return false;
}

bool checkID(std::vector<Sector>& sector, int count)
{
    if (count == 0) return true;

    for (int i = count - 1; i <= 0; --i)
    {        
        if (sector[count].id == sector[i].id)
        {
            std::cerr << "Match found! Please try again." << std::endl;
            return false;
        }
    }

    return true;
}

void fillStruct(Sector& sector)
{

}

/*
Задание 2. Модель данных для посёлка


Что нужно сделать

С помощью структур данных создайте подробную модель посёлка.

В посёлке есть множество участков. Каждый из них имеет свой уникальный номер. На каждом из участков должен быть расположен как минимум один жилой дом,
но возможны и другие сооружения, такие как гараж, сарай (бытовка) и баня. Для каждого здания предусмотрена информация о площади, которую он занимает на участке.

В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4 комнаты. Каждая комната при этом может быть разных типов: спальня, кухня, ванная, детская,
гостиная. Для каждой комнаты предусмотрены данные о её площади. Для каждого этажа также есть данные о высоте потолка. В жилом доме и бане может быть 
печь с трубой, информация об этом также должна быть предусмотрена в данных.

Для всех упомянутых сущностей надо объявить соответствующие структуры данных.

Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков и далее начинает детализировать каждый из участков.

Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи, комнаты на этажах.

По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой постройками, к общей площади всего посёлка.
Главное в этой задаче не сама операция подсчёта, а структуры данных.


Советы и рекомендации

Используйте все имеющиеся у вас знания о типах данных в C++. Можно  использовать уже изученные перечисления и массивы,
создавать структуры внутри структур и так далее.


Что оценивается

Полнота структур, описывающих данные посёлка.
*/