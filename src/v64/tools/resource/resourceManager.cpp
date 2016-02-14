#include "resourceManager.h"
#include "../logging/logger.h"

ResourceManager::ResourceManager()
{
	_resourcePath = "res/";
}

bool ResourceManager::init(Renderer* renderer) {
	if (renderer != nullptr) {
		_renderer = renderer;
		info("Resource Manager: Initialising");
	}
	else {
		error("Resource Manager: Initialising with invalid renderer!");
	}
	return true;
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::loadTexture(std::string file, Texture* texture)
{
	if (_renderer != nullptr) {
		SDL_Texture* _pTexture = IMG_LoadTexture(_renderer->getRenderer(), (_resourcePath + file).c_str());
		if (_pTexture == nullptr) {
			error("Loading texture failed!");
			return;
		}
		int iWidth, iHeight;
		SDL_QueryTexture(_pTexture, NULL, NULL, &iWidth, &iHeight);
		texture->setTexture(_pTexture);
		texture->setSize(iWidth, iHeight);
		texture->setPosition(0, 0);
		texture->setVisibility(true);
	}
	else {
		error("Resource Manager: Renderer not initialised!");
	}
}
