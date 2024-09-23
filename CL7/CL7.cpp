// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class engine
{
private:
    char* model;
public:
    engine()
    {
        this->model = nullptr;
    }
    engine(char* model)
    {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }
    engine(const char* model)
    {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }
    engine(engine& other)
    {
        this->model = new char[strlen(other.model) + 1];
        strcpy_s(this->model, strlen(other.model) + 1, other.model);

        printf("Engine copied\n");
    }

    ~engine()
    {
        if (this->model != nullptr)
        {
            delete[] this->model;
        }
    }

    char* getModel()
    {
        return this->model;
    }
};

class ac
{
private:
    char* model;
public:
    ac()
    {
        this->model = nullptr;
    }
    ac(char* model)
    {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }
    ac(const char* model)
    {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }
    ac(ac& other)
    {
        this->model = new char[strlen(other.model) + 1];
        strcpy_s(this->model, strlen(other.model) + 1, other.model);
        printf("AC copied\n");
    }

    ~ac()
    {
        if (this->model != nullptr)
        {
            delete[] this->model;
        }
    }

    char* getModel()
    {
        return this->model;
    }
};

class car
{
private:
    char* model;
    int year;
    ac ac;
    engine engine;
public:

    car() :ac(), engine()
    {
        this->model = nullptr;
        this->year = 0;
    }

    car(char* model, int year, char* acModel, char* engineModel) :year(year), ac(acModel), engine(engineModel)
    {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }

    car(const char* model, int year, const char* acModel, const char* engineModel) :year(year), ac(acModel), engine(engineModel)
    {
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);
    }

    car(car& other) :year(other.year), engine(other.engine), ac(other.ac)
    {
        this->model = new char[strlen(other.model) + 1];
        strcpy_s(this->model, strlen(other.model) + 1, other.model);


    }

    ~car()
    {
        if (this->model != nullptr)
        {
            delete[] this->model;
        }
    }

    void display()
    {
        printf("Model: %s\n", this->model);
        printf("Manufactured year: %i\n", this->year);
        printf("AC model: %s\n", this->ac.getModel());
        printf("Engine model: %s\n", this->engine.getModel());
    }
};

int main()
{
    car car1("KIA Soul", 2020, "OEM", "Skrillex V32");
    car car2(car1);

    car1.display();
    printf("---------------\n");
    car2.display();
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
