#pragma once

#include <iostream>
#include <vector>

#include "Track.h"

enum Status { STOP, PLAY, PAUSE };

class Player {
  std::vector<Track> playlist;
  int currentStatus = Status::STOP;
  int currentTrack = 0;

 public:
  Player(int playlistSize);
  void play();
  void stop();
  void pause();
  void next();
  void getStatus();
};
