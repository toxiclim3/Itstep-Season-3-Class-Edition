#include "Exception.h"
Exception::Exception()
{
	m_message = nullptr;
}

Exception::Exception(const char* message)
{
	m_message = new char[strlen(message) + 1];
	strcpy_s(m_message, strlen(message)+1, message);
}
char* Exception::getMessage()
{
	const char* message = "Default exception message";

	char* temp;
	temp = new char[strlen(message) + 1];
	strcpy_s(temp, strlen(message)+1, message);

	return temp;
};