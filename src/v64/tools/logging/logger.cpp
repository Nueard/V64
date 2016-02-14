#include "logger.h"
#include <time.h>
#include <iostream>

Logger::Logger()
{
	_tStart = time(NULL);
	enable();
	_oInfo.open(_sInfo, std::ofstream::out);
	_oError.open(_sError, std::ofstream::out);
	info("Allocating logger");
}

Logger::~Logger()
{
	info("Deallocating logger");
	_oInfo.close();
	_oError.close();
	//delete _oInstance;
}

void Logger::log(std::string message, std::ofstream& stream) {
	_mLock.lock();
	if (_bEnabled && stream) {
		stream << difftime(time(NULL), _tStart) << " " << message << "\n";
	}
	_mLock.unlock();
}

void Logger::info(std::string message)
{
	log(message, _oInfo);
}

void Logger::error(std::string message)
{
	log(message, _oError);
}

void Logger::enable()
{
	_bEnabled = true;
}

void Logger::disable()
{
	_bEnabled = false;
}

Logger* Logger::get()
{
	if (!_oInstance) {
		_oInstance = new Logger();
	}
	return _oInstance;
}

void info(std::string message) {
	Logger* l = Logger::get();
	l->info(message);
};

void error(std::string message) {
	Logger* l = Logger::get();
	l->error(message);
};

Logger* Logger::_oInstance;