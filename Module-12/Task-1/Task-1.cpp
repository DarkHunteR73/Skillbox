#include <iostream>

int main()
{
    bool tiny[]{ true };
    bool small[]{ true,true };
    bool medium[]{ true,true,true };
    bool big[]{ true,true,true,true };

    std::cout << "Tiny ship size: " << sizeof(tiny) << std::endl;
    std::cout << "Small ship size: " << sizeof(small) << std::endl;
    std::cout << "Medium ship size: " << sizeof(medium) << std::endl;
    std::cout << "Big ship size: " << sizeof(big) << std::endl;
}
/*
Задача 1. Корабли в “морском бое”

Требуется объявить массивы для игры в морской бой и вывести их размеры в консоль, не используя констант с размерами. Всего таких типов 4: крошечный, малый, 
средний и большой. Для простоты, типом элементов корабля могут быть обычные bool (размер 1 байт).
*/