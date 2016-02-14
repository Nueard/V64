#pragma once

#include <SDL_image.h>
#include <string>

class Texture
{
private:
	SDL_Texture* _pTexture;
	SDL_Rect _oDestination;
	bool _bVisible;
public:
	Texture();
	~Texture();
	void setTexture(SDL_Texture* pTexture);
	void setSize(int iWidth, int iHeight);
	void setPosition(int iX, int iY);
	void scale(float fScale);
	bool getVisibility();
	void setVisibility(bool bVisible);
	SDL_Rect *getDestination();
	SDL_Texture *getTexture();
};
