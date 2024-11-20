#pragma once

#include "Employer.h"


class president : public employer
{
	private:
		char* country;
	public:
		president() : employer()
		{
			country = nullptr;
		}

		president(const char* n, const char* p, const char* c) : employer(n, p)
		{
			country = new char[strlen(c) + 1];
			strcpy_s(country, strlen(c), c);
		}

		~president()
		{
			if (name != nullptr)
			{
				delete[] name;
			}

			if (position != nullptr)
			{
				delete[] position;
			}

			if (country != nullptr)
			{
				delete[] country;
			}
		}

		void print()
		{
			std::printf("Name: %s\n",name);
			std::printf("Position: %s\n",position);
			std::printf("Country: %s\n",country);
		}
};