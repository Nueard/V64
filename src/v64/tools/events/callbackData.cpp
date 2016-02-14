#include "callbackData.h"

void CallbackData::initialise(void* pObject, MessageCallback pCallback) {
	_pObject = pObject;
	_pCallback = pCallback;
};

void* CallbackData::getObject() {
	return _pObject;
};

MessageCallback CallbackData::getCallback() {
	return _pCallback;
};