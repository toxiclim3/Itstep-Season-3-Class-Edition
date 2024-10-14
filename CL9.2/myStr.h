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
			this->text = new char[DEFAULT_STR_SIZE + 1];
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

			this->myStrcpy(text, myStrlen(text));
		}
		myStr(const char* text)
		{
			this->text = new char[myStrlen(text) + 1];
			this->size = myStrlen(text);

			this->myStrcpy(text, myStrlen(text));
		}
		myStr(myStr& other)
		{

			this->text = new char[other.size + 1];
			this->size = other.size;

			for (int i = 0; i < other.size; i++)
			{
				this->text[i] = other.text[i];
			}

			this->text[this->size] = '\0';
		}

		myStr(std::initializer_list<char> a)
		{
			printf("Constructed via initializer list\n");
			printf("Size is %i\n", a.size());
			this->size = a.size();
			this->text = new char[a.size() + 1];
			for (auto x = a.begin(); x != a.end(); x++)
			{
				*text = *x;
				text++;
			}
			text -= size;
		}

		~myStr()
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}
			this->size = 0;
		}

		/*myStr operator()(char* buffer)
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[myStrlen(buffer) + 1];
			strcpy_s(this->text, myStrlen(buffer) + 1, buffer);

			this->size = myStrlen(text);
		};
		myStr operator()(const char* buffer)
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[myStrlen(buffer) + 1];
			strcpy_s(this->text, myStrlen(buffer) + 1, buffer);

			this->size = myStrlen(text);
		};*/

		void input()
		{
			char buffer[255];
			std::cin >> buffer;

			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[myStrlen(buffer) + 1];
			strcpy_s(this->text, myStrlen(buffer) + 1, buffer);

			this->size = myStrlen(text);
		}
		void print()
		{
			printf("%s\n", this->text);
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
		int myStrlen(const char* t)
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
			if (this == &other)
			{
				return;
			}

			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[other.size + 1];
			this->size = other.size;

			for (int i = 0; i < other.size; i++)
			{
				this->text[i] = other.text[i];
			}

			this->text[this->size] = '\0';
		};

		void myStrcpy(char* otext,int osize)
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[osize + 1];
			this->size = osize;

			for (int i = 0; i < osize; i++)
			{
				this->text[i] = otext[i];
			}

			this->text[this->size] = '\0';
		};

		void myStrcpy(const char* otext, int osize)
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[osize + 1];
			this->size = osize;

			for (int i = 0; i < osize; i++)
			{
				this->text[i] = otext[i];
			}

			this->text[this->size] = '\0';
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

		void cutElement(int index)
		{
			myStr temp(this->size);
			for (int i = 0,j=0; i < this->size; i++)
			{
				if (i != index)
				{
					temp.text[j] = this->text[i];
					j++;
				}
			}
			temp.size--;
			temp.text[this->size] = '\0';

			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[this->size];
			this->size--;
			

			this->myStrcpy(temp);
		}

		void myDelChr(char c)
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->text[i] == c)
				{
					this->cutElement(i);
					i = 0;
				}
			}
		}

		int myStrStr(char* str)
		{
			int j = 0;
			bool matching = 0;
			for (int i = 0; i < this->size - this->myStrlen(str) + 1; i++)
			{
				if (this->text[i] == str[j])
				{
					matching = 1;
					while (j < this->myStrlen(str))
					{
						if (this->text[i] == str[j])
						{
							matching = 1;
						}
						else
						{
							j = 0;
							matching = 0;
							break;
						}
						j++;
						i++;
					}
				}
				if (matching)
				{
					return i - j + 1;
				}
			}
			return -1;
		}

		int myStrStr(const char* str)
		{
			int j = 0;
			bool matching = 0;
			for (int i = 0; i < this->size - this->myStrlen(str) + 1; i++)
			{
				if (this->text[i] == str[j])
				{
					matching = 1;
					while (j < this->myStrlen(str))
					{
						if (this->text[i] == str[j])
						{
							matching = 1;
						}
						else
						{
							j = 0;
							matching = 0;
							break;
						}
						j++;
						i++;
					}
				}
				if (matching)
				{
					return i - j + 1;
				}
			}
			return -1;
		}

		void myStrCat(myStr& other)
		{
			myStr temp(this->size + other.size);

			for (int i = 0; i < this->size; i++)
			{
				temp.text[i] = this->text[i];
			}
			for (int i = this->size,j = 0; i < this->size + other.size; i++)
			{
				temp.text[i] = other.text[j];
				j++;
			}

			this->myStrcpy(temp);
		}

		int getSize()
		{
			return this->size;
		}

		char* getText()
		{
			return this->text;
		}

		void operator()(myStr& str)
		{
			this->myStrcpy(str);
		}

		void operator()(char*& str)
		{
			myStr temp(str);
			this->myStrcpy(temp);
		}

		myStr operator++()
		{
			myStr temp(this->size + 1);


			for (int i = 0; i < temp.getSize() - 1; i++)
			{
				temp.getText()[i] = this->text[i];
			}
			temp.getText()[temp.getSize() - 1] = '_';
			temp.getText()[temp.getSize()] = '\0';

			this->myStrcpy(temp);
			return *this;
		}

		myStr operator++(int)
		{
			myStr temp(this->size + 1);
			temp.getText()[0] = '_';

			for (int i = 1, j = 0; i < temp.getSize(); i++)
			{
				temp.getText()[i] = this->text[j];
				j++;
			}
			temp.getText()[temp.getSize()] = '\0';

			this->myStrcpy(temp);
			return *this;
		}






		
};



myStr operator+(myStr& str,char c)
{
	myStr temp(str.getSize() + 1);


	for (int i = 0; i < temp.getSize() - 1; i++)
	{
		temp.getText()[i] = str.getText()[i];
	}
	temp.getText()[temp.getSize() - 1] = c;
	temp.getText()[temp.getSize()] = '\0';

	return temp;
}
myStr operator+( char c, myStr& str)
{
	myStr temp(str.getSize() + 1);
	temp.getText()[0] = c;

	for (int i = 1, j = 0; i < temp.getSize(); i++)
	{
		temp.getText()[i] = str.getText()[j];
		j++;
	}
	temp.getText()[temp.getSize()] = '\0';
	return temp;
}

myStr operator+(myStr& str,int extra)
{
	myStr temp(str.getSize() + extra);

	for (int i = 0; i < temp.getSize() - extra; i++)
	{
		temp.getText()[i] = str.getText()[i];
	}
	for (int i = temp.getSize() - extra; i < temp.getSize(); i++)
	{
		temp.getText()[i] = ' ';
	}
	temp.getText()[temp.getSize()] = '\0';

	return temp;
}

myStr operator+(int extra, myStr& str)
{
	myStr temp(str.getSize() + extra);

	for (int i = 0; i < extra; i++)
	{
		temp.getText()[i] = '_';
		
	}
	for (int i = extra,j = 0; i < temp.getSize(); i++)
	{
		temp.getText()[i] = str.getText()[j];
		j++;
	}
	temp.getText()[temp.getSize()] = '\0';
	return temp;
}

