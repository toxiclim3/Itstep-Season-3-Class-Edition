#pragma once
#include <iostream>
#include <random>
#include <ctime>

template <class T>
class matrix {
private:
    int rows;
    int cols;
    T** data;

public:
    matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) 
    {
        this->data = new T * [this->rows];
        for (int i = 0; i < this->rows; ++i)
        {
            this->data[i] = new T[this->cols]();
        }
    }

    matrix(matrix& other) : rows(other.rows), cols(other.cols)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
               this->data[i][j] = other.data[i][j];
            }
        }
    }

    ~matrix() 
    {
        for (int i = 0; i < this->rows; ++i) 
        {
            delete[] this->data[i];
        }
        delete[] this->data;
    }

    void fill_user() 
    {
        std::cout << "Enter values for a " << this->rows << "x" << this->cols << " matrix:\n";
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                std::cin >> this->data[i][j];
            }
        }
    }

    int random_val(int min = 0, int max = 100)
    {
        static std::mt19937 mt(static_cast<unsigned int>(std::time(0)));
        std::uniform_int_distribution<> rand(min, max);
        return rand(mt);
    }

    char random_val(char min = 0, char max = 100)
    {
        static std::mt19937 mt(static_cast<unsigned int>(std::time(0)));
        std::uniform_int_distribution<> rand( static_cast<int>(min), static_cast<int>(max) );
        return rand(mt);
    }

    double random_val(double min = 0, double max = 100)
    {
        static std::mt19937 mt(static_cast<unsigned int>(std::time(0)));
        std::uniform_real_distribution<> rand(min, max);
        return rand(mt);
    }

    float random_val(float min = 0, float max = 100)
    {
        static std::mt19937 mt(static_cast<unsigned int>(std::time(0)));
        std::uniform_real_distribution<> rand(min, max);
        return rand(mt);
    }

    void fill_random(T min = 0, T max = 100) 
    {
        
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                this->data[i][j] = static_cast<T>(random_val(min,max));
            }
        }
    }

    void display() const {
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                std::cout << this->data[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    T maxElement() const 
    {
        T maxVal = this->data[0][0];
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                if (this->data[i][j] > maxVal) maxVal = this->data[i][j];
            }
        }
        return maxVal;
    }

    T minElement() const 
    {
        T minVal = this->data[0][0];
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                if (this->data[i][j] < minVal) minVal = this->data[i][j];
            }
        }
        return minVal;
    }

    matrix<T> operator+(const matrix<T>& other) const 
    {
        matrix result(this->rows, this->cols);
        for (int i = 0; i < this->rows; ++i) 
        {
            for (int j = 0; j < this->cols; ++j) 
            {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    matrix<T> operator-(const matrix<T>& other) const 
    {
        matrix result(this->rows, this->cols);
        for (int i = 0; i < this->rows; ++i) 
        {
            for (int j = 0; j < this->cols; ++j) 
            {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    matrix<T> operator*(const matrix<T>& other) const 
    {
        matrix result(this->rows, other.cols);
        for (int i = 0; i < this->rows; ++i) 
        {
            for (int j = 0; j < other.cols; ++j) 
            {
                    result.data[i][j] = this->data[i][j] * other.data[i][j];
            }
        }
        return result;
    }

    matrix<T> operator/(const matrix<T>& other) const
    {
        matrix result(this->rows, this->cols);
        for (int i = 0; i < this->rows; ++i) 
        {
            for (int j = 0; j < this->cols; ++j) 
            {
                if (this->data[i][j] == 0 || other.data[i][j] == 0)
                {
                    result.data[i][j] = 0;
                }
                else
                {
                    result.data[i][j] = this->data[i][j] / other.data[i][j];
                }
                //std::cout << static_cast<int>(result.data[i][j]) << " ";
            }
            //std::cout << "\n";
        }
        return result;
    }
    
    matrix<T> operator=(T& other) const 
    {
        for (int i = 0; i < this->rows; ++i)
        {
            delete[] this->data[i];
        }
        delete[] this->data;

        this->rows = other.rows;
        this->cols = other.cols;

        this->data = new T * [this->rows];
        for (int i = 0; i < this->rows; ++i)
        {
            this->data[i] = new T[this->cols]();
        }


        
        for (int i = 0; i < this->rows; ++i) 
        {
            for (int j = 0; j < this->cols; ++j) 
            {
                this->data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }
};
