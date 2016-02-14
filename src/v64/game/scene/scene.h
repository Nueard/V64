#pragma once

#include <vector>
#include "../game.h"
#include "../gameObject.h"

class Game;
class GameObject;

class Scene {
protected:
	std::vector<GameObject*> _gameObjects;
	Game* _game;
	std::string _identifier;

public:
	bool init(Game* game);
	void setIdentifier(std::string identifier);
	std::string getIdentifier();
	Game* registerObject(GameObject* object);
	void update(float deltaTime);
};
