#pragma once
#include <string>
class ILoggable
{
protected:
	virtual void logToScreen() = 0;
	virtual void logToFile(const std::string& filename) = 0;
};

