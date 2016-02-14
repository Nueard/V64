#ifndef __MESSAGE_H__
#define __MESSAGE_H__

class Message {
private:
	int _iId;
	void* _pData;
public:
	void initialise(int iId, void* pData);
	int getId() { return _iId; }
	void setId(int iId) { _iId = iId; }
	void* getData() { return _pData; }
	void setData(void* pData) { _pData = pData; }
};

#endif
