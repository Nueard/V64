#pragma once

#include <vector>
#include "message.h"
#include "callbackData.h"

class CallbackBucket {
private:
	int _iId;
	std::vector<CallbackData> _oCallbacks;
public:
	void addCallback(CallbackData oCallbackData);
	bool removeCallback(void* pObject);
	bool removeCallback(MessageCallback pCallback);
	bool removeCallback(void* pObject, MessageCallback pCallback);
	int getId();
	void setId(int iId);
	std::vector<CallbackData> getCallbacks();
	void notifyAll(Message* pMessage);
};