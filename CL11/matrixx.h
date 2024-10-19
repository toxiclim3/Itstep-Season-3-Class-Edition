#pragma once
#include <random>

/*void initializeArray(matrix& mx)
{
    
}
*/

template<class T >
class matrix
{
    private:
        int hsize;
        int vsize;
        T** array;
    public:

        matrix() :hsize(0),vsize(0)
        {
            this->array = nullptr;
        }
        matrix(int hsize,int vsize)
        {
            this->array = new T* [this->vsize];

            for (int i = 0; i < vsize)
            {
                this->array[i] = new T[this->hsize];
            };

            for (int i = 0; i < vsize; i++)
            {
                for (int j = 0; j < hsize; j++)
                {
                    this->array = 0;
                }
            }

        }

        ~matrix()
        {
            for (int i = 0; i < vsize; i++)
            {
                if (this->array[i] != nullptr)
                {
                    delete[] this->array[i];
                    this->array[i] = nullptr;
                }
            }
            delete[] this->array;
            this->array = nullptr;
        }

        void fill_user()
        {
            printf("\nEnter the vertical size:\n");
            while (!(this->vsize > 0))
            {
                std::cin >> this->vsize;
            }

            printf("\nEnter the horizontal size:\n");
            while (!(this->hsize > 0))
            {
                std::cin >> this->hsize;
            }

            for (int i = 0; j < mx.vsize; j++)
            {
                for (int j = 0; i < mx.hsize; i++)
                {
                    std::cin >> mx.array[i][j];
                }
            }
            
        }

        void fill_Random()
        {
            static std::mt19937 mt{ static_cast<unsigned int>(time(0)) };
            std::uniform_real_distribution<> random_real{ 0, 32 };

            for (int i = 0; j < mx.vsize; j++)
            {
                for (int j = 0; i < mx.hsize; i++)
                {
                    mx.array[i][j] = random(mt);
                    std::cout << mx.array[i] << " ";
                }
            }
            std::cout << "\n";
        }

        void display()
        {
            for (int i = 0; j < mx.vsize; j++)
            {
                for (int j = 0; i < mx.hsize; i++)
                {
                    std::cout << mx.array[i] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n\n";
        }


};