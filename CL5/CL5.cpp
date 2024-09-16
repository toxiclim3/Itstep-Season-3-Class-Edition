// CL5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class car
{
	private:
		char* model;
		char* color;
		int year;
		double price;
	public:
		car();
		car(const char* model,const char* color,int year,double price);
		~car();

		void input();
		void display();

		char* getModel();
		char* getColor();
		int getYear();
		double getPrice();

		void setModel(char*);
		void setModel(const char*);
		void setColor(char*);
		void setColor(const char*);
		void setYear(int);
		void setPrice(double);
};

car::car()
{
	this->model = nullptr;
	this->color = nullptr;
	this->year = 0;
	this->price = 0;
}
car::car(const char* model, const char* color, int year, double price)
{
	this->model = new char[strlen(model)+1];
	strcpy_s(this->model, strlen(model)+1, model);

	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color)+1, color);

	this->year = year;
	this->price = price;
}
car::~car()
{
	if (this->model != nullptr)
	{
		delete[] this->model;
	}
	if (this->color != nullptr)
	{
		delete[] this->color;
	}
	this->year = 0;
	this->price = 0;
}

void car::input()
{
	if (this->model != nullptr)
	{
		delete[] this->model;
	}
	this->model = new char[strlen(model) + 1];

	char model[48];
	printf("Enter the car's name:\n");
	cin >> model;
	strcpy_s(this->model, strlen(model)+1, model);

	if (this->color != nullptr)
	{
		delete[] this->color;
	}
	this->color = new char[strlen(color) + 1];

	char color[48];
	printf("Enter the car's color:\n");
	cin >> color;
	strcpy_s(this->color, strlen(color)+1, color);

	printf("Enter the car's manufacturing year:\n");
	cin >> this->year;

	printf("Enter the car's price:\n");
	cin >> this->price;
}
void car::display()
{
	if (this->model ==  nullptr)
	{
		printf("No model saved for this car!?\n");
	}
	else
	{
		printf("Model: %s\n", this->model);
	}
	
	if (this->color == nullptr)
	{
		printf("No color saved for this car!?\n");
	}
	else
	{
		printf("Color: %s\n", this->color);
	}

	printf("Manufacturing year: %i\n", this->year);
	printf("Price: %f\n", this->price);
}

char* car::getModel()
{
	return this->model;
}
char* car::getColor()
{
	return this->color;
}
int car::getYear()
{
	return this->year;
}
double car::getPrice()
{
	return this->price;
}

void car::setModel(char* model)
{
	if (this->model != nullptr)
	{
		delete[] this->model;
	}
	this->model = new char[strlen(model) + 1];

	strcpy_s(this->model, strlen(model) + 1, model);
}
void car::setModel(const char* model)
{
	if (this->model != nullptr)
	{
		delete[] this->model;
	}
	this->model = new char[strlen(model) + 1];

	strcpy_s(this->model, strlen(model) + 1, model);
}

void car::setColor(char* color)
{
	if (this->color != nullptr)
	{
		delete[] this->color;
	}
	this->color = new char[strlen(color) + 1];

	strcpy_s(this->color, strlen(color) + 1, color);
}
void car::setColor(const char* color)
{
	if (this->color != nullptr)
	{
		delete[] this->color;
	}
	this->color = new char[strlen(color) + 1];

	strcpy_s(this->color, strlen(color) + 1, color);
}

void car::setYear(int year)
{
	this->year = year;
}

void car::setPrice(double price)
{
	this->price = price;
}

int main()
{
	car car1{ "Kia Sorento","Black",2013,2540.54 };

	car1.display();

	car1.setColor("Crimson");

	printf("This car's color is:%s\n", car1.getColor());

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
