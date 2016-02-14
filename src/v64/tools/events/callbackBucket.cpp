#include <vector>
#include "callbackData.h"
#include "callbackBucket.h"

void CallbackBucket::addCallback(CallbackData oCallbackData) {
	_oCallbacks.push_back(oCallbackData);
};

bool CallbackBucket::removeCallback(void* pObject) {
	for (std::vector<CallbackData>::iterator current = _oCallbacks.begin(); current != _oCallbacks.end(); ++current)
	{
		if(current->getObject() == pObject) {
			_oCallbacks.erase(current);
			--current;
			return true;
		}
	}
	return false;
};

// bool CallbackBucket::removeCallback(MessageCallback pCallback) {
// 	return false;
// };

// bool CallbackBucket::removeCallback(void* pObject, MessageCallback pCallback) {
// 	return false;
// };

int CallbackBucket::getId() {
	return _iId;
};

void CallbackBucket::setId(int iId) {
	_iId = iId;
};

std::vector<CallbackData> CallbackBucket::getCallbacks() {
	return _oCallbacks;
};

void CallbackBucket::notifyAll(Message* pMessage) {
	for (std::vector<CallbackData>::iterator i = _oCallbacks.begin(); i != _oCallbacks.end(); ++i)
	{
		MessageCallback callback = i->getCallback();
		callback(i->getObject(), pMessage);
	}
};