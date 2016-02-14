#include "v64\v64.h"
#include "scenes\main\mainScene.h"
#include <iostream>

int main(int argc, char** argv) {
	{
		Game g;
		if (g.init()) {
			MainScene main; 
			main.setIdentifier("mainScene");
			g.addScene(&main);
			g.setActiveScene("mainScene");
			g.start();
		}
	}
	//std::cin.get();
	return 0;
}
