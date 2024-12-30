// CL21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*

Розумний показчик з технічної точки зору представляє собой показчик з додатковою функціональністю
це класс, який контролює виділений ресурс, а саме:
1.Виділення пам'яті
2.Видалення
3.Контроль показчиків на одній ділянці
4.Право володіння на ділянку пам'яті


Розумні показчики
1.auto_ptr - семантика переноса
2.unique_ptr - тільки один власник (= заборонено, move дозволено)
3.shared_ptr - підрахунок посилань
*/

class unique_ptr
{
    private:

    public:
};

int main()
{
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
