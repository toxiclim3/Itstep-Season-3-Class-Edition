#pragma once

#include "Employer.h"


class president : public employer
{
	private:
		char* country;
	public:
		president() : employer()
		{
			this->country = nullptr;
		}

		president(const char* n, const char* p, const char* c) : employer(n, p)
		{
			this->country = new char[strlen(c) + 1];
			strcpy_s(this->country, strlen(c) + 1, c);
		}

		~president()
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

			if (this->country != nullptr)
			{
				delete[] this->country;
				this->country = nullptr;
			}
		}

		void print()
		{
			printf("Name: %s\n", this->name);
			printf("Position: %s\n", this->position);
			printf("Country: %s\n", this->country);
			printf("\n");
		}
};