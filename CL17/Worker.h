#pragma once

#include "Employer.h"
class worker : public employer
{
private:
	char* company;
public:
	worker() : employer()
	{
		this->company = nullptr;
	}

	worker(const char* n, const char* p, const char* c) : employer(n, p)
	{
		this->company = new char[strlen(c) + 1];
		strcpy_s(this->company, strlen(c)+1, c);
	}

	~worker()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}

		if (position != nullptr)
		{
			delete[] this->position;
			this->position = nullptr;
		}

		if (this->company != nullptr)
		{
			delete[] this->company;
			this->company = nullptr;
		}
	}

	void print()
	{
		printf("Name: %s\n", this->name);
		printf("Position: %s\n", this->position);
		printf("company: %s\n", this->company);
		printf("\n");
	}
};