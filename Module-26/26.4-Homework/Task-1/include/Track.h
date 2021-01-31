#pragma once

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class Track {
  std::string name;
  std::tm creationDate;
  int duration;

 public:
  Track();
  std::string getTrackName();
  void trackInfo();
};
