#pragma once

#include "message.h"

typedef void(*MessageCallback)(void*, Message*);

class CallbackData {
private:
	void* _pObject;
	MessageCallback _pCallback;
public:
	void initialise(void* pObject, MessageCallback pCallback);
	void* getObject();
	MessageCallback getCallback();
};
