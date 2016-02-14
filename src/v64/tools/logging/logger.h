#pragma once

#include <string>
#include <fstream>
#include <mutex>

class Logger
{
private:
	bool _bEnabled;
	time_t _tStart;
	static Logger* _oInstance;
	std::ofstream _oInfo, _oError;
	std::string _sInfo = "log.info", _sError = "log.err";
	std::mutex _mLock;

	void log(std::string message, std::ofstream& stream);
	Logger();

public:
	~Logger();
	void info(std::string message);
	void error(std::string message);
	void enable();
	void disable();
	static Logger* get();
};

void info(std::string message);

void error(std::string message);