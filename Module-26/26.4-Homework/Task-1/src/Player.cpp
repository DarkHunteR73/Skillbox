#include "Player.h"

Player::Player(int playlistSize) { playlist.resize(playlistSize); }

void Player::play() {
  if (currentStatus == Status::STOP) {
    std::string searchRequest;
    std::cout << "Enter track name: ";
    std::getline(std::cin, searchRequest);

    bool match = false;

    for (int i = 0; !match && i < playlist.size(); ++i) {
      if (searchRequest == playlist[i].getTrackName()) {
        currentTrack = i;
        currentStatus = Status::PLAY;
        match = true;        
      }
    }

    if (!match) {
      std::cerr << "Track with this name not found!" << std::endl;
    }
  } else if (currentStatus == Status::PAUSE)
    currentStatus = Status::PLAY;

  getStatus();
}

void Player::stop() {
  if (currentStatus) currentStatus = Status::STOP;

  getStatus();
}

void Player::pause() {
  if (currentStatus == Status::PLAY) currentStatus = Status::PAUSE;

  getStatus();
}

void Player::next() {
  if (currentStatus) {
    currentStatus = Status::PLAY;
    currentTrack =
        (currentTrack + std::rand() % playlist.size() - 1) % playlist.size();
  }

  getStatus();
}

void Player::getStatus() {
  switch (currentStatus) {
    case Status::STOP:
      std::cout << "STOPPED: ";
      break;
    case Status::PLAY:
      std::cout << "NOW PLAYING: ";
      break;
    case Status::PAUSE:
      std::cout << "PAUSED: ";
      break;
  }

  if (currentStatus) {
    playlist[currentTrack].trackInfo();
  }

  std::cout << std::endl;
}
