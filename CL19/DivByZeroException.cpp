#include "DivByZeroException.h"

char* DivByZeroException::getMessage()
{
	return m_message;
}

DivByZeroException::DivByZeroException(const char* message)
{
	m_message = new char[strlen(message) + 1];
	strcpy_s(m_message, strlen(message)+1, message);
}