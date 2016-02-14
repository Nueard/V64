#include <iostream>
#include "renderer.h"
#include "../tools/logging/logger.h"

Renderer::Renderer()
{
}

bool Renderer::init() {
	info("Renderer: Initialising");
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		error("Error initialising SDL");
		return false;
	}
	else
	{
		if (!_window.init()) {
			return false;
		}
		_renderer = SDL_CreateRenderer(_window.getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!_renderer) {
			error("Creating renderer failed");
			return false;
		}
	}
	return true;
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(_renderer);
}

SDL_Renderer* Renderer::getRenderer() {
	return _renderer;
}

void Renderer::draw() {
	SDL_RenderClear(_renderer);
	for (std::vector<Drawable*>::iterator i = _drawables.begin(); i != _drawables.end(); ++i)
	{
		//(*i)->preDraw();
		Texture* t = (*i)->getTexture();
		if (t->getVisibility()) {
			SDL_RenderCopy(_renderer, t->getTexture(), NULL, (*i)->getTexture()->getDestination());
		}
	}
	SDL_RenderPresent(_renderer);
}

void Renderer::registerDrawable(Drawable* drawable) {
	for (std::vector<Drawable*>::iterator i = _drawables.begin(); i != _drawables.end(); ++i)
	{
		if((*i)->getOrder()>= drawable->getOrder()) {
			_drawables.insert(i,drawable);
			return;
		}
	}
	_drawables.push_back(drawable);
}
