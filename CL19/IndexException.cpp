#include "IndexException.h"

char* IndexException::getMessage()
{
	return m_message;
}

IndexException::IndexException(const char* message)
{
	m_message = new char[strlen(message) + 1];
	strcpy_s(m_message, strlen(message) + 1, message);
}