// CL19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

Обробка вийняткових ситуацій

Блок try містить код, в якому може виникнути помилка

Ключове слово throw виконує виключення, виконує вихід з блоку try і передає виконання у відповідний блок catch

Всередині функції\метода, 2 способами:
1.Ззовні функції\метода
2.Всередині функції\метода



*/

/*
 try
    {
        1 / 0;
        throw;
    }
    catch () //exception type
    {
        std::cout << "Exception: division by zero";
    }
    catch (...) //... Ловит всё
    {
        std::cout << "Exception: division by zero";
    }
*/

#include <iostream>
#include "DivByZeroException.h"
#include "IndexException.h"
int main()
{
    try
    {
        throw DivByZeroException("Divided by zero!\n");
    }
    catch (Exception exception)
    {
        std::cout << exception.getMessage();
    }
    
    std::cout << "Hello World!\n";
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
