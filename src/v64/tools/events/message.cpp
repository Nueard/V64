#include <iostream>
#include "message.h"

void Message::initialise(int iId, void* pData) {
	_iId = iId;
	_pData = pData;
};