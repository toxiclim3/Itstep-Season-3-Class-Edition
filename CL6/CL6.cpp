// CL6.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        engine(const char* model)
        {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }
        char* getModel()
        {
            return this->model;
        }
        void printEngine()
        {
            printf("Engine model:%s\n", this->model);
        }
        ~engine()
        {
            if (this->model != nullptr)
            {
                delete[] this->model;
            }
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
        ac(const char* model)
        {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);
        }
        char* getModel()
        {
            return this->model;
        }
        void printAC()
        {
            printf("AC model:%s\n", this->model);
        }
        ~ac()
        {
            if (this->model != nullptr)
            {
                delete[] this->model;
            }
        }
};

class car
{
    private:
        char* model;
        int year;
        char* color;
        engine engine;
        ac ac;
    public:
        car() :engine(),ac()
        {
            this->model = nullptr;
            this->year = 0;
            this->color = nullptr;
        }
        car(const char* model, int year, const char* color) :engine(), ac()
        {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);

            this->year = year;

            this->color = new char[strlen(color) + 1];
            strcpy_s(this->color, strlen(color) + 1, color);
        }
        car(const char* model, int year, const char* color, const char* engine_Model) :engine(engine_Model), ac()
        {
            this->model = new char[strlen(model)+1];
            strcpy_s(this->model, strlen(model) + 1, model);

            this->year = year;

            this->color = new char[strlen(color) + 1];
            strcpy_s(this->color, strlen(color) + 1, color);
        }
        car(const char* model, int year, const char* color, const char* engine_model, const char* ac_model) :engine(engine_model), ac(ac_model)
        {
            this->model = new char[strlen(model) + 1];
            strcpy_s(this->model, strlen(model) + 1, model);

            this->year = year;

            this->color = new char[strlen(color) + 1];
            strcpy_s(this->color, strlen(color) + 1, color);
        }

        ~car()
        {
            if (this->model != nullptr)
            {
                delete[] this->model;
            }
            if (this->color != nullptr)
            {
                delete[] this->color;
            }
        }

        void display()
        {
            printf("Model: %s\n", this->model);
            printf("Year: %i\n", this->year);
            printf("Color: %s\n", this->color);

            if (this->engine.getModel() == nullptr)
            {
                printf("Engine model unknown\n");
            }
            else
            {
                printf("Engine model: %s\n", this->engine.getModel());
            }
            if (this->ac.getModel() == nullptr)
            {
                printf("AC model unknown\n");
            }
            else
            {
                printf("AC model: %s\n", this->ac.getModel());
            }
        }
};

int main()
{
    car car1("Toyota corolla", 2003, "Red", "V6 engine", "OEM AC");

    car1.display();
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
