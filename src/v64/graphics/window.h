#pragma once

#include <string>
#include <SDL.h>

class Window
{
private:
	std::string _sName;
	int _iX,_iY,_iWidth,_iHeight;
	bool _bFullscreen;
	SDL_Window *_pWindow;
public:
	Window();
	bool init();
	~Window();
	bool initialise(std::string name, int x, int y, int width, int height);
	void setSize(int width, int height);
	void setPosition(int x, int y);
	void setName(std::string name);
	void setFullscreen(bool fullscreen);
	SDL_Window* getWindow();
	void destroy();
};
