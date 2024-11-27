#pragma once
#include "Exception.h"
#include <iostream>
class DivByZeroException : public Exception
{
	public:
		char* getMessage();
		DivByZeroException(const char* message);
};

