#include "kbd.h"

std::string input() {
  std::string res;
  std::getline(std::cin, res);
  return res;
}