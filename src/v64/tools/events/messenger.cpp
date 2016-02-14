#include <iostream>
#include "callbackData.h"
#include "callbackBucket.h"
#include "messenger.h"

bool Messenger::init()
{
	return true;
}

void Messenger::registerHandler (int iMessageId, void* pObject, MessageCallback pCallback) {
	bool present = false;
	CallbackData data;
	data.initialise(pObject, pCallback);
	for (std::vector<CallbackBucket>::iterator i = _oCallbackList.begin(); i != _oCallbackList.end(); ++i)
	{
		if(i->getId() == iMessageId) {
			i->addCallback(data);
			present = true;
		}
	}
	if(!present) {
		CallbackBucket bucket;
		bucket.setId(iMessageId);
		bucket.addCallback(data);
		_oCallbackList.push_back(bucket);
	}
}

void Messenger::removeHandler (int iId, void*pObject){
	for (std::vector<CallbackBucket>::iterator i = _oCallbackList.begin(); i != _oCallbackList.end(); ++i)
	{
		if(i->getId() == iId) {
			i->removeCallback(pObject);
		}
	}
};

void Messenger::postMessage (Message* pMessage) {
	for (std::vector<CallbackBucket>::iterator i = _oCallbackList.begin(); i != _oCallbackList.end(); ++i)
	{
		if(i->getId() == pMessage->getId()) {
			i->notifyAll(pMessage);
		}
	}
};
