#pragma once

#include "v64.h"
#include "pacman\pacman.h"

class MainScene : public Scene
{
public:
	MainScene();
	~MainScene();
private:
	Pacman _pacman;
};
