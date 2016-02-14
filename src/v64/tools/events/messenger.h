#pragma once

#include <iostream>
#include <vector>
#include "message.h"
#include "callbackBucket.h"

class Messenger {
private:
	std::vector<CallbackBucket> _oCallbackList;
public:
	bool init();
	void registerHandler (int iMessageId, void* pObject, MessageCallback pCallback);
	void removeHandler (int iId, void*pObject);
	void postMessage (Message* pMessage);
};
