#pragma once

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class Activity { CALL, SMS, VIEW };

class PhonebookAccount {
  std::string name;
  std::vector<std::string> numbers;
  std::stringstream eventLog;

 public:
  PhonebookAccount(std::string inName, std::string inNumber);
  void addNewNumber(std::string inNumber);
  void addNewEvent(Activity mode);
  void showInfo();
  std::string getName();
};