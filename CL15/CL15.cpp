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

	virtual void Print() const
	{
		cout << "Output Person\n";
		cout << "Name: " << name << endl
			<< "Age: " << age << endl;
	}

	virtual void Input()
	{
		char buffer[20];
		cin.getline(buffer, 20);

		if (this->name != nullptr)
		{
			delete[] this->name;
			name = nullptr;
		}

		name = new char[strlen(buffer) + 1];
		strcpy_s(name, strlen(buffer) + 1, buffer);

		cin >> age;
	}

	~Person()
	{
		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}
		cout << "PERSON DESTROYED\n";
		Sleep(100);
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
		~student()
		{
			if (university != nullptr)
			{
				delete[] university;
				university = nullptr;
			}
			cout << "STUDENT STU DONE\n";
			Sleep(250);
		}

		void Print() const
		{
			printf("Student %s:\nAge:%i\nUniversity:%s\n", this->name, this->age, this->university);
			printf("\n");
		}

		void Input()
		{
			printf("Input the student's name:\n");
			char buffer[50];
			cin.getline(buffer, 50);

			if (this->name != nullptr)
			{
				delete[] this->name;
				name = nullptr;
			}

			name = new char[strlen(buffer) + 1];
			strcpy_s(name, strlen(buffer) + 1, buffer);

			printf("Input the student's age:\n");
			cin >> age;

			cin.ignore();
			printf("Input the student's University:\n");
			cin.getline(buffer, 50);
			university = new char[strlen(buffer) + 1];
			strcpy_s(university, strlen(buffer) + 1, buffer);
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
		cout << "Driver constructed!\n";

		this->carNumber = new char[strlen(c) + 1];
		strcpy_s(this->carNumber, strlen(c) + 1, c);
	}
	~driver()
	{

		if (carNumber != nullptr)
		{
			delete[] carNumber;
			carNumber = nullptr;
		}
		cout << "DRIVER OFF THE ROAD\n";
		Sleep(250);
	}

	void Print() const
	{
		printf("Driver %s:\nAge:%i\nWage:%f\nCar number:%s\nId:%i\n", this->name, this->age, this->wage,this->carNumber,this->id);
		printf("\n");
	}

	void Input()
	{
		printf("Input the driver's name:\n");
		char buffer[50];
		cin.getline(buffer, 50);

		if (this->name != nullptr)
		{
			delete[] this->name;
			name = nullptr;
		}

		this->name = new char[strlen(buffer) + 1];
		strcpy_s(this->name, strlen(buffer) + 1, buffer);

		printf("Input the driver's age:\n");
		cin >> this->age;

		printf("Input the driver's wage:\n");
		cin >> this->wage;

		
		cin.ignore();
		printf("Input the driver's car number:\n");
		cin.getline(buffer, 50);

		if (this->carNumber != nullptr)
		{
			delete[] this->carNumber;
			carNumber = nullptr;
		}

		this->carNumber = new char[strlen(buffer) + 1];
		strcpy_s(this->carNumber, strlen(buffer) + 1, buffer);

		printf("Input the driver's id:\n");
		cin >> this->id;
	}
};

class teacher : public Person
{
private:
	char* university;
	double wage;

	char** subjects;
	int subjects_ammount;
public:
	teacher() = default;
	teacher(const char* n, int a, const char* u, double w, const char** s, int s_size) : Person(n, a), wage(w)
	{
		cout << "Teacher constructed!\n";

		this->university = new char[strlen(u) + 1];
		strcpy_s(this->university, strlen(u) + 1, u);

		this->subjects = new char* [subjects_ammount];

		for (int i = 0; i < s_size; i++)
		{
			this->subjects[i] = new char[strlen(s[i]) + 1];
			strcpy_s(this->subjects[i], strlen(s[i]) + 1, s[i]);
		}

		subjects_ammount = s_size;
	}
	~teacher()
	{

		if (university != nullptr)
		{
			delete[] university;
			university = nullptr;
		}

		if (subjects != nullptr)
		{
			for (int i = 0; i < subjects_ammount; i++)
			{
				if (subjects[i] != nullptr)
				{
					delete subjects[i];
					subjects[i] = nullptr;
				}
			}
		}
		cout << "TEACHER DELETED\n";
		Sleep(250);
	}

