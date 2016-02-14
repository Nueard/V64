#include "pacman.h"

Pacman::Pacman()
{
}

Pacman::~Pacman()
{
}

void Pacman::init()
{
	_game->getResourceManager()->loadTexture("pacman.png", &_texture);
	// Register as drawable
	_game->getRenderer()->registerDrawable(this);
	// Register movement callbacks
	_game->getMessenger()->registerHandler(SDLK_UP, this, Pacman::move);
	_game->getMessenger()->registerHandler(SDLK_LEFT, this, Pacman::move);
	_game->getMessenger()->registerHandler(SDLK_RIGHT, this, Pacman::move);
	_game->getMessenger()->registerHandler(SDLK_DOWN, this, Pacman::move);
}

void Pacman::update(float deltaTime)
{
}

Texture * Pacman::getTexture()
{
	return &_texture;
}

void Pacman::move(void * object, Message * message)
{
	switch (message->getId())
	{
	case SDLK_UP:
		info("UP");
		break;
	case SDLK_DOWN:
		info("DOWN");
		break;
	case SDLK_LEFT:
		info("LEFT");
		break;
	case SDLK_RIGHT:
		info("RIGHT");
		break;
	default:
		break;
	}
}
