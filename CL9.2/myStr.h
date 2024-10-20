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

			for (int i = 0; i < DEFAULT_STR_SIZE; i++)
			{
				this->text[i] = '!';
			}
			this->text[DEFAULT_STR_SIZE] = '\0';
		}
		explicit myStr(int s)
		{
			this->text = new char[s + 1];
			this->size = s;
		}
		myStr(char* text)
		{
			int strlen = myStrlen(text);

			this->myStrcpy(text, strlen);
		}
		myStr(const char* text)
		{
			int strlen = myStrlen(text);

			this->myStrcpy(text, strlen);
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

			printf("\nCopy constructor used\n");
		}
		myStr(myStr&& other)
		{
			if (this == &other)
			{
				return;
			}

			this->size = other.size;
			this->text = other.text;
			other.size = 0;
			other.text = nullptr;

			printf("\nMove constructor used\n");
			
		}
		myStr(std::initializer_list<char> a)
		{
			printf("Constructed via initializer list\n");
			printf("Size is %i\n", static_cast<int>(a.size()));
			this->size = a.size();
			this->text = new char[a.size()+1];
			for (auto x = a.begin(); x != a.end(); x++)
			{
				*text = *x;
				text++;
			}
			this->text[this->size] = '\0';
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

			//printf("\n Destructor used \n");
		}

		char operator[](int index)
		{
			if (index < 0 || index > this->size)
			{
				return '\a';
			}

			return this->text[index];
		}

		myStr operator()(char* buffer)
		{
			myStr temp(buffer);

			this->myStrcpy(temp);
			return *this;
		};
		myStr operator()(const char* buffer)
		{
			myStr temp(buffer);

			this->myStrcpy(temp);
			return *this;
		};

		myStr operator()(myStr& str)
		{
			this->myStrcpy(str);
			return *this;
		}

		myStr operator=(myStr& other)
		{
			if (this == &other)
			{
				printf("returned early !!!!\n");
				return *this;
			}

			this->text = new char[other.size + 1];
			this->size = other.size;

			for (int i = 0; i < other.size; i++)
			{
				this->text[i] = other.text[i];
			}

			this->text[this->size] = '\0';

			return *this;
		}

		myStr operator=(char* buffer)
		{
			this->myStrcpy(buffer);

			return *this;
		}

		myStr operator=(myStr&& other)
		{
			if (this == &other)
			{
				return *this;
			}

			this->size = other.size;
			this->text = other.text;
			other.size = 0;
			other.text = nullptr;

			printf("\nMove \"=\" operator used\n");
			return *this;
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

			for (int i = 1, j = 0; i < temp.getSize(); i++)
			{
				temp.getText()[i] = this->text[j];
				j++;
			}
			temp.getText()[0] = '_';
			temp.getText()[temp.getSize()] = '\0';

			this->myStrcpy(temp);
			return *this;
		}



		void input()
		{
			char buffer[255];
			std::cin >> buffer;

			myStr temp(buffer);

			this->myStrcpy(temp);
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
			return j-1;
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

		void myStrcpy(char* otext)
		{
			if (this->text != nullptr)
			{
				delete[] this->text;
				this->text = nullptr;
			}

			this->text = new char[myStrlen(otext) + 1];
			this->size = myStrlen(otext);

			for (int i = 0; i < myStrlen(otext); i++)
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
			int newSize = this->size + other.size;
			myStr temp( newSize );

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

		int getSize() const
		{
			return this->size;
		}

		char* getText() const
		{
			return this->text;
		}

};



myStr operator+(myStr& str,char c)
{
	int newSize = str.getSize() + 1;
	myStr temp(newSize);


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
	int newSize = str.getSize() + 1;
	myStr temp(newSize);
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
	int newSize = str.getSize() + extra;
	myStr temp(newSize);

	for (int i = 0; i < temp.getSize() - extra; i++)
	{
		temp.getText()[i] = str.getText()[i];
	}
	for (int i = temp.getSize() - extra; i < temp.getSize(); i++)
	{
		temp.getText()[i] = '_';
	}
	temp.getText()[temp.getSize()] = '\0';

	return temp;
}

myStr operator+(int extra, myStr& str)
{
	int newSize = str.getSize() + extra;
	myStr temp(newSize);

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

std::ostream& operator<<(std::ostream& os, const myStr str)
{
	printf("\n<< operator used\n");

	for (int i = 0; i < str.getSize(); i++)
	{
		os << str.getText()[i];
	}
	return os;
};
std::istream& operator>>(std::istream& is, myStr& str)
{
	printf("\n>> operator used\n");

	char buffer[255];

	std::cin >> buffer;
	
	str.myStrcpy(buffer);

	return is;
};

/*

ostream& operator<<(ostream& os, const Foo& obj)
{
	os << "ostream& operator<<(ostream& os, const Foo& obj)" << endl;

	os << obj.GetInt() << endl;
	os << obj.GetChar() << endl;
	//os << obj.m_data << endl << obj.m_character << endl;

	return os;
}

istream& operator>>(istream& is, Foo& obj)
{
	cout << "istream& operator>>(istream& is, Foo& obj)" << endl;

	cout << "m_data = ";
	int a;
	cin >> a;
	obj.SetInt(a);

	cout << "m_character = ";
	char b;
	is >> b;
	obj.SetChar(b);

	return is;
}

*/