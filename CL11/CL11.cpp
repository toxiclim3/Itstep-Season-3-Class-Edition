// CL11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "matrixx.h"

/*

шаблоны позволяют создавать абстрактный алгоритим, по которому компилятор создаёт строго типизированные конструкции (функции или методы)

Абстракция даёт право не знать, а это означает, что можно создавать алгоритмы, которые будут работать с любым типом

Полиморфизм - 1 интерфейс, множество реализаций

Для использования класса в шаблоне, нужно перегрузить всё что нужно

Основная причина перегрузки операций - это выполнение требований шаблона

Шаблон нельзя разделить на несколько файлов


*/



int main()
{
    matrix<int> matrix_random(5,5);
    //matrix<char> matrix_random(5,5);
    //matrix<float> matrix_random(5,5);

    matrix_random.fill_random(50, 99);

    matrix_random.display();

    std::cout << "The maximum element in the matrix is " << matrix_random.maxElement() << "\n";
    std::cout << "The minimum element in the matrix is " << matrix_random.minElement() << "\n";

    //matrix<int> matrix_user(5, 5);
    ////matrix<char> matrix_user(5, 5);
    ////matrix<float> matrix_user(5, 5);

    //matrix_user.fill_user();

    //matrix_user.display();

    matrix<int> matrix_random2(5, 5);
    //matrix<char> matrix_random2(5, 5);
    //matrix<float> matrix_random2(5, 5);

    matrix_random2.fill_random(50, 99);
    matrix_random2.display();

    printf("\nResult using the \"+\" operator:\n");
    matrix<int> res1 = matrix_random + matrix_random2;
    res1.display();

    printf("\nResult using the \"-\" operator:\n");
    matrix<int> res2 = matrix_random - matrix_random2;
    res2.display();

    printf("\nResult using the \"*\" operator:\n");
    matrix<int> res3 = matrix_random * matrix_random2;
    res3.display();

    printf("\nResult using the \"/\" operator:\n");
    matrix<int> res4 = matrix_random / matrix_random2;
    res4.display();



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
