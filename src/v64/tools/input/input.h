#pragma once

#include <vector>
#include <SDL.h>
#include "../events/messenger.h"

class Input {
private:
  Messenger *_messenger;
  std::vector<SDL_Event> _oEvents;
public:
  bool init(Messenger *messenger);
  void poll();
};
