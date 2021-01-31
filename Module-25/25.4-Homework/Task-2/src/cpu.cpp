#include "cpu.h"

void compute(const std::vector<int>& _ram) {
  int result = 0;

  for (size_t i = 0; i < _ram.size(); ++i) {
    result += _ram[i];
  }

  std::cout << result << std::endl;
}