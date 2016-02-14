#pragma once

#include <SDL.h>
#include "window.h"
#include <vector>
#include <string>
//#include "texture.h"
#include "drawable.h"

class Renderer
{
private:
	SDL_Renderer* _renderer;
	std::vector<Drawable*> _drawables;
	Window _window;
public:
	Renderer();
	bool init();
	~Renderer();
	SDL_Renderer* getRenderer();
	//bool loadTexture(std::string sPath, Texture* pTexture);
	void draw();
	void registerDrawable(Drawable* drawable);
};
