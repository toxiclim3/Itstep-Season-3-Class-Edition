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
			this->name = nullptr;
			this->position = nullptr;
		};

		employer(const char* n, const char* p)
		{
			this->name = new char[strlen(n) + 1];
			strcpy_s(this->name, strlen(n) + 1, n);

			this->position = new char[strlen(p) + 1];
			strcpy_s(this->position, strlen(p) + 1, p);
		};

		~employer()
		{
			if (this->name != nullptr)
			{
				delete[] this->name;
				this->name = nullptr;
			}

			if (this->position != nullptr)
			{
				delete[] this->position;
				this->position = nullptr;
			}
		};

		virtual void print()
		{

		};
};