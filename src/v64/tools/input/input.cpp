#include "input.h"
#include "../events/messaging.h"
#include <iostream>

bool Input::init(Messenger *messenger) {
	_messenger = messenger;
	return true;
}

void Input::poll() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			Message message;
			message.initialise(event.key.keysym.sym, NULL);
			_messenger->postMessage(&message);
			break;
		}
	}
}
