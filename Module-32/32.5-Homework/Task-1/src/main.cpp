#include "Record.h"

#include <iostream>
#include <string>
#include <fstream>

int main() {
    Record record;
    std::ofstream file("film-record.json");
    nlohmann::json jsonObj;
    record.makeJson(jsonObj);

    file << jsonObj;
}

//  Задача 1. Информация о фильме с кинопортала
//  
//  Что нужно сделать
//  
//  Запишите подробную информацию о киноленте в виде JSON-файла. Выберите понравившуюся вам картину на
//  любимом портале, проанализируйте информацию о ней и составьте JSON-словарь.
//  
//  В информации должны присутствовать: страна и дата создания киноленты, студия, которая вела съёмки,
//  автор сценария, режиссёр и продюсер киноленты. Обязательно добавьте информацию обо всех главных
//  действующих лицах и тех актёрах, которые их сыграли.
//  
//  Что оценивается
//  
//  Валидность созданного JSON-документа.