#include "game.h"
#include "../tools/logging/logger.h"
#include <SDL.h>
#include <iostream>
#include <Windows.h>

bool Game::init()
{
	info("Game: Initialising game object");
	if (!_renderer.init()) {
		return false;
	}
	if (!_messenger.init()) {
		return false;
	}
	if (!_input.init(&_messenger)) {
		return false;
	}
	if (!_messenger.init()) {
		return false;
	}
	if (!_resourceManager.init(&_renderer)) {
		return false;
	}
	_messenger.registerHandler(SDLK_ESCAPE, this, Game::stop);
	return true;
}

Game::~Game()
{
	delete Logger::get();
	SDL_Quit();
}

void Game::start() {
	_running = true;
	while (_running) {
		_input.poll();
		float deltaTime = 0.01;
		if (_currentScene) {
			_currentScene->update(deltaTime);
		}
		_renderer.draw();
	}
}

Messenger *Game::getMessenger() {
	return &_messenger;
}

Renderer *Game::getRenderer() {
	return &_renderer;
}

ResourceManager * Game::getResourceManager()
{
	return &_resourceManager;
}

void Game::addScene(Scene *scene) {
	scene->init(this);
	_scenes.push_back(scene);
}

void Game::setActiveScene(std::string identifier)
{
	for (std::vector<Scene*>::iterator i = _scenes.begin(); i != _scenes.end(); i++) {
		if (!identifier.compare((*i)->getIdentifier())) {
			_currentScene = *i;
		}
	}
}

void Game::stop(void *pObject, Message *pMessage) {
	info("Exiting game loop");
	((Game*)pObject)->_running = false;
}
