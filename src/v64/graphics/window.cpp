#include "window.h"
#include <string>
#include <iostream>
#include <SDL.h>
#include "../tools/logging/logger.h"

Window::Window() {

}

bool Window::init()
{
	setName("V64");
	SDL_DisplayMode current;

	for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i) {
		int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
		if (should_be_zero == 0) {
			setSize(current.w, current.h);
		}
		else {
			error("Setting resolution failed");
		}
	}
	_pWindow = SDL_CreateWindow(_sName.c_str(), _iX, _iY, _iWidth, _iHeight, SDL_WINDOW_SHOWN);
	if (!_pWindow) {
		error("Creating window failed");
		return false;
	}
	setFullscreen(false);
	return true;
}

Window::~Window()
{
	if (_pWindow) SDL_DestroyWindow(_pWindow);
}

bool Window::initialise(std::string name, int x, int y, int width, int height) {
	setName(name);
	setPosition(x, y);
	setSize(width, height);
	_pWindow = SDL_CreateWindow(_sName.c_str(), _iX, _iY, _iWidth, _iHeight, SDL_WINDOW_SHOWN);
	if (_pWindow == nullptr) {
		return false;
	}
	setFullscreen(false);
	return true;
}

void Window::setSize(int width, int height) {
	_iWidth = width;
	_iHeight = height;
}

void Window::setPosition(int x, int y) {
	_iX = x;
	_iY = y;
}

void Window::setName(std::string name) {
	_sName = name;
}

void Window::setFullscreen(bool fullscreen) {
	_bFullscreen = fullscreen;
	if (_bFullscreen) {
		SDL_SetWindowFullscreen(_pWindow, SDL_WINDOW_FULLSCREEN);
	}
	else {
		SDL_SetWindowFullscreen(_pWindow, 0);
	}
}

SDL_Window* Window::getWindow() {
	return _pWindow;
}

void Window::destroy() {
	if (_pWindow) {
		SDL_DestroyWindow(_pWindow);
	}
}
