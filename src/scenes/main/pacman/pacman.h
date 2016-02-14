#pragma once

#include "v64.h"

class Pacman : public GameObject, public Drawable
{
private:
	Texture _texture;
public:
	Pacman();
	~Pacman();

	void init();
	void update(float deltaTime);
	Texture* getTexture();
	static void move(void* object, Message* message);
};
