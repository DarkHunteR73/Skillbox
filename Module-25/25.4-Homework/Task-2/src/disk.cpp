#include "disk.h"

void save(std::string _str) {
  std::ofstream file(".\\data.txt");
  file.clear();

  file << _str;
  file.close();
}

void load(std::vector<int>& _ram) {
  std::ifstream file(".\\data.txt");

  if (file.is_open()) {
    for (size_t i = 0; !file.eof() && i < _ram.size(); i++) {
      std::string tmp;
      file >> tmp;
      _ram[i] = std::stoi(tmp);
    }

    file.close();
  } else {
    std::cerr << "File not found!" << std::endl;
  }
}
