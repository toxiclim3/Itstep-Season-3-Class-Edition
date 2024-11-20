#pragma once

#include "Employer.h"


class worker : public employer
{
	private:
		char* company;
	public:
		worker() : employer()
		{
			company = nullptr;
		};

		worker(const char* n, const char* p, const char* c) : employer(n, p)
		{
			company = new char[strlen(c) + 1];
			strcpy_s(company, strlen(c), c);
		};

		~worker()
		{
			if (name != nullptr)
			{
				delete[] name;
			};

			if (position != nullptr)
			{
				delete[] position;
			};

			if (company != nullptr)
			{
				delete[] company;
			};
		};

		void print()
		{
			std::printf("Name: %s\n", name);
			std::printf("Position: %s\n", position);
			std::printf("company: %s\n", company);
		};
};