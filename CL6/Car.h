#pragma once
class car
{
private:
    char* model;
    int year;
    char* color;
    engine engine;
    ac ac;
public:
    car() :engine(), ac()
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
        this->model = new char[strlen(model) + 1];
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