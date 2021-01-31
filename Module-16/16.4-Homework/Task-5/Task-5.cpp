#include <iostream>
#include <sstream>

enum Switches {
  MAIN_SWITCH = 1,
  OUTLETS = 2,
  LIGHT_INDOOR = 4,
  LIGHT_OUTDOOR = 8,
  BOILER = 16,
  WATERPIPE_HEATER = 32,
  AIR_CONDITIONING = 64
};

void setSensors(std::stringstream& strBuf, int& state, int& hour) {
  double outDoorTemp = 0, inDoorTemp = 0;
  std::string motionSensor, indoorLight;

  strBuf >> outDoorTemp >> inDoorTemp >> motionSensor >> indoorLight;

  state |= MAIN_SWITCH;
  state |= OUTLETS;

  if (state & MAIN_SWITCH) {
    if (outDoorTemp < 0)
      state |= WATERPIPE_HEATER;
    else if (outDoorTemp > 5)
      state &= ~WATERPIPE_HEATER;

    if (motionSensor == "yes" && (hour > 16 || hour < 5))
      state |= LIGHT_OUTDOOR;
    else
      state &= ~LIGHT_OUTDOOR;

    if (inDoorTemp < 22)
      state |= BOILER;
    else if (inDoorTemp >= 25)
      state &= ~BOILER;

    if (inDoorTemp >= 30)
      state |= AIR_CONDITIONING;
    else if (inDoorTemp <= 25)
      state &= ~AIR_CONDITIONING;

    if (indoorLight == "yes")
      state |= LIGHT_INDOOR;
    else
      state &= ~LIGHT_INDOOR;
  }
}

void getStatus(int& state, int& hour) {
  int lightTemp = 5000;

  if (hour > 16 && hour <= 20) lightTemp = 5000 - ((hour - 16) * 575);
  if (hour > 20 && hour <= 23) lightTemp = 2700;

  std::cout << "\nCurrent status:\n" << std::endl;

  if (state & MAIN_SWITCH)
    std::cout << "POWER: on" << std::endl;
  else
    std::cout << "POWER: off" << std::endl;

  if (state & OUTLETS)
    std::cout << "OUTLETS: on" << std::endl;
  else
    std::cout << "OUTLETS: off" << std::endl;

  if (state & LIGHT_INDOOR)
    std::cout << "INDOOR LIGHT: " << lightTemp << std::endl;
  else
    std::cout << "LIGHT INDOOR: off" << std::endl;

  if (state & LIGHT_OUTDOOR)
    std::cout << "OUTDOOR LIGHT: on" << std::endl;
  else
    std::cout << "OUTDOOR LIGHT: off" << std::endl;

  if (state & BOILER)
    std::cout << "BOILER: on" << std::endl;
  else
    std::cout << "BOILER: off" << std::endl;

  if (state & WATERPIPE_HEATER)
    std::cout << "WATERPIPE HEATING: on" << std::endl;
  else
    std::cout << "WATERPIPE HEATING: off" << std::endl;

  if (state & AIR_CONDITIONING)
    std::cout << "A/C: on" << std::endl;
  else
    std::cout << "A/C: off" << std::endl;

  std::cout << std::endl;
}

int main() {
  for (int i = 0; i < 48; ++i) {
    int currentHour = i % 24;
    int switchState = 0;

    std::cout << "Time: " << currentHour << ":00. Input state: ";

    std::string currentState;
    std::stringstream buffer;
    std::getline(std::cin, currentState);
    buffer.str(currentState);

    setSensors(buffer, switchState, currentHour);
    getStatus(switchState, currentHour);
  }
}

/*
Умный дом

Что нужно сделать

Надо разработать упрощённую модель умного дома для дачи.Есть несколько датчиков
: датчик температуры снаружи, датчик температуры внутри дома. В доме расположен
электронный “умный” щиток с автоматами.Каждый автомат отвечает за включение и
отключение определённых устройств или групп устройств. Первый автомат - это
отключение и включение питания всего дома, второй - основные розетки дома,
третий - свет внутри дома, четвёртый - наружный свет в саду, пятый - отопление в
помещении, шестой - отопление водопровода идущего из скважины с насосом, шестой
- кондиционер в помещении.

Есть несколько условий по включению / отключению техники в доме и вне его.

Как только температура снаружи падает ниже 0, надо включить систему обогрева
водопровода и отключить её, если температура снаружи поднялась выше 5 градусов.

Если на дворе вечер(время больше 16:00 и меньше 5 : 00 утра) и снаружи есть
какое - то движение, то необходимо включить садовое освещение. Если движения нет
или время не вечернее - света снаружи быть не должно.

При условии, что температура в помещении упала ниже 22 градусов, должно
включится отопление.Как только температура поднимается выше или равно 25 - и
градусам, отопление автоматически отключается.

Если температура в помещении поднялась до 30 градусов, включается
кондиционер.Как только температура становится 25 градусов - кондиционер
отключается.

Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры
для комфортного нахождения.Каждый день начиная с 16:00 и до 20 : 00, температура
цвета должна плавно изменяться с 5000K до 2700К.Разумеется, это изменение должно
происходить в случае, если свет сейчас включен. В 0 : 00 температура
сбрасывается до 5000К.

Все события по отключению и включению устройств должны выводится в консоль явным
образом. Если устройство не изменило своего состояния(осталось включенным или
выключенным) события генерироваться не должно! Если свет в доме включен, должна
отображаться текущая цветовая температура.

Программа выполняется следующим образом.Каждый час пользователь сообщает
состояние всех основных датчиков и света : температура снаружи, температура
внутри, есть ли движение снаружи, включен ли свет в доме.Данные параметры
вводятся разом в одну строку, через пробел, а потом парсятся в переменные из
строкового буфера stringstream.Информация о

движении выводится в формате yes / no.Включение и отключение света происходит с
помощью on / off.Стартовое время для симуляции умного дома - это 0 : 00.
Требуется осуществить симуляцию на протяжении двух дней.
*/
