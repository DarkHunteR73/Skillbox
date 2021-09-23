#pragma once

#include <iostream>
#include <map>

#include "PhonebookAccount.h"

class Phone {
  std::map<std::string, PhonebookAccount*> phonebook;
  std::map<std::string, PhonebookAccount*> numberToNameMap;

  bool isNumber(std::string);
  PhonebookAccount* getAccountPtr();

 public:
  ~Phone();
  void add();
  void action(Activity mode);
};