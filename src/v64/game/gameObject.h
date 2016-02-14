#pragma once

#include <string>
#include "../graphics/drawable.h"
#include "../game/game.h"

class Game;

class GameObject {
protected:
	Game* _game;
	std::string _identifier;
public:
	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	void setGameObject(Game* game);
};
