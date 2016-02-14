#pragma once
#include <string>
#include "../../graphics/texture.h"
#include "../../graphics/renderer.h"

class ResourceManager
{
private:
	std::string _resourcePath;
	Renderer* _renderer;
public:
	ResourceManager();
	~ResourceManager();
	bool init(Renderer* renderer);
	void loadTexture(std::string file, Texture* texture);
};