#pragma once

#include "Employer.h"

class manager : public employer
{
	private:
		char* department;
	public:
		manager() : employer()
		{
			this->department = nullptr;
		};

		manager(const char* n, const char* p, const char* d) : employer(n, p)
		{
			this->department = new char[strlen(d) + 1];
			strcpy_s(this->department, strlen(d) + 1, d);
		};

		~manager()
		{
			if (name != nullptr)
			{
				delete[] this->name;
				this->name = nullptr;
			}

			if (position != nullptr)
			{
				delete[] this->position;
				this->position = nullptr;
			}

			if (department != nullptr)
			{
				delete[] this->department;
				this->department = nullptr;
			}
		};

		void print()
		{
			printf("Name: %s\n", this->name);
			printf("Position: %s\n", this->position);
			printf("Department: %s\n", this->department);
			printf("\n");
		};
};