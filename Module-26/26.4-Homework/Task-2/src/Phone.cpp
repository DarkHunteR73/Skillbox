#include "Phone.h"

Phone::~Phone() {
  for (auto it = phonebook.begin(); it != phonebook.end(); ++it) {
    delete it->second;
  }
}

void Phone::add() {
  std::string tmpNumber;
  std::cout << "Enter number: ";
  std::cin >> tmpNumber;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (!numberToNameMap.contains(tmpNumber)) {
    if (!isNumber(tmpNumber)) {
      std::cerr << "Incorrect number!" << std::endl;
      return;
    }
    std::string tmpName;
    std::cout << "Enter name: ";
    std::getline(std::cin, tmpName);

    if (!phonebook.contains(tmpName)) {
      PhonebookAccount* account = new PhonebookAccount(tmpName, tmpNumber);
      phonebook.insert(std::make_pair(tmpName, account));
    } else {
      phonebook[tmpName]->addNewNumber(tmpNumber);
    }
    numberToNameMap.insert(std::make_pair(tmpNumber, phonebook[tmpName]));
  } else {
    std::cerr << "This number has already been saved as "
              << numberToNameMap[tmpNumber]->getName() << std::endl;
  }
}

void Phone::action(Activity mode) {
  PhonebookAccount* pAccount = getAccountPtr();

  if (pAccount == nullptr) {
    std::cerr << "No results were found for your search" << std::endl;
    return;
  }

  if (mode == Activity::CALL) {
    std::cout << "CALLING TO: " << pAccount->getName() << std::endl;
  } else if (mode == Activity::SMS) {
    std::cout << "SMS TO: " << pAccount->getName() << std::endl;
  } else if (mode == Activity::VIEW) {
    pAccount->showInfo();
    return;
  }
  pAccount->addNewEvent(mode);
}

bool Phone::isNumber(std::string str) {
  if (str.length() == 12 && str[0] == '+' && str[1] == '7') {
    for (int i = 2; i < str.length(); ++i) {
      if (str[i] < '0' || str[i] > '9') {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

PhonebookAccount* Phone::getAccountPtr() {
  std::cout << "Enter your request: ";
  std::string request;
  std::getline(std::cin, request);

  if (isNumber(request) && numberToNameMap.contains(request)) {
    return numberToNameMap[request];
  } else if (phonebook.contains(request)) {
    return phonebook[request];
  } else {
    return nullptr;
  }
}