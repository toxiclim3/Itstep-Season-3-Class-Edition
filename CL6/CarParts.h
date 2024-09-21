#pragma once
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