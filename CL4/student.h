#pragma once
using namespace std;

class Student
{
	char* name;
	int age;
	char* email;
public:
	////  prototype 
	Student();
	Student(const char*, int); // construct by 2 param
	Student(const char*, int,const char*); // construct by 3 param
	void Output();
	char* getName();
	int getAge();
	char* getEmail();

	void setName(const char*);
	void setAge(int);
	void setEmail(const char*);

	~Student();

};
Student::Student()
{
	name = nullptr;
	age = 0;
	email = nullptr;
}
Student::Student(const char* Name, int Age)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age;
	email = nullptr;
}
Student::Student(const char* Name, int Age,const char* Email)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age;
	email = new char[strlen(Email) + 1];
	strcpy_s(email, strlen(Email) + 1, Email);
}
void Student::Output()
{
	printf("Name: %s\n", name);
	printf("Age: %i\n", age);
	if (email == nullptr)
	{
		printf("No email saved\n");
	}
	else
	{
		printf("Email: %s\n", email);
	}
}
char* Student::getName()
{
	if (name == nullptr)
	{
		return nullptr;
	}
	else
	{
		return name;
	}
}
int Student::getAge()
{
	return age;
}
char* Student::getEmail()
{
	if (email == nullptr)
	{
		return nullptr;
	}
	else
	{
		return email;
	}
}

void Student::setName(const char* Name)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	else
	{
		name = new char[strlen(Name) + 1];
	}
	strcpy_s(name, strlen(Name) + 1, Name);
};

void Student::setAge(int Age)
{
	age = Age;
};

void Student::setEmail(const char* Email)
{
	if (email != nullptr)
	{
		delete[] email;
	}
	else
	{
		email = new char[strlen(Email) + 1];
	}
	strcpy_s(email, strlen(Email) + 1, Email);
};

Student::~Student()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	if (email != nullptr)
	{
		delete[] email;
	}
	cout << "Student destroyed.\n";
	Sleep(250);

}