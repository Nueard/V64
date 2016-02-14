#include "scene.h"

bool Scene::init(Game* game)
{
	_game = game;
	for (std::vector<GameObject*>::iterator i = _gameObjects.begin(); i != _gameObjects.end(); ++i)
	{
		(*i)->setGameObject(_game);
		(*i)->init();
	}
	return true;
}

void Scene::setIdentifier(std::string identifier)
{
	_identifier = identifier;
}

std::string Scene::getIdentifier()
{
	return _identifier;
}

Game* Scene::registerObject(GameObject * object)
{
	if (object != nullptr) {
		_gameObjects.push_back(object);
	}
	return nullptr;
}

void Scene::update(float deltaTime)
{
	for (std::vector<GameObject*>::iterator i = _gameObjects.begin(); i != _gameObjects.end(); ++i)
	{
		(*i)->update(deltaTime);
	}
}
