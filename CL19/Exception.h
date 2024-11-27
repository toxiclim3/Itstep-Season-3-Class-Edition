#pragma once
#include <iostream>
class Exception
{
	protected:
		char* m_message;
		
	public:
		Exception(const char* message);
		Exception();
		virtual char* getMessage();
};

