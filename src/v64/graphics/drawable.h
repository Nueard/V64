#pragma once

#include "texture.h"

class Drawable
{
protected:
	int _iOrder;
public:
	//virtual void preDraw() = 0;
	virtual Texture* getTexture() = 0;
	int getOrder();
	void setOrder(int iOrder);
};
