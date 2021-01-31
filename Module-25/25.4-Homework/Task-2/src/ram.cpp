#include "ram.h"

std::vector<int> write(const std::string _input) {
  std::istringstream buf(_input);
  std::vector<int> res(8);

  for (size_t i = 0; !buf.eof() && i < res.size(); ++i) {
    std::string tmp;
    buf >> tmp;
    res[i] = std::stoi(tmp);
  }

  return res;
}

std::string read(const std::vector<int>& _ram) {
  std::string res;

  for (size_t i = 0; i < _ram.size(); ++i) {
    res += std::to_string(_ram[i]);

    if (i < _ram.size() - 1) {
      res += ' ';
    }
  }

  return res;
}
