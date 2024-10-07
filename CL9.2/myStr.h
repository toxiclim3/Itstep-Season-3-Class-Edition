#pragma once

#define DEFAULT_STR_SIZE 80

class myStr
{
	private:
		char* text;
		int size;
	public:
		myStr()
		{
			this->text = new char[DEFAULT_STR_SIZE+1];
			this->size = DEFAULT_STR_SIZE;
		}
		explicit myStr(int s)
		{
			this->text = new char[s + 1];
			this->size = s;
		}
		myStr(char* text)
		{
			this->text = new char[myStrlen(text) + 1];
			this->size = myStrlen(text);

			strcpy_s(this->text, myStrlen(text) + 1, text);
		}

		~myStr()
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
			}
			this->size = 0;
		}

		myStr operator()()
		{

		};

		void input()
		{
			char buffer[255];
			std::cin >> buffer;

			if (this->text != nullptr)
			{
				delete[] this->text;
			}

			this->text = new char[myStrlen(buffer) + 1];
			strcpy_s(this->text, myStrlen(buffer) + 1, buffer);

			this->size = myStrlen(text);
		}
		void print()
		{
			printf("%s", this->text);
		}

		int myStrlen()
		{
			int j = 0;
			while (this->text[j] != '\0')
			{
				j++;
			}
			return j;
		}
		int myStrlen(char* t)
		{
			int j = 0;
			while (t[j] != '\0')
			{
				j++;
			}
			return j;
		}

		void myStrcpy(myStr& other)
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
			}

			this->text = new char[other.size + 1];
			this->size = other.size;

			for (int i = 0; (i < other.size) && (other.text[i] != '\0'); i++)
			{
				this->text[i] = other.text[i];
			}

			this->text[this->size + 1] = '\0';
		};

		int myChr(char c)
		{
			for (int i = 0; i < this->myStrlen(); i++)
			{
				if (this->text[i] == c)
				{
					return i;
				}
			}
			return -1;
		}

		bool myStrStr(char* str)
		{

		}

};