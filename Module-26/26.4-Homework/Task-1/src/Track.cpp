#include "Track.h"

Track::Track() {
  static int count;
  std::time_t currentTime = std::time(nullptr);

  name = "Track_" + std::to_string(++count);
  creationDate = *std::localtime(&currentTime);
  duration = std::rand() % 150 + 150;
}

std::string Track::getTrackName() { return name; }

void Track::trackInfo() {
  std::cout << name << std::endl;
  std::cout << "Duration: " << duration << std::endl;
  std::cout << "Created: " << std::put_time(&creationDate, "%Y/%m/%d %R");
}
