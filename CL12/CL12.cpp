// CL12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


int main()
{
    printf("Enter the equation\n");

    std::string equation;

    std::cin >> equation;

    int operpos = equation.find_first_of("+-*/");

    if (operpos == std::string::npos)
    {
        printf("Invalid equation!!!!!\n");
        return -1;
    }

    char oper = equation[operpos];

    std::string lval = equation.substr(0,operpos);
    std::string rval = equation.substr(operpos+1);

    int l = stoi(lval);
    int r = stoi(rval);

    printf("The left value is %i,\nthe right value is %i,\nand the operator is %c", l, r, oper);

    int result = 0;

    if (oper == '+')
    {
        result = l + r;
    }
    else if (oper == '-')
    {
        result = l - r;
    }
    else if (oper == '*')
    {
        result = l * r;
    }
    else if (oper == '/')
    {
        result = l / r;
    }


    printf("\nThe result of the equation \"%s\" is: %i\n", equation.c_str(), result);
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
