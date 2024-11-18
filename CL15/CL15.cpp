#include<iostream>
#include<Windows.h>
using namespace std;

/*
	Успадкування

	це спосіб створювати нові об'єкти на основі існуючих та доповнювати їх характеристиками, які ??? новим типам

	C++ підтримує як одиночне, так і множинне успадкування

	Синтаксис успадкування:
		class [Ім'я классу]: [Специфікатор успадкування] [Ім'я базового класу]
		{

		}

	Спершу викликається конструктор базового класу, а потім похідного класу
	Деструктори викликаються в зворотньому порядку

	При успадкуванні класс-нащадок отримує всі поля та методи базового класу на етапі компіляції

	успадковану реалізацію неможливо змінити на етапі виконання

	При перевизначенні у метода одна і та ж сігнатура

	При заміщенні методи мають однакові назви, али різні сігнатури

*/

class Person 
{
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* Name, int Age)
	{
		cout << "Construct Person\n";
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
		age = Age;
	}

	void Print() const
	{
		cout << "Output Person\n";
		cout << "Name: " << name << endl
			<< "Age: " << age << endl;
	}

	void Input()
	{
		char buffer[20];
		cin.getline(buffer, 20);
		name = new char[strlen(buffer) + 1];
		strcpy_s(name, strlen(buffer) + 1, buffer);

		cin >> age;
	}

	~Person()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		cout << "Destruct Person\n";
		Sleep(1000);
	}
};

class student : public Person
{
	private:
		char* university;
	public:
		student() = default;
		student(const char* n, int a, const char* u) : Person(n,a)
		{
			cout << "Student constructed!\n";

			this->university = new char[strlen(u) + 1];
			strcpy_s(this->university, strlen(u) + 1, u);
		}
};

class driver : public Person
{
private:
	double wage;
	char* carNumber;
	int id;
public:
	driver() = default;
	driver(const char* n, int a, const char* c, double w,int i) : Person(n, a),wage(w),id(i)
	{
		cout << "Teacher constructed!\n";

		this->carNumber = new char[strlen(c) + 1];
		strcpy_s(this->carNumber, strlen(c) + 1, c);
	}


};

class teacher : public Person
{
private:
	char* university;
	double wage;

	char** subjects;
public:
	teacher() = default;
	teacher(const char* n, int a, const char* u, double w, const char** s, int s_size) : Person(n, a), wage(w)
	{
		cout << "Teacher constructed!\n";

		this->university = new char[strlen(u) + 1];
		strcpy_s(this->university, strlen(u) + 1, u);

		for (int i = 0; i < s_size; i++)
		{
			this->subjects[i] = new char[strlen(s[i]) + 1];
			strcpy_s(this->subjects[i], strlen(s[i]) + 1, u);
		}
	}
};

class doctor : public Person
{
private:
	double wage;
	char* specialization;
	int id;
public:
	doctor() = default;
	doctor(const char* n, int a, const char* c, double w, int i) : Person(n, a), wage(w), id(i)
	{
		cout << "Teacher constructed!\n";

		this->specialization = new char[strlen(c) + 1];
		strcpy_s(this->specialization, strlen(c) + 1, c);
	}


};

int main()
{
	Person a("Oleg", 19);
	a.Print();


	system("pause");
}