	void Print() const
	{
		printf("Teacher %s:\nAge:%i\nWage:%f\nUniversity:%s\nSubjects:\n", this->name, this->age, this->wage, this->university);

		for (int i = 0; i < subjects_ammount; i++)
		{
			printf("%s\n", subjects[i]);
		}
		printf("\n");
	}

	void Input()
	{
		printf("Input the teacher's name:\n");
		char buffer[50];
		cin.getline(buffer, 50);

		if (this->name != nullptr)
		{
			delete[] this->name;
			name = nullptr;
		}

		this->name = new char[strlen(buffer) + 1];
		strcpy_s(this->name, strlen(buffer) + 1, buffer);

		printf("Input the teacher's age:\n");
		cin >> this->age;

		printf("Input the teacher's wage:\n");
		cin >> this->wage;

		if (this->university != nullptr)
		{
			delete[] this->university;
			university = nullptr;
		}

		cin.ignore();
		printf("Input the teacher's university:\n");
		cin.getline(buffer, 50);
		this->university = new char[strlen(buffer) + 1];
		strcpy_s(this->university, strlen(buffer) + 1, buffer);

		printf("Input the ammount of subjects taught:\n");
		cin >> this->subjects_ammount;

		for (int i = 0; i < subjects_ammount; i++)
		{
			printf("Input the name of subject %i\n", i+1);

			cin.getline(buffer, 50);

			if (this->subjects[i] != nullptr)
			{
				delete[] this->subjects[i];
				subjects = nullptr;
			}

			this->subjects[i] = new char[strlen(buffer) + 1];
			strcpy_s(this->subjects[i], strlen(buffer) + 1, buffer);
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
	doctor(const char* n, int a, const char* s, double w, int i) : Person(n, a), wage(w), id(i)
	{
		cout << "Doctor constructed!\n";

		this->specialization = new char[strlen(s) + 1];
		strcpy_s(this->specialization, strlen(s) + 1, s);
	}
	~doctor()
	{

		if (specialization != nullptr)
		{
			delete[] specialization;
			specialization = nullptr;
		}
		cout << "DOCTOR GIVEN AN APPLE TO\n";
		Sleep(500);
	}

	void Print() const
	{
		printf("Driver %s:\nAge:%i\nWage:%f\nSpecialization:%s\nId:%i\n", this->name, this->age, this->wage, this->specialization, this->id);
		printf("\n");
	}

	void Input()
	{
		printf("Input the doctor's name:\n");
		char buffer[50];
		cin.getline(buffer, 50);

		if (this->name != nullptr)
		{
			delete[] this->name;
			name = nullptr;
		}

		this->name = new char[strlen(buffer) + 1];
		strcpy_s(this->name, strlen(buffer) + 1, buffer);

		printf("Input the doctor's age:\n");
		cin >> this->age;

		printf("Input the doctor's wage:\n");
		cin >> this->wage;

		

		cin.ignore();
		printf("Input the doctor's specialization:\n");
		cin.getline(buffer, 50);

		if (this->specialization != nullptr)
		{
			delete[] this->specialization;
			specialization = nullptr;
		}

		this->specialization = new char[strlen(buffer) + 1];
		strcpy_s(this->specialization, strlen(buffer) + 1, buffer);

		printf("Input the doctor's id:\n");
		cin >> this->id;
	}
};

int main()
{
	Person a("Oleg", 19);
	a.Print();

	const char* subjects[3]{ "Math","IT","Design"};
	


	teacher b("Teacher", 34, "University name", 54123, subjects, 3);
	b.Print();

	driver c("Driver",52,"BH3762II",61113,849284);
	c.Print();

	doctor d("Doctor",62,"Medicine",745124,7841209);
	d.Print();

	student e("Student", 19, "University university");
	e.Print();


	system("pause");
}