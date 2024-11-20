#pragma once

#include <iostream>

class employer
{
	protected:
		char* name;
		char* position;
	public:
		employer()
		{
			name = nullptr;
			position = nullptr;
		};

		employer(const char* n, const char* p)
		{
			name = new char[strlen(n) + 1];
			strcpy_s(name, strlen(n), n);

			position = new char[strlen(p) + 1];
			strcpy_s(position, strlen(p), p);
		};

		~employer()
		{
			if (name != nullptr)
			{
				delete[] name;
			}

			if (position != nullptr)
			{
				delete[] position;
			}
		};

		virtual void print();
}