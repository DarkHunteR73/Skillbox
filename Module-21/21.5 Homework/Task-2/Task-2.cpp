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
    int id = 0;

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

//Функция для поиска совпадений в номерах участков
bool checkID(std::vector<Sector>& sector, int count);

//Линия-разделитель
void splitter(char);

int main()
{
    std::cout << "Please input number of sectors: ";
    int numOfSectors;
    std::cin >> numOfSectors;
    std::vector<Sector> sector(numOfSectors);

    for (int i = 0; i < sector.size(); ++i)
    {
        splitter('#');

        std::cout << "Sector " << i + 1 << ':' << std::endl;
        
        do
        {
            std::cout << "Please enter a unique sector number: ";
            sector[i].id = getNumber(1, INT32_MAX);
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

    for (int i = 0; i < count; ++i)
    {        
        if (sector[count].id == sector[count - i - 1].id)
        {
            std::cerr << "Match found! Please try again." << std::endl;
            return false;
        }
    }

    return true;
}

void splitter(char ch)
{
    for (int  i = 0; i < 50; ++i)
    {
        std::cout << ch;
    }

    std::cout << std::endl;
}

void fillStruct(Sector& sector)
{
    //Опрос по постройкам
    std::cout << "Buildings:" << std::endl;
    std::cout << "Is there a garage on this lot? (y/n):";
    sector.garage.exist = getAnswer();

    std::cout << "\nIs there a barn on this lot? (y/n):";
    sector.barn.exist = getAnswer();

    std::cout << "\nIs there a bathhouse on this lot? (y/n):";
    sector.bathhouse.exist = getAnswer();
    std::cout << std::endl;

    splitter('-');

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Детализация жилого дома
    std::cout << "Living house:" << std::endl;
    std::cout << "Does the house have a stove with a chimney? (y/n):";
    sector.livingHouse.chimney = getAnswer();

    std::cout << "\nNumber of floors (1-3): ";
    sector.livingHouse.countOfFloors = getNumber(1, 3);
    
    //Детализация по этажам
    for (int i = 0; i < sector.livingHouse.countOfFloors; ++i)
    {
        splitter('-');
        
        std::cout << "Floor " << i + 1 << ':' << std::endl;
        std::cout << "Ceiling height: ";
        sector.livingHouse.floor[i].height = getNumber(2.0, 15.0);
        std::cout << "Number of rooms (2-4): ";
        sector.livingHouse.floor[i].countOfRooms = getNumber(2, 4);

        //Детализация комнат на этаже
        for (int j = 0; j < sector.livingHouse.floor[i].countOfRooms; ++j)
        {
            splitter('-');

            std::cout << "Room " << j + 1 << ':' << std::endl;
            std::cout << "1. Bedroom" << std::endl;
            std::cout << "2. Kitchen" << std::endl;
            std::cout << "3. Bathroom" << std::endl;
            std::cout << "4. Children room" << std::endl;
            std::cout << "5. Living room" << std::endl;
            std::cout << "\nSelect room type: ";
            sector.livingHouse.floor[i].rooms[j].roomType = getNumber(1, 5);

            std::cout << "Room area: ";
            sector.livingHouse.floor[i].rooms[j].area = getNumber(1.0, DBL_MAX);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Гараж
    if (sector.garage.exist)
    {
        splitter('-');

        std::cout << "Garage" << std::endl;
        std::cout << "Garage area: ";
        sector.garage.area = getNumber(4.0, DBL_MAX);
    }

    //Сарай
    if (sector.barn.exist)
    {
        splitter('-');

        std::cout << "Barn" << std::endl;
        std::cout << "Barn area: ";
        sector.barn.area = getNumber(4.0, DBL_MAX);
    }

    //Баня
    if (sector.bathhouse.exist)
    {
        splitter('-');

        std::cout << "Bathhouse" << std::endl;
        std::cout << "Does the bathhouse have a stove with a chimney? (y/n):";
        sector.bathhouse.chimney = getAnswer();
        std::cout << "Bathhouse area: ";
        sector.bathhouse.area = getNumber(4.0, DBL_MAX);
    }
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