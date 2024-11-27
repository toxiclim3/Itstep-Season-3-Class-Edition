#pragma once
#include "Exception.h"
#include <iostream>
class IndexException : public Exception
{
	public:
		IndexException(const char* message);
		char* getMessage();
};

