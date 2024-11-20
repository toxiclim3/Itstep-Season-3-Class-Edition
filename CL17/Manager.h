#pragma once

#include "Employer.h"


class manager : public employer
{
	private:
		char* department;
	public:
		manager() : employer()
		{
			department = nullptr;
		}

		manager(const char* n, const char* p, const char* d) : employer(n, p)
		{
			department = new char[strlen(d) + 1];
			strcpy_s(department, strlen(d), d);
		}

		~manager()
		{
			if (name != nullptr)
			{
				delete[] name;
			}

			if (position != nullptr)
			{
				delete[] position;
			}

			if (department != nullptr)
			{
				delete[] department;
			}
		}

		void print()
		{
			std::printf("Name: %s\n", name);
			std::printf("Position: %s\n", position);
			std::printf("Department: %s\n", department);
		}
};