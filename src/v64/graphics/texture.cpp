#include "texture.h"
#include "renderer.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

Texture::Texture()
{
}

Texture::~Texture()
{
	SDL_DestroyTexture(_pTexture);
}

void Texture::setTexture(SDL_Texture* pTexture) {
	_pTexture = pTexture;
}

void Texture::setSize(int iWidth, int iHeight) {
	_oDestination.w = iWidth;
	_oDestination.h = iHeight;
}

void Texture::setPosition(int iX, int iY) {
	_oDestination.x = iX;
	_oDestination.y = iY;
}

void Texture::scale(float fScale) {
	_oDestination.w *= fScale;
	_oDestination.h *= fScale;
}

bool Texture::getVisibility()
{
	return _bVisible;
}

void Texture::setVisibility(bool bVisible) {
	_bVisible = bVisible;
}

SDL_Texture *Texture::getTexture() {
	return _pTexture;
}

SDL_Rect* Texture::getDestination() {
	return &_oDestination;
}
