#pragma once

#include <string>
#include <SDL.h>
#include <vector>
#include "../graphics/renderer.h"
#include "../tools/input/input.h"
#include "../tools/events/messenger.h"
#include "../tools/resource/resourceManager.h"
#include "scene/scene.h"

class Scene;

class Game {
private:
	Renderer _renderer;
	Input _input;
	Messenger _messenger;
	bool _running;
	ResourceManager _resourceManager;
	std::vector<Scene*> _scenes;
	Scene* _currentScene;

public:
	bool init();
	~Game();
	void start();
	Messenger* getMessenger();
	Renderer* getRenderer();
	ResourceManager* getResourceManager();
	void addScene(Scene* scene);
	void setActiveScene(std::string identifier);
	static void stop(void *object, Message *message);
};
