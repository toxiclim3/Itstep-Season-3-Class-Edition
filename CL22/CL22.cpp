// CL22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


/*

Артефакти STL:
1.Контейнери - визначають, як складається пам'ять
2.Алгоритми - функціі для роботи з контейнерами
3.Ітератори - Розумні показчики для перебору контейнерів всередині алгоритмів

Функтори та предикати - додаткові умови для деяких алгоритмів

Адаптери - адаптують інтерфейс контейнера або під стек, або під чергу

Аллокатори - здійснюють розподіл пам'яті під контейнери

Кожен контейнер має свій ітератор, і також 2 функції - begin i end (Повератають показчики на перший елемент та наступний після останньго елемента в массиві)
*/

double posAvg(std::vector<int> vec)
{
    int posnumbers = 0;
    double total = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > 0)
        {
            posnumbers++;
            total += vec[i];
        }
    }

    return total / posnumbers;
}

int sumDigits(std::vector<int> vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        while (vec[i] != 0)
        {
            int digit = vec[i] % 10;
            
            vec[i] /= 10;

            sum += digit;
            std::cout << digit << ", ";
        }
        
    }
    std::cout << std::endl;
    return sum;
}



int main()
{
    std::vector<int> vec;
    vec = { 20,-23,89,1,-43 };

    std::cout << posAvg(vec) << "\n";

    std::cout << sumDigits(vec) << "\n";
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
