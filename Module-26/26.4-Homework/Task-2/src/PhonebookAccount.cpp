#include "PhonebookAccount.h"

PhonebookAccount::PhonebookAccount(std::string inName, std::string inNumber)
    : name(inName), numbers{inNumber} {}

void PhonebookAccount::addNewNumber(std::string inNumber) {
  numbers.push_back(inNumber);
}

void PhonebookAccount::addNewEvent(Activity mode) {
  std::time_t currentTime = std::time(nullptr);
  std::tm currentTM = *std::localtime(&currentTime);
  eventLog << std::put_time(&currentTM, "%Y/%m/%d %R") << std::endl;

  if (mode == Activity::CALL) {
    eventLog << "CALL" << std::endl;
  } else if (mode == Activity::SMS) {
    eventLog << "SMS: ";
    std::cout << "Message: ";
    std::string text;
    std::getline(std::cin, text);
    eventLog << text << std::endl;
  }
  eventLog << std::endl;
}

void PhonebookAccount::showInfo() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Numbers:" << std::endl;
  for (int i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << std::endl;
  }
  std::cout << "History:" << std::endl;
  std::cout << eventLog.str();
}

std::string PhonebookAccount::getName() { return name; }
